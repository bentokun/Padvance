#ifndef __TLS_H__
#define __TLS_H__

#include <e32base.h>

namespace Padvance
    {
        struct TlsData 
            {
                CActiveScheduler *iScheduler;
                CTrapCleanup *iCleanup;
        
                // Reserved part
            };
    }

#endif
