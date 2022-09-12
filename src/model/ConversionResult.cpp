/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ConversionResult.cpp">
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

#include "model/ConversionResult.h"

namespace com {
namespace aspose {
namespace model {

    ConversionResult::ConversionResult()
    {
        m_code          = 0;
        m_id            = utility::conversions::to_string_t("");
        m_status        = utility::conversions::to_string_t("");
        m_description   = utility::conversions::to_string_t("");
        m_file          = utility::conversions::to_string_t("");
    }

    ConversionResult::~ConversionResult()
    {
    }

    void ConversionResult::validate()
    {
        // TODO: implement validation
    }

    void ConversionResult::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
    {
    }

    void ConversionResult::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
    {
    }

    web::json::value ConversionResult::toJson() const
    {
        web::json::value val = web::json::value::object();

        val[utility::conversions::to_string_t("id")] = ModelBase::toJson(m_id);
        val[utility::conversions::to_string_t("ñode")] = ModelBase::toJson(m_code);
        val[utility::conversions::to_string_t("status")] = ModelBase::toJson(m_status);
        val[utility::conversions::to_string_t("description")] = ModelBase::toJson(m_description);
        val[utility::conversions::to_string_t("file")] = ModelBase::toJson(m_file);

        return val;
    }

    void ConversionResult::fromJson(web::json::value& val)
    {
        if (val.has_field(utility::conversions::to_string_t("code")))
        {
            setCode(ModelBase::int32_tFromJson(val[utility::conversions::to_string_t("code")]));
        }
        if (val.has_field(utility::conversions::to_string_t("id")))
        {
            setId(ModelBase::stringFromJson(val[utility::conversions::to_string_t("id")]));
        }
        if (val.has_field(utility::conversions::to_string_t("status")))
        {
            setStatus(ModelBase::stringFromJson(val[utility::conversions::to_string_t("status")]));
        }
        if (val.has_field(utility::conversions::to_string_t("description")))
        {
            setDescription(ModelBase::stringFromJson(val[utility::conversions::to_string_t("description")]));
        }
        if (val.has_field(utility::conversions::to_string_t("file")))
        {
            setFile(ModelBase::stringFromJson(val[utility::conversions::to_string_t("file")]));
        }
    }

    std::string ConversionResult::toString() const
    {
        auto val = toJson().serialize();
        return utility::conversions::to_utf8string(val);
    }

    unsigned short ConversionResult::getCode() const
    {
        return m_code;
    }

    void ConversionResult::setCode(unsigned short value)
    {
        m_code = value;
    }

    utility::string_t ConversionResult::getId() const
    {
        return m_id;
    }

    void ConversionResult::setId(utility::string_t value)
    {
        m_id = value;
    }

    utility::string_t ConversionResult::getStatus() const
    {
        return m_status;
    }

    void ConversionResult::setStatus(utility::string_t value)
    {
        m_status = value;
    }

    utility::string_t ConversionResult::getDescription() const
    {
        return m_description;
    }

    void ConversionResult::setDescription(utility::string_t value)
    {
        m_description = value;
    }

    utility::string_t ConversionResult::getFile() const
    {
        return m_file;
    }

    void ConversionResult::setFile(utility::string_t value)
    {
        m_file = value;
    }
}
}
}