#include <iostream>
#include "timer.h"

/*/
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
/*/

int gcd(int a, int b) {return (a ? gcd(b % a, a) : b);}
int lcd(int a, int b) {return (a*b / gcd(a,b));}

int main() {
    int num = 2520, max = 20;

    //attempt1
    {
        Timer t;
        for(int i=11; i<20; i++) 
            num = lcd(num,i);
    }
    std::cout<<num<<std::endl;
    return 0;
}