#pragma once

#include "cpp-sdk/SDK.h"
#include "Log.h"

class BoilerplateResource;
class BoilerplateRuntime : public alt::IScriptRuntime
{
    std::unordered_map<alt::IResource*, BoilerplateResource*> resources;

public:
    BoilerplateRuntime();
    alt::IResource::Impl* CreateImpl(alt::IResource* resource) override;
    void DestroyImpl(alt::IResource::Impl* impl) override;
    void OnTick() override;

    BoilerplateResource* GetResource(alt::IResource* resource)
    {
        if(resources.count(resource) == 0) return nullptr;
        return resources.at(resource);
    }

    // Gets the current runtime instance or creates one if not exists
    static BoilerplateRuntime& Instance()
    {
        static BoilerplateRuntime _instance;
        return _instance;
    }
};
