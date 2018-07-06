#ifndef COM_ASPOSE_MODEL_StorageExistResponse_H_
#define COM_ASPOSE_MODEL_StorageExistResponse_H_


#include "MessageResponse.h"
#include <cpprest/details/basic_types.h>

namespace com {
namespace aspose {
namespace model {

/// <summary>
/// 
/// </summary>
class  StorageExistResponse
    : public MessageResponse
{
public:
    StorageExistResponse();
    virtual ~StorageExistResponse();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// StorageExistResponse members

    /// <summary>
    /// 
    /// </summary>
    bool isExist() const;
    bool isExistIsSet() const;
    void unsetIsExist();
    void setIsExist(bool value);

protected:
    bool m_IsExist;
    bool m_IsExistIsSet;
};

}
}
}

#endif /* COM_ASPOSE_MODEL_StorageExistResponse_H_ */
