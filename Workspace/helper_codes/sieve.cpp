//
// Created by Nuwaisir on 06/11/2019.
//

/*
 *
 * Algorithm : Sieve of Eratosthenes
 * Description : The algorithm can generate prime numbers upto some number in lesser amount of time than naive approach
 * Runtime : O(n log log n) ; [ Roughly ]
 *
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

#define MX 1000001
vector<ll> primes;
bitset<MX> isNotPrime;                       // Compact STL for Sieve, better than vector<bool> !!

void sieve(ll n) {                           // Generate primes upto n
    ll i, j;
    isNotPrime[1] = true;
    for (i = 4; i <= n; i += 2) {
        isNotPrime[i] = true;
    }
    primes.push_back(2);
    for (i = 3; i <= n; i += 2) {
        if (!isNotPrime[i]) {
            primes.push_back(i);
            if (i * i <= n) {
                for (j = i * i; j <= n; j += i + i) {         // From j = i * i. Because i * 2, i * 3, ... are already
                                                              // crossed out by 2, 3 respectively
                    isNotPrime[j] = true;
                }
            }
        }
    }
}

bool isPrime(ll x) {
    int i;
    if (x < MX) return !isNotPrime[x];
    for (i = 0; i < (int) primes.size(); i++) {
        if (x % primes[i] == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    sieve(1000000);
    cout << isPrime(2147483647) << "\n";
    cout << isPrime(136117223863LL) << "\n";
    return 0;
}

