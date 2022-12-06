#ifndef COM_ASPOSE_API_VectorizationOptions_H_
#define COM_ASPOSE_API_VectorizationOptions_H_

#include <boost/optional.hpp>
#include "model/ConversionOptions.h"


namespace com {
namespace aspose {
namespace model {

class VectorizationOptions  : public ConversionOptions {

public:
	ASPOSE_DLL_EXPORT VectorizationOptions();
	ASPOSE_DLL_EXPORT ~VectorizationOptions();

    /// ModelBase overrides
    ASPOSE_DLL_EXPORT void validate() override;
    ASPOSE_DLL_EXPORT web::json::value toJson() const override;
    ASPOSE_DLL_EXPORT void fromJson(web::json::value& json) override;
    ASPOSE_DLL_EXPORT std::string toString() const override;

    ASPOSE_DLL_EXPORT void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    ASPOSE_DLL_EXPORT void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;


    ASPOSE_DLL_EXPORT VectorizationOptions* setErrorThreshold(double value);
    ASPOSE_DLL_EXPORT VectorizationOptions* setMaxIteration(int value);
    ASPOSE_DLL_EXPORT VectorizationOptions* setColorLimit(int value);
    ASPOSE_DLL_EXPORT VectorizationOptions* setLineWidth(double value);

private:
    boost::optional<double> m_error_threshold;
    boost::optional<int> m_max_iterations;
    boost::optional<int> m_colors_limit;
    boost::optional<double> m_line_width;
};


}
}
}
#endif /* COM_ASPOSE_API_VectorizationOptions_H_ */
