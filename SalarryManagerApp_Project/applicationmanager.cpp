#include "applicationmanager.h" // class's header file
#include "MyDefine.h"
#include "Application.h"
//static 
ApplicationManager * ApplicationManager::m_instance = NULL;
ApplicationManager * ApplicationManager::GetInstance()
{
     if(m_instance == NULL)
     {
	     m_instance = new ApplicationManager();
	 }
	 return m_instance;
}
void ApplicationManager::FreeInstance()
{
    SAFE_DEL(m_instance);
}
// end static

// class constructor
ApplicationManager::ApplicationManager(): m_currentApp(NULL)
{
	// insert your code here
}

// class destructor
ApplicationManager::~ApplicationManager()
{
	// insert your code here
}
void ApplicationManager::StartApp(Application * newApp)
{
      if(newApp != NULL)
	  {
	      SAFE_DEL(m_currentApp);
	      m_currentApp = newApp;
	      
	  } 
	  if(m_currentApp == NULL )
	  {
	      printf(" This Application was die!");
	  }else
	  {
	  		m_currentApp->Init();
	  		while(m_currentApp->IsRunning())
	  		{
	    		  m_currentApp->Update();
	  		}
	  		m_currentApp->Destroy();
	 }
}

