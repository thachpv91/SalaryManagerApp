#ifndef BONUSDB_H
#define BONUSDB_H

#include "databaseinterface.h" // inheriting class's header file

/*
 * No description
 */
class Bonus;
class BonusDB : public DataBaseInterface  //<Bonus>
{
	// private section
	public:
		// class constructor
		BonusDB();
		// class destructor
		virtual ~BonusDB();
		virtual void Import(const char *fileTxt);
		virtual void Export(const char *fileTxt);
		
		virtual void Load();
		virtual void Save();
		virtual void UnLoad();
		
		virtual void SaveOnlyChange();
		vector<Bonus*> GetData();
		
		Bonus * FindByStaffId(int id);
	protected:
		vector<Bonus*> m_data;
};

#endif // BONUSDB_H

