#ifndef BONUS_H
#define BONUS_H
#include "MyDate.h"
class MyDate;
class Bonus
{
	// private section
	public:
		// class constructor
		Bonus();
		Bonus(Bonus &bonus);
		Bonus(int staffId, const char *data, const char * reason, unsigned long money);
		// class destructor
		~Bonus();
		
		void SetStaffId(int StaffId);
		void SetDate(MyDate date);
		void SetReason(const char *reason);
		void SetMoney(unsigned long money) { m_money = money; };
		
		int GetStaffId();
		MyDate GetDate();
		void GetReason(char * reason);
		unsigned long GetMoney() { return m_money; };
		
	protected:
		int    m_staffId;
		MyDate m_date;
		char   m_reason[255];
		unsigned long m_money;
};

#endif // BONUS_H

