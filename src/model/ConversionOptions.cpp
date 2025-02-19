/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ConversionOptions.cpp">
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

#include "model/ConversionOptions.h"


namespace com {
namespace aspose {
namespace model {

ConversionOptions::ConversionOptions() {}
ConversionOptions::~ConversionOptions() {}

void ConversionOptions::validate()
{
    // TODO: implement validation
}

web::json::value ConversionOptions::toJson() const
{
    web::json::value val = web::json::value::object();

    if (m_width) 
    {
        val[utility::conversions::to_string_t("width")] = ModelBase::toJson(*m_width);
    }
    if (m_height)
    {
        val[utility::conversions::to_string_t("height")] = ModelBase::toJson(*m_height);
    }
    if (m_leftMargin)
    {
        val[utility::conversions::to_string_t("leftmargin")] = ModelBase::toJson(*m_leftMargin);
    }
    if (m_rightMargin)
    {
        val[utility::conversions::to_string_t("rightmargin")] = ModelBase::toJson(*m_rightMargin);
    }
    if (m_topMargin)
    {
        val[utility::conversions::to_string_t("topmargin")] = ModelBase::toJson(*m_topMargin);
    }
    if (m_bottomMargin)
    {
        val[utility::conversions::to_string_t("bottommargin")] = ModelBase::toJson(*m_bottomMargin);
    }
    if (m_jpeg_quality)
    {
        val[utility::conversions::to_string_t("jpegquality")] = ModelBase::toJson(*m_jpeg_quality);
    }
    if (m_background)
    {
        val[utility::conversions::to_string_t("background")] = ModelBase::toJson(*m_background);
    }
    if (m_use_git)
    {
        val[utility::conversions::to_string_t("usegit")] = ModelBase::toJson(*m_use_git);
    }
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

void ConversionOptions::fromJson(web::json::value& val)
{
}

std::string ConversionOptions::toString() const
{
    auto val = toJson().serialize();
    return utility::conversions::to_utf8string(val);
}

void ConversionOptions::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
}

void ConversionOptions::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
}

ConversionOptions* ConversionOptions::setWidth(double value)
{
    m_width = value;
    return this;
}

ConversionOptions* ConversionOptions::setHeight(double value)
{
    m_height = value;
    return this;
}

ConversionOptions* ConversionOptions::setLeftMargin(double value)
{
    m_leftMargin = value;
    return this;
}

ConversionOptions* ConversionOptions::setRightMargin(double value)
{
    m_rightMargin = value;
    return this;
}

ConversionOptions* ConversionOptions::setTopMargin(double value)
{
    m_topMargin = value;
    return this;
}

ConversionOptions* ConversionOptions::setBottomMargin(double value)
{
    m_bottomMargin = value;
    return this;
}

ConversionOptions* ConversionOptions::setJpegQuality(int value)
{
    m_jpeg_quality = value;
    return this;
}

ConversionOptions* ConversionOptions::setBackground(utility::string_t value)
{
    m_background = value;
    return this;
}

ConversionOptions* ConversionOptions::setUseGit(bool value)
{
    m_use_git = value;
    return this;
}

ConversionOptions* ConversionOptions::setErrorThreshold(double value)
{
    m_error_threshold = value;
    return this;
}

ConversionOptions* ConversionOptions::setMaxIteration(int value)
{
    m_max_iterations = value;
    return this;
}

ConversionOptions* ConversionOptions::setColorLimit(int value)
{
    m_colors_limit = value;
    return this;
}

ConversionOptions* ConversionOptions::setLineWidth(double value)
{
    m_line_width = value;
    return this;
}



}
}
}