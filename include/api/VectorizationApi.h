#ifndef COM_ASPOSE_API_VectorizationApi_H_
#define COM_ASPOSE_API_VectorizationApi_H_


#include "ApiClient.h"
#include "HttpContent.h"
#include <cpprest/details/basic_types.h>
#include <boost/optional.hpp>
#include <model/OperationResult.h>
#include <model/VectorizationOptions.h>
#include <api/StorageApi.h>

namespace com {
namespace aspose {
namespace api {

using namespace com::aspose::model;

class VectorizationApi
{
public:
    ASPOSE_DLL_EXPORT VectorizationApi( std::shared_ptr<ApiClient> apiClient );
    ASPOSE_DLL_EXPORT ~VectorizationApi();

    /// <summary>
    /// Vectorize an image from the local file to the local file.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="src">Full path to the source file.</param>
    /// <param name="dst">Full path to the result file.</param>
    /// <param name="options">VectorizationOptions for trace image. (optional)</param>
    ASPOSE_DLL_EXPORT std::shared_ptr<OperationResult> vectorizeLocalToLocal(
        const utility::string_t& src,
        const utility::string_t& dst,
        const std::shared_ptr<VectorizationOptions> options = nullptr
    ) const;

    /// <summary>
    /// Vectorize an image from the local file to the storage.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="src">Full path to the source file.</param>
    /// <param name="dst">Path to the result file in the storage.</param>
    /// <param name="storage">User's storage name. (optional)</param>
    /// <param name="options">VectorizationOptions for trace image. (optional)</param>
    ASPOSE_DLL_EXPORT std::shared_ptr<OperationResult> vectorizeLocalToStorage(
        const utility::string_t& src,
        const utility::string_t& dst,
        const boost::optional<utility::string_t> storage = boost::none,
        const std::shared_ptr<VectorizationOptions> options = nullptr
    ) const;

    /// <summary>
    /// Vectorize an image from the storage to the local file.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="src">Path to the source file in the storage.</param>
    /// <param name="dst">Full path to the result file in the local disk.</param>
    /// <param name="storage">User's storage name. (optional)</param>
    /// <param name="options">VectorizationOptions for trace image. (optional)</param>
    ASPOSE_DLL_EXPORT std::shared_ptr<OperationResult> vectorizeStorageToLocal(
        const utility::string_t& src,
        const utility::string_t& dst,
        const boost::optional<utility::string_t> storage = boost::none,
        const std::shared_ptr<VectorizationOptions> options = nullptr
    ) const;

    /// <summary>
    /// Vectorize an image from the storage to the storage.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="src">Path to the source file in the storage.</param>
    /// <param name="dst">Path to the result file in the storage.</param>
    /// <param name="storage">User's storage name. (optional)</param>
    /// <param name="options">VectorizationOptions for trace image. (optional)</param>
    ASPOSE_DLL_EXPORT std::shared_ptr<OperationResult> vectorizeStorageToStorage(
        const utility::string_t& src,
        const utility::string_t& dst,
        const boost::optional<utility::string_t> storage = boost::none,
        const std::shared_ptr<VectorizationOptions> options = nullptr
    ) const;

private:
    std::shared_ptr<OperationResult> vectorize(
        const utility::string_t& src,
        const utility::string_t& dst,
        const bool srcInLocal,
        const bool dstInLocal,
        const std::shared_ptr<VectorizationOptions> options = nullptr,
        const boost::optional<utility::string_t> storage = boost::none
    ) const;

    std::shared_ptr<OperationResult> getState(const utility::string_t& id) const;

    pplx::task<std::shared_ptr<OperationResult>> runRequest(
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
    bool isImage(const utility::string_t& format) const;

    std::shared_ptr<ApiClient> m_ApiClient;
    std::shared_ptr<StorageApi> m_StorageApi;
};

}
}
}

#endif /* COM_ASPOSE_API_VectorizationApi_H_ */
