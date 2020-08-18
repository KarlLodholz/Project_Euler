#include <iostream>
#include "timer.h"

/*/
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a^2 + b^2 = c^2
For example, 32 + 42 = 9 + 16 = 25 = 52.
There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
/*/

int main() {
    int a=0,b=0;
    unsigned long pro;
    //attempt1 
    {
        // from the equation a+b+c=1000 and a^2+b^2=c^2 I ended up with: 
        // a = 1000(500-y) / (1000-y)
        Timer t;
        for(int i = 1; i < 500; i++) {
            if (1000*(500 - i) % (1000 - i) == 0)
                if (!b) b = (1000*(500 - i) / (1000 - i));
                else a = (1000*(500 - i) / (1000 - i));
        }
        pro = ((1000-a-b)*a*b);   
    }
    std::cout<<pro<<std::endl;
    return 0;
}