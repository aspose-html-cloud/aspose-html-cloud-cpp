/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TestToSVGConversionApi.cpp">
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

class TestToSVGConversionApi : public TestBase
{

public:
    std::shared_ptr<ConversionApi> api;
    utility::string_t name;


protected:

    void SetUp()
	{
        try 
        {
            std::shared_ptr<ApiConfiguration> apiConfig(new ApiConfiguration(clientId, clientSecret, basePath, authPath));
            std::shared_ptr<ApiClient> apiClient(new ApiClient(apiConfig));
            api = std::make_shared<ConversionApi>(apiClient);
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


TEST_F(TestToSVGConversionApi, /*DISABLED_*/ToSVGLocalToLocalImages)
{
    utility::string_t formats[] = { L"jpg", L"bmp", L"png", L"tiff", L"gif" };

    for (int i = 0; i < sizeof(formats) / sizeof(formats[0]); ++i)
    {
        utility::string_t src = testSource + name + formats[i];
        utility::string_t dst = testResult + L"SVGTrace_" + formats[i] + L".svg";

        auto result = api->convertLocalToLocal(src, dst);
        auto re = result->getFile();

        std::ifstream f(re.c_str());
        ASSERT_TRUE(f.good());
    }
}

TEST_F(TestToSVGConversionApi, /*DISABLED_*/ToSVGLocalToLocalImagesWithOpts)
{
    utility::string_t formats[] = { L"jpg", L"bmp", L"png", L"tiff", L"gif" };

    std::shared_ptr<ConversionOptions> opts = std::make_shared<ConversionOptions>();
    opts->setErrorThreshold(50)
        ->setColorLimit(2)
        ->setLineWidth(1.5)
        ->setMaxIteration(10);

    for (int i = 0; i < sizeof(formats) / sizeof(formats[0]); ++i)
    {
        utility::string_t src = testSource + name + formats[i];
        utility::string_t dst = testResult + L"SVGTraceWithOpts_" + formats[i] + L".svg";

        auto result = api->convertLocalToLocal(src, dst, opts);
        auto re = result->getFile();

        std::ifstream f(re.c_str());
        ASSERT_TRUE(f.good());
    }
}
