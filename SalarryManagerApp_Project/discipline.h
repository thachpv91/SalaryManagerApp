#ifndef DISCIPLINE_H
#define DISCIPLINE_H
#include "MyDate.h"
/*
 * Ky Luat
 */
class MyDate;
class Discipline
{
	// private section
	public:
		// class constructor
		Discipline();
		Discipline(Discipline &discipline);
		Discipline(int staffId, const char *date, const char * reason, unsigned long money);
		// class destructor
		~Discipline();
		
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

#endif // DISCIPLINE_H

