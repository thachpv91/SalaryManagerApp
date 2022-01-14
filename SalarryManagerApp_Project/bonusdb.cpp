#include "bonusdb.h" // class's header file
#include "Bonus.h"
#include "MyDefine.h"
#include "MyUtil.h"
// class constructor
BonusDB::BonusDB()
{
	// insert your code here
}

// class destructor
BonusDB::~BonusDB()
{
	// insert your code here
}
		
void BonusDB::Load()
{
	printf("\n BonusDB Loading!");
	FILE * pFile = NULL;
	pFile = fopen(m_dbName, "rb");
	if(pFile == NULL)
	{
	    printf("\n Can not to read file %s", m_dbName);
	    return;
	}
	Bonus bonus;
	while( fread( &bonus, sizeof(bonus), 1, pFile))
	{
	   Bonus * acc = new Bonus(bonus);
	   m_data.push_back(acc);  
	}
	
	fclose(pFile);
	
}
void BonusDB::Save()
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
	   fwrite(m_data[i], sizeof(Bonus), 1, pFile);
   }
    fclose(pFile);
  //  MyUtil::MyCopyFile(tempFile, m_dbName);
	printf("\n Save done!");
}
void BonusDB:: UnLoad()
{
    while( !m_data.empty() )
    {
	    SAFE_DEL(m_data.back());
	    m_data.pop_back();
	};
	printf("\n UnLoad() done!");
}		
void BonusDB::SaveOnlyChange()
{
	// insert your code here
}
void BonusDB::Import(const char *fileTxt)
{
	FILE * pFile = NULL;
	pFile = fopen(fileTxt, "r");
	if(pFile == NULL)
	{
	    printf("\n Can not to read file %s", fileTxt);
	    return;
	}
	int number = 0;
	fscanf(pFile, " Number: %d \n", &number);
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
		  fscanf(pFile, " StaffId : %d \n ", &staffId);
	      fscanf(pFile, " Date : %s \n ", &date);
	      fscanf(pFile, " Reason : \" %[^\"]%*c \n ", &reason);
	      fscanf(pFile, " Money : %lu \n", &money);

	      Bonus * bonus = new Bonus(staffId, date, reason, money);
	      m_data.push_back(bonus);
	}
	fclose(pFile);
	printf("\n Import done!");	
}
void BonusDB::Export(const char *fileTxt)
{
	FILE * pFile = NULL;
	pFile = fopen(fileTxt, "w");
	if(pFile == NULL)
	{
	    printf("\n Can not to read file %s", fileTxt);
	    return;
	}
	int number = (int) m_data.size();
	fprintf(pFile, " Number: %d \n", number);

	for(int i = 0; i < number; i++)
	{
		  char * date;
		  char reason[255] = "";
		  m_data[i]->GetReason(reason);
		  date = m_data[i]->GetDate().ToString();
		  fprintf(pFile, "\n StaffId : %d \n", m_data[i]->GetStaffId());
	      fprintf(pFile, " Date : %s \n", date);
	      fprintf(pFile, " Reason : \"%s\" \n", reason);
	      fprintf(pFile, " Money : %lu \n", m_data[i]->GetMoney());
	      SAFE_DEL(date);
	}
	fclose(pFile);
	printf("\n Import done!");	
}
vector<Bonus*> BonusDB::GetData()
{
    return m_data;
}
Bonus * BonusDB::FindByStaffId(int id)
{
	for(unsigned i = 0; i < m_data.size(); i++)
	{
		if(m_data[i]->GetStaffId() == id)
		{
		     return m_data[i];
		}
	}
	return 0;
}
