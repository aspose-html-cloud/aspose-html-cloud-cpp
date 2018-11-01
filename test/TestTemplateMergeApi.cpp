/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TestTemplateMergeApi.cpp">
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
#include "api/TemplateMergeApi.h"
#include "api/StorageApi.h"

using namespace com::aspose::api;

class TestTemplateMergeApi : public TestBase
{
protected:

	void SetUp()
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
		utility::string_t path_to_template = _XPLATSTR("HtmlTestDoc/HtmlTemplate.html");
		std::shared_ptr<HttpContent> template_file(new HttpContent());
		std::shared_ptr<std::ifstream> if_stream(new std::ifstream(testSource + template_name, std::ifstream::binary));
		template_file->setData(if_stream);

		auto res = storage_api->putCreate(path_to_template, template_file, versionId, storage).get();

		ASSERT_TRUE(res->getCode() == 200);
		ASSERT_TRUE(res->getStatus() == _XPLATSTR("OK"));
        
		//Upload data file to server
		utility::string_t path_to_data = _XPLATSTR("HtmlTestDoc/XmlSourceData.xml");
		std::shared_ptr<HttpContent> data_file(new HttpContent());
		std::shared_ptr<std::ifstream> stream(new std::ifstream(testSource + data_name, std::ifstream::binary));
		data_file->setData(stream);

		res = storage_api->putCreate(path_to_data, data_file, versionId, storage).get();

		ASSERT_TRUE(res->getCode() == 200);
		ASSERT_TRUE(res->getStatus() == _XPLATSTR("OK"));
	}

	void TearDown()
	{
		delete api;
		delete storage_api;
	}

	TemplateMergeApi *api;
	StorageApi *storage_api;

	boost::optional<utility::string_t> storage;
	utility::string_t template_name;
	utility::string_t data_name;
	boost::optional<utility::string_t> versionId;
};



TEST_F(TestTemplateMergeApi, getMergeHtmlTemplate)
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

TEST_F(TestTemplateMergeApi, putMergeHtmlTemplate)
{
	//Prepare file stream to upload
	std::shared_ptr<HttpContent> file(new HttpContent());
	std::shared_ptr<std::ifstream> if_stream(new std::ifstream(testSource + _XPLATSTR("XmlSourceData.xml"), std::ifstream::binary));
	file->setData(if_stream);

	//Parameters
	utility::string_t templateName = _XPLATSTR("HtmlTemplate.html");
	utility::string_t outPath = _XPLATSTR("HtmlTestDoc/putTemplateResult.html");
	boost::optional<utility::string_t> options = _XPLATSTR("");
	boost::optional<utility::string_t> folder = _XPLATSTR("HtmlTestDoc");
	boost::optional<utility::string_t> storage = boost::none;

	auto result = api->putMergeHtmlTemplate(templateName, outPath, file, options, folder, storage).get();

	
	// Check exist file
	auto result_exist = storage_api->getIsExist(outPath, versionId, storage).get();

	ASSERT_TRUE(result_exist->getCode() == 200);
	ASSERT_TRUE(result_exist->getStatus() == _XPLATSTR("OK"));

	ASSERT_TRUE(result_exist->getFileExist()->isExist());
	ASSERT_FALSE(result_exist->getFileExist()->isFolder());

	// Download file from storage
	auto result_download = storage_api->getDownload(outPath, versionId, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result_download, testResult + _XPLATSTR("putTemplateMerhe.html")));

	//Clear file
	auto result_del = storage_api->deleteFile(outPath, versionId, storage).get();

	ASSERT_TRUE(result_del->getCode() == 200);
	ASSERT_TRUE(result_del->getStatus() == _XPLATSTR("OK"));

	// Check not exist file
	result_exist = storage_api->getIsExist(outPath, versionId, storage).get();

	ASSERT_TRUE(result_exist->getCode() == 200);
	ASSERT_TRUE(result_exist->getStatus() == _XPLATSTR("OK"));

	ASSERT_FALSE(result_exist->getFileExist()->isExist());
	ASSERT_FALSE(result_exist->getFileExist()->isFolder());
}
