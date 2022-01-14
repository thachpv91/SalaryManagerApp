#ifndef DISCIPLINEDB_H
#define DISCIPLINEDB_H

#include "databaseinterface.h" // inheriting class's header file

/*
 * No description
 */
class Discipline;
class DisciplineDB : public DataBaseInterface
{
	// private section
	public:
		// class constructor
		DisciplineDB();
		// class destructor
		~DisciplineDB();
		virtual void Import(const char *fileTxt);
		virtual void Export(const char *fileTxt);
		
		virtual void Load();
		virtual void Save();
		virtual void UnLoad();
		
		virtual void SaveOnlyChange();
		vector<Discipline*> GetData();
		
		Discipline * FindByStaffId(int id);
	protected:
		vector<Discipline*> m_data;
};

#endif // DISCIPLINEDB_H

