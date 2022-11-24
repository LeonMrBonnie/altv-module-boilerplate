#include "runtime.h"
#include "resource.h"

BoilerplateRuntime::BoilerplateRuntime()
{
    // Initialize everything for the runtime here,
    // like setting up the scripting language interpreter etc.
}

alt::IResource::Impl* BoilerplateRuntime::CreateImpl(alt::IResource* impl)
{
    // Called every time a new resource is created,
    // and expects us to return an instance of our own custom resource class
    auto resource = new BoilerplateResource(this, impl);
    resources.insert({ impl, resource });
    return resource;
}

void BoilerplateRuntime::DestroyImpl(alt::IResource::Impl* impl)
{
    // Called every time a resource is stopped,
    // and expects us to clean up everything related to the resource
    if(impl == nullptr) return;
    BoilerplateResource* resource = dynamic_cast<BoilerplateResource*>(impl);
    resources.erase(resource->GetIResource());
    delete resource;
}

void BoilerplateRuntime::OnTick()
{
    // Do everything here that needs to run OnTick that is not resource specific,
    // e.g. pumping the event loop
    // This method is not always needed for every module
}
