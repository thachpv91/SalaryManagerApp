#include "divisiondb.h" // class's header file
#include "Division.h"
#include "MyDefine.h"
#include "MyUtil.h"
// class constructor
DivisionDB::DivisionDB()
{
	// insert your code here
}

// class destructor
DivisionDB::~DivisionDB()
{
	// insert your code here
}
		
void DivisionDB::Load()
{
	printf("\n PositionDB Loading!");
	FILE * pFile = NULL;
	pFile = fopen(m_dbName, "rb");
	if(pFile == NULL)
	{
	    printf("\n Can not to read file %s", m_dbName);
	    return;
	}
	Division division;
	while( fread( &division, sizeof(Division), 1, pFile))
	{
	   Division * temp = new Division(division);
	   m_data.push_back(temp);  
	}
	fclose(pFile);
	printf("\n PositionDB Load() done!");
	
}
void DivisionDB::Save()
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
	   fwrite(m_data[i], sizeof(Division), 1, pFile);
   }
    fclose(pFile);
  //  MyUtil::MyCopyFile(tempFile, m_dbName);
	printf("\n Save done!");
}
void DivisionDB:: UnLoad()
{
    while( !m_data.empty() )
    {
	    SAFE_DEL(m_data.back());
	    m_data.pop_back();
	};
	printf("\n UnLoad() done!");
}		
void DivisionDB::SaveOnlyChange()
{
	// insert your code here
}
Division * DivisionDB::FindByName(const char *divisionName)
{
	for(unsigned int i = 0; i < m_data.size(); i++)
	{
	    if(MyUtil::MyStrStr(m_data[i]->m_Name, divisionName) != NULL)
	    {
		    return m_data[i];
		}
	}
	return 0;
}
Division * DivisionDB::FindById(int id)
{
	for(unsigned int i = 0; i < m_data.size(); i++)
	{
	    if(m_data[i]->m_Id == id)
	    {
		    return m_data[i];
		}
	}
	return 0;
}
void DivisionDB::Import(const char *fileTxt)
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
		  int  divisionId = -1;
		  char divisionName[255] = "";
		  
		  fscanf(pFile, " Id : %d \n ", &divisionId);
	      fscanf(pFile, " Name : %[^\n] \n ", &divisionName);

	      Division * division = new Division(divisionId, divisionName);
	      m_data.push_back(division);
	}
	fclose(pFile);
	printf("\n Import done!");	
}
void DivisionDB::Export(const char *fileTxt)
{
	FILE * pFile = NULL;
	pFile = fopen(fileTxt, "w");
	if(pFile == NULL)
	{
	    printf("\n Can not to read file %s", fileTxt);
	    return;
	}
	int number = (int) m_data.size();
	fprintf(pFile, " Numbers: %d\n\n", number);

	for(int i = 0; i < number; i++)
	{
		  char divisionName[255] = "";
		  m_data[i]->GetName(divisionName);
		  
		  fprintf(pFile, " Id : %d \n", m_data[i]->GetId());
	      fprintf(pFile, " Name : %s \n\n", divisionName);

	}
	fclose(pFile);
	printf("\n Import done!");	
}
vector<Division*> DivisionDB::GetData()
{
    return m_data;
}

