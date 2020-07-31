#ifndef COM_ASPOSE_API_SeoApi_H_
#define COM_ASPOSE_API_SeoApi_H_


#include "ApiClient.h"
#include "HttpContent.h"
#include <cpprest/details/basic_types.h>
#include <boost/optional.hpp>

namespace com {
namespace aspose {
namespace api {

class SeoApi
{
public:
    ASPOSE_DLL_EXPORT SeoApi( std::shared_ptr<ApiClient> apiClient );
    ASPOSE_DLL_EXPORT ~SeoApi();

	/// <summary>
	/// Page analysis and return of SEO warnings.
	/// </summary>
	/// <remarks>
	/// 
	/// </remarks>
	/// <param name="addr">Source page URL for analyses. (required)</param>
    ASPOSE_DLL_EXPORT pplx::task<HttpContent> getSeoWarning(utility::string_t addr);

	/// <summary>
    /// Checks the markup validity of Web documents in HTML, XHTML, etc. 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="url">Source page URL for analyses.</param>
    ASPOSE_DLL_EXPORT pplx::task<HttpContent> getHtmlWarning(utility::string_t url);

private:
    std::shared_ptr<ApiClient> m_ApiClient;
};

}
}
}

#endif /* COM_ASPOSE_API_SeoApi_H_ */

