#ifndef SEARCHMENUSTATE_H
#define SEARCHMENUSTATE_H
#include "AppState.h"

/*
 * No description
 */
class SearchMenuState : public AppState
{
	// private section
	public:
		SearchMenuState();
		~ SearchMenuState();
	    virtual void Init();
		virtual void Update();
		virtual void DisplayMenu();
	protected:
};

#endif // SEARCHMENUSTATE_H

