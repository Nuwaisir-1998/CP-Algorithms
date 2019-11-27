#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;

vi rank_, p, l, _p;
vi ansp;
vpii v;

void init(int n)
{
    rank_.assign(n, 0);
    p.assign(n, 0);
    _p.assign(n, 0);
    l.assign(n, 0);
    for(int i=0;i<n;i++){
        p[i] = i;
        _p[i] = i;
        l[i] = i;
    }
}

int findSet(int i){
    return (p[i] == i) ? i : findSet(p[i]);
}

int findLeaf(int i){
    return l[findSet(i)];
}

bool isSameSet(int i, int j){
    return findSet(i) == findSet(j);
}

void union_(int i, int j){
    if(!isSameSet(i, j)){

        int x = findSet(i);
        int y = findSet(j);
        if(rank_[x] < rank_[y]){
            p[x] = y;
            _p[x] = l[y];
            l[y] = l[x];
        }else{
            p[y] = x;
            _p[y] = l[x];
            l[x] = l[y];
            if(rank_[x] == rank_[y]){
                rank_[x]++;
            }
        }
    }
}

void solve(){
    int n, k, i, j, x, y;
    cin >> n;
    vector<int> f(n+1);
    vector<int> g(n+1, 1);
    vector<int> h;

    for(i=1;i<=n;i++){
        cin >> f[i];
        if(f[i] == i){
            h.push_back(f[i]);
            g[h[h.size() - 1]] = h.size();
        }
    }
    if(h.empty()){
        cout << -1;
        return;
    }

    cout << h.size() << "\n";
    for(i=1;i<=n;i++){
        cout << g[i] << " ";
    }
    cout << "\n";
    for(i=0;i<(int)h.size();i++){
        cout << h[i] << " ";
    }



}

int main(){
    ios::sync_with_stdio(false);
    ll n, t, m, a, b, k;
    cin >> t;
    while(t--) {
        cin >> a >> b >> k;
        ll g = __gcd(a, b);
        if(a == b) {
            cout << "OBEY\n";
            continue;
        }
        ll mx = max(a, b);
        ll mn = min(a, b);
        ll c1, c2;

        c1 = (mx - g) / mn;
        if((mx - g) % mn != 0) c1++;


        if(c1 >= k){
            cout << "REBEL\n";
        }else cout << "OBEY\n";


    }
    //solve();
    return 0;
}