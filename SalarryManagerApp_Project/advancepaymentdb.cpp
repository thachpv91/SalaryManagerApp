#include "advancepaymentdb.h" // class's header file
#include "advancepayment.h" // class's header file

// class constructor
AdvancePaymentDB::AdvancePaymentDB()
{
	// insert your code here
}

// class destructor
AdvancePaymentDB::~AdvancePaymentDB()
{
	// insert your code here
}
void AdvancePaymentDB::Load()
{
	printf("\n AdvancePaymentDB Loading!");
	FILE * pFile = NULL;
	pFile = fopen(m_dbName, "rb");
	if(pFile == NULL)
	{
	    printf("\n Can not to read file %s", m_dbName);
	    return;
	}
	AdvancePayment advancePayment;
	while( fread( &advancePayment, sizeof(AdvancePayment), 1, pFile))
	{
	   AdvancePayment * temp = new AdvancePayment(advancePayment);
	   m_data.push_back(temp);  
	}
	fclose(pFile);
	printf("\n AdvancePaymentDB Loading done!");
}
void AdvancePaymentDB::Save()
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
	   fwrite(m_data[i], sizeof(AdvancePayment), 1, pFile);
   }
    fclose(pFile);
  //  MyUtil::MyCopyFile(tempFile, m_dbName);
	printf("\n Save done!");
}
void AdvancePaymentDB:: UnLoad()
{
    while( !m_data.empty() )
    {
	    SAFE_DEL(m_data.back());
	    m_data.pop_back();
	};
	printf("\n UnLoad() done!");
}		
void AdvancePaymentDB::SaveOnlyChange()
{
	// insert your code here
}
void AdvancePaymentDB::Import(const char *fileTxt)
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
	    printf("\n File %s ERROR!", fileTxt);
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
	      fscanf(pFile, " Money : %lu \n", &money);
	      AdvancePayment * advancePayment = new AdvancePayment(staffId, date, money);
	      m_data.push_back(advancePayment);
	}
	fclose(pFile);
	printf("\n Import done!");	
}
void AdvancePaymentDB::Export(const char *fileTxt)
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
		  date = m_data[i]->GetDate().ToString();
		  fprintf(pFile, "\n StaffId : %d \n", m_data[i]->GetStaffId());
	      fprintf(pFile, " Date : %s \n", date);
	      fprintf(pFile, " Money : %lu \n", m_data[i]->GetMoney());
	      SAFE_DEL(date);
	}
	fclose(pFile);
	printf("\n Import done!");	
}
vector<AdvancePayment*> AdvancePaymentDB::GetData()
{
    return m_data;
}
AdvancePayment * AdvancePaymentDB::FindByStaffId(int id)
{
    for(unsigned int i = 0; i < m_data.size(); i++)
    {
	    if( m_data[i]->GetStaffId() == id)
	    {
		     return m_data[i];
		}
	}
	return 0; // NULL
}
