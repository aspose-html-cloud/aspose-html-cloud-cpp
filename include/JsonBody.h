#ifndef COM_ASPOSE_MODEL_JsonBody_H_
#define COM_ASPOSE_MODEL_JsonBody_H_


#include "IHttpBody.h"
#include <cpprest/json.h>

namespace com {
namespace aspose {
namespace model {

class JsonBody : public IHttpBody
{
public:
    JsonBody( const web::json::value& value );
    virtual ~JsonBody();

    void writeTo( std::ostream& target ) override;

protected:
    web::json::value m_Json;
};

}
}
}

#endif /* COM_ASPOSE_MODEL_JsonBody_H_ */
