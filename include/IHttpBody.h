#ifndef COM_ASPOSE_MODEL_IHttpBody_H_
#define COM_ASPOSE_MODEL_IHttpBody_H_


#include <iostream>
#include "defines.h"

namespace com {
namespace aspose {
namespace model {

class IHttpBody
{
public:
    virtual ~IHttpBody() { }

    virtual void writeTo( std::ostream& stream ) = 0;
};

}
}
}

#endif /* COM_ASPOSE_MODEL_IHttpBody_H_ */
