#ifndef COM_ASPOSE_MODEL_StorageExistResponse_H_
#define COM_ASPOSE_MODEL_StorageExistResponse_H_


#include "model/MessageResponse.h"
#include <cpprest/details/basic_types.h>

namespace com {
namespace aspose {
namespace model {

/// <summary>
/// 
/// </summary>
class StorageExistResponse : public MessageResponse
{
public:
    ASPOSE_DLL_EXPORT StorageExistResponse();
    ASPOSE_DLL_EXPORT ~StorageExistResponse();

    /////////////////////////////////////////////
    /// ModelBase overrides

    ASPOSE_DLL_EXPORT void validate() override;

    ASPOSE_DLL_EXPORT web::json::value toJson() const override;
    ASPOSE_DLL_EXPORT void fromJson(web::json::value& json) override;

    ASPOSE_DLL_EXPORT void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    ASPOSE_DLL_EXPORT void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// StorageExistResponse members

    /// <summary>
    /// 
    /// </summary>
    ASPOSE_DLL_EXPORT bool isExist() const;
    ASPOSE_DLL_EXPORT bool isExistIsSet() const;
    ASPOSE_DLL_EXPORT void unsetIsExist();
    ASPOSE_DLL_EXPORT void setIsExist(bool value);

private:
    bool m_IsExist;
    bool m_IsExistIsSet;
};

}
}
}

#endif /* COM_ASPOSE_MODEL_StorageExistResponse_H_ */
