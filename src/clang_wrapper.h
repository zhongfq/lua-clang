#ifndef __LUACLANG_CLANG_WRAPPER_H__
#define __LUACLANG_CLANG_WRAPPER_H__

#include "clang-c/Index.h"
#include "olua/olua.h"

#include <memory>

#define LUACLANG_VERSION "2.1"

namespace clangwrapper {

class TranslationUnit;
class Cursor;
class Module;

struct string {
    std::string data;
    bool isNull = true;
    
    string() = default;
    string(const string &) = default;
    
    string(CXString value)
    {
        if (value.data) {
            isNull = false;
            data = std::string(clang_getCString(value));
            clang_disposeString(value);
        }
    }
    
    string(const char *value)
    {
        if (value) {
            isNull = false;
            data = std::string(value);
        }
    }
    
    string(const char *value, size_t len)
    {
        if (value) {
            isNull = false;
            data = std::string(value, len);
        }
    }
};

class IndexError {
public:
    olua_Return __index(lua_State *L);
    olua_Return __newindex(lua_State *L);
};

using DiagnosticSeverity = CXDiagnosticSeverity;

class Diagnostic : public IndexError, public std::enable_shared_from_this<Diagnostic> {
public:
    OLUA_EXCLUDE Diagnostic(CXDiagnostic value);
    ~Diagnostic();
    
    OLUA_GETTER string name();
    OLUA_GETTER unsigned category();
    OLUA_GETTER string categoryText();
    OLUA_GETTER string text();
    OLUA_GETTER DiagnosticSeverity severity();
    OLUA_GETTER string severitySeplling();
    string formatDiagnostic(unsigned options);
private:
    CXDiagnostic _value;
};

class File : public IndexError, public std::enable_shared_from_this<File>
{
    friend class TranslationUnit;
public:
    OLUA_EXCLUDE File(CXFile value);
    
    olua_Return __eq(lua_State *L, File *f);
    
    OLUA_GETTER string fileName();
    OLUA_GETTER time_t fileTime();
    
    string tryGetRealPathName();
private:
    CXFile _value;
};

using TypeKind = CXTypeKind;
using CallingConv = CXCallingConv;
using TypeNullabilityKind = CXTypeNullabilityKind;
using RefQualifierKind = CXRefQualifierKind;

class Type : public IndexError, public std::enable_shared_from_this<Type>
{
public:
    OLUA_EXCLUDE Type(CXType value);
    ~Type();
    
    olua_Return __eq(lua_State *L, Type *t);
    
    OLUA_GETTER string name();
    OLUA_GETTER TypeKind kind();
    OLUA_GETTER string kindSpelling();
    OLUA_GETTER std::shared_ptr<Type> canonicalType();
    OLUA_GETTER bool isConstQualified();
    OLUA_GETTER bool isVolatileQualified();
    OLUA_GETTER bool isRestrictQualified();
    OLUA_GETTER unsigned addressSpace();
    OLUA_GETTER string typedefName();
    OLUA_GETTER std::shared_ptr<Type> pointeeType();
    OLUA_GETTER std::shared_ptr<Type> unqualifiedType();
    OLUA_GETTER std::shared_ptr<Type> nonReferenceType();
    OLUA_GETTER std::shared_ptr<Cursor> declaration();
    OLUA_GETTER std::shared_ptr<Type> resultType();
    OLUA_GETTER int exceptionSpecificationType();
    OLUA_GETTER bool isFunctionTypeVariadic();
    OLUA_GETTER CallingConv functionTypeCallingConv();
    OLUA_GETTER string functionTypeCallingConvSpelling();
    OLUA_GETTER std::vector<std::shared_ptr<Type>> argTypes();
    OLUA_GETTER bool isPOD();
    OLUA_GETTER std::shared_ptr<Type> elementType();
    OLUA_GETTER std::shared_ptr<Type> arrayElementType();
    OLUA_GETTER long long numElements();
    OLUA_GETTER long long arraySize();
    OLUA_GETTER bool isTransparentTagTypedef();
    OLUA_GETTER TypeNullabilityKind nullability();
    OLUA_GETTER string nullabilitySpelling();
    OLUA_GETTER long long alignOf();
    OLUA_GETTER std::shared_ptr<Type> classType();
    OLUA_GETTER long long sizeOf();
    OLUA_GETTER std::shared_ptr<Type> modifiedType();
    OLUA_GETTER std::shared_ptr<Type> valueType();
    long long offsetOf(const char *field);
    OLUA_GETTER std::vector<std::shared_ptr<Type>> templateArgumentTypes();
    OLUA_GETTER RefQualifierKind cxxRefQualifier();
    OLUA_GETTER string cxxRefQualifierSpelling();
    OLUA_GETTER std::vector<std::shared_ptr<Cursor>> fields();
private:
    CXType _value;
};

using CursorKind = CXCursorKind;
using LinkageKind = CXLinkageKind;
using VisibilityKind = CXVisibilityKind;
using AvailabilityKind = CXAvailabilityKind;
using LanguageKind = CXLanguageKind;
using TLSKind = CXTLSKind;
using TemplateArgumentKind = CXTemplateArgumentKind;
using CXXAccessSpecifier = CX_CXXAccessSpecifier;
using StorageClass = CX_StorageClass;

class Cursor : public IndexError, public std::enable_shared_from_this<Cursor>
{
public:
    struct SourceRange {
        std::string path;
        unsigned int startLine = 0;
        unsigned int startColumn = 0;
        unsigned int endLine = 0;
        unsigned int endColumn = 0;
    };
    struct SourceLocation {
        std::string path;
        unsigned int line = 0;
        unsigned int column = 0;
    };
public:
    OLUA_EXCLUDE Cursor(CXCursor value);
    ~Cursor();
    
    olua_Return __eq(lua_State *L, Cursor *c);
    
    OLUA_GETTER string name();
    OLUA_GETTER CursorKind kind();
    OLUA_GETTER string kindSpelling();
    OLUA_GETTER bool isNull();
    unsigned hashCursor();
    OLUA_GETTER bool isDeclaration();
    OLUA_GETTER bool isInvalidDeclaration();
    OLUA_GETTER bool isReference();
    OLUA_GETTER bool isExpression();
    OLUA_GETTER bool isStatement();
    OLUA_GETTER bool isAttribute();
    OLUA_GETTER bool hasAttrs();
    OLUA_GETTER bool isInvalid();
    OLUA_GETTER bool isTranslationUnit();
    OLUA_GETTER bool isPreprocessing();
    OLUA_GETTER bool isUnexposed();
    OLUA_GETTER LinkageKind linkage();
    OLUA_GETTER string linkageSpelling();
    OLUA_GETTER VisibilityKind visibility();
    OLUA_GETTER string visibilitySpelling();
    OLUA_GETTER AvailabilityKind availability();
    OLUA_GETTER string availabilitySpelling();
    OLUA_GETTER std::shared_ptr<Cursor> varDeclInitializer();
    OLUA_GETTER int hasVarDeclGlobalStorage();
    OLUA_GETTER int hasVarDeclExternalStorage();
    OLUA_GETTER LanguageKind language();
    OLUA_GETTER string languageSpelling();
    OLUA_GETTER TLSKind tlsKind();
    OLUA_GETTER string tlsKindSpelling();
    OLUA_GETTER std::shared_ptr<TranslationUnit> translationUnit();
    OLUA_GETTER std::shared_ptr<Cursor> parent();
    OLUA_GETTER std::shared_ptr<Cursor> semanticParent();
    OLUA_GETTER std::shared_ptr<Cursor> lexicalParent();
    OLUA_GETTER std::shared_ptr<File> includedFile();
    OLUA_GETTER SourceRange sourceRange();
    OLUA_GETTER SourceLocation sourceLocation();
    OLUA_GETTER std::shared_ptr<Type> type();
    OLUA_GETTER std::shared_ptr<Type> underlyingType();
    OLUA_GETTER std::shared_ptr<Type> enumDeclIntegerType();
    OLUA_GETTER long long enumConstantDeclValue();
    OLUA_GETTER unsigned long long enumConstantDeclUnsignedValue();
    OLUA_GETTER int fieldDeclBitWidth();
    OLUA_GETTER std::vector<std::shared_ptr<Cursor>> arguments();
    OLUA_GETTER std::vector<std::shared_ptr<Type>> templateArgumentTypes();
    TemplateArgumentKind templateArgumentKind(unsigned index);
    string templateArgumentKindSpelling(unsigned index);
    long long templateArgumentValue(unsigned index);
    unsigned long long templateArgumentUnsignedValue(unsigned index);
    OLUA_GETTER bool isMacroFunctionLike();
    OLUA_GETTER bool isMacroBuiltin();
    OLUA_GETTER bool isFunctionInlined();
    OLUA_GETTER std::shared_ptr<Type> resultType();
    OLUA_GETTER int exceptionSpecificationType();
    OLUA_GETTER long long offsetOfField();
    OLUA_GETTER bool isAnonymous();
    OLUA_GETTER bool isAnonymousRecordDecl();
    OLUA_GETTER bool isInlineNamespace();
    OLUA_GETTER bool isBitField();
    OLUA_GETTER bool isVirtualBase();
    OLUA_GETTER bool isDeprecated();
    OLUA_GETTER CXXAccessSpecifier cxxAccessSpecifier();
    OLUA_GETTER string cxxAccessSpecifierSpelling();
    OLUA_GETTER StorageClass storageClass();
    OLUA_GETTER string storageClassSpelling();
    OLUA_GETTER std::vector<std::shared_ptr<Cursor>> overloadedDecls();
    OLUA_GETTER std::shared_ptr<Type> ibOutletCollectionType();
    OLUA_GETTER std::vector<std::shared_ptr<Cursor>> children();
    SourceRange nameRange(unsigned pieceIndex, unsigned options);
    OLUA_GETTER string prettyPrinted();
    OLUA_GETTER string displayName();
    OLUA_GETTER std::shared_ptr<Cursor> referenced();
    OLUA_GETTER std::shared_ptr<Cursor> definition();
    OLUA_GETTER bool isDefinition();
    OLUA_GETTER std::shared_ptr<Cursor> canonical();
    OLUA_GETTER int isDynamicCall();
    OLUA_GETTER std::shared_ptr<Type> receiverType();
    OLUA_GETTER bool isVariadic();
    OLUA_GETTER SourceRange commentRange();
    OLUA_GETTER string rawCommentText();
    OLUA_GETTER string briefCommentText();
    OLUA_GETTER string mangling();
    OLUA_GETTER std::vector<string> cxxManglings();
    std::shared_ptr<Module> getModule();
    OLUA_GETTER bool isCXXConvertingConstructor();
    OLUA_GETTER bool isCXXCopyConstructor();
    OLUA_GETTER bool isCXXDefaultConstructor();
    OLUA_GETTER bool isCXXMoveConstructor();
    OLUA_GETTER bool isCXXFieldMutable();
    OLUA_GETTER bool isCXXMethodDefaulted();
    OLUA_GETTER bool isCXXMethoDeleted();
    OLUA_GETTER bool isCXXMethoPureVirtual();
    OLUA_GETTER bool isCXXMethoStatic();
    OLUA_GETTER bool isCXXMethoVirtual();
    OLUA_GETTER bool isCXXMethoCopyAssignmentOperator();
    OLUA_GETTER bool isCXXMethoConst();
    OLUA_GETTER bool isCXXMethoAbstract();
    OLUA_GETTER bool isEnumDeclScoped();
    OLUA_GETTER CursorKind templateKind();
    OLUA_GETTER string templateKindSpelling();
    OLUA_GETTER std::shared_ptr<Cursor> specializedTemplate();
    SourceRange referenceNameRange(unsigned pieceIndex, unsigned options);
private:
    CXCursor _value;
};

class Module : public IndexError, public std::enable_shared_from_this<Module> {
    friend class TranslationUnit;
public:
    OLUA_EXCLUDE Module(CXModule value);
    ~Module();
    
    OLUA_GETTER std::shared_ptr<File> astFile();
    OLUA_GETTER std::shared_ptr<Module> parent();
    OLUA_GETTER string name();
    OLUA_GETTER string fullName();
    OLUA_GETTER int isSystem();
private:
    CXModule _value;
};

class TranslationUnit : public IndexError, public std::enable_shared_from_this<TranslationUnit>
{
public:
    OLUA_EXCLUDE TranslationUnit(CXTranslationUnit value, bool owner);
    ~TranslationUnit();
    
    OLUA_GETTER string name();
    OLUA_GETTER std::shared_ptr<Cursor> cursor();
    
    bool isFileMultipleIncludeGuarded(File *f);
    std::shared_ptr<File> getFile(const std::string &path);
    string getFileContents(File *f);
    OLUA_GETTER std::vector<std::shared_ptr<Diagnostic>> diagnostics();
    OLUA_GETTER std::set<std::shared_ptr<Diagnostic>> diagnosticSetFromTU();
    std::shared_ptr<Module> moduleForFile(const std::shared_ptr<File> &file);
    unsigned numTopLevelHeaders(const std::shared_ptr<Module> &m);
    std::shared_ptr<File> topLevelHeader(const std::shared_ptr<Module> &m, unsigned index);
    unsigned defaultSaveOptions();
    int saveTranslationUnit(const std::string &path, unsigned options);
    unsigned suspendTranslationUnit();
    unsigned defaultReparseOptions();
private:
    CXTranslationUnit _value;
    std::shared_ptr<Cursor> _cursor;
    bool _owner;
};

using GlobalOptFlags = CXGlobalOptFlags;

class Index : public IndexError, public std::enable_shared_from_this<Index>
{
public:
    OLUA_EXCLUDE Index(bool excludeDeclarationsFromPCH, bool displayDiagnostics);
    ~Index();
    
    std::shared_ptr<TranslationUnit> create(const std::string &path);
    std::shared_ptr<TranslationUnit> parse(const std::string &path, const std::vector<std::string> args, unsigned int options = (unsigned int)CXTranslationUnit_SkipFunctionBodies);
    
    void setGlobalOptions(unsigned options);
    unsigned getGlobalOptions();
    void setInvocationEmissionPathOption(const std::string &path);
private:
    CXIndex _value;
};

class clang {
public:
    static std::shared_ptr<Index> createIndex(bool excludeDeclarationsFromPCH, bool displayDiagnostics);
    
    OLUA_GETTER static const std::string version();
    static bool debug;
    OLUA_EXCLUDE static int count;
};

}

int olua_push_string(lua_State *L, const clangwrapper::string &value);

#endif
