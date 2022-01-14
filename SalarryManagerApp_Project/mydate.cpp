#include "mydate.h" // class's header file
#include <string.h>
#include <stdio.h>
// Static fuction
bool MyDate::IsLeapYear(int year)
{
  if(year <= 0) return false;
  
  return  ( year % 400 == 0 ) || ( year % 4 == 0 && year % 100 != 0) ;

}
int  MyDate::GetDayNumber(int month, int year)
{
	 int dayNumber = 0;
	 
	 if( month < 0 || month > 12 || year < 1)  return -1; // err
	 
     switch(month)
     {
	     case 2: dayNumber = MyDate::IsLeapYear(year) ? 29 : 28; break; 
	     case 4:
	     case 6:
	     case 9:
	     case 11: dayNumber = 30; break;
	     default: dayNumber = 31;
	 }
	 return dayNumber;
}
// Static fuction end
// class constructor
MyDate::MyDate(int iday, int imonth, int iyear)
{
   SetDate(iday, imonth, iyear);
}
MyDate::MyDate(const char * dateString)
{
	int iday, imonth, iyear;
	sscanf(dateString, " %d / %d / %d ", &iday, &imonth, &iyear);
	SetDate(iday, imonth, iyear);
}
// class destructor
MyDate::~MyDate()
{
	// insert your code here
}
void MyDate::SetDate(int iday, int imonth, int iyear)
{
    int dayNumberOfMonth = MyDate::GetDayNumber(imonth, iyear);
    if(dayNumberOfMonth == -1 || iday <= 0 || iday > dayNumberOfMonth )
    {
	    day = month = year = 1;
	}else
	{
	    day = iday; month = imonth; year = iyear;
	}
	//SAFE_DEL(m_dateString);
	
}
char * MyDate::ToString()
{
	  // Format dd/mm/yyyy
      char temp[255] = "";
      char format[255] = "";
	  (day > 9) ? strcat(format, "%d/") : strcat(format, "0%d/");
	  (month > 9) ? strcat(format, "%d/") : strcat(format, "0%d/");
	  strcat(format, "%d");
      
      sprintf(temp, format, day, month, year);
      
      char * result = new char[100];
      memset(result, 0, 100);
	  memcpy(result, temp, strlen(temp));
	  result[strlen(temp)+1] = '\0';
	  
      return result;
}



