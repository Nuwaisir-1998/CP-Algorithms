//
// Created by nuwaisir on 11/26/19.
//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

class DSU{
public:
    vi rank, p;
    DSU(int n){
        rank.assign(n,0);
        p.assign(n,0);
        for(int i=0;i<n;i++) p[i] = i;
    }
    int findSet(int i){
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j){
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j){
        if(!isSameSet(i, j))
        {
            int x = findSet(i);
            int y = findSet(j);
            if(rank[x] > rank[y]){
                p[y] = x;
            }else{
                p[x] = y;
                if(rank[x] == rank[y]){
                    rank[y]++;
                }
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);

    return 0;
}
