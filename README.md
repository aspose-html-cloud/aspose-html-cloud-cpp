# Aspose HTML Cloud SDK C++

AsposeHtml - the C++ library for the Aspose.HTML Cloud API Reference

- API version: 3.0
- Package version: 20.8.0

## Installation

Get ready package or build from source.

### Install from command line

```code
PM> Install-Package Aspose.Html-Cloud.Cpp -Version 20.8.0
```

### Load from git

    git clone https://github.com/aspose-html-cloud/aspose-html-cloud-cpp.git
    cd aspose-html-cloud-cpp

## Getting Started
To use Aspose HTML for Cloud SDK you need to register an account with [Aspose Cloud](https://www.aspose.cloud/) and lookup/create App Key and SID at [Cloud Dashboard](https://dashboard.aspose.cloud/#/apps). There is free quota available. For more details, see [Aspose Cloud Pricing](https://purchase.aspose.cloud/pricing).

```code

// Get keys from aspose site.
// There is free quota available. 
// For more details, see https://purchase.aspose.cloud/pricing

    const utility::string_t clientId = _XPLATSTR("XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX");
    const utility::string_t clientSecret = _XPLATSTR("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    const utility::string_t basePath = _XPLATSTR("https://api.aspose.cloud/v3.0");
    const utility::string_t authPath = _XPLATSTR("https://api.aspose.cloud/connect/token");

    //Helper directory with data for test
    const utility::string_t testResult = _XPLATSTR("..\\testresult\\");

    //Create configuration for authorization
    std::shared_ptr<ApiConfiguration> apiConfig(new ApiConfiguration(clientId, clientSecret, basePath, authPath));

    //Create client from configuration
    std::shared_ptr<ApiClient> apiClient(new ApiClient(apiConfig));
    
    //Create ConversionApi
    ConversionApi *api = new ConversionApi(apiClient);

    //Parameters for conversion
    utility::string_t sourceUrl = _XPLATSTR("https://stallman.org/articles/anonymous-payments-thru-phones.html");
    boost::optional<int32_t> width = 800;
    boost::optional<int32_t> height = 1000;
    boost::optional<int32_t> leftMargin = 20;
    boost::optional<int32_t> rightMargin = 20;
    boost::optional<int32_t> topMargin = 20;
    boost::optional<int32_t> bottomMargin = 20;
    boost::optional<int32_t> resolution = 300;
    
    //Convert to png
	auto result = api->getConvertDocumentToImageByUrl(sourceUrl, _XPLATSTR("png"),
		width, height, leftMargin, rightMargin, topMargin, bottomMargin, resolution).get();

        
    //Save result to files
    std::ofstream saved_data(testresult + _XPLATSTR("ConvertResult.zip"), std::ios::out | std::ios::binary);

    result.writeTo(saved_data);
    saved_data.close();
    
    delete api;
```
## Documentation for API Endpoints

All URIs are relative to *https://api.aspose.cloud/v3.0*   

## Examples
- [ConversionApi](./docs/ConversionApi.md)
- [ImportApi](./docs/ImportApi.md)
- [DocumentApi](./docs/DocumentApi.md)
- [SeoApi](./docs/SeoApi.md)
- [TemplateMergeApi](./docs/TemplateMergeApi.md)
- [StorageApi](./docs/StorageApi.md)


## Requirements (for build from source)
- C++11
- [Boost](https://www.boost.org/)
- [C++ REST SDK](https://github.com/Microsoft/cpprestsdk)

## oauth

- **Type**: OAuth
- **Flow**: application
- **Authorization URL**: "https://api.aspose.cloud/connect/token"
- **Scopes**: N/A

[Tests](./test/) contain various examples of using the Aspose.HTML SDK.

[All API in html format](./docs/html/) Documentation for Aspose.HTML Api SDK
