#ifndef DISPAYSALARYSTATE_H
#define DISPAYSALARYSTATE_H

#include "appstate.h" // inheriting class's header file
#include "MyDefine.h"
/*
 * No description
 */
class SalaryDB;
class Salary;
class DispaySalaryState : public AppState
{
	// private section
	public:
		// class constructor
		DispaySalaryState();
		// class destructor
		~DispaySalaryState();
		virtual void Init();
		virtual void Update();
		virtual void DisplayMenu();
		        void DisplayMenu2();
	protected:
		void DisplaySalary(int page);
		void NextPage();
		void PreviousPage();
		
		int m_page;
		int m_maxPage;
		
		SalaryDB * m_salaryDB;
		vector<Salary *> m_salaryList;
};

#endif // DISPAYSALARYSTATE_H

