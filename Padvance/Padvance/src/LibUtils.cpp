#include <Padvance/LibUtils.h>

namespace Padvance
    {
        /*
         * \brief Checks if a library exists in Symbian
         * \param aLibName The name of the library
         * 
         * \returns 0 if the library exists, otherwise error code.
         */
        TInt LibUtils::LibraryExists(const TDesC &aLibName)
            {
                RLibrary library;
                TInt err = library.Load(aLibName);
                
                if (err != KErrNone)
                    {
                        return err;
                    }
                
                library.Close();
                return KErrNone;
            }
    }
