#include "advancepayment.h" // class's header file

// class constructor
AdvancePayment::AdvancePayment()
{
	// insert your code here
}

// class destructor
AdvancePayment::~AdvancePayment()
{
	// insert your code here
}
AdvancePayment::AdvancePayment(AdvancePayment &advancePayment)
{
 	m_staffId = advancePayment.GetStaffId();
	m_date = advancePayment.GetDate();
	m_money = advancePayment.GetMoney();
}
AdvancePayment::AdvancePayment(int staffId, const char *date, unsigned long money)
{
	m_staffId = staffId;
	m_date = MyDate(date);
	m_money = money;
}
void AdvancePayment::SetStaffId(int staffId)
{
	m_staffId = staffId;
	// insert your code here
}
void AdvancePayment::SetDate(MyDate date)
{
	// insert your code here
	m_date = date;
}
int AdvancePayment::GetStaffId()
{
    return m_staffId;
}
MyDate AdvancePayment::GetDate()
{
    return m_date;
}

