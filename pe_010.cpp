#include <iostream>
#include "timer.h"

/*/
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.
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
    unsigned long long int primei = 3, sum = 2;
    //attempt1 
    {
        Timer t;

        while (primei < 2000000) {
            if(isprime(primei)) sum += primei;
            primei += 2;
        }
    }
    std::cout<< sum <<std::endl;
    return 0;
}