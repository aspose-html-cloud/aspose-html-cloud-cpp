<a name="TemplateMergeApi"></a>
## TemplateMergeApi

All URIs are relative to *https://api.aspose.cloud/v3.0*

Method | HTTP request | Description
------------- | ------------- | -------------
[**getMergeHtmlTemplate**](TemplateMergeApi.md#getMergeHtmlTemplate) | **GET** /html/\{templateName\}/merge | Populate HTML document template with data located as a file in the storage.
[**postMergeHtmlTemplate**](TemplateMergeApi.md#postMergeHtmlTemplate) | **POST** /html/\{templateName\}/merge | Populate HTML document template with data from the request body. Result document will be saved to storage.


<a name="getMergeHtmlTemplate"></a>
### **getMergeHtmlTemplate**
>     ASPOSE_DLL_EXPORT pplx::task<HttpContent> getMergeHtmlTemplate(
>        utility::string_t templateName,              // Template document name. Template document is HTML or zipped HTML.
>        utility::string_t dataPath,                  // Data source file path in the storage. Supported data format: XML
>        boost::optional<utility::string_t> options,  // Template merge options: reserved for further implementation. (optional)
>        boost::optional<utility::string_t> folder,   // The template document folder. (optional)
>        boost::optional<utility::string_t> storage); // The template document and data source storage. (optional)

Populate HTML document template with data located as a file in the storage.

[&#8593;UP&#8593;](TemplateMergeApi.md#TemplateMergeApi)

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

    // Create TemplateMergeApi
    TemplateMergeApi* api = new TemplateMergeApi(apiClient);

    // Create StorageApi
    StorageApi* storage_api = new StorageApi(apiClient);

    // Folder name in the storage (should already exist)
    utility::string_t folder = _XPLATSTR("HtmlTestDoc");

    // Storage, received at registration, default is none
    boost::optional<utility::string_t> storage = boost::none;

    // Template file for merge
    utility::string_t template_name = _XPLATSTR("HtmlTemplate.html");

    // Upload template file for merge to storage (path = w_cur_dir, name = "HtmlTemplate.html")
    std::shared_ptr<HttpContent> file_html(new HttpContent(w_cur_dir, template_name));

    // Path to template file in the storage
    utility::string_t path_to_template_file = folder + _XPLATSTR("/") + template_name;

    // Upload file to the storage
    auto res = storage_api->uploadFile(path_to_template_file, file_html, storage).get();

    // Check for errors
    assert(!res->errorsIsSet());

    // Data file for merge
    utility::string_t data_name = _XPLATSTR("XmlSourceData.xml");

    // Upload data file for merge to storage (path = w_cur_dir, name = "XmlSourceData.xml")
    std::shared_ptr<HttpContent> file_data(new HttpContent(w_cur_dir, data_name));

    // Path to data file in the storage
    utility::string_t path_to_data_file = folder + _XPLATSTR("/") + data_name;

    // Upload file to the storage
    res = storage_api->uploadFile(path_to_data_file, file_data, storage).get();

    // Check for errors
    assert(!res->errorsIsSet());

    // Reserved
    boost::optional<utility::string_t> options = std::wstring( _XPLATSTR(""));

    // Merge template and data and get result as html file in body.
    auto result = api->getMergeHtmlTemplate(template_name, path_to_data_file, options, folder, storage).get();

    // Save result to files
    std::ofstream saved_data(_XPLATSTR("GetMergeTemplate.html"), std::ios::out | std::ios::binary);

    result.writeTo(saved_data);
    saved_data.close();

    delete api;
    delete storage_api;
}
```
[&#8593;UP&#8593;](TemplateMergeApi.md#TemplateMergeApi)


<a name="postMergeHtmlTemplate"></a>
### **postMergeHtmlTemplate**
>     ASPOSE_DLL_EXPORT pplx::task<HttpContent> postMergeHtmlTemplate(
>        utility::string_t templateName,              // Template document name. Template document is HTML or zipped HTML.
>        utility::string_t outPath,                   // Result document path.
>        std::shared_ptr<HttpContent> file,           // A data file to populate template.
>        boost::optional<utility::string_t> options,  // Template merge options: reserved for further implementation. (optional)
>        boost::optional<utility::string_t> folder,   // The template document folder. (optional)
>        boost::optional<utility::string_t> storage); // The template document and data source storage. (optional)

Populate HTML document template with data from the request body. Result document will be saved to storage.

[&#8593;UP&#8593;](TemplateMergeApi.md#TemplateMergeApi)

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
    TemplateMergeApi* api = new TemplateMergeApi(apiClient);

    // Create StorageApi
    StorageApi* storage_api = new StorageApi(apiClient);

    // Folder name in the storage (should already exist)
    utility::string_t folder = _XPLATSTR("HtmlTestDoc");

    // Storage, received at registration, default is none
    boost::optional<utility::string_t> storage = boost::none;

    // Template file for merge
    utility::string_t template_name = _XPLATSTR("HtmlTemplate.html");

    // Prepare template file for uploading to the storage (path = w_cur_dir, name = "HtmlTemplate.html")
    std::shared_ptr<HttpContent> file_html(new HttpContent(w_cur_dir, template_name));

    // Path to template file in the storage
    utility::string_t path_to_template_file = folder + _XPLATSTR("/") + template_name;

    // Upload template file to the storage
    auto res = storage_api->uploadFile(path_to_template_file, file_html, storage).get();

    // Check for errors
    assert(!res->errorsIsSet());

    // Data file for merge
    utility::string_t data_name = _XPLATSTR("XmlSourceData.xml");

    // Prepare data file for request
    std::shared_ptr<HttpContent> file_data(new HttpContent(w_cur_dir, data_name));

    // Reserved
    boost::optional<utility::string_t> options = std::wstring(_XPLATSTR(""));
    
    // Result file name in the storage
    auto result_name = _XPLATSTR("PostMergeHtmlTemplate.html");

    // Path to result file in the storage
    auto result_path = folder + _XPLATSTR("/") + result_name;

    // Merge template and data and save result to storage.
    auto result = api->postMergeHtmlTemplate(template_name, result_path, file_data, options, folder, storage).get();

    // Check exist file
    boost::optional<utility::string_t> versionId = std::wstring(_XPLATSTR(""));
    auto result_exist = storage_api->objectExists(result_path, versionId, storage).get();

    assert(result_exist->isExists());
    assert(!result_exist->isFolder());

    // Download file from storage
    auto result_download = storage_api->downloadFile(result_path, versionId, storage).get();

    //Save result to files
    std::ofstream saved_data(result_name, std::ios::out | std::ios::binary);
    result_download.writeTo(saved_data);
    saved_data.close();

    delete api;
    delete storage_api;
}
```
[&#8593;UP&#8593;](TemplateMergeApi.md#TemplateMergeApi)


### Data used in examples
 
#### HtmlTemplate.html

```code
<html>
<head>
    <title>{{Title}}</title>
    <meta charset="utf-8" />
    <style>
    table, th, td {
        border: 1px solid black;
        border-spacing: 0px
    }
    </style>
</head>
    <body>

        <br>
        <table data_merge="{{#foreach Person}}">
            <caption>TABLE 1</caption>
            <tr>
                <th>Name</th>
                <th>Surname</th>
                <th>City</th>
                <th>Street</th>
                <th>Number</th>
            </tr>
            <tr>
                <td>{{Name}}</td>
                <td>{{Surname}}</td>
                <td>{{Address.City}}</td>
                <td>{{Address.Street}}</td>
                <td>{{Address.Number}}</td>
            </tr>
        </table>
        <br>
        <table data_merge="{{#foreach Person}}">
            <caption>TABLE 2</caption>
            <thead>
                <tr>
                    <th>Name</th>
                    <th>Surname</th>
                    <th>City</th>
                    <th>Street</th>
                    <th>Number</th>
                </tr>            
            </thead>
            <tbody>
                <tr>
                    <td>{{Name}}</td>
                    <td>{{Surname}}</td>
                    <td>{{Address.City}}</td>
                    <td>{{Address.Street}}</td>
                    <td>{{Address.Number}}</td>
                </tr>            
            </tbody>
        </table>        
    </body>
</html>
```
[&#8593;UP&#8593;](TemplateMergeApi.md#TemplateMergeApi)

#### XmlSourceData.xml
```code
<?xml version="1.0" encoding="utf-8" ?>
<Data>
    <Title>Test</Title>
    <Person>
        <Name>John</Name>
        <Surname>Smith</Surname>
        <Address>
            <Number>200</Number>
            <Street>Austin rd.</Street>
            <City>Dallas</City>
        </Address>
    </Person>
    <Person>
        <Name>Jack</Name>
        <Surname>Fox</Surname>
        <Address>
            <Number>25</Number>
            <Street>Broadway</Street>
            <City>New York</City>
        </Address>
    </Person>
    <Person>
        <Name>Sherlock</Name>
        <Surname>Holmes</Surname>
        <Address>
            <Number>65</Number>
            <Street>Baker str.</Street>
            <City>London</City>
        </Address>
    </Person>
</Data>
```
[&#8593;UP&#8593;](TemplateMergeApi.md#TemplateMergeApi)