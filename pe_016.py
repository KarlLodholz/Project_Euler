"""
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
What is the sum of the digits of the number 2^1000?
"""

import math
temp = str("{:.0f}".format(math.pow(2,1000))) #removes scientific notation
sum = 0
for i in range(0,len(temp)):
    sum += int(temp[i])
print(sum)