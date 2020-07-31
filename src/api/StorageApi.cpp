/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="StorageApi.cpp">
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

StorageApi::StorageApi( std::shared_ptr<ApiClient> apiClient ) : m_ApiClient(apiClient)
{
}

StorageApi::~StorageApi()
{
}

pplx::task<std::shared_ptr<DiscUsage>> StorageApi::getDiscUsage(boost::optional<utility::string_t> storageName)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/html/storage/disc");
    
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

    if (storageName)
    {
        queryParams[utility::conversions::to_string_t("storageName")] = ApiClient::parameterToString(*storageName);
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
        // 2xx - successful    : OK
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
        std::shared_ptr<DiscUsage> result(new DiscUsage());

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

pplx::task<std::shared_ptr<ObjectExist>> StorageApi::objectExists(utility::string_t path_to_object, boost::optional<utility::string_t> versionId, boost::optional<utility::string_t> storageName)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t path = utility::conversions::to_string_t("/html/storage/exist/{path}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("path") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(path_to_object));

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
        throw ApiException(400, utility::conversions::to_string_t("StorageApi->objectExists does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(utility::conversions::to_string_t("application/json"));

    if (storageName)
    {
        queryParams[utility::conversions::to_string_t("storageName")] = ApiClient::parameterToString(*storageName);
    }
    if (versionId)
    {
        queryParams[utility::conversions::to_string_t("versionId")] = ApiClient::parameterToString(*versionId);
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
        throw ApiException(415, utility::conversions::to_string_t("StorageApi->objectExists does not consume any supported media type"));
    }

    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful    : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling objectExists: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling objectExists: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<ObjectExist> result(new ObjectExist());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling objectExists: unsupported response type"));
        }

        return result;
    });
}

pplx::task<std::shared_ptr<StorageExist>> StorageApi::storageExists(utility::string_t storageName)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = utility::conversions::to_string_t("/html/storage/{name}/exist");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("name") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(storageName));

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
        throw ApiException(400, utility::conversions::to_string_t("StorageApi->storageExists does not produce any supported media type"));
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
        throw ApiException(415, utility::conversions::to_string_t("StorageApi->storageExists does not consume any supported media type"));
    }

    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful    : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling storageExists: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling storageExists: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<StorageExist> result(new StorageExist());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling storageExists: unsupported response type"));
        }

        return result;
    });
}

pplx::task<std::shared_ptr<FileVersions>> StorageApi::getFileVersions(utility::string_t path_to_file, boost::optional<utility::string_t> storageName)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t path = utility::conversions::to_string_t("/html/storage/version/{path}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("path") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(path_to_file));

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
        throw ApiException(400, utility::conversions::to_string_t("StorageApi->getFileVersions does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(utility::conversions::to_string_t("application/json"));

    if (storageName)
    {
        queryParams[utility::conversions::to_string_t("storageName")] = ApiClient::parameterToString(*storageName);
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
        throw ApiException(415, utility::conversions::to_string_t("StorageApi->getFileVersions does not consume any supported media type"));
    }

    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful    : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getFileVersions: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getFileVersions: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<FileVersions> result(new FileVersions());

        if(responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getFileVersions: unsupported response type"));
        }

        return result;
    });
}

pplx::task<std::shared_ptr<MessageResponse>> StorageApi::deleteFile(utility::string_t path_to_file, boost::optional<utility::string_t> versionId, boost::optional<utility::string_t> storageName)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t path = utility::conversions::to_string_t("/html/storage/file/{path}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("path") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(path_to_file));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
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

    if (versionId)
    {
        queryParams[utility::conversions::to_string_t("versionId")] = ApiClient::parameterToString(*versionId);
    }
    if (storageName)
    {
        queryParams[utility::conversions::to_string_t("storageName")] = ApiClient::parameterToString(*storageName);
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
        // 2xx - successful    : OK
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
        if (response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if (contentType.find(responseHttpContentType) == std::string::npos)
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling deleteFile: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        std::shared_ptr<MessageResponse> result(new MessageResponse());

        result->setCode(response.status_code());
        result->setStatus(response.reason_phrase());

        return result;
    });
}

pplx::task<HttpContent> StorageApi::downloadFile(utility::string_t path_to_file, boost::optional<utility::string_t> versionId, boost::optional<utility::string_t> storageName)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t path = utility::conversions::to_string_t("/html/storage/file/{path}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("path") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(path_to_file));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( utility::conversions::to_string_t("multipart/form-data") );

    utility::string_t responseHttpContentType;
    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("application/json") );

    if (versionId)
    {
        queryParams[utility::conversions::to_string_t("versionId")] = ApiClient::parameterToString(*versionId);
    }
    if (storageName)
    {
        queryParams[utility::conversions::to_string_t("storageName")] = ApiClient::parameterToString(*storageName);
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
        throw ApiException(415, utility::conversions::to_string_t("StorageApi->downloadFile does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful    : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling downloadFile: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling downloadFile: unexpected response type: ") + contentType
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

pplx::task<std::shared_ptr<MessageResponse>> StorageApi::copyFile(utility::string_t srcPath, utility::string_t destPath, boost::optional<utility::string_t> versionId, boost::optional<utility::string_t> srcStorageName, boost::optional<utility::string_t> destStorageName)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t path = utility::conversions::to_string_t("/html/storage/file/copy/{srcPath}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("srcPath") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(srcPath));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(utility::conversions::to_string_t("application/json"));

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
        throw ApiException(400, utility::conversions::to_string_t("StorageApi->copyFile does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("multipart/form-data") );

    queryParams[utility::conversions::to_string_t("destPath")] = ApiClient::parameterToString(destPath);

    if (srcStorageName)
    {
        queryParams[utility::conversions::to_string_t("srcStorageName")] = ApiClient::parameterToString(*srcStorageName);
    }
    if (destStorageName)
    {
        queryParams[utility::conversions::to_string_t("destStorageName")] = ApiClient::parameterToString(*destStorageName);
    }
    if (versionId)
    {
        queryParams[utility::conversions::to_string_t("versionId")] = ApiClient::parameterToString(*versionId);
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
        throw ApiException(415, utility::conversions::to_string_t("StorageApi->copyFile does not consume any supported media type"));
    }

    return m_ApiClient->callApi(path, utility::conversions::to_string_t("PUT"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful    : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling copyFile: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling copyFile: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }
        std::shared_ptr<MessageResponse> result(new MessageResponse());

        result->setCode(response.status_code());
        result->setStatus(response.reason_phrase());

        return result;
    });
}

pplx::task<std::shared_ptr<MessageResponse>> StorageApi::moveFile(utility::string_t srcPath, utility::string_t destPath, boost::optional<utility::string_t> versionId, boost::optional<utility::string_t> srcStorageName, boost::optional<utility::string_t> destStorageName)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t path = utility::conversions::to_string_t("/html/storage/file/move/{srcPath}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("srcPath") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(srcPath));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(utility::conversions::to_string_t("application/json"));

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
        throw ApiException(400, utility::conversions::to_string_t("StorageApi->moveFile does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("multipart/form-data") );

    queryParams[utility::conversions::to_string_t("destPath")] = ApiClient::parameterToString(destPath);

    if (srcStorageName)
    {
        queryParams[utility::conversions::to_string_t("srcStorageName")] = ApiClient::parameterToString(*srcStorageName);
    }
    if (destStorageName)
    {
        queryParams[utility::conversions::to_string_t("destStorageName")] = ApiClient::parameterToString(*destStorageName);
    }
    if (versionId)
    {
        queryParams[utility::conversions::to_string_t("versionId")] = ApiClient::parameterToString(*versionId);
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
        throw ApiException(415, utility::conversions::to_string_t("StorageApi->moveFile does not consume any supported media type"));
    }

    return m_ApiClient->callApi(path, utility::conversions::to_string_t("PUT"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful    : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling moveFile: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling moveFile: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }
        std::shared_ptr<MessageResponse> result(new MessageResponse());

        result->setCode(response.status_code());
        result->setStatus(response.reason_phrase());

        return result;
    });
}

pplx::task<std::shared_ptr<FilesUploadResult>> StorageApi::uploadFile(utility::string_t path_to_file, std::shared_ptr<HttpContent> file, boost::optional<utility::string_t> storageName)
{
    // verify the required parameter 'file' is set
    if (file == nullptr)
    {
        throw ApiException(400, utility::conversions::to_string_t("Missing required parameter 'file' when calling StorageApi->uploadFile"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t path = utility::conversions::to_string_t("/html/storage/file/{path}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("path") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(path_to_file));

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
    consumeHttpContentTypes.insert( utility::conversions::to_string_t("multipart/form-data") );
 
    fileParams[utility::conversions::to_string_t("file")] = file;

    if (storageName)
    {
        queryParams[utility::conversions::to_string_t("storageName")] = ApiClient::parameterToString(*storageName);
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
        throw ApiException(415, utility::conversions::to_string_t("StorageApi->uploadFile does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, utility::conversions::to_string_t("PUT"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful    : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling uploadFile: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling uploadFile: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
		std::shared_ptr<FilesUploadResult> result(new FilesUploadResult());

		if (responseHttpContentType == utility::conversions::to_string_t("application/json"))
		{
			web::json::value json = web::json::value::parse(response);

			result->fromJson(json);
		}
		else
		{
			throw ApiException(500
				, utility::conversions::to_string_t("error calling uploadFile: unsupported response type"));
		}

		return result;
	});
}

pplx::task<std::shared_ptr<MessageResponse>> StorageApi::deleteFolder(utility::string_t path_to_folder, boost::optional<utility::string_t> storageName, boost::optional<bool> recursive)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t path = utility::conversions::to_string_t("/html/storage/folder/{path}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("path") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(path_to_folder));

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
        throw ApiException(400, utility::conversions::to_string_t("StorageApi->deleteFolder does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(utility::conversions::to_string_t("application/json"));

    if (storageName)
    {
        queryParams[utility::conversions::to_string_t("storageName")] = ApiClient::parameterToString(*storageName);
    }
    if (recursive && ApiClient::parameterToString(*recursive) == utility::conversions::to_string_t("1"))
    {
        queryParams[utility::conversions::to_string_t("recursive")] = utility::conversions::to_string_t("true");
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
        throw ApiException(415, utility::conversions::to_string_t("StorageApi->deleteFolder does not consume any supported media type"));
    }

    return m_ApiClient->callApi(path, utility::conversions::to_string_t("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful    : OK
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
        if (response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if (contentType.find(responseHttpContentType) == std::string::npos)
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling deleteFolder: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        std::shared_ptr<MessageResponse> result(new MessageResponse());
        result->setCode(response.status_code());
        result->setStatus(response.reason_phrase());

        return result;
    });
}

pplx::task<std::shared_ptr<FilesList>> StorageApi::getFilesList(utility::string_t path_to_folder, boost::optional<utility::string_t> storageName)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t path = utility::conversions::to_string_t("/html/storage/folder/{path}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("path") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(path_to_folder));

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
        throw ApiException(400, utility::conversions::to_string_t("StorageApi->getFilesList does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(utility::conversions::to_string_t("application/json"));

    if (storageName)
    {
        queryParams[utility::conversions::to_string_t("storageName")] = ApiClient::parameterToString(*storageName);
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
        throw ApiException(415, utility::conversions::to_string_t("StorageApi->getFilesList does not consume any supported media type"));
    }

    return m_ApiClient->callApi(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful    : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling getFilesList: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if(response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling getFilesList: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<FilesList> result(new FilesList());

        if (responseHttpContentType == utility::conversions::to_string_t("application/json"))
        {
            web::json::value json = web::json::value::parse(response);

            result->fromJson(json);
        }
        // else if(responseHttpContentType == utility::conversions::to_string_t("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , utility::conversions::to_string_t("error calling getFilesList: unsupported response type"));
        }

        return result;
    });
}

pplx::task<std::shared_ptr<MessageResponse>> StorageApi::copyFolder(utility::string_t srcPath, utility::string_t destPath, boost::optional<utility::string_t> srcStorageName, boost::optional<utility::string_t> destStorageName)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t path = utility::conversions::to_string_t("/html/storage/folder/copy/{srcPath}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("srcPath") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(srcPath));

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
        throw ApiException(400, utility::conversions::to_string_t("StorageApi->copyFolder does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(utility::conversions::to_string_t("application/json"));

    queryParams[utility::conversions::to_string_t("destPath")] = ApiClient::parameterToString(destPath);

    if (srcStorageName)
    {
        queryParams[utility::conversions::to_string_t("srcStorageName")] = ApiClient::parameterToString(*srcStorageName);
    }
    if (destStorageName)
    {
        queryParams[utility::conversions::to_string_t("destStorageName")] = ApiClient::parameterToString(*destStorageName);
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
        throw ApiException(415, utility::conversions::to_string_t("FolderApi->copyFolder does not consume any supported media type"));
    }

    return m_ApiClient->callApi(path, utility::conversions::to_string_t("PUT"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful    : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling copyFolder: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if (response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if (contentType.find(responseHttpContentType) == std::string::npos)
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling copyFolder: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        std::shared_ptr<MessageResponse> result(new MessageResponse());
        result->setCode(response.status_code());
        result->setStatus(response.reason_phrase());

        return result;
    });
}

pplx::task<std::shared_ptr<MessageResponse>> StorageApi::moveFolder(utility::string_t srcPath, utility::string_t destPath, boost::optional<utility::string_t> srcStorageName, boost::optional<utility::string_t> destStorageName)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t path = utility::conversions::to_string_t("/html/storage/folder/move/{srcPath}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("srcPath") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(srcPath));

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
        throw ApiException(400, utility::conversions::to_string_t("StorageApi->moveFolder does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(utility::conversions::to_string_t("application/json"));

    queryParams[utility::conversions::to_string_t("destPath")] = ApiClient::parameterToString(destPath);
    
    if (srcStorageName)
    {
        queryParams[utility::conversions::to_string_t("srcStorageName")] = ApiClient::parameterToString(*srcStorageName);
    }
    if (destStorageName)
    {
        queryParams[utility::conversions::to_string_t("destStorageName")] = ApiClient::parameterToString(*destStorageName);
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
        throw ApiException(415, utility::conversions::to_string_t("FolderApi->moveFolder does not consume any supported media type"));
    }

    return m_ApiClient->callApi(path, utility::conversions::to_string_t("PUT"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful    : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling moveFolder: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if (response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if (contentType.find(responseHttpContentType) == std::string::npos)
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling moveFolder: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        std::shared_ptr<MessageResponse> result(new MessageResponse());
        result->setCode(response.status_code());
        result->setStatus(response.reason_phrase());

        return result;
    });
}

pplx::task<std::shared_ptr<MessageResponse>> StorageApi::createFolder(utility::string_t path_to_folder, boost::optional<utility::string_t> storageName)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t path = utility::conversions::to_string_t("/html/storage/folder/{path}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("path") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(path_to_folder));

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
        throw ApiException(400, utility::conversions::to_string_t("StorageApi->createFolder does not produce any supported media type"));
    }

    headerParams[utility::conversions::to_string_t("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(utility::conversions::to_string_t("application/json"));

    if (storageName)
    {
        queryParams[utility::conversions::to_string_t("storageName")] = ApiClient::parameterToString(*storageName);
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
        throw ApiException(415, utility::conversions::to_string_t("StorageApi->createFolder does not consume any supported media type"));
    }

    return m_ApiClient->callApi(path, utility::conversions::to_string_t("PUT"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful    : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
        if (response.status_code() >= 400)
        {
            throw ApiException(response.status_code()
                , utility::conversions::to_string_t("error calling createFolder: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
        }

        // check response content type
        if (response.headers().has(utility::conversions::to_string_t("Content-Type")))
        {
            utility::string_t contentType = response.headers()[utility::conversions::to_string_t("Content-Type")];
            if (contentType.find(responseHttpContentType) == std::string::npos)
            {
                throw ApiException(500
                    , utility::conversions::to_string_t("error calling createFolder: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }

        std::shared_ptr<MessageResponse> result(new MessageResponse());

        result->setCode(response.status_code());
        result->setStatus(response.reason_phrase());

        return result;
    });
}

}
}
}
