#include <iostream>
#include <vector>
#include "timer.h"

/*/
Surprisingly there are only three numbers that can be written as the sum of 
fourth powers of their digits:
    1634 = 1^4 + 6^4 + 3^4 + 4^4
    8208 = 8^4 + 2^4 + 0^4 + 8^4
    9474 = 9^4 + 4^4 + 7^4 + 4^4
As 1 = 14 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers
of their digits.
/*/

int main() {
    long sum = 0;
    //attempt1 
    {
        Timer t;
        //this is faster than math.pow
        std::vector<int> pwrs(10);
        for(int i=0;i<10;i++) {
            pwrs[i]=i;
            for(int j=0; j<4; j++) pwrs[i] *= i;
        }
        //355000 is upperbound because 6*9^5 = 355000
        for (int i=2; i<355000; i++) {
            int sump = 0;
            int n = i;
            while(n>0){
                sump += pwrs[n%10];
                n /= 10;
            }
            if(sump == i) sum += i;
        }
    }
    std::cout<<sum<<std::endl;
    return 0;
}