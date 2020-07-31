/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="StorageFile.cpp">
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

#include "model/StorageFile.h"

namespace com {
namespace aspose {
namespace model {

StorageFile::StorageFile()
{
    m_Name = utility::conversions::to_string_t("");
    m_NameIsSet = false;
    m_IsFolder = false;
    m_ModifiedDate = utility::string_t();
    m_ModifiedDateIsSet = false;
    m_Size = 0L;
    m_Path = utility::conversions::to_string_t("");
    m_PathIsSet = false;
}

StorageFile::~StorageFile()
{
}

void StorageFile::validate()
{
    // TODO: implement validation
}

web::json::value StorageFile::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_NameIsSet)
    {
        val[utility::conversions::to_string_t("name")] = ModelBase::toJson(m_Name);
    }
    val[utility::conversions::to_string_t("isFolder")] = ModelBase::toJson(m_IsFolder);
    if(m_ModifiedDateIsSet)
    {
        val[utility::conversions::to_string_t("modifiedDate")] = ModelBase::toJson(m_ModifiedDate);
    }
    val[utility::conversions::to_string_t("size")] = ModelBase::toJson(m_Size);
    if(m_PathIsSet)
    {
        val[utility::conversions::to_string_t("path")] = ModelBase::toJson(m_Path);
    }

    return val;
}

void StorageFile::fromJson(web::json::value& val)
{
    if(val.has_field(utility::conversions::to_string_t("name")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("name")];
        if(!fieldValue.is_null())
        {
            setName(ModelBase::stringFromJson(fieldValue));
        }
    }
    setIsFolder(ModelBase::boolFromJson(val[utility::conversions::to_string_t("isFolder")]));
    if(val.has_field(utility::conversions::to_string_t("modifiedDate")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("modifiedDate")];
        if(!fieldValue.is_null())
        {
            setModifiedDate(ModelBase::stringFromJson(fieldValue));
        }
    }
    setSize(ModelBase::int64_tFromJson(val[utility::conversions::to_string_t("size")]));
    if(val.has_field(utility::conversions::to_string_t("path")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("path")];
        if(!fieldValue.is_null())
        {
            setPath(ModelBase::stringFromJson(fieldValue));
        }
    }
}

std::string StorageFile::toString() const
{
    auto val = toJson().serialize();
    return utility::conversions::to_utf8string(val);
}

void StorageFile::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(m_NameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("name"), m_Name));
        
    }
    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("isFolder"), m_IsFolder));
    if(m_ModifiedDateIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("modifiedDate"), m_ModifiedDate));
        
    }
    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("size"), m_Size));
    if(m_PathIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("path"), m_Path));
        
    }
}

void StorageFile::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(multipart->hasContent(utility::conversions::to_string_t("name")))
    {
        setName(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("name"))));
    }
    setIsFolder(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("isFolder"))));
    if(multipart->hasContent(utility::conversions::to_string_t("modifiedDate")))
    {
        setModifiedDate(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("modifiedDate"))));
    }
    setSize(ModelBase::int64_tFromHttpContent(multipart->getContent(utility::conversions::to_string_t("size"))));
    if(multipart->hasContent(utility::conversions::to_string_t("path")))
    {
        setPath(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("path"))));
    }
}

utility::string_t StorageFile::getName() const
{
    return m_Name;
}


void StorageFile::setName(utility::string_t value)
{
    m_Name = value;
    m_NameIsSet = true;
}
bool StorageFile::nameIsSet() const
{
    return m_NameIsSet;
}

void StorageFile::unsetName()
{
    m_NameIsSet = false;
}

bool StorageFile::isFolder() const
{
    return m_IsFolder;
}


void StorageFile::setIsFolder(bool value)
{
    m_IsFolder = value;
    
}
utility::string_t StorageFile::getModifiedDate() const
{
    return m_ModifiedDate;
}


void StorageFile::setModifiedDate(utility::string_t value)
{
    m_ModifiedDate = value;
    m_ModifiedDateIsSet = true;
}
bool StorageFile::modifiedDateIsSet() const
{
    return m_ModifiedDateIsSet;
}

void StorageFile::unsetModifiedDate()
{
    m_ModifiedDateIsSet = false;
}

int64_t StorageFile::getSize() const
{
    return m_Size;
}


void StorageFile::setSize(int64_t value)
{
    m_Size = value;
    
}
utility::string_t StorageFile::getPath() const
{
    return m_Path;
}


void StorageFile::setPath(utility::string_t value)
{
    m_Path = value;
    m_PathIsSet = true;
}
bool StorageFile::pathIsSet() const
{
    return m_PathIsSet;
}

void StorageFile::unsetPath()
{
    m_PathIsSet = false;
}

}
}
}

