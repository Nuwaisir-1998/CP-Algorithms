#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

class segmentTree{              // Segment tree for range minimum query
    vll st, A;                   // st is the array for binary tree. Index 1 is the root
    ll n;
    ll left(ll p){ return 2*p; }
    ll right(ll p){ return 2*p + 1; }

    void build(ll p, ll L, ll R){
        if(L == R){
            st[p] = L;
        }
        else{
            build(left(p), L,(L+R)/2);
            build(right(p),(L+R)/2+1, R);
            ll p1 = st[left(p)];
            ll p2 = st[right(p)];
            st[p] = (A[p1] <= A[p2]) ? p1 : p2;
        }
    }

    ll RMQ(ll p, ll L, ll R, ll i, ll j){
        if(L >= i && R <= j) return st[p];
        if(R < i || L > j)  return -1;
        ll p1 = RMQ(left(p), L, (L+R)/2, i, j);
        ll p2 = RMQ(right(p), (L+R)/2+1, R, i, j);
        if(p1 == -1) return p2;
        if(p2 == -1) return p1;
        return (A[p1] <= A[p2]) ? p1 : p2;
    }

    void update(ll p, ll L, ll R, ll i, ll val){
        if(L == R && L == i){
            A[L] = val;
            st[p] = L;
        }
        else if(i <= R && i >= L){
            update(left(p), L, (L+R)/2, i, val);
            update(right(p), (L+R)/2 + 1, R, i, val);
            ll p1 = st[left(p)];
            ll p2 = st[right(p)];
            st[p] = (A[p1] <= A[p2]) ? p1 : p2;
        }
    }
public:
    segmentTree(const vll _A){
        A = _A;
        n = A.size();
        st.assign(4*n, 0);
        build(1, 0, n-1);
    }
    ll RMQ(ll i, ll j){     // returns minimum value form i to j inclusive
        return RMQ(1, 0, n-1, i, j);
    }
    void update(ll i, ll val){
        update(1, 0, n-1, i, val);
    }
};


int main(){
    ios::sync_with_stdio(false);
    vll a = {1, 8, 5, -2, 2, 5, 9, 2, 6};
    segmentTree segmentTree(a);

    cout << a[segmentTree.RMQ(0, 5)] << "\n";
    segmentTree.update(1, -10);
    a[1] = -10;
    cout << a[segmentTree.RMQ(0, 5)] << "\n";
}
