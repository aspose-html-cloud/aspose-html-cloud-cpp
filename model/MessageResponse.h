#ifndef COM_ASPOSE_MODEL_MessageResponse_H_
#define COM_ASPOSE_MODEL_MessageResponse_H_


#include "../ModelBase.h"

#include <cpprest/details/basic_types.h>

namespace com {
namespace aspose {
namespace model {

/// <summary>
/// 
/// </summary>
class  MessageResponse
    : public ModelBase
{
public:
    MessageResponse();
    virtual ~MessageResponse();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// MessageResponse members

    /// <summary>
    /// 
    /// </summary>
    unsigned short getCode() const;
    void setCode(unsigned short value);
    /// <summary>
    /// 
    /// </summary>
    utility::string_t getStatus() const;
    bool statusIsSet() const;
    void unsetStatus();
    void setStatus(utility::string_t value);

protected:
    unsigned short m_Code;
    utility::string_t m_Status;
    bool m_StatusIsSet;
};

}
}
}

#endif /* COM_ASPOSE_MODEL_MessageResponse_H_ */
