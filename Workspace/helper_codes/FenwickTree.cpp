//
// Created by nuwaisir on 11/28/19.
//

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

/********************************************/

//    Code frome cp-algorithms.com/data_structures/fenwick.html

/********************************************/

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int main(){
    ios::sync_with_stdio(false);
    vi f = {2,4,5,5,6,6,6,7,7,8,9};
    FenwickTree ft(f);
    cout << ft.sum(4, 6) << "\n"; // 1-indexed
    return 0;
}