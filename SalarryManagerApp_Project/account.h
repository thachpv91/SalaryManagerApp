#ifndef ACCOUNT_H
#define ACCOUNT_H

/*
 * No description
 */
enum ERole
{
    READ_INFOR = 1 << 0,
    WRITE_INFOR = 1 << 1,
    DEL_INFOR = 1 << 2,
    ADD_INFOR = 1 << 3,
    MODIFIED_INFOR = READ_INFOR | WRITE_INFOR | DEL_INFOR | ADD_INFOR,
    MODIFIED_USER  = MODIFIED_INFOR | 1 << 4
};
class Account
{
	// private section
	public:
		// class constructor
		Account();
		Account(const Account &acc);
		Account(int id, const char * username, const char * pass, ERole role);
		// class destructor
		~Account();
		
		void SetId(int id);
		void SetUserName(const char * username);
		void SetPassWord(const char * pass);
		void SetRole(ERole role);
		void ToString(char * accString);
		
		
		
		static ERole GetUserRole(const char *position);
		static void GetPositionByRole(ERole role, char *position);
//	protected:
	 	int  m_id;
		char m_userName[255];
		char m_passWord[255];
		ERole m_role;
		
};

#endif // ACCOUNT_H

