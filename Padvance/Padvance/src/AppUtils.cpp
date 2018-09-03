#include <Padvance/AppUtils.h>
#include <Padvance/Tls.h>
#include <e32std.h>
#include <e32cmn.h>
#include <e32base.h>

namespace Padvance 
    {
            void AppUtils::InitializeSimpleAppL()
                {
                     Padvance::TlsData *data = reinterpret_cast<Padvance::TlsData*>(Dll::Tls());
                     
                     if (!data) 
                         {
                             return;
                         }
                    
                     data->iCleanup = CTrapCleanup::New();
                     data->iScheduler = new (ELeave) CActiveScheduler();
                     
                     CleanupStack::PushL(data->iScheduler);
                     CActiveScheduler::Install(data->iScheduler);
                }
            
            void AppUtils::ShutdownSimpleAppL()
                {
                    Padvance::TlsData *data = reinterpret_cast<Padvance::TlsData*>(Dll::Tls());
                    
                    if (!data) 
                        {
                            User::Leave(KErrGeneral);
                        }
                   
                    CleanupStack::PopAndDestroy(data->iScheduler);
                    delete data->iCleanup;
                    
                    data->iCleanup = NULL;
                    data->iScheduler = NULL;
                }
        };

