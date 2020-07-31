#ifndef COM_ASPOSE_MODEL_ObjectExist_H_
#define COM_ASPOSE_MODEL_ObjectExist_H_

#include "ModelBase.h"

namespace com {
namespace aspose {
namespace model {

/// <summary>
/// Object exists
/// </summary>
class  ObjectExist : public ModelBase
{
public:
    ASPOSE_DLL_EXPORT ObjectExist();
    ASPOSE_DLL_EXPORT ~ObjectExist();

    /////////////////////////////////////////////
    /// ModelBase overrides

    ASPOSE_DLL_EXPORT void validate() override;

    ASPOSE_DLL_EXPORT web::json::value toJson() const override;
    ASPOSE_DLL_EXPORT void fromJson(web::json::value& json) override;
    ASPOSE_DLL_EXPORT std::string toString() const override;

    ASPOSE_DLL_EXPORT void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    ASPOSE_DLL_EXPORT void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// ObjectExist members

    /// <summary>
    /// Indicates that the file or folder exists.
    /// </summary>
    ASPOSE_DLL_EXPORT bool isExists() const;
    ASPOSE_DLL_EXPORT void setExists(bool value);
    /// <summary>
    /// True if it is a folder, false if it is a file.
    /// </summary>
    ASPOSE_DLL_EXPORT bool isFolder() const;
    ASPOSE_DLL_EXPORT void setIsFolder(bool value);

protected:
    bool m_Exists;
    bool m_IsFolder;
    };

}
}
}

#endif /* COM_ASPOSE_MODEL_ObjectExist_H_ */
