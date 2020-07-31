#ifndef COM_ASPOSE_MODEL_StorageExist_H_
#define COM_ASPOSE_MODEL_StorageExist_H_

#include "ModelBase.h"

namespace com {
namespace aspose {
namespace model {

/// <summary>
/// Storage exists
/// </summary>
class  StorageExist : public ModelBase
{
public:
    ASPOSE_DLL_EXPORT StorageExist();
    ASPOSE_DLL_EXPORT ~StorageExist();

    /////////////////////////////////////////////
    /// ModelBase overrides

    ASPOSE_DLL_EXPORT void validate() override;

    ASPOSE_DLL_EXPORT web::json::value toJson() const override;
    ASPOSE_DLL_EXPORT void fromJson(web::json::value& json) override;
    ASPOSE_DLL_EXPORT std::string toString() const override;

    ASPOSE_DLL_EXPORT void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    ASPOSE_DLL_EXPORT void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// StorageExist members

    /// <summary>
    /// Shows that the storage exists.             
    /// </summary>
    ASPOSE_DLL_EXPORT bool isExists() const;
    ASPOSE_DLL_EXPORT void setExists(bool value);

protected:
    bool m_Exists;
    };

}
}
}

#endif /* COM_ASPOSE_MODEL_StorageExist_H_ */
