<a name="SeoApi"></a>
## SeoApi

All URIs are relative to *https://api.aspose.cloud/v3.0*

Method | HTTP request | Description
------------- | ------------- | -------------
[**getSeoWarning**](SeoApi.md#getSeoWarning) | **GET** /html/seo | Page analysis and return of SEO warnings.
[**getHtmlWarning**](SeoApi.md#getHtmlWarning) | **GET** /html/validator | Checks the markup validity of Web documents in HTML, XHTML, etc.


<a name="getSeoWarning"></a>
### **getSeoWarning**
>     ASPOSE_DLL_EXPORT pplx::task<HttpContent> getSeoWarning(
>        utility::string_t addr); // Source page URL for analyses.

Page analysis and return of SEO warnings in json format.

[&#8593;UP&#8593;](SeoApi.md#SeoApi)

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

    // Create SeoApi
    SeoApi* api = new SeoApi(apiClient);

    // Get Seo warnings by url
    auto result = api->getSeoWarning(_XPLATSTR("https://lenta.ru/")).get();

    // Save result to files
    std::ofstream saved_data(_XPLATSTR("SeoWarnings.json"), std::ios::out | std::ios::binary);

    result.writeTo(saved_data);
    saved_data.close();

    delete api;
}
```
[&#8593;UP&#8593;](SeoApi.md#SeoApi)


<a name="getHtmlWarning"></a>
### **getHtmlWarning**
>     ASPOSE_DLL_EXPORT pplx::task<HttpContent> getHtmlWarning(
>        utility::string_t url); // Source page URL for analyses.

Checks the markup validity of Web documents in HTML, XHTML, etc.

[&#8593;UP&#8593;](SeoApi.md#SeoApi)

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

    // Create SeoApi
    SeoApi* api = new SeoApi(apiClient);

    // Get html warnings by url
    auto result = api->getHtmlWarning(_XPLATSTR("https://lenta.ru/")).get();

    // Save result to files
    std::ofstream saved_data(_XPLATSTR("HtmlWarning.json"), std::ios::out | std::ios::binary);

    result.writeTo(saved_data);
    saved_data.close();

    delete api;
}
```
[&#8593;UP&#8593;](SeoApi.md#SeoApi)