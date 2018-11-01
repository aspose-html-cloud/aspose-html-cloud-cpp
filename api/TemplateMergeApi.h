/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TemplateMergeApi.h">
*  Copyright (c) 2018 Aspose.HTML for Cloud
* </copyright>
* <summary>
*  Permission is hereby granted, free of charge, to any person obtaining a copy
*  of this software and associated documentation files (the "Software"), to deal
*  in the Software without restriction, including without limitation the rights
*  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*  copies of the Software, and to permit persons to whom the Software is
*  furnished to do so, subject to the following conditions:
*
*  The above copyright notice and this permission notice shall be included in all
*  copies or substantial portions of the Software.
*
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
*  SOFTWARE.
* </summary>
* --------------------------------------------------------------------------------------------------------------------
*/

#ifndef COM_ASPOSE_API_TemplateMergeApi_H_
#define COM_ASPOSE_API_TemplateMergeApi_H_


#include "../ApiClient.h"

#include "HttpContent.h"
#include <cpprest/details/basic_types.h>

#include <boost/optional.hpp>

namespace com {
namespace aspose {
namespace api {

using namespace com::aspose::model;

class  TemplateMergeApi
{
public:
    TemplateMergeApi( std::shared_ptr<ApiClient> apiClient );
    virtual ~TemplateMergeApi();
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
    pplx::task<HttpContent> getMergeHtmlTemplate(
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
    pplx::task<HttpContent> putMergeHtmlTemplate(
        utility::string_t templateName,
        utility::string_t outPath,
        std::shared_ptr<HttpContent> file,
        boost::optional<utility::string_t> options,
        boost::optional<utility::string_t> folder,
        boost::optional<utility::string_t> storage
    );

protected:
    std::shared_ptr<ApiClient> m_ApiClient;
};

}
}
}

#endif /* COM_ASPOSE_API_TemplateMergeApi_H_ */

