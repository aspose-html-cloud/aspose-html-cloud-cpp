/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TestTranslationApi.cpp">
*  Copyright (c) 2018 Aspose.HTML for Cloud
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


#include "pch.h"
#include "TestBase.h"
#include "ApiConfiguration.h"
#include "api/TranslationApi.h"
#include "api/StorageApi.h"


using namespace com::aspose::api;

class TestTranslationApi : public TestBase
{
protected:

	void SetUp()
	{
		std::shared_ptr<ApiConfiguration> apiConfig(new ApiConfiguration(clientId, clientSecret, basePath, authPath));
		std::shared_ptr<ApiClient> apiClient(new ApiClient(apiConfig));
		api = new TranslationApi(apiClient);
		storage_api = new StorageApi(apiClient);
	}

	void TearDown()
	{
		delete api;
		delete storage_api;
	}

	TranslationApi *api;
	StorageApi *storage_api;
};

TEST_F(TestTranslationApi, getTranslateDocument)
{
	//Upload file for conversion to server
	utility::string_t path_to_file = _XPLATSTR("HtmlTestDoc/test_en.html");
	std::shared_ptr<HttpContent> file(new HttpContent());
	std::shared_ptr<std::ifstream> if_stream(new std::ifstream(testSource + _XPLATSTR("test_en.html"), std::ifstream::binary));
	file->setData(if_stream);
	boost::optional<utility::string_t> versionId = boost::none;
	boost::optional<utility::string_t> storage = boost::none;


	auto res = storage_api->putCreate(path_to_file, file, versionId, storage).get();

	ASSERT_TRUE(res->getCode() == 200);
	ASSERT_TRUE(res->getStatus() == _XPLATSTR("OK"));

	//Translate document
	utility::string_t name = _XPLATSTR("test_en.html");
	utility::string_t srcLang = _XPLATSTR("en");
	utility::string_t resLang = _XPLATSTR("de");
	boost::optional<utility::string_t> folder = _XPLATSTR("HtmlTestDoc");

	auto result = api->getTranslateDocument(name, srcLang, resLang, storage, folder).get();
	
	//Save result
	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("Translate_en_de.html")));
}

TEST_F(TestTranslationApi, getTranslateDocumentByUrl)
{
	utility::string_t source_url = _XPLATSTR("https://www.le.ac.uk/oerresources/bdra/html/page_02.htm");
	utility::string_t srcLang = _XPLATSTR("en"); 
	utility::string_t resLang = _XPLATSTR("fr");

	auto result = api->getTranslateDocumentByUrl(source_url, srcLang, resLang).get();

	//Save result
	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("TranslateUrl_en_fr.html")));

}


