#ifndef SALARYMANAGER_H
#define SALARYMANAGER_H

//#include <vector.h>
#include "Application.h"
#include "Account.h"
class DataBase;
class Salary;
class SalaryDB;
class StaffInfor;
class MainMenuState;
class Account;
//class Application;
// No description
class SalaryManager : public Application
{
	// private section
	public:
		// class constructor
		SalaryManager();
		// class destructor
		~SalaryManager();
		
		virtual void Init();
		virtual void Destroy();
		
		bool OnLogin(char * userName, char * passWord);
		
		void LoadDataBase();
		void ComputeSalary();
		
		DataBase * GetDataBase(){ return dataBase;};
	    Account *  GetUser(){ return currentAccount; };
		
		ERole GetUserRole() { return currentAccount->m_role; };
		bool  HaveRole(ERole role) { return GetUserRole() & role ; }; 
		
		void GetDivisionStringByStaffId(int id, char * division);
		void GetPositionStringByStaffId(int id, char * position);
		
		void DisplayPositionList();
		void DisplayDivisionList();
		void DisplayAllInforStaff(int idStaff);
		
		
		static SalaryManager * GetInstance();
		
		
	protected:
		static SalaryManager * s_CurrentInstance;
		
		DataBase * dataBase;
		Account * currentAccount;


};
inline SalaryManager * GetSalaryMgr() { return SalaryManager::GetInstance();}
#endif // SALARYMANAGER_H



