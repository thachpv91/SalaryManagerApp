#ifndef POSITIONDB_H
#define POSITIONDB_H

#include "databaseinterface.h" // inheriting class's header file

/*
 * No description
 */
 #include "MyDefine.h"
class Position;
class PositionDB : public DataBaseInterface
{
	// private section
	public:
		// class constructor
		PositionDB();
		// class destructor
		virtual ~PositionDB();
		virtual void Import(const char *fileTxt);
		virtual void Export(const char *fileTxt);
		
		virtual void Load();
		virtual void Save();
		virtual void UnLoad();
		
		virtual void SaveOnlyChange();
		vector<Position*> GetData();
		
		Position * FindByName(const char * name);
		Position * FindById(int id);
	protected:
		vector<Position*> m_data;
};

#endif // POSITIONDB_H

