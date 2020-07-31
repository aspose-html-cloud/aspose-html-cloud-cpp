/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="SeoApi.cpp">
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

#include "api/SeoApi.h"
#include <unordered_set>


namespace com {
namespace aspose {
namespace api {

using namespace com::aspose::model;

SeoApi::SeoApi( std::shared_ptr<ApiClient> apiClient )
    : m_ApiClient(apiClient)
{
}

SeoApi::~SeoApi()
{
}

pplx::task<HttpContent> SeoApi::getSeoWarning(utility::string_t addr)
{
	std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
	utility::string_t path = utility::conversions::to_string_t("/html/seo");

	std::map<utility::string_t, utility::string_t> queryParams;
	std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
	std::map<utility::string_t, utility::string_t> formParams;
	std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

	std::unordered_set<utility::string_t> responseHttpContentTypes;
	responseHttpContentTypes.insert(utility::conversions::to_string_t("application/json"));

	utility::string_t responseHttpContentType = utility::conversions::to_string_t("application/json");

	headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

	std::unordered_set<utility::string_t> consumeHttpContentTypes;
	consumeHttpContentTypes.insert(utility::conversions::to_string_t("application/json"));

	queryParams[utility::conversions::to_string_t("addr")] = ApiClient::parameterToString(addr);

	std::shared_ptr<IHttpBody> httpBody;
	utility::string_t requestHttpContentType;

	return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
		.then([=](web::http::http_response response)
	{
		// 1xx - informational : OK
		// 2xx - successful	   : OK
		// 3xx - redirection   : OK 
		// 4xx - client error  : not OK
		// 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			throw ApiException(response.status_code()
				, utility::conversions::to_string_t("error calling getSeoWarning: ") + response.reason_phrase()
				, std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
		}

		return response.extract_vector();
	}).then([=](std::vector<unsigned char> response)
	{
		HttpContent result;
		std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(std::string(response.begin(), response.end()));
		result.setData(stream);
		return result;
	});
}

pplx::task<HttpContent> SeoApi::getHtmlWarning(utility::string_t url)
{
	std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
	utility::string_t path = utility::conversions::to_string_t("/html/validator");

	std::map<utility::string_t, utility::string_t> queryParams;
	std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
	std::map<utility::string_t, utility::string_t> formParams;
	std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

	std::unordered_set<utility::string_t> responseHttpContentTypes;
	responseHttpContentTypes.insert(utility::conversions::to_string_t("application/json"));

	utility::string_t responseHttpContentType = utility::conversions::to_string_t("application/json");

	headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

	std::unordered_set<utility::string_t> consumeHttpContentTypes;
	consumeHttpContentTypes.insert(utility::conversions::to_string_t("application/json"));

	queryParams[utility::conversions::to_string_t("url")] = ApiClient::parameterToString(url);

	std::shared_ptr<IHttpBody> httpBody;
	utility::string_t requestHttpContentType;

	return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
		.then([=](web::http::http_response response)
			{
				// 1xx - informational : OK
				// 2xx - successful	   : OK
				// 3xx - redirection   : OK 
				// 4xx - client error  : not OK
				// 5xx - client error  : not OK
				if (response.status_code() >= 400)
				{
					throw ApiException(response.status_code()
						, utility::conversions::to_string_t("error calling getHtmlWarning: ") + response.reason_phrase()
						, std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
				}

				return response.extract_vector();
			}).then([=](std::vector<unsigned char> response)
				{
					HttpContent result;
					std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(std::string(response.begin(), response.end()));
					result.setData(stream);
					return result;
				});
}

}
}
}
