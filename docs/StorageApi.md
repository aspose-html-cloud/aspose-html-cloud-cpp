<a name="StorageApi"></a>
## StorageApi

All URIs are relative to *https://api.aspose.cloud/v4.0*

| Method                                               | Description                                  |
|------------------------------------------------------|----------------------------------------------|
| [**getDiscUsage**](StorageApi.md#getdiscusage)       | Check the disk usage of the current account. |
| [**objectExists**](StorageApi.md#objectexists)       | Check if a specific file or folder exists.   |
| [**storageExists**](StorageApi.md#storageexists)     | Check if storage exists.                     |
| [**getFilesList**](StorageApi.md#getfileslist)       | Get all files and folders within a folder.   |
| [**createFolder**](StorageApi.md#createfolder)       | Create the folder.                           |
| [**deleteFolder**](StorageApi.md#deletefolder)       | Remove a specific folder.                    |
| [**downloadFile**](StorageApi.md#downloadfile)       | Download a specific file.                    |
| [**uploadFile**](StorageApi.md#uploadfile)           | Upload a specific file.                      |
| [**deleteFile**](StorageApi.md#deletefile)           | Remove a specific file.                      |

## **getDiscUsage**
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
    const utility::string_t basePath = _XPLATSTR("https://api.aspose.cloud/v4.0");
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

## **objectExists**
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
    const utility::string_t basePath = _XPLATSTR("https://api.aspose.cloud/v4.0");
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
    const utility::string_t basePath = _XPLATSTR("https://api.aspose.cloud/v4.0");
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
    const utility::string_t basePath = _XPLATSTR("https://api.aspose.cloud/v4.0");
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
    const utility::string_t basePath = _XPLATSTR("https://api.aspose.cloud/v4.0");
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
    const utility::string_t basePath = _XPLATSTR("https://api.aspose.cloud/v4.0");
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
    const utility::string_t basePath = _XPLATSTR("https://api.aspose.cloud/v4.0");
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
    const utility::string_t basePath = _XPLATSTR("https://api.aspose.cloud/v4.0");
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
    const utility::string_t basePath = _XPLATSTR("https://api.aspose.cloud/v4.0");
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
