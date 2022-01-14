#include "discipline.h" // class's header file
#include "MyDefine.h"
// class constructor
Discipline::Discipline()
{
	// insert your code here
}

// class destructor
Discipline::~Discipline()
{
	// insert your code here
}
Discipline::Discipline(Discipline &discipline)
{
 	m_staffId = discipline.GetStaffId();
	m_date = discipline.GetDate();
	discipline.GetReason(m_reason);  
}
Discipline::Discipline(int staffId, const char *date, const char * reason, unsigned long money)
{
	m_staffId = staffId;
	m_date = MyDate(date);
	strcpy(m_reason, reason);
	m_money = money;
}
void Discipline::SetStaffId(int staffId)
{
	m_staffId = staffId;
	// insert your code here
}
void Discipline::SetDate(MyDate date)
{
	// insert your code here
	m_date = date;
}
void Discipline::SetReason(const char *reason)
{
	strcpy(m_reason, reason);
	// insert your code here
}
int Discipline::GetStaffId()
{
    return m_staffId;
}
MyDate Discipline::GetDate()
{
    return m_date;
}
void Discipline::GetReason(char * reason)
{
    strcpy(reason, m_reason);
}
