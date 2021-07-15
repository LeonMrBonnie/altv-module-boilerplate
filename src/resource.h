#pragma once

#include "cpp-sdk/SDK.h"
#include "Log.h"
#include <chrono>

class BoilerplateRuntime;
class BoilerplateResource : public alt::IResource::Impl
{
    BoilerplateRuntime* runtime;
    alt::IResource* resource;

public:
    BoilerplateResource(BoilerplateRuntime* runtime, alt::IResource* resource) : runtime(runtime), resource(resource){};
    ~BoilerplateResource() = default;

    bool Start() override;
    bool Stop() override;

    bool OnEvent(const alt::CEvent* event) override;
    void OnTick() override;

    void OnCreateBaseObject(alt::Ref<alt::IBaseObject> object) override;
    void OnRemoveBaseObject(alt::Ref<alt::IBaseObject> object) override;

    bool MakeClient(alt::IResource::CreationInfo* info, alt::Array<alt::String> files)
    {
        // When also having a client module that is inteded to be used with this module,
        // change uncomment the next line and change to your own module type
        // info->type = "bp";
        return true;
    }

    // Gets the alt:V IResource instance
    alt::IResource* GetIResource()
    {
        return resource;
    }
    // Gets the module runtime that instantiated this resource
    BoilerplateRuntime* GetRuntime()
    {
        return runtime;
    }

    // Yoinked from v8 helpers
    int64_t GetTime()
    {
        return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
    }

    // Reads a file using the alt:V API, so it works both on server- and clientside
    alt::String ReadFile(alt::String path);
};
