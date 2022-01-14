#ifndef SALARY_H
#define SALARY_H
#include "StaffInfor.h"
/*
 * No description
 */
class MyDate;
class StaffInfor;
class Salary
{
	// private section
	public:
		//static unsigned int s_basicSalary;
		// class constructor
		Salary();
		Salary(StaffInfor &staff);
		// class destructor
		~Salary();
		void SetStaffInfor(StaffInfor &staff);
		void ComputeSalaryMoney();
	    
		char * ToString(); 	
	//protected:
		void Init(StaffInfor &staff);
		
		int    m_staffId;
		char   m_fullName[255];
		MyDate m_date;
		int    m_wordDay;
		int    m_coefficientPay;
		char   m_position[255];
		
		unsigned long    m_bonus;
		unsigned long    m_discipline;
		unsigned long    m_advancePayment;
		
		unsigned long    m_salary;
		
};

#endif // SALARY_H

