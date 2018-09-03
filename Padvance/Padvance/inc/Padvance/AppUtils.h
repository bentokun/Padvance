#ifndef __APPUTILS_H__
#define __APPUTILS_H__

#include <e32base.h>

namespace Padvance 
    {
        class AppUtils 
            {
        public:
            /* !\brief Intended to use for app which doesn't invole GUI and still want
             * to set up things good!
             */
            static EXPORT_C void InitializeSimpleAppL();
            
            /* !\brief Shutdown a simple app which initialized using this API.
             */
            static EXPORT_C void ShutdownSimpleAppL();
            };
    }

#endif
