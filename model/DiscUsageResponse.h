#ifndef COM_ASPOSE_MODEL_DiscUsageResponse_H_
#define COM_ASPOSE_MODEL_DiscUsageResponse_H_


#include "MessageResponse.h"
#include <cpprest/details/basic_types.h>
#include "DiscUsage.h"

namespace com {
namespace aspose {
namespace model {

/// <summary>
/// 
/// </summary>
class  DiscUsageResponse
    : public MessageResponse
{
public:
    DiscUsageResponse();
    virtual ~DiscUsageResponse();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// DiscUsageResponse members

    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<DiscUsage> getDiscUsage() const;
    bool discUsageIsSet() const;
    void unsetDiscUsage();
    void setDiscUsage(std::shared_ptr<DiscUsage> value);

protected:
    std::shared_ptr<DiscUsage> m_DiscUsage;
    bool m_DiscUsageIsSet;
};

}
}
}

#endif /* COM_ASPOSE_MODEL_DiscUsageResponse_H_ */
