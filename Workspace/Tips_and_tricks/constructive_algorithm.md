# 1.
If there are some question marks in the array given and you need to replace them with some 
values from a range which is quite small (like [0, 1]), then see the effect on the result by
considering all possible replacements of two adjacent question marks. (like 01, 10). For example,
input: 0??1
try1 : 0011
try2 : 0101
Then calculate the effect and see whether you can come up with a solution. 
(A solution can be: try all possible 0-prefixed replacements e.g. 000...111)
Problem: https://codeforces.com/contest/1465/problem/D

# 2.
When you are asked to count the number of substrings or something like that by maybe replacing some of the elements, but they don't want the changed substring (they just want the count), then consider replacing with a not a certain element (maybe '?'), if you are sure that there exists some element
which will satisfie the requirements.
Problem: https://codeforces.com/contest/1466/problem/C

# 3. (probably true)
When dealing with a sliding window, and replacing and element of that window, if the size of that
sliding window is very small, (maybe 2-3), then you try all possible replacements and just see how does that effect the other sliding windows that contain the replaced element. So, maybe you can choose an element greedily in this case. Not sure whether it will work on all cases.
Problem: https://codeforces.com/contest/1466/problem/C

# 4.
XORing the rows and columns of a binary matrix in any sequence results in the same matrix. The order
of operation doesn't matter. And there is no need to do one operation (XOR a row/col) more than
once.
Problem: https://codeforces.com/contest/1475/problem/F
