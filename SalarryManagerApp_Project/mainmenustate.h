#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H



/*
 * No description
 */
 #include "AppState.h"
class SalaryManager;
class SearchMenuState;
class SalaryMgrState;
class SearchMenuState;
class MainMenuState : public AppState
{
	// private section
	public:
		// class constructor
		MainMenuState();
		// class destructor
		virtual ~MainMenuState();
		
		virtual void Init();
		virtual void Update();
		
		virtual void DisplayMenu();
		
	    
};

#endif // MAINMENUSTATE_H

