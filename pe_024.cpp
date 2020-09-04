#include <iostream>
#include <vector>
#include "timer.h"

/*/
A permutation is an ordered arrangement of objects. For example, 3124 is one
possible permutation of the digits 1, 2, 3 and 4. If all of the permutations 
are listed numerically or alphabetically, we call it lexicographic order. The
lexicographic permutations of 0, 1 and 2 are:
012   021   102   120   201   210
What is the millionth lexicographic permutation of the digits:
0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
/*/

int main() {
    long n = 1000000;
    n -= 1;
    const short DIGITS = 10;
    //first 10 permutations of nPn, letting n be 1-10
    const std::vector<long> PERM = {1,2,6,24,120,720,5040,40320,362880,3628800};
    std::vector<short> p(DIGITS);
    for(int i=0; i<DIGITS; i++) p[i] = i; 
    std::string prm = "";

    //attempt1 
    {
        int i = 0;
        Timer t;  
        while(n) {
            prm += char(p[n/PERM[DIGITS-i-2]]+48);
            for(int j=n/PERM[DIGITS-i-2]; j<DIGITS-1; j++) std::swap(p[j],p[j+1]);
            p.pop_back();
            n %= PERM[DIGITS-i-2];
            i++;
        }
        for (int j=0; j<DIGITS-i; j++) prm += char(p[j]+48);
    }
    std::cout<<prm<<std::endl;
    return 0;
}