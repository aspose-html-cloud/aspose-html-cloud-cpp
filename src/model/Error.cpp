/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="Error.cpp">
*  Copyright (c) 2019 Aspose.HTML for Cloud
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

#include "model/Error.h"

namespace com {
namespace aspose {
namespace model {

Error::Error()
{
    m_Code = utility::conversions::to_string_t("");
    m_CodeIsSet = false;
    m_Message = utility::conversions::to_string_t("");
    m_MessageIsSet = false;
    m_Description = utility::conversions::to_string_t("");
    m_DescriptionIsSet = false;
    m_InnerErrorIsSet = false;
}

Error::~Error()
{
}

void Error::validate()
{
    // TODO: implement validation
}

web::json::value Error::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_CodeIsSet)
    {
        val[utility::conversions::to_string_t("Code")] = ModelBase::toJson(m_Code);
    }
    if(m_MessageIsSet)
    {
        val[utility::conversions::to_string_t("Message")] = ModelBase::toJson(m_Message);
    }
    if(m_DescriptionIsSet)
    {
        val[utility::conversions::to_string_t("Description")] = ModelBase::toJson(m_Description);
    }
    if(m_InnerErrorIsSet)
    {
        val[utility::conversions::to_string_t("InnerError")] = ModelBase::toJson(m_InnerError);
    }

    return val;
}

void Error::fromJson(web::json::value& val)
{
    if(val.has_field(utility::conversions::to_string_t("Code")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("Code")];
        if(!fieldValue.is_null())
        {
            setCode(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("Message")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("Message")];
        if(!fieldValue.is_null())
        {
            setMessage(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("Description")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("Description")];
        if(!fieldValue.is_null())
        {
            setDescription(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("InnerError")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("InnerError")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<ErrorDetails> newItem(new ErrorDetails());
            newItem->fromJson(fieldValue);
            setInnerError( newItem );
        }
    }
}

void Error::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(m_CodeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Code"), m_Code));
        
    }
    if(m_MessageIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Message"), m_Message));
        
    }
    if(m_DescriptionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Description"), m_Description));
        
    }
    if(m_InnerErrorIsSet)
    {
        if (m_InnerError.get())
        {
            m_InnerError->toMultipart(multipart, utility::conversions::to_string_t("InnerError."));
        }
        
    }
}

void Error::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(multipart->hasContent(utility::conversions::to_string_t("Code")))
    {
        setCode(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Code"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("Message")))
    {
        setMessage(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Message"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("Description")))
    {
        setDescription(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Description"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("InnerError")))
    {
        if(multipart->hasContent(utility::conversions::to_string_t("InnerError")))
        {
            std::shared_ptr<ErrorDetails> newItem(new ErrorDetails());
            newItem->fromMultiPart(multipart, utility::conversions::to_string_t("InnerError."));
            setInnerError( newItem );
        }
    }
}

utility::string_t Error::getCode() const
{
    return m_Code;
}


void Error::setCode(utility::string_t value)
{
    m_Code = value;
    m_CodeIsSet = true;
}
bool Error::codeIsSet() const
{
    return m_CodeIsSet;
}

void Error::unsetCode()
{
    m_CodeIsSet = false;
}

utility::string_t Error::getMessage() const
{
    return m_Message;
}


void Error::setMessage(utility::string_t value)
{
    m_Message = value;
    m_MessageIsSet = true;
}
bool Error::messageIsSet() const
{
    return m_MessageIsSet;
}

void Error::unsetMessage()
{
    m_MessageIsSet = false;
}

utility::string_t Error::getDescription() const
{
    return m_Description;
}


void Error::setDescription(utility::string_t value)
{
    m_Description = value;
    m_DescriptionIsSet = true;
}
bool Error::descriptionIsSet() const
{
    return m_DescriptionIsSet;
}

void Error::unsetDescription()
{
    m_DescriptionIsSet = false;
}

std::shared_ptr<ErrorDetails> Error::getInnerError() const
{
    return m_InnerError;
}


void Error::setInnerError(std::shared_ptr<ErrorDetails> value)
{
    m_InnerError = value;
    m_InnerErrorIsSet = true;
}
bool Error::innerErrorIsSet() const
{
    return m_InnerErrorIsSet;
}

void Error::unsetInnerError()
{
    m_InnerErrorIsSet = false;
}

}
}
}

