#include <iostream>
#include "timer.h"

/*/
Considering quadratics of the form:
n^2 + an + b, where |a|<1000 and |b|<1000

Find the product of the coefficients, a and b, for the quadratic expression 
that produces the maximum number of primes for consecutive values of n,
starting with n=0.
/*/

bool isprime(int num) {
    int i = 2, init=num;
    if(!num) return false;
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
    int product;
    const short CAP = 1000;
    //attempt1  - bruteforce
    {
        product = 0;
        short max = 0;
        long n;
        Timer t;
        for(short a = -(CAP-1); a<CAP; a++) {
            for(short b = -(CAP-1); b<CAP; b++) {
                n = 0;
                while(isprime(n*n + a*n + b))
                    ++n;
                if(n>max) {
                    max = n;
                    product = a*b;
                } 
            }
        }  
    }
    std::cout<<product<<std::endl;
    return 0;
}

