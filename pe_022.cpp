#include <iostream>
#include "timer.h"
#include <vector>
#include <bits/stdc++.h> 

/*/
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.
For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.
What is the total of all the name scores in the file?
/*/

int main() {

    long sum;
    std::vector<std::string> names;
    std::string nm;
    while(std::getline(std::cin, nm, '\"'))
        if(nm[0] != ',') names.push_back(nm);
    
    //attempt1 
    {   
        sum = 0;
        int temp;
        Timer t;
        sort(names.begin(), names.end());
        for(int i=0; i<names.size(); i++) {
            temp = 0;
            for(int j=0; j<names[i].size(); j++)
                temp += names[i][j] - 64;
            sum += temp*i;
        }
    }
    std::cout<<sum<<std::endl;
    return 0;
}
//Mei Terumi

//AE3803
//mayoi hachikuji