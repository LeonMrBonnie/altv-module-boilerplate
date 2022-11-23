#include "resource.h"
#include "runtime.h"
#include <string>

#ifdef SERVER_MODULE
    // For filestream
    #include <fstream>
    #include <streambuf>
#endif

bool BoilerplateResource::Start()
{
    // Load file
    auto src = ReadFile(resource->GetMain());
    if(src.empty())
    {
        Log::Error << "Failed to read resource main file" << Log::Endl;
        return false;
    }

    // Now we can access the resource main file and e.g. start a script using the source code
    // To showcase this, we are just going to log the file content here
    Log::Info << "Resource main content:" << Log::Endl;
    Log::Info << src << Log::Endl;

    return true;
}

bool BoilerplateResource::Stop()
{
    // Do everything here that needs cleanup after the resource has been stopped
    // Make sure to clean up EVERYTHING here that the resource has created,
    // so that dynamic resource restarts are possible
    return true;
}

void BoilerplateResource::OnEvent(const alt::CEvent* ev)
{
    // Handle incoming events here, e.g. call the event handlers registered by the resource
}

void BoilerplateResource::OnTick()
{
    // Do everything here that needs to be handled on tick that is resource related
    // This can be e.g. timers
}

void BoilerplateResource::OnCreateBaseObject(alt::IBaseObject* object)
{
    // Called every time a base object has been created, so you can use this to keep track
    // of all the existing base objects, to check if they are valid in the user scripts
}

void BoilerplateResource::OnRemoveBaseObject(alt::IBaseObject* object)
{
    // Called every time a base object has been created, so you can use this to keep track
    // of all the existing base objects, to check if they are valid in the user scripts
}

std::string BoilerplateResource::ReadFile(std::string path)
{
    auto pkg = resource->GetPackage();
    // Check if file exists
    if(!pkg->FileExists(path)) return std::string();
    // Open file
    alt::IPackage::File* pkgFile = pkg->OpenFile(path);
    std::string src(pkg->GetFileSize(pkgFile), '\0');
    // Read file content
    pkg->ReadFile(pkgFile, src.data(), src.size());
    pkg->CloseFile(pkgFile);

    return src;
}
