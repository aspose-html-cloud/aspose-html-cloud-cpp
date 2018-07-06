/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FileVersion.cpp">
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
#include "FileVersion.h"

namespace com {
namespace aspose {
namespace model {

FileVersion::FileVersion()
{
    m_VersionId = utility::conversions::to_string_t("");
    m_VersionIdIsSet = false;
    m_IsLatest = false;
    m_IsLatestIsSet = false;
}

FileVersion::~FileVersion()
{
}

void FileVersion::validate()
{
    // TODO: implement validation
}

web::json::value FileVersion::toJson() const
{
    web::json::value val = this->File::toJson();

    if(m_VersionIdIsSet)
    {
        val[utility::conversions::to_string_t("VersionId")] = ModelBase::toJson(m_VersionId);
    }
    if(m_IsLatestIsSet)
    {
        val[utility::conversions::to_string_t("IsLatest")] = ModelBase::toJson(m_IsLatest);
    }

    return val;
}

void FileVersion::fromJson(web::json::value& val)
{
    this->File::fromJson(val);

    if(val.has_field(utility::conversions::to_string_t("VersionId")))
    {
        setVersionId(ModelBase::stringFromJson(val[utility::conversions::to_string_t("VersionId")]));
    }
    if(val.has_field(utility::conversions::to_string_t("IsLatest")))
    {
        setIsLatest(ModelBase::boolFromJson(val[utility::conversions::to_string_t("IsLatest")]));
    }
}

void FileVersion::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
    if(m_VersionIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("VersionId"), m_VersionId));
        
    }
    if(m_IsLatestIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("IsLatest"), m_IsLatest));
    }
}

void FileVersion::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(utility::conversions::to_string_t("VersionId")))
    {
        setVersionId(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("VersionId"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("IsLatest")))
    {
        setIsLatest(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("IsLatest"))));
    }
}

utility::string_t FileVersion::getVersionId() const
{
    return m_VersionId;
}


void FileVersion::setVersionId(utility::string_t value)
{
    m_VersionId = value;
    m_VersionIdIsSet = true;
}
bool FileVersion::versionIdIsSet() const
{
    return m_VersionIdIsSet;
}

void FileVersion::unsetVersionId()
{
    m_VersionIdIsSet = false;
}

bool FileVersion::isIsLatest() const
{
    return m_IsLatest;
}


void FileVersion::setIsLatest(bool value)
{
    m_IsLatest = value;
    m_IsLatestIsSet = true;
}
bool FileVersion::isLatestIsSet() const
{
    return m_IsLatestIsSet;
}

void FileVersion::unsetIsLatest()
{
    m_IsLatestIsSet = false;
}

}
}
}

