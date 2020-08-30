#include <iostream>
#include "timer.h"

/*/
You are given the following information, but you may prefer to do some research for yourself.
    1 Jan 1900 was a Monday.
    Thirty days has September,
    April, June and November.
    All the rest have thirty-one,
    Saving February alone,
    Which has twenty-eight, rain or shine.
    And on leap years, twenty-nine.
    A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
/*/

int main() {
    //num days per month (days in month)
    const int DIM[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    const int STRT_DAY = 1; //1 because sunday is going to 0 when mod by 7
    const int INIT_YEAR = 1901, F_YEAR = 2000;
    int sum;
    //attempt1 
    {   
        sum = 0;
        int temp = STRT_DAY;
        Timer t;  
        for(int y=INIT_YEAR; y<=F_YEAR; y++) {
            for(int m=0; m<12; m++) {
                sum += temp % 7 == 0;
                temp += DIM[m]+(m == 1 && ((y%4==0 && y%100!=0) || (y%400==0)));
            }
        }
        sum -= temp%7==0; //this is to remove the possibility of overcounting past the last date.
    }
    std::cout<<sum<<std::endl;
    return 0;
}