#ifndef COM_ASPOSE_MODEL_MessageResponse_H_
#define COM_ASPOSE_MODEL_MessageResponse_H_


#include "ModelBase.h"
#include <cpprest/details/basic_types.h>

namespace com {
namespace aspose {
namespace model {

/// <summary>
/// 
/// </summary>
class MessageResponse : public ModelBase
{
public:
    ASPOSE_DLL_EXPORT MessageResponse();
    ASPOSE_DLL_EXPORT ~MessageResponse();

    /////////////////////////////////////////////
    /// ModelBase overrides

    ASPOSE_DLL_EXPORT void validate() override;

    ASPOSE_DLL_EXPORT web::json::value toJson() const override;
    ASPOSE_DLL_EXPORT void fromJson(web::json::value& json) override;

    ASPOSE_DLL_EXPORT void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    ASPOSE_DLL_EXPORT void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// MessageResponse members

    /// <summary>
    /// 
    /// </summary>
    ASPOSE_DLL_EXPORT unsigned short getCode() const;
    ASPOSE_DLL_EXPORT void setCode(unsigned short value);
    /// <summary>
    /// 
    /// </summary>
    ASPOSE_DLL_EXPORT utility::string_t getStatus() const;
    ASPOSE_DLL_EXPORT bool statusIsSet() const;
    ASPOSE_DLL_EXPORT void unsetStatus();
    ASPOSE_DLL_EXPORT void setStatus(utility::string_t value);

protected:
    unsigned short m_Code;
    utility::string_t m_Status;
    bool m_StatusIsSet;
};

}
}
}

#endif /* COM_ASPOSE_MODEL_MessageResponse_H_ */
