/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TestHtmlConversionApi.cpp">
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

#include "ApiConfiguration.h"
#include "api/ConversionApi.h"
#include "api/StorageApi.h"
#include "TestBase.h"

using namespace com::aspose::api;

class TestHtmlConversionApi : public TestBase
{

public:
    ConversionApi* api;
    StorageApi* storage_api;

    boost::optional<utility::string_t> folder;
    boost::optional<utility::string_t> storage;
    utility::string_t name;
    boost::optional<utility::string_t> versionId;

    utility::string_t sourceUrl;
    boost::optional<int32_t> width;
    boost::optional<int32_t> height;
    boost::optional<int32_t> leftMargin;
    boost::optional<int32_t> rightMargin;
    boost::optional<int32_t> topMargin;
    boost::optional<int32_t> bottomMargin;
    boost::optional<int32_t> resolution;

protected:

    void SetUp()
	{
		std::shared_ptr<ApiConfiguration> apiConfig(new ApiConfiguration(clientId, clientSecret, basePath, authPath));
		std::shared_ptr<ApiClient> apiClient(new ApiClient(apiConfig));
		api = new ConversionApi(apiClient);
		storage_api = new StorageApi(apiClient);


		sourceUrl = _XPLATSTR("https://stallman.org/articles/anonymous-payments-thru-phones.html");
		folder = _XPLATSTR("HtmlTestDoc");
		storage = boost::none;
		name = _XPLATSTR("test1.html");
		versionId = _XPLATSTR("");

		width = 800;
		height = 1000;
		leftMargin = 50;
		rightMargin = 50;
		topMargin = 100;
		bottomMargin = 100;
		resolution = 300;

		//Upload file for conversion to server
		utility::string_t path_to_file = _XPLATSTR("HtmlTestDoc/test1.html");
		std::shared_ptr<HttpContent> file(new HttpContent());
		std::shared_ptr<std::ifstream> if_stream(new std::ifstream(testSource + _XPLATSTR("test1.html"), std::ifstream::binary));
		file->setData(if_stream);

		auto res = storage_api->putCreate(path_to_file, file, versionId, storage).get();

		ASSERT_TRUE(res->getCode() == 200);
		ASSERT_TRUE(res->getStatus() == _XPLATSTR("OK"));
	}

    void TearDown()
	{
		delete api;
		delete storage_api;
	}


};


// Convert html document

TEST_F(TestHtmlConversionApi, ConvertDocToJpeg)
{
	//Convert to jpeg
	auto result = api->getConvertDocumentToImage(name, _XPLATSTR("jpeg"), 
		width, height, leftMargin, rightMargin, topMargin, bottomMargin, resolution, folder, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertHtmlToJpg.jpg")));
}

TEST_F(TestHtmlConversionApi, ConvertDocToPng)
{
	//Convert to png
	auto result = api->getConvertDocumentToImage(name, _XPLATSTR("png"),
		width, height, leftMargin, rightMargin, topMargin, bottomMargin, resolution, folder, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertHtmlToPng.png")));
}

TEST_F(TestHtmlConversionApi, ConvertDocToBmp)
{
	//Convert to bmp
	auto result = api->getConvertDocumentToImage(name, _XPLATSTR("bmp"),
		width, height, leftMargin, rightMargin, topMargin, bottomMargin, resolution, folder, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertHtmlToBmp.bmp")));
}

TEST_F(TestHtmlConversionApi, ConvertDocToTiff)
{
	//Convert to tiff
	auto result = api->getConvertDocumentToImage(name, _XPLATSTR("tiff"),
		width, height, leftMargin, rightMargin, topMargin, bottomMargin, resolution, folder, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertHtmlToTiff.tiff")));
}

TEST_F(TestHtmlConversionApi, ConvertDocToPdf)
{
	//Convert to pdf
	auto result = api->getConvertDocumentToPdf(name, width, height, leftMargin, rightMargin, topMargin, bottomMargin, folder, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertHtmlToPdf.pdf")));
}

TEST_F(TestHtmlConversionApi, ConvertDocToXps)
{
	//Convert to xps
	auto result = api->getConvertDocumentToXps(name, width, height, leftMargin, rightMargin, topMargin, bottomMargin, folder, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertHtmlToXps.xps")));
}

//Convert URL

TEST_F(TestHtmlConversionApi, ConvertUrlToJpeg)
{
	//Convert to jpeg
	auto result = api->getConvertDocumentToImageByUrl(sourceUrl, _XPLATSTR("jpeg"),
		width, height, leftMargin, rightMargin, topMargin, bottomMargin, resolution).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertUrlToJpg.jpg")));
}

TEST_F(TestHtmlConversionApi, ConvertUrlToPng)
{
	//Convert to png
	auto result = api->getConvertDocumentToImageByUrl(sourceUrl, _XPLATSTR("png"),
		width, height, leftMargin, rightMargin, topMargin, bottomMargin, resolution).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertUrlToPng.png")));
}

TEST_F(TestHtmlConversionApi, ConvertUrlToBmp)
{
	//Convert to bmp
	auto result = api->getConvertDocumentToImageByUrl(sourceUrl, _XPLATSTR("bmp"),
		width, height, leftMargin, rightMargin, topMargin, bottomMargin, resolution).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertUrlToBmp.bmp")));
}

TEST_F(TestHtmlConversionApi, ConvertUrlToTiff)
{
	//Convert to tiff
	auto result = api->getConvertDocumentToImageByUrl(sourceUrl, _XPLATSTR("tiff"),
		width, height, leftMargin, rightMargin, topMargin, bottomMargin, resolution).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertUrlToTiff.tiff")));
}

TEST_F(TestHtmlConversionApi, ConvertUrlToPdf)
{
	//Convert to pdf
	auto result = api->getConvertDocumentToPdfByUrl(sourceUrl, width, height, leftMargin, rightMargin, topMargin, bottomMargin).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertUrlToPdf.pdf")));
}

TEST_F(TestHtmlConversionApi, ConvertUrlToXps)
{
	//Convert to xps
	auto result = api->getConvertDocumentToXpsByUrl(sourceUrl, width, height, leftMargin, rightMargin, topMargin, bottomMargin).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertUrlToXps.xps")));
}

TEST_F(TestHtmlConversionApi, putConvertDocumentInRequestToImage)
{
	//Prepare file stream to upload
	std::shared_ptr<HttpContent> file(new HttpContent());
	std::shared_ptr<std::ifstream> if_stream(new std::ifstream(testSource + _XPLATSTR("test1.html"), std::ifstream::binary));
	file->setData(if_stream);

	//Parameters
	utility::string_t outPath = _XPLATSTR("HtmlTestDoc/putConvertHtmlInRequestToImage.jpg");
	utility::string_t outFormat = _XPLATSTR("jpeg");

	//Convert to jpeg and save to storage
	auto result = api->putConvertDocumentInRequestToImage(outPath, outFormat, file, width, 
		height, leftMargin, rightMargin, topMargin, bottomMargin, resolution).get();

	// Check exist file
	auto result_exist = storage_api->getIsExist(outPath, versionId, storage).get();

	ASSERT_TRUE(result_exist->getCode() == 200);
	ASSERT_TRUE(result_exist->getStatus() == _XPLATSTR("OK"));

	ASSERT_TRUE(result_exist->getFileExist()->isExist());
	ASSERT_FALSE(result_exist->getFileExist()->isFolder());

	// Download file from storage
	auto result_download = storage_api->getDownload(outPath, versionId, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result_download, testResult + _XPLATSTR("putConvertHtmlInRequestToImage.jpg")));

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

TEST_F(TestHtmlConversionApi, putConvertDocumentInRequestToPdf)
{
	//Prepare file stream to upload
	std::shared_ptr<HttpContent> file(new HttpContent());
	std::shared_ptr<std::ifstream> if_stream(new std::ifstream(testSource + _XPLATSTR("test1.html"), std::ifstream::binary));
	file->setData(if_stream);

	//Parameters
	utility::string_t outPath = _XPLATSTR("HtmlTestDoc/putConvertHtmlInRequestToPdf.pdf");

	//Convert to pdf and save to storage
	auto result = api->putConvertDocumentInRequestToPdf(outPath, file, width, height, leftMargin, rightMargin, 
		topMargin, bottomMargin).get();

	// Check exist file
	auto result_exist = storage_api->getIsExist(outPath, versionId, storage).get();

	ASSERT_TRUE(result_exist->getCode() == 200);
	ASSERT_TRUE(result_exist->getStatus() == _XPLATSTR("OK"));

	ASSERT_TRUE(result_exist->getFileExist()->isExist());
	ASSERT_FALSE(result_exist->getFileExist()->isFolder());

	// Download file from storage
	auto result_download = storage_api->getDownload(outPath, versionId, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result_download, testResult + _XPLATSTR("putConvertHtmlInRequestToPdf.pdf")));

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

TEST_F(TestHtmlConversionApi, putConvertDocumentInRequestToXps)
{
	//Prepare file stream to upload
	std::shared_ptr<HttpContent> file(new HttpContent());
	std::shared_ptr<std::ifstream> if_stream(new std::ifstream(testSource + _XPLATSTR("test1.html"), std::ifstream::binary));
	file->setData(if_stream);

	//Parameters
	utility::string_t outPath = _XPLATSTR("HtmlTestDoc/putConvertHtmlInRequestToXps.xps");

	//Convert to xps and save to storage
	auto result = api->putConvertDocumentInRequestToXps(outPath, file, width, height, leftMargin, rightMargin,
		topMargin, bottomMargin).get();

	// Check exist file
	auto result_exist = storage_api->getIsExist(outPath, versionId, storage).get();

	ASSERT_TRUE(result_exist->getCode() == 200);
	ASSERT_TRUE(result_exist->getStatus() == _XPLATSTR("OK"));

	ASSERT_TRUE(result_exist->getFileExist()->isExist());
	ASSERT_FALSE(result_exist->getFileExist()->isFolder());

	// Download file from storage
	auto result_download = storage_api->getDownload(outPath, versionId, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result_download, testResult + _XPLATSTR("putConvertHtmlInRequestToXps.xps")));

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

TEST_F(TestHtmlConversionApi, putConvertDocumentToImage)
{
	//Parameters
	utility::string_t outPath = _XPLATSTR("HtmlTestDoc/putConvertHtmlToImage.png");
	utility::string_t outFormat = _XPLATSTR("png");

	auto result = api->putConvertDocumentToImage(name, outPath, outFormat, width, height, leftMargin, rightMargin, topMargin,
			bottomMargin, resolution, folder, storage).get();

	// Check exist file
	auto result_exist = storage_api->getIsExist(outPath, versionId, storage).get();

	ASSERT_TRUE(result_exist->getCode() == 200);
	ASSERT_TRUE(result_exist->getStatus() == _XPLATSTR("OK"));

	ASSERT_TRUE(result_exist->getFileExist()->isExist());
	ASSERT_FALSE(result_exist->getFileExist()->isFolder());

	// Download file from storage
	auto result_download = storage_api->getDownload(outPath, versionId, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result_download, testResult + _XPLATSTR("putConvertHtmlToImage.png")));

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

TEST_F(TestHtmlConversionApi, putConvertDocumentToPdf)
{
	//Parameters
	utility::string_t outPath = _XPLATSTR("HtmlTestDoc/putConvertHtmlToPdf.pdf");

	//Convert to pdf and save to storage
	auto result = api->putConvertDocumentToPdf(name, outPath, width, height, leftMargin, rightMargin, 
		topMargin, bottomMargin, folder, storage).get();

	// Check exist file
	auto result_exist = storage_api->getIsExist(outPath, versionId, storage).get();

	ASSERT_TRUE(result_exist->getCode() == 200);
	ASSERT_TRUE(result_exist->getStatus() == _XPLATSTR("OK"));

	ASSERT_TRUE(result_exist->getFileExist()->isExist());
	ASSERT_FALSE(result_exist->getFileExist()->isFolder());

	// Download file from storage
	auto result_download = storage_api->getDownload(outPath, versionId, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result_download, testResult + _XPLATSTR("putConvertHtmlToPdf.pdf")));

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

TEST_F(TestHtmlConversionApi, putConvertDocumentToXps)
{
	//Parameters
	utility::string_t outPath = _XPLATSTR("HtmlTestDoc/putConvertHtmlToXps.xps");

	//Convert to xps and save to storage
	auto result = api->putConvertDocumentToXps(name, outPath, width, height, 
		leftMargin, rightMargin, topMargin, bottomMargin, folder, storage).get();

	// Check exist file
	auto result_exist = storage_api->getIsExist(outPath, versionId, storage).get();

	ASSERT_TRUE(result_exist->getCode() == 200);
	ASSERT_TRUE(result_exist->getStatus() == _XPLATSTR("OK"));

	ASSERT_TRUE(result_exist->getFileExist()->isExist());
	ASSERT_FALSE(result_exist->getFileExist()->isFolder());

	// Download file from storage
	auto result_download = storage_api->getDownload(outPath, versionId, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result_download, testResult + _XPLATSTR("putConvertHtmlToXps.xps")));

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

TEST_F(TestHtmlConversionApi, getConvertDocumentToMHTMLByUrlTest)
{

	utility::string_t sourceUrl = _XPLATSTR("https://www.yahoo.com");
	//Convert to mhtml
	auto result = api->getConvertDocumentToMHTMLByUrl(sourceUrl).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertUrlToMhtml.mht")));
}

TEST_F(TestHtmlConversionApi, getConvertDocumentToMarkdown)
{
	//Upload document to storage
	utility::string_t path_to_file = _XPLATSTR("HtmlTestDoc/test_md.html");
	std::shared_ptr<HttpContent> file(new HttpContent());
	std::shared_ptr<std::ifstream> if_stream(new std::ifstream(testSource + _XPLATSTR("test_md.html"), std::ifstream::binary));
	file->setData(if_stream);
	boost::optional<utility::string_t> versionId = boost::none;
	boost::optional<utility::string_t> storage = boost::none;
	boost::optional<utility::string_t> folder = _XPLATSTR("HtmlTestDoc");

	auto res = storage_api->putCreate(path_to_file, file, versionId, storage).get();

	ASSERT_TRUE(res->getCode() == 200);
	ASSERT_TRUE(res->getStatus() == _XPLATSTR("OK"));

	// Get convert html to markdown format
	utility::string_t name = _XPLATSTR("test_md.html");
	boost::optional<bool> useGit = true;
	
	auto result = api->getConvertDocumentToMarkdown(name, useGit, folder, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("test_get_to_markdown.md")));

	//Clear test file in the storage
	auto result_del = storage_api->deleteFile(path_to_file, versionId, storage).get();

	ASSERT_TRUE(result_del->getCode() == 200);
	ASSERT_TRUE(result_del->getStatus() == _XPLATSTR("OK"));
}

TEST_F(TestHtmlConversionApi, putConvertDocumentToMarkdown)
{
	//Upload document to storage
	utility::string_t path_to_file = _XPLATSTR("HtmlTestDoc/test_md.html");
	std::shared_ptr<HttpContent> file(new HttpContent());
	std::shared_ptr<std::ifstream> if_stream(new std::ifstream(testSource + _XPLATSTR("test_md.html"), std::ifstream::binary));
	file->setData(if_stream);
	boost::optional<utility::string_t> versionId = boost::none;
	boost::optional<utility::string_t> storage = boost::none;
	boost::optional<utility::string_t> folder = _XPLATSTR("HtmlTestDoc");

	auto res = storage_api->putCreate(path_to_file, file, versionId, storage).get();

	ASSERT_TRUE(res->getCode() == 200);
	ASSERT_TRUE(res->getStatus() == _XPLATSTR("OK"));

	// Put convert html to markdown format
	utility::string_t name = _XPLATSTR("test_md.html");
	utility::string_t outPath = _XPLATSTR("HtmlTestDoc/test_put_to_markdown.md");
	boost::optional<bool> useGit = false;

	api->putConvertDocumentToMarkdown(name, outPath, useGit, folder, storage).get();

	//Clear test file in the storage
	auto result_del_test = storage_api->deleteFile(path_to_file, versionId, storage).get();

	ASSERT_TRUE(result_del_test->getCode() == 200);
	ASSERT_TRUE(result_del_test->getStatus() == _XPLATSTR("OK"));

	// Download file from storage
	auto result_download = storage_api->getDownload(outPath, versionId, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result_download, testResult + _XPLATSTR("test_put_to_markdown.md")));

	//Clear result file
	auto result_del = storage_api->deleteFile(outPath, versionId, storage).get();

	ASSERT_TRUE(result_del->getCode() == 200);
	ASSERT_TRUE(result_del->getStatus() == _XPLATSTR("OK"));
}

