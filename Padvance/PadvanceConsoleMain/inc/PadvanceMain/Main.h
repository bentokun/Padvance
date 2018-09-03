#ifndef __MAIN_H__
#define __MAIN_H__

#include <e32base.h>

class MainExecutor
    {
        CConsoleBase *iConsole;
        
protected:
        explicit MainExecutor();
        void ConstructL(const TDesC &aConsoleName);
         
public:
        void MainL();
        
        static MainExecutor *NewL();
        static MainExecutor *NewLC(const TDesC &aConsoleName);
    };

TInt E32Main();

#endif
