/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="DiscUsage.cpp">
*  Copyright (c) 2020 Aspose.HTML for Cloud
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


#include "model/DiscUsage.h"


namespace com {
namespace aspose {
namespace model {

DiscUsage::DiscUsage()
{
    m_UsedSize = 0L;
    m_TotalSize = 0L;
}

DiscUsage::~DiscUsage()
{
}

void DiscUsage::validate()
{
    // TODO: implement validation
}

web::json::value DiscUsage::toJson() const
{
    web::json::value val = web::json::value::object();

    val[utility::conversions::to_string_t("usedSize")] = ModelBase::toJson(m_UsedSize);
    val[utility::conversions::to_string_t("totalSize")] = ModelBase::toJson(m_TotalSize);

    return val;
}

void DiscUsage::fromJson(web::json::value& val)
{
    setUsedSize(ModelBase::int64_tFromJson(val[utility::conversions::to_string_t("usedSize")]));
    setTotalSize(ModelBase::int64_tFromJson(val[utility::conversions::to_string_t("totalSize")]));
}

std::string DiscUsage::toString() const
{
    auto val = toJson().serialize();
    return utility::conversions::to_utf8string(val);
}

void DiscUsage::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("usedSize"), m_UsedSize));
    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("totalSize"), m_TotalSize));
}

void DiscUsage::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    setUsedSize(ModelBase::int64_tFromHttpContent(multipart->getContent(utility::conversions::to_string_t("usedSize"))));
    setTotalSize(ModelBase::int64_tFromHttpContent(multipart->getContent(utility::conversions::to_string_t("totalSize"))));
}

int64_t DiscUsage::getUsedSize() const
{
    return m_UsedSize;
}


void DiscUsage::setUsedSize(int64_t value)
{
    m_UsedSize = value;
    
}
int64_t DiscUsage::getTotalSize() const
{
    return m_TotalSize;
}


void DiscUsage::setTotalSize(int64_t value)
{
    m_TotalSize = value;
    
}

}
}
}

