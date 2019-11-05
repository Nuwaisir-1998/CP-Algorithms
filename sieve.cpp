//
// Created by Nuwaisir on 06/11/2019.
//
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MX 10000010

vector<ll> primes;
bitset<MX> isNotPrime;

void sieve(ll n) {
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
                for (j = i * i; j <= n; j += i + i) {
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
    sieve(10000000);
    cout << isPrime(2147483647) << "\n";
    cout << isPrime(136117223863LL) << "\n";
    return 0;
}

