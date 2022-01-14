#ifndef TIMEKEEPINGDB_H
#define TIMEKEEPINGDB_H

#include "databaseinterface.h" // inheriting class's header file

/*
 * No description
 */
class Timekeeping;
class TimekeepingDB : public DataBaseInterface
{
	// private section
	public:
		// class constructor
		TimekeepingDB();
		// class destructor
		~TimekeepingDB();
		virtual void Import(const char *fileTxt);
		virtual void Export(const char *fileTxt);
		
		virtual void Load();
		virtual void Save();
		virtual void UnLoad();
		
		Timekeeping * FindByStaffId(int id);
		
		virtual void SaveOnlyChange();
		vector<Timekeeping*> GetData();
	protected:
		vector<Timekeeping*> m_data;
};

#endif // TIMEKEEPINGDB_H

