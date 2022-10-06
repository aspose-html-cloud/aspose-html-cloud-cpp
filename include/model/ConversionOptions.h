#ifndef COM_ASPOSE_API_ConversionOptions_H_
#define COM_ASPOSE_API_ConversionOptions_H_

#include <boost/optional.hpp>
#include "ModelBase.h"


namespace com {
namespace aspose {
namespace model {

class ConversionOptions  : public ModelBase {

public:
	ASPOSE_DLL_EXPORT ConversionOptions();
	ASPOSE_DLL_EXPORT ~ConversionOptions();

    /// ModelBase overrides
    ASPOSE_DLL_EXPORT void validate() override;
    ASPOSE_DLL_EXPORT web::json::value toJson() const override;
    ASPOSE_DLL_EXPORT void fromJson(web::json::value& json) override;
    ASPOSE_DLL_EXPORT std::string toString() const override;

    ASPOSE_DLL_EXPORT void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    ASPOSE_DLL_EXPORT void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    ASPOSE_DLL_EXPORT ConversionOptions* setWidth(double value);
    ASPOSE_DLL_EXPORT ConversionOptions* setHeight(double value);
    ASPOSE_DLL_EXPORT ConversionOptions* setLeftMargin(double value);
    ASPOSE_DLL_EXPORT ConversionOptions* setRightMargin(double value);
    ASPOSE_DLL_EXPORT ConversionOptions* setTopMargin(double value);
    ASPOSE_DLL_EXPORT ConversionOptions* setBottomMargin(double value);




private:
    boost::optional<double> m_width;
    boost::optional<double> m_height;
    boost::optional<double> m_leftMargin;
    boost::optional<double> m_rightMargin;
    boost::optional<double> m_topMargin;
    boost::optional<double> m_bottomMargin;


};


}
}
}
#endif /* COM_ASPOSE_API_ConversionOptions_H_ */
