#include "database.h" // class's header file
#include "MyDefine.h"

#include "AccountDB.h"
#include "AdvancePaymentDB.h"
#include "DisciplineDB.h"
#include "StaffInforDB.h"
#include "BonusDB.h"
#include "DivisionDB.h"
#include "PositionDB.h"
#include "TimekeepingDB.h"
#include "SalaryDB.h"
// class constructor
DataBase::DataBase()
{
	isAvailable = false;
	memset(dataBase, 0 , sizeof(dataBase));
	memset(isLoaded, 0 , sizeof(isLoaded));
	// insert your code here
}

// class destructor
DataBase::~DataBase()
{
	// insert your code here
}
void DataBase::Init()
{
	dataBase[DB_ACCOUNT]    = new AccountDB();
	dataBase[DB_STAFF]      = new StaffInforDB();
	dataBase[DB_BONUS]      = new BonusDB();
	dataBase[DB_DIVISION]   = new DivisionDB();
	dataBase[DB_DISCIPLINE] = new DisciplineDB();
	dataBase[DB_POSITION]   = new PositionDB(); 
	dataBase[DB_TIMEKEEPING]     =  new TimekeepingDB();
	dataBase[DB_ADVANCE_PAYMENT] =  new AdvancePaymentDB();
	dataBase[DB_SALARY] 		 =  new SalaryDB();    
	LoadConfig();
		
	for(int i = 0; i < NUMBER_DATA_BASE; i++)
	{
	    dataBase[i]->Init(configFile.fileNames[i]);
	     isLoaded[i] = false;
	}

	if(isAvailable)
	{
	    dataBase[DB_ACCOUNT]->Load();
	    isLoaded[DB_ACCOUNT] = true;
	}
}		
void DataBase::Load()
{
	for(int i = 0; i < NUMBER_DATA_BASE; i++)
	{
	     if(!isLoaded[i])
	     {
		    dataBase[i]->Load();
		    isLoaded[i] = true;
		 }
	}
}
void DataBase::Unload()
{
	for(int i = 0; i < NUMBER_DATA_BASE; i++)
	{
	     if(isLoaded[i])
	     {
		    dataBase[i]->UnLoad();
		    isLoaded[i] = false;
		 }
	}
}
		
void DataBase::SaveAll()
{
	for(int i = 0; i < NUMBER_DATA_BASE; i++)
	{
	//	if(isLoaded[i] && isChanged[i])
//		{
	       dataBase[i]->Save();
//	    }
	}
}
void DataBase::Restore()
{
	// insert your code here
}
DataBaseInterface * DataBase::GetDataBase(ETypeDB type)
{
    return dataBase[type];
}		
AccountDB * DataBase::GetAccountDB()
{
	return (AccountDB *)dataBase[DB_ACCOUNT];
}
BonusDB * DataBase::GetBonusDB()
{
	return (BonusDB *)dataBase[DB_BONUS];
}
DisciplineDB * DataBase::GetDisciplineDB()
{
	return (DisciplineDB *)dataBase[DB_DISCIPLINE];	// insert your code here
}
DivisionDB * DataBase::GetDivisionDB()
{
	return (DivisionDB *)dataBase[DB_DIVISION];	// insert your code here
}
PositionDB * DataBase::GetPositionDB()
{
	return (PositionDB *)dataBase[DB_POSITION];	// insert your code here
}
StaffInforDB * DataBase::DataBase::GetStaffInforDB()
{
	return (StaffInforDB *)dataBase[DB_STAFF];	// insert your code here
}
TimekeepingDB * DataBase::GetTimekeepingDB()
{
	return (TimekeepingDB *)dataBase[DB_TIMEKEEPING];	// insert your code here
}
AdvancePaymentDB * DataBase::GetAdvancePaymentDB()
{
	return (AdvancePaymentDB *)dataBase[DB_ADVANCE_PAYMENT];	// insert your code here
}
SalaryDB * DataBase::GetSalaryDB()
{
	return (SalaryDB *)dataBase[DB_SALARY];
}
void DataBase::LoadConfig()
{
	FILE * pFile = NULL;
	pFile = fopen(CONFIG_FILE, "r");
	if(pFile == NULL)
	{
		printf("\n ERROE: DataBase::LoadConfig : Can not read config.txt file!");
	    isAvailable = false;
	    getch();
	    return;
	}

	fscanf(pFile, " ACCOUNT : %s \n ", &configFile.accountFile);
	fscanf(pFile, " STAFF_INFOR : %s \n ", &configFile.staffFile);
	fscanf(pFile, " DIVISION : %s \n ", &configFile.divisionFile);
	fscanf(pFile, " DISCIPLINE : %s \n ", &configFile.disciplineFile);
	fscanf(pFile, " BONUS : %s \n ", &configFile.bonusFile);
	fscanf(pFile, " ADVANCE_PAYMENT : %s \n ", &configFile.advancePaymentFile);
	fscanf(pFile, " TIMEKEEPING : %s \n ", &configFile.timekeepingFile);
	fscanf(pFile, " POSITION : %s \n ", &configFile.positionFile);
	fscanf(pFile, " SALARY : %s \n ", &configFile.salaryFile);
	fclose(pFile);
	isAvailable = CheckConfigFile();
}
bool DataBase::CheckConfigFile()
{
    if(strlen(configFile.accountFile)  == 0)
    {
    	printf("\n Can not find Account database !");
	    return false;
	}
	if(strlen(configFile.bonusFile)  == 0)
    {
    	printf("\n Can not find Bonus database !");
	    return false;
	}
	if(strlen(configFile.disciplineFile)  == 0)
    {
    	printf("\n Can not find Discipline database !");
	    return false;
	}
	if(strlen(configFile.divisionFile)  == 0)
    {
    	printf("\n Can not find Division database !");
	    return false;
	}
	if(strlen(configFile.positionFile)  == 0)
    {
    	printf("\n Can not find Position database !");
	    return false;
	}
	if(strlen(configFile.staffFile)  == 0)
    {
    	printf("\n Can not find StaffInfor database !");
	    return false;
	}
	if(strlen(configFile.timekeepingFile)  == 0)
    {
    	printf("\n Can not find Timekeeping database !");
	    return false;
	}
	if(strlen(configFile.advancePaymentFile)  == 0)
    {
    	printf("\n Can not find AdvancePayment database !");
	    return false;
	}
	if(strlen(configFile.salaryFile)  == 0)
    {
    	printf("\n Can not find Salary database !");
	    return false;
	}
	return true;
}
