#ifndef APPLICATION_H
#define APPLICATION_H

/*
 * No description
 */
class  AppState;
class Application
{
	// private section
	public:
		Application();
		virtual ~Application();
		
		virtual void Init();
		virtual void Update();
		virtual void Destroy();
		
		virtual void OnExit();
		virtual bool IsRunning();
		
		virtual void SetAppState(AppState * appState);
		virtual AppState * GetAppState();

	protected:
		bool m_isExit;
		AppState * m_currentState;
		AppState * m_tempState;
		bool   m_isChangedState;
			
};

#endif // APPLICATION_H

