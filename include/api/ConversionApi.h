#ifndef COM_ASPOSE_API_ConversionApi_H_
#define COM_ASPOSE_API_ConversionApi_H_


#include "ApiClient.h"
#include "HttpContent.h"
#include <cpprest/details/basic_types.h>
#include <boost/optional.hpp>
#include <model/ConversionResult.h>
#include <model/ConversionOptions.h>
#include <api/StorageApi.h>

namespace com {
namespace aspose {
namespace api {

using namespace com::aspose::model;

class ConversionApi
{
public:
    ASPOSE_DLL_EXPORT ConversionApi( std::shared_ptr<ApiClient> apiClient );
    ASPOSE_DLL_EXPORT ~ConversionApi();

    /// <summary>
    /// Convert the HTML or EPUB document from the local file to the local file.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="src">Full path to the source file.</param>
    /// <param name="dst">Full path to the result file.</param>
    /// <param name="options">Options for conversion.</param>
    /// <param name="width">Resulting image width in pixels. (optional)</param>
    /// <param name="height">Resulting image height in pixels. (optional)</param>
    /// <param name="leftMargin">Left resulting image margin in pixels. (optional)</param>
    /// <param name="rightMargin">Right resulting image margin in pixels. (optional)</param>
    /// <param name="topMargin">Top resulting image margin in pixels. (optional)</param>
    /// <param name="bottomMargin">Bottom resulting image margin in pixels. (optional)</param>
    ASPOSE_DLL_EXPORT std::shared_ptr<ConversionResult> convertLocalToLocal(
        const utility::string_t& src,
        const utility::string_t& dst,
        const std::shared_ptr<ConversionOptions> options = nullptr
    ) const;

    /// <summary>
    /// Convert the HTML or EPUB document from the local file to the storage.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="src">Full path to the source file.</param>
    /// <param name="dst">Path to the result file in the storage.</param>
    /// <param name="storage">User's storage name.</param>
    /// <param name="options">Options for conversion.</param>
    /// <param name="width">Resulting image width in pixels. (optional)</param>
    /// <param name="height">Resulting image height in pixels. (optional)</param>
    /// <param name="leftMargin">Left resulting image margin in pixels. (optional)</param>
    /// <param name="rightMargin">Right resulting image margin in pixels. (optional)</param>
    /// <param name="topMargin">Top resulting image margin in pixels. (optional)</param>
    /// <param name="bottomMargin">Bottom resulting image margin in pixels. (optional)</param>
    ASPOSE_DLL_EXPORT std::shared_ptr<ConversionResult> convertLocalToStorage(
        const utility::string_t& src,
        const utility::string_t& dst,
        const boost::optional<utility::string_t> storage = boost::none,
        const std::shared_ptr<ConversionOptions> options = nullptr
    ) const;
    /// <summary>
    /// Convert the HTML or EPUB document from the storage to the local file.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="src">Path to the source file in the storage.</param>
    /// <param name="dst">Full path to the result file in the local disk.</param>
    /// <param name="storage">User's storage name.</param>
    /// <param name="options">Options for conversion.</param>
    /// <param name="width">Resulting image width in pixels. (optional)</param>
    /// <param name="height">Resulting image height in pixels. (optional)</param>
    /// <param name="leftMargin">Left resulting image margin in pixels. (optional)</param>
    /// <param name="rightMargin">Right resulting image margin in pixels. (optional)</param>
    /// <param name="topMargin">Top resulting image margin in pixels. (optional)</param>
    /// <param name="bottomMargin">Bottom resulting image margin in pixels. (optional)</param>
    ASPOSE_DLL_EXPORT std::shared_ptr<ConversionResult> convertStorageToLocal(
        const utility::string_t& src,
        const utility::string_t& dst,
        const boost::optional<utility::string_t> storage = boost::none,
        const std::shared_ptr<ConversionOptions> options = nullptr
    ) const;

    /// <summary>
    /// Convert the HTML or EPUB document from the storage to the storage.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="src">Path to the source file in the storage.</param>
    /// <param name="dst">Path to the result file in the storage.</param>
    /// <param name="storage">User's storage name.</param>
    /// <param name="options">Options for conversion.</param>
    /// <param name="width">Resulting image width in pixels. (optional)</param>
    /// <param name="height">Resulting image height in pixels. (optional)</param>
    /// <param name="leftMargin">Left resulting image margin in pixels. (optional)</param>
    /// <param name="rightMargin">Right resulting image margin in pixels. (optional)</param>
    /// <param name="topMargin">Top resulting image margin in pixels. (optional)</param>
    /// <param name="bottomMargin">Bottom resulting image margin in pixels. (optional)</param>
    ASPOSE_DLL_EXPORT std::shared_ptr<ConversionResult> convertStorageToStorage(
        const utility::string_t& src,
        const utility::string_t& dst,
        const boost::optional<utility::string_t> storage = boost::none,
        const std::shared_ptr<ConversionOptions> options = nullptr
    ) const;

    /// <summary>
    /// Convert the website to the local file.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="src">Url of the website.</param>
    /// <param name="dst">Path to the result file in the local disk.</param>
    /// <param name="options">Options for conversion.</param>
    /// <param name="width">Resulting image width in pixels. (optional)</param>
    /// <param name="height">Resulting image height in pixels. (optional)</param>
    /// <param name="leftMargin">Left resulting image margin in pixels. (optional)</param>
    /// <param name="rightMargin">Right resulting image margin in pixels. (optional)</param>
    /// <param name="topMargin">Top resulting image margin in pixels. (optional)</param>
    /// <param name="bottomMargin">Bottom resulting image margin in pixels. (optional)</param>
    ASPOSE_DLL_EXPORT std::shared_ptr<ConversionResult> convertUrlToLocal(
        const utility::string_t& src,
        const utility::string_t& dst,
        const std::shared_ptr<ConversionOptions> options = nullptr
    ) const;

    /// <summary>
    /// Convert the website to the storage.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="src">Url of the website.</param>
    /// <param name="dst">Path to the result file in the storage.</param>
    /// <param name="storage">User's storage name.</param>
    /// <param name="options">Options for conversion.</param>
    /// <param name="width">Resulting image width in pixels. (optional)</param>
    /// <param name="height">Resulting image height in pixels. (optional)</param>
    /// <param name="leftMargin">Left resulting image margin in pixels. (optional)</param>
    /// <param name="rightMargin">Right resulting image margin in pixels. (optional)</param>
    /// <param name="topMargin">Top resulting image margin in pixels. (optional)</param>
    /// <param name="bottomMargin">Bottom resulting image margin in pixels. (optional)</param>
    ASPOSE_DLL_EXPORT std::shared_ptr<ConversionResult> convertUrlToStorage(
        const utility::string_t& src,
        const utility::string_t& dst,
        const boost::optional<utility::string_t> storage = boost::none,
        const std::shared_ptr<ConversionOptions> options = nullptr
    ) const;



private:
    std::shared_ptr<ConversionResult> convert(
        const utility::string_t& src,
        const utility::string_t& dst,
        bool srcInLocal,
        bool dstInLocal,
        bool isUrl,
        const std::shared_ptr<ConversionOptions> options = nullptr,
        const boost::optional<utility::string_t> storage = boost::none
    ) const;

    std::shared_ptr<ConversionResult> getState(const utility::string_t& id) const;

    pplx::task<std::shared_ptr<ConversionResult>> runRequest(
        const utility::string_t& path,
        const utility::string_t& method,
        const std::map<utility::string_t, utility::string_t>& queryParams,
        const std::shared_ptr<IHttpBody> postBody,
        const std::map<utility::string_t, utility::string_t>& headerParams,
        const std::map<utility::string_t, utility::string_t>& formParams,
        const std::map<utility::string_t, std::shared_ptr<HttpContent>>& fileParams,
        const utility::string_t& contentType
    ) const;

    inline std::shared_ptr<StorageApi> getStorage() const { return m_StorageApi; };

    std::shared_ptr<ApiClient> m_ApiClient;
    std::shared_ptr<StorageApi> m_StorageApi;
};

}
}
}

#endif /* COM_ASPOSE_API_ConversionApi_H_ */
