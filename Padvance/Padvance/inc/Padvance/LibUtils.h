#ifndef __LIBUTILS_H__
#define __LIBUTILS_H__

#include <e32def.h>
#include <e32cmn.h>
#include <e32std.h>
#include <e32base.h>

namespace Padvance 
    {
        /* \brief Static class related to library */
        class LibUtils
            {
            public:
                /*
                 * \brief Checks if a library exists in Symbian
                 * \param aLibName The name of the library
                 * 
                 * \returns 0 if the library exists, otherwise error code.
                 */
                static EXPORT_C TInt LibraryExists(const TDesC &aLibName);
            };
    }

#endif
