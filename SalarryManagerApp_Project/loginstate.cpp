#include "loginstate.h" // class's header file
#include "MyDefine.h"
#include "AppState.h" // inheriting class's header file
#include "MyDefine.h"
#include "MainMenuState.h"
#include "SalaryManager.h"
#include "MyUtil.h"
// class constructor
LoginState::LoginState()
{
	strcpy(m_userName, "");
	strcpy(m_passWord, "");
}

// class destructor
LoginState::~LoginState()
{
	// insert your code here
}
void LoginState::Init()
{

}
void LoginState::Update()
{
	  CLEAR_SCREEN();
      DisplayMenu();
      printf("\n  + Username: ");  scanf("%s", &m_userName);
      printf("\n  + Password: ");  
      MyUtil::GetPass("",m_passWord);

      if( strlen(m_userName) > 0 && strlen(m_userName) > 0)
      {
	       bool isLogin = GetSalaryMgr()->OnLogin(m_userName, m_passWord);
	       if(isLogin)
	       {
	       	    printf(TEXT_LOGIN_SUCEED);
	       	    printf("\n Loading database!");
	       	    Sleep(1000);
	       	    GetSalaryMgr()->LoadDataBase();
	         	Sleep(1000);
		        GetSalaryMgr()->SetAppState(new MainMenuState());
				return;
		   }else
		   {
		        printf(TEXT_LOGIN_INCORRECT);
				Sleep(1000);
		   }
	  }
}
void LoginState::DisplayMenu()
{
      printf("\n\n\t   LOGIN \n");
      printf("\n -----------------------------------------\n");
      printf("\n  Please enter your username and password!\n");
      Sleep(500);
}
