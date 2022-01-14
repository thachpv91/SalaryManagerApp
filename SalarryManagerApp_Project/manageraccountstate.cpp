#include "manageraccountstate.h" // class's header file
#include "MyDefine.h"
#include "SalaryManager.h"
#include "MainMenuState.h"
#include "Search_Edit_Account_State.h"
#include "DataBase.h"
#include "AccountDB.h"
#include "Account.h"
// class constructor
ManagerAccountState::ManagerAccountState()
{
	m_appDB = 0;// = GetSalaryMgr()->GetDataBase();
    m_accDB = 0;
}

// class destructor
ManagerAccountState::~ManagerAccountState()
{
	// insert your code here
}
void ManagerAccountState::Init()
{
	 m_appDB = GetSalaryMgr()->GetDataBase();
     m_accDB = m_appDB->GetAccountDB();	
}
void ManagerAccountState::Update()
{
	  CLEAR_SCREEN();
      DisplayMenu();
      char c ;
      scanf(" %c", &c);
      
      switch(c)
      {
	      case '1' : DisplayListAccount(); getch();break;
	      case '2' : GetSalaryMgr()->SetAppState(new Search_Edit_Account_State()); return;
	      case '3' : ImportFromFile(); break;
	      case '4' : ExportToFile(); break;
	      case '5' : GetSalaryMgr()->SetAppState(new MainMenuState()); return;
	      default  : 
		             printf(TEXT_PLEASE_RECHOISE); 
					 Sleep(500);
	  };

	  
}
void ManagerAccountState::DisplayMenu()
{
     printf("\n\n\t   Manager Account \n");
     printf("\n --------------------------------\n");
     printf("\n 1. List Account");
     printf("\n 2. Search and Edit Account");
     printf("\n 3. Import Database from a file( *.txt)");
     printf("\n 4. Export Database to a file( *.txt)");
     printf("\n 5. To Back");
     printf("\n --------------------------------\n");
     printf("\n Choise: ");
}
void ManagerAccountState::ImportFromFile()
{
     char fileName[255] = "";
     printf("\n\n Import Database");
     printf("\n + Enter Import file name: "); scanf(" %s", fileName);
     m_accDB->Import(fileName);
     printf("\n\n Import done!");
     Sleep(1000);
}
void ManagerAccountState::ExportToFile()
{
	 const char * defaultFile = "AccountDB.txt";
     printf("\n\n Export Database");
     printf("\n Export to file 'AccountDB.txt'");
     m_accDB->Export(defaultFile);
	 printf("\n\n Export done!");
	 Sleep(1000);
}
void ManagerAccountState::DisplayListAccount()
{
	 printf("\n\n List account\n");
     vector<Account*> accList = m_accDB->GetData();
	 char accStr[255];
	 for(unsigned int i = 0; i < accList.size(); i++)
	 {
		 accList[i]->ToString(accStr);
		 printf("\n %s", accStr);
	 }  
}
