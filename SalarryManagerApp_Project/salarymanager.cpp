#include "salarymanager.h" // class's header file
#include "Application.h"
#include "MyDefine.h"
#include "MainMenuState.h"
#include "LoginState.h"
#include "DataBase.h"
#include "Account.h"
#include "Division.h"
#include "Position.h"
#include "StaffInfor.h"
#include "AccountDB.h"
#include "DivisionDB.h"
#include "PositionDB.h"
#include "StaffInforDB.h"
#include "Salary.h"
#include "SalaryDB.h"
#include "Timekeeping.h"
#include "TimekeepingDB.h"
#include "Bonus.h"
#include "BonusDB.h"
#include "Discipline.h"
#include "DisciplineDB.h"
#include "AdvancePayment.h"
#include "AdvancePaymentDB.h"

// class constructor
SalaryManager::SalaryManager()
{
	s_CurrentInstance = this;
}

// class destructor
SalaryManager::~SalaryManager()
{
	// insert your code here
}
void SalaryManager::Init()
{
	//LoadData("data.dat");
	dataBase = new DataBase();
	dataBase->Init();
	SetAppState(new LoginState());
}
void SalaryManager::LoadDataBase()
{
     dataBase->Load();
}
void SalaryManager::Destroy()
{
	dataBase->SaveAll();
	dataBase->Unload();
	SAFE_DEL(dataBase);
	Application::Destroy();
}
bool SalaryManager::OnLogin(char * userName, char * passWord)
{
	// Do check login
     currentAccount = dataBase->GetAccountDB()->Find(userName, passWord);
     if(currentAccount != NULL )
     {
	    return true;
	 }
	 return false;
}
void SalaryManager::GetDivisionStringByStaffId(int id, char * divisionStr)
{
     StaffInforDB * staffInforDB = dataBase->GetStaffInforDB();
     DivisionDB   * divisionDB =   dataBase->GetDivisionDB();
     
     StaffInfor   * staff = staffInforDB->FindById(id);
     if(staff == NULL)
     {
	     strcpy(divisionStr, "Unknown");
	     return;
	 }
     Division * division = divisionDB->FindById( staff->m_DivisionId );
     if(division == NULL)
     {
	     strcpy(divisionStr, "Unknown");
	     return;
	 }
	 strcpy(divisionStr, division->m_Name);
}
void SalaryManager::GetPositionStringByStaffId(int id, char * positionStr)
{
     StaffInforDB * staffInforDB = dataBase->GetStaffInforDB();
     PositionDB   * positionDB =   dataBase->GetPositionDB();
     
     StaffInfor   * staff = staffInforDB->FindById(id);
     if(staff == NULL)
     {
	     strcpy(positionStr, "Unknown");
	     return;
	 }
     Position * position = positionDB->FindById( staff->m_PositionId );
     if(position == NULL)
     {
	     strcpy(positionStr, "Unknown");
	     return;
	 }
	 strcpy(positionStr, position->m_Name);
}
void SalaryManager::DisplayPositionList()
{
    PositionDB * positionDB = dataBase->GetPositionDB();
    vector<Position *> positionlist = positionDB->GetData();
    for(unsigned int i = 0; i < positionlist.size(); i++)
    {
	     printf("\n  %-4d %s", positionlist[i]->m_Id,  positionlist[i]->m_Name);
	}
}
void SalaryManager::DisplayDivisionList()
{
    DivisionDB * DivisionDB = dataBase->GetDivisionDB();
    vector<Division *> divisonlist = DivisionDB->GetData();
    for(unsigned int i = 0; i < divisonlist.size(); i++)
    {
	     printf("\n  %-4d %s", divisonlist[i]->m_Id,  divisonlist[i]->m_Name);
	}
}
void SalaryManager::DisplayAllInforStaff(int idStaff)
{
     StaffInforDB * staffInforDB = dataBase->GetStaffInforDB();
     StaffInfor   * staff = staffInforDB->FindById(idStaff);
     if(staff == NULL) return;
     
    char positionStr[255], divisionStr[255];
    char * birthdayStr = staff->m_BirthDay.ToString();
    char sexStr[10];
    if(staff->m_Sex == MALE)         strcpy(sexStr, "Nam");
	else if( staff->m_Sex == FEMALE) strcpy(sexStr, "Nu");
	else strcpy(sexStr, "Khac");
	GetDivisionStringByStaffId(staff->m_Id, divisionStr); 
	GetPositionStringByStaffId(staff->m_Id, positionStr); 
			
    printf("\n %d %s %s %s %s %s %s", staff->m_Id, staff->m_FullName,
		  birthdayStr, sexStr, staff->m_Address, positionStr, divisionStr);
}
void SalaryManager::ComputeSalary()
{
	// Id  Name NgayThang So_cong Heso  KhenThuong  KyLuat TamUng Thuc_linh
	vector<StaffInfor *> staffList        = dataBase->GetStaffInforDB()->GetData();
	BonusDB *      bonusDB        = dataBase->GetBonusDB();
	PositionDB *   positionDB     = dataBase->GetPositionDB();
	DisciplineDB * disciplineDB    = dataBase->GetDisciplineDB();
	AdvancePaymentDB * advancePaymentDB        = dataBase->GetAdvancePaymentDB();
	TimekeepingDB * timekeepingDB = dataBase->GetTimekeepingDB();
	
	SalaryDB * salaryDB = dataBase->GetSalaryDB();
	salaryDB->UnLoad();
	for(unsigned int i = 0; i < staffList.size(); i++)
	{
		 //printf("\n\n Tinh luong cho: %s", staffList[i]->m_FullName);
	     Salary * salary = new Salary(*staffList[i]); // ID Name
	     Timekeeping * timekeeping = timekeepingDB->FindByStaffId(staffList[i]->m_Id);
	     if(timekeeping)
	     {
	       //printf("\n Ngay Cong: %d", timekeeping->m_workday);
		   //printf("\n Ngay: %s", timekeeping->m_date.ToString());
		   salary->m_date = timekeeping->m_date; // Ngay Thang
	       salary->m_wordDay = timekeeping->m_workday; // Ngay cong
	     }
	     
	     Position * position = positionDB->FindById(staffList[i]->GetPositionId());
	     if(position)
	     {
	     	 //printf("\n He so luong: %d", position->m_CoefficientPay);
		     salary->m_coefficientPay = position->m_CoefficientPay; // He so luong
		     strcpy(salary->m_position, position->m_Name);  // Ten vi tri cong viec
		 }
		 
		 // Id  Name NgayThang So_cong Heso  KhenThuong  KyLuat TamUng Thuc_linh
	     
	     Bonus * bonus = bonusDB->FindByStaffId(staffList[i]->m_Id);
	     if(bonus)
	     {
	     	//  printf("\n Bonus: %lu", bonus->GetMoney()); 
		     salary->m_bonus = bonus->GetMoney();  // KhenThuong
		 }
		 
		 Discipline * discipline = disciplineDB->FindByStaffId(staffList[i]->m_Id);
		 if(discipline)
		 {
		 	salary->m_discipline = discipline->GetMoney();  // Ky Luat
		 }
	     
	     AdvancePayment * advancePayment = advancePaymentDB->FindByStaffId(staffList[i]->m_Id);
	     if(advancePayment)
	     {
		  	salary->m_advancePayment = advancePayment->GetMoney(); // Tam ung
		  	//printf("\n %lu",salary->m_advancePayment );
		 }
		 //(socong* luongcoban/26) * heso + khenthuong – kyluat – tamung
         salary->ComputeSalaryMoney();
	     salaryDB->AddSalary(salary);
	     //getch();
	}
	 
}
//-------------------------
SalaryManager * SalaryManager::s_CurrentInstance = 0;
SalaryManager * SalaryManager::GetInstance()
{
	return s_CurrentInstance;
}

