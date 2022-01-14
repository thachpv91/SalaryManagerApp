#ifndef STAFFINFOR_H
#define STAFFINFOR_H
#include "MyDate.h"
// No description
enum ESex
{
    FEMALE = 0,
    MALE,
    OTHER,
};
class MyDate;
class StaffInfor
{
	// private section
	public:
		// class constructor
		StaffInfor();
		// class destructor
		~StaffInfor();
	//protected:
		int m_Id;
		
		char m_FirstName[255];
		char m_LastName[255];
		char m_FullName[255];
		
		MyDate m_BirthDay;
		ESex   m_Sex;
		bool   m_IsMarried;   //
		char   m_Address[255]; // Dia chi hien tru
		
		int    m_DivisionId; // Ma Bo Phan
		int    m_PositionId; // Ma Chuc vu
		
		void SplitFullName(char *fullName, char * firstName, char * lastName);
	 public:
	 	void   SetFirstName(const char *firstName);
	    //void   GetFirstName(char * firsName);
	 	
	 	void   SetLastName(const char *lastName);
	 	//void   GetLastName(char * lastName);
	 	
	 	void    SetFullName(const char * fullName);
	 	//void  GetFullName();
	 	
	 	void   SetAddress(const char *address);
	 	//char * GetAddress();
	 	
	 	
	 	void   SetId(int Id);
	 	int    GetId();
	 	
	 	void   SetSex(ESex sex);
	 	ESex   GetSex();
	 	
	    void   SetBirthDay(MyDate birthDay);
	 	MyDate GetBirthDay();
	 	
	 	void   SetDivisionId(int Id);
	 	int    GetDivisionId();
	 	
	 	void   SetPositionId(int Id);
	 	int    GetPositionId();
	 	
	 	void   SetMarried(bool isMarried);
	 	bool   IsMarried();
		 	 		 	
	 	char * ToString();
		
};
#endif // STAFFINFOR_H



