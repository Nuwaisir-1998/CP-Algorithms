//
// Created by nuwaisir on 11/28/19.
//

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

/********************************************/

//    Code from cp-algorithms.com/data_structures/fenwick.html

/********************************************/

struct FenwickTree {
    vector<ll> bit;  // binary indexed tree
    ll n;

    FenwickTree(ll n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<ll> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    ll sum(ll r) {
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    ll sum(ll l, ll r) {
        return sum(r) - sum(l - 1);
    }

    void add(ll idx, ll delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int main(){
    ios::sync_with_stdio(false);
    vll f = {2,4,5,5,6,6,6,7,7,8,9};
    FenwickTree ft(f);
    cout << ft.sum(4, 6) << "\n"; // 0-indexed
    return 0;
}