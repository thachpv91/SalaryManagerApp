#include "listofstaffstate.h" // class's header file
#include "SalaryManager.h"
#include "MyDefine.h"
#include "StaffInfor.h"
#include "StaffInforDB.h"
#include "StaffMgrState.h";
#include "DataBase.h"
// class constructor
ListOfStaffState::ListOfStaffState()
{
	// insert your code here
}

// class destructor
ListOfStaffState::~ListOfStaffState()
{
	// insert your code here
}
void ListOfStaffState::Init()
{
	DataBase * dataBase = GetSalaryMgr()->GetDataBase();
    m_staffInforDB = dataBase->GetStaffInforDB();
    vector<StaffInfor * > listStaff = m_staffInforDB->GetData();
    unsigned int maxNumberStaff = listStaff.size();
    m_maxPage = (maxNumberStaff/10) > 0? (maxNumberStaff/10): 1;
    m_page = 1;
}
void ListOfStaffState::Update()
{
	  CLEAR_SCREEN();
      DisplayMenu();
      DisplayAllStaffInfor(m_page);
      DisplayMenu2();
      char c = getch();
      switch(c)
      {
      	   case SPECIAL_KEY: break;
	       case ESC_KEY: GetSalaryMgr()->SetAppState(new StaffMgrState()); return;
	       case RIGHT_SKEY: NextPage(); break;
	       case LEFT_SKEY : PreviousPage(); break;             
	  }

}
void ListOfStaffState::DisplayMenu()
{
     printf("\n List of Staff \n");
     printf("\n --------------------------------------------------------------------------\n");
     // Id  FullName  BirthDay  Sex  Address 
     // TEXT_FORMAT_STAFF_INFOR "%2d %-25s %-20s %-5d %s"
     printf("%3s %-25s %-12s %-8s %s", "Id", "FullName" , "BirthDay", "Sex", "Address");
     printf("\n --------------------------------------------------------------------------\n");
}
void ListOfStaffState::DisplayMenu2()
{
	 char temp[255] = "";
	 sprintf(temp, TEXT_FORMAT_PAGE_NUMBER, m_page);
     printf("\n --------------------------------------------------------------------------");
     printf("%s", temp);
     // printf("\n                      Page: %d                           ")
     printf("\n\n        <-' : Pre         Esc: To back              Next :  '->' ");
     printf("\n --------------------------------------------------------------------------\n");
}
void ListOfStaffState::DisplayAllStaffInfor(int page)
{
   vector<StaffInfor * > listStaff = m_staffInforDB->GetData();
   unsigned int maxStaff = listStaff.size();
   const unsigned int numerStaffInPage = 10;
   unsigned int beginIndex = (page - 1) * numerStaffInPage;
   unsigned int endIndex   = beginIndex + numerStaffInPage;
   if( endIndex > maxStaff) endIndex = maxStaff;
   // for()
   for(unsigned int i = beginIndex; i < endIndex; i++)
   {
   		char * str = listStaff[i]->ToString();
   		printf(" %s\n", str);
   		SAFE_DEL(str);
   }
}
void ListOfStaffState::NextPage()
{
    if(m_page < m_maxPage)
    {
	    ++m_page;
	}
}
void ListOfStaffState::PreviousPage()
{
    if(m_page > 1)
    {
	    --m_page;
	} 
}
