
![](https://img.shields.io/badge/api-v3.0-lightgrey) ![Nuget](https://img.shields.io/nuget/v/Aspose.html-Cloud) ![Nuget](https://img.shields.io/nuget/dt/Aspose.html-Cloud) [![GitHub license](https://img.shields.io/github/license/aspose-html-cloud/aspose-html-cloud-cpp)](https://github.com/aspose-html-cloud/aspose-html-cloud-dotnet/blob/master/LICENSE) ![GitHub last commit](https://img.shields.io/github/last-commit/Aspose-html-Cloud/aspose-html-cloud-cpp)

# HTML Rendering & Conversion C++ Cloud REST API
Aspose.HTML Cloud for C++ is a programming SDK that allows software developers to manipulate and convert HTML documents from within their own applications. A Wrapper of RESTful APIs, Aspose.HTML Cloud for C++ speeds up HTML programming and conversion.
This cloud SDK assists to develop cloud-based [HTML page rendering, processing, translation & conversion](https://products.aspose.cloud/html/cpp) apps in C++ via REST API.

## HTML Processing Features
- Fetch the HTML page along with its resources as a ZIP archive by providing the page URL.
- Based on page URL, retrieve all images of an HTML page as a ZIP package.
- Load data from a local file to populate the HTML document template.
- Use the request body to populate the HTML document template.
- Convert HTML page to numerous other file formats.

## Read & Write HTML Formats
HTML, XHTML, zipped HTML, zipped XHTML, MHTML, HTML containing SVG markup, Markdown, JSON

## Save HTML As
*Fixed Layout*: PDF, XPS
*Images*: TIFF, JPEG, PNG, BMP, GIF
*Other*: TXT, ZIP (images)

## Read HTML Formats
*eBook*: EPUB
*Other*: XML, SVG

## Enhancements Version 20.11

- New generation of Aspose.HTML Cloud SDK for .NET (C#) is provided.
- This version of SDK has been redesigned from scratch being based on the new Aspose.HTML Cloud REST API (v3.0).
- Currently, it provides only the conversion feature. Other features that are still available in the versions up to v.20.08 are planned to be implemented in this SDK later.
- Conversion interface provides a more flexible conversion parameters setup.
- Redesigned storage access is provided using SDK entry point HtmlApi.Storage.
- Availability of synchronous and asynchronous file upload and download methods.
- Asynchronous download provides the ability to get progress data for the longer downloads.

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

## Convert HTML to PNG in C++

```code
	// Get your ClientId and ClientSecret from https://dashboard.aspose.cloud (free registration required).

	const utility::string_t clientId = _XPLATSTR("MY_CLIENT_ID");
	const utility::string_t clientSecret = _XPLATSTR("MY_CLIENT_SECRET");
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

## Aspose.HTML Cloud SDKs in Popular Languages

| .NET | Java | PHP | Python | Ruby | Node.js | Android | Swift|C++|Go|
|---|---|---|---|---|---|---|--|--|--|
| [GitHub](https://github.com/aspose-html-cloud/aspose-html-cloud-dotnet) | [GitHub](https://github.com/aspose-html-cloud/aspose-html-cloud-java) | [GitHub](https://github.com/aspose-html-cloud/aspose-html-cloud-php) | [GitHub](https://github.com/aspose-html-cloud/aspose-html-cloud-python) | [GitHub](https://github.com/aspose-html-cloud/aspose-html-cloud-ruby)  | [GitHub](https://github.com/aspose-html-cloud/aspose-html-cloud-nodejs) | [GitHub](https://github.com/aspose-html-cloud/aspose-html-cloud-android) | [GitHub](https://github.com/aspose-html-cloud/aspose-html-cloud-swift)|[GitHub](https://github.com/aspose-html-cloud/aspose-html-cloud-cpp) |[GitHub](https://github.com/aspose-html-cloud/aspose-html-cloud-go) |
| [NuGet](https://www.nuget.org/packages/Aspose.html-Cloud/) | [Maven](https://repository.aspose.cloud/webapp/#/artifacts/browse/tree/General/repo/com/aspose/aspose-html-cloud) | [Composer](https://packagist.org/packages/aspose/aspose-html-cloud-php) | [PIP](https://pypi.org/project/asposehtmlcloud/) | [GEM](https://rubygems.org/gems/aspose_html_cloud)  | [NPM](https://www.npmjs.com/package/@asposecloud/aspose-html-cloud) | [Maven](https://repository.aspose.cloud/webapp/#/artifacts/browse/tree/General/repo/com/aspose/aspose-html-cloud) | [Cocoapods](https://cocoapods.org/pods/AsposeHtmlCloud)|[NuGet](https://www.nuget.org/packages/Aspose.Html-Cloud.Cpp/) | [Go.Dev](#) |

[Product Page](https://products.aspose.cloud/html/cpp) | [Documentation](https://docs.aspose.cloud/display/htmlcloud/Home) | [API Reference](https://apireference.aspose.cloud/html/) | [Code Samples](https://github.com/aspose-html-cloud/aspose-html-cloud-cpp) | [Blog](https://blog.aspose.cloud/category/html/) | [Free Support](https://forum.aspose.cloud/c/html) | [Free Trial](https://dashboard.aspose.cloud/#/apps)
