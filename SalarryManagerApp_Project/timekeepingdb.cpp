#include "timekeepingdb.h" // class's header file
#include "timekeeping.h" // class's header file

// class constructor
TimekeepingDB::TimekeepingDB()
{
	// insert your code here
}

// class destructor
TimekeepingDB::~TimekeepingDB()
{
	// insert your code here
}
		
void TimekeepingDB::Load()
{
	printf("\n TimekeepingDB Loading!");
	FILE * pFile = NULL;
	pFile = fopen(m_dbName, "rb");
	if(pFile == NULL)
	{
	    printf("\n Can not to read file %s", m_dbName);
	    return;
	}
	Timekeeping timekeeping;
	while( fread( &timekeeping, sizeof(Timekeeping), 1, pFile))
	{
	   Timekeeping * temp = new Timekeeping(timekeeping);
	   m_data.push_back(temp);  
	}
	fclose(pFile);
	printf("\n TimekeepingDB Load() done!");
	
}
void TimekeepingDB::Save()
{
	FILE * pFile = NULL;
	pFile = fopen(m_dbName, "wb");
	if(pFile == NULL)
	{
	    printf("\n Can not to save file %s", m_dbName);
	    return;
	}
	for(unsigned int i = 0 ; i < m_data.size(); i++)
	{
	   fwrite(m_data[i], sizeof(Timekeeping), 1, pFile);
   }
    fclose(pFile);
  //  MyUtil::MyCopyFile(tempFile, m_dbName);
	printf("\n Save done!");
}
void TimekeepingDB:: UnLoad()
{
    while( !m_data.empty() )
    {
	    SAFE_DEL(m_data.back());
	    m_data.pop_back();
	};
	printf("\n UnLoad() done!");
}		
void TimekeepingDB::SaveOnlyChange()
{
	// insert your code here
}

void TimekeepingDB::Import(const char *fileTxt)
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
		  int staffId = -1;
		  char date[255] = "";
		  int workday;
		  fscanf(pFile, " StaffId : %d \n ", &staffId);
	      fscanf(pFile, " Date : %s \n ", &date);
	      fscanf(pFile, " Workday : %d \n ", &workday);
	      
	   //   printf("\n %d %20s %d", staffId, date, workday);

	      Timekeeping * timekeeping = new Timekeeping(staffId, date, workday);
	   //   printf("\n -> %d %10s %d", timekeeping->GetStaffId(), timekeeping->GetDate().ToString(), timekeeping->GetWorkday());
	      m_data.push_back(timekeeping);
	}
	fclose(pFile);
	printf("\n Import done!");	
}
void TimekeepingDB::Export(const char *fileTxt)
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
		  char * date = m_data[i]->GetDate().ToString();
		  
		  fprintf(pFile, " StaffId : %d \n", m_data[i]->GetStaffId());
	      fprintf(pFile, " Date : %s \n", date);
	      fprintf(pFile, " Workday : %d \n\n", m_data[i]->GetWorkday());
         Timekeeping * timekeeping = m_data[i];
	    //printf("\n -> %d %10s %d", timekeeping->GetStaffId(), timekeeping->GetDate().ToString(), timekeeping->GetWorkday());
	      
	      SAFE_DEL(date);
	}
	fclose(pFile);
	printf("\n Export done!");	
}
vector<Timekeeping*> TimekeepingDB::GetData()
{
    return m_data;
}
Timekeeping * TimekeepingDB::FindByStaffId(int id)
{
	for(unsigned int i = 0; i < m_data.size(); i++)
	{
	    if(m_data[i]->m_staffId == id)
	    {
		    return m_data[i];
		}
	}
	return 0; // NULL
}
