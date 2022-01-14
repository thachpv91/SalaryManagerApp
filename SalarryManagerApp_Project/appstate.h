#ifndef APPSTATE_H
#define APPSTATE_H

/*
 * No description
 */
class AppState
{
	// private section
	public:
		// class constructor
		AppState(){}
		// class destructor
		virtual ~AppState(){}
		
		virtual void Init(){}
		virtual void Update() = 0;
		virtual void DisplayMenu() = 0;
	protected:
};

#endif // APPSTATE_H

