#include "positiondb.h" // class's header file
#include "Position.h"
#include "MyDefine.h"
#include "MyUtil.h"
// class constructor
PositionDB::PositionDB()
{
	// insert your code here
}

// class destructor
PositionDB::~PositionDB()
{
	// insert your code here
}
		
void PositionDB::Load()
{
	printf("\n PositionDB Loading!");
	FILE * pFile = NULL;
	pFile = fopen(m_dbName, "rb");
	if(pFile == NULL)
	{
	    printf("\n Can not to read file %s", m_dbName);
	    return;
	}
	Position position;
	while( fread( &position, sizeof(Position), 1, pFile))
	{
	   Position * acc = new Position(position);
	   m_data.push_back(acc);  
	}
	fclose(pFile);
	printf("\n PositionDB Load() done!");
}
void PositionDB::Save()
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
	   fwrite(m_data[i], sizeof(Position), 1, pFile);
   }
    fclose(pFile);
  //  MyUtil::MyCopyFile(tempFile, m_dbName);
	printf("\n Save done!");
}
void PositionDB:: UnLoad()
{
    while( !m_data.empty() )
    {
	    SAFE_DEL(m_data.back());
	    m_data.pop_back();
	};
	printf("\n UnLoad() done!");
}		
void PositionDB::SaveOnlyChange()
{
	// insert your code here
}
Position * PositionDB::FindByName(const char *name)
{
	for(unsigned int i = 0; i < m_data.size(); i++)
	{
	    if(MyUtil::MyStrStr(m_data[i]->m_Name, name)!= NULL)
	    {
		    return m_data[i];
		}
	}
	return 0;
}
Position * PositionDB::FindById(int id)
{

	for(unsigned int i = 0; i < m_data.size(); i++)
	{
	    if(m_data[i]->GetId() == id)
	    {
		    return m_data[i];
		}
	}
	return 0;
}
void PositionDB::Import(const char *fileTxt)
{
	FILE * pFile = NULL;
	pFile = fopen(fileTxt, "r");
	if(pFile == NULL)
	{
	    printf("\n Can not to read file %s", fileTxt);
	    return;
	}
	int number = 0;
	fscanf(pFile, " Numbers : %d \n", &number);
	if(number <= 0)
	{
	    printf("\n File ERROR!");
	    return;  
	}
	for(int i = 0; i < number; i++)
	{
		  int positionId = -1;
		  char positionName[255] = "";
		  int  coefficient_Pay;
		  
		  fscanf(pFile, " Id : %d \n ", &positionId);
	      fscanf(pFile, " Name : %[^\n] \n ", &positionName);
	      fscanf(pFile, " CoefficientPay : %d \n", &coefficient_Pay);

	      Position * position = new Position(positionId, positionName, coefficient_Pay);
	      m_data.push_back(position);
	}
	fclose(pFile);
	printf("\n Import done!");	
}
void PositionDB::Export(const char *fileTxt)
{
	FILE * pFile = NULL;
	pFile = fopen(fileTxt, "w");
	if(pFile == NULL)
	{
	    printf("\n Can not to read file %s", fileTxt);
	    return;
	}
	int number = (int) m_data.size();
	fprintf(pFile, " Numbers: %d \n\n", number);

	for(int i = 0; i < number; i++)
	{
		  char positionName[255] = "";
		  m_data[i]->GetName(positionName);
		  
		  fprintf(pFile, " Id : %d \n", m_data[i]->GetId());
	      fprintf(pFile, " Name : %s \n", positionName);
	      fprintf(pFile, " CoefficientPay : %d \n\n", m_data[i]->GetCoefficientPay());

	}
	fclose(pFile);
	printf("\n Import done!");	
}
vector<Position*> PositionDB::GetData()
{
    return m_data;
}

