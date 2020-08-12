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

    for(int i=0; i<2; i++) {
        num = 0;
        while(num < CAP) {
            if (!(i && !(num%ROOTS[0]))) //checks is multiple has already been counted
                sum += num;
            num += ROOTS[i];
        }
    }

    std::cout<< sum <<std::endl;
}