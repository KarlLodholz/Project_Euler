#include <iostream>
#include "timer.h"

/*/
The following iterative sequence is defined for the set of positive integers:
n → n/2 (n is even)
n → 3n + 1 (n is odd)
Using the rule above and starting with 13, we generate the following sequence:
13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
Which starting number, under one million, produces the longest chain?
NOTE: Once the chain starts the terms are allowed to go above one million.
/*/

int collatz(const unsigned long long &n, int &itr) {
    //std::cout<<n<<std::endl;
    return n == 1 ? itr : collatz( (n%2 ? 3*n+1 : n/2) , ++itr); 
}

int main() {
    const int CAP = 1000000;
    int itr, temp = 0;
    int max = 0;
    //attempt1 
    {
        Timer t;
        for(int i = CAP-1; i >= 1; i--) {
            itr = 1;
            if (collatz(i,itr) > temp) { 
                temp = itr;
                max = i;
            } 
        }
    }
    std::cout<<max<<std::endl;
    return 0;
}