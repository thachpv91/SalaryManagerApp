#include "accountdb.h" // class's header file
#include "Account.h"
#include "MyUtil.h"
#include "MyDefine.h"
// class constructor
AccountDB::AccountDB()
{
	// insert your code here
}

// class destructor
AccountDB::~AccountDB()
{
	// insert your code here
}
		
void AccountDB::Load()
{
	printf("\n Load doing!");
	FILE * pFile = NULL;
	pFile = fopen(m_dbName, "rb");
	if(pFile == NULL)
	{
	    printf("\n Can not to read file %s", m_dbName);
	    getch();
	    return;
	}
	Account accTemp;
	while( fread( &accTemp, sizeof(Account), 1, pFile))
	{
	   Account * acc = new Account(accTemp);
	   m_data.push_back(acc); 
	}
	fclose(pFile);
	
}
void AccountDB::Save()
{
	FILE * pFile = NULL;
//	const char * tempFile = "AccountDB.temp";
	pFile = fopen(m_dbName, "wb");
	if(pFile == NULL)
	{
	    printf("\n Can not to save file %s", m_dbName);
	    return;
	}
	for(unsigned int i = 0 ; i < m_data.size(); i++)
	{
	   fwrite(m_data[i], sizeof(Account), 1, pFile);
   }
    fclose(pFile);
  //  MyUtil::MyCopyFile(tempFile, m_dbName);
	printf("\n Save done!");
}
void AccountDB:: UnLoad()
{
	printf("\n Export done!");	
    while( !m_data.empty() )
    {
	    SAFE_DEL(m_data.back());
	    m_data.pop_back();
	};
	printf("\n UnLoad() done!");
}		
void AccountDB::SaveOnlyChange()
{
	// insert your code here
}
Account * AccountDB::Find(const char *userName, const char *pass)
{
     for(unsigned int i = 0; i < m_data.size(); i++)
     {
	      if( strcmp(m_data[i]->m_userName, userName) == 0 &&
		      strcmp(m_data[i]->m_passWord, pass) == 0 )
			{
			   return m_data[i];
			}
	 }
	 return 0;
}
void AccountDB::Import(const char *fileTxt)
{
	FILE * pFile = NULL;
	pFile = fopen(fileTxt, "r");
	if(pFile == NULL)
	{
	    printf("\n Can not to read file %s", fileTxt);
	    return;
	}
	int numberAcc = 0;
	fscanf(pFile, " Number Account: %d \n", &numberAcc);
	if(numberAcc <= 0)
	{
	    printf("\n File ERROR!");
	    return;  
	}
	for(int i = 0; i < numberAcc; i++)
	{
		  int id = -1;
		  char userName[255] = "";
		  char pass[255] = "";
		  char roleStr[100] = "";
		  fscanf(pFile, " Id : %d \n ", &id);
	      fscanf(pFile, " UserName : %s \n ", &userName);
	      fscanf(pFile, " Pass : %s \n ", &pass);
	      fscanf(pFile, " Role : %s \n ", &roleStr);

	      ERole role = Account::GetUserRole(roleStr);
	      Account * acc = new Account(id, userName, pass, role);
	      m_data.push_back(acc);
	}
	fclose(pFile);
	printf("\n Import done!");	
}
void AccountDB::Export(const char *fileTxt)
{
	FILE * pFile = NULL;
	pFile = fopen(fileTxt, "w");
	if(pFile == NULL)
	{
	    printf("\n Can not to write file %s", fileTxt);
	    return;
	}
	fprintf(pFile, " Number Account: %d \n ", (int)m_data.size());
	for(int i = 0; i < (int)m_data.size(); i++)
	{
		  Account * acc = m_data[i];
		  char roleStr[100] = "";
		  Account::GetPositionByRole(acc->m_role, roleStr);
		  fprintf(pFile, " Id : %d \n ", acc->m_id);
	      fprintf(pFile, " UserName : %s \n ",  acc->m_userName);
	      fprintf(pFile, " Pass : %s \n ", acc->m_passWord);
	      fprintf(pFile, " Role : %s \n\n ", &roleStr);
	}
	fclose(pFile);
	printf("\n Export done!");		
}

