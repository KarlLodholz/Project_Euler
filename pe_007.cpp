#include <iostream>
#include "timer.h"

/*/
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
What is the 10,001st prime number?
/*/

bool isprime(int num) {
    int i = 2, init=num;
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
    return i == init;
}

int main() {
    int i = 2;
    unsigned long long int primei = 3;
    //attempt1 
    {
        Timer t;

        while (i < 10001) {
            primei += 2;
            if(isprime(primei)) ++i;
        }
    }
    std::cout<< primei <<std::endl;
    return 0;
}