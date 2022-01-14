#ifndef APPLICATIONMANAGER_H
#define APPLICATIONMANAGER_H

/*
 * No description
 */
class Application;
class ApplicationManager
{
	// private section
	public:
		void StartApp(Application * newApp);
		// class destructor
		~ApplicationManager();
	protected:
		// class constructor
		ApplicationManager();
		Application * m_currentApp;
	// Static
	    static ApplicationManager * m_instance;
	 public:
	 	static ApplicationManager * GetInstance();
	 	static void FreeInstance();
};

#endif // APPLICATIONMANAGER_H

