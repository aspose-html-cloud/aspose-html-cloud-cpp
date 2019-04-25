/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="StorageExistResponse.cpp">
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


#include "model/StorageExistResponse.h"


namespace com {
namespace aspose {
namespace model {

StorageExistResponse::StorageExistResponse()
{
    m_IsExist = false;
    m_IsExistIsSet = false;
}

StorageExistResponse::~StorageExistResponse()
{
}

void StorageExistResponse::validate()
{
    // TODO: implement validation
}

web::json::value StorageExistResponse::toJson() const
{
    web::json::value val = this->MessageResponse::toJson();

    if(m_IsExistIsSet)
    {
        val[utility::conversions::to_string_t("IsExist")] = ModelBase::toJson(m_IsExist);
    }

    return val;
}

void StorageExistResponse::fromJson(web::json::value& val)
{
    this->MessageResponse::fromJson(val);

    if(val.has_field(utility::conversions::to_string_t("IsExist")))
    {
        setIsExist(ModelBase::boolFromJson(val[utility::conversions::to_string_t("IsExist")]));
    }
}

void StorageExistResponse::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
    if(m_IsExistIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("IsExist"), m_IsExist));
    }
}

void StorageExistResponse::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(utility::conversions::to_string_t("IsExist")))
    {
        setIsExist(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("IsExist"))));
    }
}

bool StorageExistResponse::isExist() const
{
    return m_IsExist;
}


void StorageExistResponse::setIsExist(bool value)
{
    m_IsExist = value;
    m_IsExistIsSet = true;
}
bool StorageExistResponse::isExistIsSet() const
{
    return m_IsExistIsSet;
}

void StorageExistResponse::unsetIsExist()
{
    m_IsExistIsSet = false;
}

}
}
}

