#ifndef STR_MATH_H
#define STR_MATH_H
#include <vector>
#include <string>

std::string str_multiply(const std::string &num1,const std::string &num2) { 
    std::string s = "";
    int len1 = num1.size(), len2 = num2.size(); 
    if (len1 == 0 || len2 == 0) 
        return "0"; 
  
    std::vector<int> result(len1 + len2, 0); 
  
    // Indexes for result   
    int i_n1 = 0;  
    int i_n2 = 0;  
      
    // Go from right to left in num1 
    for (int i=len1-1; i>=0; i--) { 
        int carry = 0; 
        int n1 = num1[i] - '0'; 
  
        // To shift position to left after every multiplication of a digit in num2 
        i_n2 = 0;  
          
        // Go from right to left in num2              
        for (int j=len2-1; j>=0; j--) { 
            // Take current digit of second number 
            int n2 = num2[j] - '0'; 
  
            // Multiply with current digit of first number and add result to previously stored result at current position.  
            int sum = n1*n2 + result[i_n1 + i_n2] + carry; 
  
            // Carry for next iteration 
            carry = sum/10; 
  
            // Store result 
            result[i_n1 + i_n2] = sum % 10; 
  
            i_n2++; 
        } 
  
        // store carry in next cell 
        if (carry > 0) 
            result[i_n1 + i_n2] += carry; 
  
        // To shift position to left after every multiplication of a digit in num1. 
        i_n1++; 
    } 
  
    // ignore '0's from the right 
    int i = result.size() - 1; 
    while (i>=0 && result[i] == 0) --i; 
  
    // If all were '0's - means either both or one of num1 or num2 were '0' 
    if (i == -1) s = "0";  

    while (i >= 0) 
        s += std::to_string(result[i--]); 
  
    return s; 
} 

std::string str_divide(const std::string &n, const std::string &div) { 
    // As result can be very large store it in string 
    std::string ans; 
    if(std::stoll(div)) {
        // Find prefix of number that is larger than divisor. 
        long long idx = 0; 
        long long temp = n[idx] - '0'; 
        while (temp < std::stoll(div)) 
            temp = temp * 10 + (n[++idx] - '0'); 
    
        // Repeatedly divide divisor with temp. After every division, update temp to include one more digit. 
        while (n.size() > idx) { 
            // Store result in answer i.e. temp / divisor 
            ans += (temp / std::stoll(div)) + '0'; 
            // Take next digit of number 
            temp = (temp % std::stoll(div)) * 10 + n[++idx] - '0'; 
        } 
        // If divisor is greater than number 
        if (ans.length() == 0) ans = "0"; 
    }
    else ans = "error(div == 0)";
    return ans; 
} 


#endif