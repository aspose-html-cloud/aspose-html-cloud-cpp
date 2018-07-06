#ifndef COM_ASPOSE_MODEL_RemoveFileResponse_H_
#define COM_ASPOSE_MODEL_RemoveFileResponse_H_


#include "MessageResponse.h"
#include <cpprest/details/basic_types.h>

namespace com {
namespace aspose {
namespace model {

/// <summary>
/// 
/// </summary>
class  RemoveFileResponse
    : public MessageResponse
{
public:
    RemoveFileResponse();
    virtual ~RemoveFileResponse();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// RemoveFileResponse members


protected:
};

}
}
}

#endif /* COM_ASPOSE_MODEL_RemoveFileResponse_H_ */
