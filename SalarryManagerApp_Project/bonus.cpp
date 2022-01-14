#include "bonus.h" // class's header file
#include "MyDefine.h"
#include "MyDate.h"
// class constructor
Bonus::Bonus()
{
	// insert your code here
}
Bonus::Bonus(Bonus &bonus)
{
 	m_staffId = bonus.GetStaffId();
	m_date = bonus.GetDate();
	bonus.GetReason(m_reason);  
}
Bonus::Bonus(int staffId, const char *date, const char * reason, unsigned long money)
{
	m_staffId = staffId;
	m_date = MyDate(date);
	strcpy(m_reason, reason);
	m_money = money;
}
// class destructor
Bonus::~Bonus()
{
	// insert your code here
}
void Bonus::SetStaffId(int staffId)
{
	m_staffId = staffId;
	// insert your code here
}
void Bonus::SetDate(MyDate date)
{
	// insert your code here
	m_date = date;
}
void Bonus::SetReason(const char *reason)
{
	strcpy(m_reason, reason);
	// insert your code here
}
int Bonus::GetStaffId()
{
    return m_staffId;
}
MyDate Bonus::GetDate()
{
    return m_date;
}
void Bonus::GetReason(char * reason)
{
    strcpy(reason, m_reason);
}
