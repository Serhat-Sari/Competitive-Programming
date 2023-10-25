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

struct edge {

    int u,v,w;
    bool operator<(edge const& other){
        return w < other.w;
    }
};

int main(){

    int n;
    cin >> n;
    vector<edge> edges(n+1);
    for(int i = 1; i<n+1;i++){
        int u,v,w;
        cin >> u >> v >> w;
        edges[i].u = u, edges[i].v = v, edges[i].w = w;
    }
    vector<edge> results;
    int cost = 0;
    for(int i = 1; i<n+1;i++){
        par[i] = i; sz[i] = 1;
    }
    sort(edges.begin(),edges.end());

    for(edge e: edges){
        if(find(e.u) != find(e.v)){
            cost += e.w;
            results.push_back(e);
            combine(e.u,e.v);
        }
    }
    

    return 0;
}