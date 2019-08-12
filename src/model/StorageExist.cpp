/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="StorageExist.cpp">
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

#include "model/StorageExist.h"

namespace com {
namespace aspose {
namespace model {

StorageExist::StorageExist()
{
    m_Exists = false;
}

StorageExist::~StorageExist()
{
}

void StorageExist::validate()
{
    // TODO: implement validation
}

web::json::value StorageExist::toJson() const
{
    web::json::value val = web::json::value::object();

    val[utility::conversions::to_string_t("exists")] = ModelBase::toJson(m_Exists);

    return val;
}

void StorageExist::fromJson(web::json::value& val)
{
    setExists(ModelBase::boolFromJson(val[utility::conversions::to_string_t("exists")]));
}

void StorageExist::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("exists"), m_Exists));
}

void StorageExist::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    setExists(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("exists"))));
}

bool StorageExist::isExists() const
{
    return m_Exists;
}


void StorageExist::setExists(bool value)
{
    m_Exists = value;
    
}

}
}
}


