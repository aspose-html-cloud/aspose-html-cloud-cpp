#ifndef COM_ASPOSE_MODEL_StorageFile_H_
#define COM_ASPOSE_MODEL_StorageFile_H_


#include "ModelBase.h"
#include <cpprest/details/basic_types.h>

namespace com {
namespace aspose {
namespace model {

/// <summary>
/// File or folder information
/// </summary>
class  StorageFile : public ModelBase
{
public:
    ASPOSE_DLL_EXPORT StorageFile();
    ASPOSE_DLL_EXPORT ~StorageFile();

    /////////////////////////////////////////////
    /// ModelBase overrides

    ASPOSE_DLL_EXPORT void validate() override;

    ASPOSE_DLL_EXPORT web::json::value toJson() const override;
    ASPOSE_DLL_EXPORT void fromJson(web::json::value& json) override;

    ASPOSE_DLL_EXPORT void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    ASPOSE_DLL_EXPORT void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// StorageFile members

    /// <summary>
    /// File or folder name.
    /// </summary>
    ASPOSE_DLL_EXPORT utility::string_t getName() const;
    ASPOSE_DLL_EXPORT bool nameIsSet() const;
    ASPOSE_DLL_EXPORT void unsetName();
    ASPOSE_DLL_EXPORT void setName(utility::string_t value);
    /// <summary>
    /// True if it is a folder.
    /// </summary>
    ASPOSE_DLL_EXPORT bool isFolder() const;
    ASPOSE_DLL_EXPORT void setIsFolder(bool value);
    /// <summary>
    /// File or folder last modified DateTime.
    /// </summary>
    ASPOSE_DLL_EXPORT utility::datetime getModifiedDate() const;
    ASPOSE_DLL_EXPORT bool modifiedDateIsSet() const;
    ASPOSE_DLL_EXPORT void unsetModifiedDate();
    ASPOSE_DLL_EXPORT void setModifiedDate(utility::datetime value);
    /// <summary>
    /// File or folder size.
    /// </summary>
    ASPOSE_DLL_EXPORT int64_t getSize() const;
    ASPOSE_DLL_EXPORT void setSize(int64_t value);
    /// <summary>
    /// File or folder path.
    /// </summary>
    ASPOSE_DLL_EXPORT utility::string_t getPath() const;
    ASPOSE_DLL_EXPORT bool pathIsSet() const;
    ASPOSE_DLL_EXPORT void unsetPath();
    ASPOSE_DLL_EXPORT void setPath(utility::string_t value);

protected:
    utility::string_t m_Name;
    bool m_NameIsSet;
    bool m_IsFolder;
        utility::datetime m_ModifiedDate;
    bool m_ModifiedDateIsSet;
    int64_t m_Size;
        utility::string_t m_Path;
    bool m_PathIsSet;
};

}
}
}


#endif /* COM_ASPOSE_MODEL_StorageFile_H_ */
