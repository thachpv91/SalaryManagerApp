#include "search_edit_account_state.h" // class's header file
#include "SalaryManager.h"
#include "MainMenuState.h"
#include "MyDefine.h"
// class constructor
Search_Edit_Account_State::Search_Edit_Account_State()
{
	// insert your code here
}

// class destructor
Search_Edit_Account_State::~Search_Edit_Account_State()
{
	// insert your code here
}
void Search_Edit_Account_State::Init()
{

}
void Search_Edit_Account_State::Update()
{
	  CLEAR_SCREEN();
      DisplayMenu();
      char c ;
      scanf(" %c", &c);
      
      switch(c)
      {
	      case '1' : printf(TEXT_NOT_IMPLEMENT); Sleep(1000); break;
	      case '2' : GetSalaryMgr()->SetAppState(new MainMenuState()); return;
	      default  : 
		             printf(TEXT_PLEASE_RECHOISE); 
					 Sleep(500);
	  };

	  
}
void Search_Edit_Account_State::DisplayMenu()
{
     printf("\n\n\t   Account Manager \n");
     printf("\n --------------------------------\n");
     printf("\n 1. Search and Edit");
     printf("\n 2. Back ");
     printf("\n --------------------------------\n");
     printf("\n Choise: ");
}
