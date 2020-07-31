/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TestTemplateMergeApi.cpp">
*  Copyright (c) 2020 Aspose.HTML for Cloud
* </copyright>
* <summary>
*  Permission is hereby granted, free of charge, to any person obtaining a copy
*  of this software and associated documentation files (the "Software"), to deal
*  in the Software without restriction, including without limitation the rights
*  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*  copies of the Software, and to permit persons to whom the Software is
*  furnished to do so, subject to the following conditions:
*
*  The above copyright notice and this permission notice shall be included in all
*  copies or substantial portions of the Software.
*
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
*  SOFTWARE.
* </summary>
* --------------------------------------------------------------------------------------------------------------------
*/
#include "TestBase.h"

using namespace com::aspose::api;

class TestTemplateMergeApi : public TestBase
{

public:

    TemplateMergeApi* api;
    StorageApi* storage_api;

    boost::optional<utility::string_t> storage;
    utility::string_t template_name;
    utility::string_t data_name;
    boost::optional<utility::string_t> versionId;

protected:

    void SetUp()
	{
        try
        {
            std::shared_ptr<ApiConfiguration> apiConfig(new ApiConfiguration(clientId, clientSecret, basePath, authPath));
            std::shared_ptr<ApiClient> apiClient(new ApiClient(apiConfig));
            api = new TemplateMergeApi(apiClient);
            storage_api = new StorageApi(apiClient);

            storage = boost::none;
            template_name = _XPLATSTR("HtmlTemplate.html");
            data_name = _XPLATSTR("XmlSourceData.xml");
            versionId = _XPLATSTR("");


            //Upload template file to server
            utility::string_t template_name = _XPLATSTR("HtmlTemplate.html");
            std::shared_ptr<HttpContent> template_file(new HttpContent(testSource, template_name));
            utility::string_t path_to_template = _XPLATSTR("HtmlTestDoc/HtmlTemplate.html");

            auto res = storage_api->uploadFile(path_to_template, template_file, storage).get();

            ASSERT_FALSE(res->errorsIsSet());

            //Upload data file to server
            utility::string_t data_name = _XPLATSTR("XmlSourceData.xml");
            std::shared_ptr<HttpContent> data_file(new HttpContent(testSource, data_name));
            utility::string_t path_to_data = _XPLATSTR("HtmlTestDoc/XmlSourceData.xml");

            res = storage_api->uploadFile(path_to_data, data_file, storage).get();

            ASSERT_FALSE(res->errorsIsSet());
        }
        catch (std::exception& e)
        {
            api = nullptr;
            storage_api = nullptr;
            std::cout << e.what() << '\n';
        }
    }

    void TearDown()
    {
        if (api != nullptr) { delete api; }
        if (storage_api != nullptr) { delete storage_api; }
    }
};

TEST_F(TestTemplateMergeApi, DISABLED_testGetMergeHtmlTemplate)
{

	//Parameters
	utility::string_t templateName = _XPLATSTR("HtmlTemplate.html");
	utility::string_t dataPath = _XPLATSTR("HtmlTestDoc/XmlSourceData.xml");
	boost::optional<utility::string_t> options = _XPLATSTR("");
	boost::optional<utility::string_t> folder = _XPLATSTR("HtmlTestDoc");
	boost::optional<utility::string_t> storage = boost::none;

	auto result = api->getMergeHtmlTemplate(templateName, dataPath, options, folder, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("getTemplateMerge.html")));
}
TEST_F(TestTemplateMergeApi, DISABLED_testPostMergeHtmlTemplate)
{
    //Prepare file stream to upload
    utility::string_t name = _XPLATSTR("XmlSourceData.xml");
    std::shared_ptr<HttpContent> file(new HttpContent(testSource, name));

    //Parameters
    utility::string_t templateName = _XPLATSTR("HtmlTemplate.html");
    utility::string_t outPath = _XPLATSTR("HtmlTestDoc/postTemplateResult.html");
    boost::optional<utility::string_t> options = _XPLATSTR("");
    boost::optional<utility::string_t> folder = _XPLATSTR("HtmlTestDoc");
    boost::optional<utility::string_t> storageName = boost::none;

    auto result = api->postMergeHtmlTemplate(templateName, outPath, file, options, folder, storageName).get();

    // Check exist file
    auto result_exist = storage_api->objectExists(outPath, versionId, storageName).get();

    ASSERT_TRUE(result_exist->isExists());
    ASSERT_FALSE(result_exist->isFolder());

    // Download file from storage
    auto result_download = storage_api->downloadFile(outPath, versionId, storageName).get();

    ASSERT_TRUE(TestBase::save_to_file(result_download, testResult + _XPLATSTR("postTemplateMerhe.html")));

    //Clear file
    auto result_del = storage_api->deleteFile(outPath, versionId, storageName).get();

    ASSERT_TRUE(result_del->getCode() == 200);
    ASSERT_TRUE(result_del->getStatus() == _XPLATSTR("OK"));

    // Check not exist file
    result_exist = storage_api->objectExists(outPath, versionId, storageName).get();

    ASSERT_FALSE(result_exist->isExists());
    ASSERT_FALSE(result_exist->isFolder());
}
