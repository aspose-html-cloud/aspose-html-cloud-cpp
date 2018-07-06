/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TestConversionApi.cpp">
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
#include "api/ConversionApi.h"
#include "api/StorageApi.h"

using namespace com::aspose::api;

class TestConversionApi : public TestBase
{
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

	ConversionApi *api;
	StorageApi *storage_api;

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
};

// Convert document

TEST_F(TestConversionApi, ConvertDocToJpeg)
{
	//Convert to jpeg
	auto result = api->getConvertDocumentToImage(name, _XPLATSTR("jpeg"), 
		width, height, leftMargin, rightMargin, topMargin, bottomMargin, resolution, folder, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertDocToJpg.jpg")));
}

TEST_F(TestConversionApi, ConvertDocToPng)
{
	//Convert to png
	auto result = api->getConvertDocumentToImage(name, _XPLATSTR("png"),
		width, height, leftMargin, rightMargin, topMargin, bottomMargin, resolution, folder, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertDocToPng.png")));
}

TEST_F(TestConversionApi, ConvertDocToBmp)
{
	//Convert to bmp
	auto result = api->getConvertDocumentToImage(name, _XPLATSTR("bmp"),
		width, height, leftMargin, rightMargin, topMargin, bottomMargin, resolution, folder, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertDocToBmp.bmp")));
}

TEST_F(TestConversionApi, ConvertDocToTiff)
{
	//Convert to tiff
	auto result = api->getConvertDocumentToImage(name, _XPLATSTR("tiff"),
		width, height, leftMargin, rightMargin, topMargin, bottomMargin, resolution, folder, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertDocToTiff.tiff")));
}

TEST_F(TestConversionApi, ConvertDocToPdf)
{
	//Convert to pdf
	auto result = api->getConvertDocumentToPdf(name, width, height, leftMargin, rightMargin, topMargin, bottomMargin, folder, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertDocToPdf.pdf")));
}

TEST_F(TestConversionApi, ConvertDocToXps)
{
	//Convert to xps
	auto result = api->getConvertDocumentToXps(name, width, height, leftMargin, rightMargin, topMargin, bottomMargin, folder, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertDocToXps.xps")));
}

//Convert URL

TEST_F(TestConversionApi, ConvertUrlToJpeg)
{
	//Convert to jpeg
	auto result = api->getConvertDocumentToImageByUrl(sourceUrl, _XPLATSTR("jpeg"),
		width, height, leftMargin, rightMargin, topMargin, bottomMargin, resolution).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertUrlToJpg.jpg")));
}

TEST_F(TestConversionApi, ConvertUrlToPng)
{
	//Convert to png
	auto result = api->getConvertDocumentToImageByUrl(sourceUrl, _XPLATSTR("png"),
		width, height, leftMargin, rightMargin, topMargin, bottomMargin, resolution).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertUrlToPng.png")));
}

TEST_F(TestConversionApi, ConvertUrlToBmp)
{
	//Convert to bmp
	auto result = api->getConvertDocumentToImageByUrl(sourceUrl, _XPLATSTR("bmp"),
		width, height, leftMargin, rightMargin, topMargin, bottomMargin, resolution).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertUrlToBmp.bmp")));
}

TEST_F(TestConversionApi, ConvertUrlToTiff)
{
	//Convert to tiff
	auto result = api->getConvertDocumentToImageByUrl(sourceUrl, _XPLATSTR("tiff"),
		width, height, leftMargin, rightMargin, topMargin, bottomMargin, resolution).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertUrlToTiff.tiff")));
}

TEST_F(TestConversionApi, ConvertUrlToPdf)
{
	//Convert to pdf
	auto result = api->getConvertDocumentToPdfByUrl(sourceUrl, width, height, leftMargin, rightMargin, topMargin, bottomMargin).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertUrlToPdf.pdf")));
}

TEST_F(TestConversionApi, ConvertUrlToXps)
{
	//Convert to xps
	auto result = api->getConvertDocumentToXpsByUrl(sourceUrl, width, height, leftMargin, rightMargin, topMargin, bottomMargin).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertUrlToXps.xps")));
}
