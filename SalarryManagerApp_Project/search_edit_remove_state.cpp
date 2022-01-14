#include "search_edit_remove_state.h" // class's header file
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
#include "DataBase.h"
// class constructor
Search_Edit_Remove_State::Search_Edit_Remove_State()
{
	// insert your code here
}

// class destructor
Search_Edit_Remove_State::~Search_Edit_Remove_State()
{
	// insert your code here
}
void Search_Edit_Remove_State::Init()
{
   m_staffinforDB = GetSalaryMgr()->GetDataBase()->GetStaffInforDB();
}
void Search_Edit_Remove_State::Update()
{
	  CLEAR_SCREEN();
      DisplayMenu();
      char c ;
      scanf(" %c", &c);
      
      switch(c)
      {
	      case '1' : Search_ByName(); break;
	      case '2' : Search_ById();break; 
	      case '3' : Search_ByDivision();break;
	      case '4' : Search_ByPosition(); break;
	      case '5' : Edit_Delete_Staff(); break;
	      case '6' : GetSalaryMgr()->SetAppState(new MainMenuState()); return;
		  default  : 
		             printf(TEXT_PLEASE_RECHOISE); 
					 Sleep(500);
	  }
}
void Search_Edit_Remove_State::DisplayMenu()
{
     printf("\n\n\t   Search , Edit and Delelte \n");
     printf("\n --------------------------------\n");
     printf("\n 1. Search By Name");
     printf("\n 2. Search By ID");
     printf("\n 3. Search By Division");
     printf("\n 4. Search By Position");
     printf("\n 5. Edit and Delelte");
     printf("\n 6. To Back ");
     printf("\n --------------------------------\n");
     printf("\n Choise: ");
}
void Search_Edit_Remove_State::Search_ByName()
{
	char ch;
	while(1)
	{
	
		char name[255] = "";
    	printf("\n\n + Enter Name: ");
    	fflush(stdin);
    	gets(name);
    	vector<StaffInfor *> staffs = m_staffinforDB->FindByName(name);
    	if(staffs.empty())
   		{
	    	printf("\n Not found!");
	    	Sleep(500);
		}else
		{
		  printf("\n Found %d \"%s\"", (int)staffs.size(), name);
		  DisplayStaffList(staffs);
		  printf("\n\n----------------------------------------------------------------\n");
	    }
		printf("\n Do you want to continue?(y/n) ");
		ch = getch();
		if( ch == 'n' || ch == 'N') return;
	}	
}
void Search_Edit_Remove_State::Search_ById()
{
	char ch;
	while(1)
	{
		int id;
    	printf("\n\n + Enter StaffId: ");
        scanf(" %d", &id);
    	StaffInfor * staff = m_staffinforDB->FindById(id);
    	if(staff == NULL)
   		{
	    	printf("\n Not found!");
	    	Sleep(500);
		}else
		{
		  vector< StaffInfor *> temp;
		  temp.push_back(staff);
		  DisplayStaffList(temp);
		  printf("\n\n----------------------------------------------------------------\n");
	    }
		printf("\n Do you want to continue?(y/n) ");
		ch = getch();
		if( ch == 'n' || ch == 'N') return;
	}	
}
void Search_Edit_Remove_State::Search_ByDivision()
{
	char ch;
	while(1)
	{
		char divisionName[255] = "";
    	printf("\n\n + Enter Division's name: ");
    	fflush(stdin);gets(divisionName);
    	Division * division = GetSalaryMgr()->GetDataBase()->GetDivisionDB()->FindByName(divisionName);

    	vector<StaffInfor *> staffs ;
		if(division != NULL) staffs = m_staffinforDB->FindByDivisionId(division->GetId());
    	if(staffs.empty())
   		{
	    	printf("\n Not found!");
	    	Sleep(500);
		}else
		{
		  printf("\n Found %d \"%s\"", (int)staffs.size(), divisionName);
		  DisplayStaffList(staffs);
		  printf("\n\n----------------------------------------------------------------\n");
	    }
		printf("\n Do you want to continue?(y/n) ");
		ch = getch();
		if( ch == 'n' || ch == 'N') return;
	}
}
void Search_Edit_Remove_State::Search_ByPosition()
{
	char ch;
	while(1)
	{
		char positionName[255] = "";
    	printf("\n\n + Enter Position's name: ");
    	fflush(stdin);
    	gets(positionName);
    	Position * position = GetSalaryMgr()->GetDataBase()->GetPositionDB()->FindByName(positionName);
    	vector<StaffInfor *> staffs ;
		if(position != NULL) staffs = m_staffinforDB->FindByPositionId(position->GetId());
    	if(staffs.empty())
   		{
	    	printf("\n Not found!");
	    	Sleep(500);
		}else
		{
		  printf("\n Found %d \"%s\"", (int)staffs.size(), positionName);
		  DisplayStaffList(staffs);
		  printf("\n\n----------------------------------------------------------------\n");
	    }
		printf("\n Do you want to continue?(y/n) ");
		ch = getch();
		if( ch == 'n' || ch == 'N') return;
	}
}
void Search_Edit_Remove_State::Edit_Delete_Staff()
{
      while(1)
      {
      	  int id;
      	  char ch;
	      printf("\n + Enter Id: ");
	      scanf(" %d", &id);
	      StaffInfor * staff = m_staffinforDB->FindById(id);
	      if(staff != NULL) 
	      {
	      	    GetSalaryMgr()->DisplayAllInforStaff(id);
	      	    printf("\n----------------------------------------------------------------");
	      		printf("\n + [Delete]   : To Delete");
	     	 	printf("\n + [Alpha key]: To Edit");
	     		printf("\n + [Esc]      : To Back");
	   			printf("\n + [Enter]    : To Skip\n");
	      	
	      		ch = getch();
	      		if(ch == SPECIAL_KEY) ch = getch();
	      		switch(ch)
	      		{
			      case  DELETE_SKEY: DeleteStaff(staff); break;
				  case  ESC_KEY: return; 
				  case  ENTER_KEY: break;
				  default: EditStaff(staff);
				}
	      }else
	      {
	    	printf("\n Not found!");
	    	Sleep(500);
		  }
		  printf("\n Do you want to continue?(y/n) ");
		  ch = getch();
		  if(ch == 'n' || ch == 'N') break;
	      
	  }
}
void Search_Edit_Remove_State::DeleteStaff(StaffInfor * staff)
{
       if(!GetSalaryMgr()->HaveRole(DEL_INFOR))
       {
	       printf("\n No permission to delelte!\n");
	       Sleep(1000);
	       return;
	   }
	   char name[255] = "";
	   strcpy(name, staff->m_FullName);
	   m_staffinforDB->DeleteStaff(staff->m_Id);
	   printf("\n Deleled \"%s\" complele!", name);
	   Sleep(1000);
}
void Search_Edit_Remove_State::EditStaff(StaffInfor * staff)
{
	
       if(!GetSalaryMgr()->HaveRole(DEL_INFOR))
       {
	       printf("\n No permission to modified!\n");
	       return;
	   }
     printf("\n -------------------------------------------------------");
     printf("\n EDIT ");
     printf("\n -------------------------------------------------------");
    // printf("\n [1]: Name - [2]: BirthDay - [3]: Sex  - [4] : Address");
    // printf("\n [5]: Position - [6]: Division ");
    // printf("\n -------------------------------------------------------");
    
     while(1)
     {
     	    char tempStr[255] = "";
     	    int choise = 0;
     	    char positionStr[255], divisionStr[255];
     	    char * birthdayStr = staff->m_BirthDay.ToString();
     	    char sexStr[10];
     	    if(staff->m_Sex == MALE)         strcpy(sexStr, "Nam");
		    else if( staff->m_Sex == FEMALE) strcpy(sexStr, "Nu");
		    else strcpy(sexStr, "Khac");
			GetSalaryMgr()->GetDivisionStringByStaffId(staff->m_Id, divisionStr); 
			GetSalaryMgr()->GetPositionStringByStaffId(staff->m_Id, positionStr); 
			
     	    printf("\n\n\n %d %s %s %s %s %s %s", staff->m_Id, staff->m_FullName,
			         birthdayStr, sexStr, staff->m_Address, positionStr, divisionStr);
     	    
     	    printf("\n -------------------------------------------------------");
    	    printf("\n [1]: Name - [2]: BirthDay - [3]: Sex  - [4] : Address");
   		    printf("\n [5]: Position - [6]: Division - [0]: Complete edit");
    	    printf("\n -------------------------------------------------------");
	        printf("\n Choise: ");
	        scanf(" %c", &choise);
	        switch(choise)
	        {
			    case '1':  printf("\n Edit Name");
				           printf("\n + Name: %s", staff->m_FullName);
				           printf("\n + Enter New Name: ");
				           fflush(stdin);
						   gets(tempStr);
						   staff->SetFullName(tempStr);
				           printf("\n Change name complete!");
				           break;
				case '2': {
				           printf("\n Edit birthday");
				           printf("\n + Birthday: %s", birthdayStr);
				           MyDate date;
						   do
						   {
				              printf("\n + New birthday: ");
				              scanf(" %s", tempStr);
				              date = MyDate(tempStr);
				           }while(date.year <= 1); // year == 1 -> Khong hop le
				            staff->SetBirthDay(date);
				            printf("\n Change birthday complete!");
				            break;
				          }
				case '3': {
				            printf("\n Choise Sex: [0]: Nu - [1]: Nam - [2]: Khac");
				            int sex = -1;
				            while( sex != 0 || sex != 1 || sex || 2)
				            {
						      scanf(" %d", &sex);
						    }
						    staff->SetSex((ESex)sex);
						    printf("\n Change sex complete!");
						    break;
						  }
				 case '4': printf("\n Change Address");
				           printf("\n + Address: %s", staff->m_Address);
				           printf("\n + New Address: ");
				           fflush(stdin);
						   gets(tempStr);
						   staff->SetAddress(tempStr);
						   printf("\n Change Address complete!");
						   break;
				 case '5':{
							 printf("\n Change Position");
				             printf("\n + Position: %d - %s", staff->m_PositionId, positionStr);
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
						    printf("\n Change position complete!");
						    break;
						}
				 case '6':{  printf("\n Change Division");
				            printf("\n + Division: %d - %s", staff->m_DivisionId, divisionStr);
				            printf("\n + List Division: ");
				            GetSalaryMgr()->DisplayDivisionList();
				            int disisionId;
				            Division * division = NULL;
				            do
							{
							   printf("\n Choise division id: "); scanf(" %d", &disisionId);
							   division = GetSalaryMgr()->GetDataBase()->GetDivisionDB()->FindById(disisionId);
						   }while(division == NULL);
						   staff->SetPositionId(disisionId);
						   printf("\n Change division complete!");
						   break;
					}
				 case '0':  GetSalaryMgr()->GetDataBase()->GetStaffInforDB()->Save();
				            return;
				 default : printf("\n Please choise again!");		              
			}
			getch();
	 }
}
void Search_Edit_Remove_State::DisplayStaffList(vector<StaffInfor *> staffs)
{
	   	DivisionDB * divisionDB = GetSalaryMgr()->GetDataBase()->GetDivisionDB();
		PositionDB * positionDB = GetSalaryMgr()->GetDataBase()->GetPositionDB();
		const char * format = "%-2d %-25s %-5s %-10s %-10s";
		
	   //                       id Name  Sex Position Division
	    printf("\n\n----------------------------------------------------------------");
	    printf("\n%-3s %-25s %-5s %-10s %-10s", "Id", "Name", "Sex", "Division", "Position");
	    printf("\n----------------------------------------------------------------");
		for(unsigned int i = 0 ; i < staffs.size(); i++)
		{
			 char sexStr[10], divisionStr[255], positionStr[255], str[255] = "";
		     Division * division = divisionDB->FindById( staffs[i]->m_DivisionId );
		     Position * position = positionDB->FindById( staffs[i]->m_PositionId );
		     if(division)
		     {
			     strcpy(divisionStr, division->m_Name);
			 }else
			 {
			   	strcpy(divisionStr, "Unknown");
			 }
			 
			 if(position)
		     {
			     strcpy(positionStr, position->m_Name);
			 }else
			 {
			   	 strcpy(divisionStr, "Unknown");
			 }
		     if(staffs[i]->m_Sex == MALE)         strcpy(sexStr, "Nam");
		     else if( staffs[i]->m_Sex == FEMALE) strcpy(sexStr, "Nu");
		     else 	                              strcpy(sexStr, "Khac");
		     sprintf(str, format,  staffs[i]->m_Id,  staffs[i]->m_FullName,  sexStr, divisionStr, positionStr);
		     
		     printf("\n %s", str);		     
		}
}
