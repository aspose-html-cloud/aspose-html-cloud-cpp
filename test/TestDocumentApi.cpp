/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TestDocumentApi.cpp">
*  Copyright (c) 2019 Aspose.HTML for Cloud
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


#include "ApiConfiguration.h"
#include "api/DocumentApi.h"
#include "api/StorageApi.h"
#include "TestBase.h"

using namespace com::aspose::api;

class TestDocumentApi : public TestBase
{

public:

    DocumentApi* api;
    StorageApi* storage_api;

protected:

    void SetUp()
	{
        try 
        {
            std::shared_ptr<ApiConfiguration> apiConfig(new ApiConfiguration(clientId, clientSecret, basePath, authPath));
            std::shared_ptr<ApiClient> apiClient(new ApiClient(apiConfig));
            api = new DocumentApi(apiClient);
            storage_api = new StorageApi(apiClient);
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

TEST_F(TestDocumentApi, testGetHtmlByUrl)
{

	//Get web page and all linked resourses
	auto result = api->getDocumentByUrl(_XPLATSTR("https://lenta.ru/")).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("test_get_site_by_url.zip")));
}
TEST_F(TestDocumentApi, testGetHtmlFragmentByXPath)
{
	//Upload document to storage
    utility::string_t name = _XPLATSTR("test2.html.zip");
    std::shared_ptr<HttpContent> file(new HttpContent(testSource, name));

	utility::string_t path_to_file = _XPLATSTR("HtmlTestDoc/test2.html.zip");
	boost::optional<utility::string_t> storage = boost::none;
	boost::optional<utility::string_t> folder = _XPLATSTR("HtmlTestDoc");

	auto res = storage_api->uploadFile(path_to_file, file, storage).get();

	ASSERT_FALSE(res->errorsIsSet());

	// Get fragments from document
	utility::string_t xPath = _XPLATSTR(".//p");
	utility::string_t outFormat = _XPLATSTR("plain");

	auto result = api->getDocumentFragmentByXPath(name, xPath, outFormat, storage, folder).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("test_get_xpath.html")));
}
TEST_F(TestDocumentApi, testGetHtmlFragmentByXPathByUrl)
{

	// Get fragments from document url
	utility::string_t sourceUrl = _XPLATSTR("https://stallman.org/articles/anonymous-payments-thru-phones.html");
	utility::string_t xPath = _XPLATSTR(".//p");
	utility::string_t outFormat = _XPLATSTR("plain");

	auto result = api->getDocumentFragmentByXPathByUrl(sourceUrl, xPath, outFormat).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("test_get_xpath_url.html")));
}
TEST_F(TestDocumentApi, testGetHtmlFragmentByCSS)
{
	//Upload document to storage
    utility::string_t name = _XPLATSTR("test2.html.zip");
    std::shared_ptr<HttpContent> file(new HttpContent(testSource, name));

	utility::string_t path_to_file = _XPLATSTR("HtmlTestDoc/test2.html.zip");
	boost::optional<utility::string_t> storage = boost::none;
	boost::optional<utility::string_t> folder = _XPLATSTR("HtmlTestDoc");

	auto res = storage_api->uploadFile(path_to_file, file, storage).get();

	ASSERT_FALSE(res->errorsIsSet());

	// Get fragments from document
	utility::string_t selector = _XPLATSTR("div p");
	utility::string_t outFormat = _XPLATSTR("plain");

	auto result = api->getDocumentFragmentsByCSSSelector(name, selector, outFormat, folder, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("test_get_css.html")));
}
TEST_F(TestDocumentApi, testGetHtmlFragmentByCSSByUrl)
{

	// Get fragments from document url
	utility::string_t sourceUrl = _XPLATSTR("https://www.w3schools.com/cssref/css_selectors.asp");
	utility::string_t selector = _XPLATSTR("a[href$='.asp']");
	utility::string_t outFormat = _XPLATSTR("plain");

	auto result = api->getDocumentFragmentsByCSSSelectorByUrl(sourceUrl, selector, outFormat).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("test_get_css_url.html")));
}
TEST_F(TestDocumentApi, testGetHtmlImages)
{
	//Upload document to storage
    utility::string_t name = _XPLATSTR("test3.html.zip");
    std::shared_ptr<HttpContent> file(new HttpContent(testSource, name));

	utility::string_t path_to_file = _XPLATSTR("HtmlTestDoc/test3.html.zip");
	boost::optional<utility::string_t> storage = boost::none;
	boost::optional<utility::string_t> folder = _XPLATSTR("HtmlTestDoc");

	auto res = storage_api->uploadFile(path_to_file, file, storage).get();

    ASSERT_FALSE(res->errorsIsSet());

	//Get images from document
	auto result = api->getDocumentImages(_XPLATSTR("test3.html.zip"), folder, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("test_get_img_result.zip")));
}
TEST_F(TestDocumentApi, testGetHtmlImagesByUrl)
{

	//Get images from url
	auto result = api->getDocumentImagesByUrl(_XPLATSTR("https://www.google.com/")).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("test_get_img_url.zip")));
}

