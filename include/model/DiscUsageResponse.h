#ifndef COM_ASPOSE_MODEL_DiscUsageResponse_H_
#define COM_ASPOSE_MODEL_DiscUsageResponse_H_


#include "model/MessageResponse.h"
#include <cpprest/details/basic_types.h>
#include "model/DiscUsage.h"

namespace com {
namespace aspose {
namespace model {

/// <summary>
/// 
/// </summary>
class DiscUsageResponse : public MessageResponse
{
public:
    ASPOSE_DLL_EXPORT DiscUsageResponse();
    ASPOSE_DLL_EXPORT ~DiscUsageResponse();

    /////////////////////////////////////////////
    /// ModelBase overrides

    ASPOSE_DLL_EXPORT void validate() override;

    ASPOSE_DLL_EXPORT web::json::value toJson() const override;
    ASPOSE_DLL_EXPORT void fromJson(web::json::value& json) override;

    ASPOSE_DLL_EXPORT void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    ASPOSE_DLL_EXPORT void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// DiscUsageResponse members

    /// <summary>
    /// 
    /// </summary>
    ASPOSE_DLL_EXPORT std::shared_ptr<DiscUsage> getDiscUsage() const;
    ASPOSE_DLL_EXPORT bool discUsageIsSet() const;
    ASPOSE_DLL_EXPORT void unsetDiscUsage();
    ASPOSE_DLL_EXPORT void setDiscUsage(std::shared_ptr<DiscUsage> value);

private:
    std::shared_ptr<DiscUsage> m_DiscUsage;
    bool m_DiscUsageIsSet;
};

}
}
}

#endif /* COM_ASPOSE_MODEL_DiscUsageResponse_H_ */
