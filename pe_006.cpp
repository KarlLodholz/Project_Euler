#include <iostream>
#include "timer.h"

/*/
Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
/*/

int main() {
    long long int sum = 0;
    const int n = 100;
    //attempt1 
    {
        Timer t;
        sum = (n*(n+1)/2)*(n*(n+1)/2) - (n*(n+1)*(2*n+1)/6);
    }
    std::cout<<sum<<std::endl;
    return 0;
}