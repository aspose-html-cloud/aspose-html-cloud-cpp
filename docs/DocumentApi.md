<a name="DocumentApi"></a>
## DocumentApi

All URIs are relative to *https://api.aspose.cloud/v3.0*

Method | HTTP request | Description
------------- | ------------- | -------------
[**getDocumentByUrl**](DocumentApi.md#getDocumentByUrl) | **GET** /html/download | Return all HTML page with linked resources packaged as a ZIP archive by the source page URL.
[**getDocumentFragmentByXPath**](DocumentApi.md#getDocumentFragmentByXPath) | **GET** /html/\{name\}/fragments/\{outFormat\} | Return list of HTML fragments matching the specified XPath query. 
[**getDocumentFragmentByXPathByUrl**](DocumentApi.md#getDocumentFragmentByXPathByUrl) | **GET** /html/fragments/\{outFormat\} | Return list of HTML fragments matching the specified XPath query by the source page URL.
[**getDocumentFragmentsByCSSSelector**](DocumentApi.md#getDocumentFragmentsByCSSSelector) | **GET** /html/\{name\}/fragments/css/\{outFormat\} | Return list of HTML fragments matching the specified CSS selector.
[**getDocumentFragmentsByCSSSelectorByUrl**](DocumentApi.md#getDocumentFragmentsByCSSSelectorByUrl) | **GET** /html/fragments/css/\{outFormat\} | Return list of HTML fragments matching the specified CSS selector by the source page URL.
[**getDocumentImages**](DocumentApi.md#getDocumentImages) | **GET** /html/\{name\}/images/all | Return all HTML document images packaged as a ZIP archive.
[**getDocumentImagesByUrl**](DocumentApi.md#getDocumentImagesByUrl) | **GET** /html/images/all | Return all HTML page images packaged as a ZIP archive by the source page URL.


<a name="getDocumentByUrl"></a>
### **getDocumentByUrl**
>     ASPOSE_DLL_EXPORT pplx::task<HttpContent> getDocumentByUrl(
>        utility::string_t sourceUrl); // Source page URL.

Return all HTML page with linked resources packaged as a ZIP archive by the source page URL.

[&#8593;UP&#8593;](DocumentApi.md#DocumentApi)

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

    // Create DocumentApi
    DocumentApi* api = new DocumentApi(apiClient);

    // Url for processing
    utility::string_t sourceUrl = _XPLATSTR("https://stallman.org/articles/anonymous-payments-thru-phones.html");
    
    // Get html page and all linked resources as zip.
    auto result = api->getDocumentByUrl(sourceUrl).get();

    // Save result to files
    std::ofstream saved_data("DownloadedSite.zip", std::ios::out | std::ios::binary);
    result.writeTo(saved_data);
    saved_data.close();

    delete api;
}
```
[&#8593;UP&#8593;](DocumentApi.md#DocumentApi)


<a name="getDocumentFragmentByXPath"></a>
### **getDocumentFragmentByXPath**
>     ASPOSE_DLL_EXPORT pplx::task<HttpContent> getDocumentFragmentByXPath(
>        utility::string_t name,                     // The document name.
>        utility::string_t xPath,                    // XPath query string.
>        utility::string_t outFormat,                // Output format. Possible values: 'plain' and 'json'.
>        boost::optional<utility::string_t> storage, // The document storage. (optional)
>        boost::optional<utility::string_t> folder); // The document folder. (optional)

Return list of HTML fragments matching the specified XPath query.

[&#8593;UP&#8593;](DocumentApi.md#DocumentApi)

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

    // Create DocumentApi
    DocumentApi* api = new DocumentApi(apiClient);

    // Create StorageApi
    StorageApi* storage_api = new StorageApi(apiClient);

    // File name for conversion
    utility::string_t name = _XPLATSTR("test1.html");

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

    // Get all 'p' tags from html document
    utility::string_t xPath = _XPLATSTR(".//p");

    // Return as plain text
    utility::string_t outFormat = _XPLATSTR("plain");

    // Return list of HTML fragments matching the specified XPath query.
    auto result = api->getDocumentFragmentByXPath(name, xPath, outFormat, storage, folder).get();

    utility::string_t result_name = _XPLATSTR("getDocumentFragmentByXPath.txt");

    // Save result to files
    std::ofstream saved_data(result_name, std::ios::out | std::ios::binary);
    result.writeTo(saved_data);
    saved_data.close();

    delete api;
    delete storage_api;
}
```
[&#8593;UP&#8593;](DocumentApi.md#DocumentApi)


<a name="getDocumentFragmentByXPathByUrl"></a>
### **getDocumentFragmentByXPathByUrl**
>     ASPOSE_DLL_EXPORT pplx::task<HttpContent> getDocumentFragmentByXPathByUrl(
>        utility::string_t sourceUrl,  // Source page URL.
>        utility::string_t xPath,      // XPath query string.
>        utility::string_t outFormat); // Output format. Possible values: 'plain' and 'json'.

Return list of HTML fragments matching the specified XPath query by the source page URL.

[&#8593;UP&#8593;](DocumentApi.md#DocumentApi)

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

    // Create DocumentApi
    DocumentApi* api = new DocumentApi(apiClient);

    // Options
    utility::string_t sourceUrl = _XPLATSTR("https://stallman.org/articles/anonymous-payments-thru-phones.html");
    utility::string_t xPath = _XPLATSTR(".//p");
    utility::string_t outFormat = _XPLATSTR("json");

    // Return list of HTML fragments matching the specified XPath query by the source page URL.
    auto result = api->getDocumentFragmentByXPathByUrl(sourceUrl, xPath, outFormat).get();

    utility::string_t result_name = _XPLATSTR("getDocumentFragmentByXPathByUrl.json");

    // Save result to files
    std::ofstream saved_data(result_name, std::ios::out | std::ios::binary);
    result.writeTo(saved_data);
    saved_data.close();

    delete api;
}
```
[&#8593;UP&#8593;](DocumentApi.md#DocumentApi)


<a name="getDocumentFragmentsByCSSSelector"></a>
### **getDocumentFragmentsByCSSSelector**
>     ASPOSE_DLL_EXPORT pplx::task<HttpContent> getDocumentFragmentsByCSSSelector(
>        utility::string_t name,                      // The document name.
>        utility::string_t selector,                  // CSS selector string.
>        utility::string_t outFormat,                 // Output format. Possible values: 'plain' and 'json'.
>        boost::optional<utility::string_t> folder,   // The document folder. (optional)
>        boost::optional<utility::string_t> storage); // The document storage. (optional)

Return list of HTML fragments matching the specified CSS selector.

[&#8593;UP&#8593;](DocumentApi.md#DocumentApi)

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

    //Create DocumentApi
    DocumentApi* api = new DocumentApi(apiClient);

    // Create StorageApi
    StorageApi* storage_api = new StorageApi(apiClient);

    // File name for conversion
    utility::string_t name = _XPLATSTR("test1.html");

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

    // Get fragments from document
    utility::string_t selector = _XPLATSTR("div p");

    // Return as plain text
    utility::string_t outFormat = _XPLATSTR("plain");

    // Return list of HTML fragments matching the specified CSS selector.
    auto result = api->getDocumentFragmentsByCSSSelector(name, selector, outFormat, folder, storage).get();

    utility::string_t result_name = _XPLATSTR("getDocumentFragmentsByCSSSelector.txt");

    // Save result to files
    std::ofstream saved_data(result_name, std::ios::out | std::ios::binary);
    result.writeTo(saved_data);
    saved_data.close();

    delete api;
    delete storage_api;
}
```
[&#8593;UP&#8593;](DocumentApi.md#DocumentApi)


<a name="getDocumentFragmentsByCSSSelectorByUrl"></a>
### **getDocumentFragmentsByCSSSelectorByUrl**
>     ASPOSE_DLL_EXPORT pplx::task<HttpContent> getDocumentFragmentsByCSSSelectorByUrl(
>        utility::string_t sourceUrl,  // Source page URL.
>        utility::string_t selector,   // CSS selector string.
>        utility::string_t outFormat); // Output format. Possible values: 'plain' and 'json'.

Return list of HTML fragments matching the specified CSS selector by the source page URL.

[&#8593;UP&#8593;](DocumentApi.md#DocumentApi)

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

    // Create DocumentApi
    DocumentApi* api = new DocumentApi(apiClient);

    // Options
    utility::string_t sourceUrl = _XPLATSTR("https://www.w3schools.com/cssref/css_selectors.asp");
    utility::string_t selector = _XPLATSTR("a[href$='.asp']");
    utility::string_t outFormat = _XPLATSTR("plain");

    // Return list of HTML fragments matching the specified CSS selector by the source page URL.
    auto result = api->getDocumentFragmentsByCSSSelectorByUrl(sourceUrl, selector, outFormat).get();

    utility::string_t result_name = _XPLATSTR("getDocumentFragmentsByCSSSelectorByUrl.txt");

    // Save result to files
    std::ofstream saved_data(result_name, std::ios::out | std::ios::binary);
    result.writeTo(saved_data);
    saved_data.close();

    delete api;
}
```
[&#8593;UP&#8593;](DocumentApi.md#DocumentApi)


<a name="getDocumentImages"></a>
### **getDocumentImages**
>     ASPOSE_DLL_EXPORT pplx::task<HttpContent> getDocumentImages(
>        utility::string_t name,                      // The document name.
>        boost::optional<utility::string_t> folder,   // The document folder. (optional)
>        boost::optional<utility::string_t> storage); // The document storage. (optional)

Return all HTML document images packaged as a ZIP archive.

[&#8593;UP&#8593;](DocumentApi.md#DocumentApi)

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

    // Create DocumentApi
    DocumentApi* api = new DocumentApi(apiClient);

    // Create StorageApi
    StorageApi* storage_api = new StorageApi(apiClient);

    // File name for conversion
    utility::string_t name = _XPLATSTR("test.zip");

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

    // Get images from document
    auto result = api->getDocumentImages(name, folder, storage).get();

    utility::string_t result_name = _XPLATSTR("getDocumentImages.zip");

    // Save result to files
    std::ofstream saved_data(result_name, std::ios::out | std::ios::binary);
    result.writeTo(saved_data);
    saved_data.close();

    delete api;
    delete storage_api;
}
```
[&#8593;UP&#8593;](DocumentApi.md#DocumentApi)


<a name="getDocumentImagesByUrl"></a>
### **getDocumentImagesByUrl**
>     ASPOSE_DLL_EXPORT pplx::task<HttpContent> getDocumentImagesByUrl(
>        utility::string_t sourceUrl); // Source page URL.

Return all HTML page images packaged as a ZIP archive by the source page URL.

[&#8593;UP&#8593;](DocumentApi.md#DocumentApi)

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

    // Create DocumentApi
    DocumentApi* api = new DocumentApi(apiClient);

    // Get all images from url
    auto result = api->getDocumentImagesByUrl(_XPLATSTR("https://lenta.ru")).get();

    utility::string_t result_name = _XPLATSTR("getDocumentImagesByUrl.zip");

    // Save result to files
    std::ofstream saved_data(result_name, std::ios::out | std::ios::binary);
    result.writeTo(saved_data);
    saved_data.close();

    delete api;
}
```
[&#8593;UP&#8593;](DocumentApi.md#DocumentApi)


