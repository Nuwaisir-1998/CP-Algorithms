# 1.
GCD(a, b) = GCD(a, |b - a|)
GCD(a, b, c) = GCD(GCD(a, b), c) = GCD(a, GCD(b, c))
It can be proved that,
GCD of an array a = GCD(a(1), GCD(|a(1)-a(2)|, |a(2)-a(3)|, ..., |a(n-1)-a(n)|))
So, if we update all the elements of this array by x, the GCD of the array can be updated in O(1)
(Precalculate the gcd of the differences and then just replace a(1) with a(1) + x for each query)
Problem : https://codeforces.com/contest/1459/problem/C

# 2.
Maybe you need to use MOD in possibly every mathematical operation when you need an answer modulo MOD.
Example: https://codeforces.com/gym/101192/problem/H

