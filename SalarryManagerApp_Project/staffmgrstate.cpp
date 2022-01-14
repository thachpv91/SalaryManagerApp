#include "staffmgrstate.h" // class's header file
#include "AppState.h" // inheriting class's header file
#include "MyDefine.h"
#include "SalaryManager.h"
#include "MainMenuState.h"
#include "ListOfStaffState.h"
#include "Search_Edit_Remove_State.h"
#include "AddNewStaffState.h"

// class constructor
StaffMgrState::StaffMgrState()
{
}

// class destructor
StaffMgrState::~StaffMgrState()
{
}
void StaffMgrState::Init()
{

}
void StaffMgrState::Update()
{
	  CLEAR_SCREEN();
      DisplayMenu();
      char c ;
      scanf(" %c", &c);
      switch(c)
      {
	      case '1': GetSalaryMgr()->SetAppState(new ListOfStaffState());  return;
	      case '2': GetSalaryMgr()->SetAppState(new Search_Edit_Remove_State()); return;
	      case '3': GetSalaryMgr()->SetAppState(new AddNewStaffState()); return;
	      case '4': GetSalaryMgr()->SetAppState(new MainMenuState()); return;
	      default : printf(TEXT_PLEASE_RECHOISE); getch(); break;
	  };
}
void StaffMgrState::DisplayMenu()
{
     printf("\n\n\t Staff Manager\n");
     printf("\n --------------------------------\n");
     printf("\n 1. Display list of staff");
     printf("\n 2. Search, Edit and remove");
     printf("\n 3. Add new staff");
     printf("\n 4. Back ");
     printf("\n --------------------------------\n");
     printf("\n Choise: ");
}
