#ifndef __LUACLANG_CLANG_WRAPPER_H__
#define __LUACLANG_CLANG_WRAPPER_H__

#include "clang-c/Index.h"
#include "olua/olua.hpp"

#include <memory>

#define LUACLANG_VERSION "2.2"

namespace clangwrapper {

using AvailabilityKind = CXAvailabilityKind;
using CallingConv = CXCallingConv;
using CursorKind = CXCursorKind;
using CXXAccessSpecifier = CX_CXXAccessSpecifier;
using DiagnosticSeverity = CXDiagnosticSeverity;
using GlobalOptFlags = CXGlobalOptFlags;
using LanguageKind = CXLanguageKind;
using LinkageKind = CXLinkageKind;
using RefQualifierKind = CXRefQualifierKind;
using StorageClass = CX_StorageClass;
using TemplateArgumentKind = CXTemplateArgumentKind;
using TLSKind = CXTLSKind;
using TypeKind = CXTypeKind;
using TypeNullabilityKind = CXTypeNullabilityKind;
using VisibilityKind = CXVisibilityKind;

class TranslationUnit;
class Cursor;
class Module;
class Type;
class File;
class Diagnostic;

enum CXVisitorResult fieldVisitor(CXCursor cur, CXClientData client_data);
enum CXChildVisitResult childrenVisitor(CXCursor cursor, CXCursor parent, CXClientData client_data);
std::shared_ptr<Cursor> makeCursor(CXCursor value);
std::shared_ptr<Type> makeType(CXType value);
std::shared_ptr<File> makeFile(CXFile value);
std::shared_ptr<Module> makeModule(CXModule value);
std::shared_ptr<Diagnostic> makeDiagnostic(CXDiagnostic value);

struct string {
    std::string data;
    bool isNull = true;
    
    string() = default;
    string(const string &) = default;
    
    string(CXString value) {
        if (value.data) {
            isNull = false;
            data = std::string(clang_getCString(value));
            clang_disposeString(value);
        }
    }
    
    string(const char *value) {
        if (value) {
            isNull = false;
            data = std::string(value);
        }
    }
    
    string(const char *value, size_t len) {
        if (value) {
            isNull = false;
            data = std::string(value, len);
        }
    }
};

class IndexError {
public:
    olua_Return __index(lua_State *L) {
        return olua_indexerror(L);
    }

    olua_Return __newindex(lua_State *L) {
        return olua_newindexerror(L);
    }
};


class Diagnostic : public IndexError, public std::enable_shared_from_this<Diagnostic> {
public:
    OLUA_EXCLUDE Diagnostic(CXDiagnostic value);
    ~Diagnostic();
    
    /** @oluasee clang_getDiagnosticSpelling */
    OLUA_GETTER string name() {
        return clang_getDiagnosticSpelling(_value);
    }

    /** @oluasee clang_getDiagnosticCategory */
    OLUA_GETTER unsigned category() {
        return clang_getDiagnosticCategory(_value);
    }

    /** @oluasee clang_getDiagnosticCategoryText */
    OLUA_GETTER string categoryText() {
        return clang_getDiagnosticCategoryText(_value);
    }

    /** @oluasee clang_defaultDiagnosticDisplayOptions */
    OLUA_GETTER string text() {
        return formatDiagnostic(clang_defaultDiagnosticDisplayOptions());
    }

    /** @oluasee clang_getDiagnosticSeverity */
    OLUA_GETTER DiagnosticSeverity severity() {
        return clang_getDiagnosticSeverity(_value);
    }

    /** @oluasee clang_getDiagnosticSeverity */
    OLUA_GETTER string severitySeplling() {
        static const char *const ns[] = {"Ignored", "Note", "Warning", "Error", "Fatal"};
        return ns[clang_getDiagnosticSeverity(_value)];
    }

    /** @oluasee clang_formatDiagnostic */
    string formatDiagnostic(unsigned options) {
        return clang_formatDiagnostic(_value, options);
    }
private:
    CXDiagnostic _value;
};

class File : public IndexError, public std::enable_shared_from_this<File>
{
    friend class TranslationUnit;
public:
    OLUA_EXCLUDE File(CXFile value);
    
    olua_Return __eq(lua_State *L, File *f) {
        return clang_File_isEqual(_value, f->_value);
    }
    
    /** @oluasee clang_getFileName */
    OLUA_GETTER string fileName() {
        return clang_getFileName(_value);
    }

    /** @oluasee clang_getFileTime */
    OLUA_GETTER time_t fileTime() {
        return clang_getFileTime(_value);
    }
    
    /** @oluasee clang_File_tryGetRealPathName */
    string tryGetRealPathName() {
        return clang_File_tryGetRealPathName(_value);
    }
private:
    CXFile _value;
};

/**
 * @oluasee CXType
 */
class Type : public IndexError, public std::enable_shared_from_this<Type>
{
public:
    OLUA_EXCLUDE Type(CXType value);
    ~Type();
    
    olua_Return __eq(lua_State *L, Type *t) {
        return clang_equalTypes(_value, t->_value);
    }
    
    /** @oluasee clang_getTypeSpelling */
    OLUA_GETTER string name() {
        return clang_getTypeSpelling(_value);
    }

    /** The kind of type */
    OLUA_GETTER TypeKind kind() {
        return _value.kind;
    }

    /** @oluasee clang_getTypeKindSpelling */
    OLUA_GETTER string kindSpelling() {
        return clang_getTypeKindSpelling(_value.kind);
    }

    /** @oluasee clang_getCanonicalType */
    OLUA_GETTER std::shared_ptr<Type> canonicalType() {
        return makeType(clang_getCanonicalType(_value));
    }

    /** @oluasee clang_isConstQualifiedType */
    OLUA_GETTER bool isConstQualified() {
        return clang_isConstQualifiedType(_value);
    }
    /** @oluasee clang_isVolatileQualifiedType */
    OLUA_GETTER bool isVolatileQualified() {
        return clang_isVolatileQualifiedType(_value);
    }

    /** @oluasee clang_isRestrictQualifiedType */
    OLUA_GETTER bool isRestrictQualified() {
        return clang_isRestrictQualifiedType(_value);
    }

    /** @oluasee clang_getAddressSpace */
    OLUA_GETTER unsigned addressSpace() {
        return clang_getAddressSpace(_value);
    }

    /** @oluasee clang_getTypedefName */
    OLUA_GETTER string typedefName() {
        return clang_getTypedefName(_value);
    }

    /** @oluasee clang_Type_getNamedType */
    OLUA_GETTER std::shared_ptr<Type> namedType() {
        return makeType(clang_Type_getNamedType(_value));
    }

    /** @oluasee clang_getPointeeType */
    OLUA_GETTER std::shared_ptr<Type> pointeeType(){
        return makeType(clang_getPointeeType(_value));
    }

    /** @oluasee clang_getUnqualifiedType */
    OLUA_GETTER std::shared_ptr<Type> unqualifiedType() {
        return makeType(clang_getUnqualifiedType(_value));
    }

    /** @oluasee clang_getNonReferenceType */
    OLUA_GETTER std::shared_ptr<Type> nonReferenceType() {
        return makeType(clang_getNonReferenceType(_value));
    }

    /** @oluasee clang_getTypeDeclaration */
    OLUA_GETTER std::shared_ptr<Cursor> declaration() {
        return makeCursor(clang_getTypeDeclaration(_value));
    }

    /** @oluasee clang_getResultType */
    OLUA_GETTER std::shared_ptr<Type> resultType() {
        return makeType(clang_getResultType(_value));
    }

    /** @oluasee clang_getExceptionSpecificationType */
    OLUA_GETTER int exceptionSpecificationType() {
        return clang_getExceptionSpecificationType(_value);
    }

    /** @oluasee clang_isFunctionTypeVariadic */
    OLUA_GETTER bool isFunctionTypeVariadic() {
        return clang_isFunctionTypeVariadic(_value);
    }

    /** @oluasee clang_getFunctionTypeCallingConv */
    OLUA_GETTER CallingConv functionTypeCallingConv() {
        return clang_getFunctionTypeCallingConv(_value);
    }

    /** @oluasee clang_getArgType */
    OLUA_GETTER std::vector<std::shared_ptr<Type>> argTypes() {
        std::vector<std::shared_ptr<Type>> arr;
        int n = clang_getNumArgTypes(_value);
        for (int i = 0; i < n; i++) {
            arr.push_back(makeType(clang_getArgType(_value, i)));
        }
        return arr;
    }

    /** @oluasee clang_getArgType */
    std::shared_ptr<Type> getArgType(unsigned int i) {
        return makeType(clang_getArgType(_value, i));
    }

    /** @oluasee clang_isPODType */
    OLUA_GETTER bool isPOD() {
        return clang_isPODType(_value);
    }

    /** @oluasee clang_getElementType */
    OLUA_GETTER std::shared_ptr<Type> elementType() {
        return makeType(clang_getElementType(_value));
    }

    /** @oluasee clang_getArrayElementType */
    OLUA_GETTER std::shared_ptr<Type> arrayElementType() {
        return makeType(clang_getArrayElementType(_value));
    }
    /** @oluasee clang_getNumElements */
    OLUA_GETTER long long numElements() {
        return clang_getNumElements(_value);
    }

    /** @oluasee clang_getArraySize */
    OLUA_GETTER long long arraySize() {
        return clang_getArraySize(_value);
    }
    
    /** @oluasee clang_Type_isTransparentTagTypedef */
    OLUA_GETTER bool isTransparentTagTypedef() {
        return clang_Type_isTransparentTagTypedef(_value);
    }

    /** @oluasee clang_Type_getNullability */
    OLUA_GETTER TypeNullabilityKind nullability() {
        return clang_Type_getNullability(_value);
    }

    /** @oluasee clang_Type_getNullability */
    OLUA_GETTER string nullabilitySpelling() {
    static const char *const ns[] = {"NonNull", "Nullable", "Unspecified", "Invalid", "NullableResult"};
        return ns[clang_Type_getNullability(_value)];
    }

    /** @oluasee clang_Type_getAlignOf */
    OLUA_GETTER long long alignOf() {
        return clang_Type_getAlignOf(_value);
    }

    /** clang_Type_getClassType */
    OLUA_GETTER std::shared_ptr<Type> classType() {
        return makeType(clang_Type_getClassType(_value));
    }

    /** @oluasee clang_Type_getSizeOf */
    OLUA_GETTER long long sizeOf() {
        return clang_Type_getSizeOf(_value);
    }

    /** @oluasee clang_Type_getModifiedType */
    OLUA_GETTER std::shared_ptr<Type> modifiedType() {
        return makeType(clang_Type_getModifiedType(_value));
    }

    /** @oluasee clang_Type_getValueType */
    OLUA_GETTER std::shared_ptr<Type> valueType() {
        return makeType(clang_Type_getValueType(_value));
    }
    /** @oluasee clang_Type_getOffsetOf */
    long long offsetOf(const char *field) {
        return clang_Type_getOffsetOf(_value, field);
    }

    /** @oluasee clang_Type_getTemplateArgumentAsType */
    OLUA_GETTER std::vector<std::shared_ptr<Type>> templateArgumentTypes() {
         std::vector<std::shared_ptr<Type>> arr;
        int n = clang_Type_getNumTemplateArguments(_value);
        for (int i = 0; i < n; i++) {
            arr.push_back(makeType(clang_Type_getTemplateArgumentAsType(_value, i)));
        }
        return arr;
    }

    std::shared_ptr<Type> getTemplateArgument(unsigned int i) {
        return makeType(clang_Type_getTemplateArgumentAsType(_value, i));
    }

    /** @oluasee clang_Type_getCXXRefQualifier */
    OLUA_GETTER RefQualifierKind cxxRefQualifier() {
        return clang_Type_getCXXRefQualifier(_value);
    }
    
    /** @oluasee clang_Type_getCXXRefQualifier */
    OLUA_GETTER string cxxRefQualifierSpelling() {
        static const char *const ns[] = {"None", "LValue", "RValue"};
        return ns[clang_Type_getCXXRefQualifier(_value)];
    }

    /** Get the fields of a record type */
    OLUA_GETTER std::vector<std::shared_ptr<Cursor>> fields() {
        std::vector<std::shared_ptr<Cursor>> arr;
        clang_Type_visitFields(_value, fieldVisitor, &arr);
        return arr;
    }
private:
    CXType _value;
};

/**
 * @oluasee CXCursor
 */
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
    
    olua_Return __eq(lua_State *L, Cursor *c) {
        return clang_equalCursors(_value, c->_value);
    }
    
    /** @oluasee clang_getCursorSpelling */
    OLUA_GETTER string name() {
        return clang_getCursorSpelling(_value);
    }

    /** @oluasee clang_getCursorKind */
    OLUA_GETTER CursorKind kind() {
        return clang_getCursorKind(_value);
    }

    /** @oluasee clang_getCursorKindSpelling */
    OLUA_GETTER string kindSpelling() {
        return clang_getCursorKindSpelling(clang_getCursorKind(_value));
    }

    /** @oluasee clang_Cursor_isNull */
    OLUA_GETTER bool isNull() {
        return clang_Cursor_isNull(_value);
    }

    /** @oluasee clang_hashCursor */
    unsigned hashCursor() {
        return clang_hashCursor(_value);
    }

    /** @oluasee clang_isDeclaration */
    OLUA_GETTER bool isDeclaration() {
        return clang_isDeclaration(clang_getCursorKind(_value));
    }

    /** @oluasee clang_isInvalidDeclaration */
    OLUA_GETTER bool isInvalidDeclaration() {
        return clang_isInvalidDeclaration(_value);
    }

    /** @oluasee clang_isReference */
    OLUA_GETTER bool isReference() {
        return clang_isReference(clang_getCursorKind(_value));
    }

    /** @oluasee clang_isExpression */
    OLUA_GETTER bool isExpression() {
        return clang_isExpression(clang_getCursorKind(_value));
    }

    /** @oluasee clang_isStatement */
    OLUA_GETTER bool isStatement() {
        return clang_isStatement(clang_getCursorKind(_value));
    }

    /** @oluasee clang_isAttribute */
    OLUA_GETTER bool isAttribute() {
        return clang_isAttribute(clang_getCursorKind(_value));
    }

    /** @oluasee clang_Cursor_hasAttrs */
    OLUA_GETTER bool hasAttrs() {
        return clang_Cursor_hasAttrs(_value);
    }

    /** @oluasee clang_isInvalid */
    OLUA_GETTER bool isInvalid() {
        return clang_isInvalid(clang_getCursorKind(_value));
    }

    /** @oluasee clang_isTranslationUnit */
    OLUA_GETTER bool isTranslationUnit() {
        return clang_isTranslationUnit(clang_getCursorKind(_value));
    }

    /** @oluasee clang_isPreprocessing */
    OLUA_GETTER bool isPreprocessing() {
        return clang_isPreprocessing(clang_getCursorKind(_value));
    }

    /** @oluasee clang_isUnexposed */
    OLUA_GETTER bool isUnexposed() {
        return clang_isUnexposed(clang_getCursorKind(_value));
    }

    /** @oluasee clang_getCursorLinkage */
    OLUA_GETTER LinkageKind linkage() {
        return clang_getCursorLinkage(_value);
    }

    /** @oluasee clang_getCursorVisibility */
    OLUA_GETTER VisibilityKind visibility() {
        return clang_getCursorVisibility(_value);
    }

    /** @oluasee clang_getCursorAvailability */
    OLUA_GETTER AvailabilityKind availability() {
        return clang_getCursorAvailability(_value);
    }

    /** @oluasee clang_Cursor_getVarDeclInitializer */
    OLUA_GETTER std::shared_ptr<Cursor> varDeclInitializer() {
        return makeCursor(clang_Cursor_getVarDeclInitializer(_value));
    }

    /** @oluasee clang_Cursor_hasVarDeclGlobalStorage */
    OLUA_GETTER int hasVarDeclGlobalStorage() {
        return clang_Cursor_hasVarDeclGlobalStorage(_value);
    }

    /** @oluasee clang_Cursor_hasVarDeclExternalStorage */
    OLUA_GETTER int hasVarDeclExternalStorage() {
        return clang_Cursor_hasVarDeclExternalStorage(_value);
    }

    /** @oluasee clang_getCursorLanguage */
    OLUA_GETTER LanguageKind language() {
        return clang_getCursorLanguage(_value);
    }

    /** @oluasee clang_getCursorTLSKind */
    OLUA_GETTER TLSKind tlsKind() {
        return clang_getCursorTLSKind(_value);
    }

    /** @oluasee clang_Cursor_getTranslationUnit */
    OLUA_GETTER std::shared_ptr<TranslationUnit> translationUnit() {
        return std::make_shared<TranslationUnit>(clang_Cursor_getTranslationUnit(_value), false);
    }

    /** @oluasee clang_getCursorSemanticParent */
    OLUA_GETTER std::shared_ptr<Cursor> parent() {
        return semanticParent();
    }

    /** @oluasee clang_getCursorSemanticParent */
    OLUA_GETTER std::shared_ptr<Cursor> semanticParent() {
        return makeCursor(clang_getCursorSemanticParent(_value));
    }

    /** @oluasee clang_getCursorLexicalParent */
    OLUA_GETTER std::shared_ptr<Cursor> lexicalParent() {
        return makeCursor(clang_getCursorLexicalParent(_value));
    }

    /** @oluasee clang_getIncludedFile */
    OLUA_GETTER std::shared_ptr<File> includedFile() {
        return makeFile(clang_getIncludedFile(_value));
    }

    /** @oluasee clang_getCursorExtent */
    OLUA_GETTER SourceRange sourceRange() {
        CXSourceRange range = clang_getCursorExtent(_value);
        return getRange(range);
    }

    /** @oluasee clang_getCursorLocation */
    OLUA_GETTER SourceLocation sourceLocation() {
        SourceLocation ret;
        CXFile file;
        CXSourceLocation location = clang_getCursorLocation(_value);
        clang_getSpellingLocation(location, &file, &ret.line, &ret.column, NULL);
        ret.path = string(clang_getFileName(file)).data;
        return ret;
    }

    /** @oluasee clang_getCursorType */
    OLUA_GETTER std::shared_ptr<Type> type() {
        return makeType(clang_getCursorType(_value));
    }

    /** @oluasee clang_getTypedefDeclUnderlyingType */
    OLUA_GETTER std::shared_ptr<Type> underlyingType() {
        return makeType(clang_getTypedefDeclUnderlyingType(_value));
    }

    /** @oluasee clang_getEnumDeclIntegerType */
    OLUA_GETTER std::shared_ptr<Type> enumDeclIntegerType() {
        return makeType(clang_getEnumDeclIntegerType(_value));
    }

    /** @oluasee clang_getEnumConstantDeclValue */
    OLUA_GETTER long long enumConstantDeclValue() {
        return clang_getEnumConstantDeclValue(_value);
    }

    /** @oluasee clang_getEnumConstantDeclUnsignedValue */
    OLUA_GETTER unsigned long long enumConstantDeclUnsignedValue() {
        return clang_getEnumConstantDeclUnsignedValue(_value);
    }

    /** @oluasee clang_getFieldDeclBitWidth */
    OLUA_GETTER int fieldDeclBitWidth() {
        return clang_getFieldDeclBitWidth(_value);
    }

    /** @oluasee clang_Cursor_getArgument  */
    OLUA_GETTER std::vector<std::shared_ptr<Cursor>> arguments() {
        std::vector<std::shared_ptr<Cursor>> arr;
        int n = clang_Cursor_getNumArguments(_value);
        for (int i = 0; i < n; i++) {
            arr.push_back(makeCursor(clang_Cursor_getArgument(_value, i)));
        }
        return arr;
    }

    /** @oluasee clang_Cursor_getTemplateArgumentType */
    OLUA_GETTER std::vector<std::shared_ptr<Type>> templateArgumentTypes() {
        std::vector<std::shared_ptr<Type>> arr;
        int n = clang_Cursor_getNumTemplateArguments(_value);
        for (int i = 0; i < n; i++) {
            arr.push_back(makeType(clang_Cursor_getTemplateArgumentType(_value, i)));
        }
        return arr;
    }

    /** @oluasee clang_Cursor_getTemplateArgumentValue */
    TemplateArgumentKind templateArgumentKind(unsigned index) {
        return clang_Cursor_getTemplateArgumentKind(_value, index);
    }

    /** @oluasee clang_Cursor_getTemplateArgumentValue */
    long long templateArgumentValue(unsigned index) {
        return clang_Cursor_getTemplateArgumentValue(_value, index);
    }

    /** @oluasee clang_Cursor_getTemplateArgumentUnsignedValue */
    unsigned long long templateArgumentUnsignedValue(unsigned index) {
        return clang_Cursor_getTemplateArgumentUnsignedValue(_value, index);
    }

    /** @oluasee clang_Cursor_isMacroFunctionLike */
    OLUA_GETTER bool isMacroFunctionLike() {
        return clang_Cursor_isMacroFunctionLike(_value);
    }

    /** @oluasee clang_Cursor_isMacroBuiltin */
    OLUA_GETTER bool isMacroBuiltin() {
        return clang_Cursor_isMacroBuiltin(_value);
    }

    /** @oluasee clang_Cursor_isFunctionInlined */
    OLUA_GETTER bool isFunctionInlined() {
        return clang_Cursor_isFunctionInlined(_value);
    }

    /** @oluasee clang_getCursorResultType */
    OLUA_GETTER std::shared_ptr<Type> resultType() {
        return makeType(clang_getCursorResultType(_value));
    }

    /** @oluasee clang_getCursorExceptionSpecificationType */
    OLUA_GETTER int exceptionSpecificationType() {
        return clang_getCursorExceptionSpecificationType(_value);
    }

    /** @oluasee clang_Cursor_getOffsetOfField */
    OLUA_GETTER long long offsetOfField() {
        return clang_Cursor_getOffsetOfField(_value);
    }

    /** @oluasee clang_Cursor_isAnonymous */
    OLUA_GETTER bool isAnonymous() {
        return clang_Cursor_isAnonymous(_value);
    }

    /** @oluasee clang_Cursor_isAnonymousRecordDecl */
    OLUA_GETTER bool isAnonymousRecordDecl() {
        return clang_Cursor_isAnonymousRecordDecl(_value);
    }

    /** @oluasee clang_Cursor_isInlineNamespace */
    OLUA_GETTER bool isInlineNamespace() {
        return clang_Cursor_isInlineNamespace(_value);
    }

    /** @oluasee clang_Cursor_isBitField */
    OLUA_GETTER bool isBitField() {
        return clang_Cursor_isBitField(_value);
    }

    /** @oluasee clang_isVirtualBase */
    OLUA_GETTER bool isVirtualBase() {
        return clang_isVirtualBase(_value);
    }

    /** Is this a deprecated member */
    OLUA_GETTER bool isDeprecated() {
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

    /** @oluasee clang_getCXXAccessSpecifier */
    OLUA_GETTER CXXAccessSpecifier cxxAccessSpecifier() {
        return clang_getCXXAccessSpecifier(_value);
    }

    /** @oluasee clang_getCXXAccessSpecifier */
    OLUA_GETTER string cxxAccessSpecifierSpelling() {
        static const char *const ns[] = {"Invalid", "Public", "Protected", "Private"};
        return ns[clang_getCXXAccessSpecifier(_value)];
    }

    /** @oluasee clang_Cursor_getStorageClass */
    OLUA_GETTER StorageClass storageClass() {
        return clang_Cursor_getStorageClass(_value);
    }

    /** @oluasee clang_getOverloadedDecl */
    OLUA_GETTER std::vector<std::shared_ptr<Cursor>> overloadedDecls() {
        std::vector<std::shared_ptr<Cursor>> arr;
        int n = clang_getNumOverloadedDecls(_value);
        for (int i = 0; i < n; i++) {
            arr.push_back(makeCursor(clang_getOverloadedDecl(_value, i)));
        }
        return arr;
    }

    /** @oluasee clang_getIBOutletCollectionType */
    OLUA_GETTER std::shared_ptr<Type> ibOutletCollectionType() {
        return makeType(clang_getIBOutletCollectionType(_value));
    }
    
    /** @oluasee clang_visitChildren */
    OLUA_GETTER std::vector<std::shared_ptr<Cursor>> children() {
         std::vector<std::shared_ptr<Cursor>> arr;
        clang_visitChildren(_value, childrenVisitor, (void *)&arr);
        return arr;
    }

    /** @oluasee clang_Cursor_getSpellingNameRange */
    SourceRange nameRange(unsigned pieceIndex, unsigned options) {
        CXSourceRange range = clang_Cursor_getSpellingNameRange(_value, pieceIndex, options);
        return getRange(range);
    }

    /** @oluasee clang_getCursorPrettyPrinted */
    OLUA_GETTER string prettyPrinted() {
        return clang_getCursorPrettyPrinted(_value, NULL);
    }

    /** @oluasee clang_getCursorDisplayName */
    OLUA_GETTER string displayName() {
        return clang_getCursorDisplayName(_value);
    }

    /** @oluasee clang_getCursorReferenced */
    OLUA_GETTER std::shared_ptr<Cursor> referenced() {
        return makeCursor(clang_getCursorReferenced(_value));
    }

    /** @oluasee clang_getCursorDefinition */
    OLUA_GETTER std::shared_ptr<Cursor> definition() {
        return makeCursor(clang_getCursorDefinition(_value));
    }

    /** @oluasee clang_isCursorDefinition */
    OLUA_GETTER bool isDefinition() {
        return clang_isCursorDefinition(_value);
    }

    /** @oluasee clang_getCanonicalCursor */
    OLUA_GETTER std::shared_ptr<Cursor> canonical() {
        return makeCursor(clang_getCanonicalCursor(_value));
    }

    /** @oluasee clang_Cursor_isDynamicCall */
    OLUA_GETTER int isDynamicCall() {
        return clang_Cursor_isDynamicCall(_value);
    }

    /** @oluasee clang_Cursor_getReceiverType */
    OLUA_GETTER std::shared_ptr<Type> receiverType() {
        return makeType(clang_Cursor_getReceiverType(_value));
    }

    /** @oluasee clang_Cursor_isVariadic */
    OLUA_GETTER bool isVariadic() {
        return clang_Cursor_isVariadic(_value);
    }

    /** @oluasee clang_Cursor_getCommentRange */
    OLUA_GETTER SourceRange commentRange() {
        CXSourceRange range = clang_Cursor_getCommentRange(_value);
        return getRange(range);
    }

    /** @oluasee clang_Cursor_getRawCommentText */
    OLUA_GETTER string rawCommentText() {
        return clang_Cursor_getRawCommentText(_value);
    }

    /** @oluasee clang_Cursor_getBriefCommentText */
    OLUA_GETTER string briefCommentText() {
        return clang_Cursor_getBriefCommentText(_value);
    }

    /** @oluasee clang_Cursor_getMangling */
    OLUA_GETTER string mangling() {
        return clang_Cursor_getMangling(_value);
    }

    /** @oluasee clang_Cursor_getCXXManglings */
    OLUA_GETTER std::vector<string> cxxManglings() {
        CXStringSet *set = clang_Cursor_getCXXManglings(_value);
        std::vector<string> strs;
        for (int i = 0; i < (int)set->Count; i++) {
            strs.push_back(set->Strings[i]);
        }
        clang_disposeStringSet(set);
        return strs;
    }

    /** @oluasee clang_Cursor_getModule */
    std::shared_ptr<Module> getModule() {
        return makeModule(clang_Cursor_getModule(_value));
    }

    /** @oluasee clang_CXXConstructor_isConvertingConstructor */
    OLUA_GETTER bool isCXXConvertingConstructor() {
        return clang_CXXConstructor_isConvertingConstructor(_value);
    }

    /** @oluasee clang_CXXConstructor_isCopyConstructor */
    OLUA_GETTER bool isCXXCopyConstructor() {
        return clang_CXXConstructor_isCopyConstructor(_value);
    }

    /** @oluasee clang_CXXConstructor_isDefaultConstructor */
    OLUA_GETTER bool isCXXDefaultConstructor() {
        return clang_CXXConstructor_isDefaultConstructor(_value);
    }

    /** @oluasee clang_CXXConstructor_isMoveConstructor */
    OLUA_GETTER bool isCXXMoveConstructor() {
        return clang_CXXConstructor_isMoveConstructor(_value);
    }

    /** @oluasee clang_CXXField_isMutable */
    OLUA_GETTER bool isCXXFieldMutable() {
        return clang_CXXField_isMutable(_value);
    }

    /** @oluasee clang_CXXMethod_isDefaulted */
    OLUA_GETTER bool isCXXMethodDefaulted() {
        return clang_CXXMethod_isDefaulted(_value);
    }

    /** @oluasee clang_CXXMethod_isDeleted */
    OLUA_GETTER bool isCXXMethodDeleted() {
        return clang_CXXMethod_isDeleted(_value);
    }

    /** @oluasee clang_CXXMethod_isPureVirtual */
    OLUA_GETTER bool isCXXMethodPureVirtual() {
        return clang_CXXMethod_isPureVirtual(_value);
    }

    /** @oluasee clang_CXXMethod_isStatic */
    OLUA_GETTER bool isCXXMethodStatic() {
        return clang_CXXMethod_isStatic(_value);
    }

    /** @oluasee clang_CXXMethod_isVirtual */
    OLUA_GETTER bool isCXXMethodVirtual() {
        return clang_CXXMethod_isVirtual(_value);
    }

    /** @oluasee clang_CXXMethod_isCopyAssignmentOperator */
    OLUA_GETTER bool isCXXMethodCopyAssignmentOperator() {
        return clang_CXXMethod_isCopyAssignmentOperator(_value);
    }

    /** @oluasee clang_CXXMethod_isMoveAssignmentOperator */
    OLUA_GETTER bool isCXXMethodMoveAssignmentOperator() {
        return clang_CXXMethod_isMoveAssignmentOperator(_value);
    }

    /** @oluasee clang_CXXMethod_isConst */
    OLUA_GETTER bool isCXXMethodConst() {
        return clang_CXXMethod_isConst(_value);
    }

    /** @oluasee clang_CXXMethod_isExplicit */
    OLUA_GETTER bool isCXXMethodExplicit() {
        return clang_CXXMethod_isExplicit(_value);
    }

    /** @oluasee clang_CXXRecord_isAbstract */
    OLUA_GETTER bool isCXXAbstract() {
        return clang_CXXRecord_isAbstract(_value);
    }

    /** @oluasee clang_EnumDecl_isScoped */
    OLUA_GETTER bool isEnumDeclScoped() {
        return clang_EnumDecl_isScoped(_value);
    }

    /** @oluasee clang_getTemplateCursorKind */
    OLUA_GETTER CursorKind templateKind() {
        return clang_getTemplateCursorKind(_value);
    }

    /** @oluasee clang_getTemplateCursorKind */
    OLUA_GETTER string templateKindSpelling() {
        return clang_getCursorKindSpelling(clang_getTemplateCursorKind(_value));
    }

    /** @oluasee clang_getSpecializedCursorTemplate */
    OLUA_GETTER std::shared_ptr<Cursor> specializedTemplate() {
        return makeCursor(clang_getSpecializedCursorTemplate(_value));
    }

    /** @oluasee clang_getCursorReferenceNameRange */
    SourceRange referenceNameRange(unsigned pieceIndex, unsigned options) {
        CXSourceRange range = clang_getCursorReferenceNameRange(_value, pieceIndex, options);
        return getRange(range);
    }
private:
    SourceRange getRange(CXSourceRange range) {
        SourceRange ret;
        CXFile file;
        CXSourceLocation start = clang_getRangeStart(range);
        CXSourceLocation end = clang_getRangeEnd(range);
        clang_getSpellingLocation(start, &file, &ret.startLine, &ret.startColumn, NULL);
        clang_getSpellingLocation(end, &file, &ret.endLine, &ret.endColumn, NULL);
        ret.path = string(clang_getFileName(file)).data;
        return ret;
    }
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

/**
 * @oluasee CXTranslationUnit
 */
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


/**
 * @oluasee CXIndex
 */
class Index : public IndexError, public std::enable_shared_from_this<Index>
{
public:
    OLUA_EXCLUDE Index(bool excludeDeclarationsFromPCH, bool displayDiagnostics);
    ~Index();
    
    /** 
     * Create a translation unit from a source file 
     * @param path The path to the source file
     */
    std::shared_ptr<TranslationUnit> create(const std::string &path);

    /** @oluasee clang_parseTranslationUnit */
    std::shared_ptr<TranslationUnit> parse(const std::string &path, const std::vector<std::string> args, unsigned int options = (unsigned int)CXTranslationUnit_SkipFunctionBodies);
    
    void setGlobalOptions(unsigned options);
    unsigned getGlobalOptions();
    void setInvocationEmissionPathOption(const std::string &path);
private:
    CXIndex _value;
};

class clang {
public:
    /** @oluasee clang_createIndex */
    static std::shared_ptr<Index> createIndex(bool excludeDeclarationsFromPCH, bool displayDiagnostics);
    
    OLUA_GETTER static const std::string version();
    static bool debug;
    OLUA_EXCLUDE static int count;
};

}

int olua_push_string(lua_State *L, const clangwrapper::string &value);

#endif
