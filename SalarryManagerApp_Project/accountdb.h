#ifndef ACCOUNTDB_H
#define ACCOUNTDB_H

#include "databaseinterface.h" // inheriting class's header file
#include <vector>
using namespace std;
/*
 * No description
 */
class Account;
class AccountDB : public DataBaseInterface
{
	// private section
	public:
		// class constructor
		AccountDB();
		// class destructor
		~AccountDB();
				
		virtual void Import(const char *fileTxt);
		virtual void Export(const char *fileTxt);
		
		virtual void Load();
		virtual void Save();
		virtual void UnLoad();
		
		virtual void SaveOnlyChange();
		
		vector<Account *> GetData() { return m_data;};
		Account * Find(const char *userName, const char *pass);
	protected:
		
		vector< Account* > m_data;

		
	//	char m_dbName[255];
};

#endif // ACCOUNTDB_H

