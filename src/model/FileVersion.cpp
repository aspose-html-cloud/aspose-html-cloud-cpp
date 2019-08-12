/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FileVersion.cpp">
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

#include "model/FileVersion.h"

namespace com {
namespace aspose {
namespace model {

FileVersion::FileVersion()
{
    m_VersionId = utility::conversions::to_string_t("");
    m_VersionIdIsSet = false;
    m_IsLatest = false;
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
    web::json::value val = this->StorageFile::toJson();

    if(m_VersionIdIsSet)
    {
        val[utility::conversions::to_string_t("versionId")] = ModelBase::toJson(m_VersionId);
    }
    val[utility::conversions::to_string_t("isLatest")] = ModelBase::toJson(m_IsLatest);

    return val;
}

void FileVersion::fromJson(web::json::value& val)
{
    this->StorageFile::fromJson(val);

    if(val.has_field(utility::conversions::to_string_t("versionId")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("versionId")];
        if(!fieldValue.is_null())
        {
            setVersionId(ModelBase::stringFromJson(fieldValue));
        }
    }
    setIsLatest(ModelBase::boolFromJson(val[utility::conversions::to_string_t("isLatest")]));
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
    if(m_VersionIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("versionId"), m_VersionId));
        
    }
    multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("isLatest"), m_IsLatest));
}

void FileVersion::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
        setModifiedDate(ModelBase::dateFromHttpContent(multipart->getContent(utility::conversions::to_string_t("modifiedDate"))));
    }
    setSize(ModelBase::int64_tFromHttpContent(multipart->getContent(utility::conversions::to_string_t("size"))));
    if(multipart->hasContent(utility::conversions::to_string_t("path")))
    {
        setPath(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("path"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("versionId")))
    {
        setVersionId(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("versionId"))));
    }
    setIsLatest(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("isLatest"))));
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
    
}

}
}
}

