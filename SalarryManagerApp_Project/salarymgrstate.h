#ifndef SALARYMGRSTATE_H
#define SALARYMGRSTATE_H
#include "AppState.h"

/*
 * No description
 */
class SalaryMgrState : public AppState
{
	// private section
	public:
		// class constructor
		SalaryMgrState();
		// class destructor
		~SalaryMgrState();
		virtual void Init();
		virtual void Update();
		virtual void DisplayMenu();
	protected:
};

#endif // SALARYMGRSTATE_H

