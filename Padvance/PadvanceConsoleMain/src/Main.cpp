#include <PadvanceMain/Main.h>
#include <Padvance/AppUtils.h>

#include <e32def.h>
#include <e32std.h>
#include <e32cons.h>

void MainExecutor::ConstructL(const TDesC &aConsoleName) 
    {
        iConsole = Console::NewL(aConsoleName, TSize(KConsFullScreen, KConsFullScreen));
    }

MainExecutor *MainExecutor::NewL()
    {
        MainExecutor *executor = MainExecutor::NewL();
        CleanupStack::Pop();
        
        return executor;
    }

MainExecutor::MainExecutor()
    {
    
    }

MainExecutor *MainExecutor::NewLC(const TDesC &aConsoleName) 
    {
        MainExecutor *executor = new (ELeave) MainExecutor();
        CleanupStack::PushL(executor);
        executor->ConstructL(aConsoleName);
        
        return executor;
    }

void MainExecutor::MainL() 
    {
        iConsole->Write(_L("Hello World! I'm actual words!"));
        iConsole->Getch();
    }

using namespace Padvance;

void EntryPointWrapper() {
    AppUtils::InitializeSimpleAppL();
    
    MainExecutor *executor = MainExecutor::NewLC(_L("ConsoleTestEnvironment"));
    executor->MainL();
    
    AppUtils::ShutdownSimpleAppL();
}

TInt E32Main() 
    {
        TRAPD(err, EntryPointWrapper());
        return err;
    }
