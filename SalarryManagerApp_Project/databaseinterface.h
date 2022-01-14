#ifndef DATABASEINTERFACE_H
#define DATABASEINTERFACE_H

/*
 * No description
 */
 #include "MyDefine.h"
class DataBaseInterface
{
	// private section
	public:
		// class constructor
		DataBaseInterface(){};
		// class destructor
		virtual ~DataBaseInterface(){};
	    virtual void Init(const char * dbName){ strcpy(m_dbName ,dbName); };
		
		virtual void Import(const char *fileTxt) = 0;
		virtual void Export(const char *fileTxt) = 0;
		
		virtual void Load() = 0;
		virtual void Save() = 0;
		virtual void UnLoad() = 0;
		
		virtual void SaveOnlyChange() = 0;
	
	protected:
		char m_dbName[255];
};

#endif // DATABASEINTERFACE_H

