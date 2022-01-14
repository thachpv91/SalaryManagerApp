#ifndef TIMEKEEPING_H
#define TIMEKEEPING_H
#include "MyDefine.h"
#include "MyDate.h"
/*
 * Cham Cong
 */
class MyDate;
class Timekeeping
{
	// private section
	public:
		// class constructor
		Timekeeping();
		Timekeeping(Timekeeping &timekeeping);
		Timekeeping(int staffId, const char *date, int workday);
		// class destructor
		~Timekeeping();
		
		void SetStaffId(int StaffId);
		void SetDate(MyDate date);
		void SetWorkday(int workday) {m_workday = workday; };
		
		int GetStaffId();
		MyDate GetDate();
		int GetWorkday() { return m_workday; };
		
	//protected:
		int    m_staffId;
		MyDate m_date;
		int m_workday;
};

#endif // TIMEKEEPING_H

