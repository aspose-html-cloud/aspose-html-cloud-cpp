#ifndef COM_ASPOSE_API_DocumentApi_H_
#define COM_ASPOSE_API_DocumentApi_H_


#include "ApiClient.h"
#include "HttpContent.h"
#include <cpprest/details/basic_types.h>
#include <boost/optional.hpp>

namespace com {
namespace aspose {
namespace api {

using namespace com::aspose::model;

class DocumentApi
{
public:
    ASPOSE_DLL_EXPORT DocumentApi( std::shared_ptr<ApiClient> apiClient );
    ASPOSE_DLL_EXPORT ~DocumentApi();
	/// <summary>
	/// Return all HTML page with linked resources packaged as a ZIP archive by the source page URL.
	/// </summary>
	/// <remarks>
	/// 
	/// </remarks>
	/// <param name="sourceUrl">Source page URL.</param>
    ASPOSE_DLL_EXPORT pplx::task<HttpContent> getDocumentByUrl(utility::string_t sourceUrl);
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
    ASPOSE_DLL_EXPORT pplx::task<HttpContent> getDocumentFragmentByXPath(
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
    ASPOSE_DLL_EXPORT pplx::task<HttpContent> getDocumentFragmentByXPathByUrl(
		utility::string_t sourceUrl,
		utility::string_t xPath,
		utility::string_t outFormat
	);
	/// <summary>
	/// Return list of HTML fragments matching the specified CSS selector.
	/// </summary>
	/// <remarks>
	/// 
	/// </remarks>
	/// <param name="name">The document name.</param>
	/// <param name="selector">CSS selector string.</param>
	/// <param name="outFormat">Output format. Possible values: &#39;plain&#39; and &#39;json&#39;.</param>
	/// <param name="folder">The document folder. (optional)</param>
	/// <param name="storage">The document storage. (optional)</param>
    ASPOSE_DLL_EXPORT pplx::task<HttpContent> getDocumentFragmentsByCSSSelector(
		utility::string_t name,
		utility::string_t selector,
		utility::string_t outFormat,
		boost::optional<utility::string_t> folder,
		boost::optional<utility::string_t> storage
	);
	/// <summary>
	/// Return list of HTML fragments matching the specified CSS selector by the source page URL.
	/// </summary>
	/// <remarks>
	/// 
	/// </remarks>
	/// <param name="sourceUrl">Source page URL.</param>
	/// <param name="selector">CSS selector string.</param>
	/// <param name="outFormat">Output format. Possible values: &#39;plain&#39; and &#39;json&#39;.</param>
    ASPOSE_DLL_EXPORT pplx::task<HttpContent> getDocumentFragmentsByCSSSelectorByUrl(
		utility::string_t sourceUrl,
		utility::string_t selector,
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
    ASPOSE_DLL_EXPORT pplx::task<HttpContent> getDocumentImages(
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
    ASPOSE_DLL_EXPORT pplx::task<HttpContent> getDocumentImagesByUrl(
		utility::string_t sourceUrl
	);

private:
    std::shared_ptr<ApiClient> m_ApiClient;
};

}
}
}

#endif /* COM_ASPOSE_API_DocumentApi_H_ */

