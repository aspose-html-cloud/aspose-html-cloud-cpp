/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TestEpubConversionApi.cpp">
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

class TestEpubConversionApi : public TestBase
{

public:
    ConversionApi* api;
    StorageApi* storage_api;

    boost::optional<utility::string_t> folder;
    boost::optional<utility::string_t> storage;
    utility::string_t name;
    boost::optional<utility::string_t> versionId;

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


		folder = _XPLATSTR("HtmlTestDoc");
		storage = boost::none;
		name = _XPLATSTR("georgia.epub");
		versionId = _XPLATSTR("");

		width = 800;
		height = 1000;
		leftMargin = 50;
		rightMargin = 50;
		topMargin = 100;
		bottomMargin = 100;
		resolution = 300;

		//Upload file for conversion to server
		utility::string_t path_to_file = _XPLATSTR("HtmlTestDoc/georgia.epub");
		std::shared_ptr<HttpContent> file(new HttpContent());
		std::shared_ptr<std::ifstream> if_stream(new std::ifstream(testSource + _XPLATSTR("georgia.epub"), std::ifstream::binary));
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


// Convert epub document

TEST_F(TestEpubConversionApi, ConvertEpubToJpeg)
{
	//Convert to jpeg
	auto result = api->getConvertDocumentToImage(name, _XPLATSTR("jpeg"), 
		width, height, leftMargin, rightMargin, topMargin, bottomMargin, resolution, folder, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertEpubToJpg.jpg")));
}

TEST_F(TestEpubConversionApi, ConvertEpubToPng)
{
	//Convert to png
	auto result = api->getConvertDocumentToImage(name, _XPLATSTR("png"),
		width, height, leftMargin, rightMargin, topMargin, bottomMargin, resolution, folder, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertEpubToPng.png")));
}

TEST_F(TestEpubConversionApi, ConvertEpubToBmp)
{
	//Convert to bmp
	auto result = api->getConvertDocumentToImage(name, _XPLATSTR("bmp"),
		width, height, leftMargin, rightMargin, topMargin, bottomMargin, resolution, folder, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertEpubToBmp.bmp")));
}

TEST_F(TestEpubConversionApi, ConvertEpubToTiff)
{
	//Convert to tiff
	auto result = api->getConvertDocumentToImage(name, _XPLATSTR("tiff"),
		width, height, leftMargin, rightMargin, topMargin, bottomMargin, resolution, folder, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertEpubToTiff.tiff")));
}

TEST_F(TestEpubConversionApi, ConvertEpubToPdf)
{
	//Convert to pdf
	auto result = api->getConvertDocumentToPdf(name, width, height, leftMargin, rightMargin, topMargin, bottomMargin, folder, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertEpubToPdf.pdf")));
}

TEST_F(TestEpubConversionApi, ConvertEpubToXps)
{
	//Convert to xps
	auto result = api->getConvertDocumentToXps(name, width, height, leftMargin, rightMargin, topMargin, bottomMargin, folder, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertEpubToXps.xps")));
}


TEST_F(TestEpubConversionApi, putConvertEpubInRequestToImage)
{
	//Prepare file stream to upload
	std::shared_ptr<HttpContent> file(new HttpContent());
	std::shared_ptr<std::ifstream> if_stream(new std::ifstream(testSource + _XPLATSTR("georgia.epub"), std::ifstream::binary));
	file->setData(if_stream);

	//Parameters
	utility::string_t outPath = _XPLATSTR("HtmlTestDoc/putConvertEpubInRequestToImage.jpg");
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

	ASSERT_TRUE(TestBase::save_to_file(result_download, testResult + _XPLATSTR("putConvertEpubInRequestToImage.jpg")));

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

TEST_F(TestEpubConversionApi, putConvertEpubInRequestToPdf)
{
	//Prepare file stream to upload
	std::shared_ptr<HttpContent> file(new HttpContent());
	std::shared_ptr<std::ifstream> if_stream(new std::ifstream(testSource + _XPLATSTR("georgia.epub"), std::ifstream::binary));
	file->setData(if_stream);

	//Parameters
	utility::string_t outPath = _XPLATSTR("HtmlTestDoc/putConvertEpubInRequestToPdf.pdf");

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

	ASSERT_TRUE(TestBase::save_to_file(result_download, testResult + _XPLATSTR("putConvertEpubInRequestToPdf.pdf")));

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

TEST_F(TestEpubConversionApi, putConvertEpubInRequestToXps)
{
	//Prepare file stream to upload
	std::shared_ptr<HttpContent> file(new HttpContent());
	std::shared_ptr<std::ifstream> if_stream(new std::ifstream(testSource + _XPLATSTR("georgia.epub"), std::ifstream::binary));
	file->setData(if_stream);

	//Parameters
	utility::string_t outPath = _XPLATSTR("HtmlTestDoc/putConvertEpubInRequestToXps.xps");

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

	ASSERT_TRUE(TestBase::save_to_file(result_download, testResult + _XPLATSTR("putConvertEpubInRequestToXps.xps")));

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

TEST_F(TestEpubConversionApi, putConvertEpubToImage)
{
	//Parameters
	utility::string_t outPath = _XPLATSTR("HtmlTestDoc/putConvertEpubToImage.png");
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

	ASSERT_TRUE(TestBase::save_to_file(result_download, testResult + _XPLATSTR("putConvertEpubToImage.png")));

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

TEST_F(TestEpubConversionApi, putConvertEpubToPdf)
{
	//Parameters
	utility::string_t outPath = _XPLATSTR("HtmlTestDoc/putConvertEpubToPdf.pdf");

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

	ASSERT_TRUE(TestBase::save_to_file(result_download, testResult + _XPLATSTR("putConvertEpubToPdf.pdf")));

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

TEST_F(TestEpubConversionApi, putConvertEpubToXps)
{
	//Parameters
	utility::string_t outPath = _XPLATSTR("HtmlTestDoc/putConvertEpubToXps.xps");

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

	ASSERT_TRUE(TestBase::save_to_file(result_download, testResult + _XPLATSTR("putConvertEpubToXps.xps")));

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