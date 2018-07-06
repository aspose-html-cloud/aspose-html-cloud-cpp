/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FileVersionResponse.cpp">
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
#include "FileVersionsResponse.h"

namespace com {
namespace aspose {
namespace model {

FileVersionsResponse::FileVersionsResponse()
{
    m_FileVersionsIsSet = false;
}

FileVersionsResponse::~FileVersionsResponse()
{
}

void FileVersionsResponse::validate()
{
    // TODO: implement validation
}

web::json::value FileVersionsResponse::toJson() const
{
    web::json::value val = this->MessageResponse::toJson();

    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_FileVersions )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        if(jsonArray.size() > 0)
        {
            val[utility::conversions::to_string_t("FileVersions")] = web::json::value::array(jsonArray);
        }
    }

    return val;
}

void FileVersionsResponse::fromJson(web::json::value& val)
{
    this->MessageResponse::fromJson(val);

    {
        m_FileVersions.clear();
        std::vector<web::json::value> jsonArray;
        if(val.has_field(utility::conversions::to_string_t("FileVersions")))
        {
        for( auto& item : val[utility::conversions::to_string_t("FileVersions")].as_array() )
        {
            if(item.is_null())
            {
                m_FileVersions.push_back( std::shared_ptr<FileVersion>(nullptr) );
            }
            else
            {
                std::shared_ptr<FileVersion> newItem(new FileVersion());
                newItem->fromJson(item);
                m_FileVersions.push_back( newItem );
            }
        }
        }
    }
}

void FileVersionsResponse::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_FileVersions )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("FileVersions"), web::json::value::array(jsonArray), utility::conversions::to_string_t("application/json")));
        }
    }
}

void FileVersionsResponse::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
    {
        m_FileVersions.clear();
        if(multipart->hasContent(utility::conversions::to_string_t("FileVersions")))
        {

        web::json::value jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("FileVersions"))));
        for( auto& item : jsonArray.as_array() )
        {
            if(item.is_null())
            {
                m_FileVersions.push_back( std::shared_ptr<FileVersion>(nullptr) );
            }
            else
            {
                std::shared_ptr<FileVersion> newItem(new FileVersion());
                newItem->fromJson(item);
                m_FileVersions.push_back( newItem );
            }
        }
        }
    }
}

std::vector<std::shared_ptr<FileVersion>>& FileVersionsResponse::getFileVersions()
{
    return m_FileVersions;
}

void FileVersionsResponse::setFileVersions(std::vector<std::shared_ptr<FileVersion>> value)
{
    m_FileVersions = value;
    m_FileVersionsIsSet = true;
}
bool FileVersionsResponse::fileVersionsIsSet() const
{
    return m_FileVersionsIsSet;
}

void FileVersionsResponse::unsetFileVersions()
{
    m_FileVersionsIsSet = false;
}

}
}
}

