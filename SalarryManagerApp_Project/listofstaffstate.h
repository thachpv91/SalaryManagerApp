#ifndef LISTOFSTAFFSTATE_H
#define LISTOFSTAFFSTATE_H

#include "appstate.h" // inheriting class's header file

/*
 * No description
 */
class StaffInfor;
class StaffInforDB;
class ListOfStaffState : public AppState
{
	// private section
	public:
		// class constructor
		ListOfStaffState();
		// class destructor
		~ListOfStaffState();
		virtual void Init();
		virtual void Update();
		virtual void DisplayMenu();
		        void DisplayMenu2();
	protected:
		void DisplayAllStaffInfor(int page);
		void NextPage();
		void PreviousPage();
		
		int m_page;
		int m_maxPage;
		
		StaffInforDB * m_staffInforDB;
		//vector<StaffInfor> m_staffList;
};

#endif // LISTOFSTAFFSTATE_H

