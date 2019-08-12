#ifndef COM_ASPOSE_API_TemplateMergeApi_H_
#define COM_ASPOSE_API_TemplateMergeApi_H_


#include "ApiClient.h"
#include "HttpContent.h"
#include <cpprest/details/basic_types.h>
#include <boost/optional.hpp>

namespace com {
namespace aspose {
namespace api {

using namespace com::aspose::model;

class TemplateMergeApi
{
public:
    ASPOSE_DLL_EXPORT TemplateMergeApi( std::shared_ptr<ApiClient> apiClient );
    ASPOSE_DLL_EXPORT ~TemplateMergeApi();
    /// <summary>
    /// Populate HTML document template with data located as a file in the storage.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="templateName">Template document name. Template document is HTML or zipped HTML.</param>
    /// <param name="dataPath">Data source file path in the storage. Supported data format: XML</param>
    /// <param name="options">Template merge options: reserved for further implementation. (optional)</param>
    /// <param name="folder">The template document folder. (optional)</param>
    /// <param name="storage">The template document and data source storage. (optional)</param>
    ASPOSE_DLL_EXPORT pplx::task<HttpContent> getMergeHtmlTemplate(
        utility::string_t templateName,
        utility::string_t dataPath,
        boost::optional<utility::string_t> options,
        boost::optional<utility::string_t> folder,
        boost::optional<utility::string_t> storage
    );
    /// <summary>
    /// Populate HTML document template with data from the request body. Result document will be saved to storage.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="templateName">Template document name. Template document is HTML or zipped HTML.</param>
    /// <param name="outPath">Result document path.</param>
    /// <param name="file">A data file to populate template.</param>
    /// <param name="options">Template merge options: reserved for further implementation. (optional)</param>
    /// <param name="folder">The template document folder. (optional)</param>
    /// <param name="storage">The template document and data source storage. (optional)</param>
    ASPOSE_DLL_EXPORT pplx::task<HttpContent> postMergeHtmlTemplate(
        utility::string_t templateName,
        utility::string_t outPath,
        std::shared_ptr<HttpContent> file,
        boost::optional<utility::string_t> options,
        boost::optional<utility::string_t> folder,
        boost::optional<utility::string_t> storage
    );

private:
    std::shared_ptr<ApiClient> m_ApiClient;
};

}
}
}

#endif /* COM_ASPOSE_API_TemplateMergeApi_H_ */

