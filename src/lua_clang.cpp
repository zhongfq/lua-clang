//
// AUTO BUILD, DON'T MODIFY!
//
#include "lua_clang.h"
#include "clang_wrapper.h"

// clangwrapper::Cursor::SourceRange
OLUA_LIB int olua_push_clangwrapper_Cursor_SourceRange(lua_State *L, const clangwrapper::Cursor::SourceRange *value);
OLUA_LIB void olua_check_clangwrapper_Cursor_SourceRange(lua_State *L, int idx, clangwrapper::Cursor::SourceRange *value);
OLUA_LIB bool olua_is_clangwrapper_Cursor_SourceRange(lua_State *L, int idx);
OLUA_LIB void olua_pack_clangwrapper_Cursor_SourceRange(lua_State *L, int idx, clangwrapper::Cursor::SourceRange *value);
OLUA_LIB int olua_unpack_clangwrapper_Cursor_SourceRange(lua_State *L, const clangwrapper::Cursor::SourceRange *value);
OLUA_LIB bool olua_canpack_clangwrapper_Cursor_SourceRange(lua_State *L, int idx);

// clangwrapper::Cursor::SourceLocation
OLUA_LIB int olua_push_clangwrapper_Cursor_SourceLocation(lua_State *L, const clangwrapper::Cursor::SourceLocation *value);
OLUA_LIB void olua_check_clangwrapper_Cursor_SourceLocation(lua_State *L, int idx, clangwrapper::Cursor::SourceLocation *value);
OLUA_LIB bool olua_is_clangwrapper_Cursor_SourceLocation(lua_State *L, int idx);
OLUA_LIB void olua_pack_clangwrapper_Cursor_SourceLocation(lua_State *L, int idx, clangwrapper::Cursor::SourceLocation *value);
OLUA_LIB int olua_unpack_clangwrapper_Cursor_SourceLocation(lua_State *L, const clangwrapper::Cursor::SourceLocation *value);
OLUA_LIB bool olua_canpack_clangwrapper_Cursor_SourceLocation(lua_State *L, int idx);

OLUA_LIB int olua_push_clangwrapper_Cursor_SourceRange(lua_State *L, const clangwrapper::Cursor::SourceRange *value)
{
    if (value) {
        lua_createtable(L, 0, 5);

        olua_push_std_string(L, value->path);
        olua_setfield(L, -2, "path");

        olua_push_uint(L, (lua_Unsigned)value->startLine);
        olua_setfield(L, -2, "startLine");

        olua_push_uint(L, (lua_Unsigned)value->startColumn);
        olua_setfield(L, -2, "startColumn");

        olua_push_uint(L, (lua_Unsigned)value->endLine);
        olua_setfield(L, -2, "endLine");

        olua_push_uint(L, (lua_Unsigned)value->endColumn);
        olua_setfield(L, -2, "endColumn");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

OLUA_LIB void olua_check_clangwrapper_Cursor_SourceRange(lua_State *L, int idx, clangwrapper::Cursor::SourceRange *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    std::string arg1;       /** path */
    lua_Unsigned arg2 = 0;       /** startLine */
    lua_Unsigned arg3 = 0;       /** startColumn */
    lua_Unsigned arg4 = 0;       /** endLine */
    lua_Unsigned arg5 = 0;       /** endColumn */

    olua_getfield(L, idx, "path");
    olua_check_std_string(L, -1, &arg1);
    value->path = (std::string)arg1;
    lua_pop(L, 1);

    olua_getfield(L, idx, "startLine");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_uint(L, -1, &arg2);
        value->startLine = (unsigned int)arg2;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "startColumn");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_uint(L, -1, &arg3);
        value->startColumn = (unsigned int)arg3;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "endLine");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_uint(L, -1, &arg4);
        value->endLine = (unsigned int)arg4;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "endColumn");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_uint(L, -1, &arg5);
        value->endColumn = (unsigned int)arg5;
    }
    lua_pop(L, 1);
}

OLUA_LIB bool olua_is_clangwrapper_Cursor_SourceRange(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "path");
}

OLUA_LIB void olua_pack_clangwrapper_Cursor_SourceRange(lua_State *L, int idx, clangwrapper::Cursor::SourceRange *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    std::string arg1;       /** path */
    lua_Unsigned arg2 = 0;       /** startLine */
    lua_Unsigned arg3 = 0;       /** startColumn */
    lua_Unsigned arg4 = 0;       /** endLine */
    lua_Unsigned arg5 = 0;       /** endColumn */

    olua_check_std_string(L, idx + 0, &arg1);
    value->path = (std::string)arg1;

    olua_check_uint(L, idx + 1, &arg2);
    value->startLine = (unsigned int)arg2;

    olua_check_uint(L, idx + 2, &arg3);
    value->startColumn = (unsigned int)arg3;

    olua_check_uint(L, idx + 3, &arg4);
    value->endLine = (unsigned int)arg4;

    olua_check_uint(L, idx + 4, &arg5);
    value->endColumn = (unsigned int)arg5;
}

OLUA_LIB int olua_unpack_clangwrapper_Cursor_SourceRange(lua_State *L, const clangwrapper::Cursor::SourceRange *value)
{
    if (value) {
        olua_push_std_string(L, value->path);
        olua_push_uint(L, (lua_Unsigned)value->startLine);
        olua_push_uint(L, (lua_Unsigned)value->startColumn);
        olua_push_uint(L, (lua_Unsigned)value->endLine);
        olua_push_uint(L, (lua_Unsigned)value->endColumn);
    } else {
        for (int i = 0; i < 5; i++) {
            lua_pushnil(L);
        }
    }

    return 5;
}

OLUA_LIB bool olua_canpack_clangwrapper_Cursor_SourceRange(lua_State *L, int idx)
{
    return olua_is_std_string(L, idx + 0) && olua_is_uint(L, idx + 1) && olua_is_uint(L, idx + 2) && olua_is_uint(L, idx + 3) && olua_is_uint(L, idx + 4);
}

OLUA_LIB int olua_push_clangwrapper_Cursor_SourceLocation(lua_State *L, const clangwrapper::Cursor::SourceLocation *value)
{
    if (value) {
        lua_createtable(L, 0, 3);

        olua_push_std_string(L, value->path);
        olua_setfield(L, -2, "path");

        olua_push_uint(L, (lua_Unsigned)value->line);
        olua_setfield(L, -2, "line");

        olua_push_uint(L, (lua_Unsigned)value->column);
        olua_setfield(L, -2, "column");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

OLUA_LIB void olua_check_clangwrapper_Cursor_SourceLocation(lua_State *L, int idx, clangwrapper::Cursor::SourceLocation *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    std::string arg1;       /** path */
    lua_Unsigned arg2 = 0;       /** line */
    lua_Unsigned arg3 = 0;       /** column */

    olua_getfield(L, idx, "path");
    olua_check_std_string(L, -1, &arg1);
    value->path = (std::string)arg1;
    lua_pop(L, 1);

    olua_getfield(L, idx, "line");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_uint(L, -1, &arg2);
        value->line = (unsigned int)arg2;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "column");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_uint(L, -1, &arg3);
        value->column = (unsigned int)arg3;
    }
    lua_pop(L, 1);
}

OLUA_LIB bool olua_is_clangwrapper_Cursor_SourceLocation(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "path");
}

OLUA_LIB void olua_pack_clangwrapper_Cursor_SourceLocation(lua_State *L, int idx, clangwrapper::Cursor::SourceLocation *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    std::string arg1;       /** path */
    lua_Unsigned arg2 = 0;       /** line */
    lua_Unsigned arg3 = 0;       /** column */

    olua_check_std_string(L, idx + 0, &arg1);
    value->path = (std::string)arg1;

    olua_check_uint(L, idx + 1, &arg2);
    value->line = (unsigned int)arg2;

    olua_check_uint(L, idx + 2, &arg3);
    value->column = (unsigned int)arg3;
}

OLUA_LIB int olua_unpack_clangwrapper_Cursor_SourceLocation(lua_State *L, const clangwrapper::Cursor::SourceLocation *value)
{
    if (value) {
        olua_push_std_string(L, value->path);
        olua_push_uint(L, (lua_Unsigned)value->line);
        olua_push_uint(L, (lua_Unsigned)value->column);
    } else {
        for (int i = 0; i < 3; i++) {
            lua_pushnil(L);
        }
    }

    return 3;
}

OLUA_LIB bool olua_canpack_clangwrapper_Cursor_SourceLocation(lua_State *L, int idx)
{
    return olua_is_std_string(L, idx + 0) && olua_is_uint(L, idx + 1) && olua_is_uint(L, idx + 2);
}

static int _clangwrapper_IndexError___index(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::IndexError *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.IndexError");

    // olua_Return __index(lua_State *L)
    olua_Return ret = self->__index(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _clangwrapper_IndexError___newindex(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::IndexError *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.IndexError");

    // olua_Return __newindex(lua_State *L)
    olua_Return ret = self->__newindex(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _clangwrapper_IndexError___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (clangwrapper::IndexError *)olua_toobj(L, 1, "clangwrapper.IndexError");
    olua_push_obj(L, self, "clangwrapper.IndexError");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_IndexError(lua_State *L)
{
    oluacls_class(L, "clangwrapper.IndexError", nullptr);
    oluacls_func(L, "__index", _clangwrapper_IndexError___index);
    oluacls_func(L, "__newindex", _clangwrapper_IndexError___newindex);
    oluacls_func(L, "__olua_move", _clangwrapper_IndexError___olua_move);

    olua_registerluatype<clangwrapper::IndexError>(L, "clangwrapper.IndexError");

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_AvailabilityKind(lua_State *L)
{
    oluacls_class(L, "clangwrapper.AvailabilityKind", nullptr);
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_const_integer(L, "Available", (lua_Integer)clangwrapper::AvailabilityKind::CXAvailability_Available);
    oluacls_const_integer(L, "Deprecated", (lua_Integer)clangwrapper::AvailabilityKind::CXAvailability_Deprecated);
    oluacls_const_integer(L, "NotAccessible", (lua_Integer)clangwrapper::AvailabilityKind::CXAvailability_NotAccessible);
    oluacls_const_integer(L, "NotAvailable", (lua_Integer)clangwrapper::AvailabilityKind::CXAvailability_NotAvailable);

    olua_registerluatype<clangwrapper::AvailabilityKind>(L, "clangwrapper.AvailabilityKind");

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_CallingConv(lua_State *L)
{
    oluacls_class(L, "clangwrapper.CallingConv", nullptr);
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_const_integer(L, "AAPCS", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_AAPCS);
    oluacls_const_integer(L, "AAPCS_VFP", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_AAPCS_VFP);
    oluacls_const_integer(L, "AArch64SVEPCS", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_AArch64SVEPCS);
    oluacls_const_integer(L, "AArch64VectorCall", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_AArch64VectorCall);
    oluacls_const_integer(L, "C", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_C);
    oluacls_const_integer(L, "Default", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_Default);
    oluacls_const_integer(L, "IntelOclBicc", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_IntelOclBicc);
    oluacls_const_integer(L, "Invalid", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_Invalid);
    oluacls_const_integer(L, "PreserveAll", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_PreserveAll);
    oluacls_const_integer(L, "PreserveMost", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_PreserveMost);
    oluacls_const_integer(L, "Swift", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_Swift);
    oluacls_const_integer(L, "SwiftAsync", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_SwiftAsync);
    oluacls_const_integer(L, "Unexposed", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_Unexposed);
    oluacls_const_integer(L, "Win64", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_Win64);
    oluacls_const_integer(L, "X86FastCall", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_X86FastCall);
    oluacls_const_integer(L, "X86Pascal", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_X86Pascal);
    oluacls_const_integer(L, "X86RegCall", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_X86RegCall);
    oluacls_const_integer(L, "X86StdCall", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_X86StdCall);
    oluacls_const_integer(L, "X86ThisCall", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_X86ThisCall);
    oluacls_const_integer(L, "X86VectorCall", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_X86VectorCall);
    oluacls_const_integer(L, "X86_64SysV", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_X86_64SysV);
    oluacls_const_integer(L, "X86_64Win64", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_X86_64Win64);

    olua_registerluatype<clangwrapper::CallingConv>(L, "clangwrapper.CallingConv");

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_CursorKind(lua_State *L)
{
    oluacls_class(L, "clangwrapper.CursorKind", nullptr);
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_const_integer(L, "AddrLabelExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_AddrLabelExpr);
    oluacls_const_integer(L, "AlignedAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_AlignedAttr);
    oluacls_const_integer(L, "AnnotateAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_AnnotateAttr);
    oluacls_const_integer(L, "ArraySubscriptExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_ArraySubscriptExpr);
    oluacls_const_integer(L, "AsmLabelAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_AsmLabelAttr);
    oluacls_const_integer(L, "AsmStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_AsmStmt);
    oluacls_const_integer(L, "BinaryOperator", (lua_Integer)clangwrapper::CursorKind::CXCursor_BinaryOperator);
    oluacls_const_integer(L, "BlockExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_BlockExpr);
    oluacls_const_integer(L, "BreakStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_BreakStmt);
    oluacls_const_integer(L, "BuiltinBitCastExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_BuiltinBitCastExpr);
    oluacls_const_integer(L, "CStyleCastExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CStyleCastExpr);
    oluacls_const_integer(L, "CUDAConstantAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CUDAConstantAttr);
    oluacls_const_integer(L, "CUDADeviceAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CUDADeviceAttr);
    oluacls_const_integer(L, "CUDAGlobalAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CUDAGlobalAttr);
    oluacls_const_integer(L, "CUDAHostAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CUDAHostAttr);
    oluacls_const_integer(L, "CUDASharedAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CUDASharedAttr);
    oluacls_const_integer(L, "CXXAccessSpecifier", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXAccessSpecifier);
    oluacls_const_integer(L, "CXXAddrspaceCastExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXAddrspaceCastExpr);
    oluacls_const_integer(L, "CXXBaseSpecifier", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXBaseSpecifier);
    oluacls_const_integer(L, "CXXBoolLiteralExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXBoolLiteralExpr);
    oluacls_const_integer(L, "CXXCatchStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXCatchStmt);
    oluacls_const_integer(L, "CXXConstCastExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXConstCastExpr);
    oluacls_const_integer(L, "CXXDeleteExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXDeleteExpr);
    oluacls_const_integer(L, "CXXDynamicCastExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXDynamicCastExpr);
    oluacls_const_integer(L, "CXXFinalAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXFinalAttr);
    oluacls_const_integer(L, "CXXForRangeStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXForRangeStmt);
    oluacls_const_integer(L, "CXXFunctionalCastExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXFunctionalCastExpr);
    oluacls_const_integer(L, "CXXMethod", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXMethod);
    oluacls_const_integer(L, "CXXNewExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXNewExpr);
    oluacls_const_integer(L, "CXXNullPtrLiteralExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXNullPtrLiteralExpr);
    oluacls_const_integer(L, "CXXOverrideAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXOverrideAttr);
    oluacls_const_integer(L, "CXXReinterpretCastExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXReinterpretCastExpr);
    oluacls_const_integer(L, "CXXStaticCastExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXStaticCastExpr);
    oluacls_const_integer(L, "CXXThisExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXThisExpr);
    oluacls_const_integer(L, "CXXThrowExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXThrowExpr);
    oluacls_const_integer(L, "CXXTryStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXTryStmt);
    oluacls_const_integer(L, "CXXTypeidExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXTypeidExpr);
    oluacls_const_integer(L, "CallExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CallExpr);
    oluacls_const_integer(L, "CaseStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_CaseStmt);
    oluacls_const_integer(L, "CharacterLiteral", (lua_Integer)clangwrapper::CursorKind::CXCursor_CharacterLiteral);
    oluacls_const_integer(L, "ClassDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_ClassDecl);
    oluacls_const_integer(L, "ClassTemplate", (lua_Integer)clangwrapper::CursorKind::CXCursor_ClassTemplate);
    oluacls_const_integer(L, "ClassTemplatePartialSpecialization", (lua_Integer)clangwrapper::CursorKind::CXCursor_ClassTemplatePartialSpecialization);
    oluacls_const_integer(L, "CompoundAssignOperator", (lua_Integer)clangwrapper::CursorKind::CXCursor_CompoundAssignOperator);
    oluacls_const_integer(L, "CompoundLiteralExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CompoundLiteralExpr);
    oluacls_const_integer(L, "CompoundStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_CompoundStmt);
    oluacls_const_integer(L, "ConceptDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_ConceptDecl);
    oluacls_const_integer(L, "ConceptSpecializationExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_ConceptSpecializationExpr);
    oluacls_const_integer(L, "ConditionalOperator", (lua_Integer)clangwrapper::CursorKind::CXCursor_ConditionalOperator);
    oluacls_const_integer(L, "ConstAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_ConstAttr);
    oluacls_const_integer(L, "Constructor", (lua_Integer)clangwrapper::CursorKind::CXCursor_Constructor);
    oluacls_const_integer(L, "ContinueStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_ContinueStmt);
    oluacls_const_integer(L, "ConvergentAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_ConvergentAttr);
    oluacls_const_integer(L, "ConversionFunction", (lua_Integer)clangwrapper::CursorKind::CXCursor_ConversionFunction);
    oluacls_const_integer(L, "DLLExport", (lua_Integer)clangwrapper::CursorKind::CXCursor_DLLExport);
    oluacls_const_integer(L, "DLLImport", (lua_Integer)clangwrapper::CursorKind::CXCursor_DLLImport);
    oluacls_const_integer(L, "DeclRefExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_DeclRefExpr);
    oluacls_const_integer(L, "DeclStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_DeclStmt);
    oluacls_const_integer(L, "DefaultStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_DefaultStmt);
    oluacls_const_integer(L, "Destructor", (lua_Integer)clangwrapper::CursorKind::CXCursor_Destructor);
    oluacls_const_integer(L, "DoStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_DoStmt);
    oluacls_const_integer(L, "EnumConstantDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_EnumConstantDecl);
    oluacls_const_integer(L, "EnumDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_EnumDecl);
    oluacls_const_integer(L, "FieldDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_FieldDecl);
    oluacls_const_integer(L, "FirstAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_FirstAttr);
    oluacls_const_integer(L, "FirstDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_FirstDecl);
    oluacls_const_integer(L, "FirstExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_FirstExpr);
    oluacls_const_integer(L, "FirstExtraDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_FirstExtraDecl);
    oluacls_const_integer(L, "FirstInvalid", (lua_Integer)clangwrapper::CursorKind::CXCursor_FirstInvalid);
    oluacls_const_integer(L, "FirstPreprocessing", (lua_Integer)clangwrapper::CursorKind::CXCursor_FirstPreprocessing);
    oluacls_const_integer(L, "FirstRef", (lua_Integer)clangwrapper::CursorKind::CXCursor_FirstRef);
    oluacls_const_integer(L, "FirstStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_FirstStmt);
    oluacls_const_integer(L, "FixedPointLiteral", (lua_Integer)clangwrapper::CursorKind::CXCursor_FixedPointLiteral);
    oluacls_const_integer(L, "FlagEnum", (lua_Integer)clangwrapper::CursorKind::CXCursor_FlagEnum);
    oluacls_const_integer(L, "FloatingLiteral", (lua_Integer)clangwrapper::CursorKind::CXCursor_FloatingLiteral);
    oluacls_const_integer(L, "ForStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_ForStmt);
    oluacls_const_integer(L, "FriendDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_FriendDecl);
    oluacls_const_integer(L, "FunctionDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_FunctionDecl);
    oluacls_const_integer(L, "FunctionTemplate", (lua_Integer)clangwrapper::CursorKind::CXCursor_FunctionTemplate);
    oluacls_const_integer(L, "GCCAsmStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_GCCAsmStmt);
    oluacls_const_integer(L, "GNUNullExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_GNUNullExpr);
    oluacls_const_integer(L, "GenericSelectionExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_GenericSelectionExpr);
    oluacls_const_integer(L, "GotoStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_GotoStmt);
    oluacls_const_integer(L, "IBActionAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_IBActionAttr);
    oluacls_const_integer(L, "IBOutletAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_IBOutletAttr);
    oluacls_const_integer(L, "IBOutletCollectionAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_IBOutletCollectionAttr);
    oluacls_const_integer(L, "IfStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_IfStmt);
    oluacls_const_integer(L, "ImaginaryLiteral", (lua_Integer)clangwrapper::CursorKind::CXCursor_ImaginaryLiteral);
    oluacls_const_integer(L, "InclusionDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_InclusionDirective);
    oluacls_const_integer(L, "IndirectGotoStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_IndirectGotoStmt);
    oluacls_const_integer(L, "InitListExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_InitListExpr);
    oluacls_const_integer(L, "IntegerLiteral", (lua_Integer)clangwrapper::CursorKind::CXCursor_IntegerLiteral);
    oluacls_const_integer(L, "InvalidCode", (lua_Integer)clangwrapper::CursorKind::CXCursor_InvalidCode);
    oluacls_const_integer(L, "InvalidFile", (lua_Integer)clangwrapper::CursorKind::CXCursor_InvalidFile);
    oluacls_const_integer(L, "LabelRef", (lua_Integer)clangwrapper::CursorKind::CXCursor_LabelRef);
    oluacls_const_integer(L, "LabelStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_LabelStmt);
    oluacls_const_integer(L, "LambdaExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_LambdaExpr);
    oluacls_const_integer(L, "LastAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_LastAttr);
    oluacls_const_integer(L, "LastDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_LastDecl);
    oluacls_const_integer(L, "LastExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_LastExpr);
    oluacls_const_integer(L, "LastExtraDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_LastExtraDecl);
    oluacls_const_integer(L, "LastInvalid", (lua_Integer)clangwrapper::CursorKind::CXCursor_LastInvalid);
    oluacls_const_integer(L, "LastPreprocessing", (lua_Integer)clangwrapper::CursorKind::CXCursor_LastPreprocessing);
    oluacls_const_integer(L, "LastRef", (lua_Integer)clangwrapper::CursorKind::CXCursor_LastRef);
    oluacls_const_integer(L, "LastStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_LastStmt);
    oluacls_const_integer(L, "LinkageSpec", (lua_Integer)clangwrapper::CursorKind::CXCursor_LinkageSpec);
    oluacls_const_integer(L, "MSAsmStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_MSAsmStmt);
    oluacls_const_integer(L, "MacroDefinition", (lua_Integer)clangwrapper::CursorKind::CXCursor_MacroDefinition);
    oluacls_const_integer(L, "MacroExpansion", (lua_Integer)clangwrapper::CursorKind::CXCursor_MacroExpansion);
    oluacls_const_integer(L, "MacroInstantiation", (lua_Integer)clangwrapper::CursorKind::CXCursor_MacroInstantiation);
    oluacls_const_integer(L, "MemberRef", (lua_Integer)clangwrapper::CursorKind::CXCursor_MemberRef);
    oluacls_const_integer(L, "MemberRefExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_MemberRefExpr);
    oluacls_const_integer(L, "ModuleImportDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_ModuleImportDecl);
    oluacls_const_integer(L, "NSConsumed", (lua_Integer)clangwrapper::CursorKind::CXCursor_NSConsumed);
    oluacls_const_integer(L, "NSConsumesSelf", (lua_Integer)clangwrapper::CursorKind::CXCursor_NSConsumesSelf);
    oluacls_const_integer(L, "NSReturnsAutoreleased", (lua_Integer)clangwrapper::CursorKind::CXCursor_NSReturnsAutoreleased);
    oluacls_const_integer(L, "NSReturnsNotRetained", (lua_Integer)clangwrapper::CursorKind::CXCursor_NSReturnsNotRetained);
    oluacls_const_integer(L, "NSReturnsRetained", (lua_Integer)clangwrapper::CursorKind::CXCursor_NSReturnsRetained);
    oluacls_const_integer(L, "Namespace", (lua_Integer)clangwrapper::CursorKind::CXCursor_Namespace);
    oluacls_const_integer(L, "NamespaceAlias", (lua_Integer)clangwrapper::CursorKind::CXCursor_NamespaceAlias);
    oluacls_const_integer(L, "NamespaceRef", (lua_Integer)clangwrapper::CursorKind::CXCursor_NamespaceRef);
    oluacls_const_integer(L, "NoDeclFound", (lua_Integer)clangwrapper::CursorKind::CXCursor_NoDeclFound);
    oluacls_const_integer(L, "NoDuplicateAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_NoDuplicateAttr);
    oluacls_const_integer(L, "NonTypeTemplateParameter", (lua_Integer)clangwrapper::CursorKind::CXCursor_NonTypeTemplateParameter);
    oluacls_const_integer(L, "NotImplemented", (lua_Integer)clangwrapper::CursorKind::CXCursor_NotImplemented);
    oluacls_const_integer(L, "NullStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_NullStmt);
    oluacls_const_integer(L, "OMPArraySectionExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPArraySectionExpr);
    oluacls_const_integer(L, "OMPArrayShapingExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPArrayShapingExpr);
    oluacls_const_integer(L, "OMPAtomicDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPAtomicDirective);
    oluacls_const_integer(L, "OMPBarrierDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPBarrierDirective);
    oluacls_const_integer(L, "OMPCancelDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPCancelDirective);
    oluacls_const_integer(L, "OMPCancellationPointDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPCancellationPointDirective);
    oluacls_const_integer(L, "OMPCanonicalLoop", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPCanonicalLoop);
    oluacls_const_integer(L, "OMPCriticalDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPCriticalDirective);
    oluacls_const_integer(L, "OMPDepobjDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPDepobjDirective);
    oluacls_const_integer(L, "OMPDispatchDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPDispatchDirective);
    oluacls_const_integer(L, "OMPDistributeDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPDistributeDirective);
    oluacls_const_integer(L, "OMPDistributeParallelForDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPDistributeParallelForDirective);
    oluacls_const_integer(L, "OMPDistributeParallelForSimdDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPDistributeParallelForSimdDirective);
    oluacls_const_integer(L, "OMPDistributeSimdDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPDistributeSimdDirective);
    oluacls_const_integer(L, "OMPErrorDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPErrorDirective);
    oluacls_const_integer(L, "OMPFlushDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPFlushDirective);
    oluacls_const_integer(L, "OMPForDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPForDirective);
    oluacls_const_integer(L, "OMPForSimdDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPForSimdDirective);
    oluacls_const_integer(L, "OMPGenericLoopDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPGenericLoopDirective);
    oluacls_const_integer(L, "OMPInteropDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPInteropDirective);
    oluacls_const_integer(L, "OMPIteratorExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPIteratorExpr);
    oluacls_const_integer(L, "OMPMaskedDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPMaskedDirective);
    oluacls_const_integer(L, "OMPMaskedTaskLoopDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPMaskedTaskLoopDirective);
    oluacls_const_integer(L, "OMPMaskedTaskLoopSimdDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPMaskedTaskLoopSimdDirective);
    oluacls_const_integer(L, "OMPMasterDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPMasterDirective);
    oluacls_const_integer(L, "OMPMasterTaskLoopDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPMasterTaskLoopDirective);
    oluacls_const_integer(L, "OMPMasterTaskLoopSimdDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPMasterTaskLoopSimdDirective);
    oluacls_const_integer(L, "OMPMetaDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPMetaDirective);
    oluacls_const_integer(L, "OMPOrderedDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPOrderedDirective);
    oluacls_const_integer(L, "OMPParallelDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPParallelDirective);
    oluacls_const_integer(L, "OMPParallelForDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPParallelForDirective);
    oluacls_const_integer(L, "OMPParallelForSimdDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPParallelForSimdDirective);
    oluacls_const_integer(L, "OMPParallelGenericLoopDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPParallelGenericLoopDirective);
    oluacls_const_integer(L, "OMPParallelMaskedDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPParallelMaskedDirective);
    oluacls_const_integer(L, "OMPParallelMaskedTaskLoopDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPParallelMaskedTaskLoopDirective);
    oluacls_const_integer(L, "OMPParallelMaskedTaskLoopSimdDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPParallelMaskedTaskLoopSimdDirective);
    oluacls_const_integer(L, "OMPParallelMasterDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPParallelMasterDirective);
    oluacls_const_integer(L, "OMPParallelMasterTaskLoopDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPParallelMasterTaskLoopDirective);
    oluacls_const_integer(L, "OMPParallelMasterTaskLoopSimdDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPParallelMasterTaskLoopSimdDirective);
    oluacls_const_integer(L, "OMPParallelSectionsDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPParallelSectionsDirective);
    oluacls_const_integer(L, "OMPScanDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPScanDirective);
    oluacls_const_integer(L, "OMPSectionDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPSectionDirective);
    oluacls_const_integer(L, "OMPSectionsDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPSectionsDirective);
    oluacls_const_integer(L, "OMPSimdDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPSimdDirective);
    oluacls_const_integer(L, "OMPSingleDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPSingleDirective);
    oluacls_const_integer(L, "OMPTargetDataDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTargetDataDirective);
    oluacls_const_integer(L, "OMPTargetDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTargetDirective);
    oluacls_const_integer(L, "OMPTargetEnterDataDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTargetEnterDataDirective);
    oluacls_const_integer(L, "OMPTargetExitDataDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTargetExitDataDirective);
    oluacls_const_integer(L, "OMPTargetParallelDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTargetParallelDirective);
    oluacls_const_integer(L, "OMPTargetParallelForDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTargetParallelForDirective);
    oluacls_const_integer(L, "OMPTargetParallelForSimdDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTargetParallelForSimdDirective);
    oluacls_const_integer(L, "OMPTargetParallelGenericLoopDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTargetParallelGenericLoopDirective);
    oluacls_const_integer(L, "OMPTargetSimdDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTargetSimdDirective);
    oluacls_const_integer(L, "OMPTargetTeamsDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTargetTeamsDirective);
    oluacls_const_integer(L, "OMPTargetTeamsDistributeDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTargetTeamsDistributeDirective);
    oluacls_const_integer(L, "OMPTargetTeamsDistributeParallelForDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTargetTeamsDistributeParallelForDirective);
    oluacls_const_integer(L, "OMPTargetTeamsDistributeParallelForSimdDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTargetTeamsDistributeParallelForSimdDirective);
    oluacls_const_integer(L, "OMPTargetTeamsDistributeSimdDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTargetTeamsDistributeSimdDirective);
    oluacls_const_integer(L, "OMPTargetTeamsGenericLoopDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTargetTeamsGenericLoopDirective);
    oluacls_const_integer(L, "OMPTargetUpdateDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTargetUpdateDirective);
    oluacls_const_integer(L, "OMPTaskDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTaskDirective);
    oluacls_const_integer(L, "OMPTaskLoopDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTaskLoopDirective);
    oluacls_const_integer(L, "OMPTaskLoopSimdDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTaskLoopSimdDirective);
    oluacls_const_integer(L, "OMPTaskgroupDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTaskgroupDirective);
    oluacls_const_integer(L, "OMPTaskwaitDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTaskwaitDirective);
    oluacls_const_integer(L, "OMPTaskyieldDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTaskyieldDirective);
    oluacls_const_integer(L, "OMPTeamsDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTeamsDirective);
    oluacls_const_integer(L, "OMPTeamsDistributeDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTeamsDistributeDirective);
    oluacls_const_integer(L, "OMPTeamsDistributeParallelForDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTeamsDistributeParallelForDirective);
    oluacls_const_integer(L, "OMPTeamsDistributeParallelForSimdDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTeamsDistributeParallelForSimdDirective);
    oluacls_const_integer(L, "OMPTeamsDistributeSimdDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTeamsDistributeSimdDirective);
    oluacls_const_integer(L, "OMPTeamsGenericLoopDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTeamsGenericLoopDirective);
    oluacls_const_integer(L, "OMPTileDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTileDirective);
    oluacls_const_integer(L, "OMPUnrollDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPUnrollDirective);
    oluacls_const_integer(L, "ObjCAtCatchStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCAtCatchStmt);
    oluacls_const_integer(L, "ObjCAtFinallyStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCAtFinallyStmt);
    oluacls_const_integer(L, "ObjCAtSynchronizedStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCAtSynchronizedStmt);
    oluacls_const_integer(L, "ObjCAtThrowStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCAtThrowStmt);
    oluacls_const_integer(L, "ObjCAtTryStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCAtTryStmt);
    oluacls_const_integer(L, "ObjCAutoreleasePoolStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCAutoreleasePoolStmt);
    oluacls_const_integer(L, "ObjCAvailabilityCheckExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCAvailabilityCheckExpr);
    oluacls_const_integer(L, "ObjCBoolLiteralExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCBoolLiteralExpr);
    oluacls_const_integer(L, "ObjCBoxable", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCBoxable);
    oluacls_const_integer(L, "ObjCBridgedCastExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCBridgedCastExpr);
    oluacls_const_integer(L, "ObjCCategoryDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCCategoryDecl);
    oluacls_const_integer(L, "ObjCCategoryImplDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCCategoryImplDecl);
    oluacls_const_integer(L, "ObjCClassMethodDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCClassMethodDecl);
    oluacls_const_integer(L, "ObjCClassRef", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCClassRef);
    oluacls_const_integer(L, "ObjCDesignatedInitializer", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCDesignatedInitializer);
    oluacls_const_integer(L, "ObjCDynamicDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCDynamicDecl);
    oluacls_const_integer(L, "ObjCEncodeExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCEncodeExpr);
    oluacls_const_integer(L, "ObjCException", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCException);
    oluacls_const_integer(L, "ObjCExplicitProtocolImpl", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCExplicitProtocolImpl);
    oluacls_const_integer(L, "ObjCForCollectionStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCForCollectionStmt);
    oluacls_const_integer(L, "ObjCImplementationDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCImplementationDecl);
    oluacls_const_integer(L, "ObjCIndependentClass", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCIndependentClass);
    oluacls_const_integer(L, "ObjCInstanceMethodDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCInstanceMethodDecl);
    oluacls_const_integer(L, "ObjCInterfaceDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCInterfaceDecl);
    oluacls_const_integer(L, "ObjCIvarDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCIvarDecl);
    oluacls_const_integer(L, "ObjCMessageExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCMessageExpr);
    oluacls_const_integer(L, "ObjCNSObject", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCNSObject);
    oluacls_const_integer(L, "ObjCPreciseLifetime", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCPreciseLifetime);
    oluacls_const_integer(L, "ObjCPropertyDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCPropertyDecl);
    oluacls_const_integer(L, "ObjCProtocolDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCProtocolDecl);
    oluacls_const_integer(L, "ObjCProtocolExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCProtocolExpr);
    oluacls_const_integer(L, "ObjCProtocolRef", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCProtocolRef);
    oluacls_const_integer(L, "ObjCRequiresSuper", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCRequiresSuper);
    oluacls_const_integer(L, "ObjCReturnsInnerPointer", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCReturnsInnerPointer);
    oluacls_const_integer(L, "ObjCRootClass", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCRootClass);
    oluacls_const_integer(L, "ObjCRuntimeVisible", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCRuntimeVisible);
    oluacls_const_integer(L, "ObjCSelectorExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCSelectorExpr);
    oluacls_const_integer(L, "ObjCSelfExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCSelfExpr);
    oluacls_const_integer(L, "ObjCStringLiteral", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCStringLiteral);
    oluacls_const_integer(L, "ObjCSubclassingRestricted", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCSubclassingRestricted);
    oluacls_const_integer(L, "ObjCSuperClassRef", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCSuperClassRef);
    oluacls_const_integer(L, "ObjCSynthesizeDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCSynthesizeDecl);
    oluacls_const_integer(L, "OverloadCandidate", (lua_Integer)clangwrapper::CursorKind::CXCursor_OverloadCandidate);
    oluacls_const_integer(L, "OverloadedDeclRef", (lua_Integer)clangwrapper::CursorKind::CXCursor_OverloadedDeclRef);
    oluacls_const_integer(L, "PackExpansionExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_PackExpansionExpr);
    oluacls_const_integer(L, "PackedAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_PackedAttr);
    oluacls_const_integer(L, "ParenExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_ParenExpr);
    oluacls_const_integer(L, "ParmDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_ParmDecl);
    oluacls_const_integer(L, "PreprocessingDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_PreprocessingDirective);
    oluacls_const_integer(L, "PureAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_PureAttr);
    oluacls_const_integer(L, "RequiresExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_RequiresExpr);
    oluacls_const_integer(L, "ReturnStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_ReturnStmt);
    oluacls_const_integer(L, "SEHExceptStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_SEHExceptStmt);
    oluacls_const_integer(L, "SEHFinallyStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_SEHFinallyStmt);
    oluacls_const_integer(L, "SEHLeaveStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_SEHLeaveStmt);
    oluacls_const_integer(L, "SEHTryStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_SEHTryStmt);
    oluacls_const_integer(L, "SizeOfPackExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_SizeOfPackExpr);
    oluacls_const_integer(L, "StaticAssert", (lua_Integer)clangwrapper::CursorKind::CXCursor_StaticAssert);
    oluacls_const_integer(L, "StmtExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_StmtExpr);
    oluacls_const_integer(L, "StringLiteral", (lua_Integer)clangwrapper::CursorKind::CXCursor_StringLiteral);
    oluacls_const_integer(L, "StructDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_StructDecl);
    oluacls_const_integer(L, "SwitchStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_SwitchStmt);
    oluacls_const_integer(L, "TemplateRef", (lua_Integer)clangwrapper::CursorKind::CXCursor_TemplateRef);
    oluacls_const_integer(L, "TemplateTemplateParameter", (lua_Integer)clangwrapper::CursorKind::CXCursor_TemplateTemplateParameter);
    oluacls_const_integer(L, "TemplateTypeParameter", (lua_Integer)clangwrapper::CursorKind::CXCursor_TemplateTypeParameter);
    oluacls_const_integer(L, "TranslationUnit", (lua_Integer)clangwrapper::CursorKind::CXCursor_TranslationUnit);
    oluacls_const_integer(L, "TypeAliasDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_TypeAliasDecl);
    oluacls_const_integer(L, "TypeAliasTemplateDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_TypeAliasTemplateDecl);
    oluacls_const_integer(L, "TypeRef", (lua_Integer)clangwrapper::CursorKind::CXCursor_TypeRef);
    oluacls_const_integer(L, "TypedefDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_TypedefDecl);
    oluacls_const_integer(L, "UnaryExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_UnaryExpr);
    oluacls_const_integer(L, "UnaryOperator", (lua_Integer)clangwrapper::CursorKind::CXCursor_UnaryOperator);
    oluacls_const_integer(L, "UnexposedAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_UnexposedAttr);
    oluacls_const_integer(L, "UnexposedDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_UnexposedDecl);
    oluacls_const_integer(L, "UnexposedExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_UnexposedExpr);
    oluacls_const_integer(L, "UnexposedStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_UnexposedStmt);
    oluacls_const_integer(L, "UnionDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_UnionDecl);
    oluacls_const_integer(L, "UsingDeclaration", (lua_Integer)clangwrapper::CursorKind::CXCursor_UsingDeclaration);
    oluacls_const_integer(L, "UsingDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_UsingDirective);
    oluacls_const_integer(L, "VarDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_VarDecl);
    oluacls_const_integer(L, "VariableRef", (lua_Integer)clangwrapper::CursorKind::CXCursor_VariableRef);
    oluacls_const_integer(L, "VisibilityAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_VisibilityAttr);
    oluacls_const_integer(L, "WarnUnusedAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_WarnUnusedAttr);
    oluacls_const_integer(L, "WarnUnusedResultAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_WarnUnusedResultAttr);
    oluacls_const_integer(L, "WhileStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_WhileStmt);

    olua_registerluatype<clangwrapper::CursorKind>(L, "clangwrapper.CursorKind");

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_CXXAccessSpecifier(lua_State *L)
{
    oluacls_class(L, "clangwrapper.CXXAccessSpecifier", nullptr);
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_const_integer(L, "InvalidAccessSpecifier", (lua_Integer)clangwrapper::CXXAccessSpecifier::CX_CXXInvalidAccessSpecifier);
    oluacls_const_integer(L, "Private", (lua_Integer)clangwrapper::CXXAccessSpecifier::CX_CXXPrivate);
    oluacls_const_integer(L, "Protected", (lua_Integer)clangwrapper::CXXAccessSpecifier::CX_CXXProtected);
    oluacls_const_integer(L, "Public", (lua_Integer)clangwrapper::CXXAccessSpecifier::CX_CXXPublic);

    olua_registerluatype<clangwrapper::CXXAccessSpecifier>(L, "clangwrapper.CXXAccessSpecifier");

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_DiagnosticSeverity(lua_State *L)
{
    oluacls_class(L, "clangwrapper.DiagnosticSeverity", nullptr);
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_const_integer(L, "Error", (lua_Integer)clangwrapper::DiagnosticSeverity::CXDiagnostic_Error);
    oluacls_const_integer(L, "Fatal", (lua_Integer)clangwrapper::DiagnosticSeverity::CXDiagnostic_Fatal);
    oluacls_const_integer(L, "Ignored", (lua_Integer)clangwrapper::DiagnosticSeverity::CXDiagnostic_Ignored);
    oluacls_const_integer(L, "Note", (lua_Integer)clangwrapper::DiagnosticSeverity::CXDiagnostic_Note);
    oluacls_const_integer(L, "Warning", (lua_Integer)clangwrapper::DiagnosticSeverity::CXDiagnostic_Warning);

    olua_registerluatype<clangwrapper::DiagnosticSeverity>(L, "clangwrapper.DiagnosticSeverity");

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_GlobalOptFlags(lua_State *L)
{
    oluacls_class(L, "clangwrapper.GlobalOptFlags", nullptr);
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_const_integer(L, "None", (lua_Integer)clangwrapper::GlobalOptFlags::CXGlobalOpt_None);
    oluacls_const_integer(L, "ThreadBackgroundPriorityForAll", (lua_Integer)clangwrapper::GlobalOptFlags::CXGlobalOpt_ThreadBackgroundPriorityForAll);
    oluacls_const_integer(L, "ThreadBackgroundPriorityForEditing", (lua_Integer)clangwrapper::GlobalOptFlags::CXGlobalOpt_ThreadBackgroundPriorityForEditing);
    oluacls_const_integer(L, "ThreadBackgroundPriorityForIndexing", (lua_Integer)clangwrapper::GlobalOptFlags::CXGlobalOpt_ThreadBackgroundPriorityForIndexing);

    olua_registerluatype<clangwrapper::GlobalOptFlags>(L, "clangwrapper.GlobalOptFlags");

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_LanguageKind(lua_State *L)
{
    oluacls_class(L, "clangwrapper.LanguageKind", nullptr);
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_const_integer(L, "C", (lua_Integer)clangwrapper::LanguageKind::CXLanguage_C);
    oluacls_const_integer(L, "CPlusPlus", (lua_Integer)clangwrapper::LanguageKind::CXLanguage_CPlusPlus);
    oluacls_const_integer(L, "Invalid", (lua_Integer)clangwrapper::LanguageKind::CXLanguage_Invalid);
    oluacls_const_integer(L, "ObjC", (lua_Integer)clangwrapper::LanguageKind::CXLanguage_ObjC);

    olua_registerluatype<clangwrapper::LanguageKind>(L, "clangwrapper.LanguageKind");

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_LinkageKind(lua_State *L)
{
    oluacls_class(L, "clangwrapper.LinkageKind", nullptr);
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_const_integer(L, "External", (lua_Integer)clangwrapper::LinkageKind::CXLinkage_External);
    oluacls_const_integer(L, "Internal", (lua_Integer)clangwrapper::LinkageKind::CXLinkage_Internal);
    oluacls_const_integer(L, "Invalid", (lua_Integer)clangwrapper::LinkageKind::CXLinkage_Invalid);
    oluacls_const_integer(L, "NoLinkage", (lua_Integer)clangwrapper::LinkageKind::CXLinkage_NoLinkage);
    oluacls_const_integer(L, "UniqueExternal", (lua_Integer)clangwrapper::LinkageKind::CXLinkage_UniqueExternal);

    olua_registerluatype<clangwrapper::LinkageKind>(L, "clangwrapper.LinkageKind");

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_RefQualifierKind(lua_State *L)
{
    oluacls_class(L, "clangwrapper.RefQualifierKind", nullptr);
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_const_integer(L, "LValue", (lua_Integer)clangwrapper::RefQualifierKind::CXRefQualifier_LValue);
    oluacls_const_integer(L, "None", (lua_Integer)clangwrapper::RefQualifierKind::CXRefQualifier_None);
    oluacls_const_integer(L, "RValue", (lua_Integer)clangwrapper::RefQualifierKind::CXRefQualifier_RValue);

    olua_registerluatype<clangwrapper::RefQualifierKind>(L, "clangwrapper.RefQualifierKind");

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_StorageClass(lua_State *L)
{
    oluacls_class(L, "clangwrapper.StorageClass", nullptr);
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_const_integer(L, "Auto", (lua_Integer)clangwrapper::StorageClass::CX_SC_Auto);
    oluacls_const_integer(L, "Extern", (lua_Integer)clangwrapper::StorageClass::CX_SC_Extern);
    oluacls_const_integer(L, "Invalid", (lua_Integer)clangwrapper::StorageClass::CX_SC_Invalid);
    oluacls_const_integer(L, "None", (lua_Integer)clangwrapper::StorageClass::CX_SC_None);
    oluacls_const_integer(L, "OpenCLWorkGroupLocal", (lua_Integer)clangwrapper::StorageClass::CX_SC_OpenCLWorkGroupLocal);
    oluacls_const_integer(L, "PrivateExtern", (lua_Integer)clangwrapper::StorageClass::CX_SC_PrivateExtern);
    oluacls_const_integer(L, "Register", (lua_Integer)clangwrapper::StorageClass::CX_SC_Register);
    oluacls_const_integer(L, "Static", (lua_Integer)clangwrapper::StorageClass::CX_SC_Static);

    olua_registerluatype<clangwrapper::StorageClass>(L, "clangwrapper.StorageClass");

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_TemplateArgumentKind(lua_State *L)
{
    oluacls_class(L, "clangwrapper.TemplateArgumentKind", nullptr);
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_const_integer(L, "Declaration", (lua_Integer)clangwrapper::TemplateArgumentKind::CXTemplateArgumentKind_Declaration);
    oluacls_const_integer(L, "Expression", (lua_Integer)clangwrapper::TemplateArgumentKind::CXTemplateArgumentKind_Expression);
    oluacls_const_integer(L, "Integral", (lua_Integer)clangwrapper::TemplateArgumentKind::CXTemplateArgumentKind_Integral);
    oluacls_const_integer(L, "Invalid", (lua_Integer)clangwrapper::TemplateArgumentKind::CXTemplateArgumentKind_Invalid);
    oluacls_const_integer(L, "Null", (lua_Integer)clangwrapper::TemplateArgumentKind::CXTemplateArgumentKind_Null);
    oluacls_const_integer(L, "NullPtr", (lua_Integer)clangwrapper::TemplateArgumentKind::CXTemplateArgumentKind_NullPtr);
    oluacls_const_integer(L, "Pack", (lua_Integer)clangwrapper::TemplateArgumentKind::CXTemplateArgumentKind_Pack);
    oluacls_const_integer(L, "Template", (lua_Integer)clangwrapper::TemplateArgumentKind::CXTemplateArgumentKind_Template);
    oluacls_const_integer(L, "TemplateExpansion", (lua_Integer)clangwrapper::TemplateArgumentKind::CXTemplateArgumentKind_TemplateExpansion);
    oluacls_const_integer(L, "Type", (lua_Integer)clangwrapper::TemplateArgumentKind::CXTemplateArgumentKind_Type);

    olua_registerluatype<clangwrapper::TemplateArgumentKind>(L, "clangwrapper.TemplateArgumentKind");

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_TLSKind(lua_State *L)
{
    oluacls_class(L, "clangwrapper.TLSKind", nullptr);
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_const_integer(L, "Dynamic", (lua_Integer)clangwrapper::TLSKind::CXTLS_Dynamic);
    oluacls_const_integer(L, "None", (lua_Integer)clangwrapper::TLSKind::CXTLS_None);
    oluacls_const_integer(L, "Static", (lua_Integer)clangwrapper::TLSKind::CXTLS_Static);

    olua_registerluatype<clangwrapper::TLSKind>(L, "clangwrapper.TLSKind");

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_TypeKind(lua_State *L)
{
    oluacls_class(L, "clangwrapper.TypeKind", nullptr);
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_const_integer(L, "Accum", (lua_Integer)clangwrapper::TypeKind::CXType_Accum);
    oluacls_const_integer(L, "Atomic", (lua_Integer)clangwrapper::TypeKind::CXType_Atomic);
    oluacls_const_integer(L, "Attributed", (lua_Integer)clangwrapper::TypeKind::CXType_Attributed);
    oluacls_const_integer(L, "Auto", (lua_Integer)clangwrapper::TypeKind::CXType_Auto);
    oluacls_const_integer(L, "BFloat16", (lua_Integer)clangwrapper::TypeKind::CXType_BFloat16);
    oluacls_const_integer(L, "BTFTagAttributed", (lua_Integer)clangwrapper::TypeKind::CXType_BTFTagAttributed);
    oluacls_const_integer(L, "BlockPointer", (lua_Integer)clangwrapper::TypeKind::CXType_BlockPointer);
    oluacls_const_integer(L, "Bool", (lua_Integer)clangwrapper::TypeKind::CXType_Bool);
    oluacls_const_integer(L, "Char16", (lua_Integer)clangwrapper::TypeKind::CXType_Char16);
    oluacls_const_integer(L, "Char32", (lua_Integer)clangwrapper::TypeKind::CXType_Char32);
    oluacls_const_integer(L, "Char_S", (lua_Integer)clangwrapper::TypeKind::CXType_Char_S);
    oluacls_const_integer(L, "Char_U", (lua_Integer)clangwrapper::TypeKind::CXType_Char_U);
    oluacls_const_integer(L, "Complex", (lua_Integer)clangwrapper::TypeKind::CXType_Complex);
    oluacls_const_integer(L, "ConstantArray", (lua_Integer)clangwrapper::TypeKind::CXType_ConstantArray);
    oluacls_const_integer(L, "Dependent", (lua_Integer)clangwrapper::TypeKind::CXType_Dependent);
    oluacls_const_integer(L, "DependentSizedArray", (lua_Integer)clangwrapper::TypeKind::CXType_DependentSizedArray);
    oluacls_const_integer(L, "Double", (lua_Integer)clangwrapper::TypeKind::CXType_Double);
    oluacls_const_integer(L, "Elaborated", (lua_Integer)clangwrapper::TypeKind::CXType_Elaborated);
    oluacls_const_integer(L, "Enum", (lua_Integer)clangwrapper::TypeKind::CXType_Enum);
    oluacls_const_integer(L, "ExtVector", (lua_Integer)clangwrapper::TypeKind::CXType_ExtVector);
    oluacls_const_integer(L, "FirstBuiltin", (lua_Integer)clangwrapper::TypeKind::CXType_FirstBuiltin);
    oluacls_const_integer(L, "Float", (lua_Integer)clangwrapper::TypeKind::CXType_Float);
    oluacls_const_integer(L, "Float128", (lua_Integer)clangwrapper::TypeKind::CXType_Float128);
    oluacls_const_integer(L, "Float16", (lua_Integer)clangwrapper::TypeKind::CXType_Float16);
    oluacls_const_integer(L, "FunctionNoProto", (lua_Integer)clangwrapper::TypeKind::CXType_FunctionNoProto);
    oluacls_const_integer(L, "FunctionProto", (lua_Integer)clangwrapper::TypeKind::CXType_FunctionProto);
    oluacls_const_integer(L, "Half", (lua_Integer)clangwrapper::TypeKind::CXType_Half);
    oluacls_const_integer(L, "Ibm128", (lua_Integer)clangwrapper::TypeKind::CXType_Ibm128);
    oluacls_const_integer(L, "IncompleteArray", (lua_Integer)clangwrapper::TypeKind::CXType_IncompleteArray);
    oluacls_const_integer(L, "Int", (lua_Integer)clangwrapper::TypeKind::CXType_Int);
    oluacls_const_integer(L, "Int128", (lua_Integer)clangwrapper::TypeKind::CXType_Int128);
    oluacls_const_integer(L, "Invalid", (lua_Integer)clangwrapper::TypeKind::CXType_Invalid);
    oluacls_const_integer(L, "LValueReference", (lua_Integer)clangwrapper::TypeKind::CXType_LValueReference);
    oluacls_const_integer(L, "LastBuiltin", (lua_Integer)clangwrapper::TypeKind::CXType_LastBuiltin);
    oluacls_const_integer(L, "Long", (lua_Integer)clangwrapper::TypeKind::CXType_Long);
    oluacls_const_integer(L, "LongAccum", (lua_Integer)clangwrapper::TypeKind::CXType_LongAccum);
    oluacls_const_integer(L, "LongDouble", (lua_Integer)clangwrapper::TypeKind::CXType_LongDouble);
    oluacls_const_integer(L, "LongLong", (lua_Integer)clangwrapper::TypeKind::CXType_LongLong);
    oluacls_const_integer(L, "MemberPointer", (lua_Integer)clangwrapper::TypeKind::CXType_MemberPointer);
    oluacls_const_integer(L, "NullPtr", (lua_Integer)clangwrapper::TypeKind::CXType_NullPtr);
    oluacls_const_integer(L, "OCLEvent", (lua_Integer)clangwrapper::TypeKind::CXType_OCLEvent);
    oluacls_const_integer(L, "OCLImage1dArrayRO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage1dArrayRO);
    oluacls_const_integer(L, "OCLImage1dArrayRW", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage1dArrayRW);
    oluacls_const_integer(L, "OCLImage1dArrayWO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage1dArrayWO);
    oluacls_const_integer(L, "OCLImage1dBufferRO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage1dBufferRO);
    oluacls_const_integer(L, "OCLImage1dBufferRW", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage1dBufferRW);
    oluacls_const_integer(L, "OCLImage1dBufferWO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage1dBufferWO);
    oluacls_const_integer(L, "OCLImage1dRO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage1dRO);
    oluacls_const_integer(L, "OCLImage1dRW", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage1dRW);
    oluacls_const_integer(L, "OCLImage1dWO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage1dWO);
    oluacls_const_integer(L, "OCLImage2dArrayDepthRO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dArrayDepthRO);
    oluacls_const_integer(L, "OCLImage2dArrayDepthRW", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dArrayDepthRW);
    oluacls_const_integer(L, "OCLImage2dArrayDepthWO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dArrayDepthWO);
    oluacls_const_integer(L, "OCLImage2dArrayMSAADepthRO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dArrayMSAADepthRO);
    oluacls_const_integer(L, "OCLImage2dArrayMSAADepthRW", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dArrayMSAADepthRW);
    oluacls_const_integer(L, "OCLImage2dArrayMSAADepthWO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dArrayMSAADepthWO);
    oluacls_const_integer(L, "OCLImage2dArrayMSAARO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dArrayMSAARO);
    oluacls_const_integer(L, "OCLImage2dArrayMSAARW", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dArrayMSAARW);
    oluacls_const_integer(L, "OCLImage2dArrayMSAAWO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dArrayMSAAWO);
    oluacls_const_integer(L, "OCLImage2dArrayRO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dArrayRO);
    oluacls_const_integer(L, "OCLImage2dArrayRW", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dArrayRW);
    oluacls_const_integer(L, "OCLImage2dArrayWO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dArrayWO);
    oluacls_const_integer(L, "OCLImage2dDepthRO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dDepthRO);
    oluacls_const_integer(L, "OCLImage2dDepthRW", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dDepthRW);
    oluacls_const_integer(L, "OCLImage2dDepthWO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dDepthWO);
    oluacls_const_integer(L, "OCLImage2dMSAADepthRO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dMSAADepthRO);
    oluacls_const_integer(L, "OCLImage2dMSAADepthRW", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dMSAADepthRW);
    oluacls_const_integer(L, "OCLImage2dMSAADepthWO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dMSAADepthWO);
    oluacls_const_integer(L, "OCLImage2dMSAARO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dMSAARO);
    oluacls_const_integer(L, "OCLImage2dMSAARW", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dMSAARW);
    oluacls_const_integer(L, "OCLImage2dMSAAWO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dMSAAWO);
    oluacls_const_integer(L, "OCLImage2dRO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dRO);
    oluacls_const_integer(L, "OCLImage2dRW", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dRW);
    oluacls_const_integer(L, "OCLImage2dWO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dWO);
    oluacls_const_integer(L, "OCLImage3dRO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage3dRO);
    oluacls_const_integer(L, "OCLImage3dRW", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage3dRW);
    oluacls_const_integer(L, "OCLImage3dWO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage3dWO);
    oluacls_const_integer(L, "OCLIntelSubgroupAVCImeDualRefStreamin", (lua_Integer)clangwrapper::TypeKind::CXType_OCLIntelSubgroupAVCImeDualRefStreamin);
    oluacls_const_integer(L, "OCLIntelSubgroupAVCImePayload", (lua_Integer)clangwrapper::TypeKind::CXType_OCLIntelSubgroupAVCImePayload);
    oluacls_const_integer(L, "OCLIntelSubgroupAVCImeResult", (lua_Integer)clangwrapper::TypeKind::CXType_OCLIntelSubgroupAVCImeResult);
    oluacls_const_integer(L, "OCLIntelSubgroupAVCImeResultDualRefStreamout", (lua_Integer)clangwrapper::TypeKind::CXType_OCLIntelSubgroupAVCImeResultDualRefStreamout);
    oluacls_const_integer(L, "OCLIntelSubgroupAVCImeResultSingleRefStreamout", (lua_Integer)clangwrapper::TypeKind::CXType_OCLIntelSubgroupAVCImeResultSingleRefStreamout);
    oluacls_const_integer(L, "OCLIntelSubgroupAVCImeSingleRefStreamin", (lua_Integer)clangwrapper::TypeKind::CXType_OCLIntelSubgroupAVCImeSingleRefStreamin);
    oluacls_const_integer(L, "OCLIntelSubgroupAVCMcePayload", (lua_Integer)clangwrapper::TypeKind::CXType_OCLIntelSubgroupAVCMcePayload);
    oluacls_const_integer(L, "OCLIntelSubgroupAVCMceResult", (lua_Integer)clangwrapper::TypeKind::CXType_OCLIntelSubgroupAVCMceResult);
    oluacls_const_integer(L, "OCLIntelSubgroupAVCRefPayload", (lua_Integer)clangwrapper::TypeKind::CXType_OCLIntelSubgroupAVCRefPayload);
    oluacls_const_integer(L, "OCLIntelSubgroupAVCRefResult", (lua_Integer)clangwrapper::TypeKind::CXType_OCLIntelSubgroupAVCRefResult);
    oluacls_const_integer(L, "OCLIntelSubgroupAVCSicPayload", (lua_Integer)clangwrapper::TypeKind::CXType_OCLIntelSubgroupAVCSicPayload);
    oluacls_const_integer(L, "OCLIntelSubgroupAVCSicResult", (lua_Integer)clangwrapper::TypeKind::CXType_OCLIntelSubgroupAVCSicResult);
    oluacls_const_integer(L, "OCLQueue", (lua_Integer)clangwrapper::TypeKind::CXType_OCLQueue);
    oluacls_const_integer(L, "OCLReserveID", (lua_Integer)clangwrapper::TypeKind::CXType_OCLReserveID);
    oluacls_const_integer(L, "OCLSampler", (lua_Integer)clangwrapper::TypeKind::CXType_OCLSampler);
    oluacls_const_integer(L, "ObjCClass", (lua_Integer)clangwrapper::TypeKind::CXType_ObjCClass);
    oluacls_const_integer(L, "ObjCId", (lua_Integer)clangwrapper::TypeKind::CXType_ObjCId);
    oluacls_const_integer(L, "ObjCInterface", (lua_Integer)clangwrapper::TypeKind::CXType_ObjCInterface);
    oluacls_const_integer(L, "ObjCObject", (lua_Integer)clangwrapper::TypeKind::CXType_ObjCObject);
    oluacls_const_integer(L, "ObjCObjectPointer", (lua_Integer)clangwrapper::TypeKind::CXType_ObjCObjectPointer);
    oluacls_const_integer(L, "ObjCSel", (lua_Integer)clangwrapper::TypeKind::CXType_ObjCSel);
    oluacls_const_integer(L, "ObjCTypeParam", (lua_Integer)clangwrapper::TypeKind::CXType_ObjCTypeParam);
    oluacls_const_integer(L, "Overload", (lua_Integer)clangwrapper::TypeKind::CXType_Overload);
    oluacls_const_integer(L, "Pipe", (lua_Integer)clangwrapper::TypeKind::CXType_Pipe);
    oluacls_const_integer(L, "Pointer", (lua_Integer)clangwrapper::TypeKind::CXType_Pointer);
    oluacls_const_integer(L, "RValueReference", (lua_Integer)clangwrapper::TypeKind::CXType_RValueReference);
    oluacls_const_integer(L, "Record", (lua_Integer)clangwrapper::TypeKind::CXType_Record);
    oluacls_const_integer(L, "SChar", (lua_Integer)clangwrapper::TypeKind::CXType_SChar);
    oluacls_const_integer(L, "Short", (lua_Integer)clangwrapper::TypeKind::CXType_Short);
    oluacls_const_integer(L, "ShortAccum", (lua_Integer)clangwrapper::TypeKind::CXType_ShortAccum);
    oluacls_const_integer(L, "Typedef", (lua_Integer)clangwrapper::TypeKind::CXType_Typedef);
    oluacls_const_integer(L, "UAccum", (lua_Integer)clangwrapper::TypeKind::CXType_UAccum);
    oluacls_const_integer(L, "UChar", (lua_Integer)clangwrapper::TypeKind::CXType_UChar);
    oluacls_const_integer(L, "UInt", (lua_Integer)clangwrapper::TypeKind::CXType_UInt);
    oluacls_const_integer(L, "UInt128", (lua_Integer)clangwrapper::TypeKind::CXType_UInt128);
    oluacls_const_integer(L, "ULong", (lua_Integer)clangwrapper::TypeKind::CXType_ULong);
    oluacls_const_integer(L, "ULongAccum", (lua_Integer)clangwrapper::TypeKind::CXType_ULongAccum);
    oluacls_const_integer(L, "ULongLong", (lua_Integer)clangwrapper::TypeKind::CXType_ULongLong);
    oluacls_const_integer(L, "UShort", (lua_Integer)clangwrapper::TypeKind::CXType_UShort);
    oluacls_const_integer(L, "UShortAccum", (lua_Integer)clangwrapper::TypeKind::CXType_UShortAccum);
    oluacls_const_integer(L, "Unexposed", (lua_Integer)clangwrapper::TypeKind::CXType_Unexposed);
    oluacls_const_integer(L, "VariableArray", (lua_Integer)clangwrapper::TypeKind::CXType_VariableArray);
    oluacls_const_integer(L, "Vector", (lua_Integer)clangwrapper::TypeKind::CXType_Vector);
    oluacls_const_integer(L, "Void", (lua_Integer)clangwrapper::TypeKind::CXType_Void);
    oluacls_const_integer(L, "WChar", (lua_Integer)clangwrapper::TypeKind::CXType_WChar);

    olua_registerluatype<clangwrapper::TypeKind>(L, "clangwrapper.TypeKind");

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_TypeNullabilityKind(lua_State *L)
{
    oluacls_class(L, "clangwrapper.TypeNullabilityKind", nullptr);
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_const_integer(L, "Invalid", (lua_Integer)clangwrapper::TypeNullabilityKind::CXTypeNullability_Invalid);
    oluacls_const_integer(L, "NonNull", (lua_Integer)clangwrapper::TypeNullabilityKind::CXTypeNullability_NonNull);
    oluacls_const_integer(L, "Nullable", (lua_Integer)clangwrapper::TypeNullabilityKind::CXTypeNullability_Nullable);
    oluacls_const_integer(L, "NullableResult", (lua_Integer)clangwrapper::TypeNullabilityKind::CXTypeNullability_NullableResult);
    oluacls_const_integer(L, "Unspecified", (lua_Integer)clangwrapper::TypeNullabilityKind::CXTypeNullability_Unspecified);

    olua_registerluatype<clangwrapper::TypeNullabilityKind>(L, "clangwrapper.TypeNullabilityKind");

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_VisibilityKind(lua_State *L)
{
    oluacls_class(L, "clangwrapper.VisibilityKind", nullptr);
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_const_integer(L, "Default", (lua_Integer)clangwrapper::VisibilityKind::CXVisibility_Default);
    oluacls_const_integer(L, "Hidden", (lua_Integer)clangwrapper::VisibilityKind::CXVisibility_Hidden);
    oluacls_const_integer(L, "Invalid", (lua_Integer)clangwrapper::VisibilityKind::CXVisibility_Invalid);
    oluacls_const_integer(L, "Protected", (lua_Integer)clangwrapper::VisibilityKind::CXVisibility_Protected);

    olua_registerluatype<clangwrapper::VisibilityKind>(L, "clangwrapper.VisibilityKind");

    return 1;
}
OLUA_END_DECLS

static int _clangwrapper_Diagnostic___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (clangwrapper::Diagnostic *)olua_toobj(L, 1, "clangwrapper.Diagnostic");
    olua_push_obj(L, self, "clangwrapper.Diagnostic");

    olua_endinvoke(L);

    return 1;
}

static int _clangwrapper_Diagnostic_as(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Diagnostic *self = nullptr;
    const char *arg1 = nullptr;       /** cls */

    olua_to_obj(L, 1, &self, "clangwrapper.Diagnostic");
    olua_check_string(L, 2, &arg1);

    do {
        if (olua_isa(L, 1, arg1)) {
            lua_pushvalue(L, 1);
            break;
        }
        if (olua_strequal(arg1, "std.enable_shared_from_this")) {
            olua_pushobj_as<std::enable_shared_from_this<clangwrapper::Diagnostic>>(L, 1, self, "as.std.enable_shared_from_this");
            break;
        }

        luaL_error(L, "'clangwrapper::Diagnostic' can't cast to '%s'", arg1);
    } while (0);

    olua_endinvoke(L);

    return 1;
}

static int _clangwrapper_Diagnostic_formatDiagnostic(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Diagnostic *self = nullptr;
    lua_Unsigned arg1 = 0;       /** options */

    olua_to_obj(L, 1, &self, "clangwrapper.Diagnostic");
    olua_check_uint(L, 2, &arg1);

    // clangwrapper::string formatDiagnostic(unsigned int options)
    clangwrapper::string ret = self->formatDiagnostic((unsigned int)arg1);
    int num_ret = olua_push_clangwrapper_string(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Diagnostic_shared_from_this(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Diagnostic *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Diagnostic");

    // @copyfrom(std::enable_shared_from_this<clangwrapper::Diagnostic>) std::shared_ptr<clangwrapper::Diagnostic> shared_from_this()
    std::shared_ptr<clangwrapper::Diagnostic> ret = self->shared_from_this();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Diagnostic");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Diagnostic_category(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Diagnostic *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Diagnostic");

    // @getter unsigned int category()
    unsigned int ret = self->category();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Diagnostic_categoryText(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Diagnostic *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Diagnostic");

    // @getter clangwrapper::string categoryText()
    clangwrapper::string ret = self->categoryText();
    int num_ret = olua_push_clangwrapper_string(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Diagnostic_name(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Diagnostic *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Diagnostic");

    // @getter clangwrapper::string name()
    clangwrapper::string ret = self->name();
    int num_ret = olua_push_clangwrapper_string(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Diagnostic_severity(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Diagnostic *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Diagnostic");

    // @getter clangwrapper::DiagnosticSeverity severity()
    clangwrapper::DiagnosticSeverity ret = self->severity();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Diagnostic_severitySeplling(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Diagnostic *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Diagnostic");

    // @getter clangwrapper::string severitySeplling()
    clangwrapper::string ret = self->severitySeplling();
    int num_ret = olua_push_clangwrapper_string(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Diagnostic_text(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Diagnostic *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Diagnostic");

    // @getter clangwrapper::string text()
    clangwrapper::string ret = self->text();
    int num_ret = olua_push_clangwrapper_string(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_Diagnostic(lua_State *L)
{
    oluacls_class(L, "clangwrapper.Diagnostic", "clangwrapper.IndexError");
    oluacls_func(L, "__olua_move", _clangwrapper_Diagnostic___olua_move);
    oluacls_func(L, "as", _clangwrapper_Diagnostic_as);
    oluacls_func(L, "formatDiagnostic", _clangwrapper_Diagnostic_formatDiagnostic);
    oluacls_func(L, "shared_from_this", _clangwrapper_Diagnostic_shared_from_this);
    oluacls_prop(L, "category", _clangwrapper_Diagnostic_category, nullptr);
    oluacls_prop(L, "categoryText", _clangwrapper_Diagnostic_categoryText, nullptr);
    oluacls_prop(L, "name", _clangwrapper_Diagnostic_name, nullptr);
    oluacls_prop(L, "severity", _clangwrapper_Diagnostic_severity, nullptr);
    oluacls_prop(L, "severitySeplling", _clangwrapper_Diagnostic_severitySeplling, nullptr);
    oluacls_prop(L, "text", _clangwrapper_Diagnostic_text, nullptr);

    olua_registerluatype<clangwrapper::Diagnostic>(L, "clangwrapper.Diagnostic");

    return 1;
}
OLUA_END_DECLS

static int _clangwrapper_File___eq(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::File *self = nullptr;
    clangwrapper::File *arg2 = nullptr;       /** f */

    olua_to_obj(L, 1, &self, "clangwrapper.File");
    olua_check_obj(L, 2, &arg2, "clangwrapper.File");

    // olua_Return __eq(lua_State *L, clangwrapper::File *f)
    olua_Return ret = self->__eq(L, arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _clangwrapper_File___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (clangwrapper::File *)olua_toobj(L, 1, "clangwrapper.File");
    olua_push_obj(L, self, "clangwrapper.File");

    olua_endinvoke(L);

    return 1;
}

static int _clangwrapper_File_as(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::File *self = nullptr;
    const char *arg1 = nullptr;       /** cls */

    olua_to_obj(L, 1, &self, "clangwrapper.File");
    olua_check_string(L, 2, &arg1);

    do {
        if (olua_isa(L, 1, arg1)) {
            lua_pushvalue(L, 1);
            break;
        }
        if (olua_strequal(arg1, "std.enable_shared_from_this")) {
            olua_pushobj_as<std::enable_shared_from_this<clangwrapper::File>>(L, 1, self, "as.std.enable_shared_from_this");
            break;
        }

        luaL_error(L, "'clangwrapper::File' can't cast to '%s'", arg1);
    } while (0);

    olua_endinvoke(L);

    return 1;
}

static int _clangwrapper_File_shared_from_this(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::File *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.File");

    // @copyfrom(std::enable_shared_from_this<clangwrapper::File>) std::shared_ptr<clangwrapper::File> shared_from_this()
    std::shared_ptr<clangwrapper::File> ret = self->shared_from_this();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.File");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_File_tryGetRealPathName(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::File *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.File");

    // clangwrapper::string tryGetRealPathName()
    clangwrapper::string ret = self->tryGetRealPathName();
    int num_ret = olua_push_clangwrapper_string(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_File_fileName(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::File *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.File");

    // @getter clangwrapper::string fileName()
    clangwrapper::string ret = self->fileName();
    int num_ret = olua_push_clangwrapper_string(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_File_fileTime(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::File *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.File");

    // @getter time_t fileTime()
    time_t ret = self->fileTime();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_File(lua_State *L)
{
    oluacls_class(L, "clangwrapper.File", "clangwrapper.IndexError");
    oluacls_func(L, "__eq", _clangwrapper_File___eq);
    oluacls_func(L, "__olua_move", _clangwrapper_File___olua_move);
    oluacls_func(L, "as", _clangwrapper_File_as);
    oluacls_func(L, "shared_from_this", _clangwrapper_File_shared_from_this);
    oluacls_func(L, "tryGetRealPathName", _clangwrapper_File_tryGetRealPathName);
    oluacls_prop(L, "fileName", _clangwrapper_File_fileName, nullptr);
    oluacls_prop(L, "fileTime", _clangwrapper_File_fileTime, nullptr);

    olua_registerluatype<clangwrapper::File>(L, "clangwrapper.File");

    return 1;
}
OLUA_END_DECLS

static int _clangwrapper_Type___eq(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;
    clangwrapper::Type *arg2 = nullptr;       /** t */

    olua_to_obj(L, 1, &self, "clangwrapper.Type");
    olua_check_obj(L, 2, &arg2, "clangwrapper.Type");

    // olua_Return __eq(lua_State *L, clangwrapper::Type *t)
    olua_Return ret = self->__eq(L, arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _clangwrapper_Type___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (clangwrapper::Type *)olua_toobj(L, 1, "clangwrapper.Type");
    olua_push_obj(L, self, "clangwrapper.Type");

    olua_endinvoke(L);

    return 1;
}

static int _clangwrapper_Type_as(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;
    const char *arg1 = nullptr;       /** cls */

    olua_to_obj(L, 1, &self, "clangwrapper.Type");
    olua_check_string(L, 2, &arg1);

    do {
        if (olua_isa(L, 1, arg1)) {
            lua_pushvalue(L, 1);
            break;
        }
        if (olua_strequal(arg1, "std.enable_shared_from_this")) {
            olua_pushobj_as<std::enable_shared_from_this<clangwrapper::Type>>(L, 1, self, "as.std.enable_shared_from_this");
            break;
        }

        luaL_error(L, "'clangwrapper::Type' can't cast to '%s'", arg1);
    } while (0);

    olua_endinvoke(L);

    return 1;
}

static int _clangwrapper_Type_offsetOf(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;
    const char *arg1 = nullptr;       /** field */

    olua_to_obj(L, 1, &self, "clangwrapper.Type");
    olua_check_string(L, 2, &arg1);

    // long long offsetOf(const char *field)
    long long ret = self->offsetOf(arg1);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_shared_from_this(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Type");

    // @copyfrom(std::enable_shared_from_this<clangwrapper::Type>) std::shared_ptr<clangwrapper::Type> shared_from_this()
    std::shared_ptr<clangwrapper::Type> ret = self->shared_from_this();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Type");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_addressSpace(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Type");

    // @getter unsigned int addressSpace()
    unsigned int ret = self->addressSpace();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_alignOf(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Type");

    // @getter long long alignOf()
    long long ret = self->alignOf();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_argTypes(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Type");

    // @getter std::vector<std::shared_ptr<clangwrapper::Type>> argTypes()
    std::vector<std::shared_ptr<clangwrapper::Type>> ret = self->argTypes();
    int num_ret = olua_push_array<std::shared_ptr<clangwrapper::Type>>(L, &ret, [L](std::shared_ptr<clangwrapper::Type> &value) {
        olua_push_obj(L, &value, "clangwrapper.Type");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_arrayElementType(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Type");

    // @getter std::shared_ptr<clangwrapper::Type> arrayElementType()
    std::shared_ptr<clangwrapper::Type> ret = self->arrayElementType();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Type");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_arraySize(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Type");

    // @getter long long arraySize()
    long long ret = self->arraySize();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_canonicalType(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Type");

    // @getter std::shared_ptr<clangwrapper::Type> canonicalType()
    std::shared_ptr<clangwrapper::Type> ret = self->canonicalType();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Type");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_classType(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Type");

    // @getter std::shared_ptr<clangwrapper::Type> classType()
    std::shared_ptr<clangwrapper::Type> ret = self->classType();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Type");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_cxxRefQualifier(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Type");

    // @getter clangwrapper::RefQualifierKind cxxRefQualifier()
    clangwrapper::RefQualifierKind ret = self->cxxRefQualifier();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_cxxRefQualifierSpelling(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Type");

    // @getter clangwrapper::string cxxRefQualifierSpelling()
    clangwrapper::string ret = self->cxxRefQualifierSpelling();
    int num_ret = olua_push_clangwrapper_string(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_declaration(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Type");

    // @getter std::shared_ptr<clangwrapper::Cursor> declaration()
    std::shared_ptr<clangwrapper::Cursor> ret = self->declaration();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Cursor");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_elementType(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Type");

    // @getter std::shared_ptr<clangwrapper::Type> elementType()
    std::shared_ptr<clangwrapper::Type> ret = self->elementType();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Type");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_exceptionSpecificationType(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Type");

    // @getter int exceptionSpecificationType()
    int ret = self->exceptionSpecificationType();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_fields(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Type");

    // @getter std::vector<std::shared_ptr<clangwrapper::Cursor>> fields()
    std::vector<std::shared_ptr<clangwrapper::Cursor>> ret = self->fields();
    int num_ret = olua_push_array<std::shared_ptr<clangwrapper::Cursor>>(L, &ret, [L](std::shared_ptr<clangwrapper::Cursor> &value) {
        olua_push_obj(L, &value, "clangwrapper.Cursor");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_functionTypeCallingConv(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Type");

    // @getter clangwrapper::CallingConv functionTypeCallingConv()
    clangwrapper::CallingConv ret = self->functionTypeCallingConv();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_functionTypeCallingConvSpelling(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Type");

    // @getter clangwrapper::string functionTypeCallingConvSpelling()
    clangwrapper::string ret = self->functionTypeCallingConvSpelling();
    int num_ret = olua_push_clangwrapper_string(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_isConstQualified(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Type");

    // @getter bool isConstQualified()
    bool ret = self->isConstQualified();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_isFunctionTypeVariadic(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Type");

    // @getter bool isFunctionTypeVariadic()
    bool ret = self->isFunctionTypeVariadic();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_isPOD(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Type");

    // @getter bool isPOD()
    bool ret = self->isPOD();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_isRestrictQualified(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Type");

    // @getter bool isRestrictQualified()
    bool ret = self->isRestrictQualified();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_isTransparentTagTypedef(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Type");

    // @getter bool isTransparentTagTypedef()
    bool ret = self->isTransparentTagTypedef();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_isVolatileQualified(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Type");

    // @getter bool isVolatileQualified()
    bool ret = self->isVolatileQualified();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_kind(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Type");

    // @getter clangwrapper::TypeKind kind()
    clangwrapper::TypeKind ret = self->kind();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_kindSpelling(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Type");

    // @getter clangwrapper::string kindSpelling()
    clangwrapper::string ret = self->kindSpelling();
    int num_ret = olua_push_clangwrapper_string(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_modifiedType(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Type");

    // @getter std::shared_ptr<clangwrapper::Type> modifiedType()
    std::shared_ptr<clangwrapper::Type> ret = self->modifiedType();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Type");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_name(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Type");

    // @getter clangwrapper::string name()
    clangwrapper::string ret = self->name();
    int num_ret = olua_push_clangwrapper_string(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_nonReferenceType(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Type");

    // @getter std::shared_ptr<clangwrapper::Type> nonReferenceType()
    std::shared_ptr<clangwrapper::Type> ret = self->nonReferenceType();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Type");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_nullability(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Type");

    // @getter clangwrapper::TypeNullabilityKind nullability()
    clangwrapper::TypeNullabilityKind ret = self->nullability();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_nullabilitySpelling(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Type");

    // @getter clangwrapper::string nullabilitySpelling()
    clangwrapper::string ret = self->nullabilitySpelling();
    int num_ret = olua_push_clangwrapper_string(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_numElements(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Type");

    // @getter long long numElements()
    long long ret = self->numElements();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_pointeeType(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Type");

    // @getter std::shared_ptr<clangwrapper::Type> pointeeType()
    std::shared_ptr<clangwrapper::Type> ret = self->pointeeType();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Type");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_resultType(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Type");

    // @getter std::shared_ptr<clangwrapper::Type> resultType()
    std::shared_ptr<clangwrapper::Type> ret = self->resultType();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Type");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_sizeOf(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Type");

    // @getter long long sizeOf()
    long long ret = self->sizeOf();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_templateArgumentTypes(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Type");

    // @getter std::vector<std::shared_ptr<clangwrapper::Type>> templateArgumentTypes()
    std::vector<std::shared_ptr<clangwrapper::Type>> ret = self->templateArgumentTypes();
    int num_ret = olua_push_array<std::shared_ptr<clangwrapper::Type>>(L, &ret, [L](std::shared_ptr<clangwrapper::Type> &value) {
        olua_push_obj(L, &value, "clangwrapper.Type");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_typedefName(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Type");

    // @getter clangwrapper::string typedefName()
    clangwrapper::string ret = self->typedefName();
    int num_ret = olua_push_clangwrapper_string(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_unqualifiedType(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Type");

    // @getter std::shared_ptr<clangwrapper::Type> unqualifiedType()
    std::shared_ptr<clangwrapper::Type> ret = self->unqualifiedType();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Type");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_valueType(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Type");

    // @getter std::shared_ptr<clangwrapper::Type> valueType()
    std::shared_ptr<clangwrapper::Type> ret = self->valueType();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Type");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_Type(lua_State *L)
{
    oluacls_class(L, "clangwrapper.Type", "clangwrapper.IndexError");
    oluacls_func(L, "__eq", _clangwrapper_Type___eq);
    oluacls_func(L, "__olua_move", _clangwrapper_Type___olua_move);
    oluacls_func(L, "as", _clangwrapper_Type_as);
    oluacls_func(L, "offsetOf", _clangwrapper_Type_offsetOf);
    oluacls_func(L, "shared_from_this", _clangwrapper_Type_shared_from_this);
    oluacls_prop(L, "addressSpace", _clangwrapper_Type_addressSpace, nullptr);
    oluacls_prop(L, "alignOf", _clangwrapper_Type_alignOf, nullptr);
    oluacls_prop(L, "argTypes", _clangwrapper_Type_argTypes, nullptr);
    oluacls_prop(L, "arrayElementType", _clangwrapper_Type_arrayElementType, nullptr);
    oluacls_prop(L, "arraySize", _clangwrapper_Type_arraySize, nullptr);
    oluacls_prop(L, "canonicalType", _clangwrapper_Type_canonicalType, nullptr);
    oluacls_prop(L, "classType", _clangwrapper_Type_classType, nullptr);
    oluacls_prop(L, "cxxRefQualifier", _clangwrapper_Type_cxxRefQualifier, nullptr);
    oluacls_prop(L, "cxxRefQualifierSpelling", _clangwrapper_Type_cxxRefQualifierSpelling, nullptr);
    oluacls_prop(L, "declaration", _clangwrapper_Type_declaration, nullptr);
    oluacls_prop(L, "elementType", _clangwrapper_Type_elementType, nullptr);
    oluacls_prop(L, "exceptionSpecificationType", _clangwrapper_Type_exceptionSpecificationType, nullptr);
    oluacls_prop(L, "fields", _clangwrapper_Type_fields, nullptr);
    oluacls_prop(L, "functionTypeCallingConv", _clangwrapper_Type_functionTypeCallingConv, nullptr);
    oluacls_prop(L, "functionTypeCallingConvSpelling", _clangwrapper_Type_functionTypeCallingConvSpelling, nullptr);
    oluacls_prop(L, "isConstQualified", _clangwrapper_Type_isConstQualified, nullptr);
    oluacls_prop(L, "isFunctionTypeVariadic", _clangwrapper_Type_isFunctionTypeVariadic, nullptr);
    oluacls_prop(L, "isPOD", _clangwrapper_Type_isPOD, nullptr);
    oluacls_prop(L, "isRestrictQualified", _clangwrapper_Type_isRestrictQualified, nullptr);
    oluacls_prop(L, "isTransparentTagTypedef", _clangwrapper_Type_isTransparentTagTypedef, nullptr);
    oluacls_prop(L, "isVolatileQualified", _clangwrapper_Type_isVolatileQualified, nullptr);
    oluacls_prop(L, "kind", _clangwrapper_Type_kind, nullptr);
    oluacls_prop(L, "kindSpelling", _clangwrapper_Type_kindSpelling, nullptr);
    oluacls_prop(L, "modifiedType", _clangwrapper_Type_modifiedType, nullptr);
    oluacls_prop(L, "name", _clangwrapper_Type_name, nullptr);
    oluacls_prop(L, "nonReferenceType", _clangwrapper_Type_nonReferenceType, nullptr);
    oluacls_prop(L, "nullability", _clangwrapper_Type_nullability, nullptr);
    oluacls_prop(L, "nullabilitySpelling", _clangwrapper_Type_nullabilitySpelling, nullptr);
    oluacls_prop(L, "numElements", _clangwrapper_Type_numElements, nullptr);
    oluacls_prop(L, "pointeeType", _clangwrapper_Type_pointeeType, nullptr);
    oluacls_prop(L, "resultType", _clangwrapper_Type_resultType, nullptr);
    oluacls_prop(L, "sizeOf", _clangwrapper_Type_sizeOf, nullptr);
    oluacls_prop(L, "templateArgumentTypes", _clangwrapper_Type_templateArgumentTypes, nullptr);
    oluacls_prop(L, "typedefName", _clangwrapper_Type_typedefName, nullptr);
    oluacls_prop(L, "unqualifiedType", _clangwrapper_Type_unqualifiedType, nullptr);
    oluacls_prop(L, "valueType", _clangwrapper_Type_valueType, nullptr);

    olua_registerluatype<clangwrapper::Type>(L, "clangwrapper.Type");

    return 1;
}
OLUA_END_DECLS

static int _clangwrapper_Cursor___eq(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;
    clangwrapper::Cursor *arg2 = nullptr;       /** c */

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");
    olua_check_obj(L, 2, &arg2, "clangwrapper.Cursor");

    // olua_Return __eq(lua_State *L, clangwrapper::Cursor *c)
    olua_Return ret = self->__eq(L, arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _clangwrapper_Cursor___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (clangwrapper::Cursor *)olua_toobj(L, 1, "clangwrapper.Cursor");
    olua_push_obj(L, self, "clangwrapper.Cursor");

    olua_endinvoke(L);

    return 1;
}

static int _clangwrapper_Cursor_as(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;
    const char *arg1 = nullptr;       /** cls */

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");
    olua_check_string(L, 2, &arg1);

    do {
        if (olua_isa(L, 1, arg1)) {
            lua_pushvalue(L, 1);
            break;
        }
        if (olua_strequal(arg1, "std.enable_shared_from_this")) {
            olua_pushobj_as<std::enable_shared_from_this<clangwrapper::Cursor>>(L, 1, self, "as.std.enable_shared_from_this");
            break;
        }

        luaL_error(L, "'clangwrapper::Cursor' can't cast to '%s'", arg1);
    } while (0);

    olua_endinvoke(L);

    return 1;
}

static int _clangwrapper_Cursor_getModule(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // std::shared_ptr<clangwrapper::Module> getModule()
    std::shared_ptr<clangwrapper::Module> ret = self->getModule();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Module");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_hashCursor(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // unsigned int hashCursor()
    unsigned int ret = self->hashCursor();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_nameRange(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;
    lua_Unsigned arg1 = 0;       /** pieceIndex */
    lua_Unsigned arg2 = 0;       /** options */

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // clangwrapper::Cursor::SourceRange nameRange(unsigned int pieceIndex, unsigned int options)
    clangwrapper::Cursor::SourceRange ret = self->nameRange((unsigned int)arg1, (unsigned int)arg2);
    int num_ret = olua_push_clangwrapper_Cursor_SourceRange(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_referenceNameRange(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;
    lua_Unsigned arg1 = 0;       /** pieceIndex */
    lua_Unsigned arg2 = 0;       /** options */

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // clangwrapper::Cursor::SourceRange referenceNameRange(unsigned int pieceIndex, unsigned int options)
    clangwrapper::Cursor::SourceRange ret = self->referenceNameRange((unsigned int)arg1, (unsigned int)arg2);
    int num_ret = olua_push_clangwrapper_Cursor_SourceRange(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_shared_from_this(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @copyfrom(std::enable_shared_from_this<clangwrapper::Cursor>) std::shared_ptr<clangwrapper::Cursor> shared_from_this()
    std::shared_ptr<clangwrapper::Cursor> ret = self->shared_from_this();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Cursor");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_templateArgumentKind(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;
    lua_Unsigned arg1 = 0;       /** index */

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");
    olua_check_uint(L, 2, &arg1);

    // clangwrapper::TemplateArgumentKind templateArgumentKind(unsigned int index)
    clangwrapper::TemplateArgumentKind ret = self->templateArgumentKind((unsigned int)arg1);
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_templateArgumentKindSpelling(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;
    lua_Unsigned arg1 = 0;       /** index */

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");
    olua_check_uint(L, 2, &arg1);

    // clangwrapper::string templateArgumentKindSpelling(unsigned int index)
    clangwrapper::string ret = self->templateArgumentKindSpelling((unsigned int)arg1);
    int num_ret = olua_push_clangwrapper_string(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_templateArgumentUnsignedValue(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;
    lua_Unsigned arg1 = 0;       /** index */

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");
    olua_check_uint(L, 2, &arg1);

    // unsigned long long templateArgumentUnsignedValue(unsigned int index)
    unsigned long long ret = self->templateArgumentUnsignedValue((unsigned int)arg1);
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_templateArgumentValue(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;
    lua_Unsigned arg1 = 0;       /** index */

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");
    olua_check_uint(L, 2, &arg1);

    // long long templateArgumentValue(unsigned int index)
    long long ret = self->templateArgumentValue((unsigned int)arg1);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_arguments(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter std::vector<std::shared_ptr<clangwrapper::Cursor>> arguments()
    std::vector<std::shared_ptr<clangwrapper::Cursor>> ret = self->arguments();
    int num_ret = olua_push_array<std::shared_ptr<clangwrapper::Cursor>>(L, &ret, [L](std::shared_ptr<clangwrapper::Cursor> &value) {
        olua_push_obj(L, &value, "clangwrapper.Cursor");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_availability(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter clangwrapper::AvailabilityKind availability()
    clangwrapper::AvailabilityKind ret = self->availability();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_availabilitySpelling(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter clangwrapper::string availabilitySpelling()
    clangwrapper::string ret = self->availabilitySpelling();
    int num_ret = olua_push_clangwrapper_string(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_briefCommentText(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter clangwrapper::string briefCommentText()
    clangwrapper::string ret = self->briefCommentText();
    int num_ret = olua_push_clangwrapper_string(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_canonical(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter std::shared_ptr<clangwrapper::Cursor> canonical()
    std::shared_ptr<clangwrapper::Cursor> ret = self->canonical();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Cursor");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_children(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter std::vector<std::shared_ptr<clangwrapper::Cursor>> children()
    std::vector<std::shared_ptr<clangwrapper::Cursor>> ret = self->children();
    int num_ret = olua_push_array<std::shared_ptr<clangwrapper::Cursor>>(L, &ret, [L](std::shared_ptr<clangwrapper::Cursor> &value) {
        olua_push_obj(L, &value, "clangwrapper.Cursor");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_commentRange(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter clangwrapper::Cursor::SourceRange commentRange()
    clangwrapper::Cursor::SourceRange ret = self->commentRange();
    int num_ret = olua_push_clangwrapper_Cursor_SourceRange(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_cxxAccessSpecifier(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter clangwrapper::CXXAccessSpecifier cxxAccessSpecifier()
    clangwrapper::CXXAccessSpecifier ret = self->cxxAccessSpecifier();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_cxxAccessSpecifierSpelling(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter clangwrapper::string cxxAccessSpecifierSpelling()
    clangwrapper::string ret = self->cxxAccessSpecifierSpelling();
    int num_ret = olua_push_clangwrapper_string(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_cxxManglings(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter std::vector<clangwrapper::string> cxxManglings()
    std::vector<clangwrapper::string> ret = self->cxxManglings();
    int num_ret = olua_push_array<clangwrapper::string>(L, &ret, [L](clangwrapper::string &value) {
        olua_push_clangwrapper_string(L, &value);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_definition(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter std::shared_ptr<clangwrapper::Cursor> definition()
    std::shared_ptr<clangwrapper::Cursor> ret = self->definition();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Cursor");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_displayName(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter clangwrapper::string displayName()
    clangwrapper::string ret = self->displayName();
    int num_ret = olua_push_clangwrapper_string(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_enumConstantDeclUnsignedValue(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter unsigned long long enumConstantDeclUnsignedValue()
    unsigned long long ret = self->enumConstantDeclUnsignedValue();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_enumConstantDeclValue(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter long long enumConstantDeclValue()
    long long ret = self->enumConstantDeclValue();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_enumDeclIntegerType(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter std::shared_ptr<clangwrapper::Type> enumDeclIntegerType()
    std::shared_ptr<clangwrapper::Type> ret = self->enumDeclIntegerType();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Type");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_exceptionSpecificationType(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter int exceptionSpecificationType()
    int ret = self->exceptionSpecificationType();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_fieldDeclBitWidth(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter int fieldDeclBitWidth()
    int ret = self->fieldDeclBitWidth();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_hasAttrs(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter bool hasAttrs()
    bool ret = self->hasAttrs();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_hasVarDeclExternalStorage(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter int hasVarDeclExternalStorage()
    int ret = self->hasVarDeclExternalStorage();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_hasVarDeclGlobalStorage(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter int hasVarDeclGlobalStorage()
    int ret = self->hasVarDeclGlobalStorage();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_ibOutletCollectionType(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter std::shared_ptr<clangwrapper::Type> ibOutletCollectionType()
    std::shared_ptr<clangwrapper::Type> ret = self->ibOutletCollectionType();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Type");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_includedFile(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter std::shared_ptr<clangwrapper::File> includedFile()
    std::shared_ptr<clangwrapper::File> ret = self->includedFile();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.File");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isAnonymous(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter bool isAnonymous()
    bool ret = self->isAnonymous();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isAnonymousRecordDecl(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter bool isAnonymousRecordDecl()
    bool ret = self->isAnonymousRecordDecl();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isAttribute(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter bool isAttribute()
    bool ret = self->isAttribute();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isBitField(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter bool isBitField()
    bool ret = self->isBitField();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isCXXConvertingConstructor(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter bool isCXXConvertingConstructor()
    bool ret = self->isCXXConvertingConstructor();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isCXXCopyConstructor(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter bool isCXXCopyConstructor()
    bool ret = self->isCXXCopyConstructor();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isCXXDefaultConstructor(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter bool isCXXDefaultConstructor()
    bool ret = self->isCXXDefaultConstructor();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isCXXFieldMutable(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter bool isCXXFieldMutable()
    bool ret = self->isCXXFieldMutable();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isCXXMethoAbstract(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter bool isCXXMethoAbstract()
    bool ret = self->isCXXMethoAbstract();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isCXXMethoConst(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter bool isCXXMethoConst()
    bool ret = self->isCXXMethoConst();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isCXXMethoCopyAssignmentOperator(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter bool isCXXMethoCopyAssignmentOperator()
    bool ret = self->isCXXMethoCopyAssignmentOperator();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isCXXMethoDeleted(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter bool isCXXMethoDeleted()
    bool ret = self->isCXXMethoDeleted();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isCXXMethoPureVirtual(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter bool isCXXMethoPureVirtual()
    bool ret = self->isCXXMethoPureVirtual();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isCXXMethoStatic(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter bool isCXXMethoStatic()
    bool ret = self->isCXXMethoStatic();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isCXXMethoVirtual(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter bool isCXXMethoVirtual()
    bool ret = self->isCXXMethoVirtual();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isCXXMethodDefaulted(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter bool isCXXMethodDefaulted()
    bool ret = self->isCXXMethodDefaulted();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isCXXMoveConstructor(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter bool isCXXMoveConstructor()
    bool ret = self->isCXXMoveConstructor();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isDeclaration(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter bool isDeclaration()
    bool ret = self->isDeclaration();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isDefinition(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter bool isDefinition()
    bool ret = self->isDefinition();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isDeprecated(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter bool isDeprecated()
    bool ret = self->isDeprecated();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isDynamicCall(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter int isDynamicCall()
    int ret = self->isDynamicCall();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isEnumDeclScoped(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter bool isEnumDeclScoped()
    bool ret = self->isEnumDeclScoped();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isExpression(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter bool isExpression()
    bool ret = self->isExpression();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isFunctionInlined(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter bool isFunctionInlined()
    bool ret = self->isFunctionInlined();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isInlineNamespace(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter bool isInlineNamespace()
    bool ret = self->isInlineNamespace();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isInvalid(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter bool isInvalid()
    bool ret = self->isInvalid();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isInvalidDeclaration(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter bool isInvalidDeclaration()
    bool ret = self->isInvalidDeclaration();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isMacroBuiltin(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter bool isMacroBuiltin()
    bool ret = self->isMacroBuiltin();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isMacroFunctionLike(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter bool isMacroFunctionLike()
    bool ret = self->isMacroFunctionLike();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isNull(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter bool isNull()
    bool ret = self->isNull();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isPreprocessing(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter bool isPreprocessing()
    bool ret = self->isPreprocessing();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isReference(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter bool isReference()
    bool ret = self->isReference();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isStatement(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter bool isStatement()
    bool ret = self->isStatement();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isTranslationUnit(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter bool isTranslationUnit()
    bool ret = self->isTranslationUnit();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isUnexposed(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter bool isUnexposed()
    bool ret = self->isUnexposed();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isVariadic(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter bool isVariadic()
    bool ret = self->isVariadic();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isVirtualBase(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter bool isVirtualBase()
    bool ret = self->isVirtualBase();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_kind(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter clangwrapper::CursorKind kind()
    clangwrapper::CursorKind ret = self->kind();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_kindSpelling(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter clangwrapper::string kindSpelling()
    clangwrapper::string ret = self->kindSpelling();
    int num_ret = olua_push_clangwrapper_string(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_language(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter clangwrapper::LanguageKind language()
    clangwrapper::LanguageKind ret = self->language();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_languageSpelling(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter clangwrapper::string languageSpelling()
    clangwrapper::string ret = self->languageSpelling();
    int num_ret = olua_push_clangwrapper_string(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_lexicalParent(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter std::shared_ptr<clangwrapper::Cursor> lexicalParent()
    std::shared_ptr<clangwrapper::Cursor> ret = self->lexicalParent();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Cursor");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_linkage(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter clangwrapper::LinkageKind linkage()
    clangwrapper::LinkageKind ret = self->linkage();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_linkageSpelling(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter clangwrapper::string linkageSpelling()
    clangwrapper::string ret = self->linkageSpelling();
    int num_ret = olua_push_clangwrapper_string(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_mangling(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter clangwrapper::string mangling()
    clangwrapper::string ret = self->mangling();
    int num_ret = olua_push_clangwrapper_string(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_name(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter clangwrapper::string name()
    clangwrapper::string ret = self->name();
    int num_ret = olua_push_clangwrapper_string(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_offsetOfField(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter long long offsetOfField()
    long long ret = self->offsetOfField();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_overloadedDecls(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter std::vector<std::shared_ptr<clangwrapper::Cursor>> overloadedDecls()
    std::vector<std::shared_ptr<clangwrapper::Cursor>> ret = self->overloadedDecls();
    int num_ret = olua_push_array<std::shared_ptr<clangwrapper::Cursor>>(L, &ret, [L](std::shared_ptr<clangwrapper::Cursor> &value) {
        olua_push_obj(L, &value, "clangwrapper.Cursor");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_parent(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter std::shared_ptr<clangwrapper::Cursor> parent()
    std::shared_ptr<clangwrapper::Cursor> ret = self->parent();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Cursor");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_prettyPrinted(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter clangwrapper::string prettyPrinted()
    clangwrapper::string ret = self->prettyPrinted();
    int num_ret = olua_push_clangwrapper_string(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_rawCommentText(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter clangwrapper::string rawCommentText()
    clangwrapper::string ret = self->rawCommentText();
    int num_ret = olua_push_clangwrapper_string(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_receiverType(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter std::shared_ptr<clangwrapper::Type> receiverType()
    std::shared_ptr<clangwrapper::Type> ret = self->receiverType();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Type");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_referenced(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter std::shared_ptr<clangwrapper::Cursor> referenced()
    std::shared_ptr<clangwrapper::Cursor> ret = self->referenced();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Cursor");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_resultType(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter std::shared_ptr<clangwrapper::Type> resultType()
    std::shared_ptr<clangwrapper::Type> ret = self->resultType();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Type");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_semanticParent(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter std::shared_ptr<clangwrapper::Cursor> semanticParent()
    std::shared_ptr<clangwrapper::Cursor> ret = self->semanticParent();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Cursor");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_sourceLocation(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter clangwrapper::Cursor::SourceLocation sourceLocation()
    clangwrapper::Cursor::SourceLocation ret = self->sourceLocation();
    int num_ret = olua_push_clangwrapper_Cursor_SourceLocation(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_sourceRange(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter clangwrapper::Cursor::SourceRange sourceRange()
    clangwrapper::Cursor::SourceRange ret = self->sourceRange();
    int num_ret = olua_push_clangwrapper_Cursor_SourceRange(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_specializedTemplate(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter std::shared_ptr<clangwrapper::Cursor> specializedTemplate()
    std::shared_ptr<clangwrapper::Cursor> ret = self->specializedTemplate();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Cursor");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_storageClass(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter clangwrapper::StorageClass storageClass()
    clangwrapper::StorageClass ret = self->storageClass();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_storageClassSpelling(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter clangwrapper::string storageClassSpelling()
    clangwrapper::string ret = self->storageClassSpelling();
    int num_ret = olua_push_clangwrapper_string(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_templateArgumentTypes(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter std::vector<std::shared_ptr<clangwrapper::Type>> templateArgumentTypes()
    std::vector<std::shared_ptr<clangwrapper::Type>> ret = self->templateArgumentTypes();
    int num_ret = olua_push_array<std::shared_ptr<clangwrapper::Type>>(L, &ret, [L](std::shared_ptr<clangwrapper::Type> &value) {
        olua_push_obj(L, &value, "clangwrapper.Type");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_templateKind(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter clangwrapper::CursorKind templateKind()
    clangwrapper::CursorKind ret = self->templateKind();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_templateKindSpelling(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter clangwrapper::string templateKindSpelling()
    clangwrapper::string ret = self->templateKindSpelling();
    int num_ret = olua_push_clangwrapper_string(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_tlsKind(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter clangwrapper::TLSKind tlsKind()
    clangwrapper::TLSKind ret = self->tlsKind();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_tlsKindSpelling(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter clangwrapper::string tlsKindSpelling()
    clangwrapper::string ret = self->tlsKindSpelling();
    int num_ret = olua_push_clangwrapper_string(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_translationUnit(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter std::shared_ptr<clangwrapper::TranslationUnit> translationUnit()
    std::shared_ptr<clangwrapper::TranslationUnit> ret = self->translationUnit();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.TranslationUnit");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_type(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter std::shared_ptr<clangwrapper::Type> type()
    std::shared_ptr<clangwrapper::Type> ret = self->type();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Type");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_underlyingType(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter std::shared_ptr<clangwrapper::Type> underlyingType()
    std::shared_ptr<clangwrapper::Type> ret = self->underlyingType();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Type");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_varDeclInitializer(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter std::shared_ptr<clangwrapper::Cursor> varDeclInitializer()
    std::shared_ptr<clangwrapper::Cursor> ret = self->varDeclInitializer();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Cursor");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_visibility(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter clangwrapper::VisibilityKind visibility()
    clangwrapper::VisibilityKind ret = self->visibility();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_visibilitySpelling(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Cursor");

    // @getter clangwrapper::string visibilitySpelling()
    clangwrapper::string ret = self->visibilitySpelling();
    int num_ret = olua_push_clangwrapper_string(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_Cursor(lua_State *L)
{
    oluacls_class(L, "clangwrapper.Cursor", "clangwrapper.IndexError");
    oluacls_func(L, "__eq", _clangwrapper_Cursor___eq);
    oluacls_func(L, "__olua_move", _clangwrapper_Cursor___olua_move);
    oluacls_func(L, "as", _clangwrapper_Cursor_as);
    oluacls_func(L, "getModule", _clangwrapper_Cursor_getModule);
    oluacls_func(L, "hashCursor", _clangwrapper_Cursor_hashCursor);
    oluacls_func(L, "nameRange", _clangwrapper_Cursor_nameRange);
    oluacls_func(L, "referenceNameRange", _clangwrapper_Cursor_referenceNameRange);
    oluacls_func(L, "shared_from_this", _clangwrapper_Cursor_shared_from_this);
    oluacls_func(L, "templateArgumentKind", _clangwrapper_Cursor_templateArgumentKind);
    oluacls_func(L, "templateArgumentKindSpelling", _clangwrapper_Cursor_templateArgumentKindSpelling);
    oluacls_func(L, "templateArgumentUnsignedValue", _clangwrapper_Cursor_templateArgumentUnsignedValue);
    oluacls_func(L, "templateArgumentValue", _clangwrapper_Cursor_templateArgumentValue);
    oluacls_prop(L, "arguments", _clangwrapper_Cursor_arguments, nullptr);
    oluacls_prop(L, "availability", _clangwrapper_Cursor_availability, nullptr);
    oluacls_prop(L, "availabilitySpelling", _clangwrapper_Cursor_availabilitySpelling, nullptr);
    oluacls_prop(L, "briefCommentText", _clangwrapper_Cursor_briefCommentText, nullptr);
    oluacls_prop(L, "canonical", _clangwrapper_Cursor_canonical, nullptr);
    oluacls_prop(L, "children", _clangwrapper_Cursor_children, nullptr);
    oluacls_prop(L, "commentRange", _clangwrapper_Cursor_commentRange, nullptr);
    oluacls_prop(L, "cxxAccessSpecifier", _clangwrapper_Cursor_cxxAccessSpecifier, nullptr);
    oluacls_prop(L, "cxxAccessSpecifierSpelling", _clangwrapper_Cursor_cxxAccessSpecifierSpelling, nullptr);
    oluacls_prop(L, "cxxManglings", _clangwrapper_Cursor_cxxManglings, nullptr);
    oluacls_prop(L, "definition", _clangwrapper_Cursor_definition, nullptr);
    oluacls_prop(L, "displayName", _clangwrapper_Cursor_displayName, nullptr);
    oluacls_prop(L, "enumConstantDeclUnsignedValue", _clangwrapper_Cursor_enumConstantDeclUnsignedValue, nullptr);
    oluacls_prop(L, "enumConstantDeclValue", _clangwrapper_Cursor_enumConstantDeclValue, nullptr);
    oluacls_prop(L, "enumDeclIntegerType", _clangwrapper_Cursor_enumDeclIntegerType, nullptr);
    oluacls_prop(L, "exceptionSpecificationType", _clangwrapper_Cursor_exceptionSpecificationType, nullptr);
    oluacls_prop(L, "fieldDeclBitWidth", _clangwrapper_Cursor_fieldDeclBitWidth, nullptr);
    oluacls_prop(L, "hasAttrs", _clangwrapper_Cursor_hasAttrs, nullptr);
    oluacls_prop(L, "hasVarDeclExternalStorage", _clangwrapper_Cursor_hasVarDeclExternalStorage, nullptr);
    oluacls_prop(L, "hasVarDeclGlobalStorage", _clangwrapper_Cursor_hasVarDeclGlobalStorage, nullptr);
    oluacls_prop(L, "ibOutletCollectionType", _clangwrapper_Cursor_ibOutletCollectionType, nullptr);
    oluacls_prop(L, "includedFile", _clangwrapper_Cursor_includedFile, nullptr);
    oluacls_prop(L, "isAnonymous", _clangwrapper_Cursor_isAnonymous, nullptr);
    oluacls_prop(L, "isAnonymousRecordDecl", _clangwrapper_Cursor_isAnonymousRecordDecl, nullptr);
    oluacls_prop(L, "isAttribute", _clangwrapper_Cursor_isAttribute, nullptr);
    oluacls_prop(L, "isBitField", _clangwrapper_Cursor_isBitField, nullptr);
    oluacls_prop(L, "isCXXConvertingConstructor", _clangwrapper_Cursor_isCXXConvertingConstructor, nullptr);
    oluacls_prop(L, "isCXXCopyConstructor", _clangwrapper_Cursor_isCXXCopyConstructor, nullptr);
    oluacls_prop(L, "isCXXDefaultConstructor", _clangwrapper_Cursor_isCXXDefaultConstructor, nullptr);
    oluacls_prop(L, "isCXXFieldMutable", _clangwrapper_Cursor_isCXXFieldMutable, nullptr);
    oluacls_prop(L, "isCXXMethoAbstract", _clangwrapper_Cursor_isCXXMethoAbstract, nullptr);
    oluacls_prop(L, "isCXXMethoConst", _clangwrapper_Cursor_isCXXMethoConst, nullptr);
    oluacls_prop(L, "isCXXMethoCopyAssignmentOperator", _clangwrapper_Cursor_isCXXMethoCopyAssignmentOperator, nullptr);
    oluacls_prop(L, "isCXXMethoDeleted", _clangwrapper_Cursor_isCXXMethoDeleted, nullptr);
    oluacls_prop(L, "isCXXMethoPureVirtual", _clangwrapper_Cursor_isCXXMethoPureVirtual, nullptr);
    oluacls_prop(L, "isCXXMethoStatic", _clangwrapper_Cursor_isCXXMethoStatic, nullptr);
    oluacls_prop(L, "isCXXMethoVirtual", _clangwrapper_Cursor_isCXXMethoVirtual, nullptr);
    oluacls_prop(L, "isCXXMethodDefaulted", _clangwrapper_Cursor_isCXXMethodDefaulted, nullptr);
    oluacls_prop(L, "isCXXMoveConstructor", _clangwrapper_Cursor_isCXXMoveConstructor, nullptr);
    oluacls_prop(L, "isDeclaration", _clangwrapper_Cursor_isDeclaration, nullptr);
    oluacls_prop(L, "isDefinition", _clangwrapper_Cursor_isDefinition, nullptr);
    oluacls_prop(L, "isDeprecated", _clangwrapper_Cursor_isDeprecated, nullptr);
    oluacls_prop(L, "isDynamicCall", _clangwrapper_Cursor_isDynamicCall, nullptr);
    oluacls_prop(L, "isEnumDeclScoped", _clangwrapper_Cursor_isEnumDeclScoped, nullptr);
    oluacls_prop(L, "isExpression", _clangwrapper_Cursor_isExpression, nullptr);
    oluacls_prop(L, "isFunctionInlined", _clangwrapper_Cursor_isFunctionInlined, nullptr);
    oluacls_prop(L, "isInlineNamespace", _clangwrapper_Cursor_isInlineNamespace, nullptr);
    oluacls_prop(L, "isInvalid", _clangwrapper_Cursor_isInvalid, nullptr);
    oluacls_prop(L, "isInvalidDeclaration", _clangwrapper_Cursor_isInvalidDeclaration, nullptr);
    oluacls_prop(L, "isMacroBuiltin", _clangwrapper_Cursor_isMacroBuiltin, nullptr);
    oluacls_prop(L, "isMacroFunctionLike", _clangwrapper_Cursor_isMacroFunctionLike, nullptr);
    oluacls_prop(L, "isNull", _clangwrapper_Cursor_isNull, nullptr);
    oluacls_prop(L, "isPreprocessing", _clangwrapper_Cursor_isPreprocessing, nullptr);
    oluacls_prop(L, "isReference", _clangwrapper_Cursor_isReference, nullptr);
    oluacls_prop(L, "isStatement", _clangwrapper_Cursor_isStatement, nullptr);
    oluacls_prop(L, "isTranslationUnit", _clangwrapper_Cursor_isTranslationUnit, nullptr);
    oluacls_prop(L, "isUnexposed", _clangwrapper_Cursor_isUnexposed, nullptr);
    oluacls_prop(L, "isVariadic", _clangwrapper_Cursor_isVariadic, nullptr);
    oluacls_prop(L, "isVirtualBase", _clangwrapper_Cursor_isVirtualBase, nullptr);
    oluacls_prop(L, "kind", _clangwrapper_Cursor_kind, nullptr);
    oluacls_prop(L, "kindSpelling", _clangwrapper_Cursor_kindSpelling, nullptr);
    oluacls_prop(L, "language", _clangwrapper_Cursor_language, nullptr);
    oluacls_prop(L, "languageSpelling", _clangwrapper_Cursor_languageSpelling, nullptr);
    oluacls_prop(L, "lexicalParent", _clangwrapper_Cursor_lexicalParent, nullptr);
    oluacls_prop(L, "linkage", _clangwrapper_Cursor_linkage, nullptr);
    oluacls_prop(L, "linkageSpelling", _clangwrapper_Cursor_linkageSpelling, nullptr);
    oluacls_prop(L, "mangling", _clangwrapper_Cursor_mangling, nullptr);
    oluacls_prop(L, "module", _clangwrapper_Cursor_getModule, nullptr);
    oluacls_prop(L, "name", _clangwrapper_Cursor_name, nullptr);
    oluacls_prop(L, "offsetOfField", _clangwrapper_Cursor_offsetOfField, nullptr);
    oluacls_prop(L, "overloadedDecls", _clangwrapper_Cursor_overloadedDecls, nullptr);
    oluacls_prop(L, "parent", _clangwrapper_Cursor_parent, nullptr);
    oluacls_prop(L, "prettyPrinted", _clangwrapper_Cursor_prettyPrinted, nullptr);
    oluacls_prop(L, "rawCommentText", _clangwrapper_Cursor_rawCommentText, nullptr);
    oluacls_prop(L, "receiverType", _clangwrapper_Cursor_receiverType, nullptr);
    oluacls_prop(L, "referenced", _clangwrapper_Cursor_referenced, nullptr);
    oluacls_prop(L, "resultType", _clangwrapper_Cursor_resultType, nullptr);
    oluacls_prop(L, "semanticParent", _clangwrapper_Cursor_semanticParent, nullptr);
    oluacls_prop(L, "sourceLocation", _clangwrapper_Cursor_sourceLocation, nullptr);
    oluacls_prop(L, "sourceRange", _clangwrapper_Cursor_sourceRange, nullptr);
    oluacls_prop(L, "specializedTemplate", _clangwrapper_Cursor_specializedTemplate, nullptr);
    oluacls_prop(L, "storageClass", _clangwrapper_Cursor_storageClass, nullptr);
    oluacls_prop(L, "storageClassSpelling", _clangwrapper_Cursor_storageClassSpelling, nullptr);
    oluacls_prop(L, "templateArgumentTypes", _clangwrapper_Cursor_templateArgumentTypes, nullptr);
    oluacls_prop(L, "templateKind", _clangwrapper_Cursor_templateKind, nullptr);
    oluacls_prop(L, "templateKindSpelling", _clangwrapper_Cursor_templateKindSpelling, nullptr);
    oluacls_prop(L, "tlsKind", _clangwrapper_Cursor_tlsKind, nullptr);
    oluacls_prop(L, "tlsKindSpelling", _clangwrapper_Cursor_tlsKindSpelling, nullptr);
    oluacls_prop(L, "translationUnit", _clangwrapper_Cursor_translationUnit, nullptr);
    oluacls_prop(L, "type", _clangwrapper_Cursor_type, nullptr);
    oluacls_prop(L, "underlyingType", _clangwrapper_Cursor_underlyingType, nullptr);
    oluacls_prop(L, "varDeclInitializer", _clangwrapper_Cursor_varDeclInitializer, nullptr);
    oluacls_prop(L, "visibility", _clangwrapper_Cursor_visibility, nullptr);
    oluacls_prop(L, "visibilitySpelling", _clangwrapper_Cursor_visibilitySpelling, nullptr);

    olua_registerluatype<clangwrapper::Cursor>(L, "clangwrapper.Cursor");

    return 1;
}
OLUA_END_DECLS

static int _clangwrapper_Module___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (clangwrapper::Module *)olua_toobj(L, 1, "clangwrapper.Module");
    olua_push_obj(L, self, "clangwrapper.Module");

    olua_endinvoke(L);

    return 1;
}

static int _clangwrapper_Module_as(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Module *self = nullptr;
    const char *arg1 = nullptr;       /** cls */

    olua_to_obj(L, 1, &self, "clangwrapper.Module");
    olua_check_string(L, 2, &arg1);

    do {
        if (olua_isa(L, 1, arg1)) {
            lua_pushvalue(L, 1);
            break;
        }
        if (olua_strequal(arg1, "std.enable_shared_from_this")) {
            olua_pushobj_as<std::enable_shared_from_this<clangwrapper::Module>>(L, 1, self, "as.std.enable_shared_from_this");
            break;
        }

        luaL_error(L, "'clangwrapper::Module' can't cast to '%s'", arg1);
    } while (0);

    olua_endinvoke(L);

    return 1;
}

static int _clangwrapper_Module_shared_from_this(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Module *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Module");

    // @copyfrom(std::enable_shared_from_this<clangwrapper::Module>) std::shared_ptr<clangwrapper::Module> shared_from_this()
    std::shared_ptr<clangwrapper::Module> ret = self->shared_from_this();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Module");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Module_astFile(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Module *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Module");

    // @getter std::shared_ptr<clangwrapper::File> astFile()
    std::shared_ptr<clangwrapper::File> ret = self->astFile();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.File");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Module_fullName(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Module *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Module");

    // @getter clangwrapper::string fullName()
    clangwrapper::string ret = self->fullName();
    int num_ret = olua_push_clangwrapper_string(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Module_isSystem(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Module *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Module");

    // @getter int isSystem()
    int ret = self->isSystem();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Module_name(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Module *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Module");

    // @getter clangwrapper::string name()
    clangwrapper::string ret = self->name();
    int num_ret = olua_push_clangwrapper_string(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Module_parent(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Module *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Module");

    // @getter std::shared_ptr<clangwrapper::Module> parent()
    std::shared_ptr<clangwrapper::Module> ret = self->parent();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Module");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_Module(lua_State *L)
{
    oluacls_class(L, "clangwrapper.Module", "clangwrapper.IndexError");
    oluacls_func(L, "__olua_move", _clangwrapper_Module___olua_move);
    oluacls_func(L, "as", _clangwrapper_Module_as);
    oluacls_func(L, "shared_from_this", _clangwrapper_Module_shared_from_this);
    oluacls_prop(L, "astFile", _clangwrapper_Module_astFile, nullptr);
    oluacls_prop(L, "fullName", _clangwrapper_Module_fullName, nullptr);
    oluacls_prop(L, "isSystem", _clangwrapper_Module_isSystem, nullptr);
    oluacls_prop(L, "name", _clangwrapper_Module_name, nullptr);
    oluacls_prop(L, "parent", _clangwrapper_Module_parent, nullptr);

    olua_registerluatype<clangwrapper::Module>(L, "clangwrapper.Module");

    return 1;
}
OLUA_END_DECLS

static int _clangwrapper_TranslationUnit___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (clangwrapper::TranslationUnit *)olua_toobj(L, 1, "clangwrapper.TranslationUnit");
    olua_push_obj(L, self, "clangwrapper.TranslationUnit");

    olua_endinvoke(L);

    return 1;
}

static int _clangwrapper_TranslationUnit_as(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::TranslationUnit *self = nullptr;
    const char *arg1 = nullptr;       /** cls */

    olua_to_obj(L, 1, &self, "clangwrapper.TranslationUnit");
    olua_check_string(L, 2, &arg1);

    do {
        if (olua_isa(L, 1, arg1)) {
            lua_pushvalue(L, 1);
            break;
        }
        if (olua_strequal(arg1, "std.enable_shared_from_this")) {
            olua_pushobj_as<std::enable_shared_from_this<clangwrapper::TranslationUnit>>(L, 1, self, "as.std.enable_shared_from_this");
            break;
        }

        luaL_error(L, "'clangwrapper::TranslationUnit' can't cast to '%s'", arg1);
    } while (0);

    olua_endinvoke(L);

    return 1;
}

static int _clangwrapper_TranslationUnit_defaultReparseOptions(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::TranslationUnit *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.TranslationUnit");

    // unsigned int defaultReparseOptions()
    unsigned int ret = self->defaultReparseOptions();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_TranslationUnit_defaultSaveOptions(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::TranslationUnit *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.TranslationUnit");

    // unsigned int defaultSaveOptions()
    unsigned int ret = self->defaultSaveOptions();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_TranslationUnit_getFile(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::TranslationUnit *self = nullptr;
    std::string arg1;       /** path */

    olua_to_obj(L, 1, &self, "clangwrapper.TranslationUnit");
    olua_check_std_string(L, 2, &arg1);

    // std::shared_ptr<clangwrapper::File> getFile(const std::string &path)
    std::shared_ptr<clangwrapper::File> ret = self->getFile(arg1);
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.File");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_TranslationUnit_getFileContents(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::TranslationUnit *self = nullptr;
    clangwrapper::File *arg1 = nullptr;       /** f */

    olua_to_obj(L, 1, &self, "clangwrapper.TranslationUnit");
    olua_check_obj(L, 2, &arg1, "clangwrapper.File");

    // clangwrapper::string getFileContents(clangwrapper::File *f)
    clangwrapper::string ret = self->getFileContents(arg1);
    int num_ret = olua_push_clangwrapper_string(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_TranslationUnit_isFileMultipleIncludeGuarded(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::TranslationUnit *self = nullptr;
    clangwrapper::File *arg1 = nullptr;       /** f */

    olua_to_obj(L, 1, &self, "clangwrapper.TranslationUnit");
    olua_check_obj(L, 2, &arg1, "clangwrapper.File");

    // bool isFileMultipleIncludeGuarded(clangwrapper::File *f)
    bool ret = self->isFileMultipleIncludeGuarded(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_TranslationUnit_moduleForFile(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::TranslationUnit *self = nullptr;
    std::shared_ptr<clangwrapper::File> arg1;       /** file */

    olua_to_obj(L, 1, &self, "clangwrapper.TranslationUnit");
    olua_check_obj(L, 2, &arg1, "clangwrapper.File");

    // std::shared_ptr<clangwrapper::Module> moduleForFile(const std::shared_ptr<clangwrapper::File> &file)
    std::shared_ptr<clangwrapper::Module> ret = self->moduleForFile(arg1);
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Module");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_TranslationUnit_numTopLevelHeaders(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::TranslationUnit *self = nullptr;
    std::shared_ptr<clangwrapper::Module> arg1;       /** m */

    olua_to_obj(L, 1, &self, "clangwrapper.TranslationUnit");
    olua_check_obj(L, 2, &arg1, "clangwrapper.Module");

    // unsigned int numTopLevelHeaders(const std::shared_ptr<clangwrapper::Module> &m)
    unsigned int ret = self->numTopLevelHeaders(arg1);
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_TranslationUnit_saveTranslationUnit(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::TranslationUnit *self = nullptr;
    std::string arg1;       /** path */
    lua_Unsigned arg2 = 0;       /** options */

    olua_to_obj(L, 1, &self, "clangwrapper.TranslationUnit");
    olua_check_std_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // int saveTranslationUnit(const std::string &path, unsigned int options)
    int ret = self->saveTranslationUnit(arg1, (unsigned int)arg2);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_TranslationUnit_shared_from_this(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::TranslationUnit *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.TranslationUnit");

    // @copyfrom(std::enable_shared_from_this<clangwrapper::TranslationUnit>) std::shared_ptr<clangwrapper::TranslationUnit> shared_from_this()
    std::shared_ptr<clangwrapper::TranslationUnit> ret = self->shared_from_this();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.TranslationUnit");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_TranslationUnit_suspendTranslationUnit(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::TranslationUnit *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.TranslationUnit");

    // unsigned int suspendTranslationUnit()
    unsigned int ret = self->suspendTranslationUnit();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_TranslationUnit_topLevelHeader(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::TranslationUnit *self = nullptr;
    std::shared_ptr<clangwrapper::Module> arg1;       /** m */
    lua_Unsigned arg2 = 0;       /** index */

    olua_to_obj(L, 1, &self, "clangwrapper.TranslationUnit");
    olua_check_obj(L, 2, &arg1, "clangwrapper.Module");
    olua_check_uint(L, 3, &arg2);

    // std::shared_ptr<clangwrapper::File> topLevelHeader(const std::shared_ptr<clangwrapper::Module> &m, unsigned int index)
    std::shared_ptr<clangwrapper::File> ret = self->topLevelHeader(arg1, (unsigned int)arg2);
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.File");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_TranslationUnit_cursor(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::TranslationUnit *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.TranslationUnit");

    // @getter std::shared_ptr<clangwrapper::Cursor> cursor()
    std::shared_ptr<clangwrapper::Cursor> ret = self->cursor();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Cursor");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_TranslationUnit_diagnosticSetFromTU(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::TranslationUnit *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.TranslationUnit");

    // @getter std::set<std::shared_ptr<clangwrapper::Diagnostic>> diagnosticSetFromTU()
    std::set<std::shared_ptr<clangwrapper::Diagnostic>> ret = self->diagnosticSetFromTU();
    int num_ret = olua_push_array<std::shared_ptr<clangwrapper::Diagnostic>>(L, &ret, [L](std::shared_ptr<clangwrapper::Diagnostic> &value) {
        olua_push_obj(L, &value, "clangwrapper.Diagnostic");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_TranslationUnit_diagnostics(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::TranslationUnit *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.TranslationUnit");

    // @getter std::vector<std::shared_ptr<clangwrapper::Diagnostic>> diagnostics()
    std::vector<std::shared_ptr<clangwrapper::Diagnostic>> ret = self->diagnostics();
    int num_ret = olua_push_array<std::shared_ptr<clangwrapper::Diagnostic>>(L, &ret, [L](std::shared_ptr<clangwrapper::Diagnostic> &value) {
        olua_push_obj(L, &value, "clangwrapper.Diagnostic");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_TranslationUnit_name(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::TranslationUnit *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.TranslationUnit");

    // @getter clangwrapper::string name()
    clangwrapper::string ret = self->name();
    int num_ret = olua_push_clangwrapper_string(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_TranslationUnit(lua_State *L)
{
    oluacls_class(L, "clangwrapper.TranslationUnit", "clangwrapper.IndexError");
    oluacls_func(L, "__olua_move", _clangwrapper_TranslationUnit___olua_move);
    oluacls_func(L, "as", _clangwrapper_TranslationUnit_as);
    oluacls_func(L, "defaultReparseOptions", _clangwrapper_TranslationUnit_defaultReparseOptions);
    oluacls_func(L, "defaultSaveOptions", _clangwrapper_TranslationUnit_defaultSaveOptions);
    oluacls_func(L, "getFile", _clangwrapper_TranslationUnit_getFile);
    oluacls_func(L, "getFileContents", _clangwrapper_TranslationUnit_getFileContents);
    oluacls_func(L, "isFileMultipleIncludeGuarded", _clangwrapper_TranslationUnit_isFileMultipleIncludeGuarded);
    oluacls_func(L, "moduleForFile", _clangwrapper_TranslationUnit_moduleForFile);
    oluacls_func(L, "numTopLevelHeaders", _clangwrapper_TranslationUnit_numTopLevelHeaders);
    oluacls_func(L, "saveTranslationUnit", _clangwrapper_TranslationUnit_saveTranslationUnit);
    oluacls_func(L, "shared_from_this", _clangwrapper_TranslationUnit_shared_from_this);
    oluacls_func(L, "suspendTranslationUnit", _clangwrapper_TranslationUnit_suspendTranslationUnit);
    oluacls_func(L, "topLevelHeader", _clangwrapper_TranslationUnit_topLevelHeader);
    oluacls_prop(L, "cursor", _clangwrapper_TranslationUnit_cursor, nullptr);
    oluacls_prop(L, "diagnosticSetFromTU", _clangwrapper_TranslationUnit_diagnosticSetFromTU, nullptr);
    oluacls_prop(L, "diagnostics", _clangwrapper_TranslationUnit_diagnostics, nullptr);
    oluacls_prop(L, "name", _clangwrapper_TranslationUnit_name, nullptr);

    olua_registerluatype<clangwrapper::TranslationUnit>(L, "clangwrapper.TranslationUnit");

    return 1;
}
OLUA_END_DECLS

static int _clangwrapper_Index___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (clangwrapper::Index *)olua_toobj(L, 1, "clangwrapper.Index");
    olua_push_obj(L, self, "clangwrapper.Index");

    olua_endinvoke(L);

    return 1;
}

static int _clangwrapper_Index_as(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Index *self = nullptr;
    const char *arg1 = nullptr;       /** cls */

    olua_to_obj(L, 1, &self, "clangwrapper.Index");
    olua_check_string(L, 2, &arg1);

    do {
        if (olua_isa(L, 1, arg1)) {
            lua_pushvalue(L, 1);
            break;
        }
        if (olua_strequal(arg1, "std.enable_shared_from_this")) {
            olua_pushobj_as<std::enable_shared_from_this<clangwrapper::Index>>(L, 1, self, "as.std.enable_shared_from_this");
            break;
        }

        luaL_error(L, "'clangwrapper::Index' can't cast to '%s'", arg1);
    } while (0);

    olua_endinvoke(L);

    return 1;
}

static int _clangwrapper_Index_create(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Index *self = nullptr;
    std::string arg1;       /** path */

    olua_to_obj(L, 1, &self, "clangwrapper.Index");
    olua_check_std_string(L, 2, &arg1);

    // std::shared_ptr<clangwrapper::TranslationUnit> create(const std::string &path)
    std::shared_ptr<clangwrapper::TranslationUnit> ret = self->create(arg1);
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.TranslationUnit");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Index_getGlobalOptions(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Index *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Index");

    // unsigned int getGlobalOptions()
    unsigned int ret = self->getGlobalOptions();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Index_parse1(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Index *self = nullptr;
    std::string arg1;       /** path */
    std::vector<std::string> arg2;       /** args */
    lua_Unsigned arg3 = 0;       /** options */

    olua_to_obj(L, 1, &self, "clangwrapper.Index");
    olua_check_std_string(L, 2, &arg1);
    olua_check_array<std::string>(L, 3, &arg2, [L](std::string *value) {
        olua_check_std_string(L, -1, value);
    });
    olua_check_uint(L, 4, &arg3);

    // std::shared_ptr<clangwrapper::TranslationUnit> parse(const std::string &path, const std::vector<std::string> args, @optional unsigned int options)
    std::shared_ptr<clangwrapper::TranslationUnit> ret = self->parse(arg1, arg2, (unsigned int)arg3);
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.TranslationUnit");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Index_parse2(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Index *self = nullptr;
    std::string arg1;       /** path */
    std::vector<std::string> arg2;       /** args */

    olua_to_obj(L, 1, &self, "clangwrapper.Index");
    olua_check_std_string(L, 2, &arg1);
    olua_check_array<std::string>(L, 3, &arg2, [L](std::string *value) {
        olua_check_std_string(L, -1, value);
    });

    // std::shared_ptr<clangwrapper::TranslationUnit> parse(const std::string &path, const std::vector<std::string> args, @optional unsigned int options)
    std::shared_ptr<clangwrapper::TranslationUnit> ret = self->parse(arg1, arg2);
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.TranslationUnit");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Index_parse(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_array(L, 3))) {
            // std::shared_ptr<clangwrapper::TranslationUnit> parse(const std::string &path, const std::vector<std::string> args, @optional unsigned int options)
            return _clangwrapper_Index_parse2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_array(L, 3)) && (olua_is_uint(L, 4))) {
            // std::shared_ptr<clangwrapper::TranslationUnit> parse(const std::string &path, const std::vector<std::string> args, @optional unsigned int options)
            return _clangwrapper_Index_parse1(L);
        // }
    }

    luaL_error(L, "method 'clangwrapper::Index::parse' not support '%d' arguments", num_args);

    return 0;
}

static int _clangwrapper_Index_setGlobalOptions(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Index *self = nullptr;
    lua_Unsigned arg1 = 0;       /** options */

    olua_to_obj(L, 1, &self, "clangwrapper.Index");
    olua_check_uint(L, 2, &arg1);

    // void setGlobalOptions(unsigned int options)
    self->setGlobalOptions((unsigned int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _clangwrapper_Index_setInvocationEmissionPathOption(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Index *self = nullptr;
    std::string arg1;       /** path */

    olua_to_obj(L, 1, &self, "clangwrapper.Index");
    olua_check_std_string(L, 2, &arg1);

    // void setInvocationEmissionPathOption(const std::string &path)
    self->setInvocationEmissionPathOption(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _clangwrapper_Index_shared_from_this(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Index *self = nullptr;

    olua_to_obj(L, 1, &self, "clangwrapper.Index");

    // @copyfrom(std::enable_shared_from_this<clangwrapper::Index>) std::shared_ptr<clangwrapper::Index> shared_from_this()
    std::shared_ptr<clangwrapper::Index> ret = self->shared_from_this();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Index");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_Index(lua_State *L)
{
    oluacls_class(L, "clangwrapper.Index", "clangwrapper.IndexError");
    oluacls_func(L, "__olua_move", _clangwrapper_Index___olua_move);
    oluacls_func(L, "as", _clangwrapper_Index_as);
    oluacls_func(L, "create", _clangwrapper_Index_create);
    oluacls_func(L, "getGlobalOptions", _clangwrapper_Index_getGlobalOptions);
    oluacls_func(L, "parse", _clangwrapper_Index_parse);
    oluacls_func(L, "setGlobalOptions", _clangwrapper_Index_setGlobalOptions);
    oluacls_func(L, "setInvocationEmissionPathOption", _clangwrapper_Index_setInvocationEmissionPathOption);
    oluacls_func(L, "shared_from_this", _clangwrapper_Index_shared_from_this);
    oluacls_prop(L, "globalOptions", _clangwrapper_Index_getGlobalOptions, _clangwrapper_Index_setGlobalOptions);

    olua_registerluatype<clangwrapper::Index>(L, "clangwrapper.Index");

    return 1;
}
OLUA_END_DECLS

static int _clangwrapper_clang___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (clangwrapper::clang *)olua_toobj(L, 1, "clangwrapper.clang");
    olua_push_obj(L, self, "clangwrapper.clang");

    olua_endinvoke(L);

    return 1;
}

static int _clangwrapper_clang_createIndex(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** excludeDeclarationsFromPCH */
    bool arg2 = false;       /** displayDiagnostics */

    olua_check_bool(L, 1, &arg1);
    olua_check_bool(L, 2, &arg2);

    // static std::shared_ptr<clangwrapper::Index> createIndex(bool excludeDeclarationsFromPCH, bool displayDiagnostics)
    std::shared_ptr<clangwrapper::Index> ret = clangwrapper::clang::createIndex(arg1, arg2);
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Index");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_clang_version(lua_State *L)
{
    olua_startinvoke(L);

    // @getter static const std::string version()
    const std::string ret = clangwrapper::clang::version();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_clang_get_debug(lua_State *L)
{
    olua_startinvoke(L);

    // static bool debug
    bool ret = clangwrapper::clang::debug;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_clang_set_debug(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** debug */

    olua_check_bool(L, 1, &arg1);

    // static bool debug
    clangwrapper::clang::debug = arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_clang(lua_State *L)
{
    oluacls_class(L, "clangwrapper.clang", nullptr);
    oluacls_func(L, "__olua_move", _clangwrapper_clang___olua_move);
    oluacls_func(L, "createIndex", _clangwrapper_clang_createIndex);
    oluacls_prop(L, "version", _clangwrapper_clang_version, nullptr);
    oluacls_prop(L, "debug", _clangwrapper_clang_get_debug, _clangwrapper_clang_set_debug);

    olua_registerluatype<clangwrapper::clang>(L, "clangwrapper.clang");

    return 1;
}
OLUA_END_DECLS

static int _std_enable_shared_from_this_clangwrapper_Diagnostic___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (std::enable_shared_from_this<clangwrapper::Diagnostic> *)olua_toobj(L, 1, "std.enable_shared_from_this<clangwrapper.Diagnostic>");
    olua_push_obj(L, self, "std.enable_shared_from_this<clangwrapper.Diagnostic>");

    olua_endinvoke(L);

    return 1;
}

static int _std_enable_shared_from_this_clangwrapper_Diagnostic_shared_from_this(lua_State *L)
{
    olua_startinvoke(L);

    std::enable_shared_from_this<clangwrapper::Diagnostic> *self = nullptr;

    olua_to_obj(L, 1, &self, "std.enable_shared_from_this<clangwrapper.Diagnostic>");

    // std::shared_ptr<clangwrapper::Diagnostic> shared_from_this()
    std::shared_ptr<clangwrapper::Diagnostic> ret = self->shared_from_this();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Diagnostic");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_std_enable_shared_from_this_clangwrapper_Diagnostic(lua_State *L)
{
    oluacls_class(L, "std.enable_shared_from_this<clangwrapper.Diagnostic>", nullptr);
    oluacls_func(L, "__olua_move", _std_enable_shared_from_this_clangwrapper_Diagnostic___olua_move);
    oluacls_func(L, "shared_from_this", _std_enable_shared_from_this_clangwrapper_Diagnostic_shared_from_this);

    olua_registerluatype<std::enable_shared_from_this<clangwrapper::Diagnostic>>(L, "std.enable_shared_from_this<clangwrapper.Diagnostic>");

    return 1;
}
OLUA_END_DECLS

static int _std_enable_shared_from_this_clangwrapper_File___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (std::enable_shared_from_this<clangwrapper::File> *)olua_toobj(L, 1, "std.enable_shared_from_this<clangwrapper.File>");
    olua_push_obj(L, self, "std.enable_shared_from_this<clangwrapper.File>");

    olua_endinvoke(L);

    return 1;
}

static int _std_enable_shared_from_this_clangwrapper_File_shared_from_this(lua_State *L)
{
    olua_startinvoke(L);

    std::enable_shared_from_this<clangwrapper::File> *self = nullptr;

    olua_to_obj(L, 1, &self, "std.enable_shared_from_this<clangwrapper.File>");

    // std::shared_ptr<clangwrapper::File> shared_from_this()
    std::shared_ptr<clangwrapper::File> ret = self->shared_from_this();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.File");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_std_enable_shared_from_this_clangwrapper_File(lua_State *L)
{
    oluacls_class(L, "std.enable_shared_from_this<clangwrapper.File>", nullptr);
    oluacls_func(L, "__olua_move", _std_enable_shared_from_this_clangwrapper_File___olua_move);
    oluacls_func(L, "shared_from_this", _std_enable_shared_from_this_clangwrapper_File_shared_from_this);

    olua_registerluatype<std::enable_shared_from_this<clangwrapper::File>>(L, "std.enable_shared_from_this<clangwrapper.File>");

    return 1;
}
OLUA_END_DECLS

static int _std_enable_shared_from_this_clangwrapper_Type___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (std::enable_shared_from_this<clangwrapper::Type> *)olua_toobj(L, 1, "std.enable_shared_from_this<clangwrapper.Type>");
    olua_push_obj(L, self, "std.enable_shared_from_this<clangwrapper.Type>");

    olua_endinvoke(L);

    return 1;
}

static int _std_enable_shared_from_this_clangwrapper_Type_shared_from_this(lua_State *L)
{
    olua_startinvoke(L);

    std::enable_shared_from_this<clangwrapper::Type> *self = nullptr;

    olua_to_obj(L, 1, &self, "std.enable_shared_from_this<clangwrapper.Type>");

    // std::shared_ptr<clangwrapper::Type> shared_from_this()
    std::shared_ptr<clangwrapper::Type> ret = self->shared_from_this();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Type");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_std_enable_shared_from_this_clangwrapper_Type(lua_State *L)
{
    oluacls_class(L, "std.enable_shared_from_this<clangwrapper.Type>", nullptr);
    oluacls_func(L, "__olua_move", _std_enable_shared_from_this_clangwrapper_Type___olua_move);
    oluacls_func(L, "shared_from_this", _std_enable_shared_from_this_clangwrapper_Type_shared_from_this);

    olua_registerluatype<std::enable_shared_from_this<clangwrapper::Type>>(L, "std.enable_shared_from_this<clangwrapper.Type>");

    return 1;
}
OLUA_END_DECLS

static int _std_enable_shared_from_this_clangwrapper_Cursor___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (std::enable_shared_from_this<clangwrapper::Cursor> *)olua_toobj(L, 1, "std.enable_shared_from_this<clangwrapper.Cursor>");
    olua_push_obj(L, self, "std.enable_shared_from_this<clangwrapper.Cursor>");

    olua_endinvoke(L);

    return 1;
}

static int _std_enable_shared_from_this_clangwrapper_Cursor_shared_from_this(lua_State *L)
{
    olua_startinvoke(L);

    std::enable_shared_from_this<clangwrapper::Cursor> *self = nullptr;

    olua_to_obj(L, 1, &self, "std.enable_shared_from_this<clangwrapper.Cursor>");

    // std::shared_ptr<clangwrapper::Cursor> shared_from_this()
    std::shared_ptr<clangwrapper::Cursor> ret = self->shared_from_this();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Cursor");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_std_enable_shared_from_this_clangwrapper_Cursor(lua_State *L)
{
    oluacls_class(L, "std.enable_shared_from_this<clangwrapper.Cursor>", nullptr);
    oluacls_func(L, "__olua_move", _std_enable_shared_from_this_clangwrapper_Cursor___olua_move);
    oluacls_func(L, "shared_from_this", _std_enable_shared_from_this_clangwrapper_Cursor_shared_from_this);

    olua_registerluatype<std::enable_shared_from_this<clangwrapper::Cursor>>(L, "std.enable_shared_from_this<clangwrapper.Cursor>");

    return 1;
}
OLUA_END_DECLS

static int _std_enable_shared_from_this_clangwrapper_Module___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (std::enable_shared_from_this<clangwrapper::Module> *)olua_toobj(L, 1, "std.enable_shared_from_this<clangwrapper.Module>");
    olua_push_obj(L, self, "std.enable_shared_from_this<clangwrapper.Module>");

    olua_endinvoke(L);

    return 1;
}

static int _std_enable_shared_from_this_clangwrapper_Module_shared_from_this(lua_State *L)
{
    olua_startinvoke(L);

    std::enable_shared_from_this<clangwrapper::Module> *self = nullptr;

    olua_to_obj(L, 1, &self, "std.enable_shared_from_this<clangwrapper.Module>");

    // std::shared_ptr<clangwrapper::Module> shared_from_this()
    std::shared_ptr<clangwrapper::Module> ret = self->shared_from_this();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Module");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_std_enable_shared_from_this_clangwrapper_Module(lua_State *L)
{
    oluacls_class(L, "std.enable_shared_from_this<clangwrapper.Module>", nullptr);
    oluacls_func(L, "__olua_move", _std_enable_shared_from_this_clangwrapper_Module___olua_move);
    oluacls_func(L, "shared_from_this", _std_enable_shared_from_this_clangwrapper_Module_shared_from_this);

    olua_registerluatype<std::enable_shared_from_this<clangwrapper::Module>>(L, "std.enable_shared_from_this<clangwrapper.Module>");

    return 1;
}
OLUA_END_DECLS

static int _std_enable_shared_from_this_clangwrapper_TranslationUnit___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (std::enable_shared_from_this<clangwrapper::TranslationUnit> *)olua_toobj(L, 1, "std.enable_shared_from_this<clangwrapper.TranslationUnit>");
    olua_push_obj(L, self, "std.enable_shared_from_this<clangwrapper.TranslationUnit>");

    olua_endinvoke(L);

    return 1;
}

static int _std_enable_shared_from_this_clangwrapper_TranslationUnit_shared_from_this(lua_State *L)
{
    olua_startinvoke(L);

    std::enable_shared_from_this<clangwrapper::TranslationUnit> *self = nullptr;

    olua_to_obj(L, 1, &self, "std.enable_shared_from_this<clangwrapper.TranslationUnit>");

    // std::shared_ptr<clangwrapper::TranslationUnit> shared_from_this()
    std::shared_ptr<clangwrapper::TranslationUnit> ret = self->shared_from_this();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.TranslationUnit");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_std_enable_shared_from_this_clangwrapper_TranslationUnit(lua_State *L)
{
    oluacls_class(L, "std.enable_shared_from_this<clangwrapper.TranslationUnit>", nullptr);
    oluacls_func(L, "__olua_move", _std_enable_shared_from_this_clangwrapper_TranslationUnit___olua_move);
    oluacls_func(L, "shared_from_this", _std_enable_shared_from_this_clangwrapper_TranslationUnit_shared_from_this);

    olua_registerluatype<std::enable_shared_from_this<clangwrapper::TranslationUnit>>(L, "std.enable_shared_from_this<clangwrapper.TranslationUnit>");

    return 1;
}
OLUA_END_DECLS

static int _std_enable_shared_from_this_clangwrapper_Index___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (std::enable_shared_from_this<clangwrapper::Index> *)olua_toobj(L, 1, "std.enable_shared_from_this<clangwrapper.Index>");
    olua_push_obj(L, self, "std.enable_shared_from_this<clangwrapper.Index>");

    olua_endinvoke(L);

    return 1;
}

static int _std_enable_shared_from_this_clangwrapper_Index_shared_from_this(lua_State *L)
{
    olua_startinvoke(L);

    std::enable_shared_from_this<clangwrapper::Index> *self = nullptr;

    olua_to_obj(L, 1, &self, "std.enable_shared_from_this<clangwrapper.Index>");

    // std::shared_ptr<clangwrapper::Index> shared_from_this()
    std::shared_ptr<clangwrapper::Index> ret = self->shared_from_this();
    int num_ret = olua_push_obj(L, &ret, "clangwrapper.Index");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_std_enable_shared_from_this_clangwrapper_Index(lua_State *L)
{
    oluacls_class(L, "std.enable_shared_from_this<clangwrapper.Index>", nullptr);
    oluacls_func(L, "__olua_move", _std_enable_shared_from_this_clangwrapper_Index___olua_move);
    oluacls_func(L, "shared_from_this", _std_enable_shared_from_this_clangwrapper_Index_shared_from_this);

    olua_registerluatype<std::enable_shared_from_this<clangwrapper::Index>>(L, "std.enable_shared_from_this<clangwrapper.Index>");

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clang(lua_State *L)
{
    olua_require(L, "clangwrapper.IndexError", luaopen_clangwrapper_IndexError);
    olua_require(L, "clangwrapper.AvailabilityKind", luaopen_clangwrapper_AvailabilityKind);
    olua_require(L, "clangwrapper.CallingConv", luaopen_clangwrapper_CallingConv);
    olua_require(L, "clangwrapper.CursorKind", luaopen_clangwrapper_CursorKind);
    olua_require(L, "clangwrapper.CXXAccessSpecifier", luaopen_clangwrapper_CXXAccessSpecifier);
    olua_require(L, "clangwrapper.DiagnosticSeverity", luaopen_clangwrapper_DiagnosticSeverity);
    olua_require(L, "clangwrapper.GlobalOptFlags", luaopen_clangwrapper_GlobalOptFlags);
    olua_require(L, "clangwrapper.LanguageKind", luaopen_clangwrapper_LanguageKind);
    olua_require(L, "clangwrapper.LinkageKind", luaopen_clangwrapper_LinkageKind);
    olua_require(L, "clangwrapper.RefQualifierKind", luaopen_clangwrapper_RefQualifierKind);
    olua_require(L, "clangwrapper.StorageClass", luaopen_clangwrapper_StorageClass);
    olua_require(L, "clangwrapper.TemplateArgumentKind", luaopen_clangwrapper_TemplateArgumentKind);
    olua_require(L, "clangwrapper.TLSKind", luaopen_clangwrapper_TLSKind);
    olua_require(L, "clangwrapper.TypeKind", luaopen_clangwrapper_TypeKind);
    olua_require(L, "clangwrapper.TypeNullabilityKind", luaopen_clangwrapper_TypeNullabilityKind);
    olua_require(L, "clangwrapper.VisibilityKind", luaopen_clangwrapper_VisibilityKind);
    olua_require(L, "clangwrapper.Diagnostic", luaopen_clangwrapper_Diagnostic);
    olua_require(L, "clangwrapper.File", luaopen_clangwrapper_File);
    olua_require(L, "clangwrapper.Type", luaopen_clangwrapper_Type);
    olua_require(L, "clangwrapper.Cursor", luaopen_clangwrapper_Cursor);
    olua_require(L, "clangwrapper.Module", luaopen_clangwrapper_Module);
    olua_require(L, "clangwrapper.TranslationUnit", luaopen_clangwrapper_TranslationUnit);
    olua_require(L, "clangwrapper.Index", luaopen_clangwrapper_Index);
    olua_require(L, "clangwrapper.clang", luaopen_clangwrapper_clang);
    olua_require(L, "std.enable_shared_from_this<clangwrapper.Diagnostic>", luaopen_std_enable_shared_from_this_clangwrapper_Diagnostic);
    olua_require(L, "std.enable_shared_from_this<clangwrapper.File>", luaopen_std_enable_shared_from_this_clangwrapper_File);
    olua_require(L, "std.enable_shared_from_this<clangwrapper.Type>", luaopen_std_enable_shared_from_this_clangwrapper_Type);
    olua_require(L, "std.enable_shared_from_this<clangwrapper.Cursor>", luaopen_std_enable_shared_from_this_clangwrapper_Cursor);
    olua_require(L, "std.enable_shared_from_this<clangwrapper.Module>", luaopen_std_enable_shared_from_this_clangwrapper_Module);
    olua_require(L, "std.enable_shared_from_this<clangwrapper.TranslationUnit>", luaopen_std_enable_shared_from_this_clangwrapper_TranslationUnit);
    olua_require(L, "std.enable_shared_from_this<clangwrapper.Index>", luaopen_std_enable_shared_from_this_clangwrapper_Index);

    if (olua_getclass(L, "clangwrapper.clang")) {
        return 1;
    }

    return 0;
}
OLUA_END_DECLS
