#include "application.h" // class's header file
#include "AppState.h"
#include "MyDefine.h"
// class constructor
Application::Application()
: m_isExit(false)
, m_isChangedState(false)
, m_currentState(0) // NULL
, m_tempState(0)
{
}
void Application::Init()
{
}
void Application::Update()
{
	/*if(m_isChangedState && m_tempState != NULL)
	{   
       SAFE_DEL(m_currentState);
       m_currentState = m_tempState;
       m_tempState = 0;
       m_isChangedState = false;
    } */
   	if(m_currentState)
	{  
       m_currentState->Update();
       
    }
}
void Application::Destroy()
{
   SAFE_DEL(m_currentState);
   SAFE_DEL(m_tempState);
}
// class destructor
Application::~Application()
{
	this->Destroy();
	// insert your code here
}
void Application::OnExit()
{
	m_isExit = true;
}
bool Application::IsRunning()
{
	return !m_isExit;
}
void Application::SetAppState(AppState * appState)
{
    if(appState != 0)
    {
	   m_tempState = m_currentState;
	   m_currentState = appState;	   
	   m_currentState->Init();
	   SAFE_DEL(m_tempState); 	    
	}
	
}
AppState * Application::GetAppState()
{
    return m_currentState;
}

