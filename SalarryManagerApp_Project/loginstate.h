#ifndef LOGINSTATE_H
#define LOGINSTATE_H

#include "appstate.h" // inheriting class's header file

/*
 * No description
 */
class LoginState : public AppState
{
	// private section
	public:
		// class constructor
		LoginState();
		// class destructor
		~LoginState();
		
		virtual void Init();
		virtual void Update();
		
		virtual void DisplayMenu();
	protected:
		char m_userName[255];
		char m_passWord[255];
};

#endif // LOGINSTATE_H

