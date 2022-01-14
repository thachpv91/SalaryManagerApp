#include "account.h" // class's header file
#include "MyDefine.h"
// class constructor
Account::Account()
{
	m_id = -1;
	m_role = READ_INFOR;
	strcpy(m_userName,"");
	strcpy(m_passWord,"");
}
Account::Account(const Account &acc)
{
     m_id = acc.m_id;
     m_role = acc.m_role;
     strcpy(m_userName, acc.m_userName);
   	 strcpy(m_passWord, acc.m_passWord);
}
Account::Account(int id, const char * username, const char * pass, ERole role)
{
  	m_id = id;
  	m_role = role;
	strcpy(m_userName,username);
	strcpy(m_passWord,pass);   
}
void Account::ToString(char * accString)
{
   char temp[255] = "";	
   char position[100];
   GetPositionByRole(m_role, position);
   sprintf(temp, " %3d %-20s %-20s %-5s", m_id, m_userName, m_passWord, position);
   strcpy(accString, temp);
}   
// class destructor
Account::~Account()
{
	// insert your code here
}
void Account::SetUserName(const char *username)
{
    strcpy(m_userName, username);
}
void Account::SetPassWord(const char *pass)
{
    strcpy(m_passWord, pass);
}
void Account::SetId(int id)
{
    m_id = id;
}
void Account::SetRole(ERole role)
{
    m_role = role;
}
//-------------------------------------
// Static begin
//------------------------
ERole Account::GetUserRole(const char *position)
{
    if( strcmp(position, "ADMIN") == 0) 
    {
	    return MODIFIED_USER;
	}
	if( strcmp(position, "MANAGER") == 0) 
    {
	    return MODIFIED_INFOR;
	}
	if( strcmp(position, "USER") == 0) 
    {
	    return READ_INFOR;
	}
	return READ_INFOR;
}
void Account::GetPositionByRole(ERole role, char * position)
{
     if(role & MODIFIED_USER)
     {
	       strcpy(position, "ADMIN");
	 }else if(role & MODIFIED_INFOR)
     {
	       strcpy(position, "MANAGER");
	 }else 
	 {
	      strcpy(position, "USER");
	 }	 
}
//------------------------
// Static end
//------------------------------------------		
