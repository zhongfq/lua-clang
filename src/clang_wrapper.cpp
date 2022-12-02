#include "clang_wrapper.h"

using namespace clangwrapper;

static std::shared_ptr<Cursor> makeCursor(CXCursor value)
{
    if (clang_Cursor_isNull(value)) {
        return std::shared_ptr<Cursor>();
    } else {
        return std::make_shared<Cursor>(value);
    }
}

static std::shared_ptr<Type> makeType(CXType value)
{
    if (value.kind == CXType_Invalid) {
        return std::shared_ptr<Type>();
    } else {
        return std::make_shared<Type>(value);
    }
}

static std::shared_ptr<File> makeFile(CXFile value)
{
    if (!value) {
        return std::shared_ptr<File>();
    } else {
        return std::make_shared<File>(value);
    }
}

static std::shared_ptr<Module> makeModule(CXModule value)
{
    if (!value) {
        return std::shared_ptr<Module>();
    } else {
        return std::make_shared<Module>(value);
    }
}

static std::shared_ptr<Diagnostic> makeDiagnostic(CXDiagnostic value)
{
    if (!value) {
        return std::shared_ptr<Diagnostic>();
    } else {
        return std::make_shared<Diagnostic>(value);
    }
}

olua_Return IndexError::__index(lua_State *L)
{
    return olua_indexerror(L);
}

olua_Return IndexError::__newindex(lua_State *L)
{
    return olua_newindexerror(L);
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

string Diagnostic::name()
{
    return clang_getDiagnosticSpelling(_value);
}

unsigned Diagnostic::category()
{
    return clang_getDiagnosticCategory(_value);
}

string Diagnostic::categoryText()
{
    return clang_getDiagnosticCategoryText(_value);
}

string Diagnostic::text()
{
    return formatDiagnostic(clang_defaultDiagnosticDisplayOptions());
}

DiagnosticSeverity Diagnostic::severity()
{
    return clang_getDiagnosticSeverity(_value);
}

string Diagnostic::severitySeplling()
{
    static const char *const ns[] = {"Ignored", "Note", "Warning", "Error", "Fatal"};
    return ns[clang_getDiagnosticSeverity(_value)];
}

string Diagnostic::formatDiagnostic(unsigned options)
{
    return clang_formatDiagnostic(_value, options);
}

File::File(CXFile value)
:_value(value)
{
}

olua_Return File::__eq(lua_State *L, File *f)
{
    return clang_File_isEqual(_value, f->_value);
}

string File::fileName()
{
    return clang_getFileName(_value);
}

time_t File::fileTime()
{
    return clang_getFileTime(_value);
}

string File::tryGetRealPathName()
{
    return clang_File_tryGetRealPathName(_value);
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

olua_Return Type::__eq(lua_State *L, Type *t)
{
    return clang_equalTypes(_value, t->_value);
}

string Type::name()
{
    return clang_getTypeSpelling(_value);
}

TypeKind Type::kind()
{
    return _value.kind;
}

string Type::kindSpelling()
{
    return clang_getTypeKindSpelling(_value.kind);
}

std::shared_ptr<Type> Type::canonicalType()
{
    return makeType(clang_getCanonicalType(_value));
}

bool Type::isConstQualified()
{
    return clang_isConstQualifiedType(_value);
}

bool Type::isVolatileQualified()
{
    return clang_isVolatileQualifiedType(_value);
}

bool Type::isRestrictQualified()
{
    return clang_isRestrictQualifiedType(_value);
}

unsigned Type::addressSpace()
{
    return clang_getAddressSpace(_value);
}

string Type::typedefName()
{
    return clang_getTypedefName(_value);
}

std::shared_ptr<Type> Type::pointeeType()
{
    return makeType(clang_getPointeeType(_value));
}

std::shared_ptr<Type> Type::unqualifiedType()
{
    return makeType(clang_getUnqualifiedType(_value));
}

std::shared_ptr<Type> Type::nonReferenceType()
{
    return makeType(clang_getNonReferenceType(_value));
}

std::shared_ptr<Cursor> Type::declaration()
{
    return makeCursor(clang_getTypeDeclaration(_value));
}

std::shared_ptr<Type> Type::resultType()
{
    return makeType(clang_getResultType(_value));
}

int Type::exceptionSpecificationType()
{
    return clang_getExceptionSpecificationType(_value);
}

bool Type::isFunctionTypeVariadic()
{
    return clang_isFunctionTypeVariadic(_value);
}

CallingConv Type::functionTypeCallingConv()
{
    return clang_getFunctionTypeCallingConv(_value);
}

string Type::functionTypeCallingConvSpelling()
{
    static const char *const ns[] = {"Default", "C", "X86StdCall", "X86FastCall", "X86ThisCall", "X86Pascal", "AAPCS","AAPCS_VFP", "X86RegCall", "IntelOclBicc", "Win64", "X86_64SysV", "X86VectorCall", "Swift", "PreserveMost", "PreserveAll", "AArch64VectorCall", "SwiftAsync", "AArch64SVEPCS"};
    int i = (int)clang_getFunctionTypeCallingConv(_value);
    if (i <= 18) {
        return ns[i];
    } else {
        return "Unexposed";
    }
}

std::vector<std::shared_ptr<Type>> Type::argTypes()
{
    std::vector<std::shared_ptr<Type>> arr;
    int n = clang_getNumArgTypes(_value);
    for (int i = 0; i < n; i++) {
        arr.push_back(makeType(clang_getArgType(_value, i)));
    }
    return arr;
}

bool Type::isPOD()
{
    return clang_isPODType(_value);
}

std::shared_ptr<Type> Type::elementType()
{
    return makeType(clang_getElementType(_value));
}

std::shared_ptr<Type> Type::arrayElementType()
{
    return makeType(clang_getArrayElementType(_value));
}

long long Type::numElements()
{
    return clang_getNumElements(_value);
}

long long Type::arraySize()
{
    return clang_getArraySize(_value);
}

bool Type::isTransparentTagTypedef()
{
    return clang_Type_isTransparentTagTypedef(_value);
}

TypeNullabilityKind Type::nullability()
{
    return clang_Type_getNullability(_value);
}

string Type::nullabilitySpelling()
{
    static const char *const ns[] = {"NonNull", "Nullable", "Unspecified", "Invalid", "NullableResult"};
    return ns[clang_Type_getNullability(_value)];
}

long long Type::alignOf()
{
    return clang_Type_getAlignOf(_value);
}

std::shared_ptr<Type> Type::classType()
{
    return makeType(clang_Type_getClassType(_value));
}

long long Type::sizeOf()
{
    return clang_Type_getSizeOf(_value);
}

std::shared_ptr<Type> Type::modifiedType()
{
    return makeType(clang_Type_getModifiedType(_value));
}

std::shared_ptr<Type> Type::valueType()
{
    return makeType(clang_Type_getValueType(_value));
}

long long Type::offsetOf(const char *field)
{
    return clang_Type_getOffsetOf(_value, field);
}

std::vector<std::shared_ptr<Type>> Type::templateArgumentTypes()
{
    std::vector<std::shared_ptr<Type>> arr;
    int n = clang_Type_getNumTemplateArguments(_value);
    for (int i = 0; i < n; i++) {
        arr.push_back(makeType(clang_Type_getTemplateArgumentAsType(_value, i)));
    }
    return arr;
}

RefQualifierKind Type::cxxRefQualifier()
{
    return clang_Type_getCXXRefQualifier(_value);
}

string Type::cxxRefQualifierSpelling()
{
    static const char *const ns[] = {"None", "LValue", "RValue"};
    return ns[clang_Type_getCXXRefQualifier(_value)];
}

enum CXVisitorResult fieldVisitor(CXCursor cur, CXClientData client_data)
{
    auto arr = (std::vector<std::shared_ptr<Cursor>> *)client_data;
    arr->push_back(makeCursor(cur));
    return CXVisit_Continue;
}

std::vector<std::shared_ptr<Cursor>> Type::fields()
{
    std::vector<std::shared_ptr<Cursor>> arr;
    clang_Type_visitFields(_value, fieldVisitor, &arr);
    return arr;
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

olua_Return Cursor::__eq(lua_State *L, Cursor *c)
{
    return clang_equalCursors(_value, c->_value);
}

string Cursor::name()
{
    return clang_getCursorSpelling(_value);
}

CursorKind Cursor::kind()
{
    return clang_getCursorKind(_value);
}

string Cursor::kindSpelling()
{
    return clang_getCursorKindSpelling(clang_getCursorKind(_value));
}

bool Cursor::isNull()
{
    return clang_Cursor_isNull(_value);
}

unsigned Cursor::hashCursor()
{
    return clang_hashCursor(_value);
}

bool Cursor::isDeclaration()
{
    return clang_isDeclaration(clang_getCursorKind(_value));
}

bool Cursor::isInvalidDeclaration()
{
    return clang_isInvalidDeclaration(_value);
}

bool Cursor::isReference()
{
    return clang_isReference(clang_getCursorKind(_value));
}

bool Cursor::isExpression()
{
    return clang_isExpression(clang_getCursorKind(_value));
}

bool Cursor::isStatement()
{
    return clang_isStatement(clang_getCursorKind(_value));
}

bool Cursor::isAttribute()
{
    return clang_isAttribute(clang_getCursorKind(_value));
}

bool Cursor::hasAttrs()
{
    return clang_Cursor_hasAttrs(_value);
}

bool Cursor::isInvalid()
{
    return clang_isInvalid(clang_getCursorKind(_value));
}

bool Cursor::isTranslationUnit()
{
    return clang_isTranslationUnit(clang_getCursorKind(_value));
}

bool Cursor::isPreprocessing()
{
    return clang_isPreprocessing(clang_getCursorKind(_value));
}

bool Cursor::isUnexposed()
{
    return clang_isUnexposed(clang_getCursorKind(_value));
}

LinkageKind Cursor::linkage()
{
    return clang_getCursorLinkage(_value);
}

string Cursor::linkageSpelling()
{
    static const char *const ns[] = {"Invalid", "NoLinkage", "Internal", "UniqueExternal", "External"};
    return ns[clang_getCursorLinkage(_value)];
}

VisibilityKind Cursor::visibility()
{
    return clang_getCursorVisibility(_value);
}

string Cursor::visibilitySpelling()
{
    static const char *const ns[] = {"Invalid", "Hidden", "Protected", "Default"};
    return ns[clang_getCursorVisibility(_value)];
}

AvailabilityKind Cursor::availability()
{
    return clang_getCursorAvailability(_value);
}

string Cursor::availabilitySpelling()
{
    static const char *const ns[] = {"Available", "Deprecated", "NotAvailable", "NotAccessible"};
    return ns[clang_getCursorAvailability(_value)];
}

std::shared_ptr<Cursor> Cursor::varDeclInitializer()
{
    return makeCursor(clang_Cursor_getVarDeclInitializer(_value));
}

int Cursor::hasVarDeclGlobalStorage()
{
    return clang_Cursor_hasVarDeclGlobalStorage(_value);
}

int Cursor::hasVarDeclExternalStorage()
{
    return clang_Cursor_hasVarDeclExternalStorage(_value);
}

LanguageKind Cursor::language()
{
    return clang_getCursorLanguage(_value);
}

string Cursor::languageSpelling()
{
    static const char *const ns[] = {"Invalid", "C", "ObjC", "CPlusPlus"};
    return ns[clang_getCursorLanguage(_value)];
}

TLSKind Cursor::tlsKind()
{
    return clang_getCursorTLSKind(_value);
}

string Cursor::tlsKindSpelling()
{
    static const char *const ns[] = {"None", "Dynamic", "Static"};
    return ns[clang_getCursorTLSKind(_value)];
}

std::shared_ptr<TranslationUnit> Cursor::translationUnit()
{
    return std::make_shared<TranslationUnit>(clang_Cursor_getTranslationUnit(_value), false);
}

std::shared_ptr<Cursor> Cursor::parent()
{
    return semanticParent();
}

std::shared_ptr<Cursor> Cursor::semanticParent()
{
    return makeCursor(clang_getCursorSemanticParent(_value));
}

std::shared_ptr<Cursor> Cursor::lexicalParent()
{
    return makeCursor(clang_getCursorLexicalParent(_value));
}

std::shared_ptr<File> Cursor::includedFile()
{
    return makeFile(clang_getIncludedFile(_value));
}

Cursor::SourceRange Cursor::sourceRange()
{
    SourceRange ret;
    CXFile file;
    CXSourceRange range = clang_getCursorExtent(_value);
    CXSourceLocation start = clang_getRangeStart(range);
    CXSourceLocation end = clang_getRangeEnd(range);
    clang_getSpellingLocation(start, &file, &ret.startLine, &ret.startColumn, NULL);
    clang_getSpellingLocation(end, &file, &ret.endLine, &ret.endColumn, NULL);
    ret.path = string(clang_getFileName(file)).data;
    return ret;
}

Cursor::SourceLocation Cursor::sourceLocation()
{
    SourceLocation ret;
    CXFile file;
    CXSourceLocation location = clang_getCursorLocation(_value);
    clang_getSpellingLocation(location, &file, &ret.line, &ret.column, NULL);
    ret.path = string(clang_getFileName(file)).data;
    return ret;
}

std::shared_ptr<Type> Cursor::type()
{
    return makeType(clang_getCursorType(_value));
}

std::shared_ptr<Type> Cursor::underlyingType()
{
    return makeType(clang_getTypedefDeclUnderlyingType(_value));
}

std::shared_ptr<Type> Cursor::enumDeclIntegerType()
{
    return makeType(clang_getEnumDeclIntegerType(_value));
}

long long Cursor::enumConstantDeclValue()
{
    return clang_getEnumConstantDeclValue(_value);
}

unsigned long long Cursor::enumConstantDeclUnsignedValue()
{
    return clang_getEnumConstantDeclUnsignedValue(_value);
}

int Cursor::fieldDeclBitWidth()
{
    return clang_getFieldDeclBitWidth(_value);
}

std::vector<std::shared_ptr<Cursor>> Cursor::arguments()
{
    std::vector<std::shared_ptr<Cursor>> arr;
    int n = clang_Cursor_getNumArguments(_value);
    for (int i = 0; i < n; i++) {
        arr.push_back(makeCursor(clang_Cursor_getArgument(_value, i)));
    }
    return arr;
}

std::vector<std::shared_ptr<Type>> Cursor::templateArgumentTypes()
{
    std::vector<std::shared_ptr<Type>> arr;
    int n = clang_Cursor_getNumTemplateArguments(_value);
    for (int i = 0; i < n; i++) {
        arr.push_back(makeType(clang_Cursor_getTemplateArgumentType(_value, i)));
    }
    return arr;
}

TemplateArgumentKind Cursor::templateArgumentKind(unsigned int index)
{
    return clang_Cursor_getTemplateArgumentKind(_value, index);
}

string Cursor::templateArgumentKindSpelling(unsigned index)
{
    static const char *const ns[] = {"Null", "Type", "Declaration", "NullPtr", "Integral", "Template", "TemplateExpansion", "Expression", "Pack", "Invalid"};
    return ns[clang_Cursor_getTemplateArgumentKind(_value, index)];
}

long long Cursor::templateArgumentValue(unsigned index)
{
    return clang_Cursor_getTemplateArgumentValue(_value, index);
}

unsigned long long Cursor::templateArgumentUnsignedValue(unsigned index)
{
    return clang_Cursor_getTemplateArgumentUnsignedValue(_value, index);
}

bool Cursor::isMacroFunctionLike()
{
    return clang_Cursor_isMacroFunctionLike(_value);
}

bool Cursor::isMacroBuiltin()
{
    return clang_Cursor_isMacroBuiltin(_value);
}

bool Cursor::isFunctionInlined()
{
    return clang_Cursor_isFunctionInlined(_value);
}

std::shared_ptr<Type> Cursor::resultType()
{
    return makeType(clang_getCursorResultType(_value));
}

int Cursor::exceptionSpecificationType()
{
    return clang_getCursorExceptionSpecificationType(_value);
}

long long Cursor::offsetOfField()
{
    return clang_Cursor_getOffsetOfField(_value);
}

bool Cursor::isAnonymous()
{
    return clang_Cursor_isAnonymous(_value);
}

bool Cursor::isAnonymousRecordDecl()
{
    return clang_Cursor_isAnonymousRecordDecl(_value);
}

bool Cursor::isInlineNamespace()
{
    return clang_Cursor_isInlineNamespace(_value);
}

bool Cursor::isBitField()
{
    return clang_Cursor_isBitField(_value);
}

bool Cursor::isVirtualBase()
{
    return clang_isVirtualBase(_value);
}

bool Cursor::isDeprecated()
{
    bool ret = false;
    CXString pretty = clang_getCursorPrettyPrinted(_value, NULL);
    const char *str = clang_getCString(pretty);
    if (strstr(str, "__attribute__((deprecated")) {
        ret = true;
    } else if (strstr(str, "__declspec(deprecated")) {
        ret = true;
    }
    clang_disposeString(pretty);
    return ret;
}

CXXAccessSpecifier Cursor::cxxAccessSpecifier()
{
    return clang_getCXXAccessSpecifier(_value);
}

string Cursor::cxxAccessSpecifierSpelling()
{
    static const char *const ns[] = {"Invalid", "Public", "Protected", "Private"};
    return ns[clang_getCXXAccessSpecifier(_value)];
}

StorageClass Cursor::storageClass()
{
    return clang_Cursor_getStorageClass(_value);
}

string Cursor::storageClassSpelling()
{
    static const char *const ns[] = {"Invalid", "None", "Extern", "Static", "PrivateExtern", "OpenCLWorkGroupLocal", "Auto", "Register"};
    return ns[clang_Cursor_getStorageClass(_value)];
}

std::vector<std::shared_ptr<Cursor>> Cursor::overloadedDecls()
{
    std::vector<std::shared_ptr<Cursor>> arr;
    int n = clang_getNumOverloadedDecls(_value);
    for (int i = 0; i < n; i++) {
        arr.push_back(makeCursor(clang_getOverloadedDecl(_value, i)));
    }
    return arr;
}

std::shared_ptr<Type> Cursor::ibOutletCollectionType()
{
    return makeType(clang_getIBOutletCollectionType(_value));
}

static enum CXChildVisitResult childrenVisitor(CXCursor cursor, CXCursor parent, CXClientData client_data)
{
    auto *arr = (std::vector<std::shared_ptr<Cursor>> *)client_data;
    arr->push_back(makeCursor(cursor));
    return CXChildVisit_Continue;
}

std::vector<std::shared_ptr<Cursor>> Cursor::children()
{
    std::vector<std::shared_ptr<Cursor>> arr;
    clang_visitChildren(_value, childrenVisitor, (void *)&arr);
    return arr;
}

Cursor::SourceRange Cursor::nameRange(unsigned pieceIndex, unsigned options)
{
    SourceRange ret;
    CXFile file;
    CXSourceRange range = clang_Cursor_getSpellingNameRange(_value, pieceIndex, options);
    CXSourceLocation start = clang_getRangeStart(range);
    CXSourceLocation end = clang_getRangeEnd(range);
    clang_getSpellingLocation(start, &file, &ret.startLine, &ret.startColumn, NULL);
    clang_getSpellingLocation(end, &file, &ret.endLine, &ret.endColumn, NULL);
    ret.path = string(clang_getFileName(file)).data;
    return ret;
}

string Cursor::prettyPrinted()
{
    return clang_getCursorPrettyPrinted(_value, NULL);
}

string Cursor::displayName()
{
    return clang_getCursorDisplayName(_value);
}

std::shared_ptr<Cursor> Cursor::referenced()
{
    return makeCursor(clang_getCursorReferenced(_value));
}

std::shared_ptr<Cursor> Cursor::definition()
{
    return makeCursor(clang_getCursorDefinition(_value));
}

bool Cursor::isDefinition()
{
    return clang_isCursorDefinition(_value);
}

std::shared_ptr<Cursor> Cursor::canonical()
{
    return makeCursor(clang_getCanonicalCursor(_value));
}

int Cursor::isDynamicCall()
{
    return clang_Cursor_isDynamicCall(_value);
}

std::shared_ptr<Type> Cursor::receiverType()
{
    return makeType(clang_Cursor_getReceiverType(_value));
}

bool Cursor::isVariadic()
{
    return clang_Cursor_isVariadic(_value);
}

Cursor::SourceRange Cursor::commentRange()
{
    SourceRange ret;
    CXFile file;
    CXSourceRange range = clang_Cursor_getCommentRange(_value);
    CXSourceLocation start = clang_getRangeStart(range);
    CXSourceLocation end = clang_getRangeEnd(range);
    clang_getSpellingLocation(start, &file, &ret.startLine, &ret.startColumn, NULL);
    clang_getSpellingLocation(end, &file, &ret.endLine, &ret.endColumn, NULL);
    ret.path = string(clang_getFileName(file)).data;
    return ret;
}

string Cursor::rawCommentText()
{
    return clang_Cursor_getRawCommentText(_value);
}

string Cursor::briefCommentText()
{
    return clang_Cursor_getBriefCommentText(_value);
}

string Cursor::mangling()
{
    return clang_Cursor_getMangling(_value);
}

std::vector<string> Cursor::cxxManglings()
{
    CXStringSet *set = clang_Cursor_getCXXManglings(_value);
    std::vector<string> strs;
    for (int i = 0; i < set->Count; i++) {
        strs.push_back(set->Strings[i]);
    }
    clang_disposeStringSet(set);
    return strs;
}

std::shared_ptr<Module> Cursor::getModule()
{
    return makeModule(clang_Cursor_getModule(_value));
}

bool Cursor::isCXXConvertingConstructor()
{
    return clang_CXXConstructor_isConvertingConstructor(_value);
}

bool Cursor::isCXXCopyConstructor()
{
    return clang_CXXConstructor_isCopyConstructor(_value);
}

bool Cursor::isCXXDefaultConstructor()
{
    return clang_CXXConstructor_isDefaultConstructor(_value);
}

bool Cursor::isCXXMoveConstructor()
{
    return clang_CXXConstructor_isMoveConstructor(_value);
}

bool Cursor::isCXXFieldMutable()
{
    return clang_CXXField_isMutable(_value);
}

bool Cursor::isCXXMethodDefaulted()
{
    return clang_CXXMethod_isDefaulted(_value);
}

bool Cursor::isCXXMethoDeleted()
{
    return clang_CXXMethod_isDeleted(_value);
}

bool Cursor::isCXXMethoPureVirtual()
{
    return clang_CXXMethod_isPureVirtual(_value);
}

bool Cursor::isCXXMethoStatic()
{
    return clang_CXXMethod_isStatic(_value);
}

bool Cursor::isCXXMethoVirtual()
{
    return clang_CXXMethod_isVirtual(_value);
}

bool Cursor::isCXXMethoCopyAssignmentOperator()
{
    return clang_CXXMethod_isCopyAssignmentOperator(_value);
}

bool Cursor::isCXXMethoConst()
{
    return clang_CXXMethod_isConst(_value);
}

bool Cursor::isCXXMethoAbstract()
{
    return clang_CXXRecord_isAbstract(_value);
}

bool Cursor::isEnumDeclScoped()
{
    return clang_EnumDecl_isScoped(_value);
}

CursorKind Cursor::templateKind()
{
    return clang_getTemplateCursorKind(_value);
}

string Cursor::templateKindSpelling()
{
    return clang_getCursorKindSpelling(clang_getTemplateCursorKind(_value));
}

std::shared_ptr<Cursor> Cursor::specializedTemplate()
{
    return makeCursor(clang_getSpecializedCursorTemplate(_value));
}

Cursor::SourceRange Cursor::referenceNameRange(unsigned pieceIndex, unsigned options)
{
    SourceRange ret;
    CXFile file;
    CXSourceRange range = clang_getCursorReferenceNameRange(_value, pieceIndex, options);
    CXSourceLocation start = clang_getRangeStart(range);
    CXSourceLocation end = clang_getRangeEnd(range);
    clang_getSpellingLocation(start, &file, &ret.startLine, &ret.startColumn, NULL);
    clang_getSpellingLocation(end, &file, &ret.endLine, &ret.endColumn, NULL);
    ret.path = string(clang_getFileName(file)).data;
    return ret;
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

std::shared_ptr<File> Module::astFile()
{
    return makeFile(clang_Module_getASTFile(_value));
}

std::shared_ptr<Module> Module::parent()
{
    return makeModule(clang_Module_getParent(_value));
}

string Module::name()
{
    return clang_Module_getName(_value);
}

string Module::fullName()
{
    return clang_Module_getFullName(_value);
}

int Module::isSystem()
{
    return clang_Module_isSystem(_value);
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

string TranslationUnit::name()
{
    return clang_getTranslationUnitSpelling(_value);
}

std::shared_ptr<Cursor> TranslationUnit::cursor()
{
    CXCursor cur = clang_getTranslationUnitCursor(_value);
    _cursor = makeCursor(cur);
    return _cursor->shared_from_this();
}

bool TranslationUnit::isFileMultipleIncludeGuarded(File *f)
{
    return clang_isFileMultipleIncludeGuarded(_value, f->_value);
}

std::shared_ptr<File> TranslationUnit::getFile(const std::string &path)
{
    return makeFile(clang_getFile(_value, path.c_str()));
}

string TranslationUnit::getFileContents(File *f)
{
    size_t len;
    const char *data = clang_getFileContents(_value, f->_value, &len);
    return string(data, len);
}

std::vector<std::shared_ptr<Diagnostic>> TranslationUnit::diagnostics()
{
    std::vector<std::shared_ptr<Diagnostic>> arr;
    int n = clang_getNumDiagnostics(_value);
    for (int i = 0; i < n; i++) {
        arr.push_back(makeDiagnostic(clang_getDiagnostic(_value, i)));
    }
    return arr;
}

std::set<std::shared_ptr<Diagnostic>> TranslationUnit::diagnosticSetFromTU()
{
    std::set<std::shared_ptr<Diagnostic>> arr;
    CXDiagnosticSet diags = clang_getDiagnosticSetFromTU(_value);
    int n = clang_getNumDiagnosticsInSet(diags);
    for (int i = 0; i < n; i++) {
        arr.insert(makeDiagnostic(clang_getDiagnosticInSet(diags, i)));
    }
    return arr;
}

std::shared_ptr<Module> TranslationUnit::moduleForFile(const std::shared_ptr<File> &file)
{
    return makeModule(clang_getModuleForFile(_value, file->_value));
}

unsigned TranslationUnit::numTopLevelHeaders(const std::shared_ptr<Module> &m)
{
    return clang_Module_getNumTopLevelHeaders(_value, m->_value);
}

std::shared_ptr<File> TranslationUnit::topLevelHeader(const std::shared_ptr<Module> &m, unsigned index)
{
    return makeFile(clang_Module_getTopLevelHeader(_value, m->_value, index));
}

unsigned TranslationUnit::defaultSaveOptions()
{
    return clang_defaultSaveOptions(_value);
}

int TranslationUnit::saveTranslationUnit(const std::string &path, unsigned options)
{
    return clang_saveTranslationUnit(_value, path.c_str(), options);
}

unsigned TranslationUnit::suspendTranslationUnit()
{
    return clang_suspendTranslationUnit(_value);
}

unsigned TranslationUnit::defaultReparseOptions()
{
    return clang_defaultReparseOptions(_value);
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

void Index::setGlobalOptions(unsigned options)
{
    clang_CXIndex_setGlobalOptions(_value, options);
}

unsigned Index::getGlobalOptions()
{
    return clang_CXIndex_getGlobalOptions(_value);
}

void Index::setInvocationEmissionPathOption(const std::string &path)
{
    clang_CXIndex_setInvocationEmissionPathOption(_value, path.c_str());
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
