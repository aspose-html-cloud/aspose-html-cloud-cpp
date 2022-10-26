/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TestMhtmlConversionApi.cpp">
*  Copyright (c) 2022 Aspose.HTML for Cloud
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

class TestMhtmlConversionApi : public TestBase
{

public:
    std::shared_ptr<ConversionApi> api;
    std::shared_ptr<StorageApi> storage_api;

    boost::optional<utility::string_t> folder;
    boost::optional<utility::string_t> storage;
    utility::string_t name;
    boost::optional<utility::string_t> versionId;

    utility::string_t sourceUrl;
    double width;
    double height;
    double leftMargin;
    double rightMargin;
    double topMargin;
    double bottomMargin;

protected:

    void SetUp()
	{
        try 
        {
            std::shared_ptr<ApiConfiguration> apiConfig(new ApiConfiguration(clientId, clientSecret, basePath, authPath));
            std::shared_ptr<ApiClient> apiClient(new ApiClient(apiConfig));
            api = std::make_shared<ConversionApi>(apiClient);
            storage_api = std::make_shared<StorageApi>(apiClient);

            folder = _XPLATSTR("HtmlTestMHTMLCPP");
            storage = boost::none;
            name = _XPLATSTR("fileformatinfo.mht");

            width = 800;
            height = 1000;
            leftMargin = 50;
            rightMargin = 50;
            topMargin = 100;
            bottomMargin = 100;
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
    }

    void TearDown()
    {
    }
};

TEST_F(TestMhtmlConversionApi, /*DISABLED_*/testLocalToLocalMHTML)
{

    utility::string_t formats[] = { L"pdf", L"xps", L"docx"};
    utility::string_t src = testSource + name;

    for (int i = 0; i < sizeof(formats) / sizeof(formats[0]); ++i)
    {
        utility::string_t dst = testResult + L"LocToLocMHTML." + formats[i];

        auto result = api->convertLocalToLocal(src, dst);
        auto re = result->getFile();

        std::ifstream f(re.c_str());
        ASSERT_TRUE(f.good());
    }
}

TEST_F(TestMhtmlConversionApi, /*DISABLED_*/testLocalToLocalMHTMLWithOpts)
{

    utility::string_t formats[] = { L"pdf", L"xps", L"docx" };
    utility::string_t src = testSource + name;

    for (int i = 0; i < sizeof(formats) / sizeof(formats[0]); ++i)
    {
        utility::string_t dst = testResult + L"LocToLocMHTMLWithOpts." + formats[i];

        std::shared_ptr<ConversionOptions> opts_A4 = std::make_shared<ConversionOptions>();
        opts_A4->setWidth(8.3)
            ->setHeight(11.7)
            ->setLeftMargin(0.2)
            ->setRightMargin(0.2)
            ->setTopMargin(0.2)
            ->setBottomMargin(0.2);

        auto result = api->convertLocalToLocal(src, dst, opts_A4);
        auto re = result->getFile();

        std::ifstream f(re.c_str());
        ASSERT_TRUE(f.good());
    }
}

TEST_F(TestMhtmlConversionApi, /*DISABLED_*/LocalToLocalMHTMLToImages)
{

    utility::string_t formats[] = { L"jpeg", L"jpg", L"bmp", L"png", L"tiff", L"tif", L"gif" };
    utility::string_t src = testSource + name;

    std::shared_ptr<ConversionOptions> opts = std::make_shared<ConversionOptions>();
    opts->setWidth(width)
        ->setHeight(height)
        ->setLeftMargin(leftMargin)
        ->setRightMargin(rightMargin)
        ->setTopMargin(topMargin)
        ->setBottomMargin(bottomMargin);

    for (int i = 0; i < sizeof(formats) / sizeof(formats[0]); ++i)
    {
        utility::string_t dst = testResult + L"LocToLocMHTMLToImg." + formats[i];

        auto result = api->convertLocalToLocal(src, dst, opts);
        auto re = result->getFile();

        std::ifstream f(re.c_str());
        ASSERT_TRUE(f.good());
    }
}

TEST_F(TestMhtmlConversionApi, /*DISABLED_*/testLocalToStorageMHTML)
{

    utility::string_t formats[] = { L"pdf", L"xps", L"docx" };
    utility::string_t src = testSource + name;

    for (int i = 0; i < sizeof(formats) / sizeof(formats[0]); ++i)
    {
        utility::string_t dst = L"HtmlDocCPP/LocToStorMHTML." + formats[i];
        boost::optional<utility::string_t> versionId = _XPLATSTR("");
        utility::string_t storage = _XPLATSTR("");

        auto result = api->convertLocalToStorage(src, dst, storage);
        auto filePath = result->getFile();

        auto result_exist = storage_api->objectExists(filePath, versionId, storage).get();

        ASSERT_TRUE(result_exist->isExists());
        ASSERT_FALSE(result_exist->isFolder());
    }
}

TEST_F(TestMhtmlConversionApi, /*DISABLED_*/testLocalToStorageMHTMLToImages)
{

    utility::string_t formats[] = { L"jpeg", L"jpg", L"bmp", L"png", L"tiff", L"tif", L"gif" };
    utility::string_t src = testSource + name;
    std::shared_ptr<ConversionOptions> opts = std::make_shared<ConversionOptions>();
    opts->setWidth(width)
        ->setHeight(height)
        ->setLeftMargin(leftMargin)
        ->setRightMargin(rightMargin)
        ->setTopMargin(topMargin)
        ->setBottomMargin(bottomMargin);

    for (int i = 0; i < sizeof(formats) / sizeof(formats[0]); ++i)
    {
        utility::string_t dst = L"HtmlDocCPP/LocToStorMHTMLToImg." + formats[i];
        boost::optional<utility::string_t> versionId = _XPLATSTR("");
        utility::string_t storage = _XPLATSTR("");

        auto result = api->convertLocalToStorage(src, dst, storage, opts);
        auto filePath = result->getFile();

        auto result_exist = storage_api->objectExists(filePath, versionId, storage).get();

        ASSERT_TRUE(result_exist->isExists());
        ASSERT_FALSE(result_exist->isFolder());
    }
}

TEST_F(TestMhtmlConversionApi, /*DISABLED_*/testStorageToStorageMHTML)
{

    utility::string_t formats[] = { L"pdf", L"xps", L"docx" };
    utility::string_t src = name;

    std::shared_ptr<HttpContent> file(new HttpContent(testSource, name));
    utility::string_t folder = _XPLATSTR("/");

    auto res = storage_api->uploadFile(folder, file, storage).get();

    ASSERT_FALSE(res->errorsIsSet());

    for (int i = 0; i < sizeof(formats) / sizeof(formats[0]); ++i)
    {
        utility::string_t dst = L"HtmlDoc/LocToStorMHTML." + formats[i];
        boost::optional<utility::string_t> versionId = _XPLATSTR("");
        utility::string_t storage = _XPLATSTR("");

        auto result = api->convertStorageToStorage(src, dst, storage);
        auto filePath = result->getFile();

        auto result_exist = storage_api->objectExists(filePath, versionId, storage).get();

        ASSERT_TRUE(result_exist->isExists());
        ASSERT_FALSE(result_exist->isFolder());
    }
}

TEST_F(TestMhtmlConversionApi, /*DISABLED_*/testStorageToStorageMHTMLToImages)
{

    utility::string_t formats[] = { L"jpeg", L"jpg", L"bmp", L"png", L"tiff", L"tif", L"gif" };
    utility::string_t src = name;


    std::shared_ptr<HttpContent> file(new HttpContent(testSource, name));
    utility::string_t folder = _XPLATSTR("/");

    auto res = storage_api->uploadFile(folder, file, storage).get();

    std::shared_ptr<ConversionOptions> opts = std::make_shared<ConversionOptions>();
    opts->setWidth(width)
        ->setHeight(height)
        ->setLeftMargin(leftMargin)
        ->setRightMargin(rightMargin)
        ->setTopMargin(topMargin)
        ->setBottomMargin(bottomMargin);

    for (int i = 0; i < sizeof(formats) / sizeof(formats[0]); ++i)
    {
        utility::string_t dst = L"HtmlDocCPP/StorToStorMHTMLToImg." + formats[i];
        boost::optional<utility::string_t> versionId = _XPLATSTR("");
        utility::string_t storage = _XPLATSTR("");

        auto result = api->convertStorageToStorage(src, dst, storage, opts);
        auto filePath = result->getFile();

        auto result_exist = storage_api->objectExists(filePath, versionId, storage).get();

        ASSERT_TRUE(result_exist->isExists());
        ASSERT_FALSE(result_exist->isFolder());
    }
}

TEST_F(TestMhtmlConversionApi, /*DISABLED_*/testStorageToLocalMHTML)
{

    utility::string_t formats[] = { L"pdf", L"xps", L"docx" };
    utility::string_t src = name;

    std::shared_ptr<HttpContent> file(new HttpContent(testSource, name));
    utility::string_t folder = _XPLATSTR("/");

    auto res = storage_api->uploadFile(folder, file, storage).get();

    ASSERT_FALSE(res->errorsIsSet());

    for (int i = 0; i < sizeof(formats) / sizeof(formats[0]); ++i)
    {
        utility::string_t dst = testResult + L"StorToLocMHTML." + formats[i];
        boost::optional<utility::string_t> versionId = _XPLATSTR("");
        utility::string_t storage = _XPLATSTR("");

        auto result = api->convertStorageToLocal(src, dst, storage);
        auto filePath = result->getFile();

        std::ifstream f(filePath.c_str());
        ASSERT_TRUE(f.good());
    }
}

TEST_F(TestMhtmlConversionApi, /*DISABLED_*/testStorageToLocalMHTMLToImages)
{

    utility::string_t formats[] = { L"jpeg", L"jpg", L"bmp", L"png", L"tiff", L"tif", L"gif" };
    utility::string_t src = name;


    std::shared_ptr<HttpContent> file(new HttpContent(testSource, name));
    utility::string_t folder = _XPLATSTR("/");

    auto res = storage_api->uploadFile(folder, file, storage).get();

    std::shared_ptr<ConversionOptions> opts = std::make_shared<ConversionOptions>();
    opts->setWidth(width)
        ->setHeight(height)
        ->setLeftMargin(leftMargin)
        ->setRightMargin(rightMargin)
        ->setTopMargin(topMargin)
        ->setBottomMargin(bottomMargin);

    for (int i = 0; i < sizeof(formats) / sizeof(formats[0]); ++i)
    {
        utility::string_t dst = testResult + L"StorToLocMHTMLToImg." + formats[i];
        boost::optional<utility::string_t> versionId = _XPLATSTR("");
        utility::string_t storage = _XPLATSTR("");

        auto result = api->convertStorageToLocal(src, dst, storage, opts);
        auto filePath = result->getFile();

        std::ifstream f(filePath.c_str());
        ASSERT_TRUE(f.good());
    }
}
