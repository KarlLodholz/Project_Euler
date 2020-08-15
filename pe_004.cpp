#include <iostream>
#include "timer.h"

/*/
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers.
/*/

int main() {

    int pal = 0, n1 = 999, n2 = 999, i=0,t;
    //attempt1
    {
        Timer time;
        while (!pal) {
            for(int j=0;j<2;j++) {
                for(int k=0; k<=i; k++) {
                    t=(n1-i-k)*(n2-i+k);
                    // bool isPal=true;
                    // isPal&=a;
                    // isPal&=b;
                    if(t/100000 == (t%10) && (t/10000)%10 == (t%100)/10 && (t/1000)%100 == (t%1000)/100)
                        pal = t;
                }
                ++i;
            }
        }
    }

    std::cout<< pal <<std::endl;
    return 0;
}