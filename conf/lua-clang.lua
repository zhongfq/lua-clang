module 'clang'

path 'src'

headers [[
#include "clang_wrapper.h"
]]

luaopen [[
if (olua_getclass(L, "clangwrapper.clang")) {
    return 1;
}
]]

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

typedef 'clangwrapper::string'

typeconv 'clangwrapper::Cursor::SourceRange'
typeconv 'clangwrapper::Cursor::SourceLocation'

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
