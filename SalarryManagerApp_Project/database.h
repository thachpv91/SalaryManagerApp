#ifndef DATABASE_H
#define DATABASE_H
#include "MyDefine.h"
/*
 * No description
 */
enum ETypeDB
{
     DB_ACCOUNT = 0,
     DB_STAFF,
     DB_BONUS,
     DB_DISCIPLINE,
     DB_DIVISION,
     DB_POSITION,
     DB_TIMEKEEPING,
     DB_ADVANCE_PAYMENT,
     DB_SALARY
};
struct ConfigFile
{ 
  union
  {
     struct
   	{
    	char accountFile[255];
        char staffFile[255];
     	char bonusFile[255];
     	char disciplineFile[255];
     	char divisionFile[255];
     	char positionFile[255];
     	char timekeepingFile[255];
     	char advancePaymentFile[255];
     	char salaryFile[255];
  	};
    char fileNames[9][255];
  };
};
class DataBaseInterface;
class AccountDB;
class AdvancePaymentDB;
class BonusDB;
class DisciplineDB;
class DivisionDB;
class PositionDB;
class StaffInforDB;
class TimekeepingDB;
class SalaryDB;
class DataBase
{
	// private section
	public:
		// class constructor
		DataBase();
		// class destructor
		~DataBase();
		
		void Init();
		
		void Load();
		void Unload();
		
		bool IsAvailable() { return isAvailable; };
		
		void SaveAll();
		void Restore();
		
		DataBaseInterface * GetDataBase(ETypeDB type);
			
		AccountDB     * GetAccountDB();
		BonusDB       * GetBonusDB();
		DisciplineDB  * GetDisciplineDB();
		DivisionDB    * GetDivisionDB();
		PositionDB    * GetPositionDB();
		StaffInforDB  * GetStaffInforDB();
		TimekeepingDB * GetTimekeepingDB();
		AdvancePaymentDB * GetAdvancePaymentDB();
		SalaryDB      * GetSalaryDB();
		void SetChanged(ETypeDB type, bool changed ) { isChanged[type] == changed ; }

	protected:
		DataBaseInterface * dataBase[MAX_DATA_BASE];
		bool                isLoaded[MAX_DATA_BASE];
		bool                isChanged[MAX_DATA_BASE];
		ConfigFile          configFile;
		bool                isAvailable;
		
	    void LoadConfig();
	    bool CheckConfigFile();
	    
};

#endif // DATABASE_H

