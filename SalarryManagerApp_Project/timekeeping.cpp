#include "timekeeping.h" // class's header file
#include "MyDefine.h"
#include "MyDate.h"
// class constructor
Timekeeping::Timekeeping()
{
	// insert your code here
}

// class destructor
Timekeeping::~Timekeeping()
{
	// insert your code here
}
Timekeeping::Timekeeping(Timekeeping &timekeeping)
{
		 m_staffId = timekeeping.GetStaffId();
		 m_date = timekeeping.GetDate();
		 m_workday = timekeeping.GetWorkday();	
}
Timekeeping::Timekeeping(int staffId, const char *date, int workday)
{
		 m_staffId = staffId;
		 m_date = MyDate(date);
		 m_workday = workday;
}
		
void Timekeeping::SetStaffId(int staffId)
{
	// insert your code here
	m_staffId = staffId;
}
void Timekeeping::SetDate(MyDate date)
{
	m_date = date;
}		
int Timekeeping::GetStaffId()
{
	return m_staffId;
}
MyDate Timekeeping::GetDate()
{
	return m_date;
}

