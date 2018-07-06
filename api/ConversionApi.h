#ifndef COM_ASPOSE_API_ConversionApi_H_
#define COM_ASPOSE_API_ConversionApi_H_


#include "../ApiClient.h"

#include "HttpContent.h"
#include <cpprest/details/basic_types.h>

#include <boost/optional.hpp>

namespace com {
namespace aspose {
namespace api {

using namespace com::aspose::model;

class  ConversionApi
{
public:
    ConversionApi( std::shared_ptr<ApiClient> apiClient );
    virtual ~ConversionApi();
    /// <summary>
    /// Convert the HTML document from the storage by its name to the specified image format.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="name">Document name.</param>
    /// <param name="outFormat">Resulting image format.</param>
    /// <param name="width">Resulting image width in points (1/96 inch). (optional)</param>
    /// <param name="height">Resulting image height in points (1/96 inch). (optional)</param>
    /// <param name="leftMargin">Left resulting image margin in points (1/96 inch). (optional)</param>
    /// <param name="rightMargin">Right resulting image margin in points (1/96 inch). (optional)</param>
    /// <param name="topMargin">Top resulting image margin in points (1/96 inch). (optional)</param>
    /// <param name="bottomMargin">Bottom resulting image margin in points (1/96 inch). (optional)</param>
    /// <param name="resolution">Resolution of resulting image. Default is 96 dpi. (optional)</param>
    /// <param name="folder">The source document folder. (optional)</param>
    /// <param name="storage">The source document storage. (optional)</param>
    pplx::task<HttpContent> getConvertDocumentToImage(
        utility::string_t name,
        utility::string_t outFormat,
        boost::optional<int32_t> width,
        boost::optional<int32_t> height,
        boost::optional<int32_t> leftMargin,
        boost::optional<int32_t> rightMargin,
        boost::optional<int32_t> topMargin,
        boost::optional<int32_t> bottomMargin,
        boost::optional<int32_t> resolution,
        boost::optional<utility::string_t> folder,
        boost::optional<utility::string_t> storage
    );
    /// <summary>
    /// Convert the HTML page from the web by its URL to the specified image format.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="sourceUrl">Source page URL.</param>
    /// <param name="outFormat">Resulting image format.</param>
    /// <param name="width">Resulting image width in points (1/96 inch). (optional)</param>
    /// <param name="height">Resulting image height in points (1/96 inch). (optional)</param>
    /// <param name="leftMargin">Left resulting image margin in points (1/96 inch). (optional)</param>
    /// <param name="rightMargin">Right resulting image margin in points (1/96 inch). (optional)</param>
    /// <param name="topMargin">Top resulting image margin in points (1/96 inch). (optional)</param>
    /// <param name="bottomMargin">Bottom resulting image margin in points (1/96 inch). (optional)</param>
    /// <param name="resolution">Resolution of resulting image. Default is 96 dpi. (optional)</param>
    pplx::task<HttpContent> getConvertDocumentToImageByUrl(
        utility::string_t sourceUrl,
        utility::string_t outFormat,
        boost::optional<int32_t> width,
        boost::optional<int32_t> height,
        boost::optional<int32_t> leftMargin,
        boost::optional<int32_t> rightMargin,
        boost::optional<int32_t> topMargin,
        boost::optional<int32_t> bottomMargin,
        boost::optional<int32_t> resolution
    );
    /// <summary>
    /// Convert the HTML document from the storage by its name to PDF.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="name">Document name.</param>
    /// <param name="width">Resulting document page width in points (1/96 inch). (optional)</param>
    /// <param name="height">Resulting document page height in points (1/96 inch). (optional)</param>
    /// <param name="leftMargin">Left resulting document page margin in points (1/96 inch). (optional)</param>
    /// <param name="rightMargin">Right resulting document page margin in points (1/96 inch). (optional)</param>
    /// <param name="topMargin">Top resulting document page margin in points (1/96 inch). (optional)</param>
    /// <param name="bottomMargin">Bottom resulting document page margin in points (1/96 inch). (optional)</param>
    /// <param name="folder">The source document folder. (optional)</param>
    /// <param name="storage">The source document storage. (optional)</param>
    pplx::task<HttpContent> getConvertDocumentToPdf(
        utility::string_t name,
        boost::optional<int32_t> width,
        boost::optional<int32_t> height,
        boost::optional<int32_t> leftMargin,
        boost::optional<int32_t> rightMargin,
        boost::optional<int32_t> topMargin,
        boost::optional<int32_t> bottomMargin,
        boost::optional<utility::string_t> folder,
        boost::optional<utility::string_t> storage
    );
    /// <summary>
    /// Convert the HTML page from the web by its URL to PDF.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="sourceUrl">Source page URL.</param>
    /// <param name="width">Resulting document page width in points (1/96 inch). (optional)</param>
    /// <param name="height">Resulting document page height in points (1/96 inch). (optional)</param>
    /// <param name="leftMargin">Left resulting document page margin in points (1/96 inch). (optional)</param>
    /// <param name="rightMargin">Right resulting document page margin in points (1/96 inch). (optional)</param>
    /// <param name="topMargin">Top resulting document page margin in points (1/96 inch). (optional)</param>
    /// <param name="bottomMargin">Bottom resulting document page margin in points (1/96 inch). (optional)</param>
    pplx::task<HttpContent> getConvertDocumentToPdfByUrl(
        utility::string_t sourceUrl,
        boost::optional<int32_t> width,
        boost::optional<int32_t> height,
        boost::optional<int32_t> leftMargin,
        boost::optional<int32_t> rightMargin,
        boost::optional<int32_t> topMargin,
        boost::optional<int32_t> bottomMargin
    );
    /// <summary>
    /// Convert the HTML document from the storage by its name to XPS.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="name">Document name.</param>
    /// <param name="width">Resulting document page width in points (1/96 inch). (optional)</param>
    /// <param name="height">Resulting document page height in points (1/96 inch). (optional)</param>
    /// <param name="leftMargin">Left resulting document page margin in points (1/96 inch). (optional)</param>
    /// <param name="rightMargin">Right resulting document page margin in points (1/96 inch). (optional)</param>
    /// <param name="topMargin">Top resulting document page margin in points (1/96 inch). (optional)</param>
    /// <param name="bottomMargin">Bottom resulting document page margin in points (1/96 inch). (optional)</param>
    /// <param name="folder">The source document folder. (optional)</param>
    /// <param name="storage">The source document storage. (optional)</param>
    pplx::task<HttpContent> getConvertDocumentToXps(
        utility::string_t name,
        boost::optional<int32_t> width,
        boost::optional<int32_t> height,
        boost::optional<int32_t> leftMargin,
        boost::optional<int32_t> rightMargin,
        boost::optional<int32_t> topMargin,
        boost::optional<int32_t> bottomMargin,
        boost::optional<utility::string_t> folder,
        boost::optional<utility::string_t> storage
    );
    /// <summary>
    /// Convert the HTML page from the web by its URL to XPS.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="sourceUrl">Source page URL.</param>
    /// <param name="width">Resulting document page width in points (1/96 inch). (optional)</param>
    /// <param name="height">Resulting document page height in points (1/96 inch). (optional)</param>
    /// <param name="leftMargin">Left resulting document page margin in points (1/96 inch). (optional)</param>
    /// <param name="rightMargin">Right resulting document page margin in points (1/96 inch). (optional)</param>
    /// <param name="topMargin">Top resulting document page margin in points (1/96 inch). (optional)</param>
    /// <param name="bottomMargin">Bottom resulting document page margin in points (1/96 inch). (optional)</param>
    pplx::task<HttpContent> getConvertDocumentToXpsByUrl(
        utility::string_t sourceUrl,
        boost::optional<int32_t> width,
        boost::optional<int32_t> height,
        boost::optional<int32_t> leftMargin,
        boost::optional<int32_t> rightMargin,
        boost::optional<int32_t> topMargin,
        boost::optional<int32_t> bottomMargin
    );

protected:
    std::shared_ptr<ApiClient> m_ApiClient;
};

}
}
}

#endif /* COM_ASPOSE_API_ConversionApi_H_ */

