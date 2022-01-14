#ifndef DIVISIONDB_H
#define DIVISIONDB_H

#include "databaseinterface.h" // inheriting class's header file
#include "MyDefine.h"
/*
 * No description
 */
class Division;
class DivisionDB : public DataBaseInterface
{
	// private section
	public:
		// class constructor
		DivisionDB();
		// class destructor
		~DivisionDB();
		virtual void Import(const char *fileTxt);
		virtual void Export(const char *fileTxt);
		
		virtual void Load();
		virtual void Save();
		virtual void UnLoad();
		
		virtual void SaveOnlyChange();
		vector<Division*> GetData();
		
		Division * FindByName(const char *divisionName);
		Division * FindById(int id);
		
	protected:
		vector<Division*> m_data;
};

#endif // DIVISIONDB_H

