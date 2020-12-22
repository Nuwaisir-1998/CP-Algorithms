1.
GCD(a, b) = GCD(a, |b - a|)
GCD(a, b, c) = GCD(GCD(a, b), c) = GCD(a, GCD(b, c))
It can be proven that,
GCD of an array = GCD(a(1), GCD(|a(1)-a(2)|, |a(2)-a(3)|, ..., |a(n-1)-a(n)|))
So, if we update all the elements of this array by x, the GCD of the array can be updated in O(1)
(Precalculate the gcd of the differences and then just replace a(1) with a(1) + x for each query)
Problem : https://codeforces.com/contest/1459/problem/C

2.
If there are some question marks in the array given and you need to replace them with some 
values from a range which is quite small (like [0, 1]), then see the effect on the result by
considering all possible replacements of two adjacent question marks. (like 01, 10). For example,
input: 0??1
try1 : 0011
try2 : 0101
Then calculate the effect and see whether you can come up with a solution. 
(A solution can be: try all possible 0-prefixed replacements e.g. 000...111)
Problem: https://codeforces.com/contest/1465/problem/D

