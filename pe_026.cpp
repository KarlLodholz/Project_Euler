#include <iostream>
#include <vector>
#include "timer.h"

/*/
/*/

int main() {
    int num = 0;    
    //attempt1 
    {
        Timer t;
        int len = 0;
        int val;
        int pos;
        for (int i=1000; i>1; i--) {
            if (len >= i) break;
            std::vector<int> rem(i);
            val = 1;
            pos = 0;
            while (rem[val] == 0 && val != 0) {
                rem[val] = pos;
                val *= 10;
                val %= i;
                pos++;
            }
        
            if (pos - rem[val] > len) {
                num = i;
                len = pos - rem[val];
            }
        }
    }
    std::cout<<num<<std::endl;
    return 0;
}
