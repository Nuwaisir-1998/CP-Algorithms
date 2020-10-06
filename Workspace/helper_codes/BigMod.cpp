//
// Created by nuwaisir on 11/25/19.
//

#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll bigmod ( ll a, ll p, ll m )
{
    ll res = 1;
    ll x = a;
    while (p)
    {
        if (p & 1) //p is odd
        {
            res = (res * x) % m;
        }
        x = (x * x) % m;
        p = p >> 1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cout << bigmod(1625, 10005841, 1000000007) << "\n";
    return 0;
}

