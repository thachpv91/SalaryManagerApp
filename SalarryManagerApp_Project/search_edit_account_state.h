#ifndef SEARCH_EDIT_ACCOUNT_STATE_H
#define SEARCH_EDIT_ACCOUNT_STATE_H

#include "appstate.h" // inheriting class's header file

/*
 * No description
 */
class Search_Edit_Account_State : public AppState
{
	// private section
	public:
		// class constructor
		Search_Edit_Account_State();
		// class destructor
		virtual ~Search_Edit_Account_State();
		virtual void Init();
		virtual void Update();
		virtual void DisplayMenu();

	protected:
};

#endif // SEARCH_EDIT_ACCOUNT_STATE_H

