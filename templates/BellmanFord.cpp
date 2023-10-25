#include <bits/stdc++.h>												
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

const int MOD = 1e9+7;
ll gcd(ll a, ll b) {if(b==0) return a; return gcd(b,a%b);}

#define fastAf cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);

#define cp int t;cin>>t;while(t--) {solve();}

#define loop(i,n) for(int i = 0; i<n;i++)

#define pb push_back

#define SORT(v) sort(v.begin(),v.end());

struct Edge {
    int src,dest,weight;
};

vector<int> dist;
int n,m,v;
vector<Edge> edges;
const int INF = 1e9;

void bellmanFord(){
    
    int src , dest;
    cin >> src >> dest;
    dist[src] = 0;
    for(int i = 0; i<n-1;i++){
        for(int j = 0; j<edges.size();j++){
            int u = edges[j].src;
            int v = edges[j].dest;
            ll w = edges[j].weight;
            if(dist[u] != INF){
                if(dist[v] > dist[u] + w)
                    dist[v] = dist[u] + w;
            }
        }
    }
    bool negCycle = false;
    for(int j =0 ; j < edges.size();j++){
        int u = edges[j].src;
        int v = edges[j].dest;
        ll w = edges[j].weight;
        if(dist[v] > dist[u] + w){
            negCycle = true;
            break;
        }
    }

    if(negCycle)
        cout << "Negative cycle exists!\n";
    else{
        for(int i = 0; i < n;i++){
            cout << i << "->" << dist[i] << '\n';
        }
    }
}
int main(){

    int n, m;
    cin >> n >> m;
    edges.resize(m);
    dist.resize(n,INF);

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        edges[i].src = x, edges[i].dest = y, edges[i].weight = z;
    }

   
    for(int i = 0; i<dist.size();i++)
        cout << dist[i] << " ";

    return 0;
}