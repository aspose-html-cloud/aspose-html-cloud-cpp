/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TestSvgConversionApi.cpp">
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
#include "api/ConversionApi.h"
#include "api/StorageApi.h"
#include "TestBase.h"

using namespace com::aspose::api;

class TestSvgConversionApi : public TestBase
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
        try 
        {
            std::shared_ptr<ApiConfiguration> apiConfig(new ApiConfiguration(clientId, clientSecret, basePath, authPath));
            std::shared_ptr<ApiClient> apiClient(new ApiClient(apiConfig));
            api = new ConversionApi(apiClient);
            storage_api = new StorageApi(apiClient);


            folder = _XPLATSTR("HtmlTestDoc");
            storage = boost::none;
            name = _XPLATSTR("Map-World.svg");
            versionId = _XPLATSTR("");

            width = 800;
            height = 1000;
            leftMargin = 50;
            rightMargin = 50;
            topMargin = 100;
            bottomMargin = 100;
            resolution = 300;

            //Upload file for conversion to server
            utility::string_t name = _XPLATSTR("Map-World.svg");
            std::shared_ptr<HttpContent> file(new HttpContent(testSource, name));

            utility::string_t path_to_file = _XPLATSTR("HtmlTestDoc/Map-World.svg");

            auto res = storage_api->uploadFile(path_to_file, file, storage).get();

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

// Convert svg document
TEST_F(TestSvgConversionApi, testGetSvgToJpeg)
{
	//Convert to jpeg
	auto result = api->getConvertDocumentToImage(name, _XPLATSTR("jpeg"), width, height, leftMargin, 
        rightMargin, topMargin, bottomMargin, resolution, folder, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertSvgToJpg.jpg")));
}
TEST_F(TestSvgConversionApi, testGetSvgToPng)
{
	//Convert to png
	auto result = api->getConvertDocumentToImage(name, _XPLATSTR("png"), width, height, leftMargin, 
        rightMargin, topMargin, bottomMargin, resolution, folder, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertSvgToPng.png")));
}
TEST_F(TestSvgConversionApi, testGetSvgToBmp)
{
	//Convert to bmp
	auto result = api->getConvertDocumentToImage(name, _XPLATSTR("bmp"), width, height, leftMargin, 
        rightMargin, topMargin, bottomMargin, resolution, folder, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertSvgToBmp.bmp")));
}
TEST_F(TestSvgConversionApi, testGetSvgToTiff)
{
	//Convert to tiff
	auto result = api->getConvertDocumentToImage(name, _XPLATSTR("tiff"), width, height, leftMargin, 
        rightMargin, topMargin, bottomMargin, resolution, folder, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertSvgToTiff.tiff")));
}
TEST_F(TestSvgConversionApi, testGetSvgToPdf)
{
	//Convert to pdf
	auto result = api->getConvertDocumentToPdf(name, width, height, leftMargin, rightMargin,
        topMargin, bottomMargin, folder, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertSvgToPdf.pdf")));
}
TEST_F(TestSvgConversionApi, testGetSvgToXps)
{
	//Convert to xps
	auto result = api->getConvertDocumentToXps(name, width, height, leftMargin, 
        rightMargin, topMargin, bottomMargin, folder, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertSvgToXps.xps")));
}
TEST_F(TestSvgConversionApi, testPostSvgInRequestToImage)
{
	//Prepare file stream to upload
    utility::string_t name = _XPLATSTR("Map-World.svg");
    std::shared_ptr<HttpContent> file(new HttpContent(testSource, name));

	//Parameters
	utility::string_t outPath = _XPLATSTR("HtmlTestDoc/postConvertSvgInRequestToImage.jpg");
	utility::string_t outFormat = _XPLATSTR("jpeg");

	//Convert to jpeg and save to storage
	auto result = api->postConvertDocumentInRequestToImage(outPath, outFormat, file, width, 
		height, leftMargin, rightMargin, topMargin, bottomMargin, resolution, storage).get();

	// Check exist file
	auto result_exist = storage_api->objectExists(outPath, versionId, storage).get();

	ASSERT_TRUE(result_exist->isExists());
	ASSERT_FALSE(result_exist->isFolder());

	// Download file from storage
	auto result_download = storage_api->downloadFile(outPath, versionId, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result_download, testResult + _XPLATSTR("postConvertSvgInRequestToImage.jpg")));

	//Clear file
	auto result_del = storage_api->deleteFile(outPath, versionId, storage).get();

	ASSERT_TRUE(result_del->getCode() == 200);
	ASSERT_TRUE(result_del->getStatus() == _XPLATSTR("OK"));

	// Check not exist file
	result_exist = storage_api->objectExists(outPath, versionId, storage).get();

	ASSERT_FALSE(result_exist->isExists());
	ASSERT_FALSE(result_exist->isFolder());
}
TEST_F(TestSvgConversionApi, testPostSvgInRequestToPdf)
{
	//Prepare file stream to upload
    utility::string_t name = _XPLATSTR("Map-World.svg");
    std::shared_ptr<HttpContent> file(new HttpContent(testSource, name));

	//Parameters
	utility::string_t outPath = _XPLATSTR("HtmlTestDoc/postConvertSvgInRequestToPdf.pdf");

	//Convert to pdf and save to storage
	auto result = api->postConvertDocumentInRequestToPdf(outPath, file, width, height, leftMargin, 
        rightMargin, topMargin, bottomMargin, storage).get();

	// Check exist file
	auto result_exist = storage_api->objectExists(outPath, versionId, storage).get();

	ASSERT_TRUE(result_exist->isExists());
	ASSERT_FALSE(result_exist->isFolder());

	// Download file from storage
	auto result_download = storage_api->downloadFile(outPath, versionId, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result_download, testResult + _XPLATSTR("postConvertSvgInRequestToPdf.pdf")));

	//Clear file
	auto result_del = storage_api->deleteFile(outPath, versionId, storage).get();

	ASSERT_TRUE(result_del->getCode() == 200);
	ASSERT_TRUE(result_del->getStatus() == _XPLATSTR("OK"));

	// Check not exist file
	result_exist = storage_api->objectExists(outPath, versionId, storage).get();

	ASSERT_FALSE(result_exist->isExists());
	ASSERT_FALSE(result_exist->isFolder());
}
TEST_F(TestSvgConversionApi, testPostSvgInRequestToXps)
{
	//Prepare file stream to upload
    utility::string_t name = _XPLATSTR("Map-World.svg");
    std::shared_ptr<HttpContent> file(new HttpContent(testSource, name));

	//Parameters
	utility::string_t outPath = _XPLATSTR("HtmlTestDoc/postConvertSvgInRequestToXps.xps");

	//Convert to xps and save to storage
	auto result = api->postConvertDocumentInRequestToXps(outPath, file, width, height, 
        leftMargin, rightMargin, topMargin, bottomMargin, storage).get();

	// Check exist file
	auto result_exist = storage_api->objectExists(outPath, versionId, storage).get();

	ASSERT_TRUE(result_exist->isExists());
	ASSERT_FALSE(result_exist->isFolder());

	// Download file from storage
	auto result_download = storage_api->downloadFile(outPath, versionId, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result_download, testResult + _XPLATSTR("postConvertSvgInRequestToXps.xps")));

	//Clear file
	auto result_del = storage_api->deleteFile(outPath, versionId, storage).get();

	ASSERT_TRUE(result_del->getCode() == 200);
	ASSERT_TRUE(result_del->getStatus() == _XPLATSTR("OK"));

	// Check not exist file
	result_exist = storage_api->objectExists(outPath, versionId, storage).get();

	ASSERT_FALSE(result_exist->isExists());
	ASSERT_FALSE(result_exist->isFolder());
}
TEST_F(TestSvgConversionApi, testPutSvgToImage)
{
	//Parameters
	utility::string_t outPath = _XPLATSTR("HtmlTestDoc/putConvertSvgToImage.png");
	utility::string_t outFormat = _XPLATSTR("png");

	auto result = api->putConvertDocumentToImage(name, outPath, outFormat, width, height, leftMargin, 
        rightMargin, topMargin,	bottomMargin, resolution, folder, storage).get();

	// Check exist file
	auto result_exist = storage_api->objectExists(outPath, versionId, storage).get();

	ASSERT_TRUE(result_exist->isExists());
	ASSERT_FALSE(result_exist->isFolder());

	// Download file from storage
	auto result_download = storage_api->downloadFile(outPath, versionId, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result_download, testResult + _XPLATSTR("putConvertSvgToImage.png")));

	//Clear file
	auto result_del = storage_api->deleteFile(outPath, versionId, storage).get();

	ASSERT_TRUE(result_del->getCode() == 200);
	ASSERT_TRUE(result_del->getStatus() == _XPLATSTR("OK"));

	// Check not exist file
	result_exist = storage_api->objectExists(outPath, versionId, storage).get();

	ASSERT_FALSE(result_exist->isExists());
	ASSERT_FALSE(result_exist->isFolder());
}
TEST_F(TestSvgConversionApi, testPutSvgToPdf)
{
	//Parameters
	utility::string_t outPath = _XPLATSTR("HtmlTestDoc/putConvertSvgToPdf.pdf");

	//Convert to pdf and save to storage
	auto result = api->putConvertDocumentToPdf(name, outPath, width, height, leftMargin, rightMargin, 
		topMargin, bottomMargin, folder, storage).get();

	// Check exist file
	auto result_exist = storage_api->objectExists(outPath, versionId, storage).get();

	ASSERT_TRUE(result_exist->isExists());
	ASSERT_FALSE(result_exist->isFolder());

	// Download file from storage
	auto result_download = storage_api->downloadFile(outPath, versionId, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result_download, testResult + _XPLATSTR("putConvertSvgToPdf.pdf")));

	//Clear file
	auto result_del = storage_api->deleteFile(outPath, versionId, storage).get();

	ASSERT_TRUE(result_del->getCode() == 200);
	ASSERT_TRUE(result_del->getStatus() == _XPLATSTR("OK"));

	// Check not exist file
	result_exist = storage_api->objectExists(outPath, versionId, storage).get();

	ASSERT_FALSE(result_exist->isExists());
	ASSERT_FALSE(result_exist->isFolder());
}
TEST_F(TestSvgConversionApi, testPutSvgToXps)
{
	//Parameters
	utility::string_t outPath = _XPLATSTR("HtmlTestDoc/putConvertSvgToXps.xps");

	//Convert to xps and save to storage
	auto result = api->putConvertDocumentToXps(name, outPath, width, height, 
		leftMargin, rightMargin, topMargin, bottomMargin, folder, storage).get();

	// Check exist file
	auto result_exist = storage_api->objectExists(outPath, versionId, storage).get();

	ASSERT_TRUE(result_exist->isExists());
	ASSERT_FALSE(result_exist->isFolder());

	// Download file from storage
	auto result_download = storage_api->downloadFile(outPath, versionId, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result_download, testResult + _XPLATSTR("putConvertSvgToXps.xps")));

	//Clear file
	auto result_del = storage_api->deleteFile(outPath, versionId, storage).get();

	ASSERT_TRUE(result_del->getCode() == 200);
	ASSERT_TRUE(result_del->getStatus() == _XPLATSTR("OK"));

	// Check not exist file
	result_exist = storage_api->objectExists(outPath, versionId, storage).get();

	ASSERT_FALSE(result_exist->isExists());
	ASSERT_FALSE(result_exist->isFolder());
}
