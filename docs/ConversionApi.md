<a name="ConversionApi"></a>
## ConversionApi

All URIs are relative to *https://api.aspose.cloud/v3.0*

Method | HTTP request | Description
------------- | ------------- | -------------
[**getConvertDocumentToImage**](ConversionApi.md#getConvertDocumentToImage) | **GET** /html/\{name\}/convert/image/\{outFormat\} | Convert the HTML, EPUB, SVG document from the storage by its name to the specified image format.
[**getConvertDocumentToImageByUrl**](ConversionApi.md#getConvertDocumentToImageByUrl) | **GET** /html/convert/image/\{outFormat\} | Convert the HTML page from the web by its URL to the specified image format.
[**getConvertDocumentToPdf**](ConversionApi.md#getConvertDocumentToPdf) | **GET** /html/\{name\}/convert/pdf | Convert the HTML, EPUB, SVG document from the storage by its name to PDF.
[**getConvertDocumentToPdfByUrl**](ConversionApi.md#getConvertDocumentToPdfByUrl) | **GET** /html/convert/pdf | Convert the HTML page from the web by its URL to PDF.
[**getConvertDocumentToXps**](ConversionApi.md#getConvertDocumentToXps) | **GET** /html/\{name\}/convert/xps | Convert the HTML, EPUB, SVG document from the storage by its name to XPS.
[**getConvertDocumentToXpsByUrl**](ConversionApi.md#getConvertDocumentToXpsByUrl) | **GET** /html/convert/xps | Convert the HTML page from the web by its URL to XPS.
[**postConvertDocumentInRequestToImage**](ConversionApi.md#postConvertDocumentInRequestToImage) | **POST** /html/convert/image/\{outFormat\} | Converts the HTML, EPUB, SVG document (in request content) to the specified image format and uploads resulting file to storage.
[**postConvertDocumentInRequestToPdf**](ConversionApi.md#postConvertDocumentInRequestToPdf) | **POST** /html/convert/pdf | CConverts the HTML, EPUB, SVG document (in request content) to PDF and uploads resulting file to storage.
[**postConvertDocumentInRequestToXps**](ConversionApi.md#postConvertDocumentInRequestToXps) | **POST** /html/convert/xps | Converts the HTML, EPUB, SVG document (in request content) to XPS and uploads resulting file to storage.
[**putConvertDocumentToImage**](ConversionApi.md#putConvertDocumentToImage) | **PUT** /html/\{name\}/convert/image/\{outFormat\} | Converts the HTML, EPUB, SVG document (located on storage) to the specified image format and uploads resulting file to storage.
[**putConvertDocumentToPdf**](ConversionApi.md#putConvertDocumentToPdf) | **PUT** /html/\{name\}/convert/pdf | Converts the HTML, EPUB, SVG document (located on storage) to PDF and uploads resulting file to storage.
[**putConvertDocumentToXps**](ConversionApi.md#putConvertDocumentToXps) | **PUT** /html/\{name\}/convert/xps | Converts the HTML, EPUB, SVG document (located on storage) to XPS and uploads resulting file to storage.
[**getConvertDocumentToMHTMLByUrl**](ConversionApi.md#getConvertDocumentToMHTMLByUrl) | **GET** /html/convert/mhtml | Converts the HTML page from Web by its URL to MHTML returns resulting file in response content.
[**getConvertDocumentToMarkdown**](ConversionApi.md#getConvertDocumentToMarkdown) | **GET** /html/\{name\}/convert/md | Converts the HTML document (located on storage) to Markdown and returns resulting file in response content.
[**postConvertDocumentInRequestToMarkdown**](ConversionApi.md#postConvertDocumentInRequestToMarkdown) | **POST** /html/convert/md | Converts the HTML document (in request content) to Markdown and uploads resulting file to storage by specified path.
[**putConvertDocumentToMarkdown**](ConversionApi.md#putConvertDocumentToMarkdown) | **PUT** /html/\{name\}/convert/md | Converts the HTML document (located on storage) to Markdown and uploads resulting file to storage by specified path.


<a name="getConvertDocumentToImage"></a>
### **getConvertDocumentToImage**
>     ASPOSE_DLL_EXPORT pplx::task<HttpContent> getConvertDocumentToImage(
>        utility::string_t name,                      // Document name(html, epub, svg formats).
>        utility::string_t outFormat,                 // Resulting image format(jpeg, png, bmp, tiff, gif).
>        boost::optional<int32_t> width,              // Resulting image width in points (1/96 inch). (optional)
>        boost::optional<int32_t> height,             // Resulting image height in points (1/96 inch). (optional)
>        boost::optional<int32_t> leftMargin,         // Left resulting image margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> rightMargin,        // Right resulting image margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> topMargin,          // Top resulting image margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> bottomMargin,       // Bottom resulting image margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> resolution,         // Resolution of resulting image. Default is 96 dpi. (optional)
>        boost::optional<utility::string_t> folder,   // The source document folder in the storage. (optional)
>        boost::optional<utility::string_t> storage); // The source document storage. (optional)

Convert the HTML, EPUB, SVG document from the storage by its name to the specified image format.

[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)

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

    // Create ConversionApi
    ConversionApi* api = new ConversionApi(apiClient);

    // Create StorageApi
    StorageApi* storage_api = new StorageApi(apiClient);

    // File name for conversion
    utility::string_t name = _XPLATSTR("test.html");

    // Folder name in the storage (should already exist)
    utility::string_t folder = _XPLATSTR("HtmlTestDoc");

    // Storage, received at registration, default is none
    boost::optional<utility::string_t> storage = boost::none;

    // Upload file for conversion to storage (path = w_cur_dir, name = "test.html")
    std::shared_ptr<HttpContent> file(new HttpContent(w_cur_dir, name));

    // Path to file in the storage
    utility::string_t path_to_file = folder + _XPLATSTR("/test.html");

    // Upload file to the storage
    auto res = storage_api->uploadFile(path_to_file, file, storage).get();

    // Check for errors
    assert(!res->errorsIsSet());

    // Parameters for conversion
    utility::string_t outFormat = _XPLATSTR("png");
    boost::optional<int32_t> width = 800;
    boost::optional<int32_t> height = 1000;
    boost::optional<int32_t> leftMargin = 20;
    boost::optional<int32_t> rightMargin = 20;
    boost::optional<int32_t> topMargin = 20;
    boost::optional<int32_t> bottomMargin = 20;
    boost::optional<int32_t> resolution = 300;

    // Convert html file to png
    auto result = api->getConvertDocumentToImage(name, outFormat,
        width, height, leftMargin, rightMargin, topMargin, bottomMargin, resolution, folder, storage).get();

    // Save result to files
    std::ofstream saved_data(_XPLATSTR("ConvertResult.") + outFormat + _XPLATSTR(".zip"), std::ios::out | std::ios::binary);

    result.writeTo(saved_data);
    saved_data.close();

    delete api;
    delete storage_api;
}
```
[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)


<a name="getConvertDocumentToImageByUrl"></a>
### **getConvertDocumentToImageByUrl**
>        ASPOSE_DLL_EXPORT pplx::task<HttpContent> getConvertDocumentToImageByUrl(
>        utility::string_t sourceUrl,           // Source page URL.
>        utility::string_t outFormat,           // Resulting image format(jpeg, png, bmp, tiff, gif).
>        boost::optional<int32_t> width,        // Resulting image width in points (1/96 inch). (optional)
>        boost::optional<int32_t> height,       // Resulting image height in points (1/96 inch). (optional)
>        boost::optional<int32_t> leftMargin,   // Left resulting image margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> rightMargin,  // Right resulting image margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> topMargin,    // Top resulting image margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> bottomMargin, // Bottom resulting image margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> resolution);  // Resolution of resulting image. Default is 96 dpi. (optional)

Convert the HTML page from the web by its URL to the specified image format.

[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)

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

    // Create ConversionApi
    ConversionApi* api = new ConversionApi(apiClient);

    // Source url for conversion
    utility::string_t sourceUrl = _XPLATSTR("https://stallman.org/articles/anonymous-payments-thru-phones.html");

    // Parameters for conversion
    boost::optional<int32_t> width = 800;
    boost::optional<int32_t> height = 1000;
    boost::optional<int32_t> leftMargin = 20;
    boost::optional<int32_t> rightMargin = 20;
    boost::optional<int32_t> topMargin = 20;
    boost::optional<int32_t> bottomMargin = 20;
    boost::optional<int32_t> resolution = 300;

    // Convert html document by url to jpeg
    auto result = api->getConvertDocumentToImageByUrl(sourceUrl, _XPLATSTR("jpeg"),
        width, height, leftMargin, rightMargin, topMargin, bottomMargin, resolution).get();

    // Save result to files
    std::ofstream saved_data(_XPLATSTR("ConvertUrlToJpg.zip"), std::ios::out | std::ios::binary);

    result.writeTo(saved_data);
    saved_data.close();

    delete api;
}
```
[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)


<a name="getConvertDocumentToPdf"></a>
### **getConvertDocumentToPdf**
>     ASPOSE_DLL_EXPORT pplx::task<HttpContent> getConvertDocumentToPdf(
>        utility::string_t name,                      // Document name(html, epub, svg).
>        boost::optional<int32_t> width,              // Resulting document page width in points (1/96 inch). (optional)
>        boost::optional<int32_t> height,             // Resulting document page height in points (1/96 inch). (optional)
>        boost::optional<int32_t> leftMargin,         // Left resulting document page margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> rightMargin,        // Right resulting document page margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> topMargin,          // Top resulting document page margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> bottomMargin,       // Bottom resulting document page margin in points (1/96 inch). (optional)
>        boost::optional<utility::string_t> folder,   // The source document folder. (optional)
>        boost::optional<utility::string_t> storage); // The source document storage. (optional)

Convert the HTML, EPUB, SVG document from the storage by its name to PDF.

[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)

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

    // Create ConversionApi
    ConversionApi* api = new ConversionApi(apiClient);

    // Create StorageApi
    StorageApi* storage_api = new StorageApi(apiClient);

    // File name for conversion
    utility::string_t name = _XPLATSTR("test.html");

    // Folder name in the storage (should already exist)
    utility::string_t folder = _XPLATSTR("HtmlTestDoc");

    // Storage, received at registration, default is none
    boost::optional<utility::string_t> storage = boost::none;

    // Upload file for conversion to storage (path = w_cur_dir name = "test.html")
    std::shared_ptr<HttpContent> file(new HttpContent(w_cur_dir, name));

    // Path to file in the storage
    utility::string_t path_to_file = folder + _XPLATSTR("/") + name;

    // Upload file to the storage
    auto res = storage_api->uploadFile(path_to_file, file, storage).get();

    // Check for errors
    assert(!res->errorsIsSet());

    // Parameters for conversion
    boost::optional<int32_t> width = 800;
    boost::optional<int32_t> height = 1000;
    boost::optional<int32_t> leftMargin = 20;
    boost::optional<int32_t> rightMargin = 20;
    boost::optional<int32_t> topMargin = 20;
    boost::optional<int32_t> bottomMargin = 20;

    // Convert html file to pdf
    auto result = api->getConvertDocumentToPdf(name, width, height, leftMargin, rightMargin, topMargin, bottomMargin, folder, storage).get();

    // Save result to files
    std::ofstream saved_data(_XPLATSTR("ConvertHtmlToPdf.pdf"), std::ios::out | std::ios::binary);

    result.writeTo(saved_data);
    saved_data.close();

    delete api;
    delete storage_api;
}
```
[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)


<a name="getConvertDocumentToPdfByUrl"></a>
### **getConvertDocumentToPdfByUrl**
>     ASPOSE_DLL_EXPORT pplx::task<HttpContent> getConvertDocumentToPdfByUrl(
>        utility::string_t sourceUrl,            // Source page URL.
>        boost::optional<int32_t> width,         // Resulting document page width in points (1/96 inch). (optional)
>        boost::optional<int32_t> height,        // Resulting document page height in points (1/96 inch). (optional)
>        boost::optional<int32_t> leftMargin,    // Left resulting document page margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> rightMargin,   // Right resulting document page margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> topMargin,     // Top resulting document page margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> bottomMargin); // Bottom resulting document page margin in points (1/96 inch). (optional)

Convert the HTML page from the web by its URL to PDF.

[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)

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

    // Create ConversionApi
    ConversionApi* api = new ConversionApi(apiClient);

    // Source url for conversion
    utility::string_t sourceUrl = _XPLATSTR("https://stallman.org/articles/anonymous-payments-thru-phones.html");

    // Parameters for conversion
    boost::optional<int32_t> width = 800;
    boost::optional<int32_t> height = 1000;
    boost::optional<int32_t> leftMargin = 20;
    boost::optional<int32_t> rightMargin = 20;
    boost::optional<int32_t> topMargin = 20;
    boost::optional<int32_t> bottomMargin = 20;

    // Convert html from url to pdf
    auto result = api->getConvertDocumentToPdfByUrl(sourceUrl, width, height, leftMargin, rightMargin, topMargin, bottomMargin).get();

    // Save result to files
    std::ofstream saved_data(_XPLATSTR("ConvertToPdfFromUrl.pdf"), std::ios::out | std::ios::binary);

    result.writeTo(saved_data);
    saved_data.close();

    delete api;
}
```
[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)


<a name="getConvertDocumentToXps"></a>
### **getConvertDocumentToXps**
>     ASPOSE_DLL_EXPORT pplx::task<HttpContent> getConvertDocumentToXps(
>        utility::string_t name,                      // Document name(html, epub, svg).
>        boost::optional<int32_t> width,              // Resulting document page width in points (1/96 inch). (optional)
>        boost::optional<int32_t> height,             // Resulting document page height in points (1/96 inch). (optional)
>        boost::optional<int32_t> leftMargin,         // Left resulting document page margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> rightMargin,        // Right resulting document page margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> topMargin,          // Top resulting document page margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> bottomMargin,       // Bottom resulting document page margin in points (1/96 inch). (optional)
>        boost::optional<utility::string_t> folder,   // The source document folder. (optional)
>        boost::optional<utility::string_t> storage); // The source document storage. (optional)

Convert the HTML, EPUB, SVG document from the storage by its name to XPS.

[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)

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

    // Create ConversionApi
    ConversionApi* api = new ConversionApi(apiClient);

    // Create StorageApi
    StorageApi* storage_api = new StorageApi(apiClient);

    // File name for conversion
    utility::string_t name = _XPLATSTR("test.html");

    // Folder name in the storage (should already exist)
    utility::string_t folder = _XPLATSTR("HtmlTestDoc");

    // Storage, received at registration, default is none
    boost::optional<utility::string_t> storage = boost::none;

    // Upload file for conversion to storage (path = w_cur_dir name = "test.html")
    std::shared_ptr<HttpContent> file(new HttpContent(w_cur_dir, name));

    // Path to file in the storage
    utility::string_t path_to_file = folder + _XPLATSTR("/test.html");

    // Upload file to the storage
    auto res = storage_api->uploadFile(path_to_file, file, storage).get();

    // Check for errors
    assert(!res->errorsIsSet());

    // Parameters for conversion
    boost::optional<int32_t> width = 800;
    boost::optional<int32_t> height = 1000;
    boost::optional<int32_t> leftMargin = 20;
    boost::optional<int32_t> rightMargin = 20;
    boost::optional<int32_t> topMargin = 20;
    boost::optional<int32_t> bottomMargin = 20;

    // Convert html file to xps
    auto result = api->getConvertDocumentToXps(name, width, height, leftMargin, rightMargin, topMargin, bottomMargin, folder, storage).get();

    // Save result to files
    std::ofstream saved_data(_XPLATSTR("ConvertHtmlToXps.xps"), std::ios::out | std::ios::binary);

    result.writeTo(saved_data);
    saved_data.close();

    delete api;
    delete storage_api;
}
```
[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)


<a name="getConvertDocumentToXpsByUrl"></a>
### **getConvertDocumentToXpsByUrl**
>     ASPOSE_DLL_EXPORT pplx::task<HttpContent> getConvertDocumentToXpsByUrl(
>        utility::string_t sourceUrl,            // Source page URL.
>        boost::optional<int32_t> width,         // Resulting document page width in points (1/96 inch). (optional)
>        boost::optional<int32_t> height,        // Resulting document page height in points (1/96 inch). (optional)
>        boost::optional<int32_t> leftMargin,    // Left resulting document page margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> rightMargin,   // Right resulting document page margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> topMargin,     // Top resulting document page margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> bottomMargin); // Bottom resulting document page margin in points (1/96 inch). (optional)

Convert the HTML page from the web by its URL to XPS.

[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)

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

    // Create ConversionApi
    ConversionApi* api = new ConversionApi(apiClient);

    // Source url for conversion
    utility::string_t sourceUrl = _XPLATSTR("https://stallman.org/articles/anonymous-payments-thru-phones.html");

    // Parameters for conversion
    boost::optional<int32_t> width = 800;
    boost::optional<int32_t> height = 1000;
    boost::optional<int32_t> leftMargin = 20;
    boost::optional<int32_t> rightMargin = 20;
    boost::optional<int32_t> topMargin = 20;
    boost::optional<int32_t> bottomMargin = 20;

    // Convert html file from url to xps
    auto result = api->getConvertDocumentToXpsByUrl(sourceUrl, width, height, leftMargin, rightMargin, topMargin, bottomMargin).get();

    // Save result to files
    std::ofstream saved_data(_XPLATSTR("ConvertToXpsFromUrl.xps"), std::ios::out | std::ios::binary);

    result.writeTo(saved_data);
    saved_data.close();

    delete api;
}
```
[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)


<a name="postConvertDocumentInRequestToImage"></a>
### **postConvertDocumentInRequestToImage**
>     ASPOSE_DLL_EXPORT pplx::task<HttpContent> postConvertDocumentInRequestToImage(
>        utility::string_t outPath,                   // Full resulting filename (ex. /folder1/folder2/result.jpg)
>        utility::string_t outFormat,                 // Resulting image format(jpeg, png, bmp, tiff, gif).
>        std::shared_ptr<HttpContent> file,           // A file to be converted.
>        boost::optional<int32_t> width,              // Resulting document page width in points (1/96 inch). (optional)
>        boost::optional<int32_t> height,             // Resulting document page height in points (1/96 inch). (optional)
>        boost::optional<int32_t> leftMargin,         // Left resulting document page margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> rightMargin,        // Right resulting document page margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> topMargin,          // Top resulting document page margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> bottomMargin,       // Bottom resulting document page margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> resolution,         // Resolution of resulting image. Default is 96 dpi. (optional)
>        boost::optional<utility::string_t> storage); // The source document storage. (optional)

Converts the HTML, EPUB, SVG document (in request content) to the specified image format and uploads resulting file to storage.

[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)

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

    // Create ConversionApi
    ConversionApi* api = new ConversionApi(apiClient);

    // Create StorageApi
    StorageApi* storage_api = new StorageApi(apiClient);

    // File name for conversion
    utility::string_t name = _XPLATSTR("test.html");

    // Folder name in the storage (should already exist)
    utility::string_t folder = _XPLATSTR("HtmlTestDoc");

    // Storage, received at registration, default is none
    boost::optional<utility::string_t> storage = boost::none;

    // Prepare file stream to upload
    std::shared_ptr<HttpContent> file(new HttpContent(w_cur_dir, name));

    utility::string_t result_name = _XPLATSTR("postConvertHtmlInRequestToJpg.zip");

    // Path to file in the storage for save result
    utility::string_t path_to_file = folder + _XPLATSTR("/") + result_name;

    // Parameters for conversion
    utility::string_t outFormat = _XPLATSTR("jpeg");
    boost::optional<int32_t> width = 800;
    boost::optional<int32_t> height = 1000;
    boost::optional<int32_t> leftMargin = 20;
    boost::optional<int32_t> rightMargin = 20;
    boost::optional<int32_t> topMargin = 20;
    boost::optional<int32_t> bottomMargin = 20; 
    boost::optional<int32_t> resolution = 150;

    // Convert html file in request to jpeg and save to storage
    auto result = api->postConvertDocumentInRequestToImage(path_to_file, outFormat, file, 
        width, height, leftMargin, rightMargin, topMargin, bottomMargin, resolution, storage).get();

    // Check exist file
    boost::optional<utility::string_t> versionId = std::wstring(_XPLATSTR(""));
    auto result_exist = storage_api->objectExists(path_to_file, versionId, storage).get();

    assert(result_exist->isExists());
    assert(!result_exist->isFolder());

    // Download file from storage
    auto result_download = storage_api->downloadFile(path_to_file, versionId, storage).get();

    // Save result to files
    std::ofstream saved_data(result_name, std::ios::out | std::ios::binary);
    result_download.writeTo(saved_data);
    saved_data.close();

    delete api;
    delete storage_api;
}
```
[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)


<a name="postConvertDocumentInRequestToPdf"></a>
### **postConvertDocumentInRequestToPdf**
>     ASPOSE_DLL_EXPORT pplx::task<HttpContent> postConvertDocumentInRequestToPdf(
>        utility::string_t outPath,                   // Full resulting filename (ex. /folder1/folder2/result.pdf)
>        std::shared_ptr<HttpContent> file,           // A file to be converted.
>        boost::optional<int32_t> width,              // Resulting document page width in points (1/96 inch). (optional)
>        boost::optional<int32_t> height,             // Resulting document page height in points (1/96 inch). (optional)
>        boost::optional<int32_t> leftMargin,         // Left resulting document page margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> rightMargin,        // Right resulting document page margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> topMargin,          // Top resulting document page margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> bottomMargin,       // Bottom resulting document page margin in points (1/96 inch). (optional)
>        boost::optional<utility::string_t> storage); // The source document storage. (optional)

Converts the HTML, EPUB, SVG document (in request content) to PDF and uploads resulting file to storage.

[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)

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

    // Create ConversionApi
    ConversionApi* api = new ConversionApi(apiClient);

    // Create StorageApi
    StorageApi* storage_api = new StorageApi(apiClient);

    // File name for conversion
    utility::string_t name = _XPLATSTR("test.html");

    // Folder name in the storage (should already exist)
    utility::string_t folder = _XPLATSTR("HtmlTestDoc");

    // Storage, received at registration, default is none
    boost::optional<utility::string_t> storage = boost::none;

    // Prepare file stream to upload
    std::shared_ptr<HttpContent> file(new HttpContent(w_cur_dir, name));

    utility::string_t result_name = _XPLATSTR("postConvertHtmlInRequestToPdf.pdf");

    // Path to file in the storage for save result
    utility::string_t path_to_file = folder + _XPLATSTR("/") + result_name;

    // Parameters for conversion
    boost::optional<int32_t> width = 800;
    boost::optional<int32_t> height = 1000;
    boost::optional<int32_t> leftMargin = 20;
    boost::optional<int32_t> rightMargin = 20;
    boost::optional<int32_t> topMargin = 20;
    boost::optional<int32_t> bottomMargin = 20;

    // Convert to pdf and save to storage
    auto result = api->postConvertDocumentInRequestToPdf(path_to_file, file,
        width, height, leftMargin, rightMargin, topMargin, bottomMargin, storage).get();

    // Check exist file
    boost::optional<utility::string_t> versionId = std::wstring(_XPLATSTR(""));
    auto result_exist = storage_api->objectExists(path_to_file, versionId, storage).get();

    assert(result_exist->isExists());
    assert(!result_exist->isFolder());

    // Download file from storage
    auto result_download = storage_api->downloadFile(path_to_file, versionId, storage).get();

    // Save result to files
    std::ofstream saved_data(result_name, std::ios::out | std::ios::binary);
    result_download.writeTo(saved_data);
    saved_data.close();

    delete api;
    delete storage_api;
}
```
[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)


<a name="postConvertDocumentInRequestToXps"></a>
### **postConvertDocumentInRequestToXps**
>     ASPOSE_DLL_EXPORT pplx::task<HttpContent> postConvertDocumentInRequestToXps(
>        utility::string_t outPath,                   // Full resulting filename (ex. /folder1/folder2/result.pdf)
>        std::shared_ptr<HttpContent> file,           // A file to be converted.
>        boost::optional<int32_t> width,              // Resulting document page width in points (1/96 inch). (optional)
>        boost::optional<int32_t> height,             // Resulting document page height in points (1/96 inch). (optional)
>        boost::optional<int32_t> leftMargin,         // Left resulting document page margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> rightMargin,        // Right resulting document page margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> topMargin,          // Top resulting document page margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> bottomMargin,       // Bottom resulting document page margin in points (1/96 inch). (optional)
>        boost::optional<utility::string_t> storage); // The source document storage. (optional)

Converts the HTML, EPUB, SVG document (in request content) to XPS and uploads resulting file to storage.

[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)

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

    // Create ConversionApi
    ConversionApi* api = new ConversionApi(apiClient);

    // Create StorageApi
    StorageApi* storage_api = new StorageApi(apiClient);

    // File name for conversion
    utility::string_t name = _XPLATSTR("test.html");

    // Folder name in the storage (should already exist)
    utility::string_t folder = _XPLATSTR("HtmlTestDoc");

    // Storage, received at registration, default is none
    boost::optional<utility::string_t> storage = boost::none;

    // Prepare file stream to upload
    std::shared_ptr<HttpContent> file(new HttpContent(w_cur_dir, name));

    utility::string_t result_name = _XPLATSTR("postConvertHtmlInRequestToXps.xps");

    // Path to file in the storage for save result
    utility::string_t path_to_file = folder + _XPLATSTR("/") + result_name;

    // Parameters for conversion
    boost::optional<int32_t> width = 800;
    boost::optional<int32_t> height = 1000;
    boost::optional<int32_t> leftMargin = 20;
    boost::optional<int32_t> rightMargin = 20;
    boost::optional<int32_t> topMargin = 20;
    boost::optional<int32_t> bottomMargin = 20;

    // Convert to html file in request to xps and save to storage
    auto result = api->postConvertDocumentInRequestToXps(path_to_file, file,
        width, height, leftMargin, rightMargin, topMargin, bottomMargin, storage).get();

    // Check exist file
    boost::optional<utility::string_t> versionId = std::wstring(_XPLATSTR(""));
    auto result_exist = storage_api->objectExists(path_to_file, versionId, storage).get();

    assert(result_exist->isExists());
    assert(!result_exist->isFolder());

    // Download file from storage
    auto result_download = storage_api->downloadFile(path_to_file, versionId, storage).get();

    // Save result to files
    std::ofstream saved_data(result_name, std::ios::out | std::ios::binary);
    result_download.writeTo(saved_data);
    saved_data.close();

    delete api;
    delete storage_api;
}
```
[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)


<a name="putConvertDocumentToImage"></a>
### **putConvertDocumentToImage**
>     ASPOSE_DLL_EXPORT pplx::task<HttpContent> putConvertDocumentToImage(
>        utility::string_t name,                      // Document name(html, epub, svg formats).
>        utility::string_t outPath,                   // Full resulting filename (ex. /folder1/folder2/result.jpg)
>        utility::string_t outFormat,                 // Resulting image format(jpeg, png, bmp, tiff, gif).
>        boost::optional<int32_t> width,              // Resulting document page width in points (1/96 inch). (optional)
>        boost::optional<int32_t> height,             // Resulting document page height in points (1/96 inch). (optional)
>        boost::optional<int32_t> leftMargin,         // Left resulting document page margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> rightMargin,        // Right resulting document page margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> topMargin,          // Top resulting document page margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> bottomMargin,       // Bottom resulting document page margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> resolution,         // Resolution of resulting image. Default is 96 dpi. (optional)
>        boost::optional<utility::string_t> folder,   // The source document folder. (optional)
>        boost::optional<utility::string_t> storage); // The source and resulting document storage. (optional)

Converts the HTML, EPUB, SVG document (located on storage) to the specified image format and uploads resulting file to storage.

[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)

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

    // Create ConversionApi
    ConversionApi* api = new ConversionApi(apiClient);

    // Create StorageApi
    StorageApi* storage_api = new StorageApi(apiClient);

    // File name for conversion
    utility::string_t name = _XPLATSTR("test.html");

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

    utility::string_t result_name = _XPLATSTR("putConvertHtmlToPng.zip");

    // Path to file in the storage for save result
    utility::string_t  result_file = folder + _XPLATSTR("/") + result_name;

    // Parameters for conversion
    utility::string_t outFormat = _XPLATSTR("png");
    boost::optional<int32_t> width = 800;
    boost::optional<int32_t> height = 1000;
    boost::optional<int32_t> leftMargin = 20;
    boost::optional<int32_t> rightMargin = 20;
    boost::optional<int32_t> topMargin = 20;
    boost::optional<int32_t> bottomMargin = 20;
    boost::optional<int32_t> resolution = 300;

    // Convert html file in the storage to png and save to storage
    auto result = api->putConvertDocumentToImage(name, result_file, outFormat,
        width, height, leftMargin, rightMargin, topMargin, bottomMargin, resolution, folder, storage).get();

    // Check exist file
    boost::optional<utility::string_t> versionId = std::wstring(_XPLATSTR(""));
    auto result_exist = storage_api->objectExists(result_file, versionId, storage).get();

    assert(result_exist->isExists());
    assert(!result_exist->isFolder());

    // Download file from storage
    auto result_download = storage_api->downloadFile(result_file, versionId, storage).get();

    // Save result to files
    std::ofstream saved_data(result_name, std::ios::out | std::ios::binary);
    result_download.writeTo(saved_data);
    saved_data.close();

    delete api;
    delete storage_api;
}
```
[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)


<a name="putConvertDocumentToPdf"></a>
### **putConvertDocumentToPdf**
>     ASPOSE_DLL_EXPORT pplx::task<HttpContent> putConvertDocumentToPdf(
>        utility::string_t name,                      // Document name(html, epub, svg formats).
>        utility::string_t outPath,                   // Full resulting filename (ex. /folder1/folder2/result.pdf)
>        boost::optional<int32_t> width,              // Resulting document page width in points (1/96 inch). (optional)
>        boost::optional<int32_t> height,             // Resulting document page height in points (1/96 inch). (optional)
>        boost::optional<int32_t> leftMargin,         // Left resulting document page margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> rightMargin,        // Right resulting document page margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> topMargin,          // Top resulting document page margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> bottomMargin,       // Bottom resulting document page margin in points (1/96 inch). (optional)
>        boost::optional<utility::string_t> folder,   // The source document folder. (optional)
>        boost::optional<utility::string_t> storage); // The source and resulting document storage. (optional)

Converts the HTML, EPUB, SVG document (located on storage) to PDF and uploads resulting file to storage.

[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)

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

    // Create ConversionApi
    ConversionApi* api = new ConversionApi(apiClient);

    // Create StorageApi
    StorageApi* storage_api = new StorageApi(apiClient);

    // File name for conversion
    utility::string_t name = _XPLATSTR("test.html");

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

    utility::string_t result_name = _XPLATSTR("putConvertHtmlToPdf.pdf");

    // Path to file in the storage for save result
    utility::string_t  result_file = folder + _XPLATSTR("/") + result_name;

    // Parameters for conversion
    boost::optional<int32_t> width = 800;
    boost::optional<int32_t> height = 1000;
    boost::optional<int32_t> leftMargin = 20;
    boost::optional<int32_t> rightMargin = 20;
    boost::optional<int32_t> topMargin = 20;
    boost::optional<int32_t> bottomMargin = 20;

    // Convert html file in the storage to pdf and save to the storage
    auto result = api->putConvertDocumentToPdf(name, result_file, 
        width, height, leftMargin, rightMargin, topMargin, bottomMargin, folder, storage).get();

    // Check exist file
    boost::optional<utility::string_t> versionId = std::wstring(_XPLATSTR(""));
    auto result_exist = storage_api->objectExists(result_file, versionId, storage).get();

    assert(result_exist->isExists());
    assert(!result_exist->isFolder());

    // Download file from storage
    auto result_download = storage_api->downloadFile(result_file, versionId, storage).get();

    // Save result to files
    std::ofstream saved_data(result_name, std::ios::out | std::ios::binary);
    result_download.writeTo(saved_data);
    saved_data.close();

    delete api;
    delete storage_api;
}
```
[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)


<a name="putConvertDocumentToXps"></a>
### **putConvertDocumentToXps**
>     ASPOSE_DLL_EXPORT pplx::task<HttpContent> putConvertDocumentToXps(
>        utility::string_t name,                      // Document name(html, epub, svg formats).
>        utility::string_t outPath,                   // Full resulting filename (ex. /folder1/folder2/result.xps)
>        boost::optional<int32_t> width,              // Resulting document page width in points (1/96 inch). (optional)
>        boost::optional<int32_t> height,             // Resulting document page height in points (1/96 inch). (optional)
>        boost::optional<int32_t> leftMargin,         // Left resulting document page margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> rightMargin,        // Right resulting document page margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> topMargin,          // Top resulting document page margin in points (1/96 inch). (optional)
>        boost::optional<int32_t> bottomMargin,       // Bottom resulting document page margin in points (1/96 inch). (optional)
>        boost::optional<utility::string_t> folder,   // The source document folder. (optional)
>        boost::optional<utility::string_t> storage); // The source and resulting document storage. (optional)

Converts the HTML, EPUB, SVG document (located on storage) to XPS and uploads resulting file to storage.

[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)

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

    // Create ConversionApi
    ConversionApi* api = new ConversionApi(apiClient);

    // Create StorageApi
    StorageApi* storage_api = new StorageApi(apiClient);

    // File name for conversion
    utility::string_t name = _XPLATSTR("test.html");

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

    utility::string_t result_name = _XPLATSTR("putConvertHtmlToXps.xps");

    // Path to file in the storage for save result
    utility::string_t  result_file = folder + _XPLATSTR("/") + result_name;

    // Parameters for conversion
    boost::optional<int32_t> width = 800;
    boost::optional<int32_t> height = 1000;
    boost::optional<int32_t> leftMargin = 20;
    boost::optional<int32_t> rightMargin = 20;
    boost::optional<int32_t> topMargin = 20;
    boost::optional<int32_t> bottomMargin = 20;

    // Convert html file in the storage to xps and save to the storage
    auto result = api->putConvertDocumentToXps(name, result_file,
        width, height, leftMargin, rightMargin, topMargin, bottomMargin, folder, storage).get();

    // Check exist file
    boost::optional<utility::string_t> versionId = std::wstring(_XPLATSTR(""));
    auto result_exist = storage_api->objectExists(result_file, versionId, storage).get();

    assert(result_exist->isExists());
    assert(!result_exist->isFolder());

    // Download file from storage
    auto result_download = storage_api->downloadFile(result_file, versionId, storage).get();

    // Save result to files
    std::ofstream saved_data(result_name, std::ios::out | std::ios::binary);
    result_download.writeTo(saved_data);
    saved_data.close();

    delete api;
    delete storage_api;
}
```
[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)


<a name="getConvertDocumentToMHTMLByUrl"></a>
### **getConvertDocumentToMHTMLByUrl**
>     ASPOSE_DLL_EXPORT pplx::task<HttpContent> getConvertDocumentToMHTMLByUrl(
>        utility::string_t sourceUrl); // Source page URL.

Converts the HTML page from Web by its URL to MHTML returns resulting file in response content.

[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)

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

    // Create ConversionApi
    ConversionApi* api = new ConversionApi(apiClient);

    utility::string_t sourceUrl = _XPLATSTR("https://stallman.org/articles/anonymous-payments-thru-phones.html");
    utility::string_t result_name = _XPLATSTR("ConvertHtmlToMhtmlByUrl.mht");

    // Convert html by url to mhtml file and return result in body
    auto result = api->getConvertDocumentToMHTMLByUrl(sourceUrl).get();

    // Save result to files
    std::ofstream saved_data(result_name, std::ios::out | std::ios::binary);
    result.writeTo(saved_data);
    saved_data.close();

    delete api;
}
```
[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)


<a name="getConvertDocumentToMarkdown"></a>
### **getConvertDocumentToMarkdown**
>     ASPOSE_DLL_EXPORT pplx::task<HttpContent> getConvertDocumentToMarkdown(
>         utility::string_t name,                      // Document name.
>         boost::optional<bool> useGit,                // Use Git Markdown flavor to save. (optional, default to false)
>         boost::optional<utility::string_t> folder,   // Source document folder. (optional)
>         boost::optional<utility::string_t> storage); // Source document storage. (optional)

Converts the HTML document (located on storage) to Markdown and returns resulting file in response content.

[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)

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

    // Create ConversionApi
    ConversionApi* api = new ConversionApi(apiClient);

    // Create StorageApi
    StorageApi* storage_api = new StorageApi(apiClient);

    // File name for conversion
    utility::string_t name = _XPLATSTR("test.html");

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

    // Convert html file in the storage to markdown and return markdown file
    auto result = api->getConvertDocumentToMarkdown(name, false, folder, storage).get();

    // Save result to files
    std::ofstream saved_data("getConvertDocumentToMarkdown.md", std::ios::out | std::ios::binary);
    result.writeTo(saved_data);
    saved_data.close();

    delete api;
    delete storage_api;
}
```
[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)


<a name="postConvertDocumentInRequestToMarkdown"></a>
### **postConvertDocumentInRequestToMarkdown**
>     ASPOSE_DLL_EXPORT pplx::task<HttpContent> postConvertDocumentInRequestToMarkdown(
>        utility::string_t outPath,                   // Full resulting file path in the storage (ex. /folder1/folder2/result.md)
>        std::shared_ptr<HttpContent> file,           // A file to be converted.
>        boost::optional<bool> useGit,                // Use Git Markdown flavor to save. (optional, default to false)
>        boost::optional<utility::string_t> storage); // The source and resulting document storage. (optional)

Converts the HTML document (in request content) to Markdown and uploads resulting file to storage by specified path.

[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)

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

    // Create ConversionApi
    ConversionApi* api = new ConversionApi(apiClient);

    // Create StorageApi
    StorageApi* storage_api = new StorageApi(apiClient);

    // File name for conversion
    utility::string_t name = _XPLATSTR("test.html");

    // Folder name in the storage (should already exist)
    utility::string_t folder = _XPLATSTR("HtmlTestDoc");

    // Storage, received at registration, default is none
    boost::optional<utility::string_t> storage = boost::none;

    // Prepare file stream to upload
    std::shared_ptr<HttpContent> file(new HttpContent(w_cur_dir, name));

    utility::string_t result_name = _XPLATSTR("postConvertDocumentInRequestToMarkdown.md");

    // Path to file in the storage for save result
    utility::string_t path_to_result = folder + _XPLATSTR("/") + result_name;

    // Convert html file in request to markdown and save result in the storage
    auto result = api->postConvertDocumentInRequestToMarkdown(path_to_result, file, false, storage).get();

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
[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)


<a name="putConvertDocumentToMarkdown"></a>
### **putConvertDocumentToMarkdown**
>     ASPOSE_DLL_EXPORT pplx::task<HttpContent> putConvertDocumentToMarkdown(
>        utility::string_t name,                      // Document name.
>        utility::string_t outPath,                   // Full resulting file path in the storage (ex. /folder1/folder2/result.md)
>        boost::optional<bool> useGit,                // Use Git Markdown flavor to save. (optional, default to false)
>        boost::optional<utility::string_t> folder,   // The source document folder. (optional)
>        boost::optional<utility::string_t> storage); // The source and resulting document storage. (optional)

Converts the HTML document (located on storage) to Markdown and uploads resulting file to storage by specified path.

[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)

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

    // Create ConversionApi
    ConversionApi* api = new ConversionApi(apiClient);

    // Create StorageApi
    StorageApi* storage_api = new StorageApi(apiClient);

    // File name for conversion
    utility::string_t name = _XPLATSTR("test.html");

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

    auto result_name = _XPLATSTR("putConvertDocumentToMarkdown.md");
    auto result_path = folder + _XPLATSTR("/") + result_name;

    // Convert html file in the storage to markdown and save result in the storage
    auto result = api->putConvertDocumentToMarkdown(name, result_path, false, folder, storage).get();
    
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
[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)
