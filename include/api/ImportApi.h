#ifndef COM_ASPOSE_API_ImportApi_H_
#define COM_ASPOSE_API_ImportApi_H_


#include "ApiClient.h"
#include "HttpContent.h"
#include <cpprest/details/basic_types.h>
#include <boost/optional.hpp>

namespace com {
namespace aspose {
namespace api {

using namespace com::aspose::model;

class ImportApi
{
public:
    ASPOSE_DLL_EXPORT ImportApi( std::shared_ptr<ApiClient> apiClient );
    ASPOSE_DLL_EXPORT ~ImportApi();

    /// <summary>
    /// Converts the Markdown document (located on storage) to HTML and returns resulting file in response content.
    /// </summary>
    /// <remarks>
    ///
    /// </remarks>
    /// <param name="name">Document name.</param>
    /// <param name="folder">Source document folder. (optional)</param>
    /// <param name="storage">Source document storage. (optional)</param>
    ASPOSE_DLL_EXPORT pplx::task<HttpContent> getConvertMarkdownToHtml(
        utility::string_t name,
        boost::optional<utility::string_t> folder,
        boost::optional<utility::string_t> storage
    );

    /// <summary>
    /// Converts the Markdown document (in request content) to HTML and uploads resulting file to storage by specified path.
    /// </summary>
    /// <remarks>
    ///
    /// </remarks>
    /// <param name="outPath">Full resulting file path in the storage (ex. /folder1/folder2/result.html)</param>
    /// <param name="file">A file to be converted.</param>
    /// <param name="storage">The source and resulting document storage. (optional)</param>
    ASPOSE_DLL_EXPORT pplx::task<HttpContent> postConvertMarkdownInRequestToHtml(
        utility::string_t outPath,
        std::shared_ptr<HttpContent> file,
        boost::optional<utility::string_t> storage
    );
    /// <summary>
    /// Converts the Markdown document (located on storage) to HTML and uploads resulting file to storage by specified path.
    /// </summary>
    /// <remarks>
    ///
    /// </remarks>
    /// <param name="name">Document name.</param>
    /// <param name="outPath">Full resulting file path in the storage (ex. /folder1/folder2/result.html)</param>
    /// <param name="folder">The source document folder. (optional)</param>
    /// <param name="storage">The source and resulting document storage. (optional)</param>
    ASPOSE_DLL_EXPORT pplx::task<HttpContent> putConvertMarkdownToHtml(
        utility::string_t name,
        utility::string_t outPath,
        boost::optional<utility::string_t> folder,
        boost::optional<utility::string_t> storage
    );

private:
    std::shared_ptr<ApiClient> m_ApiClient;
};

}
}
}

#endif /* COM_ASPOSE_API_ImportApi_H_ */
