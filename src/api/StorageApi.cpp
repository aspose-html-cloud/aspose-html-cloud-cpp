/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="StorageApi.cpp">
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


#include "api/StorageApi.h"
#include "IHttpBody.h"
#include "JsonBody.h"
#include "OctetStreamBody.h"
#include <unordered_set>
#include <boost/algorithm/string/replace.hpp>


namespace com {
namespace aspose {
namespace api {

using namespace com::aspose::model;

StorageApi::StorageApi( std::shared_ptr<ApiClient> apiClient )
    : m_ApiClient(apiClient)
{
}

StorageApi::~StorageApi()
{
}

pplx::task<std::shared_ptr<DiscUsageResponse>> StorageApi::getDiscUsage(boost::optional<utility::string_t> storage)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/storage/disc");
    
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
        throw ApiException(400, utility::conversions::to_string_t("StorageApi->getDiscUsage does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

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
        throw ApiException(415, utility::conversions::to_string_t("StorageApi->getDiscUsage does not consume any supported media type"));
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
                , utility::conversions::to_string_t("error calling getDiscUsage: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getDiscUsage: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<DiscUsageResponse> result(new DiscUsageResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getDiscUsage: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<FileExistResponse>> StorageApi::getIsExist(utility::string_t path_to_storage, boost::optional<utility::string_t> versionId, boost::optional<utility::string_t> storage)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/storage/exist");
    
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
        throw ApiException(400, utility::conversions::to_string_t("StorageApi->getIsExist does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    {
        queryParams[utility::conversions::to_string_t("path")] = ApiClient::parameterToString(path_to_storage);
    }
    if (versionId)
    {
        queryParams[utility::conversions::to_string_t("versionId")] = ApiClient::parameterToString(*versionId);
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
        throw ApiException(415, utility::conversions::to_string_t("StorageApi->getIsExist does not consume any supported media type"));
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
                , utility::conversions::to_string_t("error calling getIsExist: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getIsExist: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<FileExistResponse> result(new FileExistResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getIsExist: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<StorageExistResponse>> StorageApi::getIsStorageExist(utility::string_t name)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/storage/{name}/exist");
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
        throw ApiException(400, utility::conversions::to_string_t("StorageApi->getIsStorageExist does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );


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
        throw ApiException(415, utility::conversions::to_string_t("StorageApi->getIsStorageExist does not consume any supported media type"));
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
                , utility::conversions::to_string_t("error calling getIsStorageExist: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getIsStorageExist: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<StorageExistResponse> result(new StorageExistResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getIsStorageExist: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<FileVersionsResponse>> StorageApi::getListFileVersions(utility::string_t path_to_file, boost::optional<utility::string_t> storage)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/storage/version");
    
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
        throw ApiException(400, utility::conversions::to_string_t("StorageApi->getListFileVersions does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    {
        queryParams[utility::conversions::to_string_t("path")] = ApiClient::parameterToString(path_to_file);
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
        throw ApiException(415, utility::conversions::to_string_t("StorageApi->getListFileVersions does not consume any supported media type"));
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
                , utility::conversions::to_string_t("error calling getListFileVersions: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getListFileVersions: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<FileVersionsResponse> result(new FileVersionsResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getListFileVersions: unsupported response type"));
        }

        return result;
    });
}

pplx::task<std::shared_ptr<MessageResponse>> StorageApi::deleteFile(utility::string_t path_to_file, boost::optional<utility::string_t> versionId, boost::optional<utility::string_t> storage)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/storage/file");
    
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
        throw ApiException(400, utility::conversions::to_string_t("StorageApi->deleteFile does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    {
        queryParams[utility::conversions::to_string_t("path")] = ApiClient::parameterToString(path_to_file);
    }
    if (versionId)
    {
        queryParams[utility::conversions::to_string_t("versionId")] = ApiClient::parameterToString(*versionId);
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
        throw ApiException(415, utility::conversions::to_string_t("StorageApi->deleteFile does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
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
                , utility::conversions::to_string_t("error calling deleteFile: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling deleteFile: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<MessageResponse> result(new MessageResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling deleteFile: unsupported response type"));
        }

        return result;
    });
}
pplx::task<HttpContent> StorageApi::getDownload(utility::string_t path_to_file, boost::optional<utility::string_t> versionId, boost::optional<utility::string_t> storage)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/storage/file");
    
    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("multipart/form-data") );

    utility::string_t responseHttpContentType;

    responseHttpContentType = utility::conversions::to_string_t("application/octet-stream");

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    {
        queryParams[utility::conversions::to_string_t("path")] = ApiClient::parameterToString(path_to_file);
    }
    if (versionId)
    {
        queryParams[utility::conversions::to_string_t("versionId")] = ApiClient::parameterToString(*versionId);
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
        throw ApiException(415, utility::conversions::to_string_t("StorageApi->getDownload does not consume any supported media type"));
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
                , utility::conversions::to_string_t("error calling getDownload: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getDownload: unexpected response type: ") + contentType
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
pplx::task<std::shared_ptr<MessageResponse>> StorageApi::postMoveFile(utility::string_t src, utility::string_t dest, boost::optional<utility::string_t> versionId, boost::optional<utility::string_t> storage, boost::optional<utility::string_t> destStorage)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/storage/file");
    
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
        throw ApiException(400, utility::conversions::to_string_t("StorageApi->postMoveFile does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("multipart/form-data") );

    {
        queryParams[utility::conversions::to_string_t("src")] = ApiClient::parameterToString(src);
    }
    {
        queryParams[utility::conversions::to_string_t("dest")] = ApiClient::parameterToString(dest);
    }
    if (versionId)
    {
        queryParams[utility::conversions::to_string_t("versionId")] = ApiClient::parameterToString(*versionId);
    }
    if (storage)
    {
        queryParams[utility::conversions::to_string_t("storage")] = ApiClient::parameterToString(*storage);
    }
    if (destStorage)
    {
        queryParams[utility::conversions::to_string_t("destStorage")] = ApiClient::parameterToString(*destStorage);
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
        throw ApiException(415, utility::conversions::to_string_t("StorageApi->postMoveFile does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("POST"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
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
                , utility::conversions::to_string_t("error calling postMoveFile: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling postMoveFile: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<MessageResponse> result(new MessageResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling postMoveFile: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<MessageResponse>> StorageApi::putCreate(utility::string_t path_to_file, std::shared_ptr<HttpContent> file, boost::optional<utility::string_t> versionId, boost::optional<utility::string_t> storage)
{

    // verify the required parameter 'file' is set
    if (file == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'file' when calling StorageApi->putCreate"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/storage/file");
    
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
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/octet-stream") );

    queryParams[utility::conversions::to_string_t("path")] = ApiClient::parameterToString(path_to_file);
 
	if (versionId)
    {
        queryParams[utility::conversions::to_string_t("versionId")] = ApiClient::parameterToString(*versionId);
    }
    if (storage)
    {
        queryParams[utility::conversions::to_string_t("storage")] = ApiClient::parameterToString(*storage);
    }


	std::shared_ptr<OctetStreamBody> httpBody(new OctetStreamBody());
	httpBody->add(file);
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
	// application/octet-stream 
	else if (consumeHttpContentTypes.find(utility::conversions::to_string_t("application/octet-stream")) != consumeHttpContentTypes.end())
	{
		requestHttpContentType = utility::conversions::to_string_t("application/octet-stream");
	}
	else
    {
        throw ApiException(415, utility::conversions::to_string_t("StorageApi->putCreate does not consume any supported media type"));
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
                , utility::conversions::to_string_t("error calling putCreate: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling putCreate: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
		std::shared_ptr<MessageResponse> result(new MessageResponse());

		if (responseHttpContentType == utility::conversions::to_string_t("application/json"))
		{
			web::json::value json = web::json::value::parse(response);

			result->fromJson(json);
		}
		else
		{
			throw ApiException(500
				, utility::conversions::to_string_t("error calling putCreate: unsupported response type"));
		}

		return result;
	});
}

pplx::task<std::shared_ptr<MessageResponse>> StorageApi::deleteFolder(utility::string_t path_to_folder, boost::optional<utility::string_t> storage, boost::optional<bool> recursive)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/storage/folder");
    
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
        throw ApiException(400, utility::conversions::to_string_t("StorageApi->deleteFolder does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    {
        queryParams[utility::conversions::to_string_t("path")] = ApiClient::parameterToString(path_to_folder);
    }
    if (storage)
    {
        queryParams[utility::conversions::to_string_t("storage")] = ApiClient::parameterToString(*storage);
    }
    if (recursive)
    {
        queryParams[utility::conversions::to_string_t("recursive")] = ApiClient::parameterToString(*recursive);
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
        throw ApiException(415, utility::conversions::to_string_t("StorageApi->deleteFolder does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
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
                , utility::conversions::to_string_t("error calling deleteFolder: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling deleteFolder: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<MessageResponse> result(new MessageResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling deleteFolder: unsupported response type"));
        }

        return result;
    });
}
pplx::task<HttpContent> StorageApi::getListFiles(boost::optional<utility::string_t> path_to_folder, boost::optional<utility::string_t> storage)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/storage/folder");
    
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

    if (path_to_folder)
    {
        queryParams[utility::conversions::to_string_t("path")] = ApiClient::parameterToString(*path_to_folder);
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
        throw ApiException(415, utility::conversions::to_string_t("StorageApi->getListFiles does not consume any supported media type"));
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
                , utility::conversions::to_string_t("error calling getListFiles: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getListFiles: unexpected response type: ") + contentType
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
pplx::task<std::shared_ptr<MessageResponse>> StorageApi::postMoveFolder(utility::string_t src, utility::string_t dest, boost::optional<utility::string_t> storage, boost::optional<utility::string_t> destStorage)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/storage/folder");
    
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
        throw ApiException(400, utility::conversions::to_string_t("StorageApi->postMoveFolder does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    {
        queryParams[utility::conversions::to_string_t("src")] = ApiClient::parameterToString(src);
    }
    {
        queryParams[utility::conversions::to_string_t("dest")] = ApiClient::parameterToString(dest);
    }
    if (storage)
    {
        queryParams[utility::conversions::to_string_t("storage")] = ApiClient::parameterToString(*storage);
    }
    if (destStorage)
    {
        queryParams[utility::conversions::to_string_t("destStorage")] = ApiClient::parameterToString(*destStorage);
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
        throw ApiException(415, utility::conversions::to_string_t("StorageApi->postMoveFolder does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("POST"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
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
                , utility::conversions::to_string_t("error calling postMoveFolder: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling postMoveFolder: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<MessageResponse> result(new MessageResponse());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling postMoveFolder: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<MessageResponse>> StorageApi::putCreateFolder(utility::string_t path_to_folder, boost::optional<utility::string_t> storage, boost::optional<utility::string_t> destStorage)
{


    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/storage/folder");
    
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

    {
        queryParams[utility::conversions::to_string_t("path")] = ApiClient::parameterToString(path_to_folder);
    }
    if (storage)
    {
        queryParams[utility::conversions::to_string_t("storage")] = ApiClient::parameterToString(*storage);
    }
    if (destStorage)
    {
        queryParams[utility::conversions::to_string_t("destStorage")] = ApiClient::parameterToString(*destStorage);
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
        throw ApiException(415, utility::conversions::to_string_t("StorageApi->putCreateFolder does not consume any supported media type"));
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
                , utility::conversions::to_string_t("error calling putCreateFolder: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling putCreateFolder: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
		std::shared_ptr<MessageResponse> result(new MessageResponse());

		if (responseHttpContentType == utility::conversions::to_string_t("application/json"))
		{
			web::json::value json = web::json::value::parse(response);

			result->fromJson(json);
		}
		else
		{
			throw ApiException(500
				, utility::conversions::to_string_t("error calling postMoveFolder: unsupported response type"));
		}

		return result;
    });
}


}
}
}
