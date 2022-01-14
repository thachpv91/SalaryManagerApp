#include "salarydb.h" // class's header file
#include "Salary.h"
#include "MyDefine.h"
// class constructor
SalaryDB::SalaryDB()
{

}
SalaryDB::SalaryDB(SalaryDB &salary)
{
	// insert your code here
}

// class destructor
SalaryDB::~SalaryDB()
{
	// insert your code here
}
		
void SalaryDB::Load()
{
	printf("\n SalaryDB Loading!");
	FILE * pFile = NULL;
	pFile = fopen(m_dbName, "rb");
	if(pFile == NULL)
	{
	    printf("\n Can not to read file %s", m_dbName);
	    return;
	}
	Salary salary;
	while( fread( &salary, sizeof(Salary), 1, pFile))
	{
	   Salary * temp = new Salary(salary);
	   m_data.push_back(temp);  
	}
	fclose(pFile);
	printf("\n SalaryDB Load() done!");
	
}
void SalaryDB::Save()
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
	   fwrite(m_data[i], sizeof(Salary), 1, pFile);
   }
    fclose(pFile);
  //  MyUtil::MyCopyFile(tempFile, m_dbName);
	printf("\n Save done!");
}
void SalaryDB:: UnLoad()
{
    while( !m_data.empty() )
    {
	    SAFE_DEL(m_data.back());
	    m_data.pop_back();
	};
	printf("\n UnLoad() done!");
}		
void SalaryDB::SaveOnlyChange()
{
	// insert your code here
}

void SalaryDB::Import(const char *fileTxt)
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
		/*  int  divisionId = -1;
		  char divisionName[255] = "";
		  
		  fscanf(pFile, " Id : %d \n ", &divisionId);
	      fscanf(pFile, " Name : %[^\n] \n ", &divisionName);

	      Division * division = new Division(divisionId, divisionName);
	      m_data.push_back(division);
	      */
	}
	fclose(pFile);
	printf("\n Import done!");	
}
void SalaryDB::Export(const char *fileTxt)
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
/*
	for(int i = 0; i < number; i++)
	{
		  char divisionName[255] = "";
		  m_data[i]->GetName(divisionName);
		  
		  fprintf(pFile, " Id : %d \n", m_data[i]->GetId());
	      fprintf(pFile, " Name : %s \n\n", divisionName);

	}
*/
	fclose(pFile);
	printf("\n Export done!");	
}
void SalaryDB::Reset()
{
     UnLoad();
}
void SalaryDB::AddSalary(Salary * salary)
{
    if(salary)
    {
	    m_data.push_back(salary);
	}
}
vector<Salary*> SalaryDB::GetData()
{
    return m_data;
}
