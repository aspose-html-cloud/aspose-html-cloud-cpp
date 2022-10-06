<a name="ConversionApi"></a>
## ConversionApi

All URIs are relative to *https://api.aspose.cloud/v4.0*

| Method                                                                  | Description                                                              |
|-------------------------------------------------------------------------|--------------------------------------------------------------------------|
| [**сonvertLocalToLocal**](ConversionApi.md#convertlocaltolocal)         | Convert the HTML or EPUB document from the local disk to the local disk. |
| [**сonvertLocalToStorage**](ConversionApi.md#convertlocaltostorage)     | Convert the HTML or EPUB document from the local disk to the storage.    |
| [**сonvertStorageToLocal**](ConversionApi.md#convertstoragetolocal)     | Convert the HTML or EPUB document from the storage to the local disk.    |
| [**сonvertStorageToStorage**](ConversionApi.md#convertstoragetostorage) | Convert the HTML or EPUB document from the storage to the storage.       |
| [**сonvertUrlToLocal**](ConversionApi.md#converturltolocal)             | Convert the website to the local disk.                                   |
| [**сonvertUrlToStorage**](ConversionApi.md#converturltostorage)         | Convert the website to the storage.                                      |

## **convertLocalToLocal**

```cpp
    /// <summary>
    /// Convert the HTML or EPUB document from the local file to the local file.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="src">Full path to the source file.</param>
    /// <param name="dst">Full path to the result file.</param>
    /// <param name="options">Options for conversion.</param>
    /// <param name="width">Resulting width(for images in pixels, for PDF, XPS, DOCX in inches). (optional)</param>
    /// <param name="height">Resulting height(for images in pixels, for PDF, XPS, DOCX in inches). (optional)</param>
    /// <param name="leftMargin">Left margin(for images in pixels, for PDF, XPS, DOCX in inches). (optional)</param>
    /// <param name="rightMargin">Right margin(for images in pixels, for PDF, XPS, DOCX in inches). (optional)</param>
    /// <param name="topMargin">Top margin(for images in pixels, for PDF, XPS, DOCX in inches). (optional)</param>
    /// <param name="bottomMargin">Bottom margin(for images in pixels, for PDF, XPS, DOCX in inches). (optional)</param>
    ASPOSE_DLL_EXPORT std::shared_ptr<ConversionResult> convertLocalToLocal(
    const utility::string_t& src,
    const utility::string_t& dst,
    const std::shared_ptr<ConversionOptions> options = nullptr
    ) const;
```

Convert the HTML or EPUB document from the local file to the local file.

[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)

### Example
```cpp
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

    // Create ConversionApi
    std::shared_ptr<ConversionApi> api = std::make_shared<ConversionApi>(apiClient);
 
    // File name for conversion
    utility::string_t src = w_cur_dir + _XPLATSTR("test.html");
    utility::string_t dst = w_cur_dir + _XPLATSTR("result.jpeg");
    
    // Set options for conversion
    std::shared_ptr<ConversionOptions> opts = std::make_shared<ConversionOptions>();
    opts->setWidth(800)
        ->setHeight(600)
        ->setLeftMargin(10)
        ->setRightMargin(10)
        ->setTopMargin(10)
        ->setBottomMargin(10);
    
    //Conversion
    auto result = api->convertLocalToLocal(src, dst, opts);
    
    // Check the result file
    auto re = result->getFile();
    std::ifstream f(re.c_str());
    if(!f.good())
    {
        throw std::runtime_error("Conversion failed");
    }
}
```
[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)


## **convertLocalToStorage**

```cpp
    /// <summary>
    /// Convert the HTML or EPUB document from the local file to the storage.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="src">Full path to the source file.</param>
    /// <param name="dst">Path to the result file in the storage.</param>
    /// <param name="storage">User's storage name.</param>
    /// <param name="options">Options for conversion.</param>
    /// <param name="width">Resulting width(for images in pixels, for PDF, XPS, DOCX in inches). (optional)</param>
    /// <param name="height">Resulting height(for images in pixels, for PDF, XPS, DOCX in inches). (optional)</param>
    /// <param name="leftMargin">Left margin(for images in pixels, for PDF, XPS, DOCX in inches). (optional)</param>
    /// <param name="rightMargin">Right margin(for images in pixels, for PDF, XPS, DOCX in inches). (optional)</param>
    /// <param name="topMargin">Top margin(for images in pixels, for PDF, XPS, DOCX in inches). (optional)</param>
    /// <param name="bottomMargin">Bottom margin(for images in pixels, for PDF, XPS, DOCX in inches). (optional)</param>
    ASPOSE_DLL_EXPORT std::shared_ptr<ConversionResult> convertLocalToStorage(
    const utility::string_t& src,
    const utility::string_t& dst,
    const boost::optional<utility::string_t> storage = boost::none,
    const std::shared_ptr<ConversionOptions> options = nullptr
    ) const;
```

Convert the HTML or EPUB document from the local file to the storage.

[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)

### Example
```cpp
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

    // Create ConversionApi
    std::shared_ptr<ConversionApi> api = std::make_shared<ConversionApi>(apiClient);
 
    // File name for conversion
    utility::string_t src = w_cur_dir + _XPLATSTR("test.html");
    utility::string_t dst = _XPLATSTR("FolderInStorage/result.pdf");
    
    // Set options for conversion
    std::shared_ptr<ConversionOptions> opts = std::make_shared<ConversionOptions>();
    opts->setWidth(8.3)
        ->setHeight(11.7)
        ->setLeftMargin(0.2)
        ->setRightMargin(0.2)
        ->setTopMargin(0.2)
        ->setBottomMargin(0.2);

    utility::string_t storage = _XPLATSTR("");

    //Conversion
    auto result = api->convertLocalToStorage(src, dst, storage, opts);
    
    // Check the result file
 
    // Create StorageApi
    std::shared_ptr<StorageApi> storage_api = std::make_shared<StorageApi>(apiClient);
    
    boost::optional<utility::string_t> versionId = _XPLATSTR("");
    
    // Result exists checking.
    auto result_exist = storage_api->objectExists(result->getFile(), versionId, storage).get();

    if(!result_exist->isExists())
    {
        throw std::runtime_error("Conversion failed");
    }
}
```
[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)

## **convertStorageToLocal**

```cpp
    /// <summary>
    /// Convert the HTML or EPUB document from the storage to the local file.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="src">Path to the source file in the storage.</param>
    /// <param name="dst">Full path to the result file in the local disk.</param>
    /// <param name="storage">User's storage name.</param>
    /// <param name="options">Options for conversion.</param>
    /// <param name="width">Resulting width(for images in pixels, for PDF, XPS, DOCX in inches). (optional)</param>
    /// <param name="height">Resulting height(for images in pixels, for PDF, XPS, DOCX in inches). (optional)</param>
    /// <param name="leftMargin">Left margin(for images in pixels, for PDF, XPS, DOCX in inches). (optional)</param>
    /// <param name="rightMargin">Right margin(for images in pixels, for PDF, XPS, DOCX in inches). (optional)</param>
    /// <param name="topMargin">Top margin(for images in pixels, for PDF, XPS, DOCX in inches). (optional)</param>
    /// <param name="bottomMargin">Bottom margin(for images in pixels, for PDF, XPS, DOCX in inches). (optional)</param>
    ASPOSE_DLL_EXPORT std::shared_ptr<ConversionResult> convertStorageToLocal(
    const utility::string_t& src,
    const utility::string_t& dst,
    const boost::optional<utility::string_t> storage = boost::none,
    const std::shared_ptr<ConversionOptions> options = nullptr
    ) const;
```

Convert the HTML or EPUB document from the storage to the local file.

[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)

### Example
```cpp
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

    // Create ConversionApi
    std::shared_ptr<ConversionApi> api = std::make_shared<ConversionApi>(apiClient);
 
    // File name for conversion
    utility::string_t src = w_cur_dir + _XPLATSTR("test.html");
    utility::string_t dst = w_cur_dir + _XPLATSTR("result.jpeg");
    
    // Set options for conversion
    std::shared_ptr<ConversionOptions> opts = std::make_shared<ConversionOptions>();
    opts->setWidth(800)
        ->setHeight(600)
        ->setLeftMargin(10)
        ->setRightMargin(10)
        ->setTopMargin(10)
        ->setBottomMargin(10);
    
    // Upload file to the storage
    // Create StorageApi
    std::shared_ptr<StorageApi> storage_api = std::make_shared<StorageApi>(apiClient);

    std::shared_ptr<HttpContent> file(new HttpContent(w_cur_dir, "test.html"));
    utility::string_t folder = _XPLATSTR("/");
    boost::optional<utility::string_t> storage = boost::none;
    
    auto res = storage_api->uploadFile(folder, file, storage).get();

    if(res->errorsIsSet())
    {
        throw std::runtime_error("Unable upload file to the storage");
    }
    
    //Conversion
    auto result = api->convertStorageToLocal(src, dst, storage, opts);
    
    // Check the result file
    auto re = result->getFile();
    std::ifstream f(re.c_str());
    if(!f.good())
    {
        throw std::runtime_error("Conversion failed");
    }
}
```
[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)


## **convertStorageToStorage**

```cpp
    /// <summary>
    /// Convert the HTML or EPUB document from the storage to the storage.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="src">Path to the source file in the storage.</param>
    /// <param name="dst">Path to the result file in the storage.</param>
    /// <param name="storage">User's storage name.</param>
    /// <param name="options">Options for conversion.</param>
    /// <param name="width">Resulting width(for images in pixels, for PDF, XPS, DOCX in inches). (optional)</param>
    /// <param name="height">Resulting height(for images in pixels, for PDF, XPS, DOCX in inches). (optional)</param>
    /// <param name="leftMargin">Left margin(for images in pixels, for PDF, XPS, DOCX in inches). (optional)</param>
    /// <param name="rightMargin">Right margin(for images in pixels, for PDF, XPS, DOCX in inches). (optional)</param>
    /// <param name="topMargin">Top margin(for images in pixels, for PDF, XPS, DOCX in inches). (optional)</param>
    /// <param name="bottomMargin">Bottom margin(for images in pixels, for PDF, XPS, DOCX in inches). (optional)</param>
    ASPOSE_DLL_EXPORT std::shared_ptr<ConversionResult> convertStorageToStorage(
    const utility::string_t& src,
    const utility::string_t& dst,
    const boost::optional<utility::string_t> storage = boost::none,
    const std::shared_ptr<ConversionOptions> options = nullptr
    ) const;
```

Convert the HTML or EPUB document from the storage to the storage.

[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)

### Example
```cpp
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

    // Create ConversionApi
    std::shared_ptr<ConversionApi> api = std::make_shared<ConversionApi>(apiClient);
 
    // File name for conversion
    utility::string_t src = w_cur_dir + _XPLATSTR("test.html");
    utility::string_t dst = w_cur_dir + _XPLATSTR("result.jpeg");
    
    // Set options for conversion
    std::shared_ptr<ConversionOptions> opts = std::make_shared<ConversionOptions>();
    opts->setWidth(800)
        ->setHeight(600)
        ->setLeftMargin(10)
        ->setRightMargin(10)
        ->setTopMargin(10)
        ->setBottomMargin(10);
    
    // Upload file to the storage
    // Create StorageApi
    std::shared_ptr<StorageApi> storage_api = std::make_shared<StorageApi>(apiClient);

    std::shared_ptr<HttpContent> file(new HttpContent(w_cur_dir, "test.html"));
    utility::string_t folder = _XPLATSTR("/");
    boost::optional<utility::string_t> storage = boost::none;
    
    auto res = storage_api->uploadFile(folder, file, storage).get();

    if(res->errorsIsSet())
    {
        throw std::runtime_error("Unable upload file to the storage");
    }
    
    //Conversion
    auto result = api->convertStorageToStorage(src, dst, storage, opts);
    
    // Check the result file
    boost::optional<utility::string_t> versionId = _XPLATSTR("");
    
    // Result exists checking.
    auto result_exist = storage_api->objectExists(result->getFile(), versionId, storage).get();

    if(!result_exist->isExists())
    {
        throw std::runtime_error("Conversion failed");
    }
}
```
[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)

## **convertUrlToLocal**

```cpp
    /// <summary>
    /// Convert the website to the local file.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="src">Url of the website.</param>
    /// <param name="dst">Path to the result file in the local disk.</param>
    /// <param name="options">Options for conversion.</param>
    /// <param name="width">Resulting width(for images in pixels, for PDF, XPS, DOCX in inches). (optional)</param>
    /// <param name="height">Resulting height(for images in pixels, for PDF, XPS, DOCX in inches). (optional)</param>
    /// <param name="leftMargin">Left margin(for images in pixels, for PDF, XPS, DOCX in inches). (optional)</param>
    /// <param name="rightMargin">Right margin(for images in pixels, for PDF, XPS, DOCX in inches). (optional)</param>
    /// <param name="topMargin">Top margin(for images in pixels, for PDF, XPS, DOCX in inches). (optional)</param>
    /// <param name="bottomMargin">Bottom margin(for images in pixels, for PDF, XPS, DOCX in inches). (optional)</param>
    ASPOSE_DLL_EXPORT std::shared_ptr<ConversionResult> convertUrlToLocal(
    const utility::string_t& src,
    const utility::string_t& dst,
    const std::shared_ptr<ConversionOptions> options = nullptr
    ) const;
```

Convert the website to the local file.

[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)

### Example
```cpp
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

    // Create ConversionApi
    std::shared_ptr<ConversionApi> api = std::make_shared<ConversionApi>(apiClient);
 
    // File name for conversion
    utility::string_t src = _XPLATSTR("https://stallman.org/articles/anonymous-payments-thru-phones.html");
    utility::string_t dst = w_cur_dir + _XPLATSTR("result.jpeg");
    
    // Set options for conversion
    std::shared_ptr<ConversionOptions> opts = std::make_shared<ConversionOptions>();
    opts->setWidth(800)
        ->setHeight(600)
        ->setLeftMargin(10)
        ->setRightMargin(10)
        ->setTopMargin(10)
        ->setBottomMargin(10);
    
    //Conversion
    auto result = api->convertUrlToLocal(src, dst, opts);
    
    // Check the result file
    auto re = result->getFile();
    std::ifstream f(re.c_str());
    if(!f.good())
    {
        throw std::runtime_error("Conversion failed");
    }
}
```
[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)

## **convertUrlToStorage**

```cpp
    /// <summary>
    /// Convert the website to the storage.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="src">Url of the website.</param>
    /// <param name="dst">Path to the result file in the storage.</param>
    /// <param name="storage">User's storage name.</param>
    /// <param name="options">Options for conversion.</param>
    /// <param name="width">Resulting width(for images in pixels, for PDF, XPS, DOCX in inches). (optional)</param>
    /// <param name="height">Resulting height(for images in pixels, for PDF, XPS, DOCX in inches). (optional)</param>
    /// <param name="leftMargin">Left margin(for images in pixels, for PDF, XPS, DOCX in inches). (optional)</param>
    /// <param name="rightMargin">Right margin(for images in pixels, for PDF, XPS, DOCX in inches). (optional)</param>
    /// <param name="topMargin">Top margin(for images in pixels, for PDF, XPS, DOCX in inches). (optional)</param>
    /// <param name="bottomMargin">Bottom margin(for images in pixels, for PDF, XPS, DOCX in inches). (optional)</param>
    ASPOSE_DLL_EXPORT std::shared_ptr<ConversionResult> convertUrlToStorage(
    const utility::string_t& src,
    const utility::string_t& dst,
    const boost::optional<utility::string_t> storage = boost::none,
    const std::shared_ptr<ConversionOptions> options = nullptr
    ) const;
```

Convert the website to the storage.

[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)

### Example
```cpp
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

    // Create ConversionApi
    std::shared_ptr<ConversionApi> api = std::make_shared<ConversionApi>(apiClient);
 
    // File name for conversion
    utility::string_t src = _XPLATSTR("https://stallman.org/articles/anonymous-payments-thru-phones.html");
    utility::string_t dst = w_cur_dir + _XPLATSTR("result.jpeg");
    
    // Set options for conversion
    std::shared_ptr<ConversionOptions> opts = std::make_shared<ConversionOptions>();
    opts->setWidth(800)
        ->setHeight(600)
        ->setLeftMargin(10)
        ->setRightMargin(10)
        ->setTopMargin(10)
        ->setBottomMargin(10);
    
    //Conversion
    auto result = api->convertUrlToStorage(src, dst, storage, opts);

    // Create StorageApi
    std::shared_ptr<StorageApi> storage_api = std::make_shared<StorageApi>(apiClient);

    // Check the result file
    boost::optional<utility::string_t> versionId = _XPLATSTR("");
    
    // Result exists checking.
    auto result_exist = storage_api->objectExists(result->getFile(), versionId, storage).get();

    if(!result_exist->isExists())
    {
        throw std::runtime_error("Conversion failed");
    }
}
```
[&#8593;UP&#8593;](ConversionApi.md#ConversionApi)

