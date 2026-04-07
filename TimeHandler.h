#ifndef TIME
#define TIME
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
struct TimeHandler{
	int date;
	int year;
	int month;
	void SetDate(){
		time_t timeH = time(0);
		tm *timeptr = localtime(&timeH);
		date=timeptr->tm_mday;
		year=timeptr->tm_year+1900;
		month=(rand()%12)+1;}
	int GetDate(){
		return date;}
	int GetMonth(){
		return month;}
	void PrintDate(){
		std::cout<<"Date : "<<" "<<date<<"-"<<ReturnMonth(month)<<"-"<<year<<std::endl;}
	std::string ReturnMonth(int month){
    switch(month){
        case 1: return "January";
        case 2: return "February";
        case 3: return "March";
        case 4: return "April";
        case 5: return "May";
        case 6: return "June";
        case 7: return "July";
        case 8: return "August";
        case 9: return "September";
        case 10: return "October";
        case 11: return "November";
        case 12: return "December";
        default: return "Invalid Month";
    }
}
};
#endif
