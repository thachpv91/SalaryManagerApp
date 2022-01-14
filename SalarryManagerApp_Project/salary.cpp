#include "salary.h" // class's header file
#include "MyDefine.h"
// class constructor
Salary::Salary()
{
	 m_staffId = -1;
     strcpy(m_fullName, "");
	 m_date = MyDate();
     m_wordDay = 0;
     m_coefficientPay = 0;
	 strcpy(m_position, "");
		
	 m_bonus = 0;
	 m_discipline = 0;
	 m_advancePayment = 0;
		
	 m_salary = 0;
		
}

// class destructor
Salary::~Salary()
{
	// insert your code here
}
Salary::Salary(StaffInfor &staff)
{
	 m_staffId = -1;
     strcpy(m_fullName, "");
	 m_date = MyDate();
     m_wordDay = 0;
     m_coefficientPay = 0;
	 strcpy( m_position, "");
		
	 m_bonus = 0;
	 m_discipline = 0;
	 m_advancePayment = 0;
		
	 m_salary = 0;
    Init(staff);
}
void Salary::SetStaffInfor(StaffInfor &staff)
{
    Init(staff);
}

void Salary::Init(StaffInfor &staff)
{
      m_staffId = staff.GetId();
      strcpy(m_fullName, staff.m_FullName);
}
void Salary::ComputeSalaryMoney()
{
 	float salaryF = BASIC_SALARY * m_wordDay / 20.0f * m_coefficientPay + m_bonus - m_discipline - m_advancePayment;
    m_salary = int(salaryF);
}
char * Salary::ToString()
{
	// Id  Name NgayThang So_cong Heso  KhenThuong  KyLuat TamUng Thuc_linh
	const char * format = "%-2d %-20s %-12s %5d %4d %9lu %9lu %9lu %15.2f";
	char * result = new char[200];
	memset(result, 0, 200);
	char * date = m_date.ToString();
	sprintf(result, format, m_staffId, m_fullName, date, m_wordDay, m_coefficientPay, m_bonus, m_discipline, m_advancePayment, m_salary / 1000000.0f);
    result[ strlen(result)] = '\0';
    SAFE_DEL(date);
    return result;
}
 
