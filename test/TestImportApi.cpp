/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TestImportApi.cpp">
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

class TestImportApi : public TestBase
{

public:
    ImportApi* api;
    StorageApi* storage_api;

    boost::optional<utility::string_t> folder;
    boost::optional<utility::string_t> storage;
    utility::string_t name;
    boost::optional<utility::string_t> versionId;

protected:

    void SetUp()
	{
        try 
        {
            std::shared_ptr<ApiConfiguration> apiConfig(new ApiConfiguration(clientId, clientSecret, basePath, authPath));
            std::shared_ptr<ApiClient> apiClient(new ApiClient(apiConfig));
            api = new ImportApi(apiClient);
            storage_api = new StorageApi(apiClient);

            folder = _XPLATSTR("HtmlTestDoc");
            storage = boost::none;
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
TEST_F(TestImportApi, DISABLED_testGetMarkdownToHtml)
{
	//Upload document to storage
    utility::string_t name = _XPLATSTR("testpage1.md");
    std::shared_ptr<HttpContent> file(new HttpContent(testSource, name));

	utility::string_t path_to_file = _XPLATSTR("HtmlTestDoc/testpage1.md");

	auto res = storage_api->uploadFile(path_to_file, file, storage).get();

    ASSERT_FALSE(res->errorsIsSet());

	auto result = api->getConvertMarkdownToHtml(name, folder, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("test_get_md_to_html.html")));

	//Clear test file in the storage
	auto result_del = storage_api->deleteFile(path_to_file, versionId, storage).get();

	ASSERT_TRUE(result_del->getCode() == 200);
	ASSERT_TRUE(result_del->getStatus() == _XPLATSTR("OK"));
}
TEST_F(TestImportApi, DISABLED_testPostConvertMarkdownInRequestToHtml)
{
    //Prepare document
    utility::string_t name = _XPLATSTR("testpage1.md");
    std::shared_ptr<HttpContent> file(new HttpContent(testSource, name));

    // Post convert markdown to html format
    utility::string_t outPath = _XPLATSTR("HtmlTestDoc/test_post_md_to_html.html");
    api->postConvertMarkdownInRequestToHtml(outPath, file, storage).get();

    // Download file from storage
    auto result_download = storage_api->downloadFile(outPath, versionId, storage).get();

    ASSERT_TRUE(TestBase::save_to_file(result_download, testResult + _XPLATSTR("test_post_md_to_html.html")));

    //Clear test file in the storage
    auto result_del_test = storage_api->deleteFile(outPath, versionId, storage).get();

    ASSERT_TRUE(result_del_test->getCode() == 200);
    ASSERT_TRUE(result_del_test->getStatus() == _XPLATSTR("OK"));
}
TEST_F(TestImportApi, DISABLED_testPutMarkdownToHtml)
{
	//Upload document to storage
    utility::string_t name = _XPLATSTR("testpage1.md");
    std::shared_ptr<HttpContent> file(new HttpContent(testSource, name));
    
    utility::string_t path_to_file = _XPLATSTR("HtmlTestDoc/testpage1.md");
    boost::optional<utility::string_t> versionId = boost::none;

	auto res = storage_api->uploadFile(path_to_file, file, storage).get();

	ASSERT_FALSE(res->errorsIsSet());

	// Put convert markdown to html format
	utility::string_t outPath = _XPLATSTR("HtmlTestDoc/test_put_md_to_html.html");

	api->putConvertMarkdownToHtml(name, outPath, folder, storage).get();

	//Clear test file in the storage
	auto result_del_test = storage_api->deleteFile(path_to_file, versionId, storage).get();

	ASSERT_TRUE(result_del_test->getCode() == 200);
	ASSERT_TRUE(result_del_test->getStatus() == _XPLATSTR("OK"));

	// Download file from storage
	auto result_download = storage_api->downloadFile(outPath, versionId, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result_download, testResult + _XPLATSTR("test_put_md_to_html.html")));

	//Clear result file
	auto result_del = storage_api->deleteFile(outPath, versionId, storage).get();

	ASSERT_TRUE(result_del->getCode() == 200);
	ASSERT_TRUE(result_del->getStatus() == _XPLATSTR("OK"));
}
