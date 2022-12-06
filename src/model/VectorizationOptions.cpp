/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="VectorizationOptions.cpp">
*  Copyright (c) 2022 Aspose.HTML for Cloud
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

#include "model/VectorizationOptions.h"


namespace com {
    namespace aspose {
        namespace model {

            VectorizationOptions::VectorizationOptions() {}
            VectorizationOptions::~VectorizationOptions() {}

            void VectorizationOptions::validate()
            {
                // TODO: implement validation
            }

            web::json::value VectorizationOptions::toJson() const
            {
                web::json::value val = web::json::value::object();

                if (m_error_threshold)
                {
                    val[utility::conversions::to_string_t("error_threshold")] = ModelBase::toJson(*m_error_threshold);
                }
                if (m_max_iterations)
                {
                    val[utility::conversions::to_string_t("max_iterations")] = ModelBase::toJson(*m_max_iterations);
                }
                if (m_colors_limit)
                {
                    val[utility::conversions::to_string_t("colors_limit")] = ModelBase::toJson(*m_colors_limit);
                }
                if (m_line_width)
                {
                    val[utility::conversions::to_string_t("line_width")] = ModelBase::toJson(*m_line_width);
                }
                return val;
            }

            void VectorizationOptions::fromJson(web::json::value& val)
            {
            }

            std::string VectorizationOptions::toString() const
            {
                auto val = toJson().serialize();
                return utility::conversions::to_utf8string(val);
            }

            void VectorizationOptions::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
            {
            }

            void VectorizationOptions::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
            {
            }

            VectorizationOptions* VectorizationOptions::setErrorThreshold(double value)
            {
                m_error_threshold = value;
                return this;
            }

            VectorizationOptions* VectorizationOptions::setMaxIteration(int value)
            {
                m_max_iterations = value;
                return this;
            }

            VectorizationOptions* VectorizationOptions::setColorLimit(int value)
            {
                m_colors_limit = value;
                return this;
            }

            VectorizationOptions* VectorizationOptions::setLineWidth(double value)
            {
                m_line_width = value;
                return this;
            }
        }
    }
}