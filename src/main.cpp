#include "main.h"
#include "Log.h"
#include "cpp-sdk/version/version.h" // Don't worry if your IDE doesn't find this file, compile the module once, to generate this file

#ifdef SERVER_MODULE
EXPORT bool altMain(alt::ICore* core)
{
    alt::ICore::SetInstance(core);

    // Create instance of runtime and register
    auto& runtime = BoilerplateRuntime::Instance();
    core->RegisterScriptRuntime(MODULE_TYPE, &runtime);
    Log::Colored << "Loaded Boilerplate module. Version ~y~" MODULE_VERSION << Log::Endl;

    return true;
}
#endif
#ifdef CLIENT_MODULE
EXPORT void CreateScriptRuntime(alt::ICore* core)
{
    alt::ICore::SetInstance(core);

    // Create instance of runtime and register
    auto& runtime = BoilerplateRuntime::Instance();
    core->RegisterScriptRuntime(MODULE_TYPE, &runtime);
    Log::Colored << "Loaded Boilerplate client module. Version ~y~" MODULE_VERSION << Log::Endl;
}

EXPORT const char* GetType()
{
    return MODULE_TYPE;
}
#endif

EXPORT const char* GetSDKHash()
{
    return ALT_SDK_VERSION;
}
