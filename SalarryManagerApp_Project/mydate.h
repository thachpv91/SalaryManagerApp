#ifndef MYDATE_H
#define MYDATE_H

// No description
class MyDate
{
	// private section
		void SetDate(int iDay, int iMonth, int iYear);
	
	public:
		// class constructor
		MyDate(int day = 1, int month = 1, int year = 1);
		MyDate(const char * dateString);
		// class destructor
		~MyDate();
		
		char * ToString();
		
		int day, month, year;
		              

	static bool IsLeapYear(int year);
	static int  GetDayNumber(int month, int year);

};
#endif // MYDATE_H

