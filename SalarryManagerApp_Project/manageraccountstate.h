#ifndef MANAGERACCOUNTSTATE_H
#define MANAGERACCOUNTSTATE_H

#include "appstate.h" // inheriting class's header file

/*
 * No description
 */
class Account;
class AccountDB;
class DataBase;
class ManagerAccountState : public AppState
{
	// private section
	public:
		// class constructor
		ManagerAccountState();
		// class destructor
		~ManagerAccountState();
		virtual void Init();
		virtual void Update();
		
		virtual void DisplayMenu();
		
		void ImportFromFile();
		void ExportToFile();
		
		void DisplayListAccount();
	protected:
	 DataBase  * m_appDB;// = GetSalaryMgr()->GetDataBase();
     AccountDB * m_accDB;// = appDB->GetAccountDB();
};

#endif // MANAGERACCOUNTSTATE_H

