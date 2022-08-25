#include "clang-c/Index.h"
#include "olua/olua.h"

#define LUACLANG_VERSION "1.0"

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
    static const char *const serverity[] = {"ignored", "note", "warning", "error", "fatal"};
    lua_createtable(L, 0, 0);
    olua_pushCXString(L, clang_getDiagnosticSpelling(diag));
    lua_setfield(L, -2, "name");
    olua_pushCXString(L, clang_getDiagnosticCategoryText(diag));
    lua_setfield(L, -2, "category");
    olua_pushCXString(L, clang_formatDiagnostic(diag, clang_defaultDiagnosticDisplayOptions()));
    lua_setfield(L, -2, "text");
    lua_pushstring(L, serverity[clang_getDiagnosticSeverity(diag)]);
    lua_setfield(L, -2, "severity");
    clang_disposeDiagnostic(diag);
}

static int ltype_clang_getTypeSpelling(lua_State *L)
{
    CXType type = olua_toCXType(L, 1);
    olua_pushCXString(L, clang_getTypeSpelling(type));
    return 1;
}

static int ltype_clang_getTypeKindSpelling(lua_State *L)
{
    CXType type = olua_toCXType(L, 1);
    olua_pushCXString(L, clang_getTypeKindSpelling(type.kind));
    return 1;
}

static int ltype_clang_getCanonicalType(lua_State *L)
{
    CXType type = olua_toCXType(L, 1);
    olua_pushCXType(L, clang_getCanonicalType(type));
    return 1;
}

static int ltype_clang_isPODType(lua_State *L)
{
    CXType type = olua_toCXType(L, 1);
    lua_pushboolean(L, clang_isPODType(type));
    return 1;
}

static int ltype_clang_equalTypes(lua_State *L)
{
    CXType type = olua_toCXType(L, 1);
    CXType type2 = olua_toCXType(L, 2);
    lua_pushboolean(L, clang_equalTypes(type, type2));
    return 1;
}

static int ltype_clang_getTypeDeclaration(lua_State *L)
{
    CXType type = olua_toCXType(L, 1);
    olua_pushCXCursor(L, clang_getTypeDeclaration(type));
    return 1;
}

static int ltype_clang_getPointeeType(lua_State *L)
{
    CXType type = olua_toCXType(L, 1);
    olua_pushCXType(L, clang_getPointeeType(type));
    return 1;
}

static int ltype_clang_getTypedefName(lua_State *L)
{
    CXType type = olua_toCXType(L, 1);
    olua_pushCXString(L, clang_getTypedefName(type));
    return 1;
}

static int ltype_clang_isConstQualifiedType(lua_State *L)
{
    CXType type = olua_toCXType(L, 1);
    lua_pushboolean(L, clang_isConstQualifiedType(type));
    return 1;
}

static int ltype_clang_isRestrictQualifiedType(lua_State *L)
{
    CXType type = olua_toCXType(L, 1);
    lua_pushboolean(L, clang_isRestrictQualifiedType(type));
    return 1;
}

static int ltype_clang_isVolatileQualifiedType(lua_State *L)
{
    CXType type = olua_toCXType(L, 1);
    lua_pushboolean(L, clang_isVolatileQualifiedType(type));
    return 1;
}

static int ltype_clang_getResultType(lua_State *L)
{
    CXType type = olua_toCXType(L, 1);
    olua_pushCXType(L, clang_getResultType(type));
    return 1;
}

static int ltype_clang_getArgTypes(lua_State *L)
{
    CXType type = olua_toCXType(L, 1);
    int total = clang_getNumArgTypes(type);
    lua_createtable(L, total, 0);
    for (int i = 0; i < total; i++) {
        olua_pushCXType(L, clang_getArgType(type, i));
        olua_rawseti(L, -2, i + 1);
    }
    return 1;
}

static int ltype_clang_Type_getTemplateArgumentTypes(lua_State *L)
{
    CXType type = olua_toCXType(L, 1);
    int total = clang_Type_getNumTemplateArguments(type);
    lua_createtable(L, total, 0);
    for (int i = 0; i < total; i++) {
        olua_pushCXType(L, clang_Type_getTemplateArgumentAsType(type, i));
        olua_rawseti(L, -2, i + 1);
    }
    return 1;
}

static int ltype_clang_Type_getClassType(lua_State *L)
{
    CXType type = olua_toCXType(L, 1);
    olua_pushCXType(L, clang_Type_getClassType(type));
    return 1;
}

static int luaopen_clang_type(lua_State *L)
{
    oluacls_class(L, CLANG_TYPE, NULL);
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_func(L, "__eq", ltype_clang_equalTypes);
    oluacls_prop(L, "name", ltype_clang_getTypeSpelling, NULL);
    oluacls_prop(L, "kind", ltype_clang_getTypeKindSpelling, NULL);
    oluacls_prop(L, "canonicalType", ltype_clang_getCanonicalType, NULL);
    oluacls_prop(L, "isPod", ltype_clang_isPODType, NULL);
    oluacls_prop(L, "declaration", ltype_clang_getTypeDeclaration, NULL);
    oluacls_prop(L, "pointeeType", ltype_clang_getPointeeType, NULL);
    oluacls_prop(L, "typedefName", ltype_clang_getTypedefName, NULL);
    oluacls_prop(L, "isConst", ltype_clang_isConstQualifiedType, NULL);
    oluacls_prop(L, "isRestrict", ltype_clang_isRestrictQualifiedType, NULL);
    oluacls_prop(L, "isVolatile", ltype_clang_isVolatileQualifiedType, NULL);
    oluacls_prop(L, "resultType", ltype_clang_getResultType, NULL);
    oluacls_prop(L, "argTypes", ltype_clang_getArgTypes, NULL);
    oluacls_prop(L, "templateArgTypes", ltype_clang_Type_getTemplateArgumentTypes, NULL);
    oluacls_prop(L, "classType", ltype_clang_Type_getClassType, NULL);
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
    // case CXCursor_FirstDecl: return "FirstDecl";
    // case CXCursor_LastDecl: return "LastDecl";
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
    // case CXCursor_LastRef: return "LastRef";
    // case CXCursor_FirstInvalid: return "FirstInvalid";
    case CXCursor_InvalidFile: return "InvalidFile";
    case CXCursor_NoDeclFound: return "NoDeclFound";
    case CXCursor_NotImplemented: return "NotImplemented";
    case CXCursor_InvalidCode: return "InvalidCode";
    // case CXCursor_LastInvalid: return "LastInvalid";
    // case CXCursor_FirstExpr: return "FirstExpr";
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
    case CXCursor_ObjCSelfExpr: return "ObjCSelfExpr";
    case CXCursor_OMPArraySectionExpr: return "OMPArraySectionExpr";
    case CXCursor_ObjCAvailabilityCheckExpr: return "ObjCAvailabilityCheckExpr";
    case CXCursor_FixedPointLiteral: return "FixedPointLiteral";
    case CXCursor_OMPArrayShapingExpr: return "OMPArrayShapingExpr";
    case CXCursor_OMPIteratorExpr: return "OMPIteratorExpr";
    case CXCursor_CXXAddrspaceCastExpr: return "CXXAddrspaceCastExpr";
    // case CXCursor_LastExpr: return "LastExpr";
    case CXCursor_FirstStmt: return "FirstStmt";
    // case CXCursor_UnexposedStmt: return "UnexposedStmt";
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
    case CXCursor_MSAsmStmt: return "MSAsmStmt";
    case CXCursor_NullStmt: return "NullStmt";
    case CXCursor_DeclStmt: return "DeclStmt";
    case CXCursor_OMPParallelDirective: return "OMPParallelDirective";
    case CXCursor_OMPSimdDirective: return "OMPSimdDirective";
    case CXCursor_OMPForDirective: return "OMPForDirective";
    case CXCursor_OMPSectionsDirective: return "OMPSectionsDirective";
    case CXCursor_OMPSectionDirective: return "OMPSectionDirective";
    case CXCursor_OMPSingleDirective: return "OMPSingleDirective";
    case CXCursor_OMPParallelForDirective: return "OMPParallelForDirective";
    case CXCursor_OMPParallelSectionsDirective: return "OMPParallelSectionsDirective";
    case CXCursor_OMPTaskDirective: return "OMPTaskDirective";
    case CXCursor_OMPMasterDirective: return "OMPMasterDirective";
    case CXCursor_OMPCriticalDirective: return "OMPCriticalDirective";
    case CXCursor_OMPTaskyieldDirective: return "OMPTaskyieldDirective";
    case CXCursor_OMPBarrierDirective: return "OMPBarrierDirective";
    case CXCursor_OMPTaskwaitDirective: return "OMPTaskwaitDirective";
    case CXCursor_OMPFlushDirective: return "OMPFlushDirective";
    case CXCursor_SEHLeaveStmt: return "SEHLeaveStmt";
    case CXCursor_OMPOrderedDirective: return "OMPOrderedDirective";
    case CXCursor_OMPAtomicDirective: return "OMPAtomicDirective";
    case CXCursor_OMPForSimdDirective: return "OMPForSimdDirective";
    case CXCursor_OMPParallelForSimdDirective: return "OMPParallelForSimdDirective";
    case CXCursor_OMPTargetDirective: return "OMPTargetDirective";
    case CXCursor_OMPTeamsDirective: return "OMPTeamsDirective";
    case CXCursor_OMPTaskgroupDirective: return "OMPTaskgroupDirective";
    case CXCursor_OMPCancellationPointDirective: return "OMPCancellationPointDirective";
    case CXCursor_OMPCancelDirective: return "OMPCancelDirective";
    case CXCursor_OMPTargetDataDirective: return "OMPTargetDataDirective";
    case CXCursor_OMPTaskLoopDirective: return "OMPTaskLoopDirective";
    case CXCursor_OMPTaskLoopSimdDirective: return "OMPTaskLoopSimdDirective";
    case CXCursor_OMPDistributeDirective: return "OMPDistributeDirective";
    case CXCursor_OMPTargetEnterDataDirective: return "OMPTargetEnterDataDirective";
    case CXCursor_OMPTargetExitDataDirective: return "OMPTargetExitDataDirective";
    case CXCursor_OMPTargetParallelDirective: return "OMPTargetParallelDirective";
    case CXCursor_OMPTargetParallelForDirective: return "OMPTargetParallelForDirective";
    case CXCursor_OMPTargetUpdateDirective: return "OMPTargetUpdateDirective";
    case CXCursor_OMPDistributeParallelForDirective: return "OMPDistributeParallelForDirective";
    case CXCursor_OMPDistributeParallelForSimdDirective: return "OMPDistributeParallelForSimdDirective";
    case CXCursor_OMPDistributeSimdDirective: return "OMPDistributeSimdDirective";
    case CXCursor_OMPTargetParallelForSimdDirective: return "OMPTargetParallelForSimdDirective";
    case CXCursor_OMPTargetSimdDirective: return "OMPTargetSimdDirective";
    case CXCursor_OMPTeamsDistributeDirective: return "OMPTeamsDistributeDirective";
    case CXCursor_OMPTeamsDistributeSimdDirective: return "OMPTeamsDistributeSimdDirective";
    case CXCursor_OMPTeamsDistributeParallelForSimdDirective: return "OMPTeamsDistributeParallelForSimdDirective";
    case CXCursor_OMPTeamsDistributeParallelForDirective: return "OMPTeamsDistributeParallelForDirective";
    case CXCursor_OMPTargetTeamsDirective: return "OMPTargetTeamsDirective";
    case CXCursor_OMPTargetTeamsDistributeDirective: return "OMPTargetTeamsDistributeDirective";
    case CXCursor_OMPTargetTeamsDistributeParallelForDirective: return "OMPTargetTeamsDistributeParallelForDirective";
    case CXCursor_OMPTargetTeamsDistributeParallelForSimdDirective: return "OMPTargetTeamsDistributeParallelForSimdDirective";
    case CXCursor_OMPTargetTeamsDistributeSimdDirective: return "OMPTargetTeamsDistributeSimdDirective";
    case CXCursor_BuiltinBitCastExpr: return "BuiltinBitCastExpr";
    case CXCursor_OMPMasterTaskLoopDirective: return "OMPMasterTaskLoopDirective";
    case CXCursor_OMPParallelMasterTaskLoopDirective: return "OMPParallelMasterTaskLoopDirective";
    case CXCursor_OMPMasterTaskLoopSimdDirective: return "OMPMasterTaskLoopSimdDirective";
    case CXCursor_OMPParallelMasterTaskLoopSimdDirective: return "OMPParallelMasterTaskLoopSimdDirective";
    case CXCursor_OMPParallelMasterDirective: return "OMPParallelMasterDirective";
    case CXCursor_OMPDepobjDirective: return "OMPDepobjDirective";
    case CXCursor_OMPScanDirective: return "OMPScanDirective";
    // case CXCursor_LastStmt: return "LastStmt";
    case CXCursor_TranslationUnit: return "TranslationUnit";
    // case CXCursor_FirstAttr: return "FirstAttr";
    case CXCursor_UnexposedAttr: return "UnexposedAttr";
    case CXCursor_IBActionAttr: return "IBActionAttr";
    case CXCursor_IBOutletAttr: return "IBOutletAttr";
    case CXCursor_IBOutletCollectionAttr: return "IBOutletCollectionAttr";
    case CXCursor_CXXFinalAttr: return "CXXFinalAttr";
    case CXCursor_CXXOverrideAttr: return "CXXOverrideAttr";
    case CXCursor_AnnotateAttr: return "AnnotateAttr";
    case CXCursor_AsmLabelAttr: return "AsmLabelAttr";
    case CXCursor_PackedAttr: return "PackedAttr";
    case CXCursor_PureAttr: return "PureAttr";
    case CXCursor_ConstAttr: return "ConstAttr";
    case CXCursor_NoDuplicateAttr: return "NoDuplicateAttr";
    case CXCursor_CUDAConstantAttr: return "CUDAConstantAttr";
    case CXCursor_CUDADeviceAttr: return "CUDADeviceAttr";
    case CXCursor_CUDAGlobalAttr: return "CUDAGlobalAttr";
    case CXCursor_CUDAHostAttr: return "CUDAHostAttr";
    case CXCursor_CUDASharedAttr: return "CUDASharedAttr";
    case CXCursor_VisibilityAttr: return "VisibilityAttr";
    case CXCursor_DLLExport: return "DLLExport";
    case CXCursor_DLLImport: return "DLLImport";
    case CXCursor_NSReturnsRetained: return "NSReturnsRetained";
    case CXCursor_NSReturnsNotRetained: return "NSReturnsNotRetained";
    case CXCursor_NSReturnsAutoreleased: return "NSReturnsAutoreleased";
    case CXCursor_NSConsumesSelf: return "NSConsumesSelf";
    case CXCursor_NSConsumed: return "NSConsumed";
    case CXCursor_ObjCException: return "ObjCException";
    case CXCursor_ObjCNSObject: return "ObjCNSObject";
    case CXCursor_ObjCIndependentClass: return "ObjCIndependentClass";
    case CXCursor_ObjCPreciseLifetime: return "ObjCPreciseLifetime";
    case CXCursor_ObjCReturnsInnerPointer: return "ObjCReturnsInnerPointer";
    case CXCursor_ObjCRequiresSuper: return "ObjCRequiresSuper";
    case CXCursor_ObjCRootClass: return "ObjCRootClass";
    case CXCursor_ObjCSubclassingRestricted: return "ObjCSubclassingRestricted";
    case CXCursor_ObjCExplicitProtocolImpl: return "ObjCExplicitProtocolImpl";
    case CXCursor_ObjCDesignatedInitializer: return "ObjCDesignatedInitializer";
    case CXCursor_ObjCRuntimeVisible: return "ObjCRuntimeVisible";
    case CXCursor_ObjCBoxable: return "ObjCBoxable";
    case CXCursor_FlagEnum: return "FlagEnum";
    case CXCursor_ConvergentAttr: return "ConvergentAttr";
    case CXCursor_WarnUnusedAttr: return "WarnUnusedAttr";
    case CXCursor_WarnUnusedResultAttr: return "WarnUnusedResultAttr";
    case CXCursor_AlignedAttr: return "AlignedAttr";
    // case CXCursor_LastAttr: return "LastAttr";
    case CXCursor_PreprocessingDirective: return "PreprocessingDirective";
    case CXCursor_MacroDefinition: return "MacroDefinition";
    case CXCursor_MacroExpansion: return "MacroExpansion";
    // case CXCursor_MacroInstantiation: return "MacroInstantiation";
    case CXCursor_InclusionDirective: return "InclusionDirective";
    // case CXCursor_FirstPreprocessing: return "FirstPreprocessing";
    // case CXCursor_LastPreprocessing: return "LastPreprocessing";
    case CXCursor_ModuleImportDecl: return "ModuleImportDecl";
    case CXCursor_TypeAliasTemplateDecl: return "TypeAliasTemplateDecl";
    case CXCursor_StaticAssert: return "StaticAssert";
    case CXCursor_FriendDecl: return "FriendDecl";
    // case CXCursor_FirstExtraDecl: return "FirstExtraDecl";
    // case CXCursor_LastExtraDecl: return "LastExtraDecl";
    case CXCursor_OverloadCandidate: return "OverloadCandidate";
    default: return "Unknown";
    }
}

static int lcursor_clang_getCursorSpelling(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    olua_pushCXString(L, clang_getCursorSpelling(cur));
    return 1;
}

static int lcursor_clang_equalCursors(lua_State *L)
{
    CXCursor cur1 = olua_toCXCursor(L, 1);
    CXCursor cur2 = olua_toCXCursor(L, 2);
    lua_pushboolean(L, clang_equalCursors(cur1, cur2));
    return 1;
}

static int lcursor_clang_getCursorKind(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    lua_pushstring(L, toCursorKindString(clang_getCursorKind(cur)));
    return 1;
}

static int lcursor_clang_getCursorType(lua_State *L)
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

static int lcursor_clang_getCursorDisplayName(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    olua_pushCXString(L, clang_getCursorDisplayName(cur));
    return 1;
}

static int lcursor_clang_getCXXAccessSpecifier(lua_State *L)
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

static int lcursor_clang_getSpellingLocation(lua_State *L)
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

static int lcursor_clang_getCursorUSR(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    olua_pushCXString(L, clang_getCursorUSR(cur));
    return 1;
}

static int lcursor_clang_getCursorSemanticParent(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    olua_pushCXCursor(L, clang_getCursorSemanticParent(cur));
    return 1;
}

static int lcursor_clang_Cursor_getArguments(lua_State *L)
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

static int lcursor_clang_getCursorReferenced(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    olua_pushCXCursor(L, clang_getCursorReferenced(cur));
    return 1;
}

static int lcursor_clang_getCursorDefinition(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    olua_pushCXCursor(L, clang_getCursorDefinition(cur));
    return 1;
}

static int lcursor_clang_isDeclaration(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    lua_pushboolean(L, clang_isDeclaration(clang_getCursorKind(cur)));
    return 1;
}

static int lcursor_clang_isInvalidDeclaration(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    lua_pushboolean(L, clang_isInvalidDeclaration(cur));
    return 1;
}

static int lcursor_clang_isReference(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    lua_pushboolean(L, clang_isReference(clang_getCursorKind(cur)));
    return 1;
}

static int lcursor_clang_isExpression(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    lua_pushboolean(L, clang_isExpression(clang_getCursorKind(cur)));
    return 1;
}

static int lcursor_clang_isStatement(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    lua_pushboolean(L, clang_isStatement(clang_getCursorKind(cur)));
    return 1;
}

static int lcursor_clang_isAttribute(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    lua_pushboolean(L, clang_isAttribute(clang_getCursorKind(cur)));
    return 1;
}

static int lcursor_clang_CXXMethod_isStatic(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    lua_pushboolean(L, clang_CXXMethod_isStatic(cur));
    return 1;
}

static int lcursor_clang_CXXMethod_isVirtual(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    lua_pushboolean(L, clang_CXXMethod_isVirtual(cur));
    return 1;
}

static int lcursor_clang_CXXMethod_isPureVirtual(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    lua_pushboolean(L, clang_CXXMethod_isPureVirtual(cur));
    return 1;
}

static int lcursor_clang_CXXRecord_isAbstract(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    lua_pushboolean(L, clang_CXXRecord_isAbstract(cur));
    return 1;
}

static int lcursor_clang_CXXMethod_isConst(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    lua_pushboolean(L, clang_CXXMethod_isConst(cur));
    return 1;
}

static int lcursor_clang_getCursorResultType(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    olua_pushCXType(L, clang_getCursorResultType(cur));
    return 1;
}

static int lcursor_clang_CXXConstructor_isConvertingConstructor(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    lua_pushboolean(L, clang_CXXConstructor_isConvertingConstructor(cur));
    return 1;
}

static int lcursor_clang_CXXConstructor_isCopyConstructor(lua_State *L) {
    CXCursor cur = olua_toCXCursor(L, 1);
    lua_pushboolean(L, clang_CXXConstructor_isCopyConstructor(cur));
    return 1;
}

static int lcursor_clang_CXXConstructor_isDefaultConstructor(lua_State *L) {
    CXCursor cur = olua_toCXCursor(L, 1);
    lua_pushboolean(L, clang_CXXConstructor_isDefaultConstructor(cur));
    return 1;
}

static int lcursor_clang_CXXConstructor_isMoveConstructor(lua_State *L) {
    CXCursor cur = olua_toCXCursor(L, 1);
    lua_pushboolean(L, clang_CXXConstructor_isMoveConstructor(cur));
    return 1;
}

static int lcursor_clang_Cursor_isVariadic(lua_State *L) {
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

static int lcursor_clang_getTypedefDeclUnderlyingType(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    olua_pushCXType(L, clang_getTypedefDeclUnderlyingType(cur));
    return 1;
}

static int lcursor_clang_getChildren(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    lua_createtable(L, 0, 0);
    clang_visitChildren(cur, childrenVisitor, L);
    return 1;
}

static int lcursor_clang_Cursor_getTemplateArgumentTypes(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    int total = clang_Cursor_getNumTemplateArguments(cur);
    lua_createtable(L, total, 0);
    for (int i = 0; i < total; i++) {
        olua_pushCXType(L, clang_Cursor_getTemplateArgumentType(cur, i));
        olua_rawseti(L, -2, i + 1);
    }
    return 1;
}

static int lcursor_clang_getCursorPrettyPrinted(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    olua_pushCXString(L, clang_getCursorPrettyPrinted(cur, nullptr));
    return 1;
}

static int lcursor_clang_getCanonicalCursor(lua_State *L)
{
    CXCursor cur = olua_toCXCursor(L, 1);
    olua_pushCXCursor(L, clang_getCanonicalCursor(cur));
    return 1;
}

static int luaopen_clang_cursor(lua_State *L)
{
    oluacls_class(L, CLANG_CURSOR, NULL);
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_func(L, "__eq", lcursor_clang_equalCursors);
    oluacls_prop(L, "name", lcursor_clang_getCursorSpelling, NULL);
    oluacls_prop(L, "kind", lcursor_clang_getCursorKind, NULL);
    oluacls_prop(L, "type", lcursor_clang_getCursorType, NULL);
    oluacls_prop(L, "displayName", lcursor_clang_getCursorDisplayName, NULL);
    oluacls_prop(L, "access", lcursor_clang_getCXXAccessSpecifier, NULL);
    oluacls_func(L, "location", lcursor_clang_getSpellingLocation);
    oluacls_prop(L, "usr", lcursor_clang_getCursorUSR, NULL);
    oluacls_prop(L, "parent", lcursor_clang_getCursorSemanticParent, NULL);
    oluacls_prop(L, "arguments", lcursor_clang_Cursor_getArguments, NULL);
    oluacls_prop(L, "referenced", lcursor_clang_getCursorReferenced, NULL);
    oluacls_prop(L, "definition", lcursor_clang_getCursorDefinition, NULL);
    oluacls_prop(L, "isDeclaration", lcursor_clang_isDeclaration, NULL);
    oluacls_prop(L, "isInvalidDeclaration", lcursor_clang_isInvalidDeclaration, NULL);
    oluacls_prop(L, "isReference", lcursor_clang_isReference, NULL);
    oluacls_prop(L, "isExpression", lcursor_clang_isExpression, NULL);
    oluacls_prop(L, "isStatement", lcursor_clang_isStatement, NULL);
    oluacls_prop(L, "isAttribute", lcursor_clang_isAttribute, NULL);
    oluacls_prop(L, "isStatic", lcursor_clang_CXXMethod_isStatic, NULL);
    oluacls_prop(L, "isVirtual", lcursor_clang_CXXMethod_isVirtual, NULL);
    oluacls_prop(L, "isPureVirtual", lcursor_clang_CXXMethod_isPureVirtual, NULL);
    oluacls_prop(L, "isAbstract", lcursor_clang_CXXRecord_isAbstract, NULL);
    oluacls_prop(L, "isConst", lcursor_clang_CXXMethod_isConst, NULL);
    oluacls_prop(L, "resultType", lcursor_clang_getCursorResultType, NULL);
    oluacls_prop(L, "isConvertingConstructor", lcursor_clang_CXXConstructor_isConvertingConstructor, NULL);
    oluacls_prop(L, "isCopyConstructor", lcursor_clang_CXXConstructor_isCopyConstructor, NULL);
    oluacls_prop(L, "isDefaultConstructor", lcursor_clang_CXXConstructor_isDefaultConstructor, NULL);
    oluacls_prop(L, "isMoveConstructor", lcursor_clang_CXXConstructor_isMoveConstructor, NULL);
    oluacls_prop(L, "isVariadic", lcursor_clang_Cursor_isVariadic, NULL);
    oluacls_prop(L, "underlyingType", lcursor_clang_getTypedefDeclUnderlyingType, NULL);
    oluacls_prop(L, "children", lcursor_clang_getChildren, NULL);
    oluacls_prop(L, "templateArgTypes", lcursor_clang_Cursor_getTemplateArgumentTypes, NULL);
    oluacls_prop(L, "prettyPrinted", lcursor_clang_getCursorPrettyPrinted, NULL);
    oluacls_prop(L, "canonical", lcursor_clang_getCanonicalCursor, NULL);
    return 1;
}

static int ltu_clang_getTranslationUnitCursor(lua_State *L)
{
    CXTranslationUnit tu = olua_toCXTranslationUnit(L, 1);
    olua_pushCXCursor(L, clang_getTranslationUnitCursor(tu));
    return 1;
}

static int ltu_clang_getFile(lua_State *L)
{
    CXTranslationUnit tu = olua_toCXTranslationUnit(L, 1);
    const char *file = olua_checkstring(L, 2);
    CXFile f = clang_getFile(tu, file);
    olua_pushCXString(L, clang_getFileName(f));
    lua_pushnumber(L, (lua_Number)clang_getFileTime(f));
    return 2;
}

static int ltu_clang_getDiagnostic(lua_State *L) {
    CXTranslationUnit tu = olua_toCXTranslationUnit(L, 1);
    int nDiag = clang_getNumDiagnostics(tu);
    lua_createtable(L, nDiag, 0);
    for (int i=0; i<nDiag; i++) {
        olua_pushDiagnostic(L, clang_getDiagnostic(tu, i));
        lua_rawseti(L, -2, i+1);
    }
    return 1;
}

static int ltu_clang_disposeTranslationUnit(lua_State *L)
{
    CXTranslationUnit tu = olua_toCXTranslationUnit(L, 1);
    clang_disposeTranslationUnit(tu);
    return 0;
}

static int luaopen_clang_tu(lua_State *L)
{
    oluacls_class(L, CLANG_TU, NULL);
    oluacls_func(L, "__gc", ltu_clang_disposeTranslationUnit);
    oluacls_func(L, "cursor", ltu_clang_getTranslationUnitCursor);
    oluacls_func(L, "file", ltu_clang_getFile);
    oluacls_func(L, "diagnostics", ltu_clang_getDiagnostic);
    return 1;
}

static int lindex_clang_createTranslationUnit(lua_State *L)
{
    CXIndex idx = olua_toCXIndex(L, 1);
    const char *ast_filename = olua_checkstring(L, 2);
    CXTranslationUnit tu = clang_createTranslationUnit(idx, ast_filename);
    if (tu) {
        olua_pushobj(L, (void *)tu, CLANG_TU);
    } else {
        lua_pushnil(L);
        lua_pushfstring(L, "failed to open ast file: %s", ast_filename);
        return 2;
    }
    return 1;
}

static int lindex_clang_parseTranslationUnit(lua_State *L)
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
        olua_pushobj(L, (void *)tu, CLANG_TU);
    } else {
        lua_pushnil(L);
        lua_pushfstring(L, "failed to parse file: %s", source_filename);
        return 2;
    }
    return 1;
}

static int lindex_clang_disposeIndex(lua_State *L)
{
    CXIndex idx = olua_toCXIndex(L, 1);
    clang_disposeIndex(idx);
    return 0;
}

static int luaopen_clang_index(lua_State *L)
{
    oluacls_class(L, CLANG_INDEX, NULL);
    oluacls_func(L, "__gc", lindex_clang_disposeIndex);
    oluacls_func(L, "create", lindex_clang_createTranslationUnit);
    oluacls_func(L, "parse", lindex_clang_parseTranslationUnit);
    
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

OLUA_LIB int luaopen_clang(lua_State *L)
{
    olua_require(L, CLANG_TYPE, luaopen_clang_type);
    olua_require(L, CLANG_CURSOR, luaopen_clang_cursor);
    olua_require(L, CLANG_TU, luaopen_clang_tu);
    olua_require(L, CLANG_INDEX, luaopen_clang_index);
    
    oluacls_class(L, "clang", NULL);
    oluacls_func(L, "createIndex", l_clang_createIndex);
    oluacls_const_string(L, "version", LUACLANG_VERSION);
    
    return 1;
}

#ifdef __cplusplus
}
#endif
