/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ErrorDetails.cpp">
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

#include "model/ErrorDetails.h"

namespace com {
namespace aspose {
namespace model {

ErrorDetails::ErrorDetails()
{
    m_RequestId = utility::conversions::to_string_t("");
    m_RequestIdIsSet = false;
    m_Date = utility::datetime();
}

ErrorDetails::~ErrorDetails()
{
}

void ErrorDetails::validate()
{
    // TODO: implement validation
}

web::json::value ErrorDetails::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_RequestIdIsSet)
    {
        val[utility::conversions::to_string_t("RequestId")] = ModelBase::toJson(m_RequestId);
    }
    val[utility::conversions::to_string_t("Date")] = ModelBase::toJson(m_Date);

    return val;
}

void ErrorDetails::fromJson(web::json::value& val)
{
    if(val.has_field(utility::conversions::to_string_t("RequestId")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("RequestId")];
        if(!fieldValue.is_null())
        {
            setRequestId(ModelBase::stringFromJson(fieldValue));
        }
    }
    setDate
    (ModelBase::dateFromJson(val[utility::conversions::to_string_t("Date")]));
}

std::string ErrorDetails::toString() const
{
    auto val = toJson().serialize();
    return utility::conversions::to_utf8string(val);
}

void ErrorDetails::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(m_RequestIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("RequestId"), m_RequestId));
        
    }
    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Date"), m_Date));
}

void ErrorDetails::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(multipart->hasContent(utility::conversions::to_string_t("RequestId")))
    {
        setRequestId(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("RequestId"))));
    }
    setDate(ModelBase::dateFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Date"))));
}

utility::string_t ErrorDetails::getRequestId() const
{
    return m_RequestId;
}


void ErrorDetails::setRequestId(utility::string_t value)
{
    m_RequestId = value;
    m_RequestIdIsSet = true;
}
bool ErrorDetails::requestIdIsSet() const
{
    return m_RequestIdIsSet;
}

void ErrorDetails::unsetRequestId()
{
    m_RequestIdIsSet = false;
}

utility::datetime ErrorDetails::getDate() const
{
    return m_Date;
}


void ErrorDetails::setDate(utility::datetime value)
{
    m_Date = value;
    
}
}
}

}

