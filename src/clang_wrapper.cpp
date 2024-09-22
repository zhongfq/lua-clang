#include "clang_wrapper.h"

using namespace clangwrapper;

enum CXVisitorResult clangwrapper::fieldVisitor(CXCursor cur, CXClientData client_data)
{
    auto arr = (std::vector<std::shared_ptr<Cursor>> *)client_data;
    arr->push_back(clangwrapper::makeCursor(cur));
    return CXVisit_Continue;
}

enum CXChildVisitResult clangwrapper::childrenVisitor(CXCursor cursor, CXCursor parent, CXClientData client_data)
{
    auto *arr = (std::vector<std::shared_ptr<Cursor>> *)client_data;
    arr->push_back(clangwrapper::makeCursor(cursor));
    return CXChildVisit_Continue;
}

std::shared_ptr<Cursor> clangwrapper::makeCursor(CXCursor value)
{
    if (clang_Cursor_isNull(value)) {
        return std::shared_ptr<Cursor>();
    } else {
        return std::make_shared<Cursor>(value);
    }
}

std::shared_ptr<Type> clangwrapper::makeType(CXType value)
{
    if (value.kind == CXType_Invalid) {
        return std::shared_ptr<Type>();
    } else {
        return std::make_shared<Type>(value);
    }
}

std::shared_ptr<File> clangwrapper::makeFile(CXFile value)
{
    if (!value) {
        return std::shared_ptr<File>();
    } else {
        return std::make_shared<File>(value);
    }
}

std::shared_ptr<Module> clangwrapper::makeModule(CXModule value)
{
    if (!value) {
        return std::shared_ptr<Module>();
    } else {
        return std::make_shared<Module>(value);
    }
}

std::shared_ptr<Diagnostic> clangwrapper::makeDiagnostic(CXDiagnostic value)
{
    if (!value) {
        return std::shared_ptr<Diagnostic>();
    } else {
        return std::make_shared<Diagnostic>(value);
    }
}

Diagnostic::Diagnostic(CXDiagnostic value)
:_value(value)
{
    clang::count++;
}

Diagnostic::~Diagnostic()
{
    clang::count--;
    if (clang::debug) {
        printf("~Diagnostic: count=%d this=%p %s\n", clang::count, this, typeid(*this).name());
    }
    clang_disposeDiagnostic(_value);
}

File::File(CXFile value)
:_value(value)
{
}

Type::Type(CXType value)
:_value(value)
{
    clang::count++;
}

Type::~Type()
{
    clang::count--;
    if (clang::debug) {
        printf("~Type: count=%d this=%p %s\n", clang::count, this, typeid(*this).name());
    }
}

//
// Cursor
//
Cursor::Cursor(CXCursor value)
:_value(value)
{
    clang::count++;
}

Cursor::~Cursor()
{
    clang::count--;
    if (clang::debug) {
        printf("~Cursor: count=%d this=%p %s\n", clang::count, this, typeid(*this).name());
    }
}

//
// Module
//
Module::Module(CXModule value)
:_value(value)
{
    clang::count++;
}

Module::~Module()
{
    clang::count--;
    if (clang::debug) {
        printf("~Module: count=%d this=%p %s\n", clang::count, this, typeid(*this).name());
    }
}

//
// TranslationUnit
//
TranslationUnit::TranslationUnit(CXTranslationUnit value, bool owner)
:_value(value)
,_owner(owner)
{
    if (_owner) {
        clang::count++;
    }
}

TranslationUnit::~TranslationUnit()
{
    if (_owner) {
        clang::count--;
        if (clang::debug) {
            printf("~TranslationUnit: count=%d this=%p %s\n", clang::count, this, typeid(*this).name());
        }
        clang_disposeTranslationUnit(_value);
    }
}

//
// Index
//
Index::Index(bool excludeDeclarationsFromPCH, bool displayDiagnostics)
{
    clang::count++;
    _value = clang_createIndex((int)excludeDeclarationsFromPCH, (int)displayDiagnostics);
}

Index::~Index()
{
    clang::count--;
    if (clang::debug) {
        printf("~Index: count=%d this=%p %s\n", clang::count, this, typeid(*this).name());
    }
    clang_disposeIndex(_value);
}

std::shared_ptr<TranslationUnit> Index::create(const std::string &path)
{
    CXTranslationUnit tu = clang_createTranslationUnit(_value, path.c_str());
    if (tu) {
        return std::make_shared<TranslationUnit>(tu, true);
    } else {
        printf("failed to open ast file: %s", path.c_str());
        return std::shared_ptr<TranslationUnit>();
    }
}

std::shared_ptr<TranslationUnit> Index::parse(const std::string &path, const std::vector<std::string> args, unsigned int options)
{
    char const **cargs = (char const **)malloc(sizeof(char *) * args.size());
    for (int i = 0; i < (int)args.size(); i++) {
        cargs[i] = args[i].c_str();
    }
    CXTranslationUnit tu = clang_parseTranslationUnit(_value, path.c_str(), cargs, (int)args.size(), NULL, 0, options);
    free(cargs);
    if (tu) {
        return std::make_shared<TranslationUnit>(tu, true);
    } else {
        printf("failed to parse file: %s", path.c_str());
        return std::shared_ptr<TranslationUnit>();
    }
}

const std::string clang::version()
{
    return LUACLANG_VERSION;
}

std::shared_ptr<Index> clang::createIndex(bool excludeDeclarationsFromPCH, bool displayDiagnostics)
{
    return std::make_shared<Index>(excludeDeclarationsFromPCH, displayDiagnostics);
}

bool clang::debug = false;
int clang::count = 0;

int olua_push_string(lua_State *L, const clangwrapper::string &value)
{
    if (!value.isNull) {
        lua_pushlstring(L, value.data.c_str(), value.data.size());
    } else {
        lua_pushnil(L);
    }
    return 1;
}
