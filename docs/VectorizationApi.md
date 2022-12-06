## Possible vectorizations: 
- JPEG, BMP, PNG, TIFF, GIF -> SVG


<a name="VectorizationApi"></a>
## VectorizationApi

All URIs are relative to *https://api.aspose.cloud/v4.0*

| Method                                                                              | Description                                                          |
|-------------------------------------------------------------------------------------|----------------------------------------------------------------------|
| [**vectorizeLocalToLocal**](docs/VectorizationApi.md#vectorizelocaltolocal)         | Vectorize image to SVG format from the local disk to the local disk. |
| [**vectorizeLocalToStorage**](docs/VectorizationApi.md#vectorizelocaltostorage)     | Vectorize image to SVG format from the local disk to the storage.    |
| [**vectorizeStorageToLocal**](docs/VectorizationApi.md#vectorizestoragetolocal)     | Vectorize image to SVG format from the storage to the local disk.    |
| [**vectorizeStorageToStorage**](docs/VectorizationApi.md#vectorizestoragetostorage) | Vectorize image to SVG format from the storage to the storage.       |


### Vectorization options for trace to the SVG format
| Method                                                                           | Description                                                                                             | Note     |
|----------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------|----------|
| **VectorizationOptions\* VectorizationOptions::setErrorThreshold(double value)** | This parameter defines maximum deviation of points to fitted curve. By default it is 30.                | Optional |
| **VectorizationOptions\* VectorizationOptions::setMaxIteration(int value)**      | This parameter defines number of iteration for least-squares approximation method. By default it is 30. | Optional |
| **VectorizationOptions\* VectorizationOptions::setColorLimit(int value)**        | The maximum number of colors used to quantize an image. Default value is 25.                            | Optional |
| **VectorizationOptions\* VectorizationOptions::setLineWidth(double value)**      | The value of this parameter is affected by the graphics scale. Default value is 1.                      | Optional |


## **vectorizeLocalToLocal**

```cpp
    /// <summary>
    /// Vectorize an image from the local file to the local file.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="src">Full path to the source file.</param>
    /// <param name="dst">Full path to the result file.</param>
    /// <param name="options">Vectorization options. (optional)</param>
    ASPOSE_DLL_EXPORT std::shared_ptr<ConversionResult> vectorizeLocalToLocal(
    const utility::string_t& src,
    const utility::string_t& dst,
    const std::shared_ptr<VectorizationOptions> options = nullptr
    ) const;
```

Vectorize an image from the local file to the local file.

[&#8593;UP&#8593;](VectorizationApi.md#VectorizationApi)

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

    // Create VectorizationApi
    std::shared_ptr<VectorizationApi> api = std::make_shared<VectorizationApi>(apiClient);
 
    // File name for vectorization
    utility::string_t src = w_cur_dir + _XPLATSTR("test.bmp");
    utility::string_t dst = w_cur_dir + _XPLATSTR("result.svg");
    
    // Set options for vectorization
    std::shared_ptr<VectorizationOptions> opts = std::make_shared<VectorizationOptions>();
    opts->setErrorThreshold(50)
        ->setColorLimit(2)
        ->setLineWidth(1.5)
        ->setMaxIteration(10);
    
    //Vectorization
    auto result = api->vectorizeLocalToLocal(src, dst, opts);
    
    // Check the result file
    auto re = result->getFile();
    std::ifstream f(re.c_str());
    if(!f.good())
    {
        throw std::runtime_error("Vectorization failed");
    }
}
```
[&#8593;UP&#8593;](VectorizationApi.md#VectorizationApi)


## **vectorizeLocalToStorage**

```cpp
    /// <summary>
    /// Vectorize an image from the local file to the storage.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="src">Full path to the source file.</param>
    /// <param name="dst">Path to the result file in the storage.</param>
    /// <param name="storage">User's storage name. (optional)</param>
    /// <param name="options">Options for vectorization. (optional)</param>
    ASPOSE_DLL_EXPORT std::shared_ptr<ConversionResult> vectorizeLocalToStorage(
    const utility::string_t& src,
    const utility::string_t& dst,
    const boost::optional<utility::string_t> storage = boost::none,
    const std::shared_ptr<VectorizationOptions> options = nullptr
    ) const;
```

Vectorize an image from the local file to the storage.

[&#8593;UP&#8593;](VectorizationApi.md#VectorizationApi)

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

    // Create VectorizationApi
    std::shared_ptr<VectorizationApi> api = std::make_shared<VectorizationApi>(apiClient);
 
    // File name for vectorization
    utility::string_t src = w_cur_dir + _XPLATSTR("test.png");
    utility::string_t dst = _XPLATSTR("FolderInStorage/result.svg");
    
    // Set options for vectorization
    std::shared_ptr<VectorizationOptions> opts = std::make_shared<VectorizationOptions>();
    opts->setErrorThreshold(50)
        ->setColorLimit(2)
        ->setLineWidth(1.5)
        ->setMaxIteration(10);

    utility::string_t storage = _XPLATSTR("");

    //Vectorization
    auto result = api->vectorizeLocalToStorage(src, dst, storage, opts);
    
    // Check the result file
 
    // Create StorageApi
    std::shared_ptr<StorageApi> storage_api = std::make_shared<StorageApi>(apiClient);
    
    boost::optional<utility::string_t> versionId = _XPLATSTR("");
    
    // Result exists checking.
    auto result_exist = storage_api->objectExists(result->getFile(), versionId, storage).get();

    if(!result_exist->isExists())
    {
        throw std::runtime_error("Vectorization failed");
    }
}
```
[&#8593;UP&#8593;](VectorizationApi.md#VectorizationApi)

## **vectorizeStorageToLocal**

```cpp
    /// <summary>
    /// Vectorize an image from the storage to the local file.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="src">Path to the source file in the storage.</param>
    /// <param name="dst">Full path to the result file in the local disk.</param>
    /// <param name="storage">User's storage name.</param>
    /// <param name="options">Options for vectorization. (optional)</param>
    ASPOSE_DLL_EXPORT std::shared_ptr<ConversionResult> vectorizeStorageToLocal(
    const utility::string_t& src,
    const utility::string_t& dst,
    const boost::optional<utility::string_t> storage = boost::none,
    const std::shared_ptr<VectorizationOptions> options = nullptr
    ) const;
```

Vectorize an image from the storage to the local file.

[&#8593;UP&#8593;](VectorizationApi.md#VectorizationApi)

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

    // Create VectorizationApi
    std::shared_ptr<VectorizationApi> api = std::make_shared<VectorizationApi>(apiClient);
 
    // File name for vectorization
    utility::string_t src = w_cur_dir + _XPLATSTR("test.bmp");
    utility::string_t dst = w_cur_dir + _XPLATSTR("result.svg");
    
    // Set options for vectorization
    std::shared_ptr<VectorizationOptions> opts = std::make_shared<VectorizationOptions>();
    opts->setErrorThreshold(50)
        ->setColorLimit(2)
        ->setLineWidth(1.5)
        ->setMaxIteration(10);
    
    // Upload file to the storage
    // Create StorageApi
    std::shared_ptr<StorageApi> storage_api = std::make_shared<StorageApi>(apiClient);

    std::shared_ptr<HttpContent> file(new HttpContent(w_cur_dir, "test.bmp"));
    utility::string_t folder = _XPLATSTR("/");
    boost::optional<utility::string_t> storage = boost::none;
    
    auto res = storage_api->uploadFile(folder, file, storage).get();

    if(res->errorsIsSet())
    {
        throw std::runtime_error("Unable upload file to the storage");
    }
    
    //Vectorization
    auto result = api->vectorizeStorageToLocal(src, dst, storage, opts);
    
    // Check the result file
    auto re = result->getFile();
    std::ifstream f(re.c_str());
    if(!f.good())
    {
        throw std::runtime_error("Vectorization failed");
    }
}
```
[&#8593;UP&#8593;](VectorizationApi.md#VectorizationApi)


## **vectorizeStorageToStorage**

```cpp
    /// <summary>
    /// Vectorize an image from the storage to the storage.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="src">Path to the source file in the storage.</param>
    /// <param name="dst">Path to the result file in the storage.</param>
    /// <param name="storage">User's storage name. (optional)</param>
    /// <param name="options">Options for vectorization. (optional)</param>
    ASPOSE_DLL_EXPORT std::shared_ptr<ConversionResult> vectorizeStorageToStorage(
    const utility::string_t& src,
    const utility::string_t& dst,
    const boost::optional<utility::string_t> storage = boost::none,
    const std::shared_ptr<VectorizationOptions> options = nullptr
    ) const;
```

Vectorize an image from the storage to the storage.

[&#8593;UP&#8593;](VectorizationApi.md#VectorizationApi)

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

    // Create VectorizationApi
    std::shared_ptr<VectorizationApi> api = std::make_shared<VectorizationApi>(apiClient);
 
    // File name for vectorization
    utility::string_t src = w_cur_dir + _XPLATSTR("test.png");
    utility::string_t dst = w_cur_dir + _XPLATSTR("result.svg");
    
    // Set options for vectorization
    std::shared_ptr<VectorizationOptions> opts = std::make_shared<VectorizationOptions>();
    opts->setErrorThreshold(50)
        ->setColorLimit(2)
        ->setLineWidth(1.5)
        ->setMaxIteration(10);
    
    // Upload file to the storage
    // Create StorageApi
    std::shared_ptr<StorageApi> storage_api = std::make_shared<StorageApi>(apiClient);

    std::shared_ptr<HttpContent> file(new HttpContent(w_cur_dir, "test.png"));
    utility::string_t folder = _XPLATSTR("/");
    boost::optional<utility::string_t> storage = boost::none;
    
    auto res = storage_api->uploadFile(folder, file, storage).get();

    if(res->errorsIsSet())
    {
        throw std::runtime_error("Unable to upload file to the storage");
    }
    
    //Vectorization
    auto result = api->vectorizeStorageToStorage(src, dst, storage, opts);
    
    // Check the result file
    boost::optional<utility::string_t> versionId = _XPLATSTR("");
    
    // Result exists checking.
    auto result_exist = storage_api->objectExists(result->getFile(), versionId, storage).get();

    if(!result_exist->isExists())
    {
        throw std::runtime_error("Vectorization failed");
    }
}
```
[&#8593;UP&#8593;](VectorizationApi.md#VectorizationApi)

