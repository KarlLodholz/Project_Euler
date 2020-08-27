#include <iostream>
#include "timer.h"

/*/
If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
/*/

int main() {
    int sum;
    //attempt1 
    {
        Timer t;
        const int num0[20] = {0,3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8};
        const int num1[10] = {0,0,6,6,5,5,5,7,6,6};
        const int num2 = 10; //hundred and
        sum = 11; //one thousand
        for(int i = 0; i<10; i++)
            for(int j=0; j<10; j++)
                for(int k=0; k<10;k++)
                    sum += bool(i)*num2+num0[i] - (i && (j+k==0) ? 3 : 0)  +  ((j-1)? (num1[j] + num0[k]) : num0[10+k]);
    }
    std::cout<<sum<<std::endl;
    return 0;
}