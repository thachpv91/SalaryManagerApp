#ifndef ADVANCEPAYMENT_H
#define ADVANCEPAYMENT_H
#include "MyDate.h"
/*
 * Tam Ung
 */
class AdvancePayment
{
	// private section
	public:
		// class constructor
		AdvancePayment();
		AdvancePayment(AdvancePayment &advancePayment);
		AdvancePayment(int staffId, const char *date, unsigned long money);
		// class destructor
		~AdvancePayment();
		
		void SetStaffId(int StaffId);
		void SetDate(MyDate date);
		void SetMoney(unsigned long money) { m_money = money; };
		
		int GetStaffId();
		MyDate GetDate();
		unsigned long GetMoney() { return m_money; };
		
	protected:
		int    m_staffId;
		MyDate m_date;
		unsigned long m_money;
};

#endif // ADVANCEPAYMENT_H

