<a name="StorageApi"></a>
## StorageApi

All URIs are relative to *https://api.aspose.cloud/v3.0*

Method | HTTP request | Description
------------- | ------------- | -------------
[**getDiscUsage**](StorageApi.md#getDiscUsage) | **GET** /html/storage/disc | Check the disk usage of the current account.
[**objectExists**](StorageApi.md#objectExists) | **GET** /html/storage/exist/\{path\} | Check if a specific file or folder exists.
[**storageExists**](StorageApi.md#storageExists) | **GET** /html/storage/\{name\}/exist | Check if storage exists.
[**getFileVersions**](StorageApi.md#getFileVersions) | **GET** /html/storage/version/\{path\} | Get the file's versions list.
[**getFilesList**](StorageApi.md#getFilesList) | **GET** /html/storage/folder/\{path\} | Get all files and folders within a folder.
[**createFolder**](StorageApi.md#createFolder) | **PUT** /html/storage/folder/\{path\} | Create the folder.
[**deleteFolder**](StorageApi.md#deleteFolder) | **DELETE** /html/storage/folder/\{path\} | Remove a specific folder.
[**copyFolder**](StorageApi.md#copyFolder) | **PUT** /html/storage/folder/copy/\{srcPath\} | Copy a specific folder.
[**moveFolder**](StorageApi.md#moveFolder) | **PUT** /html/storage/folder/move/\{srcPath\} | Move a specific folder.
[**downloadFile**](StorageApi.md#downloadFile) | **GET** /html/storage/file/\{path\} | Download a specific file.
[**uploadFile**](StorageApi.md#uploadFile) | **PUT** /html/storage/file/\{path\} | Upload a specific file.
[**deleteFile**](StorageApi.md#deleteFile) | **DELETE** /html/storage/file/\{path\} | Remove a specific file.
[**copyFile**](StorageApi.md#copyFile) | **PUT** /html/storage/file/copy/\{srcPath\} | Copy a specific file.
[**moveFile**](StorageApi.md#moveFile) | **PUT** /html/storage/file/move/\{srcPath\} | Move a specific file.


<a name="getDiscUsage"></a>
### **getDiscUsage**
>     ASPOSE_DLL_EXPORT pplx::task<std::shared_ptr<DiscUsage>> getDiscUsage(
>        boost::optional<utility::string_t> storageName); // User's storage name (optional)

Check the disk usage of the current account.

[&#8593;UP&#8593;](StorageApi.md#StorageApi)

### Example
```code
#include <AsposeHtmlCloud.h>

using namespace com::aspose::api;

int main(int argc, char* argv[])
{
    // Get keys from aspose site.
    // There is free quota available. 
    // For more details, see https://purchase.aspose.cloud/pricing

    const utility::string_t clientId = _XPLATSTR("XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX");
    const utility::string_t clientSecret = _XPLATSTR("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    const utility::string_t basePath = _XPLATSTR("https://api.aspose.cloud/v3.0");
    const utility::string_t authPath = _XPLATSTR("https://api.aspose.cloud/connect/token");
    
    // Create configuration for authorization
    std::shared_ptr<ApiConfiguration> apiConfig(new ApiConfiguration(clientId, clientSecret, basePath, authPath));

    // Create client from configuration
    std::shared_ptr<ApiClient> apiClient(new ApiClient(apiConfig));

    // Create StorageApi
    StorageApi* api = new StorageApi(apiClient);

    // Storage name
    boost::optional<utility::string_t> storageName = std::wstring(_XPLATSTR(""));

    // Get disk usage
    auto result = api->getDiscUsage(storageName).get();

    // Print result
    std::cout << "Total size: " << result->getTotalSize() << "\n";
    std::cout << "Used size: " << result->getUsedSize() << "\n";

    delete api;
}
```
[&#8593;UP&#8593;](StorageApi.md#StorageApi)


<a name="objectExists"></a>
### **objectExists**
>     ASPOSE_DLL_EXPORT pplx::task<std::shared_ptr<ObjectExist>> objectExists(
>        utility::string_t path,                          // File or folder path e.g. /file.ext or /Folder1
>        boost::optional<utility::string_t> versionId,    // File's version (optional)
>        boost::optional<utility::string_t> storageName); // User's storage name (optional)

Check if a specific file or folder exists.

[&#8593;UP&#8593;](StorageApi.md#StorageApi)

### Example
```code
#include <AsposeHtmlCloud.h>

using namespace com::aspose::api;

int main(int argc, char* argv[])
{
    // Get current directory
    std::string cur_dir(argv[0]);
    int pos = cur_dir.find_last_of("/\\");
    cur_dir = cur_dir.substr(0, pos + 1); // Include the last slash
    std::wstring w_cur_dir(cur_dir.begin(), cur_dir.end());

    // Get keys from aspose site.
    // There is free quota available. 
    // For more details, see https://purchase.aspose.cloud/pricing

    const utility::string_t clientId = _XPLATSTR("XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX");
    const utility::string_t clientSecret = _XPLATSTR("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    const utility::string_t basePath = _XPLATSTR("https://api.aspose.cloud/v3.0");
    const utility::string_t authPath = _XPLATSTR("https://api.aspose.cloud/connect/token");
    
    // Create configuration for authorization
    std::shared_ptr<ApiConfiguration> apiConfig(new ApiConfiguration(clientId, clientSecret, basePath, authPath));

    // Create client from configuration
    std::shared_ptr<ApiClient> apiClient(new ApiClient(apiConfig));

    // Create StorageApi
    StorageApi* api = new StorageApi(apiClient);

    // Storage name
    boost::optional<utility::string_t> storageName = std::wstring(_XPLATSTR(""));

    // Folder name in the storage (should already exist)
    utility::string_t folder = _XPLATSTR("HtmlTestDoc");

    // Storage, received at registration, default is none
    boost::optional<utility::string_t> storage = boost::none;

    // File name for upload to storage
    utility::string_t name = _XPLATSTR("test.html");

    // Prepare file for upload (path = w_cur_dir, name = "test.html")
    std::shared_ptr<HttpContent> file(new HttpContent(w_cur_dir, name));

    // Path to file in the storage
    utility::string_t path_to_file = folder + _XPLATSTR("/") + name;

    // Upload file to the storage
    auto res = api->uploadFile(path_to_file, file, storage).get();

    // Check for errors
    assert(!res->errorsIsSet());

    // File version
    boost::optional<utility::string_t> versionId = std::wstring(_XPLATSTR(""));

    // Check exist file
    auto result_exist = api->objectExists(path_to_file, versionId, storageName).get();

    assert(result_exist->isExists());
    assert(!result_exist->isFolder());

    // Clear file
    auto result_del = api->deleteFile(path_to_file, versionId, storageName).get();

    assert(result_del->getCode() == 200);
    assert(result_del->getStatus() == _XPLATSTR("OK"));

    // Check not exist file
    result_exist = api->objectExists(path_to_file, versionId, storageName).get();

    assert(!result_exist->isExists());
    assert(!result_exist->isFolder());

    delete api;
}
```
[&#8593;UP&#8593;](StorageApi.md#StorageApi)


<a name="storageExists"></a>
### **storageExists**
>     ASPOSE_DLL_EXPORT pplx::task<std::shared_ptr<StorageExist>> storageExists(
>        utility::string_t storageName); // Storage name.

Check if storage exists.

[&#8593;UP&#8593;](StorageApi.md#StorageApi)

### Example
```code
#include <AsposeHtmlCloud.h>

using namespace com::aspose::api;

int main(int argc, char* argv[])
{
    // Get keys from aspose site.
    // There is free quota available. 
    // For more details, see https://purchase.aspose.cloud/pricing

    const utility::string_t clientId = _XPLATSTR("XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX");
    const utility::string_t clientSecret = _XPLATSTR("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    const utility::string_t basePath = _XPLATSTR("https://api.aspose.cloud/v3.0");
    const utility::string_t authPath = _XPLATSTR("https://api.aspose.cloud/connect/token");
    
    // Create configuration for authorization
    std::shared_ptr<ApiConfiguration> apiConfig(new ApiConfiguration(clientId, clientSecret, basePath, authPath));

    // Create client from configuration
    std::shared_ptr<ApiClient> apiClient(new ApiClient(apiConfig));

    // Create StorageApi
    StorageApi* api = new StorageApi(apiClient);

    utility::string_t storage_not_exist = _XPLATSTR("NotExistStorage");

    auto result = api->storageExists(storage_not_exist).get();
    assert(!result->isExists());

    delete api;
}
```
[&#8593;UP&#8593;](StorageApi.md#StorageApi)


<a name="getFileVersions"></a>
### **getFileVersions**
>     ASPOSE_DLL_EXPORT pplx::task<std::shared_ptr<FileVersions>> getFileVersions(
>        utility::string_t path,                          // File path e.g. /file.ext or /Folder1/file.ext
>        boost::optional<utility::string_t> storageName); // User's storage name (optional)

Get the file's versions list.

[&#8593;UP&#8593;](StorageApi.md#StorageApi)

### Example
```code
#include <AsposeHtmlCloud.h>

using namespace com::aspose::api;

int main(int argc, char* argv[])
{
    // Get current directory
    std::string cur_dir(argv[0]);
    int pos = cur_dir.find_last_of("/\\");
    cur_dir = cur_dir.substr(0, pos + 1); // Include the last slash
    std::wstring w_cur_dir(cur_dir.begin(), cur_dir.end());

    // Get keys from aspose site.
    // There is free quota available. 
    // For more details, see https://purchase.aspose.cloud/pricing

    const utility::string_t clientId = _XPLATSTR("XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX");
    const utility::string_t clientSecret = _XPLATSTR("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    const utility::string_t basePath = _XPLATSTR("https://api.aspose.cloud/v3.0");
    const utility::string_t authPath = _XPLATSTR("https://api.aspose.cloud/connect/token");

    // Create configuration for authorization
    std::shared_ptr<ApiConfiguration> apiConfig(new ApiConfiguration(clientId, clientSecret, basePath, authPath));

    // Create client from configuration
    std::shared_ptr<ApiClient> apiClient(new ApiClient(apiConfig));

    // Create StorageApi
    StorageApi* api = new StorageApi(apiClient);

    // Create several files in storage
    utility::string_t name = _XPLATSTR("test.html");
    std::shared_ptr<HttpContent> file(new HttpContent(w_cur_dir, name));

    utility::string_t path_to_file = _XPLATSTR("HtmlTestDoc/test.txt");

    boost::optional<utility::string_t> storageName = std::wstring(_XPLATSTR(""));

    auto result = api->uploadFile(path_to_file, file, storageName).get();
    assert(!result->errorsIsSet());

    result = api->uploadFile(path_to_file, file, storageName).get();
    assert(!result->errorsIsSet());

    result = api->uploadFile(path_to_file, file, storageName).get();
    assert(!result->errorsIsSet());

    // Get file versions
    auto list = api->getFileVersions(path_to_file, storageName).get();

    std::ofstream saved_data(_XPLATSTR("file_list_version.json"), std::ios::out | std::ios::binary);

    // Save file locally
    if (saved_data.is_open())
    {
        saved_data << list->toString();
        saved_data.close();
    }
    else
    {
        std::cout << "Unable to open file";
        assert(false);
    }

    delete api;
}
```
[&#8593;UP&#8593;](StorageApi.md#StorageApi)


<a name="getFilesList"></a>
### **getFilesList**
>     ASPOSE_DLL_EXPORT pplx::task<std::shared_ptr<FilesList>> getFilesList(
>        utility::string_t path,                          // Folder path e.g. '/folder'
>        boost::optional<utility::string_t> storageName); // Storage name (optional)

Get all files and folders within a folder.

[&#8593;UP&#8593;](StorageApi.md#StorageApi)

### Example
```code
#include <AsposeHtmlCloud.h>

using namespace com::aspose::api;

int main(int argc, char* argv[])
{
    // Get keys from aspose site.
    // There is free quota available. 
    // For more details, see https://purchase.aspose.cloud/pricing

    const utility::string_t clientId = _XPLATSTR("XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX");
    const utility::string_t clientSecret = _XPLATSTR("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    const utility::string_t basePath = _XPLATSTR("https://api.aspose.cloud/v3.0");
    const utility::string_t authPath = _XPLATSTR("https://api.aspose.cloud/connect/token");

    // Create configuration for authorization
    std::shared_ptr<ApiConfiguration> apiConfig(new ApiConfiguration(clientId, clientSecret, basePath, authPath));

    // Create client from configuration
    std::shared_ptr<ApiClient> apiClient(new ApiClient(apiConfig));

    // Create StorageApi
    StorageApi* api = new StorageApi(apiClient);

    utility::string_t folder = _XPLATSTR("HtmlTestDoc");
    boost::optional<utility::string_t> storage = boost::none;

    // Get list of file in the folder
    auto result = api->getFilesList(folder, storage).get();
    
    std::ofstream saved_data(_XPLATSTR("file_list.json"), std::ios::out | std::ios::binary);


    // Save file locally
    if (saved_data.is_open())
    {
        saved_data << result->toString();
        saved_data.close();
    }

    delete api;
}
```
[&#8593;UP&#8593;](StorageApi.md#StorageApi)


<a name="createFolder"></a>
### **createFolder**
>     ASPOSE_DLL_EXPORT pplx::task<std::shared_ptr<MessageResponse>> createFolder(
>        utility::string_t path,                          // Target folder's path e.g. Folder1/Folder2/. The folders will be created recursively.
>        boost::optional<utility::string_t> storageName); // User's source storage name (optional)

Create the folder.

[&#8593;UP&#8593;](StorageApi.md#StorageApi)

### Example
```code
#include <AsposeHtmlCloud.h>

using namespace com::aspose::api;

int main(int argc, char* argv[])
{
    // Get keys from aspose site.
    // There is free quota available. 
    // For more details, see https://purchase.aspose.cloud/pricing

    const utility::string_t clientId = _XPLATSTR("XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX");
    const utility::string_t clientSecret = _XPLATSTR("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    const utility::string_t basePath = _XPLATSTR("https://api.aspose.cloud/v3.0");
    const utility::string_t authPath = _XPLATSTR("https://api.aspose.cloud/connect/token");

    // Create configuration for authorization
    std::shared_ptr<ApiConfiguration> apiConfig(new ApiConfiguration(clientId, clientSecret, basePath, authPath));

    // Create client from configuration
    std::shared_ptr<ApiClient> apiClient(new ApiClient(apiConfig));

    // Create StorageApi
    StorageApi* api = new StorageApi(apiClient);

    utility::string_t path = _XPLATSTR("HtmlTestDoc/TestFolder");
    boost::optional<utility::string_t> storageName = boost::none;
    boost::optional<utility::string_t> versionId = boost::none;
    boost::optional<bool> recursive = true;

    auto result = api->createFolder(path, storageName).get();

    assert(result->getCode() == 200);
    assert(result->getStatus() == _XPLATSTR("OK"));

    // Check is folder exist
    auto result_exist = api->objectExists(path, versionId, storageName).get();

    assert(result_exist->isExists());
    assert(result_exist->isFolder());

    // Delete folder
    auto result_del = api->deleteFolder(path, storageName, recursive).get();

    assert(result_del->getCode() == 200);
    assert(result_del->getStatus() == _XPLATSTR("OK"));

    // Check is folder not exist
    result_exist = api->objectExists(path, versionId, storageName).get();

    assert(!result_exist->isExists());
    assert(!result_exist->isFolder());

    delete api;
}
```
[&#8593;UP&#8593;](StorageApi.md#StorageApi)


<a name="deleteFolder"></a>
### **deleteFolder**
>     ASPOSE_DLL_EXPORT pplx::task<std::shared_ptr<MessageResponse>> deleteFolder(
>        utility::string_t path,                         // Folder path e.g. /Folder1
>        boost::optional<utility::string_t> storageName, // User's storage name (optional)
>        boost::optional<bool> recursive);               // Remove recursivelly inner folder/files. If false and folder contains data than exception is raised. (optional, default to false)

Remove a specific folder.

[&#8593;UP&#8593;](StorageApi.md#StorageApi)

### Example
```code
#include <AsposeHtmlCloud.h>

using namespace com::aspose::api;

int main(int argc, char* argv[])
{
    // Get keys from aspose site.
    // There is free quota available. 
    // For more details, see https://purchase.aspose.cloud/pricing

    const utility::string_t clientId = _XPLATSTR("XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX");
    const utility::string_t clientSecret = _XPLATSTR("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    const utility::string_t basePath = _XPLATSTR("https://api.aspose.cloud/v3.0");
    const utility::string_t authPath = _XPLATSTR("https://api.aspose.cloud/connect/token");

    // Create configuration for authorization
    std::shared_ptr<ApiConfiguration> apiConfig(new ApiConfiguration(clientId, clientSecret, basePath, authPath));

    // Create client from configuration
    std::shared_ptr<ApiClient> apiClient(new ApiClient(apiConfig));

    // Create StorageApi
    StorageApi* api = new StorageApi(apiClient);

    // Create folder
    utility::string_t folder_name = _XPLATSTR("HtmlTestDoc/TestDeleteFolder");
    boost::optional<utility::string_t> storageName = boost::none;
    boost::optional<utility::string_t> versionId = boost::none;
    boost::optional<utility::string_t> dest_storage = boost::none;
    boost::optional<bool> recursive = true;

    auto result = api->createFolder(folder_name, storageName).get();

    assert(result->getCode() == 200);
    assert(result->getStatus() == _XPLATSTR("OK"));

    // Check is folder exist
    auto result_exist = api->objectExists(folder_name, versionId, storageName).get();

    assert(result_exist->isExists());
    assert(result_exist->isFolder());

    // Delete folder
    auto result_del = api->deleteFolder(folder_name, storageName, recursive).get();

    assert(result_del->getCode() == 200);
    assert(result_del->getStatus() == _XPLATSTR("OK"));

    // Check is folder not exist
    result_exist = api->objectExists(folder_name, versionId, storageName).get();

    assert(!result_exist->isExists());
    assert(!result_exist->isFolder());

    delete api;
}
```
[&#8593;UP&#8593;](StorageApi.md#StorageApi)


<a name="copyFolder"></a>
### **copyFolder**
>     ASPOSE_DLL_EXPORT pplx::task<std::shared_ptr<MessageResponse>> copyFolder(
>        utility::string_t srcPath,                           // Source folder path e.g. /Folder1
>        utility::string_t destPath,                          // Destination folder path e.g. /Folder2
>        boost::optional<utility::string_t> srcStorageName,   // User's source storage name (optional)
>        boost::optional<utility::string_t> destStorageName); // User's destination storage name (optional)

Copy a specific folder.

[&#8593;UP&#8593;](StorageApi.md#StorageApi)

### Example
```code
#include <AsposeHtmlCloud.h>

using namespace com::aspose::api;

int main(int argc, char* argv[])
{
    // Get keys from aspose site.
    // There is free quota available. 
    // For more details, see https://purchase.aspose.cloud/pricing

    const utility::string_t clientId = _XPLATSTR("XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX");
    const utility::string_t clientSecret = _XPLATSTR("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    const utility::string_t basePath = _XPLATSTR("https://api.aspose.cloud/v3.0");
    const utility::string_t authPath = _XPLATSTR("https://api.aspose.cloud/connect/token");

    // Create configuration for authorization
    std::shared_ptr<ApiConfiguration> apiConfig(new ApiConfiguration(clientId, clientSecret, basePath, authPath));

    // Create client from configuration
    std::shared_ptr<ApiClient> apiClient(new ApiClient(apiConfig));

    // Create StorageApi
    StorageApi* api = new StorageApi(apiClient);

    utility::string_t srcPath = _XPLATSTR("TestForCopyFolder");
    utility::string_t destPath = _XPLATSTR("TestCopiedFolder");
    boost::optional<utility::string_t> versionId = boost::none;
    boost::optional<utility::string_t> srcStorageName = boost::none;
    boost::optional<utility::string_t> destStorageName = boost::none;
    boost::optional<bool> recursive = true;

    // Create folder for copy
    auto create = api->createFolder(srcPath, srcStorageName).get();

    assert(create->getCode() == 200);
    assert(create->getStatus() == _XPLATSTR("OK"));

    // Check is folder exist
    auto result_exist = api->objectExists(srcPath, versionId, srcStorageName).get();

    assert(result_exist->isExists());
    assert(result_exist->isFolder());

    // Copy folder
    auto copy = api->copyFolder(srcPath, destPath, srcStorageName, destStorageName).get();

    assert(copy->getCode() == 200);
    assert(copy->getStatus() == _XPLATSTR("OK"));

    // Check is srcFolder exist
    result_exist = api->objectExists(srcPath, versionId, srcStorageName).get();

    assert(result_exist->isExists());
    assert(result_exist->isFolder());

    // Check is destFolder exist
    result_exist = api->objectExists(destPath, versionId, destStorageName).get();

    assert(result_exist->isExists());
    assert(result_exist->isFolder());

    // Delete destFolder
    auto result_del = api->deleteFolder(destPath, destStorageName, recursive).get();

    assert(result_del->getCode() == 200);
    assert(result_del->getStatus() == _XPLATSTR("OK"));

    delete api;
}
```
[&#8593;UP&#8593;](StorageApi.md#StorageApi)



<a name="moveFolder"></a>
### **moveFolder**
>     ASPOSE_DLL_EXPORT pplx::task<std::shared_ptr<MessageResponse>> moveFolder(
>        utility::string_t srcPath,                           // Source folder path e.g. /Folder1
>        utility::string_t destPath,                          // Destination folder path e.g. /Folder2
>        boost::optional<utility::string_t> srcStorageName,   // User's source storage name (optional)
>        boost::optional<utility::string_t> destStorageName); // User's destination storage name (optional)

Move a specific folder.

[&#8593;UP&#8593;](StorageApi.md#StorageApi)

### Example
```code
#include <AsposeHtmlCloud.h>

using namespace com::aspose::api;

int main(int argc, char* argv[])
{
    // Get keys from aspose site.
    // There is free quota available. 
    // For more details, see https://purchase.aspose.cloud/pricing

    const utility::string_t clientId = _XPLATSTR("XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX");
    const utility::string_t clientSecret = _XPLATSTR("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    const utility::string_t basePath = _XPLATSTR("https://api.aspose.cloud/v3.0");
    const utility::string_t authPath = _XPLATSTR("https://api.aspose.cloud/connect/token");

    // Create configuration for authorization
    std::shared_ptr<ApiConfiguration> apiConfig(new ApiConfiguration(clientId, clientSecret, basePath, authPath));

    // Create client from configuration
    std::shared_ptr<ApiClient> apiClient(new ApiClient(apiConfig));

    // Create StorageApi
    StorageApi* api = new StorageApi(apiClient);

    utility::string_t srcPath = _XPLATSTR("TestForMoveFolder");
    utility::string_t destPath = _XPLATSTR("TestMovedFolder");
    boost::optional<utility::string_t> versionId = boost::none;
    boost::optional<utility::string_t> srcStorageName = boost::none;
    boost::optional<utility::string_t> destStorageName = boost::none;
    boost::optional<bool> recursive = true;

    // Create folder for move
    auto create = api->createFolder(srcPath, srcStorageName).get();

    assert(create->getCode() == 200);
    assert(create->getStatus() == _XPLATSTR("OK"));

    // Check is folder exist
    auto result_exist = api->objectExists(srcPath, versionId, srcStorageName).get();

    assert(result_exist->isExists());
    assert(result_exist->isFolder());

    // Move folder
    auto move = api->moveFolder(srcPath, destPath, srcStorageName, destStorageName).get();

    assert(move->getCode() == 200);
    assert(move->getStatus() == _XPLATSTR("OK"));

    // Check is srcFolder not exist
    result_exist = api->objectExists(srcPath, versionId, srcStorageName).get();

    assert(!result_exist->isExists());
    assert(!result_exist->isFolder());

    // Check is destFolder exist
    result_exist = api->objectExists(destPath, versionId, destStorageName).get();

    assert(result_exist->isExists());
    assert(result_exist->isFolder());

    // Delete destFolder
    auto result_del = api->deleteFolder(destPath, destStorageName, recursive).get();

    assert(result_del->getCode() == 200);
    assert(result_del->getStatus() == _XPLATSTR("OK"));

    delete api;
}
```
[&#8593;UP&#8593;](StorageApi.md#StorageApi)


<a name="downloadFile"></a>
### **downloadFile**
>     ASPOSE_DLL_EXPORT pplx::task<HttpContent> downloadFile(
>        utility::string_t path,                          // Path of the file including the file name and extension e.g. /file.ext
>        boost::optional<utility::string_t> versionId,    // File's version (optional)
>        boost::optional<utility::string_t> storageName); // User's storage name (optional)

Download a specific file.

[&#8593;UP&#8593;](StorageApi.md#StorageApi)

### Example
```code
#include <AsposeHtmlCloud.h>

using namespace com::aspose::api;

int main(int argc, char* argv[])
{
    // Get current directory
    std::string cur_dir(argv[0]);
    int pos = cur_dir.find_last_of("/\\");
    cur_dir = cur_dir.substr(0, pos + 1); // Include the last slash
    std::wstring w_cur_dir(cur_dir.begin(), cur_dir.end());
	
    // Get keys from aspose site.
    // There is free quota available. 
    // For more details, see https://purchase.aspose.cloud/pricing

    const utility::string_t clientId = _XPLATSTR("XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX");
    const utility::string_t clientSecret = _XPLATSTR("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    const utility::string_t basePath = _XPLATSTR("https://api.aspose.cloud/v3.0");
    const utility::string_t authPath = _XPLATSTR("https://api.aspose.cloud/connect/token");

    
    // Create configuration for authorization
    std::shared_ptr<ApiConfiguration> apiConfig(new ApiConfiguration(clientId, clientSecret, basePath, authPath));

    // Create client from configuration
    std::shared_ptr<ApiClient> apiClient(new ApiClient(apiConfig));

    // Create StorageApi
    StorageApi* api = new StorageApi(apiClient);

    // Create file in storage
    utility::string_t name = _XPLATSTR("test.html");
    std::shared_ptr<HttpContent> file(new HttpContent(w_cur_dir, name));

    boost::optional<utility::string_t> storageName = boost::none;

    utility::string_t path_to_file = _XPLATSTR("HtmlTestDoc/testDowmloadFile.txt");

    auto result = api->uploadFile(path_to_file, file, storageName).get();

    assert(!result->errorsIsSet());

    // Download file from storage
    boost::optional<utility::string_t> versionId = boost::none;
    auto result_download = api->downloadFile(path_to_file, versionId, storageName).get();

    std::ofstream saved_data(_XPLATSTR("testDowmloadFile.txt"), std::ios::out | std::ios::binary);

    // Save file locally
    if (saved_data.is_open())
    {
        result_download.writeTo(saved_data);
        saved_data.close();
    }
    else
    {
        std::cout << "Unable to open file";
    }

    // Clear file
    auto result_clear = api->deleteFile(path_to_file, versionId, storageName).get();

    assert(result_clear->getCode() == 200);
    assert(result_clear->getStatus() == _XPLATSTR("OK"));

    delete api;
}
```
[&#8593;UP&#8593;](StorageApi.md#StorageApi)


<a name="uploadFile"></a>
### **uploadFile**
>     ASPOSE_DLL_EXPORT pplx::task<std::shared_ptr<FilesUploadResult>> uploadFile(
>        utility::string_t path,                          // Path where to upload including filename and extension e.g. /file.ext or /Folder 1/file.ext
>        std::shared_ptr<HttpContent> file,               // File to upload 
>        boost::optional<utility::string_t> storageName); // User's storage name (optional)

Upload a specific file.

[&#8593;UP&#8593;](StorageApi.md#StorageApi)

### Example
```code
#include <AsposeHtmlCloud.h>

using namespace com::aspose::api;

int main(int argc, char* argv[])
{
    // Get current directory
    std::string cur_dir(argv[0]);
    int pos = cur_dir.find_last_of("/\\");
    cur_dir = cur_dir.substr(0, pos + 1); // Include the last slash
    std::wstring w_cur_dir(cur_dir.begin(), cur_dir.end());
	
    // Get keys from aspose site.
    // There is free quota available. 
    // For more details, see https://purchase.aspose.cloud/pricing

    const utility::string_t clientId = _XPLATSTR("XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX");
    const utility::string_t clientSecret = _XPLATSTR("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    const utility::string_t basePath = _XPLATSTR("https://api.aspose.cloud/v3.0");
    const utility::string_t authPath = _XPLATSTR("https://api.aspose.cloud/connect/token");

    
    // Create configuration for authorization
    std::shared_ptr<ApiConfiguration> apiConfig(new ApiConfiguration(clientId, clientSecret, basePath, authPath));

    // Create client from configuration
    std::shared_ptr<ApiClient> apiClient(new ApiClient(apiConfig));

    // Create StorageApi
    StorageApi* api = new StorageApi(apiClient);

    // Create file in storage
    utility::string_t name = _XPLATSTR("test.html");
    std::shared_ptr<HttpContent> file(new HttpContent(w_cur_dir, name));

    boost::optional<utility::string_t> storageName = boost::none;

    utility::string_t path_to_file = _XPLATSTR("HtmlTestDoc/testDowmloadFile.txt");

    auto result = api->uploadFile(path_to_file, file, storageName).get();

    assert(!result->errorsIsSet());

    // Download file from storage
    boost::optional<utility::string_t> versionId = boost::none;
    auto result_download = api->downloadFile(path_to_file, versionId, storageName).get();

    std::ofstream saved_data(_XPLATSTR("testDowmloadFile.txt"), std::ios::out | std::ios::binary);

    // Save file locally
    if (saved_data.is_open())
    {
        result_download.writeTo(saved_data);
        saved_data.close();
    }
    else
    {
        std::cout << "Unable to open file";
    }

    // Clear file
    auto result_clear = api->deleteFile(path_to_file, versionId, storageName).get();

    assert(result_clear->getCode() == 200);
    assert(result_clear->getStatus() == _XPLATSTR("OK"));

    delete api;
}
```
[&#8593;UP&#8593;](StorageApi.md#StorageApi)


<a name="deleteFile"></a>
### **deleteFile**
>     ASPOSE_DLL_EXPORT pplx::task<std::shared_ptr<MessageResponse>> deleteFile(
>        utility::string_t path,                          // Path of the file including file name and extension e.g. /Folder1/file.ext
>        boost::optional<utility::string_t> versionId,    // File's version (optional)
>        boost::optional<utility::string_t> storageName); // User's storage name (optional)

Remove a specific file.

[&#8593;UP&#8593;](StorageApi.md#StorageApi)

### Example
```code
#include <AsposeHtmlCloud.h>

using namespace com::aspose::api;

int main(int argc, char* argv[])
{
    // Get current directory
    std::string cur_dir(argv[0]);
    int pos = cur_dir.find_last_of("/\\");
    cur_dir = cur_dir.substr(0, pos + 1); // Include the last slash
    std::wstring w_cur_dir(cur_dir.begin(), cur_dir.end());
	
    // Get keys from aspose site.
    // There is free quota available. 
    // For more details, see https://purchase.aspose.cloud/pricing

    const utility::string_t clientId = _XPLATSTR("XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX");
    const utility::string_t clientSecret = _XPLATSTR("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    const utility::string_t basePath = _XPLATSTR("https://api.aspose.cloud/v3.0");
    const utility::string_t authPath = _XPLATSTR("https://api.aspose.cloud/connect/token");

    
    // Create configuration for authorization
    std::shared_ptr<ApiConfiguration> apiConfig(new ApiConfiguration(clientId, clientSecret, basePath, authPath));

    // Create client from configuration
    std::shared_ptr<ApiClient> apiClient(new ApiClient(apiConfig));

    // Create StorageApi
    StorageApi* api = new StorageApi(apiClient);

    // Create file in storage
    utility::string_t name = _XPLATSTR("test.html");
    std::shared_ptr<HttpContent> file(new HttpContent(w_cur_dir, name));

    boost::optional<utility::string_t> storageName = boost::none;

    utility::string_t path_to_file = _XPLATSTR("HtmlTestDoc/testDowmloadFile.txt");

    auto result = api->uploadFile(path_to_file, file, storageName).get();

    assert(!result->errorsIsSet());

    // Download file from storage
    boost::optional<utility::string_t> versionId = boost::none;
    auto result_download = api->downloadFile(path_to_file, versionId, storageName).get();

    std::ofstream saved_data(_XPLATSTR("testDowmloadFile.txt"), std::ios::out | std::ios::binary);

    // Save file locally
    if (saved_data.is_open())
    {
        result_download.writeTo(saved_data);
        saved_data.close();
    }
    else
    {
        std::cout << "Unable to open file";
    }

    // Clear file
    auto result_clear = api->deleteFile(path_to_file, versionId, storageName).get();

    assert(result_clear->getCode() == 200);
    assert(result_clear->getStatus() == _XPLATSTR("OK"));

    delete api;
}
```
[&#8593;UP&#8593;](StorageApi.md#StorageApi)


<a name="copyFile"></a>
### **copyFile**
>     ASPOSE_DLL_EXPORT pplx::task<std::shared_ptr<MessageResponse>> copyFile(
>        utility::string_t srcPath,                           // Source file path e.g. /fileSource.ext
>        utility::string_t destPath,                          // Destination file path e.g. /fileDestination.ext
>        boost::optional<utility::string_t> versionId,        // Source file's version, (optional)
>        boost::optional<utility::string_t> srcStorageName,   // User's source storage name (optional)
>        boost::optional<utility::string_t> destStorageName); // User's destination storage name (optional)

Copy a specific file.

[&#8593;UP&#8593;](StorageApi.md#StorageApi)

### Example
```code
#include <AsposeHtmlCloud.h>

using namespace com::aspose::api;

int main(int argc, char* argv[])
{
    // Get current directory
    std::string cur_dir(argv[0]);
    int pos = cur_dir.find_last_of("/\\");
    cur_dir = cur_dir.substr(0, pos + 1); // Include the last slash
    std::wstring w_cur_dir(cur_dir.begin(), cur_dir.end());
	
    // Get keys from aspose site.
    // There is free quota available. 
    // For more details, see https://purchase.aspose.cloud/pricing

    const utility::string_t clientId = _XPLATSTR("XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX");
    const utility::string_t clientSecret = _XPLATSTR("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    const utility::string_t basePath = _XPLATSTR("https://api.aspose.cloud/v3.0");
    const utility::string_t authPath = _XPLATSTR("https://api.aspose.cloud/connect/token");
    
    
    // Create configuration for authorization
    std::shared_ptr<ApiConfiguration> apiConfig(new ApiConfiguration(clientId, clientSecret, basePath, authPath));

    // Create client from configuration
    std::shared_ptr<ApiClient> apiClient(new ApiClient(apiConfig));

    // Create StorageApi
    StorageApi* api = new StorageApi(apiClient);

    // Create file for copy
    utility::string_t name = _XPLATSTR("test.html");
    utility::string_t srcPath = _XPLATSTR("HtmlTestDoc/test_for_copy.html");
    std::shared_ptr<HttpContent> file(new HttpContent(w_cur_dir, name));
    boost::optional<utility::string_t> srcStorageName = boost::none;

    auto result = api->uploadFile(srcPath, file, srcStorageName).get();

    assert(!result->errorsIsSet());

    // Copy file in the storage
    utility::string_t destPath = _XPLATSTR("HtmlTestDoc/copied_file.txt");
    boost::optional<utility::string_t> versionId = boost::none;
    boost::optional<utility::string_t> destStorageName = boost::none;

    auto res_copy = api->copyFile(srcPath, destPath, versionId, srcStorageName, destStorageName).get();

    assert(res_copy->getCode() == 200);
    assert(res_copy->getStatus() == _XPLATSTR("OK"));

    // Clear copy file
    auto result_del = api->deleteFile(destPath, versionId, destStorageName).get();

    assert(result_del->getCode() == 200);
    assert(result_del->getStatus() == _XPLATSTR("OK"));

    delete api;
}
```
[&#8593;UP&#8593;](StorageApi.md#StorageApi)


<a name="moveFile"></a>
### **moveFile**
>     ASPOSE_DLL_EXPORT pplx::task<std::shared_ptr<MessageResponse>> moveFile(
>        utility::string_t srcPath,                           // Source file path e.g. /fileSource.ext
>        utility::string_t destPath,                          // Destination file path e.g. /fileDestination.ext
>        boost::optional<utility::string_t> versionId,        // Source file's version, (optional)
>        boost::optional<utility::string_t> srcStorageName,   // User's source storage name (optional)
>        boost::optional<utility::string_t> destStorageName); // User's destination storage name (optional)

Move a specific file.

[&#8593;UP&#8593;](StorageApi.md#StorageApi)

### Example
```code
#include <AsposeHtmlCloud.h>

using namespace com::aspose::api;

int main(int argc, char* argv[])
{
    // Get current directory
    std::string cur_dir(argv[0]);
    int pos = cur_dir.find_last_of("/\\");
    cur_dir = cur_dir.substr(0, pos + 1); // Include the last slash
    std::wstring w_cur_dir(cur_dir.begin(), cur_dir.end());
	
    // Get keys from aspose site.
    // There is free quota available. 
    // For more details, see https://purchase.aspose.cloud/pricing

    const utility::string_t clientId = _XPLATSTR("XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX");
    const utility::string_t clientSecret = _XPLATSTR("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    const utility::string_t basePath = _XPLATSTR("https://api.aspose.cloud/v3.0");
    const utility::string_t authPath = _XPLATSTR("https://api.aspose.cloud/connect/token");
    
    // Create configuration for authorization
    std::shared_ptr<ApiConfiguration> apiConfig(new ApiConfiguration(clientId, clientSecret, basePath, authPath));

    // Create client from configuration
    std::shared_ptr<ApiClient> apiClient(new ApiClient(apiConfig));

    // Create StorageApi
    StorageApi* api = new StorageApi(apiClient);

    // Create file for move
    utility::string_t name = _XPLATSTR("test.html");
    utility::string_t srcPath = _XPLATSTR("HtmlTestDoc/test_for_moved.html");
    std::shared_ptr<HttpContent> file(new HttpContent(w_cur_dir, name));
    boost::optional<utility::string_t> srcStorageName = boost::none;

    auto result = api->uploadFile(srcPath, file, srcStorageName).get();

    assert(!result->errorsIsSet());

    // Move file in the storage
    utility::string_t destPath = _XPLATSTR("HtmlTestDoc/moved_file.txt");
    boost::optional<utility::string_t> versionId = boost::none;
    boost::optional<utility::string_t> destStorageName = boost::none;

    auto res_move = api->moveFile(srcPath, destPath, versionId, srcStorageName, destStorageName).get();

    assert(res_move->getCode() == 200);
    assert(res_move->getStatus() == _XPLATSTR("OK"));

    // Clear moving file
    auto result_del = api->deleteFile(destPath, versionId, destStorageName).get();

    assert(result_del->getCode() == 200);
    assert(result_del->getStatus() == _XPLATSTR("OK"));

    delete api;
}
```
[&#8593;UP&#8593;](StorageApi.md#StorageApi)