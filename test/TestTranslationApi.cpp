/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TestTranslationApi.cpp">
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
#include "api/TranslationApi.h"
#include "api/StorageApi.h"
#include "TestBase.h"

using namespace com::aspose::api;

class TestTranslationApi : public TestBase
{

public:
    TranslationApi* api;
    StorageApi* storage_api;

protected:

    void SetUp()
	{
        try 
        {
            std::shared_ptr<ApiConfiguration> apiConfig(new ApiConfiguration(clientId, clientSecret, basePath, authPath));
            std::shared_ptr<ApiClient> apiClient(new ApiClient(apiConfig));
            api = new TranslationApi(apiClient);
            storage_api = new StorageApi(apiClient);
        }
        catch(std::exception& e)
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

TEST_F(TestTranslationApi, testGetTranslateDocument)
{
	//Upload file for conversion to server
    utility::string_t name = _XPLATSTR("test_en.html");
    std::shared_ptr<HttpContent> file(new HttpContent(testSource, name));

	utility::string_t path_to_file = _XPLATSTR("HtmlTestDoc/test_en.html");

    boost::optional<utility::string_t> versionId = boost::none;
	boost::optional<utility::string_t> storage = boost::none;

	auto res = storage_api->uploadFile(path_to_file, file, storage).get();

    ASSERT_FALSE(res->errorsIsSet()); 

	//Translate document
	utility::string_t srcLang = _XPLATSTR("en");
	utility::string_t resLang = _XPLATSTR("de");
	boost::optional<utility::string_t> folder = _XPLATSTR("HtmlTestDoc");

	auto result = api->getTranslateDocument(name, srcLang, resLang, storage, folder).get();
	
	//Save result
	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("Translate_en_de.html")));
}
TEST_F(TestTranslationApi, testGetTranslateDocumentByUrl)
{
	utility::string_t source_url = _XPLATSTR("https://www.le.ac.uk/oerresources/bdra/html/page_02.htm");
	utility::string_t srcLang = _XPLATSTR("en"); 
	utility::string_t resLang = _XPLATSTR("fr");

	auto result = api->getTranslateDocumentByUrl(source_url, srcLang, resLang).get();

	//Save result
	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("TranslateUrl_en_fr.html")));

}
