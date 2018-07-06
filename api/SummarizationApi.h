#ifndef COM_ASPOSE_API_SummarizationApi_H_
#define COM_ASPOSE_API_SummarizationApi_H_


#include "../ApiClient.h"

#include "HttpContent.h"
#include <cpprest/details/basic_types.h>

#include <boost/optional.hpp>

namespace com {
namespace aspose {
namespace api {

using namespace com::aspose::model;

class  SummarizationApi
{
public:
    SummarizationApi( std::shared_ptr<ApiClient> apiClient );
    virtual ~SummarizationApi();
    /// <summary>
    /// Get the HTML document keywords using the keyword detection service.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="name">Document name.</param>
    /// <param name="folder">Document folder. (optional)</param>
    /// <param name="storage">Document storage. (optional)</param>
    pplx::task<HttpContent> getDetectHtmlKeywords(
        utility::string_t name,
        boost::optional<utility::string_t> folder,
        boost::optional<utility::string_t> storage
    );
    /// <summary>
    /// Get the keywords from HTML document from Web specified by its URL using the keyword detection service
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="sourceUrl">Source document URL.</param>
    pplx::task<HttpContent> getDetectHtmlKeywordsByUrl(
        utility::string_t sourceUrl
    );

protected:
    std::shared_ptr<ApiClient> m_ApiClient;
};

}
}
}

#endif /* COM_ASPOSE_API_SummarizationApi_H_ */

