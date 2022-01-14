#include "addnewstaffstate.h" // class's header file
#include "MyDefine.h"
#include "MyDate.h"
#include "SalaryManager.h"
#include "MainMenustate.h"
#include "Position.h"
#include "Division.h"
#include "StaffInfor.h"
#include "PositionDB.h"
#include "DivisionDB.h"
#include "StaffInforDB.h"
#include "StaffInfor.h"
#include "DataBase.h"
// class constructor
AddNewStaffState::AddNewStaffState()
{
	// insert your code here
}

// class destructor
AddNewStaffState::~AddNewStaffState()
{
	// insert your code here
}
void AddNewStaffState::Init()
{
}
void AddNewStaffState::Update()
{
	  CLEAR_SCREEN();
      DisplayMenu();
      char c ;
      scanf(" %c", &c);
      
      switch(c)
      {
	      case '1' : EnterNewStaff(); return;
	      case '2' : ImportStaffFromFile(); return;
	      case '3' : ExportStaffToFile(); return;
	      case '4' : GetSalaryMgr()->SetAppState(new MainMenuState()); return;
	      default  : 
		             printf(TEXT_PLEASE_RECHOISE); 
					 Sleep(500);
	  };

	  
}
void AddNewStaffState::DisplayMenu()
{
     printf("\n\n\t   Add new staff\n");
     printf("\n --------------------------------\n");
     printf("\n 1. Enter new staff");
     printf("\n 2. Import from file txt");
     printf("\n 3. Export all staff to file txt");
     printf("\n 4. Close ");
     printf("\n --------------------------------\n");
     printf("\n Choise: ");
}
void AddNewStaffState::EnterNewStaff()
{
	if(!GetSalaryMgr()->HaveRole(ADD_INFOR))
    {
	       printf("\n No permission to add!\n");
	       Sleep(500);
	       return;
   }
   int id;
   char ch = 0;
   while(1)
   	{    
        printf("\n\n Enter new staff");
        printf("\n -----------------------------------------------------------------");
        char tempStr[255] = "";
        StaffInfor * staff = new StaffInfor();
        for(int i = 0; i < 7; i++)
        {
		    switch(i)
		    {
		    	case 0:    id = GetSalaryMgr()->GetDataBase()->GetStaffInforDB()->GetData().size() + 1; 
				           staff->SetId(id); break;
			    case 1:    printf("\n + Enter New Name: ");
			               do{ fflush(stdin); gets(tempStr);
			               }while(strlen(tempStr) < 2);
						   staff->SetFullName(tempStr);
				           break;
				case 2: {
				           MyDate date;
						   do
						   {
				              printf("\n + New birthday: ");
				              scanf(" %s", tempStr);
				              date = MyDate(tempStr);
				           }while(date.year <= 1); // year == 1 -> Khong hop le
				            staff->SetBirthDay(date);
				            break;
				          }
				case 3: {
				            printf("\n Choise Sex: [0]: Nu - [1]: Nam - [2]: Khac\n");
				            int sex = -1;
				            while( !(sex == 0 || sex == 1 || sex == 2))
				            {
						      scanf(" %d", &sex);
						    }
						    staff->SetSex((ESex)sex);
						    break;
						  }
				 case 4: printf("\n + New Address: ");
				           fflush(stdin);
						   gets(tempStr);
						   staff->SetAddress(tempStr);
						   break;
				 case 5:{ 
				             printf("\n + List position: ");
				             GetSalaryMgr()->DisplayPositionList();
				             int positionId;
				             Position * position = NULL;
				             do
						  	{
						 	   printf("\n Choise postion id: "); scanf(" %d", &positionId);
							   position = GetSalaryMgr()->GetDataBase()->GetPositionDB()->FindById(positionId);
						    }while(position == NULL);
						    staff->SetPositionId(positionId);
						    break;
						}
				 case 6:{ printf("\n + List Division: ");
				            GetSalaryMgr()->DisplayDivisionList();
				            int disisionId;
				            Division * division = NULL;
				            do
							{
							   printf("\n Choise division id: "); scanf(" %d", &disisionId);
							   division = GetSalaryMgr()->GetDataBase()->GetDivisionDB()->FindById(disisionId);
						   }while(division == NULL);
						   staff->SetPositionId(disisionId);
						   break;
					     }
			}
		} // end for
		GetSalaryMgr()->GetDataBase()->GetStaffInforDB()->AddStaff(staff);
		GetSalaryMgr()->GetDataBase()->GetStaffInforDB()->Save();
		printf("\n\n Do you want to continue?(y/n) ");
		ch = getch();
		if(ch == 'n' || ch == 'N') return;
		printf("\n -----------------------------------------------------------------");
		
   } 
}
void AddNewStaffState::ImportStaffFromFile()
{
	  char fileName[255] = "";
      printf("\n\n-----------------------------------------------------------------");
      printf("\n Import new staff from file");
      printf("\n\n + Enter file name: "); 
      do{ fflush(stdin); gets(fileName);
	  }while(strlen(fileName) < 3);
	  GetSalaryMgr()->GetDataBase()->GetStaffInforDB()->Import(fileName);
	  
}
void AddNewStaffState::ExportStaffToFile()
{
	  char fileName[255] = "";
      printf("\n\n-----------------------------------------------------------------");
      printf("\n Export allstaff to file");
      printf("\n\n + Enter file name: "); 
      do{ fflush(stdin); gets(fileName);
	  }while(strlen(fileName) < 3);
	  GetSalaryMgr()->GetDataBase()->GetStaffInforDB()->Export(fileName);
	  printf("\n Export compelete!");
	  Sleep(500);
}
			    
