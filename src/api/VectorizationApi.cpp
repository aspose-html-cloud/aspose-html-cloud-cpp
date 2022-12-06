/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="VectorizationApi.cpp">
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


#include "api/VectorizationApi.h"
#include "IHttpBody.h"
#include "JsonBody.h"
#include <unordered_set>
#include <boost/algorithm/string/replace.hpp>
#include <model/ConversionRequest.h>
#include <model/VectorizationOptions.h>


namespace com {
namespace aspose {
namespace api {

using namespace com::aspose::model;

VectorizationApi::VectorizationApi( std::shared_ptr<ApiClient> apiClient )
    : m_ApiClient(apiClient), m_StorageApi(new StorageApi(apiClient))
{
}

VectorizationApi::~VectorizationApi()
{
}

std::shared_ptr<OperationResult> VectorizationApi::vectorizeLocalToLocal(
    const utility::string_t& src,
    const utility::string_t& dst,
    const std::shared_ptr<VectorizationOptions> options
) const
{
    return vectorize(src, dst, true, true, options);
}

std::shared_ptr<OperationResult> VectorizationApi::vectorizeLocalToStorage(
    const utility::string_t& src, 
    const utility::string_t& dst,
    const boost::optional<utility::string_t> storage,
    const std::shared_ptr<VectorizationOptions> options
) const
{
    return vectorize(src, dst, true, false, options, storage);
}

std::shared_ptr<OperationResult> VectorizationApi::vectorizeStorageToLocal(
    const utility::string_t& src,
    const utility::string_t& dst,
    const boost::optional<utility::string_t> storage,
    const std::shared_ptr<VectorizationOptions> options
) const
{
    return vectorize(src, dst, false, true, options, storage);
}

std::shared_ptr<OperationResult> VectorizationApi::vectorizeStorageToStorage(
    const utility::string_t& src,
    const utility::string_t& dst,
    const boost::optional<utility::string_t> storage,
    const std::shared_ptr<VectorizationOptions> options
) const
{
    return vectorize(src, dst, false, false, options, storage);
}

std::shared_ptr<OperationResult> VectorizationApi::vectorize(
    const utility::string_t& src,
    const utility::string_t& dst,
    const bool  srcInLocal,
    const bool  dstInLocal,
    const std::shared_ptr<VectorizationOptions> options,
    const boost::optional<utility::string_t> storage
) const
{
    size_t index = src.find_last_of(_XPLATSTR("."));
    utility::string_t ext = src.substr(index + 1);
    std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);

    utility::string_t inputFormat = ext;

    if (ext == _XPLATSTR("tif"))
    {
        inputFormat = _XPLATSTR("tiff");
    }
    else if (ext == _XPLATSTR("jpg"))
    {
        inputFormat = _XPLATSTR("jpeg");
    }

    if (!isImage(inputFormat)) 
    {
        throw std::invalid_argument("Source file must be an image.");
    }

    index = dst.find_last_of(_XPLATSTR("/\\"));
    utility::string_t outFile = dstInLocal ? dst.substr(index + 1) : dst;
    utility::string_t outFolder = dst.substr(0, index + 1);

    index = dst.find_last_of(_XPLATSTR("."));
    utility::string_t outFormat = dst.substr(index + 1);
    std::transform(outFormat.begin(), outFormat.end(), outFormat.begin(), ::tolower);

    if (outFormat != _XPLATSTR("svg"))
    {
        throw std::invalid_argument("Output file must be in SVG format.");
    }

    utility::string_t fileInStorage = src;

    if (srcInLocal)
    {
        std::ifstream f(src.c_str());
        if (!f.good())
        {
            throw std::invalid_argument("Source file not found.");
        }

        size_t index = src.find_last_of(_XPLATSTR("/\\"));
        utility::string_t name = src.substr(index + 1);
        utility::string_t folder = src.substr(0, index + 1);
        std::shared_ptr<HttpContent> file(new HttpContent(folder, name));
        boost::optional<utility::string_t> storageName = _XPLATSTR("");
        auto result = m_StorageApi->uploadFile(utility::conversions::to_string_t("/"), file, storageName).get();

        if (result->errorsIsSet())
        {
            throw std::runtime_error("Unable upload the file to the storage.");
        }
        
        fileInStorage = result->getUploaded()[0];
    }

    utility::string_t path = utility::conversions::to_string_t("/html/conversion/{from}-{to}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("from") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(inputFormat));
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("to") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(outFormat));
    
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    headerParams[utility::conversions::to_string_t("Accept")] = utility::conversions::to_string_t("application/json");
    utility::string_t requestHttpContentType = utility::conversions::to_string_t("application/json");

    std::shared_ptr<ConversionRequest> req(new ConversionRequest);

    req->setInputPath(fileInStorage)->setOutputFile(outFile);

    if (storage)
    {
        req->setStorageName(storage.get());
    }

    if (options)
    {
        req->setOptions(options);
    }

    web::json::value value = req->toJson();

    std::shared_ptr<IHttpBody> httpBody(new JsonBody(value));


    std::shared_ptr<OperationResult> 
        response = runRequest(path, utility::conversions::to_string_t("POST"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType).get();

   
    std::shared_ptr<OperationResult> result;

    while (true)
    {
        result = getState(response->getId());

        if (result->getStatus() == utility::conversions::to_string_t("faulted")
            || result->getStatus() == utility::conversions::to_string_t("canceled"))
        {
            throw std::runtime_error("Vectorization failed");
        }
        if (result->getStatus() == utility::conversions::to_string_t("completed"))
        {
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    }

    if (dstInLocal)
    {
        auto resultFile = result->getFile();
        size_t index = resultFile.find_last_of(_XPLATSTR("/\\"));
        auto fileName = (index == std::string::npos) ? resultFile : resultFile.substr(index + 1);
        auto fullPath = outFolder + fileName;
        auto res = m_StorageApi->downloadFile(resultFile).get();

        std::ofstream saved_data(fullPath, std::ios::out | std::ios::binary);

        //Save file locally
        if (saved_data.is_open())
        {
            res.writeTo(saved_data);
            saved_data.close();
            result->setFile(fullPath);
        }
        else
        {
            throw std::runtime_error("Unable to save the result file");
        }
    }

    return result;
}


std::shared_ptr<OperationResult> VectorizationApi::getState(const utility::string_t& id) const
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t path = utility::conversions::to_string_t("/html/conversion/{id}");
    boost::replace_all(path, utility::conversions::to_string_t("{") + utility::conversions::to_string_t("id") + utility::conversions::to_string_t("}"), ApiClient::parameterToString(id));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    headerParams[utility::conversions::to_string_t("Accept")] = utility::conversions::to_string_t("application/json");

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType = utility::conversions::to_string_t("application/json");

    pplx::task<std::shared_ptr<OperationResult>> response = runRequest(path, utility::conversions::to_string_t("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType);

    return response.get();

}

bool VectorizationApi::isImage(const utility::string_t& format) const
{
    return format == _XPLATSTR("bmp") || format == _XPLATSTR("jpeg") || format == _XPLATSTR("tiff") || format == _XPLATSTR("gif") || format == _XPLATSTR("png");
}


pplx::task<std::shared_ptr<OperationResult>>
VectorizationApi::runRequest(
    const utility::string_t& path,
    const utility::string_t& method,
    const std::map<utility::string_t, utility::string_t>& queryParams,
    const std::shared_ptr<IHttpBody> postBody,
    const std::map<utility::string_t, utility::string_t>& headerParams,
    const std::map<utility::string_t, utility::string_t>& formParams,
    const std::map<utility::string_t, std::shared_ptr<HttpContent>>& fileParams,
    const utility::string_t& contentType
) const
{
    return m_ApiClient->callApi(path, method, queryParams, postBody, headerParams, formParams, fileParams, contentType)
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
                return response.extract_string();
            })
        .then([=](utility::string_t response)
            {
                std::shared_ptr<OperationResult> result(new OperationResult());
                web::json::value json = web::json::value::parse(response);
                result->fromJson(json);

                return result;
            });
}


}
}
}
