<a name="ImportApi"></a>
## ImportApi

All URIs are relative to *https://api.aspose.cloud/v3.0*

Method | HTTP request | Description
------------- | ------------- | -------------
[**getConvertMarkdownToHtml**](ImportApi.md#getConvertMarkdownToHtml) | **GET** /html/\{name\}/import/md | Converts the Markdown document (located on storage) to HTML and returns resulting file in response content.
[**postConvertMarkdownInRequestToHtml**](ImportApi.md#postConvertMarkdownInRequestToHtml) | **POST** /html/\{name\}/convert/md | Converts the Markdown document (in request content) to HTML and uploads resulting file to storage by specified path.
[**putConvertMarkdownToHtml**](ImportApi.md#putConvertMarkdownToHtml) | **PUT** /html/\{name\}/import/md | Converts the Markdown document (located on storage) to HTML and uploads resulting file to storage by specified path.


<a name="getConvertMarkdownToHtml"></a>
### **getConvertMarkdownToHtml**
>     ASPOSE_DLL_EXPORT pplx::task<HttpContent> getConvertMarkdownToHtml(
>        utility::string_t name,                      // Document name.
>        boost::optional<utility::string_t> folder,   // Source document folder. (optional)
>        boost::optional<utility::string_t> storage); // Source document storage. (optional)

Converts the Markdown document (located on storage) to HTML and returns resulting file in response content.

[&#8593;UP&#8593;](ImportApi.md#ImportApi)

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

    // Create ImportApi
    ImportApi* api = new ImportApi(apiClient);

    // Create StorageApi
    StorageApi* storage_api = new StorageApi(apiClient);

    // File name for conversion
    utility::string_t name = _XPLATSTR("test.md");

    // Folder name in the storage (should already exist)
    utility::string_t folder = _XPLATSTR("HtmlTestDoc");

    // Storage, received at registration, default is none
    boost::optional<utility::string_t> storage = boost::none;

    // Prepare file stream to upload
    std::shared_ptr<HttpContent> file(new HttpContent(w_cur_dir, name));

    // Path to file in the storage
    utility::string_t path_to_file = folder + _XPLATSTR("/") + name;

    // Upload file to the storage
    auto res = storage_api->uploadFile(path_to_file, file, storage).get();

    // Check for errors
    assert(!res->errorsIsSet());

    // Convert markdown file in the storage to html and return html file
    auto result = api->getConvertMarkdownToHtml(name, folder, storage).get();

    // Save result to files
    std::ofstream saved_data("getConvertMarkdownToHtml.html", std::ios::out | std::ios::binary);
    result.writeTo(saved_data);
    saved_data.close();

    delete api;
    delete storage_api;
}
```
[&#8593;UP&#8593;](ImportApi.md#ImportApi)


<a name="postConvertMarkdownInRequestToHtml"></a>
### **postConvertMarkdownInRequestToHtml**
>     ASPOSE_DLL_EXPORT pplx::task<HttpContent> postConvertMarkdownInRequestToHtml(
>        utility::string_t outPath,                   // Full resulting file path in the storage (ex. /folder1/folder2/result.html)
>        std::shared_ptr<HttpContent> file,           // A file to be converted.
>        boost::optional<utility::string_t> storage); // The source and resulting document storage. (optional)
	
Converts the Markdown document (in request content) to HTML and uploads resulting file to storage by specified path.

[&#8593;UP&#8593;](ImportApi.md#ImportApi)

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

    // Create ImportApi
    ImportApi* api = new ImportApi(apiClient);

    // Create StorageApi
    StorageApi* storage_api = new StorageApi(apiClient);

    // File name for conversion
    utility::string_t name = _XPLATSTR("test.md");

    // Folder name in the storage (should already exist)
    utility::string_t folder = _XPLATSTR("HtmlTestDoc");

    // Storage, received at registration, default is none
    boost::optional<utility::string_t> storage = boost::none;

    // Prepare file stream to upload
    std::shared_ptr<HttpContent> file(new HttpContent(w_cur_dir, name));

    utility::string_t result_name = _XPLATSTR("postConvertMarkdownInRequestToHtml.html");

    // Path to file in the storage for save result
    utility::string_t path_to_result = folder + _XPLATSTR("/") + result_name;

    // Convert markdown file in request to html and save result in storage
    auto result = api->postConvertMarkdownInRequestToHtml(path_to_result, file, storage).get();

    // Check exist file
    boost::optional<utility::string_t> versionId = std::wstring(_XPLATSTR(""));
    auto result_exist = storage_api->objectExists(path_to_result, versionId, storage).get();

    assert(result_exist->isExists());
    assert(!result_exist->isFolder());

    // Download file from storage
    auto result_download = storage_api->downloadFile(path_to_result, versionId, storage).get();

    // Save result to files
    std::ofstream saved_data(result_name, std::ios::out | std::ios::binary);
    result_download.writeTo(saved_data);
    saved_data.close();

    delete api;
    delete storage_api;
}
```
[&#8593;UP&#8593;](ImportApi.md#ImportApi)


<a name="putConvertMarkdownToHtml"></a>
### **putConvertMarkdownToHtml**
>     ASPOSE_DLL_EXPORT pplx::task<HttpContent> putConvertMarkdownToHtml(
>        utility::string_t name,                      // Document name.
>        utility::string_t outPath,                   // Full resulting file path in the storage (ex. /folder1/folder2/result.html)
>        boost::optional<utility::string_t> folder,   // The source document folder. (optional)
>        boost::optional<utility::string_t> storage); // The source and resulting document storage. (optional)

Converts the Markdown document (located on storage) to HTML and uploads resulting file to storage by specified path.

[&#8593;UP&#8593;](ImportApi.md#ImportApi)

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

    // Create ImportApi
    ImportApi* api = new ImportApi(apiClient);

    // Create StorageApi
    StorageApi* storage_api = new StorageApi(apiClient);

    // File name for conversion
    utility::string_t name = _XPLATSTR("test.md");

    // Folder name in the storage (should already exist)
    utility::string_t folder = _XPLATSTR("HtmlTestDoc");

    // Storage, received at registration, default is none
    boost::optional<utility::string_t> storage = boost::none;

    // Prepare file stream to upload
    std::shared_ptr<HttpContent> file(new HttpContent(w_cur_dir, name));

    // Path to file in the storage
    utility::string_t path_to_file = folder + _XPLATSTR("/") + name;

    // Upload file to the storage
    auto res = storage_api->uploadFile(path_to_file, file, storage).get();

    // Check for errors
    assert(!res->errorsIsSet());

    auto result_name = _XPLATSTR("putConvertMarkdownToHtml.html");
    auto result_path = folder + _XPLATSTR("/") + result_name;

    // Convert markdown file in the storage to html and save result in the storage
    auto result = api->putConvertMarkdownToHtml(name, result_path, folder, storage).get();

    // Check exist file
    boost::optional<utility::string_t> versionId = std::wstring(_XPLATSTR(""));
    auto result_exist = storage_api->objectExists(result_path, versionId, storage).get();

    assert(result_exist->isExists());
    assert(!result_exist->isFolder());

    // Download file from storage
    auto result_download = storage_api->downloadFile(result_path, versionId, storage).get();

    // Save result to files
    std::ofstream saved_data(result_name, std::ios::out | std::ios::binary);
    result_download.writeTo(saved_data);
    saved_data.close();

    delete api;
    delete storage_api;
}
```
[&#8593;UP&#8593;](ImportApi.md#ImportApi)