#ifndef COM_ASPOSE_MODEL_File_H_
#define COM_ASPOSE_MODEL_File_H_


#include "../ModelBase.h"

#include <cpprest/details/basic_types.h>

namespace com {
namespace aspose {
namespace model {

/// <summary>
/// 
/// </summary>
class  File
    : public ModelBase
{
public:
    File();
    virtual ~File();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// File members

    /// <summary>
    /// 
    /// </summary>
    utility::string_t getName() const;
    bool nameIsSet() const;
    void unsetName();
    void setName(utility::string_t value);
    /// <summary>
    /// 
    /// </summary>
    bool isIsFolder() const;
        void setIsFolder(bool value);
    /// <summary>
    /// 
    /// </summary>
    utility::datetime getModifiedDate() const;
        void setModifiedDate(utility::datetime value);
    /// <summary>
    /// 
    /// </summary>
    int64_t getSize() const;
        void setSize(int64_t value);
    /// <summary>
    /// 
    /// </summary>
    utility::string_t getPath() const;
    bool pathIsSet() const;
    void unsetPath();
    void setPath(utility::string_t value);
    /// <summary>
    /// 
    /// </summary>
    bool isIsDirectory() const;
        void setIsDirectory(bool value);

protected:
    utility::string_t m_Name;
    bool m_NameIsSet;
    bool m_IsFolder;
        utility::datetime m_ModifiedDate;
        int64_t m_Size;
        utility::string_t m_Path;
    bool m_PathIsSet;
    bool m_IsDirectory;
    };

}
}
}

#endif /* COM_ASPOSE_MODEL_File_H_ */
