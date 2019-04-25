/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ConversionApi.cpp">
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


#include "api/ConversionApi.h"
#include "IHttpBody.h"
#include "JsonBody.h"
#include "OctetStreamBody.h"
#include <unordered_set>
#include <boost/algorithm/string/replace.hpp>


namespace com {
namespace aspose {
namespace api {

using namespace com::aspose::model;

ConversionApi::ConversionApi( std::shared_ptr<ApiClient> apiClient )
    : m_ApiClient(apiClient)
{
}

ConversionApi::~ConversionApi()
{
}

pplx::task<HttpContent> ConversionApi::getConvertDocumentToImage(utility::string_t name, utility::string_t outFormat, boost::optional<int32_t> width, boost::optional<int32_t> height, boost::optional<int32_t> leftMargin, boost::optional<int32_t> rightMargin, boost::optional<int32_t> topMargin, boost::optional<int32_t> bottomMargin, boost::optional<int32_t> resolution, boost::optional<utility::string_t> folder, boost::optional<utility::string_t> storage)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/html/{name}/convert/image/{outFormat}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(name));
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("outFormat") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(outFormat));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("multipart/form-data") );

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

    if (width)
    {
        queryParams[utility::conversions::to_string_t("width")] = ApiClient::parameterToString(*width);
    }
    if (height)
    {
        queryParams[utility::conversions::to_string_t("height")] = ApiClient::parameterToString(*height);
    }
    if (leftMargin)
    {
        queryParams[utility::conversions::to_string_t("leftMargin")] = ApiClient::parameterToString(*leftMargin);
    }
    if (rightMargin)
    {
        queryParams[utility::conversions::to_string_t("rightMargin")] = ApiClient::parameterToString(*rightMargin);
    }
    if (topMargin)
    {
        queryParams[utility::conversions::to_string_t("topMargin")] = ApiClient::parameterToString(*topMargin);
    }
    if (bottomMargin)
    {
        queryParams[utility::conversions::to_string_t("bottomMargin")] = ApiClient::parameterToString(*bottomMargin);
    }
    if (resolution)
    {
        queryParams[utility::conversions::to_string_t("resolution")] = ApiClient::parameterToString(*resolution);
    }
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
        throw ApiException(415, utility::conversions::to_string_t("ConversionApi->getConvertDocumentToImage does not consume any supported media type"));
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
                , utility::conversions::to_string_t("error calling getConvertDocumentToImage: ") + response.reason_phrase()
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
pplx::task<HttpContent> ConversionApi::getConvertDocumentToImageByUrl(utility::string_t sourceUrl, utility::string_t outFormat, boost::optional<int32_t> width, boost::optional<int32_t> height, boost::optional<int32_t> leftMargin, boost::optional<int32_t> rightMargin, boost::optional<int32_t> topMargin, boost::optional<int32_t> bottomMargin, boost::optional<int32_t> resolution)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/html/convert/image/{outFormat}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("outFormat") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(outFormat));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("multipart/form-data") );

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

    {
        queryParams[utility::conversions::to_string_t("sourceUrl")] = ApiClient::parameterToString(sourceUrl);
    }
    if (width)
    {
        queryParams[utility::conversions::to_string_t("width")] = ApiClient::parameterToString(*width);
    }
    if (height)
    {
        queryParams[utility::conversions::to_string_t("height")] = ApiClient::parameterToString(*height);
    }
    if (leftMargin)
    {
        queryParams[utility::conversions::to_string_t("leftMargin")] = ApiClient::parameterToString(*leftMargin);
    }
    if (rightMargin)
    {
        queryParams[utility::conversions::to_string_t("rightMargin")] = ApiClient::parameterToString(*rightMargin);
    }
    if (topMargin)
    {
        queryParams[utility::conversions::to_string_t("topMargin")] = ApiClient::parameterToString(*topMargin);
    }
    if (bottomMargin)
    {
        queryParams[utility::conversions::to_string_t("bottomMargin")] = ApiClient::parameterToString(*bottomMargin);
    }
    if (resolution)
    {
        queryParams[utility::conversions::to_string_t("resolution")] = ApiClient::parameterToString(*resolution);
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
        throw ApiException(415, utility::conversions::to_string_t("ConversionApi->getConvertDocumentToImageByUrl does not consume any supported media type"));
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
                , utility::conversions::to_string_t("error calling getConvertDocumentToImageByUrl: ") + response.reason_phrase()
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
pplx::task<HttpContent> ConversionApi::getConvertDocumentToPdf(utility::string_t name, boost::optional<int32_t> width, boost::optional<int32_t> height, boost::optional<int32_t> leftMargin, boost::optional<int32_t> rightMargin, boost::optional<int32_t> topMargin, boost::optional<int32_t> bottomMargin, boost::optional<utility::string_t> folder, boost::optional<utility::string_t> storage)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/html/{name}/convert/pdf");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("multipart/form-data") );

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

    if (width)
    {
        queryParams[utility::conversions::to_string_t("width")] = ApiClient::parameterToString(*width);
    }
    if (height)
    {
        queryParams[utility::conversions::to_string_t("height")] = ApiClient::parameterToString(*height);
    }
    if (leftMargin)
    {
        queryParams[utility::conversions::to_string_t("leftMargin")] = ApiClient::parameterToString(*leftMargin);
    }
    if (rightMargin)
    {
        queryParams[utility::conversions::to_string_t("rightMargin")] = ApiClient::parameterToString(*rightMargin);
    }
    if (topMargin)
    {
        queryParams[utility::conversions::to_string_t("topMargin")] = ApiClient::parameterToString(*topMargin);
    }
    if (bottomMargin)
    {
        queryParams[utility::conversions::to_string_t("bottomMargin")] = ApiClient::parameterToString(*bottomMargin);
    }
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
        throw ApiException(415, utility::conversions::to_string_t("ConversionApi->getConvertDocumentToPdf does not consume any supported media type"));
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
                , utility::conversions::to_string_t("error calling getConvertDocumentToPdf: ") + response.reason_phrase()
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
pplx::task<HttpContent> ConversionApi::getConvertDocumentToPdfByUrl(utility::string_t sourceUrl, boost::optional<int32_t> width, boost::optional<int32_t> height, boost::optional<int32_t> leftMargin, boost::optional<int32_t> rightMargin, boost::optional<int32_t> topMargin, boost::optional<int32_t> bottomMargin)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/html/convert/pdf");
    
    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("multipart/form-data") );

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

    {
        queryParams[utility::conversions::to_string_t("sourceUrl")] = ApiClient::parameterToString(sourceUrl);
    }
    if (width)
    {
        queryParams[utility::conversions::to_string_t("width")] = ApiClient::parameterToString(*width);
    }
    if (height)
    {
        queryParams[utility::conversions::to_string_t("height")] = ApiClient::parameterToString(*height);
    }
    if (leftMargin)
    {
        queryParams[utility::conversions::to_string_t("leftMargin")] = ApiClient::parameterToString(*leftMargin);
    }
    if (rightMargin)
    {
        queryParams[utility::conversions::to_string_t("rightMargin")] = ApiClient::parameterToString(*rightMargin);
    }
    if (topMargin)
    {
        queryParams[utility::conversions::to_string_t("topMargin")] = ApiClient::parameterToString(*topMargin);
    }
    if (bottomMargin)
    {
        queryParams[utility::conversions::to_string_t("bottomMargin")] = ApiClient::parameterToString(*bottomMargin);
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
        throw ApiException(415, utility::conversions::to_string_t("ConversionApi->getConvertDocumentToPdfByUrl does not consume any supported media type"));
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
                , utility::conversions::to_string_t("error calling getConvertDocumentToPdfByUrl: ") + response.reason_phrase()
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
pplx::task<HttpContent> ConversionApi::getConvertDocumentToXps(utility::string_t name, boost::optional<int32_t> width, boost::optional<int32_t> height, boost::optional<int32_t> leftMargin, boost::optional<int32_t> rightMargin, boost::optional<int32_t> topMargin, boost::optional<int32_t> bottomMargin, boost::optional<utility::string_t> folder, boost::optional<utility::string_t> storage)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/html/{name}/convert/xps");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(name));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("multipart/form-data") );

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

    if (width)
    {
        queryParams[utility::conversions::to_string_t("width")] = ApiClient::parameterToString(*width);
    }
    if (height)
    {
        queryParams[utility::conversions::to_string_t("height")] = ApiClient::parameterToString(*height);
    }
    if (leftMargin)
    {
        queryParams[utility::conversions::to_string_t("leftMargin")] = ApiClient::parameterToString(*leftMargin);
    }
    if (rightMargin)
    {
        queryParams[utility::conversions::to_string_t("rightMargin")] = ApiClient::parameterToString(*rightMargin);
    }
    if (topMargin)
    {
        queryParams[utility::conversions::to_string_t("topMargin")] = ApiClient::parameterToString(*topMargin);
    }
    if (bottomMargin)
    {
        queryParams[utility::conversions::to_string_t("bottomMargin")] = ApiClient::parameterToString(*bottomMargin);
    }
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
        throw ApiException(415, utility::conversions::to_string_t("ConversionApi->getConvertDocumentToXps does not consume any supported media type"));
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
                , utility::conversions::to_string_t("error calling getConvertDocumentToXps: ") + response.reason_phrase()
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
pplx::task<HttpContent> ConversionApi::getConvertDocumentToXpsByUrl(utility::string_t sourceUrl, boost::optional<int32_t> width, boost::optional<int32_t> height, boost::optional<int32_t> leftMargin, boost::optional<int32_t> rightMargin, boost::optional<int32_t> topMargin, boost::optional<int32_t> bottomMargin)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/html/convert/xps");
    
    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("multipart/form-data") );

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

    {
        queryParams[utility::conversions::to_string_t("sourceUrl")] = ApiClient::parameterToString(sourceUrl);
    }
    if (width)
    {
        queryParams[utility::conversions::to_string_t("width")] = ApiClient::parameterToString(*width);
    }
    if (height)
    {
        queryParams[utility::conversions::to_string_t("height")] = ApiClient::parameterToString(*height);
    }
    if (leftMargin)
    {
        queryParams[utility::conversions::to_string_t("leftMargin")] = ApiClient::parameterToString(*leftMargin);
    }
    if (rightMargin)
    {
        queryParams[utility::conversions::to_string_t("rightMargin")] = ApiClient::parameterToString(*rightMargin);
    }
    if (topMargin)
    {
        queryParams[utility::conversions::to_string_t("topMargin")] = ApiClient::parameterToString(*topMargin);
    }
    if (bottomMargin)
    {
        queryParams[utility::conversions::to_string_t("bottomMargin")] = ApiClient::parameterToString(*bottomMargin);
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
        throw ApiException(415, utility::conversions::to_string_t("ConversionApi->getConvertDocumentToXpsByUrl does not consume any supported media type"));
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
                , utility::conversions::to_string_t("error calling getConvertDocumentToXpsByUrl: ") + response.reason_phrase()
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

pplx::task<HttpContent> ConversionApi::putConvertDocumentInRequestToImage(utility::string_t outPath, utility::string_t outFormat, std::shared_ptr<HttpContent> file, boost::optional<int32_t> width, boost::optional<int32_t> height, boost::optional<int32_t> leftMargin, boost::optional<int32_t> rightMargin, boost::optional<int32_t> topMargin, boost::optional<int32_t> bottomMargin, boost::optional<int32_t> resolution)
{

	// verify the required parameter 'file' is set
	if (file == nullptr)
	{
		throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'file' when calling ConversionApi->putConvertDocumentInRequestToImage"));
	}


	std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
	utility::string_t path = utility::conversions::to_string_t("/html/convert/image/{outFormat}");
	boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("outFormat") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(outFormat));

	std::map<utility::string_t, utility::string_t> queryParams;
	std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
	std::map<utility::string_t, utility::string_t> formParams;
	std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

	std::unordered_set<utility::string_t> responseHttpContentTypes;
	responseHttpContentTypes.insert(utility::conversions::to_string_t("application/json"));

	utility::string_t responseHttpContentType;

	// use JSON if possible
	if (responseHttpContentTypes.size() == 0)
	{
		responseHttpContentType = utility::conversions::to_string_t("application/json");
	}
	// JSON
	else if (responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end())
	{
		responseHttpContentType = utility::conversions::to_string_t("application/json");
	}
	// multipart formdata
	else if (responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end())
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
	consumeHttpContentTypes.insert(utility::conversions::to_string_t("application/octet-stream"));

	queryParams[utility::conversions::to_string_t("outPath")] = ApiClient::parameterToString(outPath);

	if (width)
	{
		queryParams[utility::conversions::to_string_t("width")] = ApiClient::parameterToString(*width);
	}
	if (height)
	{
		queryParams[utility::conversions::to_string_t("height")] = ApiClient::parameterToString(*height);
	}
	if (leftMargin)
	{
		queryParams[utility::conversions::to_string_t("leftMargin")] = ApiClient::parameterToString(*leftMargin);
	}
	if (rightMargin)
	{
		queryParams[utility::conversions::to_string_t("rightMargin")] = ApiClient::parameterToString(*rightMargin);
	}
	if (topMargin)
	{
		queryParams[utility::conversions::to_string_t("topMargin")] = ApiClient::parameterToString(*topMargin);
	}
	if (bottomMargin)
	{
		queryParams[utility::conversions::to_string_t("bottomMargin")] = ApiClient::parameterToString(*bottomMargin);
	}
	if (resolution)
	{
		queryParams[utility::conversions::to_string_t("resolution")] = ApiClient::parameterToString(*resolution);
	}

	std::shared_ptr<OctetStreamBody> httpBody(new OctetStreamBody());
	httpBody->add(file);

	utility::string_t requestHttpContentType;

	// use JSON if possible
	if (consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end())
	{
		requestHttpContentType = utility::conversions::to_string_t("application/json");
	}
	// multipart formdata
	else if (consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end())
	{
		requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
	}
	// application/octet-stream 
	else if (consumeHttpContentTypes.find(utility::conversions::to_string_t("application/octet-stream")) != consumeHttpContentTypes.end())
	{
		requestHttpContentType = utility::conversions::to_string_t("application/octet-stream");
	}
	else
	{
		throw ApiException(415, utility::conversions::to_string_t("ConversionApi->putConvertDocumentInRequestToImage does not consume any supported media type"));
	}


	return m_ApiClient->callApi(path, utility::conversions::to_string_t("PUT"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
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
				, utility::conversions::to_string_t("error calling putConvertDocumentInRequestToImage: ") + response.reason_phrase()
				, std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
		}

		// check response content type
		if (response.headers().has(utility::conversions::to_string_t("Content-Type")))
		{
			utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
			if (contentType.find(responseHttpContentType) == std::string::npos)
			{
				throw ApiException(500
					, utility::conversions::to_string_t("error calling putConvertDocumentInRequestToImage: unexpected response type: ") + contentType
					, std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
			}
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
pplx::task<HttpContent> ConversionApi::putConvertDocumentInRequestToPdf(utility::string_t outPath, std::shared_ptr<HttpContent> file, boost::optional<int32_t> width, boost::optional<int32_t> height, boost::optional<int32_t> leftMargin, boost::optional<int32_t> rightMargin, boost::optional<int32_t> topMargin, boost::optional<int32_t> bottomMargin)
{

	// verify the required parameter 'file' is set
	if (file == nullptr)
	{
		throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'file' when calling ConversionApi->putConvertDocumentInRequestToPdf"));
	}


	std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
	utility::string_t path = utility::conversions::to_string_t("/html/convert/pdf");

	std::map<utility::string_t, utility::string_t> queryParams;
	std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
	std::map<utility::string_t, utility::string_t> formParams;
	std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

	std::unordered_set<utility::string_t> responseHttpContentTypes;
	responseHttpContentTypes.insert(utility::conversions::to_string_t("application/json"));

	utility::string_t responseHttpContentType;

	// use JSON if possible
	if (responseHttpContentTypes.size() == 0)
	{
		responseHttpContentType = utility::conversions::to_string_t("application/json");
	}
	// JSON
	else if (responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end())
	{
		responseHttpContentType = utility::conversions::to_string_t("application/json");
	}
	// multipart formdata
	else if (responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end())
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
	consumeHttpContentTypes.insert(utility::conversions::to_string_t("application/octet-stream"));

    queryParams[utility::conversions::to_string_t("outPath")] = ApiClient::parameterToString(outPath);

	if (width)
	{
		queryParams[utility::conversions::to_string_t("width")] = ApiClient::parameterToString(*width);
	}
	if (height)
	{
		queryParams[utility::conversions::to_string_t("height")] = ApiClient::parameterToString(*height);
	}
	if (leftMargin)
	{
		queryParams[utility::conversions::to_string_t("leftMargin")] = ApiClient::parameterToString(*leftMargin);
	}
	if (rightMargin)
	{
		queryParams[utility::conversions::to_string_t("rightMargin")] = ApiClient::parameterToString(*rightMargin);
	}
	if (topMargin)
	{
		queryParams[utility::conversions::to_string_t("topMargin")] = ApiClient::parameterToString(*topMargin);
	}
	if (bottomMargin)
	{
		queryParams[utility::conversions::to_string_t("bottomMargin")] = ApiClient::parameterToString(*bottomMargin);
	}

	std::shared_ptr<OctetStreamBody> httpBody(new OctetStreamBody());
	httpBody->add(file);

	utility::string_t requestHttpContentType;

	// use JSON if possible
	if (consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end())
	{
		requestHttpContentType = utility::conversions::to_string_t("application/json");
	}
	// multipart formdata
	else if (consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end())
	{
		requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
	}
	// application/octet-stream 
	else if (consumeHttpContentTypes.find(utility::conversions::to_string_t("application/octet-stream")) != consumeHttpContentTypes.end())
	{
		requestHttpContentType = utility::conversions::to_string_t("application/octet-stream");
	}
	else
	{
		throw ApiException(415, utility::conversions::to_string_t("ConversionApi->putConvertDocumentInRequestToImage does not consume any supported media type"));
	}


	return m_ApiClient->callApi(path, utility::conversions::to_string_t("PUT"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
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
				, utility::conversions::to_string_t("error calling putConvertDocumentInRequestToPdf: ") + response.reason_phrase()
				, std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
		}

		// check response content type
		if (response.headers().has(utility::conversions::to_string_t("Content-Type")))
		{
			utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
			if (contentType.find(responseHttpContentType) == std::string::npos)
			{
				throw ApiException(500
					, utility::conversions::to_string_t("error calling putConvertDocumentInRequestToPdf: unexpected response type: ") + contentType
					, std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
			}
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
pplx::task<HttpContent> ConversionApi::putConvertDocumentInRequestToXps(utility::string_t outPath, std::shared_ptr<HttpContent> file, boost::optional<int32_t> width, boost::optional<int32_t> height, boost::optional<int32_t> leftMargin, boost::optional<int32_t> rightMargin, boost::optional<int32_t> topMargin, boost::optional<int32_t> bottomMargin)
{

	// verify the required parameter 'file' is set
	if (file == nullptr)
	{
		throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'file' when calling ConversionApi->putConvertDocumentInRequestToXps"));
	}


	std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
	utility::string_t path = utility::conversions::to_string_t("/html/convert/xps");

	std::map<utility::string_t, utility::string_t> queryParams;
	std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
	std::map<utility::string_t, utility::string_t> formParams;
	std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

	std::unordered_set<utility::string_t> responseHttpContentTypes;
	responseHttpContentTypes.insert(utility::conversions::to_string_t("application/json"));

	utility::string_t responseHttpContentType;

	// use JSON if possible
	if (responseHttpContentTypes.size() == 0)
	{
		responseHttpContentType = utility::conversions::to_string_t("application/json");
	}
	// JSON
	else if (responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end())
	{
		responseHttpContentType = utility::conversions::to_string_t("application/json");
	}
	// multipart formdata
	else if (responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end())
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
	consumeHttpContentTypes.insert(utility::conversions::to_string_t("application/octet-stream"));

	queryParams[utility::conversions::to_string_t("outPath")] = ApiClient::parameterToString(outPath);

	if (width)
	{
		queryParams[utility::conversions::to_string_t("width")] = ApiClient::parameterToString(*width);
	}
	if (height)
	{
		queryParams[utility::conversions::to_string_t("height")] = ApiClient::parameterToString(*height);
	}
	if (leftMargin)
	{
		queryParams[utility::conversions::to_string_t("leftMargin")] = ApiClient::parameterToString(*leftMargin);
	}
	if (rightMargin)
	{
		queryParams[utility::conversions::to_string_t("rightMargin")] = ApiClient::parameterToString(*rightMargin);
	}
	if (topMargin)
	{
		queryParams[utility::conversions::to_string_t("topMargin")] = ApiClient::parameterToString(*topMargin);
	}
	if (bottomMargin)
	{
		queryParams[utility::conversions::to_string_t("bottomMargin")] = ApiClient::parameterToString(*bottomMargin);
	}

	std::shared_ptr<OctetStreamBody> httpBody(new OctetStreamBody());
	httpBody->add(file);

	utility::string_t requestHttpContentType;

	// use JSON if possible
	if (consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end())
	{
		requestHttpContentType = utility::conversions::to_string_t("application/json");
	}
	// multipart formdata
	else if (consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end())
	{
		requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
	}
	// application/octet-stream 
	else if (consumeHttpContentTypes.find(utility::conversions::to_string_t("application/octet-stream")) != consumeHttpContentTypes.end())
	{
		requestHttpContentType = utility::conversions::to_string_t("application/octet-stream");
	}
	else
	{
		throw ApiException(415, utility::conversions::to_string_t("ConversionApi->putConvertDocumentInRequestToImage does not consume any supported media type"));
	}

	return m_ApiClient->callApi(path, utility::conversions::to_string_t("PUT"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
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
				, utility::conversions::to_string_t("error calling putConvertDocumentInRequestToXps: ") + response.reason_phrase()
				, std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
		}

		// check response content type
		if (response.headers().has(utility::conversions::to_string_t("Content-Type")))
		{
			utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
			if (contentType.find(responseHttpContentType) == std::string::npos)
			{
				throw ApiException(500
					, utility::conversions::to_string_t("error calling putConvertDocumentInRequestToXps: unexpected response type: ") + contentType
					, std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
			}
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
pplx::task<HttpContent> ConversionApi::putConvertDocumentToImage(utility::string_t name, utility::string_t outPath, utility::string_t outFormat, boost::optional<int32_t> width, boost::optional<int32_t> height, boost::optional<int32_t> leftMargin, boost::optional<int32_t> rightMargin, boost::optional<int32_t> topMargin, boost::optional<int32_t> bottomMargin, boost::optional<int32_t> resolution, boost::optional<utility::string_t> folder, boost::optional<utility::string_t> storage)
{


	std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
	utility::string_t path = utility::conversions::to_string_t("/html/{name}/convert/image/{outFormat}");
	boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(name));
	boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("outFormat") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(outFormat));

	std::map<utility::string_t, utility::string_t> queryParams;
	std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
	std::map<utility::string_t, utility::string_t> formParams;
	std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

	std::unordered_set<utility::string_t> responseHttpContentTypes;
	responseHttpContentTypes.insert(utility::conversions::to_string_t("application/json"));

	utility::string_t responseHttpContentType;

	// use JSON if possible
	if (responseHttpContentTypes.size() == 0)
	{
		responseHttpContentType = utility::conversions::to_string_t("application/json");
	}
	// JSON
	else if (responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end())
	{
		responseHttpContentType = utility::conversions::to_string_t("application/json");
	}
	// multipart formdata
	else if (responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end())
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
	consumeHttpContentTypes.insert(utility::conversions::to_string_t("application/json"));

	{
		queryParams[utility::conversions::to_string_t("outPath")] = ApiClient::parameterToString(outPath);
	}
	if (width)
	{
		queryParams[utility::conversions::to_string_t("width")] = ApiClient::parameterToString(*width);
	}
	if (height)
	{
		queryParams[utility::conversions::to_string_t("height")] = ApiClient::parameterToString(*height);
	}
	if (leftMargin)
	{
		queryParams[utility::conversions::to_string_t("leftMargin")] = ApiClient::parameterToString(*leftMargin);
	}
	if (rightMargin)
	{
		queryParams[utility::conversions::to_string_t("rightMargin")] = ApiClient::parameterToString(*rightMargin);
	}
	if (topMargin)
	{
		queryParams[utility::conversions::to_string_t("topMargin")] = ApiClient::parameterToString(*topMargin);
	}
	if (bottomMargin)
	{
		queryParams[utility::conversions::to_string_t("bottomMargin")] = ApiClient::parameterToString(*bottomMargin);
	}
	if (resolution)
	{
		queryParams[utility::conversions::to_string_t("resolution")] = ApiClient::parameterToString(*resolution);
	}
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
	if (consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end())
	{
		requestHttpContentType = utility::conversions::to_string_t("application/json");
	}
	// multipart formdata
	else if (consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end())
	{
		requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
	}
	else
	{
		throw ApiException(415, utility::conversions::to_string_t("ConversionApi->putConvertDocumentToImage does not consume any supported media type"));
	}


	return m_ApiClient->callApi(path, utility::conversions::to_string_t("PUT"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
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
				, utility::conversions::to_string_t("error calling putConvertDocumentToImage: ") + response.reason_phrase()
				, std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
		}

		// check response content type
		if (response.headers().has(utility::conversions::to_string_t("Content-Type")))
		{
			utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
			if (contentType.find(responseHttpContentType) == std::string::npos)
			{
				throw ApiException(500
					, utility::conversions::to_string_t("error calling putConvertDocumentToImage: unexpected response type: ") + contentType
					, std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
			}
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
pplx::task<HttpContent> ConversionApi::putConvertDocumentToPdf(utility::string_t name, utility::string_t outPath, boost::optional<int32_t> width, boost::optional<int32_t> height, boost::optional<int32_t> leftMargin, boost::optional<int32_t> rightMargin, boost::optional<int32_t> topMargin, boost::optional<int32_t> bottomMargin, boost::optional<utility::string_t> folder, boost::optional<utility::string_t> storage)
{


	std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
	utility::string_t path = utility::conversions::to_string_t("/html/{name}/convert/pdf");
	boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(name));

	std::map<utility::string_t, utility::string_t> queryParams;
	std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
	std::map<utility::string_t, utility::string_t> formParams;
	std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

	std::unordered_set<utility::string_t> responseHttpContentTypes;
	responseHttpContentTypes.insert(utility::conversions::to_string_t("application/json"));

	utility::string_t responseHttpContentType;

	// use JSON if possible
	if (responseHttpContentTypes.size() == 0)
	{
		responseHttpContentType = utility::conversions::to_string_t("application/json");
	}
	// JSON
	else if (responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end())
	{
		responseHttpContentType = utility::conversions::to_string_t("application/json");
	}
	// multipart formdata
	else if (responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end())
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
	consumeHttpContentTypes.insert(utility::conversions::to_string_t("application/json"));

	{
		queryParams[utility::conversions::to_string_t("outPath")] = ApiClient::parameterToString(outPath);
	}
	if (width)
	{
		queryParams[utility::conversions::to_string_t("width")] = ApiClient::parameterToString(*width);
	}
	if (height)
	{
		queryParams[utility::conversions::to_string_t("height")] = ApiClient::parameterToString(*height);
	}
	if (leftMargin)
	{
		queryParams[utility::conversions::to_string_t("leftMargin")] = ApiClient::parameterToString(*leftMargin);
	}
	if (rightMargin)
	{
		queryParams[utility::conversions::to_string_t("rightMargin")] = ApiClient::parameterToString(*rightMargin);
	}
	if (topMargin)
	{
		queryParams[utility::conversions::to_string_t("topMargin")] = ApiClient::parameterToString(*topMargin);
	}
	if (bottomMargin)
	{
		queryParams[utility::conversions::to_string_t("bottomMargin")] = ApiClient::parameterToString(*bottomMargin);
	}
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
	if (consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end())
	{
		requestHttpContentType = utility::conversions::to_string_t("application/json");
	}
	// multipart formdata
	else if (consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end())
	{
		requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
	}
	else
	{
		throw ApiException(415, utility::conversions::to_string_t("ConversionApi->putConvertDocumentToPdf does not consume any supported media type"));
	}


	return m_ApiClient->callApi(path, utility::conversions::to_string_t("PUT"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
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
				, utility::conversions::to_string_t("error calling putConvertDocumentToPdf: ") + response.reason_phrase()
				, std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
		}

		// check response content type
		if (response.headers().has(utility::conversions::to_string_t("Content-Type")))
		{
			utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
			if (contentType.find(responseHttpContentType) == std::string::npos)
			{
				throw ApiException(500
					, utility::conversions::to_string_t("error calling putConvertDocumentToPdf: unexpected response type: ") + contentType
					, std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
			}
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
pplx::task<HttpContent> ConversionApi::putConvertDocumentToXps(utility::string_t name, utility::string_t outPath, boost::optional<int32_t> width, boost::optional<int32_t> height, boost::optional<int32_t> leftMargin, boost::optional<int32_t> rightMargin, boost::optional<int32_t> topMargin, boost::optional<int32_t> bottomMargin, boost::optional<utility::string_t> folder, boost::optional<utility::string_t> storage)
{


	std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
	utility::string_t path = utility::conversions::to_string_t("/html/{name}/convert/xps");
	boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(name));

	std::map<utility::string_t, utility::string_t> queryParams;
	std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
	std::map<utility::string_t, utility::string_t> formParams;
	std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

	std::unordered_set<utility::string_t> responseHttpContentTypes;
	responseHttpContentTypes.insert(utility::conversions::to_string_t("application/json"));

	utility::string_t responseHttpContentType;

	// use JSON if possible
	if (responseHttpContentTypes.size() == 0)
	{
		responseHttpContentType = utility::conversions::to_string_t("application/json");
	}
	// JSON
	else if (responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end())
	{
		responseHttpContentType = utility::conversions::to_string_t("application/json");
	}
	// multipart formdata
	else if (responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end())
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
	consumeHttpContentTypes.insert(utility::conversions::to_string_t("application/json"));

	queryParams[utility::conversions::to_string_t("outPath")] = ApiClient::parameterToString(outPath);

	if (width)
	{
		queryParams[utility::conversions::to_string_t("width")] = ApiClient::parameterToString(*width);
	}
	if (height)
	{
		queryParams[utility::conversions::to_string_t("height")] = ApiClient::parameterToString(*height);
	}
	if (leftMargin)
	{
		queryParams[utility::conversions::to_string_t("leftMargin")] = ApiClient::parameterToString(*leftMargin);
	}
	if (rightMargin)
	{
		queryParams[utility::conversions::to_string_t("rightMargin")] = ApiClient::parameterToString(*rightMargin);
	}
	if (topMargin)
	{
		queryParams[utility::conversions::to_string_t("topMargin")] = ApiClient::parameterToString(*topMargin);
	}
	if (bottomMargin)
	{
		queryParams[utility::conversions::to_string_t("bottomMargin")] = ApiClient::parameterToString(*bottomMargin);
	}
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
	if (consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end())
	{
		requestHttpContentType = utility::conversions::to_string_t("application/json");
	}
	// multipart formdata
	else if (consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end())
	{
		requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
	}
	else
	{
		throw ApiException(415, utility::conversions::to_string_t("ConversionApi->putConvertDocumentToXps does not consume any supported media type"));
	}
	return m_ApiClient->callApi(path, utility::conversions::to_string_t("PUT"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
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
				, utility::conversions::to_string_t("error calling putConvertDocumentToXps: ") + response.reason_phrase()
				, std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
		}

		// check response content type
		if (response.headers().has(utility::conversions::to_string_t("Content-Type")))
		{
			utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
			if (contentType.find(responseHttpContentType) == std::string::npos)
			{
				throw ApiException(500
					, utility::conversions::to_string_t("error calling putConvertDocumentToXps: unexpected response type: ") + contentType
					, std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
			}
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

pplx::task<HttpContent> ConversionApi::getConvertDocumentToMHTMLByUrl(utility::string_t sourceUrl)
{


	std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
	utility::string_t path = utility::conversions::to_string_t("/html/convert/mhtml");

	std::map<utility::string_t, utility::string_t> queryParams;
	std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
	std::map<utility::string_t, utility::string_t> formParams;
	std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

	std::unordered_set<utility::string_t> responseHttpContentTypes;
	responseHttpContentTypes.insert(utility::conversions::to_string_t("multipart/form-data"));

	utility::string_t responseHttpContentType;

	// use JSON if possible
	if (responseHttpContentTypes.size() == 0)
	{
		responseHttpContentType = utility::conversions::to_string_t("application/json");
	}
	// JSON
	else if (responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end())
	{
		responseHttpContentType = utility::conversions::to_string_t("application/json");
	}
	// multipart formdata
	else if (responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end())
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
	consumeHttpContentTypes.insert(utility::conversions::to_string_t("application/json"));

	{
		queryParams[utility::conversions::to_string_t("sourceUrl")] = ApiClient::parameterToString(sourceUrl);
	}

	std::shared_ptr<IHttpBody> httpBody;
	utility::string_t requestHttpContentType;

	// use JSON if possible
	if (consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end())
	{
		requestHttpContentType = utility::conversions::to_string_t("application/json");
	}
	// multipart formdata
	else if (consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end())
	{
		requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
	}
	else
	{
		throw ApiException(415, utility::conversions::to_string_t("ConversionApi->getConvertDocumentToMHTMLByUrl does not consume any supported media type"));
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
				, utility::conversions::to_string_t("error calling getConvertDocumentToMHTMLByUrl: ") + response.reason_phrase()
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

pplx::task<HttpContent> ConversionApi::getConvertDocumentToMarkdown(
	utility::string_t name,
	boost::optional<bool> useGit,
	boost::optional<utility::string_t> folder,
	boost::optional<utility::string_t> storage)
{
	std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
	utility::string_t path = utility::conversions::to_string_t("/html/{name}/convert/md");
	boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(name));

	std::map<utility::string_t, utility::string_t> queryParams;
	std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
	std::map<utility::string_t, utility::string_t> formParams;
	std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

	std::unordered_set<utility::string_t> responseHttpContentTypes;
	responseHttpContentTypes.insert(utility::conversions::to_string_t("application/json"));

	utility::string_t responseHttpContentType;

	// use JSON if possible
	if (responseHttpContentTypes.size() == 0)
	{
		responseHttpContentType = utility::conversions::to_string_t("application/json");
	}
	// JSON
	else if (responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end())
	{
		responseHttpContentType = utility::conversions::to_string_t("application/json");
	}
	// multipart formdata
	else if (responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end())
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
	consumeHttpContentTypes.insert(utility::conversions::to_string_t("application/json"));

	if (useGit == true)
	{
		queryParams[utility::conversions::to_string_t("useGit")] = utility::conversions::to_string_t("true");
	}
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
	if (consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end())
	{
		requestHttpContentType = utility::conversions::to_string_t("application/json");
	}
	// multipart formdata
	else if (consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end())
	{
		requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
	}
	else
	{
		throw ApiException(415, utility::conversions::to_string_t("ConversionApi->GetConvertDocumentToMarkdown does not consume any supported media type"));
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
				, utility::conversions::to_string_t("error calling GetConvertDocumentToMarkdown: ") + response.reason_phrase()
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

pplx::task<HttpContent> ConversionApi::putConvertDocumentToMarkdown(utility::string_t name, utility::string_t outPath, boost::optional<bool> useGit, boost::optional<utility::string_t> folder, boost::optional<utility::string_t> storage)
{
	std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
	utility::string_t path = utility::conversions::to_string_t("/html/{name}/convert/md");
	boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(name));

	std::map<utility::string_t, utility::string_t> queryParams;
	std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
	std::map<utility::string_t, utility::string_t> formParams;
	std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

	std::unordered_set<utility::string_t> responseHttpContentTypes;
	responseHttpContentTypes.insert(utility::conversions::to_string_t("application/json"));

	utility::string_t responseHttpContentType;

	// use JSON if possible
	if (responseHttpContentTypes.size() == 0)
	{
		responseHttpContentType = utility::conversions::to_string_t("application/json");
	}
	// JSON
	else if (responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end())
	{
		responseHttpContentType = utility::conversions::to_string_t("application/json");
	}
	// multipart formdata
	else if (responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end())
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
	consumeHttpContentTypes.insert(utility::conversions::to_string_t("application/json"));

	queryParams[utility::conversions::to_string_t("outPath")] = ApiClient::parameterToString(outPath);

	if (useGit == true)
	{
		queryParams[utility::conversions::to_string_t("useGit")] = utility::conversions::to_string_t("true");
	}
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
	if (consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end())
	{
		requestHttpContentType = utility::conversions::to_string_t("application/json");
	}
	// multipart formdata
	else if (consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end())
	{
		requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
	}
	else
	{
		throw ApiException(415, utility::conversions::to_string_t("ConversionApi->PutConvertDocumentToMarkdown does not consume any supported media type"));
	}
	return m_ApiClient->callApi(path, utility::conversions::to_string_t("PUT"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
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
				, utility::conversions::to_string_t("error calling PutConvertDocumentToMarkdown: ") + response.reason_phrase()
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

pplx::task<HttpContent> ConversionApi::putConvertDocumentInRequestToMarkdown(utility::string_t outPath, std::shared_ptr<HttpContent> file, boost::optional<bool> useGit)
{
	// verify the required parameter 'file' is set
	if (file == nullptr)
	{
		throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'file' when calling ConversionApi->PutConvertDocumentInRequestToMarkdown"));
	}

	std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
	utility::string_t path = utility::conversions::to_string_t("/html/convert/md");

	std::map<utility::string_t, utility::string_t> queryParams;
	std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
	std::map<utility::string_t, utility::string_t> formParams;
	std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

	std::unordered_set<utility::string_t> responseHttpContentTypes;
	responseHttpContentTypes.insert(utility::conversions::to_string_t("application/json"));

	utility::string_t responseHttpContentType;

	// use JSON if possible
	if (responseHttpContentTypes.size() == 0)
	{
		responseHttpContentType = utility::conversions::to_string_t("application/json");
	}
	// JSON
	else if (responseHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != responseHttpContentTypes.end())
	{
		responseHttpContentType = utility::conversions::to_string_t("application/json");
	}
	// multipart formdata
	else if (responseHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != responseHttpContentTypes.end())
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
	consumeHttpContentTypes.insert(utility::conversions::to_string_t("multipart/form-data"));

	queryParams[utility::conversions::to_string_t("outPath")] = ApiClient::parameterToString(outPath);

//	if (file != nullptr)
//	{
//		fileParams[utility::conversions::to_string_t("file")] = file;
//	}
	if (useGit == true)
	{
		queryParams[utility::conversions::to_string_t("useGit")] = utility::conversions::to_string_t("true");
	}

	std::shared_ptr<OctetStreamBody> httpBody(new OctetStreamBody());
	httpBody->add(file);

	utility::string_t requestHttpContentType;

	// use JSON if possible
	if (consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(utility::conversions::to_string_t("application/json")) != consumeHttpContentTypes.end())
	{
		requestHttpContentType = utility::conversions::to_string_t("application/json");
	}
	// multipart formdata
	else if (consumeHttpContentTypes.find(utility::conversions::to_string_t("multipart/form-data")) != consumeHttpContentTypes.end())
	{
		requestHttpContentType = utility::conversions::to_string_t("multipart/form-data");
	}
	else
	{
		throw ApiException(415, utility::conversions::to_string_t("ConversionApi->PutConvertDocumentInRequestToMarkdown does not consume any supported media type"));
	}
	return m_ApiClient->callApi(path, utility::conversions::to_string_t("PUT"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
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
				, utility::conversions::to_string_t("error calling PutConvertDocumentInRequestToMarkdown: ") + response.reason_phrase()
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
