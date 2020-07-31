/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ObjectExist.cpp">
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

#include "model/ObjectExist.h"

namespace com {
namespace aspose {
namespace model {

ObjectExist::ObjectExist()
{
    m_Exists = false;
    m_IsFolder = false;
}

ObjectExist::~ObjectExist()
{
}

void ObjectExist::validate()
{
    // TODO: implement validation
}

web::json::value ObjectExist::toJson() const
{
    web::json::value val = web::json::value::object();

    val[utility::conversions::to_string_t("exists")] = ModelBase::toJson(m_Exists);
    val[utility::conversions::to_string_t("isFolder")] = ModelBase::toJson(m_IsFolder);

    return val;
}

void ObjectExist::fromJson(web::json::value& val)
{
    setExists(ModelBase::boolFromJson(val[utility::conversions::to_string_t("exists")]));
    setIsFolder(ModelBase::boolFromJson(val[utility::conversions::to_string_t("isFolder")]));
}

std::string ObjectExist::toString() const
{
    auto val = toJson().serialize();
    return utility::conversions::to_utf8string(val);
}

void ObjectExist::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("exists"), m_Exists));
    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("isFolder"), m_IsFolder));
}

void ObjectExist::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    setExists(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("exists"))));
    setIsFolder(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("isFolder"))));
}

bool ObjectExist::isExists() const
{
    return m_Exists;
}


void ObjectExist::setExists(bool value)
{
    m_Exists = value;
    
}
bool ObjectExist::isFolder() const
{
    return m_IsFolder;
}


void ObjectExist::setIsFolder(bool value)
{
    m_IsFolder = value;
    
}

}
}
}
