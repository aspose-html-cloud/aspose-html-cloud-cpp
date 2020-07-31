/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TestHtmlConversionApi.cpp">
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
        try 
        {
            std::shared_ptr<ApiConfiguration> apiConfig(new ApiConfiguration(clientId, clientSecret, basePath, authPath));
            std::shared_ptr<ApiClient> apiClient(new ApiClient(apiConfig));
            api = new ConversionApi(apiClient);
            storage_api = new StorageApi(apiClient);


            sourceUrl = _XPLATSTR("https://stallman.org/articles/anonymous-payments-thru-phones.html");
            folder = _XPLATSTR("HtmlTestDoc");
            storage = boost::none;
            name = _XPLATSTR("test1.html");

            width = 800;
            height = 1000;
            leftMargin = 50;
            rightMargin = 50;
            topMargin = 100;
            bottomMargin = 100;
            resolution = 300;

            //Upload file for conversion to server
            std::shared_ptr<HttpContent> file(new HttpContent(testSource, name));
            utility::string_t path_to_file = _XPLATSTR("HtmlTestDoc/test1.html");

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

// Convert html document
TEST_F(TestHtmlConversionApi, /*DISABLED_*/testGetHtmlToJpeg)
{
	//Convert to jpeg
	auto result = api->getConvertDocumentToImage(name, _XPLATSTR("jpeg"), 
		width, height, leftMargin, rightMargin, topMargin, bottomMargin, resolution, folder, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertHtmlToJpg.zip")));
}
TEST_F(TestHtmlConversionApi, /*DISABLED_*/testGetHtmlToPng)
{
	//Convert to png
	auto result = api->getConvertDocumentToImage(name, _XPLATSTR("png"),
		width, height, leftMargin, rightMargin, topMargin, bottomMargin, resolution, folder, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertHtmlToPng.zip")));
}
TEST_F(TestHtmlConversionApi, /*DISABLED_*/testGetHtmlToBmp)
{
	//Convert to bmp
	auto result = api->getConvertDocumentToImage(name, _XPLATSTR("bmp"),
		width, height, leftMargin, rightMargin, topMargin, bottomMargin, resolution, folder, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertHtmlToBmp.zip")));
}
TEST_F(TestHtmlConversionApi, /*DISABLED_*/testGetHtmlToTiff)
{
	//Convert to tiff
	auto result = api->getConvertDocumentToImage(name, _XPLATSTR("tiff"),
		width, height, leftMargin, rightMargin, topMargin, bottomMargin, resolution, folder, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertHtmlToTiff.zip")));
}
TEST_F(TestHtmlConversionApi, /*DISABLED_*/testGetHtmlToPdf)
{
	//Convert to pdf
	auto result = api->getConvertDocumentToPdf(name, width, height, leftMargin, 
        rightMargin, topMargin, bottomMargin, folder, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertHtmlToPdf.pdf")));
}
TEST_F(TestHtmlConversionApi, /*DISABLED_*/testGetHtmlToXps)
{
	//Convert to xps
	auto result = api->getConvertDocumentToXps(name, width, height, leftMargin, 
        rightMargin, topMargin, bottomMargin, folder, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertHtmlToXps.xps")));
}

//Convert URL
TEST_F(TestHtmlConversionApi, /*DISABLED_*/testGetUrlToJpeg)
{
	//Convert to jpeg
	auto result = api->getConvertDocumentToImageByUrl(sourceUrl, _XPLATSTR("jpeg"),
		width, height, leftMargin, rightMargin, topMargin, bottomMargin, resolution).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertUrlToJpg.zip")));
}
TEST_F(TestHtmlConversionApi, /*DISABLED_*/testGetUrlToPng)
{
	//Convert to png
	auto result = api->getConvertDocumentToImageByUrl(sourceUrl, _XPLATSTR("png"),
		width, height, leftMargin, rightMargin, topMargin, bottomMargin, resolution).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertUrlToPng.zip")));
}
TEST_F(TestHtmlConversionApi, /*DISABLED_*/testGetUrlToBmp)
{
	//Convert to bmp
	auto result = api->getConvertDocumentToImageByUrl(sourceUrl, _XPLATSTR("bmp"),
		width, height, leftMargin, rightMargin, topMargin, bottomMargin, resolution).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertUrlToBmp.zip")));
}
TEST_F(TestHtmlConversionApi, /*DISABLED_*/testGetUrlToTiff)
{
	//Convert to tiff
	auto result = api->getConvertDocumentToImageByUrl(sourceUrl, _XPLATSTR("tiff"),
		width, height, leftMargin, rightMargin, topMargin, bottomMargin, resolution).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertUrlToTiff.zip")));
}
TEST_F(TestHtmlConversionApi, /*DISABLED_*/testGetUrlToPdf)
{
	//Convert to pdf
	auto result = api->getConvertDocumentToPdfByUrl(sourceUrl, width, height, leftMargin, rightMargin, topMargin, bottomMargin).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertUrlToPdf.pdf")));
}
TEST_F(TestHtmlConversionApi, /*DISABLED_*/testGetUrlToXps)
{
	//Convert to xps
	auto result = api->getConvertDocumentToXpsByUrl(sourceUrl, width, height, leftMargin, rightMargin, topMargin, bottomMargin).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertUrlToXps.xps")));
}
TEST_F(TestHtmlConversionApi, /*DISABLED_*/testPostHtmlInRequestToImage)
{
	//Prepare file stream to upload
    utility::string_t name = _XPLATSTR("test1.html");
    std::shared_ptr<HttpContent> file(new HttpContent(testSource, name));

	//Parameters
	utility::string_t outPath = _XPLATSTR("HtmlTestDoc/postConvertHtmlInRequestToJpg.zip");
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

	ASSERT_TRUE(TestBase::save_to_file(result_download, testResult + _XPLATSTR("postConvertHtmlInRequestToJpg.zip")));

	//Clear file
	auto result_del = storage_api->deleteFile(outPath, versionId, storage).get();

	ASSERT_TRUE(result_del->getCode() == 200);
	ASSERT_TRUE(result_del->getStatus() == _XPLATSTR("OK"));

	// Check not exist file
	result_exist = storage_api->objectExists(outPath, versionId, storage).get();

	ASSERT_FALSE(result_exist->isExists());
	ASSERT_FALSE(result_exist->isFolder());
}
TEST_F(TestHtmlConversionApi, /*DISABLED_*/testPostHtmlInRequestToPdf)
{
	//Prepare file stream to upload
    utility::string_t name = _XPLATSTR("test1.html");
    std::shared_ptr<HttpContent> file(new HttpContent(testSource, name));

	//Parameters
	utility::string_t outPath = _XPLATSTR("HtmlTestDoc/postConvertHtmlInRequestToPdf.pdf");

	//Convert to pdf and save to storage
	auto result = api->postConvertDocumentInRequestToPdf(outPath, file, width, height, leftMargin, rightMargin, 
		topMargin, bottomMargin, storage).get();

	// Check exist file
	auto result_exist = storage_api->objectExists(outPath, versionId, storage).get();

	ASSERT_TRUE(result_exist->isExists());
	ASSERT_FALSE(result_exist->isFolder());

	// Download file from storage
	auto result_download = storage_api->downloadFile(outPath, versionId, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result_download, testResult + _XPLATSTR("postConvertHtmlInRequestToPdf.pdf")));

	//Clear file
	auto result_del = storage_api->deleteFile(outPath, versionId, storage).get();

	ASSERT_TRUE(result_del->getCode() == 200);
	ASSERT_TRUE(result_del->getStatus() == _XPLATSTR("OK"));

	// Check not exist file
	result_exist = storage_api->objectExists(outPath, versionId, storage).get();

	ASSERT_FALSE(result_exist->isExists());
	ASSERT_FALSE(result_exist->isFolder());
}
TEST_F(TestHtmlConversionApi, /*DISABLED_*/testPostHtmlInRequestToXps)
{
	//Prepare file stream to upload
    utility::string_t name = _XPLATSTR("test1.html");
    std::shared_ptr<HttpContent> file(new HttpContent(testSource, name));

	//Parameters
	utility::string_t outPath = _XPLATSTR("HtmlTestDoc/postConvertHtmlInRequestToXps.xps");

	//Convert to xps and save to storage
	auto result = api->postConvertDocumentInRequestToXps(outPath, file, width, height, leftMargin, rightMargin,
		topMargin, bottomMargin, storage).get();

	// Check exist file
	auto result_exist = storage_api->objectExists(outPath, versionId, storage).get();

	ASSERT_TRUE(result_exist->isExists());
	ASSERT_FALSE(result_exist->isFolder());

	// Download file from storage
	auto result_download = storage_api->downloadFile(outPath, versionId, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result_download, testResult + _XPLATSTR("postConvertHtmlInRequestToXps.xps")));

	//Clear file
	auto result_del = storage_api->deleteFile(outPath, versionId, storage).get();

	ASSERT_TRUE(result_del->getCode() == 200);
	ASSERT_TRUE(result_del->getStatus() == _XPLATSTR("OK"));

	// Check not exist file
	result_exist = storage_api->objectExists(outPath, versionId, storage).get();

	ASSERT_FALSE(result_exist->isExists());
	ASSERT_FALSE(result_exist->isFolder());
}
TEST_F(TestHtmlConversionApi, /*DISABLED_*/testPutHtmlToImage)
{
	//Parameters
	utility::string_t outPath = _XPLATSTR("HtmlTestDoc/putConvertHtmlToPng.zip");
	utility::string_t outFormat = _XPLATSTR("png");

	auto result = api->putConvertDocumentToImage(name, outPath, outFormat, width, height, leftMargin, rightMargin, topMargin,
			bottomMargin, resolution, folder, storage).get();

	// Check exist file
	auto result_exist = storage_api->objectExists(outPath, versionId, storage).get();

	ASSERT_TRUE(result_exist->isExists());
	ASSERT_FALSE(result_exist->isFolder());

	// Download file from storage
	auto result_download = storage_api->downloadFile(outPath, versionId, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result_download, testResult + _XPLATSTR("putConvertHtmlToPng.zip")));

	//Clear file
	auto result_del = storage_api->deleteFile(outPath, versionId, storage).get();

	ASSERT_TRUE(result_del->getCode() == 200);
	ASSERT_TRUE(result_del->getStatus() == _XPLATSTR("OK"));

	// Check not exist file
	result_exist = storage_api->objectExists(outPath, versionId, storage).get();

	ASSERT_FALSE(result_exist->isExists());
	ASSERT_FALSE(result_exist->isFolder());
}
TEST_F(TestHtmlConversionApi, /*DISABLED_*/testPutHtmlToPdf)
{
	//Parameters
	utility::string_t outPath = _XPLATSTR("HtmlTestDoc/putConvertHtmlToPdf.pdf");

	//Convert to pdf and save to storage
	auto result = api->putConvertDocumentToPdf(name, outPath, width, height, leftMargin, rightMargin, 
		topMargin, bottomMargin, folder, storage).get();

	// Check exist file
	auto result_exist = storage_api->objectExists(outPath, versionId, storage).get();

	ASSERT_TRUE(result_exist->isExists());
	ASSERT_FALSE(result_exist->isFolder());

	// Download file from storage
	auto result_download = storage_api->downloadFile(outPath, versionId, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result_download, testResult + _XPLATSTR("putConvertHtmlToPdf.pdf")));

	//Clear file
	auto result_del = storage_api->deleteFile(outPath, versionId, storage).get();

	ASSERT_TRUE(result_del->getCode() == 200);
	ASSERT_TRUE(result_del->getStatus() == _XPLATSTR("OK"));

	// Check not exist file
	result_exist = storage_api->objectExists(outPath, versionId, storage).get();

	ASSERT_FALSE(result_exist->isExists());
	ASSERT_FALSE(result_exist->isFolder());
}
TEST_F(TestHtmlConversionApi, /*DISABLED_*/testPutHtmlToXps)
{
	//Parameters
	utility::string_t outPath = _XPLATSTR("HtmlTestDoc/putConvertHtmlToXps.xps");

	//Convert to xps and save to storage
	auto result = api->putConvertDocumentToXps(name, outPath, width, height, 
		leftMargin, rightMargin, topMargin, bottomMargin, folder, storage).get();

	// Check exist file
	auto result_exist = storage_api->objectExists(outPath, versionId, storage).get();

	ASSERT_TRUE(result_exist->isExists());
	ASSERT_FALSE(result_exist->isFolder());

	// Download file from storage
	auto result_download = storage_api->downloadFile(outPath, versionId, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result_download, testResult + _XPLATSTR("putConvertHtmlToXps.xps")));

	//Clear file
	auto result_del = storage_api->deleteFile(outPath, versionId, storage).get();

	ASSERT_TRUE(result_del->getCode() == 200);
	ASSERT_TRUE(result_del->getStatus() == _XPLATSTR("OK"));

	// Check not exist file
	result_exist = storage_api->objectExists(outPath, versionId, storage).get();

	ASSERT_FALSE(result_exist->isExists());
	ASSERT_FALSE(result_exist->isFolder());
}
TEST_F(TestHtmlConversionApi, /*DISABLED_*/testGetHtmlToMHTMLByUrlTest)
{
	utility::string_t sourceUrl = _XPLATSTR("https://www.yahoo.com");
	//Convert to mhtml
	auto result = api->getConvertDocumentToMHTMLByUrl(sourceUrl).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("ConvertUrlToMhtml.mht")));
}
TEST_F(TestHtmlConversionApi, /*DISABLED_*/testGetHtmlToMarkdown)
{
	//Upload document to storage
    utility::string_t name = _XPLATSTR("test_md.html");
    std::shared_ptr<HttpContent> file(new HttpContent(testSource, name));

	utility::string_t path_to_file = _XPLATSTR("HtmlTestDoc/test_md.html");

	auto res = storage_api->uploadFile(path_to_file, file, storage).get();

    ASSERT_FALSE(res->errorsIsSet());

	// Get convert html to markdown format
	boost::optional<bool> useGit = true;
	
	auto result = api->getConvertDocumentToMarkdown(name, useGit, folder, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("test_get_to_markdown.md")));

	//Clear test file in the storage
	auto result_del = storage_api->deleteFile(path_to_file, versionId, storage).get();

	ASSERT_TRUE(result_del->getCode() == 200);
	ASSERT_TRUE(result_del->getStatus() == _XPLATSTR("OK"));
}
TEST_F(TestHtmlConversionApi, /*DISABLED_*/testConvertDocumentInRequestToMarkdown)
{
    //Prepare document
    utility::string_t name = _XPLATSTR("test_md.html");
    std::shared_ptr<HttpContent> file(new HttpContent(testSource, name));

    // Post convert html to markdown format
    utility::string_t outPath = _XPLATSTR("HtmlTestDoc/test_post_to_markdown.md");
    boost::optional<bool> useGit = false;
    api->postConvertDocumentInRequestToMarkdown(outPath, file, useGit, storage).get();

    // Download file from storage
    auto result_download = storage_api->downloadFile(outPath, versionId, storage).get();

    ASSERT_TRUE(TestBase::save_to_file(result_download, testResult + _XPLATSTR("test_put_to_markdown.md")));

    //Clear test file in the storage
    auto result_del_test = storage_api->deleteFile(outPath, versionId, storage).get();

    ASSERT_TRUE(result_del_test->getCode() == 200);
    ASSERT_TRUE(result_del_test->getStatus() == _XPLATSTR("OK"));
}
TEST_F(TestHtmlConversionApi, /*DISABLED_*/testPutHtmlToMarkdown)
{
	//Upload document to storage
    utility::string_t name = _XPLATSTR("test_md.html");
    std::shared_ptr<HttpContent> file(new HttpContent(testSource, name));
    
    utility::string_t path_to_file = _XPLATSTR("HtmlTestDoc/test_md.html");
    boost::optional<utility::string_t> versionId = boost::none;

	auto res = storage_api->uploadFile(path_to_file, file, storage).get();

	ASSERT_FALSE(res->errorsIsSet());

	// Put convert html to markdown format
	utility::string_t outPath = _XPLATSTR("HtmlTestDoc/test_put_to_markdown.md");
	boost::optional<bool> useGit = false;

	api->putConvertDocumentToMarkdown(name, outPath, useGit, folder, storage).get();

	//Clear test file in the storage
	auto result_del_test = storage_api->deleteFile(path_to_file, versionId, storage).get();

	ASSERT_TRUE(result_del_test->getCode() == 200);
	ASSERT_TRUE(result_del_test->getStatus() == _XPLATSTR("OK"));

	// Download file from storage
	auto result_download = storage_api->downloadFile(outPath, versionId, storage).get();

	ASSERT_TRUE(TestBase::save_to_file(result_download, testResult + _XPLATSTR("test_put_to_markdown.md")));

	//Clear result file
	auto result_del = storage_api->deleteFile(outPath, versionId, storage).get();

	ASSERT_TRUE(result_del->getCode() == 200);
	ASSERT_TRUE(result_del->getStatus() == _XPLATSTR("OK"));
}
