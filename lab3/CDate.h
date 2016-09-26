// ...........................................................
// CDate class declaration
// Author: Kimberly Voll, January 2008
// ...........................................................

#ifndef _C_DATE_
#define _C_DATE_

#include <string>
#include <vector>

class CDate
{
public:
	CDate( void );
	CDate( int year, int month, int day );
	CDate( int year, std::string month, int day );
	void setDate( int year, int month, int day );
	void setDate( int year, std::string month, int day );
	bool isValidDate( int year, int month, int day );
	bool isValidDate( int year, std::string month, int day );
	void print( void );
	int getDate( void ); 
	
private:
	int m_year;
	int m_month;
	int m_day;

	int monthStr2Num(std::string month);
	bool isValidDay(int year, int month, int day);

};


const std::string months[13] = {"NAM", "January", "February", "March", "April", "May", "June", "July",
                                "August", "September", "October", "November", "December"};


#endif
