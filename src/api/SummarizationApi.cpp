/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="SummarizationApi.cpp">
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


#include "api/SummarizationApi.h"
#include "IHttpBody.h"
#include "JsonBody.h"
#include "MultipartFormData.h"
#include <unordered_set>
#include <boost/algorithm/string/replace.hpp>


namespace com {
namespace aspose {
namespace api {

using namespace com::aspose::model;

SummarizationApi::SummarizationApi( std::shared_ptr<ApiClient> apiClient )
    : m_ApiClient(apiClient)
{
}

SummarizationApi::~SummarizationApi()
{
}

pplx::task<HttpContent> SummarizationApi::getDetectHtmlKeywords(utility::string_t name, boost::optional<utility::string_t> folder, boost::optional<utility::string_t> storage)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/html/{name}/summ/keywords");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // JSON
    else if ( responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        //It's going to be binary, so just use the first one.
        responseHttpContentType = *responseHttpContentTypes.begin();
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (folder)
    {
        queryParams[utility::conversions::to_string_t("folder")] = ApiClient::parameterToString(*folder);
    }
    if (storage)
    {
        queryParams[utility::conversions::to_string_t("storage")] = ApiClient::parameterToString(*storage);
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("SummarizationApi->getDetectHtmlKeywords does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getDetectHtmlKeywords: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

		return response.extract_vector();
    })
    .then([=](std::vector<unsigned char> response)
    {
        HttpContent result;
        std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(std::string(response.begin(), response.end()));
        result.setData(stream);
        return result;
    });
}
pplx::task<HttpContent> SummarizationApi::getDetectHtmlKeywordsByUrl(utility::string_t sourceUrl)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/html/summ/keywords");
    
    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    utility::string_t responseHttpContentType;

    responseHttpContentType = utility::conversions::to_string_t("text/html");

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    {
        queryParams[utility::conversions::to_string_t("sourceUrl")] = ApiClient::parameterToString(sourceUrl);
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("application/json");
    }
    // multipart formdata
    else if( consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
    }
    else
    {
        throw ApiException(415, utility::conversions::to_string_t("SummarizationApi->getDetectHtmlKeywordsByUrl does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getDetectHtmlKeywordsByUrl: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        return response.extract_vector();
    })
    .then([=](std::vector<unsigned char> response)
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
