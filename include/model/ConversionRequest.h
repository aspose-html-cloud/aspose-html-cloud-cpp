#ifndef COM_ASPOSE_API_ConversionRequest_H_
#define COM_ASPOSE_API_ConversionRequest_H_

#include "ConversionOptions.h"
#include "ModelBase.h"

namespace com {
namespace aspose {
namespace model {


class ConversionRequest : public ModelBase
{

public:
    ASPOSE_DLL_EXPORT ConversionRequest();
    ASPOSE_DLL_EXPORT ~ConversionRequest();

    /// ModelBase overrides
    ASPOSE_DLL_EXPORT void validate() override;
    ASPOSE_DLL_EXPORT web::json::value toJson() const override;
    ASPOSE_DLL_EXPORT void fromJson(web::json::value& json) override;
    ASPOSE_DLL_EXPORT std::string toString() const override;

    ASPOSE_DLL_EXPORT void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    ASPOSE_DLL_EXPORT void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    // Setters
    ASPOSE_DLL_EXPORT ConversionRequest* setInputPath(const utility::string_t& value);
    ASPOSE_DLL_EXPORT ConversionRequest* setOutputFile(const utility::string_t& value);
    ASPOSE_DLL_EXPORT ConversionRequest* setStorageName(const utility::string_t& value);
    ASPOSE_DLL_EXPORT ConversionRequest* setOptions(const std::shared_ptr<ConversionOptions> value);


private:
    utility::string_t m_inputPath;
    utility::string_t m_outputPath;
    boost::optional<utility::string_t> m_storageName;
    std::shared_ptr<ConversionOptions> m_options;
};




}
}
}

#endif
