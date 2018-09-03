#include <Padvance/Tls.h>
#include <e32std.h>

TInt DllMain()
    {
        // Allocate without leave
        Padvance::TlsData *tlsData = reinterpret_cast<Padvance::TlsData*>(
                User::Alloc(sizeof(Padvance::TlsData)));
        
        if (!tlsData) 
            {   
                return KErrNoMemory;
            }
        
        Dll::SetTls(tlsData);
    }
