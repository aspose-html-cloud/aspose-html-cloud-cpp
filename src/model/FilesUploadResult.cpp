/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FilesUploadResult.cpp">
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

#include "model/FilesUploadResult.h"

namespace com {
namespace aspose {
namespace model {

FilesUploadResult::FilesUploadResult()
{
    m_UploadedIsSet = false;
    m_ErrorsIsSet = false;
}

FilesUploadResult::~FilesUploadResult()
{
}

void FilesUploadResult::validate()
{
    // TODO: implement validation
}

web::json::value FilesUploadResult::toJson() const
{
    web::json::value val = web::json::value::object();

    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_Uploaded )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        if(jsonArray.size() > 0)
        {
            val[utility::conversions::to_string_t("Uploaded")] = web::json::value::array(jsonArray);
        }
    }
    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_Errors )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        if(jsonArray.size() > 0)
        {
            val[utility::conversions::to_string_t("Errors")] = web::json::value::array(jsonArray);
        }
    }

    return val;
}

void FilesUploadResult::fromJson(web::json::value& val)
{
    {
        m_Uploaded.clear();
        std::vector<web::json::value> jsonArray;
        if(val.has_field(utility::conversions::to_string_t("Uploaded")))
        {
        for( auto& item : val[utility::conversions::to_string_t("Uploaded")].as_array() )
        {
            m_Uploaded.push_back(ModelBase::stringFromJson(item));
        }
        }
    }
    {
        m_Errors.clear();
        std::vector<web::json::value> jsonArray;
        if(val.has_field(utility::conversions::to_string_t("Errors")))
        {
        for( auto& item : val[utility::conversions::to_string_t("Errors")].as_array() )
        {
            if(item.is_null())
            {
                m_Errors.push_back( std::shared_ptr<Error>(nullptr) );
            }
            else
            {
                std::shared_ptr<Error> newItem(new Error());
                newItem->fromJson(item);
                m_Errors.push_back( newItem );
            }
        }
        }
    }
}

std::string FilesUploadResult::toString() const
{
    auto val = toJson().serialize();
    return utility::conversions::to_utf8string(val);
}

void FilesUploadResult::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_Uploaded )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Uploaded"), web::json::value::array(jsonArray), utility::conversions::to_string_t("application/json")));
        }
    }
    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_Errors )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Errors"), web::json::value::array(jsonArray), utility::conversions::to_string_t("application/json")));
        }
    }
}

void FilesUploadResult::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    {
        m_Uploaded.clear();
        if(multipart->hasContent(utility::conversions::to_string_t("Uploaded")))
        {

        web::json::value jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Uploaded"))));
        for( auto& item : jsonArray.as_array() )
        {
            m_Uploaded.push_back(ModelBase::stringFromJson(item));
        }
        }
    }
    {
        m_Errors.clear();
        if(multipart->hasContent(utility::conversions::to_string_t("Errors")))
        {

        web::json::value jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Errors"))));
        for( auto& item : jsonArray.as_array() )
        {
            if(item.is_null())
            {
                m_Errors.push_back( std::shared_ptr<Error>(nullptr) );
            }
            else
            {
                std::shared_ptr<Error> newItem(new Error());
                newItem->fromJson(item);
                m_Errors.push_back( newItem );
            }
        }
        }
    }
}

std::vector<utility::string_t>& FilesUploadResult::getUploaded()
{
    return m_Uploaded;
}

void FilesUploadResult::setUploaded(std::vector<utility::string_t> value)
{
    m_Uploaded = value;
    m_UploadedIsSet = true;
}
bool FilesUploadResult::uploadedIsSet() const
{
    return m_UploadedIsSet;
}

void FilesUploadResult::unsetUploaded()
{
    m_UploadedIsSet = false;
}

std::vector<std::shared_ptr<Error>>& FilesUploadResult::getErrors()
{
    return m_Errors;
}

void FilesUploadResult::setErrors(std::vector<std::shared_ptr<Error>> value)
{
    m_Errors = value;
    m_ErrorsIsSet = true;
}
bool FilesUploadResult::errorsIsSet() const
{
    return m_ErrorsIsSet;
}

void FilesUploadResult::unsetErrors()
{
    m_ErrorsIsSet = false;
}

}
}
}

