/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TestSeoApi.cpp">
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

class TestSeoApi : public TestBase
{

public:

    SeoApi* api;
    StorageApi* storage_api;

protected:

    void SetUp()
	{
        try 
        {
            std::shared_ptr<ApiConfiguration> apiConfig(new ApiConfiguration(clientId, clientSecret, basePath, authPath));
            std::shared_ptr<ApiClient> apiClient(new ApiClient(apiConfig));
            api = new SeoApi(apiClient);
            storage_api = new StorageApi(apiClient);
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

TEST_F(TestSeoApi, DISABLED_testGetSeoWarning)
{
	auto result = api->getSeoWarning(_XPLATSTR("https://lenta.ru/")).get();
	ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("test_get_seo_warning.json")));
}

TEST_F(TestSeoApi, DISABLED_testGetHtmlWarning)
{
    auto result = api->getHtmlWarning(_XPLATSTR("https://lenta.ru/")).get();
    ASSERT_TRUE(TestBase::save_to_file(result, testResult + _XPLATSTR("test_get_html_warning.json")));
}
