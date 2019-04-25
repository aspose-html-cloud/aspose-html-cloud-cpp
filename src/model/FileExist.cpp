/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FileExist.cpp">
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


#include "model/FileExist.h"


namespace com {
namespace aspose {
namespace model {

FileExist::FileExist()
{
    m_IsExist = false;
    m_IsFolder = false;
}

FileExist::~FileExist()
{
}

void FileExist::validate()
{
    // TODO: implement validation
}

web::json::value FileExist::toJson() const
{
    web::json::value val = web::json::value::object();

    val[utility::conversions::to_string_t("IsExist")] = ModelBase::toJson(m_IsExist);
    val[utility::conversions::to_string_t("IsFolder")] = ModelBase::toJson(m_IsFolder);

    return val;
}

void FileExist::fromJson(web::json::value& val)
{
    setIsExist(ModelBase::boolFromJson(val[utility::conversions::to_string_t("IsExist")]));
    setIsFolder(ModelBase::boolFromJson(val[utility::conversions::to_string_t("IsFolder")]));
}

void FileExist::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("IsExist"), m_IsExist));
    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("IsFolder"), m_IsFolder));
}

void FileExist::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    setIsExist(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("IsExist"))));
    setIsFolder(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("IsFolder"))));
}

bool FileExist::isExist() const
{
    return m_IsExist;
}


void FileExist::setIsExist(bool value)
{
    m_IsExist = value;
    
}
bool FileExist::isFolder() const
{
    return m_IsFolder;
}


void FileExist::setIsFolder(bool value)
{
    m_IsFolder = value;
    
}
}
}
}

