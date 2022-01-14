#include "dispaysalarystate.h" // class's header file
#include "SalaryManager.h"
#include "MyDefine.h"
#include "StaffInfor.h"
#include "StaffInforDB.h"
#include "Salary.h"
#include "SalaryDB.h"
#include "SalaryMgrState.h";
#include "DataBase.h"
// class constructor
DispaySalaryState::DispaySalaryState()
{
	// insert your code here
}

// class destructor
DispaySalaryState::~DispaySalaryState()
{
	// insert your code here
}
void DispaySalaryState::Init()
{
	DataBase * dataBase = GetSalaryMgr()->GetDataBase();
    m_salaryDB = dataBase->GetSalaryDB();
    m_salaryList = m_salaryDB->GetData();
    unsigned int maxNumberStaff = m_salaryList.size();
    m_maxPage = (maxNumberStaff/10) > 0? (maxNumberStaff/10): 1;
    m_page = 1;
}
void DispaySalaryState::Update()
{
	  CLEAR_SCREEN();
      DisplayMenu();
      DisplaySalary(m_page);
      DisplayMenu2();
      char c = getch();
      switch(c)
      {
      	   case SPECIAL_KEY: break;
	       case ESC_KEY: GetSalaryMgr()->SetAppState(new SalaryMgrState()); return;
	       case RIGHT_SKEY: NextPage(); break;
	       case LEFT_SKEY : PreviousPage(); break;             
	  }

}
void DispaySalaryState::DisplayMenu()
{
     printf("\n List of Staff \n");
     printf("\n--------------------------------------------------------------------------------------------------\n");
     // // Id  Name NgayThang So_cong Heso  KhenThuong  KyLuat TamUng Thuc_linh
     printf("%3s %-20s %-12s %-4s %-6s %-9s %-9s %-9s %-7s", "Id", "Name" , "Date", "Workday", "CP", "Bonus", "Dis..", "AP", "Salary(trieu)");
     printf("\n---------------------------------------------------------------------------------------------------\n");
}
void DispaySalaryState::DisplayMenu2()
{
	 char temp[255] = "";
	 sprintf(temp, TEXT_FORMAT_PAGE_NUMBER, m_page);
     printf("\n --------------------------------------------------------------------------");
     printf("%s", temp);
     // printf("\n                      Page: %d                           ")
     printf("\n\n        <-' : Pre         Esc: To back              Next :  '->' ");
     printf("\n --------------------------------------------------------------------------\n");
}
void DispaySalaryState::DisplaySalary(int page)
{
   m_salaryList = m_salaryDB->GetData();
   unsigned int maxStaff = m_salaryList.size();
   const unsigned int numerStaffInPage = 10;
   unsigned int beginIndex = (page - 1) * numerStaffInPage;
   unsigned int endIndex   = beginIndex + numerStaffInPage;
   if( endIndex > maxStaff) endIndex = maxStaff;
   // for()
   for(unsigned int i = beginIndex; i < endIndex; i++)
   {
   		char * str = m_salaryList[i]->ToString();
   		printf(" %s\n", str);
   		SAFE_DEL(str);
   }
}
void DispaySalaryState::NextPage()
{
    if(m_page < m_maxPage)
    {
	    ++m_page;
	}
}
void DispaySalaryState::PreviousPage()
{
    if(m_page > 1)
    {
	    --m_page;
	} 
}

