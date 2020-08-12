#include <iostream>
// #include <array>

/* PROBLEM
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.
*/

int main() {
    //variable init
    const int CAP = 1000;
    const int ROOTS[2] = {3,5};
    int num =0, sum = 0;

    //attempt 1
    for(int i=0; i<2; i++) {
        num = 0;
        while(num < CAP) {
            if (!(i && !(num%ROOTS[0]))) //checks is multiple has already been counted
                sum += num;
            num += ROOTS[i];
        }
    }

    std::cout<< sum <<std::endl;

    //attempt 2
    sum = 0;
    int n;
    const int LEN = sizeof(ROOTS)/sizeof(ROOTS[0]);
    for(int i=0; i<LEN; i++) {
        int n = (CAP-1)/ROOTS[i];
        sum += (int)(ROOTS[i] * (n/2.0) * (n+1));
    }
    n = (CAP-1) / (ROOTS[0]*ROOTS[1]);
    sum -= (int)((ROOTS[0]*ROOTS[1]) * (n/2.0) * (n+1));
    std::cout<< sum <<std::endl;

}