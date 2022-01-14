#include "staffinfordb.h" // class's header file
#include "StaffInfor.h"
#include "MyUtil.h"
// class constructor
StaffInforDB::StaffInforDB()
{
	// insert your code here
}

// class destructor
StaffInforDB::~StaffInforDB()
{
	// insert your code here
}
void StaffInforDB::Load()
{
	printf("\n StaffInforDB:: Loading!");
	FILE * pFile = NULL;
	pFile = fopen(m_dbName, "rb");
	if(pFile == NULL)
	{
	    printf("\n Can not to read file %s", m_dbName);
	    return;
	}
	StaffInfor staffTemp;
	int i = 0;
	while(fread( &staffTemp, sizeof(StaffInfor), 1, pFile))
	{
	   StaffInfor * staff = new StaffInfor(staffTemp);
	   m_data.push_back(staff);  
	}
	fclose(pFile);
	
}
void StaffInforDB::Save()
{
	FILE * pFile = NULL;
//	const char * tempFile = "StaffInforDB.temp";
	pFile = fopen(m_dbName, "wb");
	if(pFile == NULL)
	{
	    printf("\n Can not to save file %s", m_dbName);
	    return;
	}
	for(unsigned int i = 0 ; i < m_data.size(); i++)
	{
	   fwrite(m_data[i], sizeof(StaffInfor), 1, pFile);
   }
    fclose(pFile);
   // MyUtil::MyCopyFile(tempFile, m_dbName);
	printf("\n Save done!");
}
void StaffInforDB::UnLoad()
{
    while( !m_data.empty() )
    {
	    SAFE_DEL(m_data.back());
	    m_data.pop_back();
	};
	printf("\n UnLoad() done!");
}		
void StaffInforDB::SaveOnlyChange()
{
	// insert your code here
}
vector<StaffInfor*> StaffInforDB::FindByName(const char *name)
{
	vector<StaffInfor*> result;
	for(unsigned int i = 0; i < m_data.size(); i++)
	{
		char fullName[255] = "";
	    if( MyUtil::MyStrStr(m_data[i]->m_FullName, name) != NULL)
	    {
		    result.push_back(m_data[i]);
		}
	}
	return result;
}
StaffInfor *	StaffInforDB::FindById(int id)
{
	StaffInfor * result = 0;
	for(unsigned int i = 0; i < m_data.size(); i++)
	{
	    if( m_data[i]->m_Id == id)
	    {
		    result = m_data[i];
		    break;
		}
	}
	return result;
}
vector<StaffInfor*>	StaffInforDB::FindByDivisionId(int id)
{
	vector<StaffInfor*> result;
	for(unsigned int i = 0; i < m_data.size(); i++)
	{
	    if( m_data[i]->m_DivisionId == id)
	    {
		    result.push_back(m_data[i]);
		}
	}
	return result;
}
vector<StaffInfor*>	StaffInforDB::FindByPositionId(int id)
{
	vector<StaffInfor*> result;
	for(unsigned int i = 0; i < m_data.size(); i++)
	{
	    if( m_data[i]->m_PositionId == id)
	    {
		    result.push_back(m_data[i]);
		}
	}
	return result;
}
void StaffInforDB::DeleteStaff(int id)
{
	StaffInfor * staff;
	for(unsigned int i = 0; i < m_data.size(); i++)
	{
	    if( m_data[i]->m_Id == id)
	    {
		    staff =  m_data[i];
		    m_data.erase(m_data.begin() + i);
		    SAFE_DEL(staff);
		    return;
		}
	}
}
void StaffInforDB::AddStaff(StaffInfor * newStaff)
{
      if(newStaff)
      {
	      m_data.push_back(newStaff);
	  }
}
void StaffInforDB::Import(const char *fileTxt)
{
	FILE * pFile = NULL;
	pFile = fopen(fileTxt, "r");
	if(pFile == NULL)
	{
	    printf("\n Can not to read file %s", fileTxt);
	    return;
	}
	int number = 0;
	fscanf(pFile, " NumberStaff : %d \n", &number);
	if(number <= 0)
	{
	    printf("\n File ERROR!");
	    return;  
	}
	for(int i = 0; i < number; i++)
	{
		int id, sex, divisionId, positionId, isMarried;
		char address[255], fullName[255] , birthdayStr[255];
		
		fscanf(pFile, " Id : %d \n", &id);
		fscanf(pFile, " Name : %[^\n] \n", &fullName);
		fscanf(pFile, " Sex : %d \n", &sex);
		fscanf(pFile, " BirthDay : %[^\n] \n", &birthdayStr);
		fscanf(pFile, " Married : %d \n", &isMarried);
		fscanf(pFile, " Address : %[^\n] \n", &address);
		fscanf(pFile, " PositionId : %d \n", &positionId);
		fscanf(pFile, " DivisionId : %d \n", &divisionId);
		
		
		StaffInfor * staff = new StaffInfor();
		MyDate birthday(birthdayStr);
		
		staff->SetId(id);
		staff->SetFullName(fullName);
		staff->SetSex((ESex)sex);
		staff->SetBirthDay(birthday);
		staff->SetMarried(isMarried == 1);
		staff->SetAddress(address);
		staff->SetPositionId(positionId);
		staff->SetDivisionId(divisionId);
		
		m_data.push_back(staff);
    }
    fclose(pFile);
	printf("\n Import done!");	
}
void StaffInforDB::Export(const char *fileTxt)
{
	FILE * pFile = NULL;
	pFile = fopen(fileTxt, "w");
	if(pFile == NULL)
	{
	    printf("\n Can not write file %s", fileTxt);
	    return;
	}
	int number = (int) m_data.size();
    fprintf(pFile, " NumberStaff : %d \n\n", number);

	for(int i = 0; i < number; i++)
	{
		int id, sex, divisionId, positionId, isMarried;
		char * birthday;
		birthday = m_data[i]->m_BirthDay.ToString();
		
		fprintf(pFile, " Id : %d \n", m_data[i]->m_Id);
		fprintf(pFile, " Name : %s \n", m_data[i]->m_FullName);
		fprintf(pFile, " Sex : %d \n", m_data[i]->m_Sex);
		fprintf(pFile, " BirthDay : %s \n", birthday);
		fprintf(pFile, " Married : %d \n", m_data[i]->m_IsMarried);
		fprintf(pFile, " Address : %s \n", m_data[i]->m_Address);
		fprintf(pFile, " PositionId : %d \n", m_data[i]->m_PositionId);
		fprintf(pFile, " DivisionId : %d \n\n", m_data[i]->m_DivisionId);
		SAFE_DEL(birthday);
    }
	fclose(pFile);
	printf("\n Export done!");	
}
vector<StaffInfor*> StaffInforDB::GetData()
{
    return m_data;
}

