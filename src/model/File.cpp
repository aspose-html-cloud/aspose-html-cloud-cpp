/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="File.cpp">
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


#include "model/File.h"


namespace com {
namespace aspose {
namespace model {

File::File()
{
    m_Name = utility::conversions::to_string_t("");
    m_NameIsSet = false;
    m_IsFolder = false;
    m_ModifiedDate = utility::datetime();
    m_Size = 0L;
    m_Path = utility::conversions::to_string_t("");
    m_PathIsSet = false;
    m_IsDirectory = false;
}

File::~File()
{
}

void File::validate()
{
    // TODO: implement validation
}

web::json::value File::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_NameIsSet)
    {
        val[utility::conversions::to_string_t("Name")] = ModelBase::toJson(m_Name);
    }
    val[utility::conversions::to_string_t("IsFolder")] = ModelBase::toJson(m_IsFolder);
    val[utility::conversions::to_string_t("ModifiedDate")] = ModelBase::toJson(m_ModifiedDate);
    val[utility::conversions::to_string_t("Size")] = ModelBase::toJson(m_Size);
    if(m_PathIsSet)
    {
        val[utility::conversions::to_string_t("Path")] = ModelBase::toJson(m_Path);
    }
    val[utility::conversions::to_string_t("IsDirectory")] = ModelBase::toJson(m_IsDirectory);

    return val;
}

void File::fromJson(web::json::value& val)
{
    if(val.has_field(utility::conversions::to_string_t("Name")))
    {
        setName(ModelBase::stringFromJson(val[utility::conversions::to_string_t("Name")]));
    }
    setIsFolder(ModelBase::boolFromJson(val[utility::conversions::to_string_t("IsFolder")]));
    setModifiedDate
    (ModelBase::dateFromJson(val[utility::conversions::to_string_t("ModifiedDate")]));
    setSize(ModelBase::int64_tFromJson(val[utility::conversions::to_string_t("Size")]));
    if(val.has_field(utility::conversions::to_string_t("Path")))
    {
        setPath(ModelBase::stringFromJson(val[utility::conversions::to_string_t("Path")]));
    }
    setIsDirectory(ModelBase::boolFromJson(val[utility::conversions::to_string_t("IsDirectory")]));
}

void File::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(m_NameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Name"), m_Name));
        
    }
    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("IsFolder"), m_IsFolder));
    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("ModifiedDate"), m_ModifiedDate));
    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Size"), m_Size));
    if(m_PathIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Path"), m_Path));
        
    }
    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("IsDirectory"), m_IsDirectory));
}

void File::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(multipart->hasContent(utility::conversions::to_string_t("Name")))
    {
        setName(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Name"))));
    }
    setIsFolder(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("IsFolder"))));
    setModifiedDate(ModelBase::dateFromHttpContent(multipart->getContent(utility::conversions::to_string_t("ModifiedDate"))));
    setSize(ModelBase::int64_tFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Size"))));
    if(multipart->hasContent(utility::conversions::to_string_t("Path")))
    {
        setPath(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Path"))));
    }
    setIsDirectory(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("IsDirectory"))));
}

utility::string_t File::getName() const
{
    return m_Name;
}


void File::setName(utility::string_t value)
{
    m_Name = value;
    m_NameIsSet = true;
}
bool File::nameIsSet() const
{
    return m_NameIsSet;
}

void File::unsetName()
{
    m_NameIsSet = false;
}

bool File::isIsFolder() const
{
    return m_IsFolder;
}


void File::setIsFolder(bool value)
{
    m_IsFolder = value;
    
}
utility::datetime File::getModifiedDate() const
{
    return m_ModifiedDate;
}


void File::setModifiedDate(utility::datetime value)
{
    m_ModifiedDate = value;
    
}
int64_t File::getSize() const
{
    return m_Size;
}


void File::setSize(int64_t value)
{
    m_Size = value;
    
}
utility::string_t File::getPath() const
{
    return m_Path;
}


void File::setPath(utility::string_t value)
{
    m_Path = value;
    m_PathIsSet = true;
}
bool File::pathIsSet() const
{
    return m_PathIsSet;
}

void File::unsetPath()
{
    m_PathIsSet = false;
}

bool File::isIsDirectory() const
{
    return m_IsDirectory;
}


void File::setIsDirectory(bool value)
{
    m_IsDirectory = value;
    
}
}
}
}

