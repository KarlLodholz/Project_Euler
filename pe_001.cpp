#include <iostream>
#include "timer.h"
/* PROBLEM
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.
*/
using namespace std;

int gcd(int a, int b) {return (a ? gcd(b % a, a) : b);}  

int main() {
    //variable init
    const int CAP = 1000;
    const int ROOTS[] = {3,5};
    const int LEN = sizeof(ROOTS)/sizeof(ROOTS[0]);
    int num = 0, sum, n, lcm;


    //attempt 1 
    {
        Timer t;
        sum = 0;
        for(int i=0; i<2; i++) {
            num = 0;
            while(num < CAP) {
                if (!(i && !(num%ROOTS[0]))) //checks is multiple has already been counted
                    sum += num;
                num += ROOTS[i];
            }
        }
    }
    std::cout<< sum <<std::endl;

    //attempt 2
    {
        Timer t;
        sum = 0;
        for(int i=0; i<2; i++) {
            n = (CAP-1)/ROOTS[i];
            sum += (int)(ROOTS[i] * (n/2.0) * (n+1));
        }
        n = (CAP-1) / (ROOTS[0]*ROOTS[1]);
        sum -= (int)((ROOTS[0]*ROOTS[1]) * (n/2.0) * (n+1));
    }
    std::cout<< sum <<std::endl;

    //attempt 3
    //with this attempt the size of the array isn't limited to two integers
    {
        Timer t;
        sum = 0;
        for(int i=0; i<LEN; i++) {
            n = (CAP-1)/ROOTS[i];
            sum += (int)(ROOTS[i] * (n/2.0) * (n+1));
        }

        for(int i=0; i<LEN-1; i++) {
            for(int j=i+1; j<LEN;j++) {
                lcm = (ROOTS[i] * ROOTS[j]) / gcd(ROOTS[i],ROOTS[j]);
                n = (CAP-1)/(lcm);
                sum -= (int)(lcm * (n/2.0) * (n+1));
            }
        }
    }
    
    std::cout<< sum <<std::endl;

}