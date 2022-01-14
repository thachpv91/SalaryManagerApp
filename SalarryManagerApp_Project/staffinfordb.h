#ifndef STAFFINFORDB_H
#define STAFFINFORDB_H

#include "databaseinterface.h" // inheriting class's header file

/*
 * No description
 */
class StaffInfor;
class StaffInforDB : public DataBaseInterface
{
	// private section
	public:
		// class constructor
		StaffInforDB();
		// class destructor
		~StaffInforDB();
		virtual void Import(const char *fileTxt);
		virtual void Export(const char *fileTxt);
		
		virtual void Load();
		virtual void Save();
		virtual void UnLoad();
		
		virtual void SaveOnlyChange();
		vector<StaffInfor*> GetData();
		vector<StaffInfor*> FindByName(const char *name);
		vector<StaffInfor*>	FindByDivisionId(int id);
		vector<StaffInfor*>	FindByPositionId(int id);
		
		void DeleteStaff(int id);
		void AddStaff(StaffInfor * newStaff);
		
		StaffInfor *	    FindById(int id); 
	protected:
		vector<StaffInfor*> m_data;
};

#endif // STAFFINFORDB_H

