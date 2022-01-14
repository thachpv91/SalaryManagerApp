#include "disciplinedb.h" // class's header file
#include "Discipline.h"
#include "MyDefine.h"
// class constructor
DisciplineDB::DisciplineDB()
{
	// insert your code here
}

// class destructor
DisciplineDB::~DisciplineDB()
{
	// insert your code here
}
void DisciplineDB::Load()
{
	printf("\n DisciplineDB Loading!");
	FILE * pFile = NULL;
	pFile = fopen(m_dbName, "rb");
	if(pFile == NULL)
	{
	    printf("\n Can not to read file %s", m_dbName);
	    return;
	}
	Discipline discipline;
	while( fread( &discipline, sizeof(Discipline), 1, pFile))
	{
	   Discipline * temp = new Discipline(discipline);
	   m_data.push_back(temp);  
	}
	
	fclose(pFile);
	
}
void DisciplineDB::Save()
{
	FILE * pFile = NULL;
//	const char * tempFile = "BonusDB.temp";
	pFile = fopen(m_dbName, "wb");
	if(pFile == NULL)
	{
	    printf("\n Can not to save file %s", m_dbName);
	    return;
	}
	for(unsigned int i = 0 ; i < m_data.size(); i++)
	{
	   fwrite(m_data[i], sizeof(Discipline), 1, pFile);
   }
    fclose(pFile);
  //  MyUtil::MyCopyFile(tempFile, m_dbName);
	printf("\n Save done!");
}
void DisciplineDB:: UnLoad()
{
    while( !m_data.empty() )
    {
	    SAFE_DEL(m_data.back());
	    m_data.pop_back();
	};
	printf("\n UnLoad() done!");
}		
void DisciplineDB::SaveOnlyChange()
{
	// insert your code here
}
/*
Numbers: 2

StaffID: 2
Date: 20/02/2015
Reason: Lam mat phone N9505
Money: 4000000
*/
void DisciplineDB::Import(const char *fileTxt)
{
	FILE * pFile = NULL;
	pFile = fopen(fileTxt, "r");
	if(pFile == NULL)
	{
	    printf("\n Can not to read file %s", fileTxt);
	    return;
	}
	int number = 0;
	fscanf(pFile, " Numbers: %d \n", &number);
	if(number <= 0)
	{
	    printf("\n File ERROR!");
	    return;  
	}
	for(int i = 0; i < number; i++)
	{
		  int staffId = -1;
		  char date[255] = "";
		  char reason[255] = "";
		  unsigned long money;
		  fscanf(pFile, " StaffID : %d \n ", &staffId);
	      fscanf(pFile, " Date : %s \n ", &date);
	      fscanf(pFile, " Reason : %[^\n] \n ", &reason);
	      fscanf(pFile, " Money : %lu \n", &money);
          printf("\n %d %s %s %lu", staffId, date, reason, money);
	      Discipline * discipline = new Discipline(staffId, date, reason, money);
	      m_data.push_back(discipline);
	}
	fclose(pFile);
	printf("\n Import done!");	
}
void DisciplineDB::Export(const char *fileTxt)
{
	FILE * pFile = NULL;
	pFile = fopen(fileTxt, "w");
	if(pFile == NULL)
	{
	    printf("\n Can not to read file %s", fileTxt);
	    return;
	}
	int number = (int) m_data.size();
	fprintf(pFile, " Numbers: %d \n", number);

	for(int i = 0; i < number; i++)
	{
		  char * date;
		  char reason[255] = "";
		  m_data[i]->GetReason(reason);
		  date = m_data[i]->GetDate().ToString();
		  fprintf(pFile, "\n StaffId : %d \n", m_data[i]->GetStaffId());
	      fprintf(pFile, " Date : %s \n", date);
	      fprintf(pFile, " Reason : %s \n", reason);
	      fprintf(pFile, " Money : %lu \n", m_data[i]->GetMoney());
	      SAFE_DEL(date);
	}
	fclose(pFile);
	printf("\n Import done!");	
}
vector<Discipline*> DisciplineDB::GetData()
{
    return m_data;
}
Discipline * DisciplineDB::FindByStaffId(int id)
{
 	for(unsigned int i = 0; i < m_data.size(); i++)
 	{
	 	if(m_data[i]->GetStaffId() == id)
		{
		     return m_data[i];
		} 
	}
	return 0; // NULL
}
