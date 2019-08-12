#ifndef COM_ASPOSE_API_ConversionApi_H_
#define COM_ASPOSE_API_ConversionApi_H_


#include "ApiClient.h"
#include "HttpContent.h"
#include <cpprest/details/basic_types.h>
#include <boost/optional.hpp>

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
    /// Convert the HTML, EPUB, SVG document from the storage by its name to the specified image format.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="name">Document name(html,epub,svg formats).</param>
    /// <param name="outFormat">Resulting image format(jpeg, png, bmp, tiff, gif).</param>
    /// <param name="width">Resulting image width in points (1/96 inch). (optional)</param>
    /// <param name="height">Resulting image height in points (1/96 inch). (optional)</param>
    /// <param name="leftMargin">Left resulting image margin in points (1/96 inch). (optional)</param>
    /// <param name="rightMargin">Right resulting image margin in points (1/96 inch). (optional)</param>
    /// <param name="topMargin">Top resulting image margin in points (1/96 inch). (optional)</param>
    /// <param name="bottomMargin">Bottom resulting image margin in points (1/96 inch). (optional)</param>
    /// <param name="resolution">Resolution of resulting image. Default is 96 dpi. (optional)</param>
    /// <param name="folder">The source document folder. (optional)</param>
    /// <param name="storage">The source document storage. (optional)</param>
    ASPOSE_DLL_EXPORT pplx::task<HttpContent> getConvertDocumentToImage(
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
    /// <param name="outFormat">Resulting image format(jpeg, png, bmp, tiff, gif).</param>
    /// <param name="width">Resulting image width in points (1/96 inch). (optional)</param>
    /// <param name="height">Resulting image height in points (1/96 inch). (optional)</param>
    /// <param name="leftMargin">Left resulting image margin in points (1/96 inch). (optional)</param>
    /// <param name="rightMargin">Right resulting image margin in points (1/96 inch). (optional)</param>
    /// <param name="topMargin">Top resulting image margin in points (1/96 inch). (optional)</param>
    /// <param name="bottomMargin">Bottom resulting image margin in points (1/96 inch). (optional)</param>
    /// <param name="resolution">Resolution of resulting image. Default is 96 dpi. (optional)</param>
    ASPOSE_DLL_EXPORT pplx::task<HttpContent> getConvertDocumentToImageByUrl(
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
    /// Convert the HTML, EPUB, SVG document from the storage by its name to PDF.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="name">Document name(html, epub, svg).</param>
    /// <param name="width">Resulting document page width in points (1/96 inch). (optional)</param>
    /// <param name="height">Resulting document page height in points (1/96 inch). (optional)</param>
    /// <param name="leftMargin">Left resulting document page margin in points (1/96 inch). (optional)</param>
    /// <param name="rightMargin">Right resulting document page margin in points (1/96 inch). (optional)</param>
    /// <param name="topMargin">Top resulting document page margin in points (1/96 inch). (optional)</param>
    /// <param name="bottomMargin">Bottom resulting document page margin in points (1/96 inch). (optional)</param>
    /// <param name="folder">The source document folder. (optional)</param>
    /// <param name="storage">The source document storage. (optional)</param>
    ASPOSE_DLL_EXPORT pplx::task<HttpContent> getConvertDocumentToPdf(
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
    ASPOSE_DLL_EXPORT pplx::task<HttpContent> getConvertDocumentToPdfByUrl(
        utility::string_t sourceUrl,
        boost::optional<int32_t> width,
        boost::optional<int32_t> height,
        boost::optional<int32_t> leftMargin,
        boost::optional<int32_t> rightMargin,
        boost::optional<int32_t> topMargin,
        boost::optional<int32_t> bottomMargin
    );
    /// <summary>
    /// Convert the HTML, EPUB, SVG document from the storage by its name to XPS.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="name">Document name(html, epub, svg).</param>
    /// <param name="width">Resulting document page width in points (1/96 inch). (optional)</param>
    /// <param name="height">Resulting document page height in points (1/96 inch). (optional)</param>
    /// <param name="leftMargin">Left resulting document page margin in points (1/96 inch). (optional)</param>
    /// <param name="rightMargin">Right resulting document page margin in points (1/96 inch). (optional)</param>
    /// <param name="topMargin">Top resulting document page margin in points (1/96 inch). (optional)</param>
    /// <param name="bottomMargin">Bottom resulting document page margin in points (1/96 inch). (optional)</param>
    /// <param name="folder">The source document folder. (optional)</param>
    /// <param name="storage">The source document storage. (optional)</param>
    ASPOSE_DLL_EXPORT pplx::task<HttpContent> getConvertDocumentToXps(
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
    ASPOSE_DLL_EXPORT pplx::task<HttpContent> getConvertDocumentToXpsByUrl(
        utility::string_t sourceUrl,
        boost::optional<int32_t> width,
        boost::optional<int32_t> height,
        boost::optional<int32_t> leftMargin,
        boost::optional<int32_t> rightMargin,
        boost::optional<int32_t> topMargin,
        boost::optional<int32_t> bottomMargin
    );
	/// <summary>
	/// Converts the HTML, EPUB, SVG document (in request content) to the specified image format and uploads resulting file to storage.
	/// </summary>
	/// <remarks>
	/// 
	/// </remarks>
	/// <param name="outPath">Full resulting filename (ex. /folder1/folder2/result.jpg)</param>
	/// <param name="outFormat">Resulting image format(jpeg, png, bmp, tiff, gif).</param>
	/// <param name="file">A file to be converted.</param>
	/// <param name="width">Resulting document page width in points (1/96 inch). (optional)</param>
	/// <param name="height">Resulting document page height in points (1/96 inch). (optional)</param>
	/// <param name="leftMargin">Left resulting document page margin in points (1/96 inch). (optional)</param>
	/// <param name="rightMargin">Right resulting document page margin in points (1/96 inch). (optional)</param>
	/// <param name="topMargin">Top resulting document page margin in points (1/96 inch). (optional)</param>
	/// <param name="bottomMargin">Bottom resulting document page margin in points (1/96 inch). (optional)</param>
	/// <param name="resolution">Resolution of resulting image. Default is 96 dpi. (optional)</param>
    /// <param name="storage">The source document storage. (optional)</param>
    ASPOSE_DLL_EXPORT pplx::task<HttpContent> postConvertDocumentInRequestToImage(
		utility::string_t outPath,
		utility::string_t outFormat,
		std::shared_ptr<HttpContent> file,
		boost::optional<int32_t> width,
		boost::optional<int32_t> height,
		boost::optional<int32_t> leftMargin,
		boost::optional<int32_t> rightMargin,
		boost::optional<int32_t> topMargin,
		boost::optional<int32_t> bottomMargin,
		boost::optional<int32_t> resolution,
        boost::optional<utility::string_t> storage
	);
	/// <summary>
	/// Converts the HTML, EPUB, SVG document (in request content) to PDF and uploads resulting file to storage.
	/// </summary>
	/// <remarks>
	/// 
	/// </remarks>
	/// <param name="outPath">Full resulting filename (ex. /folder1/folder2/result.pdf)</param>
	/// <param name="file">A file to be converted.</param>
	/// <param name="width">Resulting document page width in points (1/96 inch). (optional)</param>
	/// <param name="height">Resulting document page height in points (1/96 inch). (optional)</param>
	/// <param name="leftMargin">Left resulting document page margin in points (1/96 inch). (optional)</param>
	/// <param name="rightMargin">Right resulting document page margin in points (1/96 inch). (optional)</param>
	/// <param name="topMargin">Top resulting document page margin in points (1/96 inch). (optional)</param>
	/// <param name="bottomMargin">Bottom resulting document page margin in points (1/96 inch). (optional)</param>
    /// <param name="storage">The source document storage. (optional)</param>
    ASPOSE_DLL_EXPORT pplx::task<HttpContent> postConvertDocumentInRequestToPdf(
		utility::string_t outPath,
		std::shared_ptr<HttpContent> file,
		boost::optional<int32_t> width,
		boost::optional<int32_t> height,
		boost::optional<int32_t> leftMargin,
		boost::optional<int32_t> rightMargin,
		boost::optional<int32_t> topMargin,
		boost::optional<int32_t> bottomMargin,
        boost::optional<utility::string_t> storage
    );
	/// <summary>
	/// Converts the HTML, EPUB, SVG document (in request content) to XPS and uploads resulting file to storage.
	/// </summary>
	/// <remarks>
	/// 
	/// </remarks>
	/// <param name="outPath">Full resulting filename (ex. /folder1/folder2/result.xps)</param>
	/// <param name="file">A file to be converted.</param>
	/// <param name="width">Resulting document page width in points (1/96 inch). (optional)</param>
	/// <param name="height">Resulting document page height in points (1/96 inch). (optional)</param>
	/// <param name="leftMargin">Left resulting document page margin in points (1/96 inch). (optional)</param>
	/// <param name="rightMargin">Right resulting document page margin in points (1/96 inch). (optional)</param>
	/// <param name="topMargin">Top resulting document page margin in points (1/96 inch). (optional)</param>
	/// <param name="bottomMargin">Bottom resulting document page margin in points (1/96 inch). (optional)</param>
    /// <param name="storage">The source document storage. (optional)</param>
    ASPOSE_DLL_EXPORT pplx::task<HttpContent> postConvertDocumentInRequestToXps(
		utility::string_t outPath,
		std::shared_ptr<HttpContent> file,
		boost::optional<int32_t> width,
		boost::optional<int32_t> height,
		boost::optional<int32_t> leftMargin,
		boost::optional<int32_t> rightMargin,
		boost::optional<int32_t> topMargin,
		boost::optional<int32_t> bottomMargin,
        boost::optional<utility::string_t> storage
    );
	/// <summary>
	/// Converts the HTML, EPUB, SVG document (located on storage) to the specified image format and uploads resulting file to storage.
	/// </summary>
	/// <remarks>
	/// 
	/// </remarks>
	/// <param name="name">Document name(html, epub, svg formats).</param>
	/// <param name="outPath">Full resulting filename (ex. /folder1/folder2/result.jpg)</param>
	/// <param name="outFormat">Resulting image format(jpeg, png, bmp, tiff, gif).</param>
	/// <param name="width">Resulting document page width in points (1/96 inch). (optional)</param>
	/// <param name="height">Resulting document page height in points (1/96 inch). (optional)</param>
	/// <param name="leftMargin">Left resulting document page margin in points (1/96 inch). (optional)</param>
	/// <param name="rightMargin">Right resulting document page margin in points (1/96 inch). (optional)</param>
	/// <param name="topMargin">Top resulting document page margin in points (1/96 inch). (optional)</param>
	/// <param name="bottomMargin">Bottom resulting document page margin in points (1/96 inch). (optional)</param>
	/// <param name="resolution">Resolution of resulting image. Default is 96 dpi. (optional)</param>
	/// <param name="folder">The source document folder. (optional)</param>
	/// <param name="storage">The source and resulting document storage. (optional)</param>
    ASPOSE_DLL_EXPORT pplx::task<HttpContent> putConvertDocumentToImage(
		utility::string_t name,
		utility::string_t outPath,
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
	/// Converts the HTML, EPUB, SVG document (located on storage) to PDF and uploads resulting file to storage.
	/// </summary>
	/// <remarks>
	/// 
	/// </remarks>
	/// <param name="name">Document name(html, epub, svg).</param>
	/// <param name="outPath">Full resulting filename (ex. /folder1/folder2/result.pdf)</param>
	/// <param name="width">Resulting document page width in points (1/96 inch). (optional)</param>
	/// <param name="height">Resulting document page height in points (1/96 inch). (optional)</param>
	/// <param name="leftMargin">Left resulting document page margin in points (1/96 inch). (optional)</param>
	/// <param name="rightMargin">Right resulting document page margin in points (1/96 inch). (optional)</param>
	/// <param name="topMargin">Top resulting document page margin in points (1/96 inch). (optional)</param>
	/// <param name="bottomMargin">Bottom resulting document page margin in points (1/96 inch). (optional)</param>
	/// <param name="folder">The source document folder. (optional)</param>
	/// <param name="storage">The source and resulting document storage. (optional)</param>
    ASPOSE_DLL_EXPORT pplx::task<HttpContent> putConvertDocumentToPdf(
		utility::string_t name,
		utility::string_t outPath,
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
	/// Converts the HTML, EPUB, SVG document (located on storage) to XPS and uploads resulting file to storage.
	/// </summary>
	/// <remarks>
	/// 
	/// </remarks>
	/// <param name="name">Document name(html, epub, svg formats).</param>
	/// <param name="outPath">Full resulting filename (ex. /folder1/folder2/result.xps)</param>
	/// <param name="width">Resulting document page width in points (1/96 inch). (optional)</param>
	/// <param name="height">Resulting document page height in points (1/96 inch). (optional)</param>
	/// <param name="leftMargin">Left resulting document page margin in points (1/96 inch). (optional)</param>
	/// <param name="rightMargin">Right resulting document page margin in points (1/96 inch). (optional)</param>
	/// <param name="topMargin">Top resulting document page margin in points (1/96 inch). (optional)</param>
	/// <param name="bottomMargin">Bottom resulting document page margin in points (1/96 inch). (optional)</param>
	/// <param name="folder">The source document folder. (optional)</param>
	/// <param name="storage">The source and resulting document storage. (optional)</param>
    ASPOSE_DLL_EXPORT pplx::task<HttpContent> putConvertDocumentToXps(
		utility::string_t name,
		utility::string_t outPath,
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
	/// Converts the HTML page from Web by its URL to MHTML returns resulting file in response content.
	/// </summary>
	/// <remarks>
	/// 
	/// </remarks>
	/// <param name="sourceUrl">Source page URL.</param>
    ASPOSE_DLL_EXPORT pplx::task<HttpContent> getConvertDocumentToMHTMLByUrl(
		utility::string_t sourceUrl
	);
	/// <summary>
	/// Converts the HTML document (located on storage) to Markdown and returns resulting file in response content.
	/// </summary>
	/// <remarks>
	///
	/// </remarks>
	/// <param name="name">Document name.</param>
	/// <param name="useGit">Use Git Markdown flavor to save. (optional, default to false)</param>
	/// <param name="folder">Source document folder. (optional)</param>
	/// <param name="storage">Source document storage. (optional)</param>
    ASPOSE_DLL_EXPORT pplx::task<HttpContent> getConvertDocumentToMarkdown(
		utility::string_t name,
		boost::optional<bool> useGit,
		boost::optional<utility::string_t> folder,
		boost::optional<utility::string_t> storage
	);
	/// <summary>
	/// Converts the HTML document (in request content) to Markdown and uploads resulting file to storage by specified path.
	/// </summary>
	/// <remarks>
	///
	/// </remarks>
	/// <param name="outPath">Full resulting file path in the storage (ex. /folder1/folder2/result.md)</param>
	/// <param name="file">A file to be converted.</param>
	/// <param name="useGit">Use Git Markdown flavor to save. (optional, default to false)</param>
    /// <param name="storage">The source and resulting document storage. (optional)</param>
    ASPOSE_DLL_EXPORT pplx::task<HttpContent> postConvertDocumentInRequestToMarkdown(
		utility::string_t outPath,
		std::shared_ptr<HttpContent> file,
		boost::optional<bool> useGit,
        boost::optional<utility::string_t> storage
	);
	/// <summary>
	/// Converts the HTML document (located on storage) to Markdown and uploads resulting file to storage by specified path.
	/// </summary>
	/// <remarks>
	///
	/// </remarks>
	/// <param name="name">Document name.</param>
	/// <param name="outPath">Full resulting file path in the storage (ex. /folder1/folder2/result.md)</param>
	/// <param name="useGit">Use Git Markdown flavor to save. (optional, default to false)</param>
	/// <param name="folder">The source document folder. (optional)</param>
	/// <param name="storage">The source and resulting document storage. (optional)</param>
    ASPOSE_DLL_EXPORT pplx::task<HttpContent> putConvertDocumentToMarkdown(
		utility::string_t name,
		utility::string_t outPath,
		boost::optional<bool> useGit,
		boost::optional<utility::string_t> folder,
		boost::optional<utility::string_t> storage
	);

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

#endif /* COM_ASPOSE_API_ConversionApi_H_ */
