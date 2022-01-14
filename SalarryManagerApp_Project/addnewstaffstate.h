#ifndef ADDNEWSTAFFSTATE_H
#define ADDNEWSTAFFSTATE_H

#include "appstate.h" // inheriting class's header file

/*
 * No description
 */

class AddNewStaffState : public AppState
{
	// private section
	public:
		// class constructor
		AddNewStaffState();
		// class destructor
		virtual ~AddNewStaffState();
		virtual void Init();
		virtual void Update();
		
		virtual void DisplayMenu();
	protected:
		void EnterNewStaff();
		void ImportStaffFromFile();
		void ExportStaffToFile();
};

#endif // ADDNEWSTAFFSTATE_H

