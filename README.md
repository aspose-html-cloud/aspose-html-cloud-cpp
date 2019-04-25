# Aspose HTML Cloud SDK C++

AsposeHtml - the C++ library for the Aspose.HTML Cloud API Reference

- API version: 1.1
- Package version: 1.0.1

## Requirements
- C++11
- [Boost](https://www.boost.org/)
- [C++ REST SDK](https://github.com/Microsoft/cpprestsdk)

## Installation

### Load from git

    git clone https://github.com/aspose-html-cloud/aspose-html-cloud-cpp.git
    cd aspose-html-cloud-cpp

## Getting Started
To use Aspose HTML for Cloud SDK you need to register an account with [Aspose Cloud](https://www.aspose.cloud/) and lookup/create App Key and SID at [Cloud Dashboard](https://dashboard.aspose.cloud/#/apps). There is free quota available. For more details, see [Aspose Cloud Pricing](https://purchase.aspose.cloud/pricing).

```code
    const utility::string_t clientId = _XPLATSTR("XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX");
    const utility::string_t clientSecret = _XPLATSTR("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    const utility::string_t basePath = _XPLATSTR("https://api.aspose.cloud/v1.1");
    const utility::string_t authPath = _XPLATSTR("https://api.aspose.cloud/oauth2/token");

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
    std::ofstream saved_data(testresult + _XPLATSTR("ConvertResult.png"), std::ios::out | std::ios::binary);

    result.writeTo(saved_data);
    saved_data.close();
    
    delete api;
```


For use SDK see examples in [test](./test/)

## Documentation for API Endpoints

All URIs are relative to *https://api.aspose.cloud/v1.1*   

- [ConversionApi](./docs/html/de/dcc/classcom_1_1aspose_1_1api_1_1_conversion_api.html)
- [DocumentApi](./docs/html/dc/d9d/classcom_1_1aspose_1_1api_1_1_document_api.html)
- [OcrApi](./docs/html/d1/d11/classcom_1_1aspose_1_1api_1_1_ocr_api.html)
- [SummarizationApi](./docs/html/dc/dce/classcom_1_1aspose_1_1api_1_1_summarization_api.html)
- [TranslationApi](./docs/html/d4/d7a/classcom_1_1aspose_1_1api_1_1_translation_api.html)
- [TemplateMergeApi](./docs/html/d7/d0c/classcom_1_1aspose_1_1api_1_1_template_merge_api.html)

Aspose HTML includes Aspose.Storage.Cloud to manipulate files on a remote server. This is used in tests for download test files to the server.
- [StorageApi](./docs/html/dd/d83/classcom_1_1aspose_1_1api_1_1_storage_api.html)


## oauth

- **Type**: OAuth
- **Flow**: application
- **Authorization URL**: "https://api.aspose.cloud/oauth2/token"
- **Scopes**: N/A

[Tests](./test/) contain various examples of using the Aspose.HTML SDK.

[Docs](./docs/html/) Documentation for Aspose.HTML Api SDK
