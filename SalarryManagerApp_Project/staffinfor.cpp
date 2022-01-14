#include "staffinfor.h" // class's header file
#include "MyDate.h"
#include "MyDefine.h"
// class constructor
StaffInfor::StaffInfor()
:m_Id(-1)
,m_Sex(FEMALE)
,m_IsMarried(false)
{
	strcpy(m_FirstName,"");
	strcpy(m_LastName, "");
	strcpy(m_FullName, "");
	strcpy(m_Address, "");
}

// class destructor
StaffInfor::~StaffInfor()
{
}
// ID
void StaffInfor::SetId(int i_Id)
{
	m_Id = i_Id;
}
int StaffInfor::GetId()
{
	return m_Id;
}
// FirstName
void StaffInfor::SetFirstName(const char * i_FirstName)
{

     strcpy(m_FirstName, i_FirstName);

}
// LastName
void StaffInfor::SetLastName(const char * i_LastName)
{
   strcpy(m_LastName, i_LastName);
}
// FullName
void StaffInfor::SetFullName(const char * i_FullName)
{

        strcpy(m_FullName, i_FullName);
        
        char firstName[255] = "", lastName[255] = "";
        int lastSpaceIndex = 0;
        SplitFullName(m_FullName, firstName, lastName);
        
        strcpy(m_FirstName, firstName);
		strcpy(m_LastName, lastName);

}		
// Address
void StaffInfor::SetAddress(const char * i_Address)
{
	 if( strlen(i_Address) > 0)
	 {
        strcpy(m_Address, i_Address);
	 }
}
// BrithDay
void StaffInfor::SetBirthDay(MyDate i_BirthDay)
{
    m_BirthDay = i_BirthDay;
}
MyDate StaffInfor::GetBirthDay()
{

}
//Sex
void StaffInfor::SetSex(ESex Sex)
{
   m_Sex = Sex;
}
ESex StaffInfor::GetSex()
{
    return m_Sex;
}
// Married
void StaffInfor::SetMarried(bool isMarried)
{
    m_IsMarried = isMarried;
}
bool StaffInfor::IsMarried()
{
    return m_IsMarried;
}
void StaffInfor::SetDivisionId(int Id)
{
      m_DivisionId = Id;
}
int  StaffInfor::GetDivisionId()
{
     return m_DivisionId;
} 	
void StaffInfor::SetPositionId(int Id)
{
     m_PositionId= Id;
} 
int  StaffInfor::GetPositionId()
{
     return m_PositionId;
} 		
void StaffInfor::SplitFullName(char *fullName, char * firstName, char * lastName)
{
	  int lastSpaceIndex = 0;
	 bool isStrim = true;
     for(int i = strlen(fullName) -1 ; i > 0 ; i--)
     {
     	if(!isStrim && fullName[i] == ' ') 
		 {
		    lastSpaceIndex= i;
		    break;
		 }
     	
	     if(isStrim && fullName[i] == ' ')
		 {
		     fullName[i] = '\0';
	     }else
	     {
		    isStrim = false;
		 }
	 }
	 memcpy(lastName, fullName, lastSpaceIndex);
	 memcpy(firstName, fullName + strlen(lastName), strlen(fullName) - lastSpaceIndex);
}
char * StaffInfor::ToString()
{
     char * res = new char[500];
     memset(res,0, 500);
     // Id  FullName  BirthDay  Sex  Address 
     //TEXT_FORMAT_STAFF_INFOR = "%3d %-20s %-15s %d %-25s"
     char sexStr[10] = "";
     if(m_Sex == MALE)         strcpy(sexStr, "Nam");
	 else if(m_Sex == FEMALE) strcpy(sexStr, "Nu");
	 else strcpy(sexStr, "Khac");
     char * birthDateStr = m_BirthDay.ToString();
     sprintf(res,TEXT_FORMAT_STAFF_INFOR, m_Id, m_FullName, birthDateStr, sexStr, m_Address);
     SAFE_DEL(birthDateStr);
     return res;
}

