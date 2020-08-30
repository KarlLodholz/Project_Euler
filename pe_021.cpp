#include <iostream>
#include "timer.h"

/*/
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.
For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
Evaluate the sum of all the amicable numbers under 10000.
/*/

int sum_prop_div(const int &n) {
    int sum = 1;
    for(int i=2; i*i<=n; i++)
        if(n%i==0) sum += i + (i*i==n? 0 : n/i);  
    return sum;
}

int main() {
    const int CAP = 10000;
    int sum = 0;

    //attempt1 
    {
        Timer t;
        //starting at 2 because 1 is the only number with only itself as its factors
        for(int i = 2; i<CAP; i++)
            if(i == sum_prop_div(sum_prop_div(i)) && sum_prop_div(i) != i) 
                sum += i;
        
    }
    std::cout<<sum<<std::endl;
    return 0;
}