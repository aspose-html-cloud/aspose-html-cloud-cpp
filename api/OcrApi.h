#ifndef COM_ASPOSE_API_OcrApi_H_
#define COM_ASPOSE_API_OcrApi_H_


#include "../ApiClient.h"

#include "HttpContent.h"
#include <cpprest/details/basic_types.h>

#include <boost/optional.hpp>

namespace com {
namespace aspose {
namespace api {

using namespace com::aspose::model;

class  OcrApi
{
public:
    OcrApi( std::shared_ptr<ApiClient> apiClient );
    virtual ~OcrApi();
    /// <summary>
    /// Recognize text from the image file in the storage and import it to HTML format.
    /// Acceptable image formats is jpg, gif, png, bmp, tiff.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="name">The image file name.</param>
    /// <param name="ocrEngineLang">OCR engine language - language  (optional, default to en). Allowed values is "en", "de", "fr", "ru".</param>
    /// <param name="folder">The source image folder. (optional)</param>
    /// <param name="storage">The source image storage. (optional)</param>
    pplx::task<HttpContent> getRecognizeAndImportToHtml(
        utility::string_t name,
        boost::optional<utility::string_t> ocrEngineLang,
        boost::optional<utility::string_t> folder,
        boost::optional<utility::string_t> storage
    );
    /// <summary>
    /// Recognize text from the image file in the storage, import it to HTML format and translate to specified language.
    /// Acceptable image formats is jpg, gif, png, bmp, tiff.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="name">The image file name.</param>
    /// <param name="srcLang">Source language - also supposed as the OCR engine language. Allowed values is "en", "de", "fr", "ru".</param>
    /// <param name="resLang">Result language. Allowed values is "en", "de", "fr", "ru"</param>
    /// <param name="folder">The source image folder. (optional)</param>
    /// <param name="storage">The source image storage. (optional)</param>
    pplx::task<HttpContent> getRecognizeAndTranslateToHtml(
        utility::string_t name,
        utility::string_t srcLang,
        utility::string_t resLang,
        boost::optional<utility::string_t> folder,
        boost::optional<utility::string_t> storage
    );

protected:
    std::shared_ptr<ApiClient> m_ApiClient;
};

}
}
}

#endif /* COM_ASPOSE_API_OcrApi_H_ */

