#ifndef COM_ASPOSE_MODEL_FileExist_H_
#define COM_ASPOSE_MODEL_FileExist_H_


#include "ModelBase.h"


namespace com {
namespace aspose {
namespace model {

/// <summary>
/// 
/// </summary>
class FileExist : public ModelBase
{
public:
    ASPOSE_DLL_EXPORT FileExist();
    ASPOSE_DLL_EXPORT ~FileExist();

    /////////////////////////////////////////////
    /// ModelBase overrides

    ASPOSE_DLL_EXPORT void validate() override;

    ASPOSE_DLL_EXPORT web::json::value toJson() const override;
    ASPOSE_DLL_EXPORT void fromJson(web::json::value& json) override;

    ASPOSE_DLL_EXPORT void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    ASPOSE_DLL_EXPORT void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// FileExist members

    /// <summary>
    /// 
    /// </summary>
    ASPOSE_DLL_EXPORT bool isExist() const;
    ASPOSE_DLL_EXPORT void setIsExist(bool value);
    /// <summary>
    /// 
    /// </summary>
    ASPOSE_DLL_EXPORT bool isFolder() const;
    ASPOSE_DLL_EXPORT void setIsFolder(bool value);

private:
    bool m_IsExist;
    bool m_IsFolder;
    };

}
}
}

#endif /* COM_ASPOSE_MODEL_FileExist_H_ */
