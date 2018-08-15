#ifndef COM_ASPOSE_API_DocumentApi_H_
#define COM_ASPOSE_API_DocumentApi_H_


#include "../ApiClient.h"

#include "HttpContent.h"
#include <cpprest/details/basic_types.h>

#include <boost/optional.hpp>

namespace com {
namespace aspose {
namespace api {

using namespace com::aspose::model;

class  DocumentApi
{
public:
    DocumentApi( std::shared_ptr<ApiClient> apiClient );
    virtual ~DocumentApi();
    /// <summary>
    /// Return the HTML document by the name from default or specified storage.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="name">The document name.</param>
    /// <param name="storage">The document folder (optional)</param>
    /// <param name="folder">The document folder. (optional)</param>
    pplx::task<HttpContent> getDocument(
        utility::string_t name,
        boost::optional<utility::string_t> storage,
        boost::optional<utility::string_t> folder
    );
    /// <summary>
    /// Return list of HTML fragments matching the specified XPath query. 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="name">The document name.</param>
    /// <param name="xPath">XPath query string.</param>
    /// <param name="outFormat">Output format. Possible values: &#39;plain&#39; and &#39;json&#39;.</param>
    /// <param name="storage">The document storage. (optional)</param>
    /// <param name="folder">The document folder. (optional)</param>
    pplx::task<HttpContent> getDocumentFragmentByXPath(
        utility::string_t name,
        utility::string_t xPath,
        utility::string_t outFormat,
        boost::optional<utility::string_t> storage,
        boost::optional<utility::string_t> folder
    );
	/// <summary>
	/// Return list of HTML fragments matching the specified XPath query by the source page URL.
	/// </summary>
	/// <remarks>
	/// 
	/// </remarks>
	/// <param name="sourceUrl">Source page URL.</param>
	/// <param name="xPath">XPath query string.</param>
	/// <param name="outFormat">Output format. Possible values: &#39;plain&#39; and &#39;json&#39;.</param>
	pplx::task<HttpContent> getDocumentFragmentByXPathByUrl(
		utility::string_t sourceUrl,
		utility::string_t xPath,
		utility::string_t outFormat
	);
    /// <summary>
    /// Return all HTML document images packaged as a ZIP archive.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="name">The document name.</param>
    /// <param name="folder">The document folder. (optional)</param>
    /// <param name="storage">The document storage. (optional)</param>
    pplx::task<HttpContent> getDocumentImages(
        utility::string_t name,
        boost::optional<utility::string_t> folder,
        boost::optional<utility::string_t> storage
    );
	/// <summary>
	/// Return all HTML page images packaged as a ZIP archive by the source page URL.
	/// </summary>
	/// <remarks>
	/// 
	/// </remarks>
	/// <param name="sourceUrl">Source page URL.</param>
	pplx::task<HttpContent> getDocumentImagesByUrl(
		utility::string_t sourceUrl
	);

protected:
    std::shared_ptr<ApiClient> m_ApiClient;
};

}
}
}

#endif /* COM_ASPOSE_API_DocumentApi_H_ */

