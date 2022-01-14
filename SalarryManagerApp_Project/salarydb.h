#ifndef SALARYDB_H
#define SALARYDB_H

#include "databaseinterface.h" // inheriting class's header file

/*
 * No description
 */
class Salary;
class SalaryDB : public DataBaseInterface
{
	// private section
	public:
		// class constructor
		SalaryDB();
		SalaryDB(SalaryDB &salary);
		// class destructor
		virtual ~SalaryDB();
		virtual void Import(const char *fileTxt);
		virtual void Export(const char *fileTxt);
		
		virtual void Load();
		virtual void Save();
		virtual void UnLoad();
		
		virtual void SaveOnlyChange();
		vector<Salary*> GetData();
		
		void AddSalary(Salary * salary);
		void Reset();
	protected:
		vector<Salary*> m_data;
};

#endif // SALARYDB_H

