/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="OperationResult.cpp">
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

#include "model/OperationResult.h"

namespace com {
namespace aspose {
namespace model {

    OperationResult::OperationResult()
    {
        m_code          = 0;
        m_id            = utility::conversions::to_string_t("");
        m_status        = utility::conversions::to_string_t("");
        m_description   = utility::conversions::to_string_t("");
        m_file          = utility::conversions::to_string_t("");
    }

    OperationResult::~OperationResult()
    {
    }

    void OperationResult::validate()
    {
        // TODO: implement validation
    }

    void OperationResult::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
    {
    }

    void OperationResult::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
    {
    }

    web::json::value OperationResult::toJson() const
    {
        web::json::value val = web::json::value::object();

        val[utility::conversions::to_string_t("id")] = ModelBase::toJson(m_id);
        val[utility::conversions::to_string_t("ñode")] = ModelBase::toJson(m_code);
        val[utility::conversions::to_string_t("status")] = ModelBase::toJson(m_status);
        val[utility::conversions::to_string_t("description")] = ModelBase::toJson(m_description);
        val[utility::conversions::to_string_t("file")] = ModelBase::toJson(m_file);

        return val;
    }

    void OperationResult::fromJson(web::json::value& val)
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

    std::string OperationResult::toString() const
    {
        auto val = toJson().serialize();
        return utility::conversions::to_utf8string(val);
    }

    unsigned short OperationResult::getCode() const
    {
        return m_code;
    }

    void OperationResult::setCode(unsigned short value)
    {
        m_code = value;
    }

    utility::string_t OperationResult::getId() const
    {
        return m_id;
    }

    void OperationResult::setId(utility::string_t value)
    {
        m_id = value;
    }

    utility::string_t OperationResult::getStatus() const
    {
        return m_status;
    }

    void OperationResult::setStatus(utility::string_t value)
    {
        m_status = value;
    }

    utility::string_t OperationResult::getDescription() const
    {
        return m_description;
    }

    void OperationResult::setDescription(utility::string_t value)
    {
        m_description = value;
    }

    utility::string_t OperationResult::getFile() const
    {
        return m_file;
    }

    void OperationResult::setFile(utility::string_t value)
    {
        m_file = value;
    }
}
}
}