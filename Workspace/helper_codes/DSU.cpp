//
// Created by nuwaisir on 11/26/19.
//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

class DSU{
    int numSets;
    vi rank, p, setSize;
public:
    DSU(int n){
        setSize.assign(n, 1);
        rank.assign(n,0);
        p.assign(n,0);
        for(int i=0;i<n;i++) p[i] = i;
        numSets = n;
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
            numSets--;
            int x = findSet(i);
            int y = findSet(j);
            if(rank[x] > rank[y]){
                p[y] = x;
                setSize[x] += setSize[y];
            }else{
                p[x] = y;
                if(rank[x] == rank[y]){
                    rank[y]++;
                }
                setSize[y] += setSize[x];
            }
        }
    }

    int numDisjointSets(){
        return numSets;
    }

    int sizeOfSet(int i){
        return setSize[findSet(i)];
    }
};

int main() {
    ios::sync_with_stdio(false);
    DSU dsu(10);
    dsu.unionSet(2,1);
    //dsu.unionSet(1,3);
    dsu.unionSet(1,4);
    cout << dsu.findSet(3) << "\n";
    cout << dsu.numDisjointSets() << "\n";
    cout << dsu.sizeOfSet(4) << "\n";
    return 0;
}
