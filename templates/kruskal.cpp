#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int par[N], sz[N];

int find(int x) {
    return (x == par[x] ? x : par[x] = find(par[x]));
}

void combine(int u, int v) {
    u = find(u), v = find(v); // İki node'un da parentlarını bul
    if (u == v)
        return; // Her iki node da aynı sette ise devam et.
    if (sz[u] < sz[v])
        swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
}

int main(){

    int n;
    cin >> n;
    vector<pair<int,pair<int,int> > >  adj(n+1);
    for(int i = 1; i<n+1;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj.push_back({w,{u,v}});
    }
    vector<pair<int,pair<int,int> > > results;
    int cost = 0;
    for(int i = 1; i<n+1;i++){
        par[i] = i; sz[i] = 1;
    }
    sort(adj.begin(),adj.end());

    for(auto it : adj){
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if(find(u) != find(v)){
            cost += wt;
            combine(u,v);
            results.push_back({wt,{u,v}});
        }
    }
    

    return 0;
}