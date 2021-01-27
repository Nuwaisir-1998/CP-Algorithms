#include <bits/stdc++.h>
using namespace std;
string b(int n){
    string s;
    while(n){
        if(n%2)s.push_back('1');
        else s.push_back('0');
        n /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif // ONLINE_JUDGE
    string s;
    getline(cin, s);
    int mx = 0;
    vector<string> v;
    for(auto e : s){
        v.push_back(b((int)e));
        mx = max(mx, (int)b((int)e).size());
    }
    cout << mx << endl;
    for(int i=0;i<mx;i++){
        for(int j=0;j<v.size();j++){
            if(i < v[j].size()) cout << v[j][i];
            else cout << " ";
        }
        cout << endl;
    }
    

}