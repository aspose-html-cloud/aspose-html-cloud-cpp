# Aspose HTML Cloud SDK C++

AsposeHtml - the C++ library for the Aspose.HTML Cloud API Reference

- API version: 4.0
- Package version: 22.11.1

## Installation

Get ready package or build from source.

### Install from command line

```code
PM> Install-Package Aspose.Html-Cloud.Cpp -Version 22.11.1
```

### Load from git

    git clone https://github.com/aspose-html-cloud/aspose-html-cloud-cpp.git
    cd aspose-html-cloud-cpp

## Getting Started
To use Aspose HTML for Cloud SDK you need to register an account with [Aspose Cloud](https://www.aspose.cloud/) and lookup/create App Key and SID at [Cloud Dashboard](https://dashboard.aspose.cloud/#/apps). There is free quota available. For more details, see [Aspose Cloud Pricing](https://purchase.aspose.cloud/pricing).

### Possible conversions: 
- HTML -> PDF, XPS, DOCX, MD, MHTML, JPEG, BMP, PNG, TIFF, GIF
- EPUB -> PDF, XPS, DOCX, JPEG, BMP, PNG, TIFF, GIF
- MD -> PDF, XPS, DOCX, HTML, MHTML, JPEG, BMP, PNG, TIFF, GIF
- MHTML -> PDF, XPS, DOCX, JPEG, BMP, PNG, TIFF, GIF
- SVG -> PDF, XPS, JPEG, BMP, PNG, TIFF, GIF
- JPEG, BMP, PNG, TIFF, GIF -> SVG


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
    opts->setWidth(800)         // Size in pixels for images, for output formats PDF, XPS, DOCX - in inches.
        ->setHeight(600)        // Size in pixels for images, for output formats PDF, XPS, DOCX - in inches.
        ->setLeftMargin(10)     // Size in pixels for images, for output formats PDF, XPS, DOCX - in inches.
        ->setRightMargin(10)    // Size in pixels for images, for output formats PDF, XPS, DOCX - in inches.
        ->setTopMargin(10)      // Size in pixels for images, for output formats PDF, XPS, DOCX - in inches.
        ->setBottomMargin(10);  // Size in pixels for images, for output formats PDF, XPS, DOCX - in inches.
    
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

### ConversionOptions
| Method                                                                            | Description                                                                      | Note     |
|-----------------------------------------------------------------------------------|----------------------------------------------------------------------------------|----------|
| **ConversionOptions\* ConversionOptions::setWidth(double value)**                 | Width in inches for PDF, XPS, DOCX output formats. In pixels for images.         | Optional |
| **ConversionOptions\* ConversionOptions::setHeight(double value)**                | Height in inches for PDF, XPS, DOCX output formats. In pixels for images.        | Optional |
| **ConversionOptions\* ConversionOptions::setLeftMargin(double value)**            | Left margin in inches for PDF, XPS, DOCX output formats. In pixels for images.   | Optional |
| **ConversionOptions\* ConversionOptions::setRightMargin(double value)**           | Right margin in inches for PDF, XPS, DOCX output formats. In pixels for images.  | Optional |
| **ConversionOptions\* ConversionOptions::setTopMargin(double value)**             | Top margin in inches for PDF, XPS, DOCX output formats. In pixels for images.    | Optional |
| **ConversionOptions\* ConversionOptions::setBottomMargin(double value)**          | Bottom margin in inches for PDF, XPS, DOCX output formats. In pixels for images. | Optional |
| **ConversionOptions\* ConversionOptions::setJpegQuality(int value)**              | Quality in percent (for PDF conversion only).                                    | Optional |
| **ConversionOptions\* ConversionOptions::setBackground(utility::string_t value)** | CSS background like '#FF0000'. For conversion from SVG only.                     | Optional |


### Additional options for trace to the SVG format
| Method                                                                     | Description                                                                                             | Note     |
|----------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------|----------|
| **ConversionOptions\* ConversionOptions::setErrorThreshold(double value)** | This parameter defines maximum deviation of points to fitted curve. By default it is 30.                | Optional |
| **ConversionOptions\* ConversionOptions::setMaxIteration(int value)**      | This parameter defines number of iteration for least-squares approximation method. By default it is 30. | Optional |
| **ConversionOptions\* ConversionOptions::setColorLimit(int value)**        | The maximum number of colors used to quantize an image. Default value is 25.                            | Optional |
| **ConversionOptions\* ConversionOptions::setLineWidth(double value)**      | The value of this parameter is affected by the graphics scale. Default value is 1.                      | Optional |


### Additional options for convert to the markdown format
| Method                                                           | Description                                   | Note     |
|------------------------------------------------------------------|-----------------------------------------------|----------|
| **ConversionOptions\* ConversionOptions::setUseGit(bool value)** | Use git flavor. True or False. Default false. | Optional |


## Documentation for API Endpoints

All URIs are relative to *https://api.aspose.cloud/v4.0*   

## Examples
- [ConversionApi](./docs/ConversionApi.md)
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