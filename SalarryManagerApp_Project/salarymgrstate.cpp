#include "salarymgrstate.h" // class's header file
#include "MyDefine.h"
#include "SalaryManager.h"
#include "StaffInfor.h"
#include "MainMenuState.h"
#include "DispaySalaryState.h"
#include "DataBase.h"
#include "Salary.h"
#include "SalaryDB.h"
// class constructor
SalaryMgrState::SalaryMgrState()
{
	// insert your code here
}

// class destructor
SalaryMgrState::~SalaryMgrState()
{
	// insert your code here
}
void SalaryMgrState::Init()
{
       GetSalaryMgr()->ComputeSalary();
       GetSalaryMgr()->GetDataBase()->GetSalaryDB()->Save();
}
void SalaryMgrState::Update()
{
    CLEAR_SCREEN();
    DisplayMenu();
    char c = getch();
    switch(c)
    {
    	case '1': GetSalaryMgr()->SetAppState(new DispaySalaryState()); break;
    	case '2': printf("\n Not yet completed!"); Sleep(1000); break; 
		case '3': printf("\n Edit the salary info of staff: ( workday, bonus, discipline, ...");
		          printf("\n Not yet completed!"); Sleep(1000); break;
	    case '4': GetSalaryMgr()->SetAppState(new MainMenuState()); return;
		default : 
		          printf(TEXT_PLEASE_RECHOISE); 
				  Sleep(500);
	}
}
void SalaryMgrState::DisplayMenu()
{
     
     printf("\n\n    Salary Manager");
     printf("\n ---------------------------------\n");
     printf("\n 1. List of Salary ");
     printf("\n 2. Export to file");
     printf("\n 3. Search and modified salary infor");
     printf("\n 4. To Back ");
     printf("\n ----------------------------------");
     printf("\n Choise: ");
}
