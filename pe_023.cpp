#include <iostream>
#include <vector>
#include "timer.h"

/*/
A perfect number is a number for which the sum of its proper divisors is exactly equal 
to the number. For example, the sum of the proper divisors of 28 would be
1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it
is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number 
that can be written as the sum of two abundant numbers is 24. By mathematical 
analysis, it can be shown that all integers greater than 28123 can be written as the 
sum of two abundant numbers. However, this upper limit cannot be reduced any further 
by analysis even though it is known that the greatest number that cannot be expressed 
as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two 
abundant numbers.

------------ my notes -------------
abundant numbers only appear to be even numbers prior to 945
after 945 multiples some multiples of 5

/*/

bool perfect_number(const int &n) {
    int sum = 1, i = 2; //sum starts at 1 because every number is divisible by 1
    do {
        if(n%i == 0) 
            sum += i + (i*i == n ? 0:n/i);    
    } while(++i*i <= n);

    if(n == sum)std::cout<<n<<" : "<<sum<<std::endl;
    return n == sum;
}

bool abundant_number(const int &n) {
    int sum = 1, i = 1; //sum starts at 1 because every number is divisible by 1
    while(++i*i <= n) {
        if(n%i == 0) 
            sum += i + (i*i == n ? 0:n/i);    
    }

    return n < sum;
}


int main() {
    const int CAP = 28123;
    unsigned long long sum;
    std::vector<int> abt;
    //attempt1 
    {
        sum = 0;
        Timer t;  
        for(int i=1; i<=CAP; i++)
            if(abundant_number(i)) abt.push_back(i);

        std::vector<bool> tb(CAP+1,true);  //this is to used to keep track of the integers
        for(int i=0; i<abt.size(); i++) {
            for(int j=0; j<abt.size(); j++) {
                if(abt[i]+abt[j] > CAP) break;
                    tb[abt[i]+abt[j]] = false;
            }
        }
        for(int i=1; i<tb.size(); i++)
            if(tb[i]) sum += i;
    }
    std::cout<<sum<<std::endl;
    return 0;
}