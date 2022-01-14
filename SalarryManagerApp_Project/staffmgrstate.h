#ifndef STAFFMGRSTATE_H
#define STAFFMGRSTATE_H
#include "AppState.h"


/*
 * No description
 */
class StaffMgrState : public AppState
{
	// private section
	public:
		// class constructor
		StaffMgrState();
		// class destructor
		virtual ~StaffMgrState();
		
		virtual void Init();
		virtual void Update();
		
		virtual void DisplayMenu();
	protected:
};

#endif // STAFFMGRSTATE_H

