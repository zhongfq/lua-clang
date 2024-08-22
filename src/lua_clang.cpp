//
// AUTO BUILD, DON'T MODIFY!
//
#include "lua_clang.h"
#include "clang_wrapper.h"

static int _clangwrapper_IndexError___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (clangwrapper::IndexError *)olua_toobj(L, 1, "clang.IndexError");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _clangwrapper_IndexError___index(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::IndexError *self = nullptr;

    olua_to_object(L, 1, &self, "clang.IndexError");

    // olua_Return __index(lua_State *L)
    olua_Return ret = self->__index(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _clangwrapper_IndexError___newindex(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::IndexError *self = nullptr;

    olua_to_object(L, 1, &self, "clang.IndexError");

    // olua_Return __newindex(lua_State *L)
    olua_Return ret = self->__newindex(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _clangwrapper_IndexError___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (clangwrapper::IndexError *)olua_toobj(L, 1, "clang.IndexError");
    olua_push_object(L, self, "clang.IndexError");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_IndexError(lua_State *L)
{
    oluacls_class<clangwrapper::IndexError>(L, "clang.IndexError");
    oluacls_func(L, "__gc", _clangwrapper_IndexError___gc);
    oluacls_func(L, "__index", _clangwrapper_IndexError___index);
    oluacls_func(L, "__newindex", _clangwrapper_IndexError___newindex);
    oluacls_func(L, "__olua_move", _clangwrapper_IndexError___olua_move);

    return 1;
}
OLUA_END_DECLS

static int _clangwrapper_Cursor_SourceRange___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (clangwrapper::Cursor::SourceRange *)olua_toobj(L, 1, "clang.Cursor.SourceRange");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _clangwrapper_Cursor_SourceRange___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (clangwrapper::Cursor::SourceRange *)olua_toobj(L, 1, "clang.Cursor.SourceRange");
    olua_push_object(L, self, "clang.Cursor.SourceRange");

    olua_endinvoke(L);

    return 1;
}

static int _clangwrapper_Cursor_SourceRange_endColumn$1(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor::SourceRange *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor.SourceRange");

    // unsigned int endColumn
    unsigned int ret = self->endColumn;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_SourceRange_endColumn$2(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor::SourceRange *self = nullptr;
    unsigned int arg1 = 0;       /** endColumn */

    olua_to_object(L, 1, &self, "clang.Cursor.SourceRange");
    olua_check_integer(L, 2, &arg1);

    // unsigned int endColumn
    self->endColumn = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _clangwrapper_Cursor_SourceRange_endColumn(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // unsigned int endColumn
        return _clangwrapper_Cursor_SourceRange_endColumn$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_integer(L, 2))) {
            // unsigned int endColumn
            return _clangwrapper_Cursor_SourceRange_endColumn$2(L);
        // }
    }

    luaL_error(L, "method 'clangwrapper::Cursor::SourceRange::endColumn' not support '%d' arguments", num_args);

    return 0;
}

static int _clangwrapper_Cursor_SourceRange_endLine$1(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor::SourceRange *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor.SourceRange");

    // unsigned int endLine
    unsigned int ret = self->endLine;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_SourceRange_endLine$2(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor::SourceRange *self = nullptr;
    unsigned int arg1 = 0;       /** endLine */

    olua_to_object(L, 1, &self, "clang.Cursor.SourceRange");
    olua_check_integer(L, 2, &arg1);

    // unsigned int endLine
    self->endLine = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _clangwrapper_Cursor_SourceRange_endLine(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // unsigned int endLine
        return _clangwrapper_Cursor_SourceRange_endLine$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_integer(L, 2))) {
            // unsigned int endLine
            return _clangwrapper_Cursor_SourceRange_endLine$2(L);
        // }
    }

    luaL_error(L, "method 'clangwrapper::Cursor::SourceRange::endLine' not support '%d' arguments", num_args);

    return 0;
}

static int _clangwrapper_Cursor_SourceRange_path$1(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor::SourceRange *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor.SourceRange");

    // std::string path
    std::string ret = self->path;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_SourceRange_path$2(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor::SourceRange *self = nullptr;
    std::string arg1;       /** path */

    olua_to_object(L, 1, &self, "clang.Cursor.SourceRange");
    olua_check_string(L, 2, &arg1);

    // std::string path
    self->path = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _clangwrapper_Cursor_SourceRange_path(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // std::string path
        return _clangwrapper_Cursor_SourceRange_path$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_string(L, 2))) {
            // std::string path
            return _clangwrapper_Cursor_SourceRange_path$2(L);
        // }
    }

    luaL_error(L, "method 'clangwrapper::Cursor::SourceRange::path' not support '%d' arguments", num_args);

    return 0;
}

static int _clangwrapper_Cursor_SourceRange_startColumn$1(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor::SourceRange *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor.SourceRange");

    // unsigned int startColumn
    unsigned int ret = self->startColumn;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_SourceRange_startColumn$2(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor::SourceRange *self = nullptr;
    unsigned int arg1 = 0;       /** startColumn */

    olua_to_object(L, 1, &self, "clang.Cursor.SourceRange");
    olua_check_integer(L, 2, &arg1);

    // unsigned int startColumn
    self->startColumn = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _clangwrapper_Cursor_SourceRange_startColumn(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // unsigned int startColumn
        return _clangwrapper_Cursor_SourceRange_startColumn$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_integer(L, 2))) {
            // unsigned int startColumn
            return _clangwrapper_Cursor_SourceRange_startColumn$2(L);
        // }
    }

    luaL_error(L, "method 'clangwrapper::Cursor::SourceRange::startColumn' not support '%d' arguments", num_args);

    return 0;
}

static int _clangwrapper_Cursor_SourceRange_startLine$1(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor::SourceRange *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor.SourceRange");

    // unsigned int startLine
    unsigned int ret = self->startLine;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_SourceRange_startLine$2(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor::SourceRange *self = nullptr;
    unsigned int arg1 = 0;       /** startLine */

    olua_to_object(L, 1, &self, "clang.Cursor.SourceRange");
    olua_check_integer(L, 2, &arg1);

    // unsigned int startLine
    self->startLine = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _clangwrapper_Cursor_SourceRange_startLine(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // unsigned int startLine
        return _clangwrapper_Cursor_SourceRange_startLine$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_integer(L, 2))) {
            // unsigned int startLine
            return _clangwrapper_Cursor_SourceRange_startLine$2(L);
        // }
    }

    luaL_error(L, "method 'clangwrapper::Cursor::SourceRange::startLine' not support '%d' arguments", num_args);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_Cursor_SourceRange(lua_State *L)
{
    oluacls_class<clangwrapper::Cursor::SourceRange>(L, "clang.Cursor.SourceRange");
    oluacls_func(L, "__gc", _clangwrapper_Cursor_SourceRange___gc);
    oluacls_func(L, "__olua_move", _clangwrapper_Cursor_SourceRange___olua_move);
    oluacls_prop(L, "endColumn", _clangwrapper_Cursor_SourceRange_endColumn, _clangwrapper_Cursor_SourceRange_endColumn);
    oluacls_prop(L, "endLine", _clangwrapper_Cursor_SourceRange_endLine, _clangwrapper_Cursor_SourceRange_endLine);
    oluacls_prop(L, "path", _clangwrapper_Cursor_SourceRange_path, _clangwrapper_Cursor_SourceRange_path);
    oluacls_prop(L, "startColumn", _clangwrapper_Cursor_SourceRange_startColumn, _clangwrapper_Cursor_SourceRange_startColumn);
    oluacls_prop(L, "startLine", _clangwrapper_Cursor_SourceRange_startLine, _clangwrapper_Cursor_SourceRange_startLine);

    return 1;
}
OLUA_END_DECLS

static int _clangwrapper_Cursor_SourceLocation___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (clangwrapper::Cursor::SourceLocation *)olua_toobj(L, 1, "clang.Cursor.SourceLocation");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _clangwrapper_Cursor_SourceLocation___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (clangwrapper::Cursor::SourceLocation *)olua_toobj(L, 1, "clang.Cursor.SourceLocation");
    olua_push_object(L, self, "clang.Cursor.SourceLocation");

    olua_endinvoke(L);

    return 1;
}

static int _clangwrapper_Cursor_SourceLocation_column$1(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor::SourceLocation *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor.SourceLocation");

    // unsigned int column
    unsigned int ret = self->column;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_SourceLocation_column$2(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor::SourceLocation *self = nullptr;
    unsigned int arg1 = 0;       /** column */

    olua_to_object(L, 1, &self, "clang.Cursor.SourceLocation");
    olua_check_integer(L, 2, &arg1);

    // unsigned int column
    self->column = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _clangwrapper_Cursor_SourceLocation_column(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // unsigned int column
        return _clangwrapper_Cursor_SourceLocation_column$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_integer(L, 2))) {
            // unsigned int column
            return _clangwrapper_Cursor_SourceLocation_column$2(L);
        // }
    }

    luaL_error(L, "method 'clangwrapper::Cursor::SourceLocation::column' not support '%d' arguments", num_args);

    return 0;
}

static int _clangwrapper_Cursor_SourceLocation_line$1(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor::SourceLocation *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor.SourceLocation");

    // unsigned int line
    unsigned int ret = self->line;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_SourceLocation_line$2(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor::SourceLocation *self = nullptr;
    unsigned int arg1 = 0;       /** line */

    olua_to_object(L, 1, &self, "clang.Cursor.SourceLocation");
    olua_check_integer(L, 2, &arg1);

    // unsigned int line
    self->line = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _clangwrapper_Cursor_SourceLocation_line(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // unsigned int line
        return _clangwrapper_Cursor_SourceLocation_line$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_integer(L, 2))) {
            // unsigned int line
            return _clangwrapper_Cursor_SourceLocation_line$2(L);
        // }
    }

    luaL_error(L, "method 'clangwrapper::Cursor::SourceLocation::line' not support '%d' arguments", num_args);

    return 0;
}

static int _clangwrapper_Cursor_SourceLocation_path$1(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor::SourceLocation *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor.SourceLocation");

    // std::string path
    std::string ret = self->path;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_SourceLocation_path$2(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor::SourceLocation *self = nullptr;
    std::string arg1;       /** path */

    olua_to_object(L, 1, &self, "clang.Cursor.SourceLocation");
    olua_check_string(L, 2, &arg1);

    // std::string path
    self->path = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _clangwrapper_Cursor_SourceLocation_path(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // std::string path
        return _clangwrapper_Cursor_SourceLocation_path$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_string(L, 2))) {
            // std::string path
            return _clangwrapper_Cursor_SourceLocation_path$2(L);
        // }
    }

    luaL_error(L, "method 'clangwrapper::Cursor::SourceLocation::path' not support '%d' arguments", num_args);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_Cursor_SourceLocation(lua_State *L)
{
    oluacls_class<clangwrapper::Cursor::SourceLocation>(L, "clang.Cursor.SourceLocation");
    oluacls_func(L, "__gc", _clangwrapper_Cursor_SourceLocation___gc);
    oluacls_func(L, "__olua_move", _clangwrapper_Cursor_SourceLocation___olua_move);
    oluacls_prop(L, "column", _clangwrapper_Cursor_SourceLocation_column, _clangwrapper_Cursor_SourceLocation_column);
    oluacls_prop(L, "line", _clangwrapper_Cursor_SourceLocation_line, _clangwrapper_Cursor_SourceLocation_line);
    oluacls_prop(L, "path", _clangwrapper_Cursor_SourceLocation_path, _clangwrapper_Cursor_SourceLocation_path);

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_AvailabilityKind(lua_State *L)
{
    oluacls_class<clangwrapper::AvailabilityKind>(L, "clang.AvailabilityKind");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "Available", (lua_Integer)clangwrapper::AvailabilityKind::CXAvailability_Available);
    oluacls_enum(L, "Deprecated", (lua_Integer)clangwrapper::AvailabilityKind::CXAvailability_Deprecated);
    oluacls_enum(L, "NotAccessible", (lua_Integer)clangwrapper::AvailabilityKind::CXAvailability_NotAccessible);
    oluacls_enum(L, "NotAvailable", (lua_Integer)clangwrapper::AvailabilityKind::CXAvailability_NotAvailable);

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_CallingConv(lua_State *L)
{
    oluacls_class<clangwrapper::CallingConv>(L, "clang.CallingConv");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "AAPCS", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_AAPCS);
    oluacls_enum(L, "AAPCS_VFP", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_AAPCS_VFP);
    oluacls_enum(L, "AArch64SVEPCS", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_AArch64SVEPCS);
    oluacls_enum(L, "AArch64VectorCall", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_AArch64VectorCall);
    oluacls_enum(L, "C", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_C);
    oluacls_enum(L, "Default", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_Default);
    oluacls_enum(L, "IntelOclBicc", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_IntelOclBicc);
    oluacls_enum(L, "Invalid", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_Invalid);
    oluacls_enum(L, "M68kRTD", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_M68kRTD);
    oluacls_enum(L, "PreserveAll", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_PreserveAll);
    oluacls_enum(L, "PreserveMost", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_PreserveMost);
    oluacls_enum(L, "PreserveNone", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_PreserveNone);
    oluacls_enum(L, "RISCVVectorCall", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_RISCVVectorCall);
    oluacls_enum(L, "Swift", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_Swift);
    oluacls_enum(L, "SwiftAsync", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_SwiftAsync);
    oluacls_enum(L, "Unexposed", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_Unexposed);
    oluacls_enum(L, "Win64", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_Win64);
    oluacls_enum(L, "X86FastCall", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_X86FastCall);
    oluacls_enum(L, "X86Pascal", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_X86Pascal);
    oluacls_enum(L, "X86RegCall", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_X86RegCall);
    oluacls_enum(L, "X86StdCall", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_X86StdCall);
    oluacls_enum(L, "X86ThisCall", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_X86ThisCall);
    oluacls_enum(L, "X86VectorCall", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_X86VectorCall);
    oluacls_enum(L, "X86_64SysV", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_X86_64SysV);
    oluacls_enum(L, "X86_64Win64", (lua_Integer)clangwrapper::CallingConv::CXCallingConv_X86_64Win64);

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_CursorKind(lua_State *L)
{
    oluacls_class<clangwrapper::CursorKind>(L, "clang.CursorKind");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "AddrLabelExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_AddrLabelExpr);
    oluacls_enum(L, "AlignedAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_AlignedAttr);
    oluacls_enum(L, "AnnotateAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_AnnotateAttr);
    oluacls_enum(L, "ArraySectionExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_ArraySectionExpr);
    oluacls_enum(L, "ArraySubscriptExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_ArraySubscriptExpr);
    oluacls_enum(L, "AsmLabelAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_AsmLabelAttr);
    oluacls_enum(L, "AsmStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_AsmStmt);
    oluacls_enum(L, "BinaryOperator", (lua_Integer)clangwrapper::CursorKind::CXCursor_BinaryOperator);
    oluacls_enum(L, "BlockExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_BlockExpr);
    oluacls_enum(L, "BreakStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_BreakStmt);
    oluacls_enum(L, "BuiltinBitCastExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_BuiltinBitCastExpr);
    oluacls_enum(L, "CStyleCastExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CStyleCastExpr);
    oluacls_enum(L, "CUDAConstantAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CUDAConstantAttr);
    oluacls_enum(L, "CUDADeviceAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CUDADeviceAttr);
    oluacls_enum(L, "CUDAGlobalAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CUDAGlobalAttr);
    oluacls_enum(L, "CUDAHostAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CUDAHostAttr);
    oluacls_enum(L, "CUDASharedAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CUDASharedAttr);
    oluacls_enum(L, "CXXAccessSpecifier", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXAccessSpecifier);
    oluacls_enum(L, "CXXAddrspaceCastExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXAddrspaceCastExpr);
    oluacls_enum(L, "CXXBaseSpecifier", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXBaseSpecifier);
    oluacls_enum(L, "CXXBoolLiteralExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXBoolLiteralExpr);
    oluacls_enum(L, "CXXCatchStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXCatchStmt);
    oluacls_enum(L, "CXXConstCastExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXConstCastExpr);
    oluacls_enum(L, "CXXDeleteExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXDeleteExpr);
    oluacls_enum(L, "CXXDynamicCastExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXDynamicCastExpr);
    oluacls_enum(L, "CXXFinalAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXFinalAttr);
    oluacls_enum(L, "CXXForRangeStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXForRangeStmt);
    oluacls_enum(L, "CXXFunctionalCastExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXFunctionalCastExpr);
    oluacls_enum(L, "CXXMethod", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXMethod);
    oluacls_enum(L, "CXXNewExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXNewExpr);
    oluacls_enum(L, "CXXNullPtrLiteralExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXNullPtrLiteralExpr);
    oluacls_enum(L, "CXXOverrideAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXOverrideAttr);
    oluacls_enum(L, "CXXParenListInitExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXParenListInitExpr);
    oluacls_enum(L, "CXXReinterpretCastExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXReinterpretCastExpr);
    oluacls_enum(L, "CXXStaticCastExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXStaticCastExpr);
    oluacls_enum(L, "CXXThisExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXThisExpr);
    oluacls_enum(L, "CXXThrowExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXThrowExpr);
    oluacls_enum(L, "CXXTryStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXTryStmt);
    oluacls_enum(L, "CXXTypeidExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CXXTypeidExpr);
    oluacls_enum(L, "CallExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CallExpr);
    oluacls_enum(L, "CaseStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_CaseStmt);
    oluacls_enum(L, "CharacterLiteral", (lua_Integer)clangwrapper::CursorKind::CXCursor_CharacterLiteral);
    oluacls_enum(L, "ClassDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_ClassDecl);
    oluacls_enum(L, "ClassTemplate", (lua_Integer)clangwrapper::CursorKind::CXCursor_ClassTemplate);
    oluacls_enum(L, "ClassTemplatePartialSpecialization", (lua_Integer)clangwrapper::CursorKind::CXCursor_ClassTemplatePartialSpecialization);
    oluacls_enum(L, "CompoundAssignOperator", (lua_Integer)clangwrapper::CursorKind::CXCursor_CompoundAssignOperator);
    oluacls_enum(L, "CompoundLiteralExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_CompoundLiteralExpr);
    oluacls_enum(L, "CompoundStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_CompoundStmt);
    oluacls_enum(L, "ConceptDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_ConceptDecl);
    oluacls_enum(L, "ConceptSpecializationExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_ConceptSpecializationExpr);
    oluacls_enum(L, "ConditionalOperator", (lua_Integer)clangwrapper::CursorKind::CXCursor_ConditionalOperator);
    oluacls_enum(L, "ConstAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_ConstAttr);
    oluacls_enum(L, "Constructor", (lua_Integer)clangwrapper::CursorKind::CXCursor_Constructor);
    oluacls_enum(L, "ContinueStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_ContinueStmt);
    oluacls_enum(L, "ConvergentAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_ConvergentAttr);
    oluacls_enum(L, "ConversionFunction", (lua_Integer)clangwrapper::CursorKind::CXCursor_ConversionFunction);
    oluacls_enum(L, "DLLExport", (lua_Integer)clangwrapper::CursorKind::CXCursor_DLLExport);
    oluacls_enum(L, "DLLImport", (lua_Integer)clangwrapper::CursorKind::CXCursor_DLLImport);
    oluacls_enum(L, "DeclRefExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_DeclRefExpr);
    oluacls_enum(L, "DeclStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_DeclStmt);
    oluacls_enum(L, "DefaultStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_DefaultStmt);
    oluacls_enum(L, "Destructor", (lua_Integer)clangwrapper::CursorKind::CXCursor_Destructor);
    oluacls_enum(L, "DoStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_DoStmt);
    oluacls_enum(L, "EnumConstantDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_EnumConstantDecl);
    oluacls_enum(L, "EnumDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_EnumDecl);
    oluacls_enum(L, "FieldDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_FieldDecl);
    oluacls_enum(L, "FirstAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_FirstAttr);
    oluacls_enum(L, "FirstDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_FirstDecl);
    oluacls_enum(L, "FirstExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_FirstExpr);
    oluacls_enum(L, "FirstExtraDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_FirstExtraDecl);
    oluacls_enum(L, "FirstInvalid", (lua_Integer)clangwrapper::CursorKind::CXCursor_FirstInvalid);
    oluacls_enum(L, "FirstPreprocessing", (lua_Integer)clangwrapper::CursorKind::CXCursor_FirstPreprocessing);
    oluacls_enum(L, "FirstRef", (lua_Integer)clangwrapper::CursorKind::CXCursor_FirstRef);
    oluacls_enum(L, "FirstStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_FirstStmt);
    oluacls_enum(L, "FixedPointLiteral", (lua_Integer)clangwrapper::CursorKind::CXCursor_FixedPointLiteral);
    oluacls_enum(L, "FlagEnum", (lua_Integer)clangwrapper::CursorKind::CXCursor_FlagEnum);
    oluacls_enum(L, "FloatingLiteral", (lua_Integer)clangwrapper::CursorKind::CXCursor_FloatingLiteral);
    oluacls_enum(L, "ForStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_ForStmt);
    oluacls_enum(L, "FriendDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_FriendDecl);
    oluacls_enum(L, "FunctionDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_FunctionDecl);
    oluacls_enum(L, "FunctionTemplate", (lua_Integer)clangwrapper::CursorKind::CXCursor_FunctionTemplate);
    oluacls_enum(L, "GCCAsmStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_GCCAsmStmt);
    oluacls_enum(L, "GNUNullExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_GNUNullExpr);
    oluacls_enum(L, "GenericSelectionExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_GenericSelectionExpr);
    oluacls_enum(L, "GotoStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_GotoStmt);
    oluacls_enum(L, "IBActionAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_IBActionAttr);
    oluacls_enum(L, "IBOutletAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_IBOutletAttr);
    oluacls_enum(L, "IBOutletCollectionAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_IBOutletCollectionAttr);
    oluacls_enum(L, "IfStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_IfStmt);
    oluacls_enum(L, "ImaginaryLiteral", (lua_Integer)clangwrapper::CursorKind::CXCursor_ImaginaryLiteral);
    oluacls_enum(L, "InclusionDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_InclusionDirective);
    oluacls_enum(L, "IndirectGotoStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_IndirectGotoStmt);
    oluacls_enum(L, "InitListExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_InitListExpr);
    oluacls_enum(L, "IntegerLiteral", (lua_Integer)clangwrapper::CursorKind::CXCursor_IntegerLiteral);
    oluacls_enum(L, "InvalidCode", (lua_Integer)clangwrapper::CursorKind::CXCursor_InvalidCode);
    oluacls_enum(L, "InvalidFile", (lua_Integer)clangwrapper::CursorKind::CXCursor_InvalidFile);
    oluacls_enum(L, "LabelRef", (lua_Integer)clangwrapper::CursorKind::CXCursor_LabelRef);
    oluacls_enum(L, "LabelStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_LabelStmt);
    oluacls_enum(L, "LambdaExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_LambdaExpr);
    oluacls_enum(L, "LastAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_LastAttr);
    oluacls_enum(L, "LastDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_LastDecl);
    oluacls_enum(L, "LastExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_LastExpr);
    oluacls_enum(L, "LastExtraDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_LastExtraDecl);
    oluacls_enum(L, "LastInvalid", (lua_Integer)clangwrapper::CursorKind::CXCursor_LastInvalid);
    oluacls_enum(L, "LastPreprocessing", (lua_Integer)clangwrapper::CursorKind::CXCursor_LastPreprocessing);
    oluacls_enum(L, "LastRef", (lua_Integer)clangwrapper::CursorKind::CXCursor_LastRef);
    oluacls_enum(L, "LastStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_LastStmt);
    oluacls_enum(L, "LinkageSpec", (lua_Integer)clangwrapper::CursorKind::CXCursor_LinkageSpec);
    oluacls_enum(L, "MSAsmStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_MSAsmStmt);
    oluacls_enum(L, "MacroDefinition", (lua_Integer)clangwrapper::CursorKind::CXCursor_MacroDefinition);
    oluacls_enum(L, "MacroExpansion", (lua_Integer)clangwrapper::CursorKind::CXCursor_MacroExpansion);
    oluacls_enum(L, "MacroInstantiation", (lua_Integer)clangwrapper::CursorKind::CXCursor_MacroInstantiation);
    oluacls_enum(L, "MemberRef", (lua_Integer)clangwrapper::CursorKind::CXCursor_MemberRef);
    oluacls_enum(L, "MemberRefExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_MemberRefExpr);
    oluacls_enum(L, "ModuleImportDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_ModuleImportDecl);
    oluacls_enum(L, "NSConsumed", (lua_Integer)clangwrapper::CursorKind::CXCursor_NSConsumed);
    oluacls_enum(L, "NSConsumesSelf", (lua_Integer)clangwrapper::CursorKind::CXCursor_NSConsumesSelf);
    oluacls_enum(L, "NSReturnsAutoreleased", (lua_Integer)clangwrapper::CursorKind::CXCursor_NSReturnsAutoreleased);
    oluacls_enum(L, "NSReturnsNotRetained", (lua_Integer)clangwrapper::CursorKind::CXCursor_NSReturnsNotRetained);
    oluacls_enum(L, "NSReturnsRetained", (lua_Integer)clangwrapper::CursorKind::CXCursor_NSReturnsRetained);
    oluacls_enum(L, "Namespace", (lua_Integer)clangwrapper::CursorKind::CXCursor_Namespace);
    oluacls_enum(L, "NamespaceAlias", (lua_Integer)clangwrapper::CursorKind::CXCursor_NamespaceAlias);
    oluacls_enum(L, "NamespaceRef", (lua_Integer)clangwrapper::CursorKind::CXCursor_NamespaceRef);
    oluacls_enum(L, "NoDeclFound", (lua_Integer)clangwrapper::CursorKind::CXCursor_NoDeclFound);
    oluacls_enum(L, "NoDuplicateAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_NoDuplicateAttr);
    oluacls_enum(L, "NonTypeTemplateParameter", (lua_Integer)clangwrapper::CursorKind::CXCursor_NonTypeTemplateParameter);
    oluacls_enum(L, "NotImplemented", (lua_Integer)clangwrapper::CursorKind::CXCursor_NotImplemented);
    oluacls_enum(L, "NullStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_NullStmt);
    oluacls_enum(L, "OMPArrayShapingExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPArrayShapingExpr);
    oluacls_enum(L, "OMPAssumeDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPAssumeDirective);
    oluacls_enum(L, "OMPAtomicDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPAtomicDirective);
    oluacls_enum(L, "OMPBarrierDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPBarrierDirective);
    oluacls_enum(L, "OMPCancelDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPCancelDirective);
    oluacls_enum(L, "OMPCancellationPointDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPCancellationPointDirective);
    oluacls_enum(L, "OMPCanonicalLoop", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPCanonicalLoop);
    oluacls_enum(L, "OMPCriticalDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPCriticalDirective);
    oluacls_enum(L, "OMPDepobjDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPDepobjDirective);
    oluacls_enum(L, "OMPDispatchDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPDispatchDirective);
    oluacls_enum(L, "OMPDistributeDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPDistributeDirective);
    oluacls_enum(L, "OMPDistributeParallelForDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPDistributeParallelForDirective);
    oluacls_enum(L, "OMPDistributeParallelForSimdDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPDistributeParallelForSimdDirective);
    oluacls_enum(L, "OMPDistributeSimdDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPDistributeSimdDirective);
    oluacls_enum(L, "OMPErrorDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPErrorDirective);
    oluacls_enum(L, "OMPFlushDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPFlushDirective);
    oluacls_enum(L, "OMPForDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPForDirective);
    oluacls_enum(L, "OMPForSimdDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPForSimdDirective);
    oluacls_enum(L, "OMPGenericLoopDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPGenericLoopDirective);
    oluacls_enum(L, "OMPInterchangeDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPInterchangeDirective);
    oluacls_enum(L, "OMPInteropDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPInteropDirective);
    oluacls_enum(L, "OMPIteratorExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPIteratorExpr);
    oluacls_enum(L, "OMPMaskedDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPMaskedDirective);
    oluacls_enum(L, "OMPMaskedTaskLoopDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPMaskedTaskLoopDirective);
    oluacls_enum(L, "OMPMaskedTaskLoopSimdDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPMaskedTaskLoopSimdDirective);
    oluacls_enum(L, "OMPMasterDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPMasterDirective);
    oluacls_enum(L, "OMPMasterTaskLoopDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPMasterTaskLoopDirective);
    oluacls_enum(L, "OMPMasterTaskLoopSimdDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPMasterTaskLoopSimdDirective);
    oluacls_enum(L, "OMPMetaDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPMetaDirective);
    oluacls_enum(L, "OMPOrderedDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPOrderedDirective);
    oluacls_enum(L, "OMPParallelDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPParallelDirective);
    oluacls_enum(L, "OMPParallelForDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPParallelForDirective);
    oluacls_enum(L, "OMPParallelForSimdDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPParallelForSimdDirective);
    oluacls_enum(L, "OMPParallelGenericLoopDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPParallelGenericLoopDirective);
    oluacls_enum(L, "OMPParallelMaskedDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPParallelMaskedDirective);
    oluacls_enum(L, "OMPParallelMaskedTaskLoopDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPParallelMaskedTaskLoopDirective);
    oluacls_enum(L, "OMPParallelMaskedTaskLoopSimdDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPParallelMaskedTaskLoopSimdDirective);
    oluacls_enum(L, "OMPParallelMasterDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPParallelMasterDirective);
    oluacls_enum(L, "OMPParallelMasterTaskLoopDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPParallelMasterTaskLoopDirective);
    oluacls_enum(L, "OMPParallelMasterTaskLoopSimdDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPParallelMasterTaskLoopSimdDirective);
    oluacls_enum(L, "OMPParallelSectionsDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPParallelSectionsDirective);
    oluacls_enum(L, "OMPReverseDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPReverseDirective);
    oluacls_enum(L, "OMPScanDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPScanDirective);
    oluacls_enum(L, "OMPScopeDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPScopeDirective);
    oluacls_enum(L, "OMPSectionDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPSectionDirective);
    oluacls_enum(L, "OMPSectionsDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPSectionsDirective);
    oluacls_enum(L, "OMPSimdDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPSimdDirective);
    oluacls_enum(L, "OMPSingleDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPSingleDirective);
    oluacls_enum(L, "OMPTargetDataDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTargetDataDirective);
    oluacls_enum(L, "OMPTargetDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTargetDirective);
    oluacls_enum(L, "OMPTargetEnterDataDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTargetEnterDataDirective);
    oluacls_enum(L, "OMPTargetExitDataDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTargetExitDataDirective);
    oluacls_enum(L, "OMPTargetParallelDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTargetParallelDirective);
    oluacls_enum(L, "OMPTargetParallelForDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTargetParallelForDirective);
    oluacls_enum(L, "OMPTargetParallelForSimdDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTargetParallelForSimdDirective);
    oluacls_enum(L, "OMPTargetParallelGenericLoopDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTargetParallelGenericLoopDirective);
    oluacls_enum(L, "OMPTargetSimdDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTargetSimdDirective);
    oluacls_enum(L, "OMPTargetTeamsDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTargetTeamsDirective);
    oluacls_enum(L, "OMPTargetTeamsDistributeDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTargetTeamsDistributeDirective);
    oluacls_enum(L, "OMPTargetTeamsDistributeParallelForDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTargetTeamsDistributeParallelForDirective);
    oluacls_enum(L, "OMPTargetTeamsDistributeParallelForSimdDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTargetTeamsDistributeParallelForSimdDirective);
    oluacls_enum(L, "OMPTargetTeamsDistributeSimdDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTargetTeamsDistributeSimdDirective);
    oluacls_enum(L, "OMPTargetTeamsGenericLoopDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTargetTeamsGenericLoopDirective);
    oluacls_enum(L, "OMPTargetUpdateDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTargetUpdateDirective);
    oluacls_enum(L, "OMPTaskDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTaskDirective);
    oluacls_enum(L, "OMPTaskLoopDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTaskLoopDirective);
    oluacls_enum(L, "OMPTaskLoopSimdDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTaskLoopSimdDirective);
    oluacls_enum(L, "OMPTaskgroupDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTaskgroupDirective);
    oluacls_enum(L, "OMPTaskwaitDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTaskwaitDirective);
    oluacls_enum(L, "OMPTaskyieldDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTaskyieldDirective);
    oluacls_enum(L, "OMPTeamsDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTeamsDirective);
    oluacls_enum(L, "OMPTeamsDistributeDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTeamsDistributeDirective);
    oluacls_enum(L, "OMPTeamsDistributeParallelForDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTeamsDistributeParallelForDirective);
    oluacls_enum(L, "OMPTeamsDistributeParallelForSimdDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTeamsDistributeParallelForSimdDirective);
    oluacls_enum(L, "OMPTeamsDistributeSimdDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTeamsDistributeSimdDirective);
    oluacls_enum(L, "OMPTeamsGenericLoopDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTeamsGenericLoopDirective);
    oluacls_enum(L, "OMPTileDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPTileDirective);
    oluacls_enum(L, "OMPUnrollDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_OMPUnrollDirective);
    oluacls_enum(L, "ObjCAtCatchStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCAtCatchStmt);
    oluacls_enum(L, "ObjCAtFinallyStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCAtFinallyStmt);
    oluacls_enum(L, "ObjCAtSynchronizedStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCAtSynchronizedStmt);
    oluacls_enum(L, "ObjCAtThrowStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCAtThrowStmt);
    oluacls_enum(L, "ObjCAtTryStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCAtTryStmt);
    oluacls_enum(L, "ObjCAutoreleasePoolStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCAutoreleasePoolStmt);
    oluacls_enum(L, "ObjCAvailabilityCheckExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCAvailabilityCheckExpr);
    oluacls_enum(L, "ObjCBoolLiteralExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCBoolLiteralExpr);
    oluacls_enum(L, "ObjCBoxable", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCBoxable);
    oluacls_enum(L, "ObjCBridgedCastExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCBridgedCastExpr);
    oluacls_enum(L, "ObjCCategoryDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCCategoryDecl);
    oluacls_enum(L, "ObjCCategoryImplDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCCategoryImplDecl);
    oluacls_enum(L, "ObjCClassMethodDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCClassMethodDecl);
    oluacls_enum(L, "ObjCClassRef", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCClassRef);
    oluacls_enum(L, "ObjCDesignatedInitializer", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCDesignatedInitializer);
    oluacls_enum(L, "ObjCDynamicDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCDynamicDecl);
    oluacls_enum(L, "ObjCEncodeExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCEncodeExpr);
    oluacls_enum(L, "ObjCException", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCException);
    oluacls_enum(L, "ObjCExplicitProtocolImpl", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCExplicitProtocolImpl);
    oluacls_enum(L, "ObjCForCollectionStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCForCollectionStmt);
    oluacls_enum(L, "ObjCImplementationDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCImplementationDecl);
    oluacls_enum(L, "ObjCIndependentClass", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCIndependentClass);
    oluacls_enum(L, "ObjCInstanceMethodDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCInstanceMethodDecl);
    oluacls_enum(L, "ObjCInterfaceDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCInterfaceDecl);
    oluacls_enum(L, "ObjCIvarDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCIvarDecl);
    oluacls_enum(L, "ObjCMessageExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCMessageExpr);
    oluacls_enum(L, "ObjCNSObject", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCNSObject);
    oluacls_enum(L, "ObjCPreciseLifetime", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCPreciseLifetime);
    oluacls_enum(L, "ObjCPropertyDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCPropertyDecl);
    oluacls_enum(L, "ObjCProtocolDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCProtocolDecl);
    oluacls_enum(L, "ObjCProtocolExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCProtocolExpr);
    oluacls_enum(L, "ObjCProtocolRef", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCProtocolRef);
    oluacls_enum(L, "ObjCRequiresSuper", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCRequiresSuper);
    oluacls_enum(L, "ObjCReturnsInnerPointer", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCReturnsInnerPointer);
    oluacls_enum(L, "ObjCRootClass", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCRootClass);
    oluacls_enum(L, "ObjCRuntimeVisible", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCRuntimeVisible);
    oluacls_enum(L, "ObjCSelectorExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCSelectorExpr);
    oluacls_enum(L, "ObjCSelfExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCSelfExpr);
    oluacls_enum(L, "ObjCStringLiteral", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCStringLiteral);
    oluacls_enum(L, "ObjCSubclassingRestricted", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCSubclassingRestricted);
    oluacls_enum(L, "ObjCSuperClassRef", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCSuperClassRef);
    oluacls_enum(L, "ObjCSynthesizeDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_ObjCSynthesizeDecl);
    oluacls_enum(L, "OpenACCComputeConstruct", (lua_Integer)clangwrapper::CursorKind::CXCursor_OpenACCComputeConstruct);
    oluacls_enum(L, "OpenACCLoopConstruct", (lua_Integer)clangwrapper::CursorKind::CXCursor_OpenACCLoopConstruct);
    oluacls_enum(L, "OverloadCandidate", (lua_Integer)clangwrapper::CursorKind::CXCursor_OverloadCandidate);
    oluacls_enum(L, "OverloadedDeclRef", (lua_Integer)clangwrapper::CursorKind::CXCursor_OverloadedDeclRef);
    oluacls_enum(L, "PackExpansionExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_PackExpansionExpr);
    oluacls_enum(L, "PackIndexingExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_PackIndexingExpr);
    oluacls_enum(L, "PackedAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_PackedAttr);
    oluacls_enum(L, "ParenExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_ParenExpr);
    oluacls_enum(L, "ParmDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_ParmDecl);
    oluacls_enum(L, "PreprocessingDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_PreprocessingDirective);
    oluacls_enum(L, "PureAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_PureAttr);
    oluacls_enum(L, "RequiresExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_RequiresExpr);
    oluacls_enum(L, "ReturnStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_ReturnStmt);
    oluacls_enum(L, "SEHExceptStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_SEHExceptStmt);
    oluacls_enum(L, "SEHFinallyStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_SEHFinallyStmt);
    oluacls_enum(L, "SEHLeaveStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_SEHLeaveStmt);
    oluacls_enum(L, "SEHTryStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_SEHTryStmt);
    oluacls_enum(L, "SizeOfPackExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_SizeOfPackExpr);
    oluacls_enum(L, "StaticAssert", (lua_Integer)clangwrapper::CursorKind::CXCursor_StaticAssert);
    oluacls_enum(L, "StmtExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_StmtExpr);
    oluacls_enum(L, "StringLiteral", (lua_Integer)clangwrapper::CursorKind::CXCursor_StringLiteral);
    oluacls_enum(L, "StructDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_StructDecl);
    oluacls_enum(L, "SwitchStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_SwitchStmt);
    oluacls_enum(L, "TemplateRef", (lua_Integer)clangwrapper::CursorKind::CXCursor_TemplateRef);
    oluacls_enum(L, "TemplateTemplateParameter", (lua_Integer)clangwrapper::CursorKind::CXCursor_TemplateTemplateParameter);
    oluacls_enum(L, "TemplateTypeParameter", (lua_Integer)clangwrapper::CursorKind::CXCursor_TemplateTypeParameter);
    oluacls_enum(L, "TranslationUnit", (lua_Integer)clangwrapper::CursorKind::CXCursor_TranslationUnit);
    oluacls_enum(L, "TypeAliasDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_TypeAliasDecl);
    oluacls_enum(L, "TypeAliasTemplateDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_TypeAliasTemplateDecl);
    oluacls_enum(L, "TypeRef", (lua_Integer)clangwrapper::CursorKind::CXCursor_TypeRef);
    oluacls_enum(L, "TypedefDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_TypedefDecl);
    oluacls_enum(L, "UnaryExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_UnaryExpr);
    oluacls_enum(L, "UnaryOperator", (lua_Integer)clangwrapper::CursorKind::CXCursor_UnaryOperator);
    oluacls_enum(L, "UnexposedAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_UnexposedAttr);
    oluacls_enum(L, "UnexposedDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_UnexposedDecl);
    oluacls_enum(L, "UnexposedExpr", (lua_Integer)clangwrapper::CursorKind::CXCursor_UnexposedExpr);
    oluacls_enum(L, "UnexposedStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_UnexposedStmt);
    oluacls_enum(L, "UnionDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_UnionDecl);
    oluacls_enum(L, "UsingDeclaration", (lua_Integer)clangwrapper::CursorKind::CXCursor_UsingDeclaration);
    oluacls_enum(L, "UsingDirective", (lua_Integer)clangwrapper::CursorKind::CXCursor_UsingDirective);
    oluacls_enum(L, "VarDecl", (lua_Integer)clangwrapper::CursorKind::CXCursor_VarDecl);
    oluacls_enum(L, "VariableRef", (lua_Integer)clangwrapper::CursorKind::CXCursor_VariableRef);
    oluacls_enum(L, "VisibilityAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_VisibilityAttr);
    oluacls_enum(L, "WarnUnusedAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_WarnUnusedAttr);
    oluacls_enum(L, "WarnUnusedResultAttr", (lua_Integer)clangwrapper::CursorKind::CXCursor_WarnUnusedResultAttr);
    oluacls_enum(L, "WhileStmt", (lua_Integer)clangwrapper::CursorKind::CXCursor_WhileStmt);

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_CXXAccessSpecifier(lua_State *L)
{
    oluacls_class<clangwrapper::CXXAccessSpecifier>(L, "clang.CXXAccessSpecifier");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "InvalidAccessSpecifier", (lua_Integer)clangwrapper::CXXAccessSpecifier::CX_CXXInvalidAccessSpecifier);
    oluacls_enum(L, "Private", (lua_Integer)clangwrapper::CXXAccessSpecifier::CX_CXXPrivate);
    oluacls_enum(L, "Protected", (lua_Integer)clangwrapper::CXXAccessSpecifier::CX_CXXProtected);
    oluacls_enum(L, "Public", (lua_Integer)clangwrapper::CXXAccessSpecifier::CX_CXXPublic);

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_DiagnosticSeverity(lua_State *L)
{
    oluacls_class<clangwrapper::DiagnosticSeverity>(L, "clang.DiagnosticSeverity");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "Error", (lua_Integer)clangwrapper::DiagnosticSeverity::CXDiagnostic_Error);
    oluacls_enum(L, "Fatal", (lua_Integer)clangwrapper::DiagnosticSeverity::CXDiagnostic_Fatal);
    oluacls_enum(L, "Ignored", (lua_Integer)clangwrapper::DiagnosticSeverity::CXDiagnostic_Ignored);
    oluacls_enum(L, "Note", (lua_Integer)clangwrapper::DiagnosticSeverity::CXDiagnostic_Note);
    oluacls_enum(L, "Warning", (lua_Integer)clangwrapper::DiagnosticSeverity::CXDiagnostic_Warning);

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_GlobalOptFlags(lua_State *L)
{
    oluacls_class<clangwrapper::GlobalOptFlags>(L, "clang.GlobalOptFlags");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "None", (lua_Integer)clangwrapper::GlobalOptFlags::CXGlobalOpt_None);
    oluacls_enum(L, "ThreadBackgroundPriorityForAll", (lua_Integer)clangwrapper::GlobalOptFlags::CXGlobalOpt_ThreadBackgroundPriorityForAll);
    oluacls_enum(L, "ThreadBackgroundPriorityForEditing", (lua_Integer)clangwrapper::GlobalOptFlags::CXGlobalOpt_ThreadBackgroundPriorityForEditing);
    oluacls_enum(L, "ThreadBackgroundPriorityForIndexing", (lua_Integer)clangwrapper::GlobalOptFlags::CXGlobalOpt_ThreadBackgroundPriorityForIndexing);

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_LanguageKind(lua_State *L)
{
    oluacls_class<clangwrapper::LanguageKind>(L, "clang.LanguageKind");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "C", (lua_Integer)clangwrapper::LanguageKind::CXLanguage_C);
    oluacls_enum(L, "CPlusPlus", (lua_Integer)clangwrapper::LanguageKind::CXLanguage_CPlusPlus);
    oluacls_enum(L, "Invalid", (lua_Integer)clangwrapper::LanguageKind::CXLanguage_Invalid);
    oluacls_enum(L, "ObjC", (lua_Integer)clangwrapper::LanguageKind::CXLanguage_ObjC);

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_LinkageKind(lua_State *L)
{
    oluacls_class<clangwrapper::LinkageKind>(L, "clang.LinkageKind");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "External", (lua_Integer)clangwrapper::LinkageKind::CXLinkage_External);
    oluacls_enum(L, "Internal", (lua_Integer)clangwrapper::LinkageKind::CXLinkage_Internal);
    oluacls_enum(L, "Invalid", (lua_Integer)clangwrapper::LinkageKind::CXLinkage_Invalid);
    oluacls_enum(L, "NoLinkage", (lua_Integer)clangwrapper::LinkageKind::CXLinkage_NoLinkage);
    oluacls_enum(L, "UniqueExternal", (lua_Integer)clangwrapper::LinkageKind::CXLinkage_UniqueExternal);

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_RefQualifierKind(lua_State *L)
{
    oluacls_class<clangwrapper::RefQualifierKind>(L, "clang.RefQualifierKind");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "LValue", (lua_Integer)clangwrapper::RefQualifierKind::CXRefQualifier_LValue);
    oluacls_enum(L, "None", (lua_Integer)clangwrapper::RefQualifierKind::CXRefQualifier_None);
    oluacls_enum(L, "RValue", (lua_Integer)clangwrapper::RefQualifierKind::CXRefQualifier_RValue);

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_StorageClass(lua_State *L)
{
    oluacls_class<clangwrapper::StorageClass>(L, "clang.StorageClass");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "Auto", (lua_Integer)clangwrapper::StorageClass::CX_SC_Auto);
    oluacls_enum(L, "Extern", (lua_Integer)clangwrapper::StorageClass::CX_SC_Extern);
    oluacls_enum(L, "Invalid", (lua_Integer)clangwrapper::StorageClass::CX_SC_Invalid);
    oluacls_enum(L, "None", (lua_Integer)clangwrapper::StorageClass::CX_SC_None);
    oluacls_enum(L, "OpenCLWorkGroupLocal", (lua_Integer)clangwrapper::StorageClass::CX_SC_OpenCLWorkGroupLocal);
    oluacls_enum(L, "PrivateExtern", (lua_Integer)clangwrapper::StorageClass::CX_SC_PrivateExtern);
    oluacls_enum(L, "Register", (lua_Integer)clangwrapper::StorageClass::CX_SC_Register);
    oluacls_enum(L, "Static", (lua_Integer)clangwrapper::StorageClass::CX_SC_Static);

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_TemplateArgumentKind(lua_State *L)
{
    oluacls_class<clangwrapper::TemplateArgumentKind>(L, "clang.TemplateArgumentKind");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "Declaration", (lua_Integer)clangwrapper::TemplateArgumentKind::CXTemplateArgumentKind_Declaration);
    oluacls_enum(L, "Expression", (lua_Integer)clangwrapper::TemplateArgumentKind::CXTemplateArgumentKind_Expression);
    oluacls_enum(L, "Integral", (lua_Integer)clangwrapper::TemplateArgumentKind::CXTemplateArgumentKind_Integral);
    oluacls_enum(L, "Invalid", (lua_Integer)clangwrapper::TemplateArgumentKind::CXTemplateArgumentKind_Invalid);
    oluacls_enum(L, "Null", (lua_Integer)clangwrapper::TemplateArgumentKind::CXTemplateArgumentKind_Null);
    oluacls_enum(L, "NullPtr", (lua_Integer)clangwrapper::TemplateArgumentKind::CXTemplateArgumentKind_NullPtr);
    oluacls_enum(L, "Pack", (lua_Integer)clangwrapper::TemplateArgumentKind::CXTemplateArgumentKind_Pack);
    oluacls_enum(L, "Template", (lua_Integer)clangwrapper::TemplateArgumentKind::CXTemplateArgumentKind_Template);
    oluacls_enum(L, "TemplateExpansion", (lua_Integer)clangwrapper::TemplateArgumentKind::CXTemplateArgumentKind_TemplateExpansion);
    oluacls_enum(L, "Type", (lua_Integer)clangwrapper::TemplateArgumentKind::CXTemplateArgumentKind_Type);

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_TLSKind(lua_State *L)
{
    oluacls_class<clangwrapper::TLSKind>(L, "clang.TLSKind");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "Dynamic", (lua_Integer)clangwrapper::TLSKind::CXTLS_Dynamic);
    oluacls_enum(L, "None", (lua_Integer)clangwrapper::TLSKind::CXTLS_None);
    oluacls_enum(L, "Static", (lua_Integer)clangwrapper::TLSKind::CXTLS_Static);

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_TypeKind(lua_State *L)
{
    oluacls_class<clangwrapper::TypeKind>(L, "clang.TypeKind");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "Accum", (lua_Integer)clangwrapper::TypeKind::CXType_Accum);
    oluacls_enum(L, "Atomic", (lua_Integer)clangwrapper::TypeKind::CXType_Atomic);
    oluacls_enum(L, "Attributed", (lua_Integer)clangwrapper::TypeKind::CXType_Attributed);
    oluacls_enum(L, "Auto", (lua_Integer)clangwrapper::TypeKind::CXType_Auto);
    oluacls_enum(L, "BFloat16", (lua_Integer)clangwrapper::TypeKind::CXType_BFloat16);
    oluacls_enum(L, "BTFTagAttributed", (lua_Integer)clangwrapper::TypeKind::CXType_BTFTagAttributed);
    oluacls_enum(L, "BlockPointer", (lua_Integer)clangwrapper::TypeKind::CXType_BlockPointer);
    oluacls_enum(L, "Bool", (lua_Integer)clangwrapper::TypeKind::CXType_Bool);
    oluacls_enum(L, "Char16", (lua_Integer)clangwrapper::TypeKind::CXType_Char16);
    oluacls_enum(L, "Char32", (lua_Integer)clangwrapper::TypeKind::CXType_Char32);
    oluacls_enum(L, "Char_S", (lua_Integer)clangwrapper::TypeKind::CXType_Char_S);
    oluacls_enum(L, "Char_U", (lua_Integer)clangwrapper::TypeKind::CXType_Char_U);
    oluacls_enum(L, "Complex", (lua_Integer)clangwrapper::TypeKind::CXType_Complex);
    oluacls_enum(L, "ConstantArray", (lua_Integer)clangwrapper::TypeKind::CXType_ConstantArray);
    oluacls_enum(L, "Dependent", (lua_Integer)clangwrapper::TypeKind::CXType_Dependent);
    oluacls_enum(L, "DependentSizedArray", (lua_Integer)clangwrapper::TypeKind::CXType_DependentSizedArray);
    oluacls_enum(L, "Double", (lua_Integer)clangwrapper::TypeKind::CXType_Double);
    oluacls_enum(L, "Elaborated", (lua_Integer)clangwrapper::TypeKind::CXType_Elaborated);
    oluacls_enum(L, "Enum", (lua_Integer)clangwrapper::TypeKind::CXType_Enum);
    oluacls_enum(L, "ExtVector", (lua_Integer)clangwrapper::TypeKind::CXType_ExtVector);
    oluacls_enum(L, "FirstBuiltin", (lua_Integer)clangwrapper::TypeKind::CXType_FirstBuiltin);
    oluacls_enum(L, "Float", (lua_Integer)clangwrapper::TypeKind::CXType_Float);
    oluacls_enum(L, "Float128", (lua_Integer)clangwrapper::TypeKind::CXType_Float128);
    oluacls_enum(L, "Float16", (lua_Integer)clangwrapper::TypeKind::CXType_Float16);
    oluacls_enum(L, "FunctionNoProto", (lua_Integer)clangwrapper::TypeKind::CXType_FunctionNoProto);
    oluacls_enum(L, "FunctionProto", (lua_Integer)clangwrapper::TypeKind::CXType_FunctionProto);
    oluacls_enum(L, "HLSLResource", (lua_Integer)clangwrapper::TypeKind::CXType_HLSLResource);
    oluacls_enum(L, "Half", (lua_Integer)clangwrapper::TypeKind::CXType_Half);
    oluacls_enum(L, "Ibm128", (lua_Integer)clangwrapper::TypeKind::CXType_Ibm128);
    oluacls_enum(L, "IncompleteArray", (lua_Integer)clangwrapper::TypeKind::CXType_IncompleteArray);
    oluacls_enum(L, "Int", (lua_Integer)clangwrapper::TypeKind::CXType_Int);
    oluacls_enum(L, "Int128", (lua_Integer)clangwrapper::TypeKind::CXType_Int128);
    oluacls_enum(L, "Invalid", (lua_Integer)clangwrapper::TypeKind::CXType_Invalid);
    oluacls_enum(L, "LValueReference", (lua_Integer)clangwrapper::TypeKind::CXType_LValueReference);
    oluacls_enum(L, "LastBuiltin", (lua_Integer)clangwrapper::TypeKind::CXType_LastBuiltin);
    oluacls_enum(L, "Long", (lua_Integer)clangwrapper::TypeKind::CXType_Long);
    oluacls_enum(L, "LongAccum", (lua_Integer)clangwrapper::TypeKind::CXType_LongAccum);
    oluacls_enum(L, "LongDouble", (lua_Integer)clangwrapper::TypeKind::CXType_LongDouble);
    oluacls_enum(L, "LongLong", (lua_Integer)clangwrapper::TypeKind::CXType_LongLong);
    oluacls_enum(L, "MemberPointer", (lua_Integer)clangwrapper::TypeKind::CXType_MemberPointer);
    oluacls_enum(L, "NullPtr", (lua_Integer)clangwrapper::TypeKind::CXType_NullPtr);
    oluacls_enum(L, "OCLEvent", (lua_Integer)clangwrapper::TypeKind::CXType_OCLEvent);
    oluacls_enum(L, "OCLImage1dArrayRO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage1dArrayRO);
    oluacls_enum(L, "OCLImage1dArrayRW", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage1dArrayRW);
    oluacls_enum(L, "OCLImage1dArrayWO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage1dArrayWO);
    oluacls_enum(L, "OCLImage1dBufferRO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage1dBufferRO);
    oluacls_enum(L, "OCLImage1dBufferRW", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage1dBufferRW);
    oluacls_enum(L, "OCLImage1dBufferWO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage1dBufferWO);
    oluacls_enum(L, "OCLImage1dRO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage1dRO);
    oluacls_enum(L, "OCLImage1dRW", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage1dRW);
    oluacls_enum(L, "OCLImage1dWO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage1dWO);
    oluacls_enum(L, "OCLImage2dArrayDepthRO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dArrayDepthRO);
    oluacls_enum(L, "OCLImage2dArrayDepthRW", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dArrayDepthRW);
    oluacls_enum(L, "OCLImage2dArrayDepthWO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dArrayDepthWO);
    oluacls_enum(L, "OCLImage2dArrayMSAADepthRO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dArrayMSAADepthRO);
    oluacls_enum(L, "OCLImage2dArrayMSAADepthRW", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dArrayMSAADepthRW);
    oluacls_enum(L, "OCLImage2dArrayMSAADepthWO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dArrayMSAADepthWO);
    oluacls_enum(L, "OCLImage2dArrayMSAARO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dArrayMSAARO);
    oluacls_enum(L, "OCLImage2dArrayMSAARW", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dArrayMSAARW);
    oluacls_enum(L, "OCLImage2dArrayMSAAWO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dArrayMSAAWO);
    oluacls_enum(L, "OCLImage2dArrayRO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dArrayRO);
    oluacls_enum(L, "OCLImage2dArrayRW", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dArrayRW);
    oluacls_enum(L, "OCLImage2dArrayWO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dArrayWO);
    oluacls_enum(L, "OCLImage2dDepthRO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dDepthRO);
    oluacls_enum(L, "OCLImage2dDepthRW", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dDepthRW);
    oluacls_enum(L, "OCLImage2dDepthWO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dDepthWO);
    oluacls_enum(L, "OCLImage2dMSAADepthRO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dMSAADepthRO);
    oluacls_enum(L, "OCLImage2dMSAADepthRW", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dMSAADepthRW);
    oluacls_enum(L, "OCLImage2dMSAADepthWO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dMSAADepthWO);
    oluacls_enum(L, "OCLImage2dMSAARO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dMSAARO);
    oluacls_enum(L, "OCLImage2dMSAARW", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dMSAARW);
    oluacls_enum(L, "OCLImage2dMSAAWO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dMSAAWO);
    oluacls_enum(L, "OCLImage2dRO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dRO);
    oluacls_enum(L, "OCLImage2dRW", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dRW);
    oluacls_enum(L, "OCLImage2dWO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage2dWO);
    oluacls_enum(L, "OCLImage3dRO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage3dRO);
    oluacls_enum(L, "OCLImage3dRW", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage3dRW);
    oluacls_enum(L, "OCLImage3dWO", (lua_Integer)clangwrapper::TypeKind::CXType_OCLImage3dWO);
    oluacls_enum(L, "OCLIntelSubgroupAVCImeDualRefStreamin", (lua_Integer)clangwrapper::TypeKind::CXType_OCLIntelSubgroupAVCImeDualRefStreamin);
    oluacls_enum(L, "OCLIntelSubgroupAVCImeDualReferenceStreamin", (lua_Integer)clangwrapper::TypeKind::CXType_OCLIntelSubgroupAVCImeDualReferenceStreamin);
    oluacls_enum(L, "OCLIntelSubgroupAVCImePayload", (lua_Integer)clangwrapper::TypeKind::CXType_OCLIntelSubgroupAVCImePayload);
    oluacls_enum(L, "OCLIntelSubgroupAVCImeResult", (lua_Integer)clangwrapper::TypeKind::CXType_OCLIntelSubgroupAVCImeResult);
    oluacls_enum(L, "OCLIntelSubgroupAVCImeResultDualRefStreamout", (lua_Integer)clangwrapper::TypeKind::CXType_OCLIntelSubgroupAVCImeResultDualRefStreamout);
    oluacls_enum(L, "OCLIntelSubgroupAVCImeResultDualReferenceStreamout", (lua_Integer)clangwrapper::TypeKind::CXType_OCLIntelSubgroupAVCImeResultDualReferenceStreamout);
    oluacls_enum(L, "OCLIntelSubgroupAVCImeResultSingleRefStreamout", (lua_Integer)clangwrapper::TypeKind::CXType_OCLIntelSubgroupAVCImeResultSingleRefStreamout);
    oluacls_enum(L, "OCLIntelSubgroupAVCImeResultSingleReferenceStreamout", (lua_Integer)clangwrapper::TypeKind::CXType_OCLIntelSubgroupAVCImeResultSingleReferenceStreamout);
    oluacls_enum(L, "OCLIntelSubgroupAVCImeSingleRefStreamin", (lua_Integer)clangwrapper::TypeKind::CXType_OCLIntelSubgroupAVCImeSingleRefStreamin);
    oluacls_enum(L, "OCLIntelSubgroupAVCImeSingleReferenceStreamin", (lua_Integer)clangwrapper::TypeKind::CXType_OCLIntelSubgroupAVCImeSingleReferenceStreamin);
    oluacls_enum(L, "OCLIntelSubgroupAVCMcePayload", (lua_Integer)clangwrapper::TypeKind::CXType_OCLIntelSubgroupAVCMcePayload);
    oluacls_enum(L, "OCLIntelSubgroupAVCMceResult", (lua_Integer)clangwrapper::TypeKind::CXType_OCLIntelSubgroupAVCMceResult);
    oluacls_enum(L, "OCLIntelSubgroupAVCRefPayload", (lua_Integer)clangwrapper::TypeKind::CXType_OCLIntelSubgroupAVCRefPayload);
    oluacls_enum(L, "OCLIntelSubgroupAVCRefResult", (lua_Integer)clangwrapper::TypeKind::CXType_OCLIntelSubgroupAVCRefResult);
    oluacls_enum(L, "OCLIntelSubgroupAVCSicPayload", (lua_Integer)clangwrapper::TypeKind::CXType_OCLIntelSubgroupAVCSicPayload);
    oluacls_enum(L, "OCLIntelSubgroupAVCSicResult", (lua_Integer)clangwrapper::TypeKind::CXType_OCLIntelSubgroupAVCSicResult);
    oluacls_enum(L, "OCLQueue", (lua_Integer)clangwrapper::TypeKind::CXType_OCLQueue);
    oluacls_enum(L, "OCLReserveID", (lua_Integer)clangwrapper::TypeKind::CXType_OCLReserveID);
    oluacls_enum(L, "OCLSampler", (lua_Integer)clangwrapper::TypeKind::CXType_OCLSampler);
    oluacls_enum(L, "ObjCClass", (lua_Integer)clangwrapper::TypeKind::CXType_ObjCClass);
    oluacls_enum(L, "ObjCId", (lua_Integer)clangwrapper::TypeKind::CXType_ObjCId);
    oluacls_enum(L, "ObjCInterface", (lua_Integer)clangwrapper::TypeKind::CXType_ObjCInterface);
    oluacls_enum(L, "ObjCObject", (lua_Integer)clangwrapper::TypeKind::CXType_ObjCObject);
    oluacls_enum(L, "ObjCObjectPointer", (lua_Integer)clangwrapper::TypeKind::CXType_ObjCObjectPointer);
    oluacls_enum(L, "ObjCSel", (lua_Integer)clangwrapper::TypeKind::CXType_ObjCSel);
    oluacls_enum(L, "ObjCTypeParam", (lua_Integer)clangwrapper::TypeKind::CXType_ObjCTypeParam);
    oluacls_enum(L, "Overload", (lua_Integer)clangwrapper::TypeKind::CXType_Overload);
    oluacls_enum(L, "Pipe", (lua_Integer)clangwrapper::TypeKind::CXType_Pipe);
    oluacls_enum(L, "Pointer", (lua_Integer)clangwrapper::TypeKind::CXType_Pointer);
    oluacls_enum(L, "RValueReference", (lua_Integer)clangwrapper::TypeKind::CXType_RValueReference);
    oluacls_enum(L, "Record", (lua_Integer)clangwrapper::TypeKind::CXType_Record);
    oluacls_enum(L, "SChar", (lua_Integer)clangwrapper::TypeKind::CXType_SChar);
    oluacls_enum(L, "Short", (lua_Integer)clangwrapper::TypeKind::CXType_Short);
    oluacls_enum(L, "ShortAccum", (lua_Integer)clangwrapper::TypeKind::CXType_ShortAccum);
    oluacls_enum(L, "Typedef", (lua_Integer)clangwrapper::TypeKind::CXType_Typedef);
    oluacls_enum(L, "UAccum", (lua_Integer)clangwrapper::TypeKind::CXType_UAccum);
    oluacls_enum(L, "UChar", (lua_Integer)clangwrapper::TypeKind::CXType_UChar);
    oluacls_enum(L, "UInt", (lua_Integer)clangwrapper::TypeKind::CXType_UInt);
    oluacls_enum(L, "UInt128", (lua_Integer)clangwrapper::TypeKind::CXType_UInt128);
    oluacls_enum(L, "ULong", (lua_Integer)clangwrapper::TypeKind::CXType_ULong);
    oluacls_enum(L, "ULongAccum", (lua_Integer)clangwrapper::TypeKind::CXType_ULongAccum);
    oluacls_enum(L, "ULongLong", (lua_Integer)clangwrapper::TypeKind::CXType_ULongLong);
    oluacls_enum(L, "UShort", (lua_Integer)clangwrapper::TypeKind::CXType_UShort);
    oluacls_enum(L, "UShortAccum", (lua_Integer)clangwrapper::TypeKind::CXType_UShortAccum);
    oluacls_enum(L, "Unexposed", (lua_Integer)clangwrapper::TypeKind::CXType_Unexposed);
    oluacls_enum(L, "VariableArray", (lua_Integer)clangwrapper::TypeKind::CXType_VariableArray);
    oluacls_enum(L, "Vector", (lua_Integer)clangwrapper::TypeKind::CXType_Vector);
    oluacls_enum(L, "Void", (lua_Integer)clangwrapper::TypeKind::CXType_Void);
    oluacls_enum(L, "WChar", (lua_Integer)clangwrapper::TypeKind::CXType_WChar);

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_TypeNullabilityKind(lua_State *L)
{
    oluacls_class<clangwrapper::TypeNullabilityKind>(L, "clang.TypeNullabilityKind");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "Invalid", (lua_Integer)clangwrapper::TypeNullabilityKind::CXTypeNullability_Invalid);
    oluacls_enum(L, "NonNull", (lua_Integer)clangwrapper::TypeNullabilityKind::CXTypeNullability_NonNull);
    oluacls_enum(L, "Nullable", (lua_Integer)clangwrapper::TypeNullabilityKind::CXTypeNullability_Nullable);
    oluacls_enum(L, "NullableResult", (lua_Integer)clangwrapper::TypeNullabilityKind::CXTypeNullability_NullableResult);
    oluacls_enum(L, "Unspecified", (lua_Integer)clangwrapper::TypeNullabilityKind::CXTypeNullability_Unspecified);

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_VisibilityKind(lua_State *L)
{
    oluacls_class<clangwrapper::VisibilityKind>(L, "clang.VisibilityKind");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "Default", (lua_Integer)clangwrapper::VisibilityKind::CXVisibility_Default);
    oluacls_enum(L, "Hidden", (lua_Integer)clangwrapper::VisibilityKind::CXVisibility_Hidden);
    oluacls_enum(L, "Invalid", (lua_Integer)clangwrapper::VisibilityKind::CXVisibility_Invalid);
    oluacls_enum(L, "Protected", (lua_Integer)clangwrapper::VisibilityKind::CXVisibility_Protected);

    return 1;
}
OLUA_END_DECLS

static int _clangwrapper_Diagnostic_as(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Diagnostic *self = nullptr;
    const char *arg1 = nullptr;       /** cls */

    olua_to_object(L, 1, &self, "clang.Diagnostic");
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

static int _clangwrapper_Diagnostic_category(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Diagnostic *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Diagnostic");

    // @getter unsigned int category()
    unsigned int ret = self->category();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Diagnostic_categoryText(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Diagnostic *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Diagnostic");

    // @getter clangwrapper::string categoryText()
    clangwrapper::string ret = self->categoryText();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Diagnostic_formatDiagnostic(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Diagnostic *self = nullptr;
    unsigned int arg1 = 0;       /** options */

    olua_to_object(L, 1, &self, "clang.Diagnostic");
    olua_check_integer(L, 2, &arg1);

    // clangwrapper::string formatDiagnostic(unsigned int options)
    clangwrapper::string ret = self->formatDiagnostic(arg1);
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Diagnostic_name(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Diagnostic *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Diagnostic");

    // @getter clangwrapper::string name()
    clangwrapper::string ret = self->name();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Diagnostic_severity(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Diagnostic *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Diagnostic");

    // @getter clangwrapper::DiagnosticSeverity severity()
    clangwrapper::DiagnosticSeverity ret = self->severity();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Diagnostic_severitySeplling(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Diagnostic *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Diagnostic");

    // @getter clangwrapper::string severitySeplling()
    clangwrapper::string ret = self->severitySeplling();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Diagnostic_shared_from_this(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Diagnostic *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Diagnostic");

    // @copyfrom(std::enable_shared_from_this) std::shared_ptr<clangwrapper::Diagnostic> shared_from_this()
    std::shared_ptr<clangwrapper::Diagnostic> ret = self->shared_from_this();
    int num_ret = olua_push_object(L, &ret, "clang.Diagnostic");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Diagnostic_text(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Diagnostic *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Diagnostic");

    // @getter clangwrapper::string text()
    clangwrapper::string ret = self->text();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_Diagnostic(lua_State *L)
{
    oluacls_class<clangwrapper::Diagnostic, clangwrapper::IndexError>(L, "clang.Diagnostic");
    oluacls_func(L, "as", _clangwrapper_Diagnostic_as);
    oluacls_func(L, "formatDiagnostic", _clangwrapper_Diagnostic_formatDiagnostic);
    oluacls_func(L, "shared_from_this", _clangwrapper_Diagnostic_shared_from_this);
    oluacls_prop(L, "category", _clangwrapper_Diagnostic_category, nullptr);
    oluacls_prop(L, "categoryText", _clangwrapper_Diagnostic_categoryText, nullptr);
    oluacls_prop(L, "name", _clangwrapper_Diagnostic_name, nullptr);
    oluacls_prop(L, "severity", _clangwrapper_Diagnostic_severity, nullptr);
    oluacls_prop(L, "severitySeplling", _clangwrapper_Diagnostic_severitySeplling, nullptr);
    oluacls_prop(L, "text", _clangwrapper_Diagnostic_text, nullptr);

    return 1;
}
OLUA_END_DECLS

static int _clangwrapper_File___eq(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::File *self = nullptr;
    clangwrapper::File *arg2 = nullptr;       /** f */

    olua_to_object(L, 1, &self, "clang.File");
    olua_check_object(L, 2, &arg2, "clang.File");

    // olua_Return __eq(lua_State *L, clangwrapper::File *f)
    olua_Return ret = self->__eq(L, arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _clangwrapper_File_as(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::File *self = nullptr;
    const char *arg1 = nullptr;       /** cls */

    olua_to_object(L, 1, &self, "clang.File");
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

static int _clangwrapper_File_fileName(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::File *self = nullptr;

    olua_to_object(L, 1, &self, "clang.File");

    // @getter clangwrapper::string fileName()
    clangwrapper::string ret = self->fileName();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_File_fileTime(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::File *self = nullptr;

    olua_to_object(L, 1, &self, "clang.File");

    // @getter time_t fileTime()
    time_t ret = self->fileTime();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_File_shared_from_this(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::File *self = nullptr;

    olua_to_object(L, 1, &self, "clang.File");

    // @copyfrom(std::enable_shared_from_this) std::shared_ptr<clangwrapper::File> shared_from_this()
    std::shared_ptr<clangwrapper::File> ret = self->shared_from_this();
    int num_ret = olua_push_object(L, &ret, "clang.File");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_File_tryGetRealPathName(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::File *self = nullptr;

    olua_to_object(L, 1, &self, "clang.File");

    // clangwrapper::string tryGetRealPathName()
    clangwrapper::string ret = self->tryGetRealPathName();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_File(lua_State *L)
{
    oluacls_class<clangwrapper::File, clangwrapper::IndexError>(L, "clang.File");
    oluacls_func(L, "__eq", _clangwrapper_File___eq);
    oluacls_func(L, "as", _clangwrapper_File_as);
    oluacls_func(L, "shared_from_this", _clangwrapper_File_shared_from_this);
    oluacls_func(L, "tryGetRealPathName", _clangwrapper_File_tryGetRealPathName);
    oluacls_prop(L, "fileName", _clangwrapper_File_fileName, nullptr);
    oluacls_prop(L, "fileTime", _clangwrapper_File_fileTime, nullptr);

    return 1;
}
OLUA_END_DECLS

static int _clangwrapper_Type___eq(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;
    clangwrapper::Type *arg2 = nullptr;       /** t */

    olua_to_object(L, 1, &self, "clang.Type");
    olua_check_object(L, 2, &arg2, "clang.Type");

    // olua_Return __eq(lua_State *L, clangwrapper::Type *t)
    olua_Return ret = self->__eq(L, arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _clangwrapper_Type_addressSpace(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Type");

    // @getter unsigned int addressSpace()
    unsigned int ret = self->addressSpace();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_alignOf(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Type");

    // @getter long long alignOf()
    long long ret = self->alignOf();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_argTypes(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Type");

    // @getter std::vector<std::shared_ptr<clangwrapper::Type>> argTypes()
    std::vector<std::shared_ptr<clangwrapper::Type>> ret = self->argTypes();
    int num_ret = olua_push_array<std::shared_ptr<clangwrapper::Type>>(L, ret, [L](std::shared_ptr<clangwrapper::Type> &arg1) {
        olua_push_object(L, &arg1, "clang.Type");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_arrayElementType(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Type");

    // @getter std::shared_ptr<clangwrapper::Type> arrayElementType()
    std::shared_ptr<clangwrapper::Type> ret = self->arrayElementType();
    int num_ret = olua_push_object(L, &ret, "clang.Type");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_arraySize(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Type");

    // @getter long long arraySize()
    long long ret = self->arraySize();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_as(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;
    const char *arg1 = nullptr;       /** cls */

    olua_to_object(L, 1, &self, "clang.Type");
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

static int _clangwrapper_Type_canonicalType(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Type");

    // @getter std::shared_ptr<clangwrapper::Type> canonicalType()
    std::shared_ptr<clangwrapper::Type> ret = self->canonicalType();
    int num_ret = olua_push_object(L, &ret, "clang.Type");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_classType(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Type");

    // @getter std::shared_ptr<clangwrapper::Type> classType()
    std::shared_ptr<clangwrapper::Type> ret = self->classType();
    int num_ret = olua_push_object(L, &ret, "clang.Type");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_cxxRefQualifier(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Type");

    // @getter clangwrapper::RefQualifierKind cxxRefQualifier()
    clangwrapper::RefQualifierKind ret = self->cxxRefQualifier();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_cxxRefQualifierSpelling(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Type");

    // @getter clangwrapper::string cxxRefQualifierSpelling()
    clangwrapper::string ret = self->cxxRefQualifierSpelling();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_declaration(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Type");

    // @getter std::shared_ptr<clangwrapper::Cursor> declaration()
    std::shared_ptr<clangwrapper::Cursor> ret = self->declaration();
    int num_ret = olua_push_object(L, &ret, "clang.Cursor");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_elementType(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Type");

    // @getter std::shared_ptr<clangwrapper::Type> elementType()
    std::shared_ptr<clangwrapper::Type> ret = self->elementType();
    int num_ret = olua_push_object(L, &ret, "clang.Type");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_exceptionSpecificationType(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Type");

    // @getter int exceptionSpecificationType()
    int ret = self->exceptionSpecificationType();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_fields(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Type");

    // @getter std::vector<std::shared_ptr<clangwrapper::Cursor>> fields()
    std::vector<std::shared_ptr<clangwrapper::Cursor>> ret = self->fields();
    int num_ret = olua_push_array<std::shared_ptr<clangwrapper::Cursor>>(L, ret, [L](std::shared_ptr<clangwrapper::Cursor> &arg1) {
        olua_push_object(L, &arg1, "clang.Cursor");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_functionTypeCallingConv(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Type");

    // @getter clangwrapper::CallingConv functionTypeCallingConv()
    clangwrapper::CallingConv ret = self->functionTypeCallingConv();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_getArgType(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;
    unsigned int arg1 = 0;       /** i */

    olua_to_object(L, 1, &self, "clang.Type");
    olua_check_integer(L, 2, &arg1);

    // std::shared_ptr<clangwrapper::Type> getArgType(unsigned int i)
    std::shared_ptr<clangwrapper::Type> ret = self->getArgType(arg1);
    int num_ret = olua_push_object(L, &ret, "clang.Type");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_getTemplateArgument(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;
    unsigned int arg1 = 0;       /** i */

    olua_to_object(L, 1, &self, "clang.Type");
    olua_check_integer(L, 2, &arg1);

    // std::shared_ptr<clangwrapper::Type> getTemplateArgument(unsigned int i)
    std::shared_ptr<clangwrapper::Type> ret = self->getTemplateArgument(arg1);
    int num_ret = olua_push_object(L, &ret, "clang.Type");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_isConstQualified(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Type");

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

    olua_to_object(L, 1, &self, "clang.Type");

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

    olua_to_object(L, 1, &self, "clang.Type");

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

    olua_to_object(L, 1, &self, "clang.Type");

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

    olua_to_object(L, 1, &self, "clang.Type");

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

    olua_to_object(L, 1, &self, "clang.Type");

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

    olua_to_object(L, 1, &self, "clang.Type");

    // @getter clangwrapper::TypeKind kind()
    clangwrapper::TypeKind ret = self->kind();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_kindSpelling(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Type");

    // @getter clangwrapper::string kindSpelling()
    clangwrapper::string ret = self->kindSpelling();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_modifiedType(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Type");

    // @getter std::shared_ptr<clangwrapper::Type> modifiedType()
    std::shared_ptr<clangwrapper::Type> ret = self->modifiedType();
    int num_ret = olua_push_object(L, &ret, "clang.Type");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_name(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Type");

    // @getter clangwrapper::string name()
    clangwrapper::string ret = self->name();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_namedType(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Type");

    // @getter std::shared_ptr<clangwrapper::Type> namedType()
    std::shared_ptr<clangwrapper::Type> ret = self->namedType();
    int num_ret = olua_push_object(L, &ret, "clang.Type");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_nonReferenceType(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Type");

    // @getter std::shared_ptr<clangwrapper::Type> nonReferenceType()
    std::shared_ptr<clangwrapper::Type> ret = self->nonReferenceType();
    int num_ret = olua_push_object(L, &ret, "clang.Type");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_nullability(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Type");

    // @getter clangwrapper::TypeNullabilityKind nullability()
    clangwrapper::TypeNullabilityKind ret = self->nullability();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_nullabilitySpelling(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Type");

    // @getter clangwrapper::string nullabilitySpelling()
    clangwrapper::string ret = self->nullabilitySpelling();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_numElements(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Type");

    // @getter long long numElements()
    long long ret = self->numElements();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_offsetOf(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;
    const char *arg1 = nullptr;       /** field */

    olua_to_object(L, 1, &self, "clang.Type");
    olua_check_string(L, 2, &arg1);

    // long long offsetOf(const char *field)
    long long ret = self->offsetOf(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_pointeeType(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Type");

    // @getter std::shared_ptr<clangwrapper::Type> pointeeType()
    std::shared_ptr<clangwrapper::Type> ret = self->pointeeType();
    int num_ret = olua_push_object(L, &ret, "clang.Type");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_resultType(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Type");

    // @getter std::shared_ptr<clangwrapper::Type> resultType()
    std::shared_ptr<clangwrapper::Type> ret = self->resultType();
    int num_ret = olua_push_object(L, &ret, "clang.Type");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_shared_from_this(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Type");

    // @copyfrom(std::enable_shared_from_this) std::shared_ptr<clangwrapper::Type> shared_from_this()
    std::shared_ptr<clangwrapper::Type> ret = self->shared_from_this();
    int num_ret = olua_push_object(L, &ret, "clang.Type");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_sizeOf(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Type");

    // @getter long long sizeOf()
    long long ret = self->sizeOf();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_templateArgumentTypes(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Type");

    // @getter std::vector<std::shared_ptr<clangwrapper::Type>> templateArgumentTypes()
    std::vector<std::shared_ptr<clangwrapper::Type>> ret = self->templateArgumentTypes();
    int num_ret = olua_push_array<std::shared_ptr<clangwrapper::Type>>(L, ret, [L](std::shared_ptr<clangwrapper::Type> &arg1) {
        olua_push_object(L, &arg1, "clang.Type");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_typedefName(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Type");

    // @getter clangwrapper::string typedefName()
    clangwrapper::string ret = self->typedefName();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_unqualifiedType(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Type");

    // @getter std::shared_ptr<clangwrapper::Type> unqualifiedType()
    std::shared_ptr<clangwrapper::Type> ret = self->unqualifiedType();
    int num_ret = olua_push_object(L, &ret, "clang.Type");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Type_valueType(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Type *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Type");

    // @getter std::shared_ptr<clangwrapper::Type> valueType()
    std::shared_ptr<clangwrapper::Type> ret = self->valueType();
    int num_ret = olua_push_object(L, &ret, "clang.Type");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_Type(lua_State *L)
{
    oluacls_class<clangwrapper::Type, clangwrapper::IndexError>(L, "clang.Type");
    oluacls_func(L, "__eq", _clangwrapper_Type___eq);
    oluacls_func(L, "as", _clangwrapper_Type_as);
    oluacls_func(L, "getArgType", _clangwrapper_Type_getArgType);
    oluacls_func(L, "getTemplateArgument", _clangwrapper_Type_getTemplateArgument);
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
    oluacls_prop(L, "namedType", _clangwrapper_Type_namedType, nullptr);
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

    return 1;
}
OLUA_END_DECLS

static int _clangwrapper_Cursor___eq(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;
    clangwrapper::Cursor *arg2 = nullptr;       /** c */

    olua_to_object(L, 1, &self, "clang.Cursor");
    olua_check_object(L, 2, &arg2, "clang.Cursor");

    // olua_Return __eq(lua_State *L, clangwrapper::Cursor *c)
    olua_Return ret = self->__eq(L, arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _clangwrapper_Cursor_arguments(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter std::vector<std::shared_ptr<clangwrapper::Cursor>> arguments()
    std::vector<std::shared_ptr<clangwrapper::Cursor>> ret = self->arguments();
    int num_ret = olua_push_array<std::shared_ptr<clangwrapper::Cursor>>(L, ret, [L](std::shared_ptr<clangwrapper::Cursor> &arg1) {
        olua_push_object(L, &arg1, "clang.Cursor");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_as(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;
    const char *arg1 = nullptr;       /** cls */

    olua_to_object(L, 1, &self, "clang.Cursor");
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

static int _clangwrapper_Cursor_availability(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter clangwrapper::AvailabilityKind availability()
    clangwrapper::AvailabilityKind ret = self->availability();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_briefCommentText(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter clangwrapper::string briefCommentText()
    clangwrapper::string ret = self->briefCommentText();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_canonical(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter std::shared_ptr<clangwrapper::Cursor> canonical()
    std::shared_ptr<clangwrapper::Cursor> ret = self->canonical();
    int num_ret = olua_push_object(L, &ret, "clang.Cursor");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_children(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter std::vector<std::shared_ptr<clangwrapper::Cursor>> children()
    std::vector<std::shared_ptr<clangwrapper::Cursor>> ret = self->children();
    int num_ret = olua_push_array<std::shared_ptr<clangwrapper::Cursor>>(L, ret, [L](std::shared_ptr<clangwrapper::Cursor> &arg1) {
        olua_push_object(L, &arg1, "clang.Cursor");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_commentRange(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter clangwrapper::Cursor::SourceRange commentRange()
    clangwrapper::Cursor::SourceRange ret = self->commentRange();
    int num_ret = olua_pushcopy_object(L, ret, "clang.Cursor.SourceRange");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_cxxAccessSpecifier(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter clangwrapper::CXXAccessSpecifier cxxAccessSpecifier()
    clangwrapper::CXXAccessSpecifier ret = self->cxxAccessSpecifier();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_cxxAccessSpecifierSpelling(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter clangwrapper::string cxxAccessSpecifierSpelling()
    clangwrapper::string ret = self->cxxAccessSpecifierSpelling();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_cxxManglings(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter std::vector<clangwrapper::string> cxxManglings()
    std::vector<clangwrapper::string> ret = self->cxxManglings();
    int num_ret = olua_push_array<clangwrapper::string>(L, ret, [L](clangwrapper::string &arg1) {
        olua_push_string(L, arg1);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_definition(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter std::shared_ptr<clangwrapper::Cursor> definition()
    std::shared_ptr<clangwrapper::Cursor> ret = self->definition();
    int num_ret = olua_push_object(L, &ret, "clang.Cursor");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_displayName(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter clangwrapper::string displayName()
    clangwrapper::string ret = self->displayName();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_enumConstantDeclUnsignedValue(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter unsigned long long enumConstantDeclUnsignedValue()
    unsigned long long ret = self->enumConstantDeclUnsignedValue();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_enumConstantDeclValue(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter long long enumConstantDeclValue()
    long long ret = self->enumConstantDeclValue();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_enumDeclIntegerType(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter std::shared_ptr<clangwrapper::Type> enumDeclIntegerType()
    std::shared_ptr<clangwrapper::Type> ret = self->enumDeclIntegerType();
    int num_ret = olua_push_object(L, &ret, "clang.Type");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_exceptionSpecificationType(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter int exceptionSpecificationType()
    int ret = self->exceptionSpecificationType();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_fieldDeclBitWidth(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter int fieldDeclBitWidth()
    int ret = self->fieldDeclBitWidth();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_getModule(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // std::shared_ptr<clangwrapper::Module> getModule()
    std::shared_ptr<clangwrapper::Module> ret = self->getModule();
    int num_ret = olua_push_object(L, &ret, "clang.Module");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_hasAttrs(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

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

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter int hasVarDeclExternalStorage()
    int ret = self->hasVarDeclExternalStorage();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_hasVarDeclGlobalStorage(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter int hasVarDeclGlobalStorage()
    int ret = self->hasVarDeclGlobalStorage();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_hashCursor(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // unsigned int hashCursor()
    unsigned int ret = self->hashCursor();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_ibOutletCollectionType(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter std::shared_ptr<clangwrapper::Type> ibOutletCollectionType()
    std::shared_ptr<clangwrapper::Type> ret = self->ibOutletCollectionType();
    int num_ret = olua_push_object(L, &ret, "clang.Type");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_includedFile(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter std::shared_ptr<clangwrapper::File> includedFile()
    std::shared_ptr<clangwrapper::File> ret = self->includedFile();
    int num_ret = olua_push_object(L, &ret, "clang.File");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isAnonymous(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

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

    olua_to_object(L, 1, &self, "clang.Cursor");

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

    olua_to_object(L, 1, &self, "clang.Cursor");

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

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter bool isBitField()
    bool ret = self->isBitField();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isCXXAbstract(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter bool isCXXAbstract()
    bool ret = self->isCXXAbstract();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isCXXConvertingConstructor(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

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

    olua_to_object(L, 1, &self, "clang.Cursor");

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

    olua_to_object(L, 1, &self, "clang.Cursor");

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

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter bool isCXXFieldMutable()
    bool ret = self->isCXXFieldMutable();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isCXXMethodConst(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter bool isCXXMethodConst()
    bool ret = self->isCXXMethodConst();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isCXXMethodCopyAssignmentOperator(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter bool isCXXMethodCopyAssignmentOperator()
    bool ret = self->isCXXMethodCopyAssignmentOperator();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isCXXMethodDefaulted(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter bool isCXXMethodDefaulted()
    bool ret = self->isCXXMethodDefaulted();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isCXXMethodDeleted(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter bool isCXXMethodDeleted()
    bool ret = self->isCXXMethodDeleted();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isCXXMethodExplicit(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter bool isCXXMethodExplicit()
    bool ret = self->isCXXMethodExplicit();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isCXXMethodMoveAssignmentOperator(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter bool isCXXMethodMoveAssignmentOperator()
    bool ret = self->isCXXMethodMoveAssignmentOperator();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isCXXMethodPureVirtual(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter bool isCXXMethodPureVirtual()
    bool ret = self->isCXXMethodPureVirtual();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isCXXMethodStatic(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter bool isCXXMethodStatic()
    bool ret = self->isCXXMethodStatic();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isCXXMethodVirtual(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter bool isCXXMethodVirtual()
    bool ret = self->isCXXMethodVirtual();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isCXXMoveConstructor(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

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

    olua_to_object(L, 1, &self, "clang.Cursor");

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

    olua_to_object(L, 1, &self, "clang.Cursor");

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

    olua_to_object(L, 1, &self, "clang.Cursor");

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

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter int isDynamicCall()
    int ret = self->isDynamicCall();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_isEnumDeclScoped(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

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

    olua_to_object(L, 1, &self, "clang.Cursor");

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

    olua_to_object(L, 1, &self, "clang.Cursor");

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

    olua_to_object(L, 1, &self, "clang.Cursor");

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

    olua_to_object(L, 1, &self, "clang.Cursor");

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

    olua_to_object(L, 1, &self, "clang.Cursor");

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

    olua_to_object(L, 1, &self, "clang.Cursor");

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

    olua_to_object(L, 1, &self, "clang.Cursor");

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

    olua_to_object(L, 1, &self, "clang.Cursor");

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

    olua_to_object(L, 1, &self, "clang.Cursor");

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

    olua_to_object(L, 1, &self, "clang.Cursor");

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

    olua_to_object(L, 1, &self, "clang.Cursor");

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

    olua_to_object(L, 1, &self, "clang.Cursor");

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

    olua_to_object(L, 1, &self, "clang.Cursor");

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

    olua_to_object(L, 1, &self, "clang.Cursor");

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

    olua_to_object(L, 1, &self, "clang.Cursor");

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

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter clangwrapper::CursorKind kind()
    clangwrapper::CursorKind ret = self->kind();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_kindSpelling(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter clangwrapper::string kindSpelling()
    clangwrapper::string ret = self->kindSpelling();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_language(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter clangwrapper::LanguageKind language()
    clangwrapper::LanguageKind ret = self->language();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_lexicalParent(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter std::shared_ptr<clangwrapper::Cursor> lexicalParent()
    std::shared_ptr<clangwrapper::Cursor> ret = self->lexicalParent();
    int num_ret = olua_push_object(L, &ret, "clang.Cursor");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_linkage(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter clangwrapper::LinkageKind linkage()
    clangwrapper::LinkageKind ret = self->linkage();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_mangling(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter clangwrapper::string mangling()
    clangwrapper::string ret = self->mangling();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_name(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter clangwrapper::string name()
    clangwrapper::string ret = self->name();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_nameRange(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;
    unsigned int arg1 = 0;       /** pieceIndex */
    unsigned int arg2 = 0;       /** options */

    olua_to_object(L, 1, &self, "clang.Cursor");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // clangwrapper::Cursor::SourceRange nameRange(unsigned int pieceIndex, unsigned int options)
    clangwrapper::Cursor::SourceRange ret = self->nameRange(arg1, arg2);
    int num_ret = olua_pushcopy_object(L, ret, "clang.Cursor.SourceRange");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_offsetOfField(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter long long offsetOfField()
    long long ret = self->offsetOfField();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_overloadedDecls(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter std::vector<std::shared_ptr<clangwrapper::Cursor>> overloadedDecls()
    std::vector<std::shared_ptr<clangwrapper::Cursor>> ret = self->overloadedDecls();
    int num_ret = olua_push_array<std::shared_ptr<clangwrapper::Cursor>>(L, ret, [L](std::shared_ptr<clangwrapper::Cursor> &arg1) {
        olua_push_object(L, &arg1, "clang.Cursor");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_parent(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter std::shared_ptr<clangwrapper::Cursor> parent()
    std::shared_ptr<clangwrapper::Cursor> ret = self->parent();
    int num_ret = olua_push_object(L, &ret, "clang.Cursor");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_prettyPrinted(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter clangwrapper::string prettyPrinted()
    clangwrapper::string ret = self->prettyPrinted();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_rawCommentText(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter clangwrapper::string rawCommentText()
    clangwrapper::string ret = self->rawCommentText();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_receiverType(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter std::shared_ptr<clangwrapper::Type> receiverType()
    std::shared_ptr<clangwrapper::Type> ret = self->receiverType();
    int num_ret = olua_push_object(L, &ret, "clang.Type");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_referenceNameRange(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;
    unsigned int arg1 = 0;       /** pieceIndex */
    unsigned int arg2 = 0;       /** options */

    olua_to_object(L, 1, &self, "clang.Cursor");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // clangwrapper::Cursor::SourceRange referenceNameRange(unsigned int pieceIndex, unsigned int options)
    clangwrapper::Cursor::SourceRange ret = self->referenceNameRange(arg1, arg2);
    int num_ret = olua_pushcopy_object(L, ret, "clang.Cursor.SourceRange");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_referenced(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter std::shared_ptr<clangwrapper::Cursor> referenced()
    std::shared_ptr<clangwrapper::Cursor> ret = self->referenced();
    int num_ret = olua_push_object(L, &ret, "clang.Cursor");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_resultType(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter std::shared_ptr<clangwrapper::Type> resultType()
    std::shared_ptr<clangwrapper::Type> ret = self->resultType();
    int num_ret = olua_push_object(L, &ret, "clang.Type");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_semanticParent(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter std::shared_ptr<clangwrapper::Cursor> semanticParent()
    std::shared_ptr<clangwrapper::Cursor> ret = self->semanticParent();
    int num_ret = olua_push_object(L, &ret, "clang.Cursor");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_shared_from_this(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @copyfrom(std::enable_shared_from_this) std::shared_ptr<clangwrapper::Cursor> shared_from_this()
    std::shared_ptr<clangwrapper::Cursor> ret = self->shared_from_this();
    int num_ret = olua_push_object(L, &ret, "clang.Cursor");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_sourceLocation(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter clangwrapper::Cursor::SourceLocation sourceLocation()
    clangwrapper::Cursor::SourceLocation ret = self->sourceLocation();
    int num_ret = olua_pushcopy_object(L, ret, "clang.Cursor.SourceLocation");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_sourceRange(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter clangwrapper::Cursor::SourceRange sourceRange()
    clangwrapper::Cursor::SourceRange ret = self->sourceRange();
    int num_ret = olua_pushcopy_object(L, ret, "clang.Cursor.SourceRange");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_specializedTemplate(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter std::shared_ptr<clangwrapper::Cursor> specializedTemplate()
    std::shared_ptr<clangwrapper::Cursor> ret = self->specializedTemplate();
    int num_ret = olua_push_object(L, &ret, "clang.Cursor");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_storageClass(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter clangwrapper::StorageClass storageClass()
    clangwrapper::StorageClass ret = self->storageClass();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_templateArgumentKind(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;
    unsigned int arg1 = 0;       /** index */

    olua_to_object(L, 1, &self, "clang.Cursor");
    olua_check_integer(L, 2, &arg1);

    // clangwrapper::TemplateArgumentKind templateArgumentKind(unsigned int index)
    clangwrapper::TemplateArgumentKind ret = self->templateArgumentKind(arg1);
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_templateArgumentTypes(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter std::vector<std::shared_ptr<clangwrapper::Type>> templateArgumentTypes()
    std::vector<std::shared_ptr<clangwrapper::Type>> ret = self->templateArgumentTypes();
    int num_ret = olua_push_array<std::shared_ptr<clangwrapper::Type>>(L, ret, [L](std::shared_ptr<clangwrapper::Type> &arg1) {
        olua_push_object(L, &arg1, "clang.Type");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_templateArgumentUnsignedValue(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;
    unsigned int arg1 = 0;       /** index */

    olua_to_object(L, 1, &self, "clang.Cursor");
    olua_check_integer(L, 2, &arg1);

    // unsigned long long templateArgumentUnsignedValue(unsigned int index)
    unsigned long long ret = self->templateArgumentUnsignedValue(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_templateArgumentValue(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;
    unsigned int arg1 = 0;       /** index */

    olua_to_object(L, 1, &self, "clang.Cursor");
    olua_check_integer(L, 2, &arg1);

    // long long templateArgumentValue(unsigned int index)
    long long ret = self->templateArgumentValue(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_templateKind(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter clangwrapper::CursorKind templateKind()
    clangwrapper::CursorKind ret = self->templateKind();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_templateKindSpelling(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter clangwrapper::string templateKindSpelling()
    clangwrapper::string ret = self->templateKindSpelling();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_tlsKind(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter clangwrapper::TLSKind tlsKind()
    clangwrapper::TLSKind ret = self->tlsKind();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_translationUnit(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter std::shared_ptr<clangwrapper::TranslationUnit> translationUnit()
    std::shared_ptr<clangwrapper::TranslationUnit> ret = self->translationUnit();
    int num_ret = olua_push_object(L, &ret, "clang.TranslationUnit");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_type(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter std::shared_ptr<clangwrapper::Type> type()
    std::shared_ptr<clangwrapper::Type> ret = self->type();
    int num_ret = olua_push_object(L, &ret, "clang.Type");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_underlyingType(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter std::shared_ptr<clangwrapper::Type> underlyingType()
    std::shared_ptr<clangwrapper::Type> ret = self->underlyingType();
    int num_ret = olua_push_object(L, &ret, "clang.Type");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_varDeclInitializer(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter std::shared_ptr<clangwrapper::Cursor> varDeclInitializer()
    std::shared_ptr<clangwrapper::Cursor> ret = self->varDeclInitializer();
    int num_ret = olua_push_object(L, &ret, "clang.Cursor");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Cursor_visibility(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Cursor *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Cursor");

    // @getter clangwrapper::VisibilityKind visibility()
    clangwrapper::VisibilityKind ret = self->visibility();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_Cursor(lua_State *L)
{
    oluacls_class<clangwrapper::Cursor, clangwrapper::IndexError>(L, "clang.Cursor");
    oluacls_func(L, "__eq", _clangwrapper_Cursor___eq);
    oluacls_func(L, "as", _clangwrapper_Cursor_as);
    oluacls_func(L, "getModule", _clangwrapper_Cursor_getModule);
    oluacls_func(L, "hashCursor", _clangwrapper_Cursor_hashCursor);
    oluacls_func(L, "nameRange", _clangwrapper_Cursor_nameRange);
    oluacls_func(L, "referenceNameRange", _clangwrapper_Cursor_referenceNameRange);
    oluacls_func(L, "shared_from_this", _clangwrapper_Cursor_shared_from_this);
    oluacls_func(L, "templateArgumentKind", _clangwrapper_Cursor_templateArgumentKind);
    oluacls_func(L, "templateArgumentUnsignedValue", _clangwrapper_Cursor_templateArgumentUnsignedValue);
    oluacls_func(L, "templateArgumentValue", _clangwrapper_Cursor_templateArgumentValue);
    oluacls_prop(L, "arguments", _clangwrapper_Cursor_arguments, nullptr);
    oluacls_prop(L, "availability", _clangwrapper_Cursor_availability, nullptr);
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
    oluacls_prop(L, "isCXXAbstract", _clangwrapper_Cursor_isCXXAbstract, nullptr);
    oluacls_prop(L, "isCXXConvertingConstructor", _clangwrapper_Cursor_isCXXConvertingConstructor, nullptr);
    oluacls_prop(L, "isCXXCopyConstructor", _clangwrapper_Cursor_isCXXCopyConstructor, nullptr);
    oluacls_prop(L, "isCXXDefaultConstructor", _clangwrapper_Cursor_isCXXDefaultConstructor, nullptr);
    oluacls_prop(L, "isCXXFieldMutable", _clangwrapper_Cursor_isCXXFieldMutable, nullptr);
    oluacls_prop(L, "isCXXMethodConst", _clangwrapper_Cursor_isCXXMethodConst, nullptr);
    oluacls_prop(L, "isCXXMethodCopyAssignmentOperator", _clangwrapper_Cursor_isCXXMethodCopyAssignmentOperator, nullptr);
    oluacls_prop(L, "isCXXMethodDefaulted", _clangwrapper_Cursor_isCXXMethodDefaulted, nullptr);
    oluacls_prop(L, "isCXXMethodDeleted", _clangwrapper_Cursor_isCXXMethodDeleted, nullptr);
    oluacls_prop(L, "isCXXMethodExplicit", _clangwrapper_Cursor_isCXXMethodExplicit, nullptr);
    oluacls_prop(L, "isCXXMethodMoveAssignmentOperator", _clangwrapper_Cursor_isCXXMethodMoveAssignmentOperator, nullptr);
    oluacls_prop(L, "isCXXMethodPureVirtual", _clangwrapper_Cursor_isCXXMethodPureVirtual, nullptr);
    oluacls_prop(L, "isCXXMethodStatic", _clangwrapper_Cursor_isCXXMethodStatic, nullptr);
    oluacls_prop(L, "isCXXMethodVirtual", _clangwrapper_Cursor_isCXXMethodVirtual, nullptr);
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
    oluacls_prop(L, "lexicalParent", _clangwrapper_Cursor_lexicalParent, nullptr);
    oluacls_prop(L, "linkage", _clangwrapper_Cursor_linkage, nullptr);
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
    oluacls_prop(L, "templateArgumentTypes", _clangwrapper_Cursor_templateArgumentTypes, nullptr);
    oluacls_prop(L, "templateKind", _clangwrapper_Cursor_templateKind, nullptr);
    oluacls_prop(L, "templateKindSpelling", _clangwrapper_Cursor_templateKindSpelling, nullptr);
    oluacls_prop(L, "tlsKind", _clangwrapper_Cursor_tlsKind, nullptr);
    oluacls_prop(L, "translationUnit", _clangwrapper_Cursor_translationUnit, nullptr);
    oluacls_prop(L, "type", _clangwrapper_Cursor_type, nullptr);
    oluacls_prop(L, "underlyingType", _clangwrapper_Cursor_underlyingType, nullptr);
    oluacls_prop(L, "varDeclInitializer", _clangwrapper_Cursor_varDeclInitializer, nullptr);
    oluacls_prop(L, "visibility", _clangwrapper_Cursor_visibility, nullptr);

    return 1;
}
OLUA_END_DECLS

static int _clangwrapper_Module_as(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Module *self = nullptr;
    const char *arg1 = nullptr;       /** cls */

    olua_to_object(L, 1, &self, "clang.Module");
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

static int _clangwrapper_Module_astFile(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Module *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Module");

    // @getter std::shared_ptr<clangwrapper::File> astFile()
    std::shared_ptr<clangwrapper::File> ret = self->astFile();
    int num_ret = olua_push_object(L, &ret, "clang.File");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Module_fullName(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Module *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Module");

    // @getter clangwrapper::string fullName()
    clangwrapper::string ret = self->fullName();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Module_isSystem(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Module *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Module");

    // @getter int isSystem()
    int ret = self->isSystem();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Module_name(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Module *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Module");

    // @getter clangwrapper::string name()
    clangwrapper::string ret = self->name();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Module_parent(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Module *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Module");

    // @getter std::shared_ptr<clangwrapper::Module> parent()
    std::shared_ptr<clangwrapper::Module> ret = self->parent();
    int num_ret = olua_push_object(L, &ret, "clang.Module");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Module_shared_from_this(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Module *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Module");

    // @copyfrom(std::enable_shared_from_this) std::shared_ptr<clangwrapper::Module> shared_from_this()
    std::shared_ptr<clangwrapper::Module> ret = self->shared_from_this();
    int num_ret = olua_push_object(L, &ret, "clang.Module");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_Module(lua_State *L)
{
    oluacls_class<clangwrapper::Module, clangwrapper::IndexError>(L, "clang.Module");
    oluacls_func(L, "as", _clangwrapper_Module_as);
    oluacls_func(L, "shared_from_this", _clangwrapper_Module_shared_from_this);
    oluacls_prop(L, "astFile", _clangwrapper_Module_astFile, nullptr);
    oluacls_prop(L, "fullName", _clangwrapper_Module_fullName, nullptr);
    oluacls_prop(L, "isSystem", _clangwrapper_Module_isSystem, nullptr);
    oluacls_prop(L, "name", _clangwrapper_Module_name, nullptr);
    oluacls_prop(L, "parent", _clangwrapper_Module_parent, nullptr);

    return 1;
}
OLUA_END_DECLS

static int _clangwrapper_TranslationUnit_as(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::TranslationUnit *self = nullptr;
    const char *arg1 = nullptr;       /** cls */

    olua_to_object(L, 1, &self, "clang.TranslationUnit");
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

static int _clangwrapper_TranslationUnit_cursor(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::TranslationUnit *self = nullptr;

    olua_to_object(L, 1, &self, "clang.TranslationUnit");

    // @getter std::shared_ptr<clangwrapper::Cursor> cursor()
    std::shared_ptr<clangwrapper::Cursor> ret = self->cursor();
    int num_ret = olua_push_object(L, &ret, "clang.Cursor");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_TranslationUnit_defaultReparseOptions(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::TranslationUnit *self = nullptr;

    olua_to_object(L, 1, &self, "clang.TranslationUnit");

    // unsigned int defaultReparseOptions()
    unsigned int ret = self->defaultReparseOptions();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_TranslationUnit_defaultSaveOptions(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::TranslationUnit *self = nullptr;

    olua_to_object(L, 1, &self, "clang.TranslationUnit");

    // unsigned int defaultSaveOptions()
    unsigned int ret = self->defaultSaveOptions();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_TranslationUnit_diagnosticSetFromTU(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::TranslationUnit *self = nullptr;

    olua_to_object(L, 1, &self, "clang.TranslationUnit");

    // @getter std::set<std::shared_ptr<clangwrapper::Diagnostic>> diagnosticSetFromTU()
    std::set<std::shared_ptr<clangwrapper::Diagnostic>> ret = self->diagnosticSetFromTU();
    int num_ret = olua_push_array<std::shared_ptr<clangwrapper::Diagnostic>>(L, ret, [L](std::shared_ptr<clangwrapper::Diagnostic> &arg1) {
        olua_push_object(L, &arg1, "clang.Diagnostic");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_TranslationUnit_diagnostics(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::TranslationUnit *self = nullptr;

    olua_to_object(L, 1, &self, "clang.TranslationUnit");

    // @getter std::vector<std::shared_ptr<clangwrapper::Diagnostic>> diagnostics()
    std::vector<std::shared_ptr<clangwrapper::Diagnostic>> ret = self->diagnostics();
    int num_ret = olua_push_array<std::shared_ptr<clangwrapper::Diagnostic>>(L, ret, [L](std::shared_ptr<clangwrapper::Diagnostic> &arg1) {
        olua_push_object(L, &arg1, "clang.Diagnostic");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_TranslationUnit_getFile(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::TranslationUnit *self = nullptr;
    std::string arg1;       /** path */

    olua_to_object(L, 1, &self, "clang.TranslationUnit");
    olua_check_string(L, 2, &arg1);

    // std::shared_ptr<clangwrapper::File> getFile(const std::string &path)
    std::shared_ptr<clangwrapper::File> ret = self->getFile(arg1);
    int num_ret = olua_push_object(L, &ret, "clang.File");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_TranslationUnit_getFileContents(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::TranslationUnit *self = nullptr;
    clangwrapper::File *arg1 = nullptr;       /** f */

    olua_to_object(L, 1, &self, "clang.TranslationUnit");
    olua_check_object(L, 2, &arg1, "clang.File");

    // clangwrapper::string getFileContents(clangwrapper::File *f)
    clangwrapper::string ret = self->getFileContents(arg1);
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_TranslationUnit_isFileMultipleIncludeGuarded(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::TranslationUnit *self = nullptr;
    clangwrapper::File *arg1 = nullptr;       /** f */

    olua_to_object(L, 1, &self, "clang.TranslationUnit");
    olua_check_object(L, 2, &arg1, "clang.File");

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

    olua_to_object(L, 1, &self, "clang.TranslationUnit");
    olua_check_object(L, 2, &arg1, "clang.File");

    // std::shared_ptr<clangwrapper::Module> moduleForFile(const std::shared_ptr<clangwrapper::File> &file)
    std::shared_ptr<clangwrapper::Module> ret = self->moduleForFile(arg1);
    int num_ret = olua_push_object(L, &ret, "clang.Module");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_TranslationUnit_name(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::TranslationUnit *self = nullptr;

    olua_to_object(L, 1, &self, "clang.TranslationUnit");

    // @getter clangwrapper::string name()
    clangwrapper::string ret = self->name();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_TranslationUnit_numTopLevelHeaders(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::TranslationUnit *self = nullptr;
    std::shared_ptr<clangwrapper::Module> arg1;       /** m */

    olua_to_object(L, 1, &self, "clang.TranslationUnit");
    olua_check_object(L, 2, &arg1, "clang.Module");

    // unsigned int numTopLevelHeaders(const std::shared_ptr<clangwrapper::Module> &m)
    unsigned int ret = self->numTopLevelHeaders(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_TranslationUnit_saveTranslationUnit(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::TranslationUnit *self = nullptr;
    std::string arg1;       /** path */
    unsigned int arg2 = 0;       /** options */

    olua_to_object(L, 1, &self, "clang.TranslationUnit");
    olua_check_string(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // int saveTranslationUnit(const std::string &path, unsigned int options)
    int ret = self->saveTranslationUnit(arg1, arg2);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_TranslationUnit_shared_from_this(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::TranslationUnit *self = nullptr;

    olua_to_object(L, 1, &self, "clang.TranslationUnit");

    // @copyfrom(std::enable_shared_from_this) std::shared_ptr<clangwrapper::TranslationUnit> shared_from_this()
    std::shared_ptr<clangwrapper::TranslationUnit> ret = self->shared_from_this();
    int num_ret = olua_push_object(L, &ret, "clang.TranslationUnit");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_TranslationUnit_suspendTranslationUnit(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::TranslationUnit *self = nullptr;

    olua_to_object(L, 1, &self, "clang.TranslationUnit");

    // unsigned int suspendTranslationUnit()
    unsigned int ret = self->suspendTranslationUnit();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_TranslationUnit_topLevelHeader(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::TranslationUnit *self = nullptr;
    std::shared_ptr<clangwrapper::Module> arg1;       /** m */
    unsigned int arg2 = 0;       /** index */

    olua_to_object(L, 1, &self, "clang.TranslationUnit");
    olua_check_object(L, 2, &arg1, "clang.Module");
    olua_check_integer(L, 3, &arg2);

    // std::shared_ptr<clangwrapper::File> topLevelHeader(const std::shared_ptr<clangwrapper::Module> &m, unsigned int index)
    std::shared_ptr<clangwrapper::File> ret = self->topLevelHeader(arg1, arg2);
    int num_ret = olua_push_object(L, &ret, "clang.File");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_TranslationUnit(lua_State *L)
{
    oluacls_class<clangwrapper::TranslationUnit, clangwrapper::IndexError>(L, "clang.TranslationUnit");
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

    return 1;
}
OLUA_END_DECLS

static int _clangwrapper_Index_as(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Index *self = nullptr;
    const char *arg1 = nullptr;       /** cls */

    olua_to_object(L, 1, &self, "clang.Index");
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

    olua_to_object(L, 1, &self, "clang.Index");
    olua_check_string(L, 2, &arg1);

    // std::shared_ptr<clangwrapper::TranslationUnit> create(const std::string &path)
    std::shared_ptr<clangwrapper::TranslationUnit> ret = self->create(arg1);
    int num_ret = olua_push_object(L, &ret, "clang.TranslationUnit");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Index_getGlobalOptions(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Index *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Index");

    // unsigned int getGlobalOptions()
    unsigned int ret = self->getGlobalOptions();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Index_parse$1(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Index *self = nullptr;
    std::string arg1;       /** path */
    std::vector<std::string> arg2;       /** args */
    unsigned int arg3 = 0;       /** options */

    olua_to_object(L, 1, &self, "clang.Index");
    olua_check_string(L, 2, &arg1);
    olua_check_array<std::string>(L, 3, arg2, [L](std::string *arg1) {
        olua_check_string(L, -1, arg1);
    });
    olua_check_integer(L, 4, &arg3);

    // std::shared_ptr<clangwrapper::TranslationUnit> parse(const std::string &path, const std::vector<std::string> args, @optional unsigned int options)
    std::shared_ptr<clangwrapper::TranslationUnit> ret = self->parse(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, &ret, "clang.TranslationUnit");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Index_parse$2(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Index *self = nullptr;
    std::string arg1;       /** path */
    std::vector<std::string> arg2;       /** args */

    olua_to_object(L, 1, &self, "clang.Index");
    olua_check_string(L, 2, &arg1);
    olua_check_array<std::string>(L, 3, arg2, [L](std::string *arg1) {
        olua_check_string(L, -1, arg1);
    });

    // std::shared_ptr<clangwrapper::TranslationUnit> parse(const std::string &path, const std::vector<std::string> args)
    std::shared_ptr<clangwrapper::TranslationUnit> ret = self->parse(arg1, arg2);
    int num_ret = olua_push_object(L, &ret, "clang.TranslationUnit");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_Index_parse(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 2) {
        // if ((olua_is_string(L, 2)) && (olua_is_array(L, 3))) {
            // std::shared_ptr<clangwrapper::TranslationUnit> parse(const std::string &path, const std::vector<std::string> args)
            return _clangwrapper_Index_parse$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_string(L, 2)) && (olua_is_array(L, 3)) && (olua_is_integer(L, 4))) {
            // std::shared_ptr<clangwrapper::TranslationUnit> parse(const std::string &path, const std::vector<std::string> args, @optional unsigned int options)
            return _clangwrapper_Index_parse$1(L);
        // }
    }

    luaL_error(L, "method 'clangwrapper::Index::parse' not support '%d' arguments", num_args);

    return 0;
}

static int _clangwrapper_Index_setGlobalOptions(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Index *self = nullptr;
    unsigned int arg1 = 0;       /** options */

    olua_to_object(L, 1, &self, "clang.Index");
    olua_check_integer(L, 2, &arg1);

    // void setGlobalOptions(unsigned int options)
    self->setGlobalOptions(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _clangwrapper_Index_setInvocationEmissionPathOption(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Index *self = nullptr;
    std::string arg1;       /** path */

    olua_to_object(L, 1, &self, "clang.Index");
    olua_check_string(L, 2, &arg1);

    // void setInvocationEmissionPathOption(const std::string &path)
    self->setInvocationEmissionPathOption(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _clangwrapper_Index_shared_from_this(lua_State *L)
{
    olua_startinvoke(L);

    clangwrapper::Index *self = nullptr;

    olua_to_object(L, 1, &self, "clang.Index");

    // @copyfrom(std::enable_shared_from_this) std::shared_ptr<clangwrapper::Index> shared_from_this()
    std::shared_ptr<clangwrapper::Index> ret = self->shared_from_this();
    int num_ret = olua_push_object(L, &ret, "clang.Index");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_Index(lua_State *L)
{
    oluacls_class<clangwrapper::Index, clangwrapper::IndexError>(L, "clang.Index");
    oluacls_func(L, "as", _clangwrapper_Index_as);
    oluacls_func(L, "create", _clangwrapper_Index_create);
    oluacls_func(L, "getGlobalOptions", _clangwrapper_Index_getGlobalOptions);
    oluacls_func(L, "parse", _clangwrapper_Index_parse);
    oluacls_func(L, "setGlobalOptions", _clangwrapper_Index_setGlobalOptions);
    oluacls_func(L, "setInvocationEmissionPathOption", _clangwrapper_Index_setInvocationEmissionPathOption);
    oluacls_func(L, "shared_from_this", _clangwrapper_Index_shared_from_this);
    oluacls_prop(L, "globalOptions", _clangwrapper_Index_getGlobalOptions, _clangwrapper_Index_setGlobalOptions);

    return 1;
}
OLUA_END_DECLS

static int _clangwrapper_clang___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (clangwrapper::clang *)olua_toobj(L, 1, "clang.clang");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _clangwrapper_clang___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (clangwrapper::clang *)olua_toobj(L, 1, "clang.clang");
    olua_push_object(L, self, "clang.clang");

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
    int num_ret = olua_push_object(L, &ret, "clang.Index");

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_clang_debug$1(lua_State *L)
{
    olua_startinvoke(L);

    // static bool debug
    bool ret = clangwrapper::clang::debug;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _clangwrapper_clang_debug$2(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** debug */

    olua_check_bool(L, 1, &arg1);

    // static bool debug
    clangwrapper::clang::debug = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _clangwrapper_clang_debug(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static bool debug
        return _clangwrapper_clang_debug$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_bool(L, 1))) {
            // static bool debug
            return _clangwrapper_clang_debug$2(L);
        // }
    }

    luaL_error(L, "method 'clangwrapper::clang::debug' not support '%d' arguments", num_args);

    return 0;
}

static int _clangwrapper_clang_version(lua_State *L)
{
    olua_startinvoke(L);

    // @getter static const std::string version()
    const std::string ret = clangwrapper::clang::version();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clangwrapper_clang(lua_State *L)
{
    oluacls_class<clangwrapper::clang>(L, "clang.clang");
    oluacls_func(L, "__gc", _clangwrapper_clang___gc);
    oluacls_func(L, "__olua_move", _clangwrapper_clang___olua_move);
    oluacls_func(L, "createIndex", _clangwrapper_clang_createIndex);
    oluacls_prop(L, "version", _clangwrapper_clang_version, nullptr);
    oluacls_prop(L, "debug", _clangwrapper_clang_debug, _clangwrapper_clang_debug);

    return 1;
}
OLUA_END_DECLS

static int _std_enable_shared_from_this_clangwrapper_Diagnostic___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (std::enable_shared_from_this<clangwrapper::Diagnostic> *)olua_toobj(L, 1, "std.enable_shared_from_this<clang.Diagnostic>");
    olua_push_object(L, self, "std.enable_shared_from_this<clang.Diagnostic>");

    olua_endinvoke(L);

    return 1;
}

static int _std_enable_shared_from_this_clangwrapper_Diagnostic_shared_from_this(lua_State *L)
{
    olua_startinvoke(L);

    std::enable_shared_from_this<clangwrapper::Diagnostic> *self = nullptr;

    olua_to_object(L, 1, &self, "std.enable_shared_from_this<clang.Diagnostic>");

    // std::shared_ptr<clangwrapper::Diagnostic> shared_from_this()
    std::shared_ptr<clangwrapper::Diagnostic> ret = self->shared_from_this();
    int num_ret = olua_push_object(L, &ret, "clang.Diagnostic");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_std_enable_shared_from_this_clangwrapper_Diagnostic(lua_State *L)
{
    oluacls_class<std::enable_shared_from_this<clangwrapper::Diagnostic>>(L, "std.enable_shared_from_this<clang.Diagnostic>");
    oluacls_func(L, "__olua_move", _std_enable_shared_from_this_clangwrapper_Diagnostic___olua_move);
    oluacls_func(L, "shared_from_this", _std_enable_shared_from_this_clangwrapper_Diagnostic_shared_from_this);

    return 1;
}
OLUA_END_DECLS

static int _std_enable_shared_from_this_clangwrapper_File___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (std::enable_shared_from_this<clangwrapper::File> *)olua_toobj(L, 1, "std.enable_shared_from_this<clang.File>");
    olua_push_object(L, self, "std.enable_shared_from_this<clang.File>");

    olua_endinvoke(L);

    return 1;
}

static int _std_enable_shared_from_this_clangwrapper_File_shared_from_this(lua_State *L)
{
    olua_startinvoke(L);

    std::enable_shared_from_this<clangwrapper::File> *self = nullptr;

    olua_to_object(L, 1, &self, "std.enable_shared_from_this<clang.File>");

    // std::shared_ptr<clangwrapper::File> shared_from_this()
    std::shared_ptr<clangwrapper::File> ret = self->shared_from_this();
    int num_ret = olua_push_object(L, &ret, "clang.File");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_std_enable_shared_from_this_clangwrapper_File(lua_State *L)
{
    oluacls_class<std::enable_shared_from_this<clangwrapper::File>>(L, "std.enable_shared_from_this<clang.File>");
    oluacls_func(L, "__olua_move", _std_enable_shared_from_this_clangwrapper_File___olua_move);
    oluacls_func(L, "shared_from_this", _std_enable_shared_from_this_clangwrapper_File_shared_from_this);

    return 1;
}
OLUA_END_DECLS

static int _std_enable_shared_from_this_clangwrapper_Type___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (std::enable_shared_from_this<clangwrapper::Type> *)olua_toobj(L, 1, "std.enable_shared_from_this<clang.Type>");
    olua_push_object(L, self, "std.enable_shared_from_this<clang.Type>");

    olua_endinvoke(L);

    return 1;
}

static int _std_enable_shared_from_this_clangwrapper_Type_shared_from_this(lua_State *L)
{
    olua_startinvoke(L);

    std::enable_shared_from_this<clangwrapper::Type> *self = nullptr;

    olua_to_object(L, 1, &self, "std.enable_shared_from_this<clang.Type>");

    // std::shared_ptr<clangwrapper::Type> shared_from_this()
    std::shared_ptr<clangwrapper::Type> ret = self->shared_from_this();
    int num_ret = olua_push_object(L, &ret, "clang.Type");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_std_enable_shared_from_this_clangwrapper_Type(lua_State *L)
{
    oluacls_class<std::enable_shared_from_this<clangwrapper::Type>>(L, "std.enable_shared_from_this<clang.Type>");
    oluacls_func(L, "__olua_move", _std_enable_shared_from_this_clangwrapper_Type___olua_move);
    oluacls_func(L, "shared_from_this", _std_enable_shared_from_this_clangwrapper_Type_shared_from_this);

    return 1;
}
OLUA_END_DECLS

static int _std_enable_shared_from_this_clangwrapper_Cursor___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (std::enable_shared_from_this<clangwrapper::Cursor> *)olua_toobj(L, 1, "std.enable_shared_from_this<clang.Cursor>");
    olua_push_object(L, self, "std.enable_shared_from_this<clang.Cursor>");

    olua_endinvoke(L);

    return 1;
}

static int _std_enable_shared_from_this_clangwrapper_Cursor_shared_from_this(lua_State *L)
{
    olua_startinvoke(L);

    std::enable_shared_from_this<clangwrapper::Cursor> *self = nullptr;

    olua_to_object(L, 1, &self, "std.enable_shared_from_this<clang.Cursor>");

    // std::shared_ptr<clangwrapper::Cursor> shared_from_this()
    std::shared_ptr<clangwrapper::Cursor> ret = self->shared_from_this();
    int num_ret = olua_push_object(L, &ret, "clang.Cursor");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_std_enable_shared_from_this_clangwrapper_Cursor(lua_State *L)
{
    oluacls_class<std::enable_shared_from_this<clangwrapper::Cursor>>(L, "std.enable_shared_from_this<clang.Cursor>");
    oluacls_func(L, "__olua_move", _std_enable_shared_from_this_clangwrapper_Cursor___olua_move);
    oluacls_func(L, "shared_from_this", _std_enable_shared_from_this_clangwrapper_Cursor_shared_from_this);

    return 1;
}
OLUA_END_DECLS

static int _std_enable_shared_from_this_clangwrapper_Module___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (std::enable_shared_from_this<clangwrapper::Module> *)olua_toobj(L, 1, "std.enable_shared_from_this<clang.Module>");
    olua_push_object(L, self, "std.enable_shared_from_this<clang.Module>");

    olua_endinvoke(L);

    return 1;
}

static int _std_enable_shared_from_this_clangwrapper_Module_shared_from_this(lua_State *L)
{
    olua_startinvoke(L);

    std::enable_shared_from_this<clangwrapper::Module> *self = nullptr;

    olua_to_object(L, 1, &self, "std.enable_shared_from_this<clang.Module>");

    // std::shared_ptr<clangwrapper::Module> shared_from_this()
    std::shared_ptr<clangwrapper::Module> ret = self->shared_from_this();
    int num_ret = olua_push_object(L, &ret, "clang.Module");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_std_enable_shared_from_this_clangwrapper_Module(lua_State *L)
{
    oluacls_class<std::enable_shared_from_this<clangwrapper::Module>>(L, "std.enable_shared_from_this<clang.Module>");
    oluacls_func(L, "__olua_move", _std_enable_shared_from_this_clangwrapper_Module___olua_move);
    oluacls_func(L, "shared_from_this", _std_enable_shared_from_this_clangwrapper_Module_shared_from_this);

    return 1;
}
OLUA_END_DECLS

static int _std_enable_shared_from_this_clangwrapper_TranslationUnit___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (std::enable_shared_from_this<clangwrapper::TranslationUnit> *)olua_toobj(L, 1, "std.enable_shared_from_this<clang.TranslationUnit>");
    olua_push_object(L, self, "std.enable_shared_from_this<clang.TranslationUnit>");

    olua_endinvoke(L);

    return 1;
}

static int _std_enable_shared_from_this_clangwrapper_TranslationUnit_shared_from_this(lua_State *L)
{
    olua_startinvoke(L);

    std::enable_shared_from_this<clangwrapper::TranslationUnit> *self = nullptr;

    olua_to_object(L, 1, &self, "std.enable_shared_from_this<clang.TranslationUnit>");

    // std::shared_ptr<clangwrapper::TranslationUnit> shared_from_this()
    std::shared_ptr<clangwrapper::TranslationUnit> ret = self->shared_from_this();
    int num_ret = olua_push_object(L, &ret, "clang.TranslationUnit");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_std_enable_shared_from_this_clangwrapper_TranslationUnit(lua_State *L)
{
    oluacls_class<std::enable_shared_from_this<clangwrapper::TranslationUnit>>(L, "std.enable_shared_from_this<clang.TranslationUnit>");
    oluacls_func(L, "__olua_move", _std_enable_shared_from_this_clangwrapper_TranslationUnit___olua_move);
    oluacls_func(L, "shared_from_this", _std_enable_shared_from_this_clangwrapper_TranslationUnit_shared_from_this);

    return 1;
}
OLUA_END_DECLS

static int _std_enable_shared_from_this_clangwrapper_Index___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (std::enable_shared_from_this<clangwrapper::Index> *)olua_toobj(L, 1, "std.enable_shared_from_this<clang.Index>");
    olua_push_object(L, self, "std.enable_shared_from_this<clang.Index>");

    olua_endinvoke(L);

    return 1;
}

static int _std_enable_shared_from_this_clangwrapper_Index_shared_from_this(lua_State *L)
{
    olua_startinvoke(L);

    std::enable_shared_from_this<clangwrapper::Index> *self = nullptr;

    olua_to_object(L, 1, &self, "std.enable_shared_from_this<clang.Index>");

    // std::shared_ptr<clangwrapper::Index> shared_from_this()
    std::shared_ptr<clangwrapper::Index> ret = self->shared_from_this();
    int num_ret = olua_push_object(L, &ret, "clang.Index");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_std_enable_shared_from_this_clangwrapper_Index(lua_State *L)
{
    oluacls_class<std::enable_shared_from_this<clangwrapper::Index>>(L, "std.enable_shared_from_this<clang.Index>");
    oluacls_func(L, "__olua_move", _std_enable_shared_from_this_clangwrapper_Index___olua_move);
    oluacls_func(L, "shared_from_this", _std_enable_shared_from_this_clangwrapper_Index_shared_from_this);

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_clang(lua_State *L)
{
    olua_require(L, "clang.IndexError", luaopen_clangwrapper_IndexError);
    olua_require(L, "clang.Cursor.SourceRange", luaopen_clangwrapper_Cursor_SourceRange);
    olua_require(L, "clang.Cursor.SourceLocation", luaopen_clangwrapper_Cursor_SourceLocation);
    olua_require(L, "clang.AvailabilityKind", luaopen_clangwrapper_AvailabilityKind);
    olua_require(L, "clang.CallingConv", luaopen_clangwrapper_CallingConv);
    olua_require(L, "clang.CursorKind", luaopen_clangwrapper_CursorKind);
    olua_require(L, "clang.CXXAccessSpecifier", luaopen_clangwrapper_CXXAccessSpecifier);
    olua_require(L, "clang.DiagnosticSeverity", luaopen_clangwrapper_DiagnosticSeverity);
    olua_require(L, "clang.GlobalOptFlags", luaopen_clangwrapper_GlobalOptFlags);
    olua_require(L, "clang.LanguageKind", luaopen_clangwrapper_LanguageKind);
    olua_require(L, "clang.LinkageKind", luaopen_clangwrapper_LinkageKind);
    olua_require(L, "clang.RefQualifierKind", luaopen_clangwrapper_RefQualifierKind);
    olua_require(L, "clang.StorageClass", luaopen_clangwrapper_StorageClass);
    olua_require(L, "clang.TemplateArgumentKind", luaopen_clangwrapper_TemplateArgumentKind);
    olua_require(L, "clang.TLSKind", luaopen_clangwrapper_TLSKind);
    olua_require(L, "clang.TypeKind", luaopen_clangwrapper_TypeKind);
    olua_require(L, "clang.TypeNullabilityKind", luaopen_clangwrapper_TypeNullabilityKind);
    olua_require(L, "clang.VisibilityKind", luaopen_clangwrapper_VisibilityKind);
    olua_require(L, "clang.Diagnostic", luaopen_clangwrapper_Diagnostic);
    olua_require(L, "clang.File", luaopen_clangwrapper_File);
    olua_require(L, "clang.Type", luaopen_clangwrapper_Type);
    olua_require(L, "clang.Cursor", luaopen_clangwrapper_Cursor);
    olua_require(L, "clang.Module", luaopen_clangwrapper_Module);
    olua_require(L, "clang.TranslationUnit", luaopen_clangwrapper_TranslationUnit);
    olua_require(L, "clang.Index", luaopen_clangwrapper_Index);
    olua_require(L, "clang.clang", luaopen_clangwrapper_clang);
    olua_require(L, "std.enable_shared_from_this<clang.Diagnostic>", luaopen_std_enable_shared_from_this_clangwrapper_Diagnostic);
    olua_require(L, "std.enable_shared_from_this<clang.File>", luaopen_std_enable_shared_from_this_clangwrapper_File);
    olua_require(L, "std.enable_shared_from_this<clang.Type>", luaopen_std_enable_shared_from_this_clangwrapper_Type);
    olua_require(L, "std.enable_shared_from_this<clang.Cursor>", luaopen_std_enable_shared_from_this_clangwrapper_Cursor);
    olua_require(L, "std.enable_shared_from_this<clang.Module>", luaopen_std_enable_shared_from_this_clangwrapper_Module);
    olua_require(L, "std.enable_shared_from_this<clang.TranslationUnit>", luaopen_std_enable_shared_from_this_clangwrapper_TranslationUnit);
    olua_require(L, "std.enable_shared_from_this<clang.Index>", luaopen_std_enable_shared_from_this_clangwrapper_Index);

    if (olua_getclass(L, olua_getluatype<clangwrapper::clang>(L))) {
        return 1;
    }

    return 0;
}
OLUA_END_DECLS
