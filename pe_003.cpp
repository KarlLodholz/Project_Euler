#include <iostream>
#include "timer.h"

/*/
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?
/*/

int main() {
    int i = 2;
    unsigned long long int num = 12;

    //attempt1
    {
        Timer t;
        while(num % i == 0) { 
            num /= i;
        }
        if(num != 1) { 
            ++i;
            while(num > 1) {
                while(num % i == 0) {
                    num /= i;
                }
                i+=2;
            }
            i-=2;
        }
    }
    std::cout<<i<<std::endl;

}