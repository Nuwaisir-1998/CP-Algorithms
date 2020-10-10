#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll Lower_bound(vector<ll> & v, ll target){
    ll n = v.size();
    ll left = 0, right = n - 1, mid;
    while(left <= right){
        mid = (left + right) / 2;
        if(v[mid] <= target){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return left;
}

int main()
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif // ONLINE_JUDGE
    vector<ll> v = {1,2,3,3,4,5};
    cout << Lower_bound(v, 3) << endl;

    return 0;
}