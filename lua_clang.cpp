#include "clang-c/Index.h"
#include "olua/olua.h"

#define CLANG_INDEX     "clang.CXIndex"
#define CLANG_TU        "clang.CXTranslationUnit"
#define CLANG_CURSOR    "clang.CXCursor"
#define CLANG_TYPE      "clang.CXType"

#define olua_toCXTranslationUnit(L, idx)    ((CXTranslationUnit)olua_toobj(L, idx, CLANG_TU))
#define olua_toCXIndex(L, idx)              ((CXIndex)olua_toobj(L, idx, CLANG_INDEX))
#define olua_toCXCursor(L, idx)             (*(CXCursor *)luaL_checkudata(L, idx, CLANG_CURSOR))
#define olua_toCXType(L, idx)               (*(CXType *)luaL_checkudata(L, idx, CLANG_TYPE))

static void olua_pushCXCursor(lua_State *L, CXCursor cur)
{
    if (clang_Cursor_isNull(cur)) {
        lua_pushnil(L);
    } else {
        *(CXCursor *)lua_newuserdata(L, sizeof(CXCursor)) = cur;
        olua_setmetatable(L, CLANG_CURSOR);
    }
}

static void olua_pushCXType(lua_State *L, CXType type)
{
    if (type.kind == CXType_Invalid) {
        lua_pushnil(L);
    } else {
        *(CXType *)lua_newuserdata(L, sizeof(CXType)) = type;
        olua_setmetatable(L, CLANG_TYPE);
    }
}

static void olua_pushCXString(lua_State *L, CXString s)
{
    if (s.data == NULL)
        lua_pushnil(L);
    else {
        lua_pushstring(L, clang_getCString(s));
        clang_disposeString(s);
    }
}

static void olua_pushDiagnostic(lua_State *L, CXDiagnostic diag) {
    lua_createtable(L, 0, 0);
    olua_pushCXString(L, clang_getDiagnosticCategoryText(diag));
    lua_setfield(L, -2, "category");
    olua_pushCXString(L, clang_formatDiagnostic(diag, clang_defaultDiagnosticDisplayOptions()));
    lua_setfield(L, -2, "text");
    clang_disposeDiagnostic(diag);
}

static int l_type_name(lua_State *L)
{
    CXType type = olua_toCXType(L, 1);
    olua_pushCXString(L, clang_getTypeSpelling(type));
    return 1;
}

static int l_type_kind(lua_State *L)
{
    CXType type = olua_toCXType(L, 1);
    olua_pushCXString(L, clang_getTypeKindSpelling(type.kind));
    return 1;
}

static int l_type_canonicalType(lua_State *L)
{
    CXType type = olua_toCXType(L, 1);
    olua_pushCXType(L, clang_getCanonicalType(type));
    return 1;
}

static int l_type_isPod(lua_State *L)
{
    CXType type = olua_toCXType(L, 1);
    lua_pushboolean(L, clang_isPODType(type));
    return 1;
}

static int l_type_eq(lua_State *L)
{
    CXType type = olua_toCXType(L, 1);
    CXType type2 = olua_toCXType(L, 2);
    lua_pushboolean(L, clang_equalTypes(type, type2));
    return 1;
}

static int l_type_declaration(lua_State *L)
{
    CXType type = olua_toCXType(L, 1);
    olua_pushCXCursor(L, clang_getTypeDeclaration(type));
    return 1;
}

static int l_type_pointeeType(lua_State *L)
{
    CXType type = olua_toCXType(L, 1);
    olua_pushCXType(L, clang_getPointeeType(type));
    return 1;
}

static int l_type_clang_getTypedefName(lua_State *L)
{
    CXType type = olua_toCXType(L, 1);
    olua_pushCXString(L, clang_getTypedefName(type));
    return 1;
}

static int l_type_isConstQualifiedType(lua_State *L)
{
    CXType type = olua_toCXType(L, 1);
    lua_pushboolean(L, clang_isConstQualifiedType(type));
    return 1;
}

static int l_type_isRestrictQualifiedType(lua_State *L)
{
    CXType type = olua_toCXType(L, 1);
    lua_pushboolean(L, clang_isRestrictQualifiedType(type));
    return 1;
}

static int l_type_isVolatileQualifiedType(lua_State *L)
{
    CXType type = olua_toCXType(L, 1);
    lua_pushboolean(L, clang_isVolatileQualifiedType(type));
    return 1;
}

static int l_type_clang_getResultType(lua_State *L)
{
    CXType type = olua_toCXType(L, 1);
    olua_pushCXType(L, clang_getResultType(type));
    return 1;
}

static int l_type_clang_argTypes(lua_State *L)
{
    CXType type = olua_toCXType(L, 1);
    int total = clang_getNumArgTypes(type);
    lua_createtable(L, total, 0);
    for (int i = 0; i < total; i++) {
        olua_pushCXType(L, clang_getArgType(type, i));
    }
    return 1;
}

static int l_type_clang_Type_getNumTemplateArguments(lua_State *L)
{
    CXType type = olua_toCXType(L, 1);
    int total = clang_Type_getNumTemplateArguments(type);
    lua_createtable(L, total, 0);
    for (int i = 0; i < total; i++) {
        olua_pushCXType(L, clang_Type_getTemplateArgumentAsType(type, i));
    }
    return 1;
}

static int luaopen_clang_type(lua_State *L)
{
    oluacls_class(L, CLANG_TYPE, NULL);
    oluacls_func(L, "__eq", l_type_eq);
    oluacls_func(L, "name", l_type_name);
    oluacls_func(L, "kind", l_type_kind);
    oluacls_func(L, "canonicalType", l_type_canonicalType);
    oluacls_func(L, "isPod", l_type_isPod);
    oluacls_func(L, "declaration", l_type_declaration);
    oluacls_func(L, "pointeeType", l_type_pointeeType);
    oluacls_func(L, "typedefName", l_type_clang_getTypedefName);
    oluacls_func(L, "isConst", l_type_isConstQualifiedType);
    oluacls_func(L, "isRestrict", l_type_isRestrictQualifiedType);
    oluacls_func(L, "isVolatile", l_type_isVolatileQualifiedType);
    oluacls_func(L, "resultType", l_type_clang_getResultType);
    oluacls_func(L, "argTypes", l_type_clang_argTypes);
    oluacls_func(L, "templateArgumentAsType", l_type_clang_argTypes);
    return 1;
}

static const char *toCursorKindString(enum CXCursorKind kind) {
    switch (kind) {
    case CXCursor_UnexposedDecl: return "UnexposedDecl";
    case CXCursor_StructDecl: return "StructDecl";
    case CXCursor_UnionDecl: return "UnionDecl";
    case CXCursor_ClassDecl: return "ClassDecl";
    case CXCursor_EnumDecl: return "EnumDecl";
    case CXCursor_FieldDecl: return "FieldDecl";
    case CXCursor_EnumConstantDecl: return "EnumConstantDecl";
    case CXCursor_FunctionDecl: return "FunctionDecl";
    case CXCursor_VarDecl: return "VarDecl";
    case CXCursor_ParmDecl: return "ParmDecl";
    case CXCursor_ObjCInterfaceDecl: return "ObjCInterfaceDecl";
    case CXCursor_ObjCCategoryDecl: return "ObjCCategoryDecl";
    case CXCursor_ObjCProtocolDecl: return "ObjCProtocolDecl";
    case CXCursor_ObjCPropertyDecl: return "ObjCPropertyDecl";
    case CXCursor_ObjCIvarDecl: return "ObjCIvarDecl";
    case CXCursor_ObjCInstanceMethodDecl: return "ObjCInstanceMethodDecl";
    case CXCursor_ObjCClassMethodDecl: return "ObjCClassMethodDecl";
    case CXCursor_ObjCImplementationDecl: return "ObjCImplementationDecl";
    case CXCursor_ObjCCategoryImplDecl: return "ObjCCategoryImplDecl";
    case CXCursor_TypedefDecl: return "TypedefDecl";
    case CXCursor_CXXMethod: return "CXXMethod";
    case CXCursor_Namespace: return "Namespace";
    case CXCursor_LinkageSpec: return "LinkageSpec";
    case CXCursor_Constructor: return "Constructor";
    case CXCursor_Destructor: return "Destructor";
    case CXCursor_ConversionFunction: return "ConversionFunction";
    case CXCursor_TemplateTypeParameter: return "TemplateTypeParameter";
    case CXCursor_NonTypeTemplateParameter: return "NonTypeTemplateParameter";
    case CXCursor_TemplateTemplateParameter: return "TemplateTemplateParameter";
    case CXCursor_FunctionTemplate: return "FunctionTemplate";
    case CXCursor_ClassTemplate: return "ClassTemplate";
    case CXCursor_ClassTemplatePartialSpecialization: return "ClassTemplatePartialSpecialization";
    case CXCursor_NamespaceAlias: return "NamespaceAlias";
    case CXCursor_UsingDirective: return "UsingDirective";
    case CXCursor_UsingDeclaration: return "UsingDeclaration";
    case CXCursor_TypeAliasDecl: return "TypeAliasDecl";
    case CXCursor_ObjCSynthesizeDecl: return "ObjCSynthesizeDecl";
    case CXCursor_ObjCDynamicDecl: return "ObjCDynamicDecl";
    case CXCursor_CXXAccessSpecifier: return "CXXAccessSpecifier";
    case CXCursor_ObjCSuperClassRef: return "ObjCSuperClassRef";
    case CXCursor_ObjCProtocolRef: return "ObjCProtocolRef";
    case CXCursor_ObjCClassRef: return "ObjCClassRef";
    case CXCursor_TypeRef: return "TypeRef";
    case CXCursor_CXXBaseSpecifier: return "CXXBaseSpecifier";
    case CXCursor_TemplateRef: return "TemplateRef";
    case CXCursor_NamespaceRef: return "NamespaceRef";
    case CXCursor_MemberRef: return "MemberRef";
    case CXCursor_LabelRef: return "LabelRef";
    case CXCursor_OverloadedDeclRef: return "OverloadedDeclRef";
    case CXCursor_VariableRef: return "VariableRef";
    case CXCursor_InvalidFile: return "InvalidFile";
    case CXCursor_NoDeclFound: return "NoDeclFound";
    case CXCursor_NotImplemented: return "NotImplemented";
    case CXCursor_InvalidCode: return "InvalidCode";
    case CXCursor_UnexposedExpr: return "UnexposedExpr";
    case CXCursor_DeclRefExpr: return "DeclRefExpr";
    case CXCursor_MemberRefExpr: return "MemberRefExpr";
    case CXCursor_CallExpr: return "CallExpr";
    case CXCursor_ObjCMessageExpr: return "ObjCMessageExpr";
    case CXCursor_BlockExpr: return "BlockExpr";
    case CXCursor_IntegerLiteral: return "IntegerLiteral";
    case CXCursor_FloatingLiteral: return "FloatingLiteral";
    case CXCursor_ImaginaryLiteral: return "ImaginaryLiteral";
    case CXCursor_StringLiteral: return "StringLiteral";
    case CXCursor_CharacterLiteral: return "CharacterLiteral";
    case CXCursor_ParenExpr: return "ParenExpr";
    case CXCursor_UnaryOperator: return "UnaryOperator";
    case CXCursor_ArraySubscriptExpr: return "ArraySubscriptExpr";
    case CXCursor_BinaryOperator: return "BinaryOperator";
    case CXCursor_CompoundAssignOperator: return "CompoundAssignOperator";
    case CXCursor_ConditionalOperator: return "ConditionalOperator";
    case CXCursor_CStyleCastExpr: return "CStyleCastExpr";
    case CXCursor_CompoundLiteralExpr: return "CompoundLiteralExpr";
    case CXCursor_InitListExpr: return "InitListExpr";
    case CXCursor_AddrLabelExpr: return "AddrLabelExpr";
    case CXCursor_StmtExpr: return "StmtExpr";
    case CXCursor_GenericSelectionExpr: return "GenericSelectionExpr";
    case CXCursor_GNUNullExpr: return "GNUNullExpr";
    case CXCursor_CXXStaticCastExpr: return "CXXStaticCastExpr";
    case CXCursor_CXXDynamicCastExpr: return "CXXDynamicCastExpr";
    case CXCursor_CXXReinterpretCastExpr: return "CXXReinterpretCastExpr";
    case CXCursor_CXXConstCastExpr: return "CXXConstCastExpr";
    case CXCursor_CXXFunctionalCastExpr: return "CXXFunctionalCastExpr";
    case CXCursor_CXXTypeidExpr: return "CXXTypeidExpr";
    case CXCursor_CXXBoolLiteralExpr: return "CXXBoolLiteralExpr";
    case CXCursor_CXXNullPtrLiteralExpr: return "CXXNullPtrLiteralExpr";
    case CXCursor_CXXThisExpr: return "CXXThisExpr";
    case CXCursor_CXXThrowExpr: return "CXXThrowExpr";
    case CXCursor_CXXNewExpr: return "CXXNewExpr";
    case CXCursor_CXXDeleteExpr: return "CXXDeleteExpr";
    case CXCursor_UnaryExpr: return "UnaryExpr";
    case CXCursor_ObjCStringLiteral: return "ObjCStringLiteral";
    case CXCursor_ObjCEncodeExpr: return "ObjCEncodeExpr";
    case CXCursor_ObjCSelectorExpr: return "ObjCSelectorExpr";
    case CXCursor_ObjCProtocolExpr: return "ObjCProtocolExpr";
    case CXCursor_ObjCBridgedCastExpr: return "ObjCBridgedCastExpr";
    case CXCursor_PackExpansionExpr: return "PackExpansionExpr";
    case CXCursor_SizeOfPackExpr: return "SizeOfPackExpr";
    case CXCursor_LambdaExpr: return "LambdaExpr";
    case CXCursor_ObjCBoolLiteralExpr: return "ObjCBoolLiteralExpr";
    case CXCursor_LabelStmt: return "LabelStmt";
    case CXCursor_CompoundStmt: return "CompoundStmt";
    case CXCursor_CaseStmt: return "CaseStmt";
    case CXCursor_DefaultStmt: return "DefaultStmt";
    case CXCursor_IfStmt: return "IfStmt";
    case CXCursor_SwitchStmt: return "SwitchStmt";
    case CXCursor_WhileStmt: return "WhileStmt";
    case CXCursor_DoStmt: return "DoStmt";
    case CXCursor_ForStmt: return "ForStmt";
    case CXCursor_GotoStmt: return "GotoStmt";
    case CXCursor_IndirectGotoStmt: return "IndirectGotoStmt";
    case CXCursor_ContinueStmt: return "ContinueStmt";
    case CXCursor_BreakStmt: return "BreakStmt";
    case CXCursor_ReturnStmt: return "ReturnStmt";
    case CXCursor_AsmStmt: return "AsmStmt";
    case CXCursor_ObjCAtTryStmt: return "ObjCAtTryStmt";
    case CXCursor_ObjCAtCatchStmt: return "ObjCAtCatchStmt";
    case CXCursor_ObjCAtFinallyStmt: return "ObjCAtFinallyStmt";
    case CXCursor_ObjCAtThrowStmt: return "ObjCAtThrowStmt";
    case CXCursor_ObjCAtSynchronizedStmt: return "ObjCAtSynchronizedStmt";
    case CXCursor_ObjCAutoreleasePoolStmt: return "ObjCAutoreleasePoolStmt";
    case CXCursor_ObjCForCollectionStmt: return "ObjCForCollectionStmt";
    case CXCursor_CXXCatchStmt: return "CXXCatchStmt";
    case CXCursor_CXXTryStmt: return "CXXTryStmt";
    case CXCursor_CXXForRangeStmt: return "CXXForRangeStmt";
    case CXCursor_SEHTryStmt: return "SEHTryStmt";
    case CXCursor_SEHExceptStmt: return "SEHExceptStmt";
    case CXCursor_SEHFinallyStmt: return "SEHFinallyStmt";
    case CXCursor_NullStmt: return "NullStmt";
    case CXCursor_DeclStmt: return "DeclStmt";
    case CXCursor_TranslationUnit: return "TranslationUnit";
    case CXCursor_UnexposedAttr: return "UnexposedAttr";
    case CXCursor_IBActionAttr: return "IBActionAttr";
    case CXCursor_IBOutletAttr: return "IBOutletAttr";
    case CXCursor_IBOutletCollectionAttr: return "IBOutletCollectionAttr";
    case CXCursor_CXXFinalAttr: return "CXXFinalAttr";
    case CXCursor_CXXOverrideAttr: return "CXXOverrideAttr";
    case CXCursor_AnnotateAttr: return "AnnotateAttr";
    case CXCursor_AsmLabelAttr: return "AsmLabelAttr";
    case CXCursor_PreprocessingDirective: return "PreprocessingDirective";
    case CXCursor_MacroDefinition: return "MacroDefinition";
    case CXCursor_MacroExpansion: return "MacroExpansion";
    case CXCursor_InclusionDirective: return "InclusionDirective";
    default: return "Unknown";
    }
}

static int l_cursor_name(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    olua_pushCXString(L, clang_getCursorSpelling(cur));
    return 1;
}

static int l_cursor_eq(lua_State *L)
{
    CXCursor cur1 = olua_toCXCursor(L, 1);
    CXCursor cur2 = olua_toCXCursor(L, 2);
    lua_pushboolean(L, clang_equalCursors(cur1, cur2));
    return 1;
}

static int l_cursor_kind(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    lua_pushstring(L, toCursorKindString(clang_getCursorKind(cur)));
    return 1;
}

static int l_cursor_type(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    CXType type = clang_getCursorType(cur);
    if (type.kind == CXType_Invalid) {
        lua_pushnil(L);
    } else {
        olua_pushCXType(L, type);
    }
    return 1;
}

static int l_cursor_displayName(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    olua_pushCXString(L, clang_getCursorDisplayName(cur));
    return 1;
}

static int l_cursor_access(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    enum CX_CXXAccessSpecifier spec = clang_getCXXAccessSpecifier(cur);
    switch (spec) {
        case CX_CXXInvalidAccessSpecifier: lua_pushnil(L); break;
        case CX_CXXPublic: lua_pushliteral(L, "public"); break;
        case CX_CXXProtected: lua_pushliteral(L, "protected"); break;
        case CX_CXXPrivate: lua_pushliteral(L, "private"); break;
    }
    return 1;
}

static int l_cursor_location(lua_State *L)
{
    CXFile file;
    unsigned int line, col;
    
    CXCursor cur = olua_toCXCursor(L, 1);
    CXSourceRange range = clang_getCursorExtent(cur);

    CXSourceLocation loc = clang_getRangeStart(range);
    clang_getSpellingLocation(loc, &file, &line, &col, NULL);
    olua_pushCXString(L, clang_getFileName(file));
    lua_pushinteger(L, line);
    lua_pushinteger(L, col);
    
    loc = clang_getRangeEnd(range);
    clang_getSpellingLocation(loc, &file, &line, &col, NULL);
    lua_pushinteger(L, line);
    lua_pushinteger(L, col);
    return 5;
}

static int l_cursor_usr(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    olua_pushCXString(L, clang_getCursorUSR(cur));
    return 1;
}

static int l_cursor_parent(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    olua_pushCXCursor(L, clang_getCursorSemanticParent(cur));
    return 1;
}

static int l_cursor_arguments(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    unsigned int nargs = clang_Cursor_getNumArguments(cur);
    lua_createtable(L, nargs, 0);
    for (unsigned int i = 0; i < nargs; i++) {
        olua_pushCXCursor(L, clang_Cursor_getArgument(cur, i));
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}

static int l_cursor_referenced(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    olua_pushCXCursor(L, clang_getCursorReferenced(cur));
    return 1;
}

static int l_cursor_definition(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    olua_pushCXCursor(L, clang_getCursorDefinition(cur));
    return 1;
}

static int l_cursor_clang_isDeclaration(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    lua_pushboolean(L, clang_isDeclaration(clang_getCursorKind(cur)));
    return 1;
}

static int l_cursor_clang_isInvalidDeclaration(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    lua_pushboolean(L, clang_isInvalidDeclaration(cur));
    return 1;
}

static int l_cursor_clang_isReference(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    lua_pushboolean(L, clang_isReference(clang_getCursorKind(cur)));
    return 1;
}

static int l_cursor_clang_isExpression(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    lua_pushboolean(L, clang_isExpression(clang_getCursorKind(cur)));
    return 1;
}

static int l_cursor_clang_isStatement(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    lua_pushboolean(L, clang_isStatement(clang_getCursorKind(cur)));
    return 1;
}

static int l_cursor_clang_isAttribute(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    lua_pushboolean(L, clang_isAttribute(clang_getCursorKind(cur)));
    return 1;
}

static int l_cursor_isStatic(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    lua_pushboolean(L, clang_CXXMethod_isStatic(cur));
    return 1;
}

static int l_cursor_isVirtual(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    lua_pushboolean(L, clang_CXXMethod_isVirtual(cur));
    return 1;
}

static int l_cursor_isPureVirtual(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    lua_pushboolean(L, clang_CXXMethod_isPureVirtual(cur));
    return 1;
}

static int l_cursor_isAbstract(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    lua_pushboolean(L, clang_CXXRecord_isAbstract(cur));
    return 1;
}

static int l_cursor_isConstMethod(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    lua_pushboolean(L, clang_CXXMethod_isConst(cur));
    return 1;
}

static int l_cursor_resultType(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    olua_pushCXType(L, clang_getCursorResultType(cur));
    return 1;
}

static int l_cursor_isConvertingConstructor(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    lua_pushboolean(L, clang_CXXConstructor_isConvertingConstructor(cur));
    return 1;
}

static int l_cursor_isCopyConstructor(lua_State *L) {
    CXCursor cur = olua_toCXCursor(L, 1);
    lua_pushboolean(L, clang_CXXConstructor_isCopyConstructor(cur));
    return 1;
}

static int l_cursor_isDefaultConstructor(lua_State *L) {
    CXCursor cur = olua_toCXCursor(L, 1);
    lua_pushboolean(L, clang_CXXConstructor_isDefaultConstructor(cur));
    return 1;
}

static int l_cursor_isMoveConstructor(lua_State *L) {
    CXCursor cur = olua_toCXCursor(L, 1);
    lua_pushboolean(L, clang_CXXConstructor_isMoveConstructor(cur));
    return 1;
}

static int l_cursor_clang_Cursor_isVariadic(lua_State *L) {
    CXCursor cur = olua_toCXCursor(L, 1);
    lua_pushboolean(L, clang_Cursor_isVariadic(cur));
    return 1;
}

enum CXChildVisitResult childrenVisitor(CXCursor cursor, CXCursor parent, CXClientData client_data)
{
    lua_State *L = (lua_State *)client_data;
    olua_pushCXCursor(L, cursor);
    lua_rawseti(L, -2, (int)lua_rawlen(L, -2) + 1);
    return CXChildVisit_Continue;
}

static int l_cursor_clang_getTypedefDeclUnderlyingType(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    olua_pushCXType(L, clang_getTypedefDeclUnderlyingType(cur));
    return 1;
}

static int l_cursor_children(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    lua_createtable(L, 0, 0);
    clang_visitChildren(cur, childrenVisitor, L);
    return 1;
}

static int luaopen_clang_cursor(lua_State *L)
{
    oluacls_class(L, CLANG_CURSOR, NULL);
    oluacls_func(L, "__eq", l_cursor_eq);
    oluacls_func(L, "name", l_cursor_name);
    oluacls_func(L, "kind", l_cursor_kind);
    oluacls_func(L, "type", l_cursor_type);
    oluacls_func(L, "displayName", l_cursor_displayName);
    oluacls_func(L, "access", l_cursor_access);
    oluacls_func(L, "location", l_cursor_location);
    oluacls_func(L, "usr", l_cursor_usr);
    oluacls_func(L, "parent", l_cursor_parent);
    oluacls_func(L, "arguments", l_cursor_arguments);
    oluacls_func(L, "referenced", l_cursor_referenced);
    oluacls_func(L, "definition", l_cursor_definition);
    oluacls_func(L, "isDeclaration", l_cursor_clang_isDeclaration);
    oluacls_func(L, "isInvalidDeclaration", l_cursor_clang_isInvalidDeclaration);
    oluacls_func(L, "isReference", l_cursor_clang_isReference);
    oluacls_func(L, "isExpression", l_cursor_clang_isExpression);
    oluacls_func(L, "isStatement", l_cursor_clang_isStatement);
    oluacls_func(L, "isAttribute", l_cursor_clang_isAttribute);
    oluacls_func(L, "isStatic", l_cursor_isStatic);
    oluacls_func(L, "isVirtual", l_cursor_isVirtual);
    oluacls_func(L, "isPureVirtual", l_cursor_isPureVirtual);
    oluacls_func(L, "isAbstract", l_cursor_isAbstract);
    oluacls_func(L, "isConstMethod", l_cursor_isConstMethod);
    oluacls_func(L, "resultType", l_cursor_resultType);
    oluacls_func(L, "isConvertingConstructor", l_cursor_isConvertingConstructor);
    oluacls_func(L, "isCopyConstructor", l_cursor_isCopyConstructor);
    oluacls_func(L, "isDefaultConstructor", l_cursor_isDefaultConstructor);
    oluacls_func(L, "isMoveConstructor", l_cursor_isMoveConstructor);
    oluacls_func(L, "isVariadic", l_cursor_clang_Cursor_isVariadic);
    oluacls_func(L, "underlyingType", l_cursor_clang_getTypedefDeclUnderlyingType);
    oluacls_func(L, "children", l_cursor_children);
    return 1;
}

static int l_tu_cursor(lua_State *L)
{
    CXTranslationUnit tu = olua_toCXTranslationUnit(L, 1);
    olua_pushCXCursor(L, clang_getTranslationUnitCursor(tu));
    return 1;
}

static int l_tu_file(lua_State *L)
{
    CXTranslationUnit tu = olua_toCXTranslationUnit(L, 1);
    const char *file = olua_checkstring(L, 2);
    CXFile f = clang_getFile(tu, file);
    olua_pushCXString(L, clang_getFileName(f));
    lua_pushnumber(L, (lua_Number)clang_getFileTime(f));
    return 2;
}

static int l_tu_diagnostics(lua_State *L) {
    CXTranslationUnit tu = olua_toCXTranslationUnit(L, 1);
    int nDiag = clang_getNumDiagnostics(tu);
    lua_createtable(L, nDiag, 0);
    for (int i=0; i<nDiag; i++) {
        olua_pushDiagnostic(L, clang_getDiagnostic(tu, i));
        lua_rawseti(L, -2, i+1);
    }
    return 1;
}

static int l_tu_gc(lua_State *L)
{
    CXTranslationUnit tu = olua_toCXTranslationUnit(L, 1);
    clang_disposeTranslationUnit(tu);
    return 0;
}

static int luaopen_clang_tu(lua_State *L)
{
    oluacls_class(L, CLANG_TU, NULL);
    oluacls_func(L, "cursor", l_tu_cursor);
    oluacls_func(L, "file", l_tu_file);
    oluacls_func(L, "diagnostics", l_tu_diagnostics);
    oluacls_func(L, "__gc", l_tu_gc);
    return 1;
}

static int l_index_load(lua_State *L)
{
    CXIndex idx = olua_toCXIndex(L, 1);
    const char *ast_filename = olua_checkstring(L, 2);
    CXTranslationUnit tu = clang_createTranslationUnit(idx, ast_filename);
    if (tu) {
        olua_pushobj(L, tu, CLANG_TU);
    } else {
        lua_pushnil(L);
        lua_pushfstring(L, "failed to open ast file: %s", ast_filename);
        return 2;
    }
    return 1;
}

static int l_index_parse(lua_State *L)
{
    CXIndex idx = olua_toCXIndex(L, 1);
    const char *source_filename = olua_optstring(L, 2, NULL);
    int nargs = (int)lua_rawlen(L, 3);
    unsigned int options = (unsigned int)olua_optinteger(L, 4, CXTranslationUnit_SkipFunctionBodies);
    char const **args = (char const **)malloc(sizeof(char *) * nargs);
    for (int i = 0; i < nargs; i++) {
        lua_rawgeti(L, 3, i + 1);
        args[i] = olua_tostring(L, -1);
        lua_pop(L, 1);
    }
    CXTranslationUnit tu = clang_parseTranslationUnit(idx, source_filename, args, nargs, NULL, 0, options);
    if (tu) {
        olua_pushobj(L, tu, CLANG_TU);
    } else {
        lua_pushnil(L);
        lua_pushfstring(L, "failed to parse file: %s", source_filename);
        return 2;
    }
    return 1;
}

static int l_index_gc(lua_State *L)
{
    CXIndex idx = olua_toCXIndex(L, 1);
    clang_disposeIndex(idx);
    return 0;
}

static int luaopen_clang_index(lua_State *L)
{
    oluacls_class(L, CLANG_INDEX, NULL);
    oluacls_func(L, "load", l_index_load);
    oluacls_func(L, "parse", l_index_parse);
    oluacls_func(L, "__gc", l_index_gc);
    
    return 1;
}

static int l_clang_createIndex(lua_State *L)
{
    int excludeDeclarationsFromPCH = olua_toboolean(L, 1);
    int displayDiagnostics = olua_toboolean(L, 2);
    CXIndex idx = clang_createIndex(excludeDeclarationsFromPCH, displayDiagnostics);
    olua_pushobj(L, idx, CLANG_INDEX);
    return 1;
}

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
#define EXPORT_LUACLANG __declspec(dllexport)
#else
#define EXPORT_LUACLANG extern
#endif

EXPORT_LUACLANG int luaopen_clang(lua_State *L)
{
    olua_require(L, CLANG_TYPE, luaopen_clang_type);
    olua_require(L, CLANG_CURSOR, luaopen_clang_cursor);
    olua_require(L, CLANG_TU, luaopen_clang_tu);
    olua_require(L, CLANG_INDEX, luaopen_clang_index);
    
    oluacls_class(L, "clang", NULL);
    oluacls_func(L, "createIndex", l_clang_createIndex);
    
    return 1;
}

#ifdef __cplusplus
}
#endif