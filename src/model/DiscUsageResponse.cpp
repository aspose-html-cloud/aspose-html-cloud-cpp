/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="DiscUsageResponse.cpp">
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


#include "model/DiscUsageResponse.h"


namespace com {
namespace aspose {
namespace model {

DiscUsageResponse::DiscUsageResponse()
{
    m_DiscUsageIsSet = false;
}

DiscUsageResponse::~DiscUsageResponse()
{
}

void DiscUsageResponse::validate()
{
    // TODO: implement validation
}

web::json::value DiscUsageResponse::toJson() const
{
    web::json::value val = this->MessageResponse::toJson();

    if(m_DiscUsageIsSet)
    {
        val[utility::conversions::to_string_t("DiscUsage")] = ModelBase::toJson(m_DiscUsage);
    }

    return val;
}

void DiscUsageResponse::fromJson(web::json::value& val)
{
    this->MessageResponse::fromJson(val);

    if(val.has_field(utility::conversions::to_string_t("DiscUsage")))
    {
        if(!val[utility::conversions::to_string_t("DiscUsage")].is_null())
        {
            std::shared_ptr<DiscUsage> newItem(new DiscUsage());
            newItem->fromJson(val[utility::conversions::to_string_t("DiscUsage")]);
            setDiscUsage( newItem );
        }
    }
}

void DiscUsageResponse::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Code"), m_Code));
    if(m_StatusIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Status"), m_Status));
        
    }
    if(m_DiscUsageIsSet)
    {
        if (m_DiscUsage.get())
        {
            m_DiscUsage->toMultipart(multipart, utility::conversions::to_string_t("DiscUsage."));
        }
        
    }
}

void DiscUsageResponse::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    setCode(ModelBase::int32_tFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Code"))));
    if(multipart->hasContent(utility::conversions::to_string_t("Status")))
    {
        setStatus(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Status"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("DiscUsage")))
    {
        if(multipart->hasContent(utility::conversions::to_string_t("DiscUsage")))
        {
            std::shared_ptr<DiscUsage> newItem(new DiscUsage());
            newItem->fromMultiPart(multipart, utility::conversions::to_string_t("DiscUsage."));
            setDiscUsage( newItem );
        }
    }
}

std::shared_ptr<DiscUsage> DiscUsageResponse::getDiscUsage() const
{
    return m_DiscUsage;
}


void DiscUsageResponse::setDiscUsage(std::shared_ptr<DiscUsage> value)
{
    m_DiscUsage = value;
    m_DiscUsageIsSet = true;
}
bool DiscUsageResponse::discUsageIsSet() const
{
    return m_DiscUsageIsSet;
}

void DiscUsageResponse::unsetDiscUsage()
{
    m_DiscUsageIsSet = false;
}

}
}
}

