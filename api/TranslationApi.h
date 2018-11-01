#ifndef COM_ASPOSE_API_TranslationApi_H_
#define COM_ASPOSE_API_TranslationApi_H_


#include "../ApiClient.h"

#include "HttpContent.h"
#include <cpprest/details/basic_types.h>

#include <boost/optional.hpp>

namespace com {
namespace aspose {
namespace api {

using namespace com::aspose::model;

class  TranslationApi
{
public:
    TranslationApi( std::shared_ptr<ApiClient> apiClient );
    virtual ~TranslationApi();
    /// <summary>
    /// Translate the HTML document specified by the name from default or specified storage. 
    /// Allowed values for language pairs is en-de, en-fr, en-ru, de-en, ru-en, en-zh, zh-en.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="name">Document name.</param>
    /// <param name="srcLang">Source language. Allowed values is "en" (alias "eng", "english"), "de" (alias "deu", "deutsch", "german"), "fr" (alias "fra", "french"), "ru" (alias "rus", "russian"), "zh", alias ("chinese").</param>
    /// <param name="resLang">Result language. Allowed values is "en" (alias "eng", "english"), "de" (alias "deu", "deutsch", "german"), "fr" (alias "fra", "french"), "ru" (alias "rus", "russian"), "zh", alias ("chinese").</param>
    /// <param name="storage">The source document storage. (optional)</param>
    /// <param name="folder">The source document folder. (optional)</param>
    pplx::task<HttpContent> getTranslateDocument(
        utility::string_t name,
        utility::string_t srcLang,
        utility::string_t resLang,
        boost::optional<utility::string_t> storage,
        boost::optional<utility::string_t> folder
    );
    /// <summary>
    /// Translate the HTML document from Web specified by its URL.
    /// Allowed values for language pairs is en-de, en-fr, en-ru, de-en, ru-en, en-zh, zh-en.
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="sourceUrl">Source document URL.</param>
    /// <param name="srcLang">Source language.  Allowed values is "en" (alias "eng", "english"), "de" (alias "deu", "deutsch", "german"), "fr" (alias "fra", "french"), "ru" (alias "rus", "russian"), "zh", alias ("chinese").</param>
    /// <param name="resLang">Result language.  Allowed values is "en" (alias "eng", "english"), "de" (alias "deu", "deutsch", "german"), "fr" (alias "fra", "french"), "ru" (alias "rus", "russian"), "zh", alias ("chinese").</param>
    pplx::task<HttpContent> getTranslateDocumentByUrl(
        utility::string_t sourceUrl,
        utility::string_t srcLang,
        utility::string_t resLang
    );

protected:
    std::shared_ptr<ApiClient> m_ApiClient;
};

}
}
}

#endif /* COM_ASPOSE_API_TranslationApi_H_ */

