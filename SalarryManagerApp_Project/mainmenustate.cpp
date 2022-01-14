#include "mainmenustate.h" // class's header file
#include "MyDefine.h"
#include "SalaryManager.h"
#include "StaffMgrState.h"
#include "SalaryMgrState.h"
// class constructor
MainMenuState::MainMenuState()
{
	// insert your code here
}

// class destructor
MainMenuState::~MainMenuState()
{
}
void MainMenuState::Init()
{
}
void MainMenuState::Update()
{
	  CLEAR_SCREEN();
      DisplayMenu();
      char c ;
      scanf(" %c", &c);
      
      switch(c)
      {
	      case '1' : GetSalaryMgr()->SetAppState(new StaffMgrState()); return;
	      case '2' : GetSalaryMgr()->SetAppState(new SalaryMgrState()); return;
	      case '3' : printf("\n Application is close"); GetSalaryMgr()->OnExit(); return;
	      default  : 
		             printf(TEXT_PLEASE_RECHOISE); 
					 Sleep(500);
	  };

	  
}
void MainMenuState::DisplayMenu()
{
     printf("\n\n\t   Main Menu\n");
     printf("\n --------------------------------\n");
     printf("\n 1. Staff Manager");
     printf("\n 2. Salary Manager");
     printf("\n 3. Close ");
     printf("\n --------------------------------\n");
     printf("\n Choise: ");
}

