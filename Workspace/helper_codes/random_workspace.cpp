//
// Created by nuwaisir on 11/26/19.
//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

class segmentTree{              // Segment tree for range minimum query
    vi st, A;                   // st is the array for binary tree. Index 1 is the root
    int n;
    bool flag;
    int left(int p){ return 2*p; }
    int right(int p){ return 2*p + 1; }

    void build(int p, int L, int R, bool flag){
        if(L == R){
            st[p] = A[L];
        }
        else{
            build(left(p), L,(L+R)/2, !flag);
            build(right(p),(L+R)/2+1, R, !flag);
            int p1 = st[left(p)];
            int p2 = st[right(p)];
            st[p] = flag ? (p1 | p2) : (p1 ^ p2);
        }
    }



    void update(int p, int L, int R, int i, int val, bool flag){
        if(L == R && L == i){
            A[L] = val;
            st[p] = val;
        }
        else if(i <= R && i >= L){
            update(left(p), L, (L+R)/2, i, val, !flag);
            update(right(p), (L+R)/2 + 1, R, i, val, !flag);
            int p1 = st[left(p)];
            int p2 = st[right(p)];
            st[p] = flag ? (p1 | p2) : (p1 ^ p2);
        }
    }
public:
    segmentTree(const vi _A, bool flag_){
        A = _A;
        n = A.size();
        st.assign(4*n, 0);
        build(1, 0, n-1, flag_);
    }

    void update(int i, int val, bool flag_){
        update(1, 0, n-1, i, val, flag_);
    }

    int atSt(int i){
        return st[i];
    }

    void setFlag(bool f){
        flag = f;
    }
};

int POW(int x, int y){
    int ans = 1;
    for(int i=0;i<y;i++){
        ans = ans * x;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    int n, i, j ,k;
    cin >> n >> k;
    bool flag = n % 2 == 0;
    n = POW(2, n);
    vector<int> a(n);
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    int idx, val;
    segmentTree st(a, !flag);
    while(k--)
    {
        cin >> idx >> val;
        a[idx-1] = val;
        st.update(idx-1, val, !flag);
        cout << st.atSt(1) << "\n";
    }
    return 0;
}