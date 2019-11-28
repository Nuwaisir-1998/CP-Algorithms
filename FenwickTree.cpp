//
// Created by nuwaisir on 11/28/19.
//

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

class FenwickTree {
    vi ft, A;
    int n;
public:
    int LSOne(int x) {
        return (x & (-x));
    }

    int rsq(int b) {
        int sum = 0;
        for (; b; b -= LSOne(b)) {
            sum += ft[b];
        }
        return sum;
    }

    int rsq(int a, int b) {
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
    }

    void adjust(int idx, int val) {
        for (; idx < (int) ft.size(); idx += LSOne(idx)) {
            ft[idx] += val;
        }
    }

    FenwickTree(vi _A) {
        A = _A;
        n = A.size();
        ft.assign(n + 1, 0);
        ft.push_back(0);
        for (int i = 1; i < n + 1; i++) {
            adjust(i, A[i-1]);
        }
    }

//    FenwickTree(int n) : n(n) {
//        ft.assign(n+1, 0);
//    }
};

int main(){
    ios::sync_with_stdio(false);
    vi f = {2,4,5,5,6,6,6,7,7,8,9};
    FenwickTree ft(f);
    cout << ft.rsq(4, 6) << "\n"; // 1-indexed
    return 0;
}