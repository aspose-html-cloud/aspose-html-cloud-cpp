#ifndef COM_ASPOSE_MODEL_FileVersion_H_
#define COM_ASPOSE_MODEL_FileVersion_H_


#include "ModelBase.h"


namespace com {
namespace aspose {
namespace model {

    /// <summary>
/// File Version
/// </summary>
    class  ConversionResult : public ModelBase
    {
    public:
        ASPOSE_DLL_EXPORT ConversionResult();
        ASPOSE_DLL_EXPORT ~ConversionResult();

        /////////////////////////////////////////////
        /// ModelBase overrides

        ASPOSE_DLL_EXPORT void validate() override;

        ASPOSE_DLL_EXPORT web::json::value toJson() const override;
        ASPOSE_DLL_EXPORT void fromJson(web::json::value& json) override;
        ASPOSE_DLL_EXPORT std::string toString() const override;

        ASPOSE_DLL_EXPORT void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
        ASPOSE_DLL_EXPORT void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

        /////////////////////////////////////////////
        /// ConversionResult members

        /// <summary>
        /// Http result code.
        /// </summary>
        ASPOSE_DLL_EXPORT unsigned short getCode() const;
        ASPOSE_DLL_EXPORT void setCode(unsigned short value);

        /// <summary>
        /// Conversion ID.
        /// </summary>
        ASPOSE_DLL_EXPORT utility::string_t getId() const;
        ASPOSE_DLL_EXPORT void setId(utility::string_t value);

        /// <summary>
        /// Conversion status.
        /// </summary>
        ASPOSE_DLL_EXPORT utility::string_t getStatus() const;
        ASPOSE_DLL_EXPORT void setStatus(utility::string_t value);

        /// <summary>
        /// Error description.
        /// </summary>
        ASPOSE_DLL_EXPORT utility::string_t getDescription() const;
        ASPOSE_DLL_EXPORT void setDescription(utility::string_t value);

        /// <summary>
        /// Result file.
        /// </summary>
        ASPOSE_DLL_EXPORT utility::string_t getFile() const;
        ASPOSE_DLL_EXPORT void setFile(utility::string_t value);


    protected:
        unsigned short m_code;
        utility::string_t m_id;
        utility::string_t m_status;
        utility::string_t m_description;
        utility::string_t m_file;
    };
}
}
}
#endif