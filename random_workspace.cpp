//
// Created by nuwaisir on ৬/১১/১৯.
//

#include<bits/stdc++.h>

using namespace std;
#define ll long long

#define MOD 1000000007

long long bigmod ( long long a, long long p, long long m )
{
    long long res = 1;
    long long x = a;

    while ( p )
    {
        if ( p & 1 ) //p is odd
        {
            res = ( res * x ) % m;
        }
        x = ( x * x ) % m;
        p = p >> 1;
    }

    return res;
}

ll sumn(ll x){
    ll sum = 0;
    while(x){
        sum ++;
        x /= 10;
    }
    return sum;
}

int main(){
    ios_base :: sync_with_stdio(false); //cin.tie(nullptr); cout.tie(nullptr);
    ll n, i, mid = 0, j, cost, l, x, y, a, b;
    string s;
    cin >> a >> b >> x;
    ll left = 1, right = 1000000000;
    int cnt = 0;
    if(a + b > x){
        cout << 0 << "\n";
        return 0;
    }
    while(left < right){
        mid = ((left + right) / 2);
        if(right - left == 1){
            if(a*right + b*sumn(right) <= x){
                mid = right;
                break;
            }else if(a*left + b*sumn(left) <= x){
                mid = left;
                break;
            }else{
                mid = 0;
                break;
            }
        }
        if(a*mid + b*sumn(mid) < x) {
            left = mid;
        }else if(a*mid + b*sumn(mid) > x) {
            right = mid-1;
        }else{

        }
    }

    cout << mid << "\n";

    return 0;
}
