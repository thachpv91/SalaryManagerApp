#ifndef SEARCH_EDIT_REMOVE_STATE_H
#define SEARCH_EDIT_REMOVE_STATE_H

#include "appstate.h" // inheriting class's header file
#include "MyDefine.h"

/*
 * No description
 */
class StaffInforDB;
class StaffInfor;
class Search_Edit_Remove_State : public AppState
{
	// private section
	public:
		// class constructor
		Search_Edit_Remove_State();
		// class destructor
		~Search_Edit_Remove_State();
		virtual void Init();
		virtual void Update();
		virtual void DisplayMenu();
		void DisplayStaffList(vector<StaffInfor*> staffInfor);
		void Search_ByName();
		void Search_ById();
		void Search_ByDivision();
		void Search_ByPosition();
		void Edit_Delete_Staff();
		
	protected:
		StaffInforDB * m_staffinforDB;
		
		void DeleteStaff(StaffInfor *staff);
		void EditStaff(StaffInfor *staff);
	
		
};

#endif // SEARCH_EDIT_REMOVE_STATE_H

