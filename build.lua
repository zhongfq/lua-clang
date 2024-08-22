OLUA_AUTO_EXPORT_PARENT = true

require "olua"

-------------------------------------------------------------------------------
--- clang compile options
-------------------------------------------------------------------------------
clang {
    '-DOLUA_DEBUG',
    '-I./src',
    '-I./lua53',
    '-I./',
    '-I./llvm-project/clang/include'
}

-------------------------------------------------------------------------------
--- clang wrapper
-------------------------------------------------------------------------------
module 'clang'

output_dir 'src'

api_dir 'olua/addons/clang'

headers [[
#include "clang_wrapper.h"
]]

entry "clangwrapper::clang"

local pattern = {
    '^CXGlobalOpt_', '^CXType_', '^CXCursor_', '^CXDiagnostic_', '^CXCallingConv_',
    '^CXTypeNullability_', '^CXRefQualifier_', '^CXLinkage_', '^CXVisibility_',
    '^CXAvailability_', '^CXLanguage_', '^CXTLS_', '^CXTemplateArgumentKind_',
    '^CX_CXX', 'CX_SC_'
}

local function luaname(name)
    for _, v in ipairs(pattern) do
        if name:find(v) then
            name = name:gsub(v, '')
        end
    end
    return name
end

local function typeenum(cls)
    return typeconf(cls)
        .luaname(luaname)
end

luacls(function (cppcls)
    return cppcls:gsub('clangwrapper::', 'clang.'):gsub('::', '.')
end)

typedef 'clangwrapper::string'
    .luatype 'string'
    .conv 'olua_$$_string'

typeconf 'clangwrapper::Cursor::SourceRange'
typeconf 'clangwrapper::Cursor::SourceLocation'

typeenum 'clangwrapper::AvailabilityKind'
typeenum 'clangwrapper::CallingConv'
typeenum 'clangwrapper::CursorKind'
typeenum 'clangwrapper::CXXAccessSpecifier'
typeenum 'clangwrapper::DiagnosticSeverity'
typeenum 'clangwrapper::GlobalOptFlags'
typeenum 'clangwrapper::LanguageKind'
typeenum 'clangwrapper::LinkageKind'
typeenum 'clangwrapper::RefQualifierKind'
typeenum 'clangwrapper::StorageClass'
typeenum 'clangwrapper::TemplateArgumentKind'
typeenum 'clangwrapper::TLSKind'
typeenum 'clangwrapper::TypeKind'
typeenum 'clangwrapper::TypeNullabilityKind'
typeenum 'clangwrapper::VisibilityKind'

typeconf 'clangwrapper::Diagnostic'
typeconf 'clangwrapper::File'
typeconf 'clangwrapper::Type'
typeconf 'clangwrapper::Cursor'
typeconf 'clangwrapper::Module'
typeconf 'clangwrapper::TranslationUnit'
typeconf 'clangwrapper::Index'
typeconf 'clangwrapper::clang'
