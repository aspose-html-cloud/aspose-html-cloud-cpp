/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TestVectorizeToSVGApi.cpp">
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

class TestVectorizeToSVGApi : public TestBase
{

public:
    std::shared_ptr<VectorizationApi> api;
    std::shared_ptr<StorageApi> storage_api;
    utility::string_t name;


protected:

    void SetUp()
	{
        try 
        {
            std::shared_ptr<ApiConfiguration> apiConfig(new ApiConfiguration(clientId, clientSecret, basePath, authPath));
            std::shared_ptr<ApiClient> apiClient(new ApiClient(apiConfig));
            api = std::make_shared<VectorizationApi>(apiClient);
            storage_api = std::make_shared<StorageApi>(apiClient);
            name = _XPLATSTR("car.");
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


TEST_F(TestVectorizeToSVGApi, /*DISABLED_*/ToSVGLocalToLocalImages)
{
    utility::string_t formats[] = { L"jpg", L"bmp", L"png", L"tiff", L"gif" };

    for (int i = 0; i < sizeof(formats) / sizeof(formats[0]); ++i)
    {
        utility::string_t src = testSource + name + formats[i];
        utility::string_t dst = testResult + L"VectorizeLocToLoc_" + formats[i] + L".svg";

        auto result = api->vectorizeLocalToLocal(src, dst);
        auto re = result->getFile();

        std::ifstream f(re.c_str());
        ASSERT_TRUE(f.good());
    }
}

TEST_F(TestVectorizeToSVGApi, /*DISABLED_*/ToSVGLocalToLocalImagesWithOpts)
{
    utility::string_t formats[] = { L"jpg", L"bmp", L"png", L"tiff", L"gif" };

    std::shared_ptr<VectorizationOptions> opts = std::make_shared<VectorizationOptions>();
    opts->setErrorThreshold(50)
        ->setColorLimit(2)
        ->setLineWidth(1.5)
        ->setMaxIteration(10);

    for (int i = 0; i < sizeof(formats) / sizeof(formats[0]); ++i)
    {
        utility::string_t src = testSource + name + formats[i];
        utility::string_t dst = testResult + L"VectorizeLocToLocWithOpts_" + formats[i] + L".svg";

        auto result = api->vectorizeLocalToLocal(src, dst, opts);
        auto re = result->getFile();

        std::ifstream f(re.c_str());
        ASSERT_TRUE(f.good());
    }
}

TEST_F(TestVectorizeToSVGApi, /*DISABLED_*/ToSVGLocalToStorage)
{
    utility::string_t formats[] = { L"jpg", L"bmp", L"png", L"tiff", L"gif" };

    for (int i = 0; i < sizeof(formats) / sizeof(formats[0]); ++i)
    {
        utility::string_t src = testSource + name + formats[i];
        utility::string_t dst = _XPLATSTR("HtmlDocCPP/VectorizeLocToStor_") + formats[i] + _XPLATSTR(".svg");
        utility::string_t storage = _XPLATSTR("");


        auto result = api->vectorizeLocalToStorage(src, dst, storage);
        auto filePath = result->getFile();

        boost::optional<utility::string_t> versionId = _XPLATSTR("");
        auto result_exist = storage_api->objectExists(filePath, versionId, storage).get();

        ASSERT_TRUE(result_exist->isExists());
        ASSERT_FALSE(result_exist->isFolder());
    }
}

TEST_F(TestVectorizeToSVGApi, /*DISABLED_*/ToSVGLocalToStorageWithOpts)
{
    utility::string_t formats[] = { L"jpg", L"bmp", L"png", L"tiff", L"gif" };

    for (int i = 0; i < sizeof(formats) / sizeof(formats[0]); ++i)
    {
        utility::string_t src = testSource + name + formats[i];
        utility::string_t dst = _XPLATSTR("HtmlDocCPP/VectorizeLocToStorWithOpts_") + formats[i] + _XPLATSTR(".svg");
        utility::string_t storage = _XPLATSTR("");
        std::shared_ptr<VectorizationOptions> opts = std::make_shared<VectorizationOptions>();
        opts->setErrorThreshold(50)
            ->setColorLimit(2)
            ->setLineWidth(1.5)
            ->setMaxIteration(10);

        auto result = api->vectorizeLocalToStorage(src, dst, storage, opts);
        auto filePath = result->getFile();

        boost::optional<utility::string_t> versionId = _XPLATSTR("");
        auto result_exist = storage_api->objectExists(filePath, versionId, storage).get();

        ASSERT_TRUE(result_exist->isExists());
        ASSERT_FALSE(result_exist->isFolder());
    }
}

TEST_F(TestVectorizeToSVGApi, /*DISABLED_*/ToSVGStorageToLocal)
{
    utility::string_t formats[] = { L"jpg", L"bmp", L"png", L"tiff", L"gif" };

    for (int i = 0; i < sizeof(formats) / sizeof(formats[0]); ++i)
    {

        std::shared_ptr<HttpContent> file(new HttpContent(testSource, name + formats[i]));
        utility::string_t folder = _XPLATSTR("/");
        utility::string_t storage = _XPLATSTR("");

        auto res = storage_api->uploadFile(folder, file, storage).get();

        ASSERT_FALSE(res->errorsIsSet());

        utility::string_t src = L"/" + name + formats[i];
        utility::string_t dst = testResult + L"VectorizeStorToLoc_" + formats[i] + L".svg";

        auto result = api->vectorizeStorageToLocal(src, dst, storage);
        auto filePath = result->getFile();

        std::ifstream f(filePath.c_str());
        ASSERT_TRUE(f.good());
    }
}

TEST_F(TestVectorizeToSVGApi, /*DISABLED_*/ToSVGStorageToLocalWithOpts)
{
    utility::string_t formats[] = { L"jpg", L"bmp", L"png", L"tiff", L"gif" };

    std::shared_ptr<VectorizationOptions> opts = std::make_shared<VectorizationOptions>();
    opts->setErrorThreshold(50)
        ->setColorLimit(2)
        ->setLineWidth(1.5)
        ->setMaxIteration(10);

    for (int i = 0; i < sizeof(formats) / sizeof(formats[0]); ++i)
    {

        std::shared_ptr<HttpContent> file(new HttpContent(testSource, name + formats[i]));
        utility::string_t folder = _XPLATSTR("/");
        utility::string_t storage = _XPLATSTR("");

        auto res = storage_api->uploadFile(folder, file, storage).get();

        ASSERT_FALSE(res->errorsIsSet());

        utility::string_t src = L"/" + name + formats[i];
        utility::string_t dst = testResult + L"VectorizeStorToLocWithOpts_" + formats[i] + L".svg";


        auto result = api->vectorizeStorageToLocal(src, dst, storage, opts);
        auto filePath = result->getFile();

        std::ifstream f(filePath.c_str());
        ASSERT_TRUE(f.good());
    }
}

TEST_F(TestVectorizeToSVGApi, /*DISABLED_*/ToSVGStorageToStorage)
{
    utility::string_t formats[] = { L"jpg", L"bmp", L"png", L"tiff", L"gif" };

    for (int i = 0; i < sizeof(formats) / sizeof(formats[0]); ++i)
    {

        std::shared_ptr<HttpContent> file(new HttpContent(testSource, name + formats[i]));
        utility::string_t folder = _XPLATSTR("/");
        utility::string_t storage = _XPLATSTR("");

        auto res = storage_api->uploadFile(folder, file, storage).get();

        ASSERT_FALSE(res->errorsIsSet());

        utility::string_t src = L"/" + name + formats[i];
        utility::string_t dst = L"/VectorizeStorToStor_" + formats[i] + L".svg";


        auto result = api->vectorizeStorageToStorage(src, dst, storage);
        auto filePath = result->getFile();

        boost::optional<utility::string_t> versionId = _XPLATSTR("");
        auto result_exist = storage_api->objectExists(filePath, versionId, storage).get();

        ASSERT_TRUE(result_exist->isExists());
        ASSERT_FALSE(result_exist->isFolder());
    }
}

TEST_F(TestVectorizeToSVGApi, /*DISABLED_*/ToSVGStorageToStorageWithOpts)
{
    utility::string_t formats[] = { L"jpg", L"bmp", L"png", L"tiff", L"gif" };

    std::shared_ptr<VectorizationOptions> opts = std::make_shared<VectorizationOptions>();
    opts->setErrorThreshold(50)
        ->setColorLimit(2)
        ->setLineWidth(1.5)
        ->setMaxIteration(10);

    for (int i = 0; i < sizeof(formats) / sizeof(formats[0]); ++i)
    {

        std::shared_ptr<HttpContent> file(new HttpContent(testSource, name + formats[i]));
        utility::string_t folder = _XPLATSTR("/");
        utility::string_t storage = _XPLATSTR("");

        auto res = storage_api->uploadFile(folder, file, storage).get();

        ASSERT_FALSE(res->errorsIsSet());

        utility::string_t src = L"/" + name + formats[i];
        utility::string_t dst = L"/VectorizeStorToStorWithOpts_" + formats[i] + L".svg";

        auto result = api->vectorizeStorageToStorage(src, dst, storage, opts);
        auto filePath = result->getFile();

        boost::optional<utility::string_t> versionId = _XPLATSTR("");
        auto result_exist = storage_api->objectExists(filePath, versionId, storage).get();

        ASSERT_TRUE(result_exist->isExists());
        ASSERT_FALSE(result_exist->isFolder());
    }
}