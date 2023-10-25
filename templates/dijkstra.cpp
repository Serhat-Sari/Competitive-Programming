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

vector<vector<pair<int,int> > > adj;
vector<int> dist;

void addEdge( int u,int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}


int dijkstra(){ // Only works in non-negative edge weights. Use Bellman Ford if there is negative edge weights.

    int src,dest;
    cin >> src >> dest;

    priority_queue<pii, vector<pii>, greater<pii> > pq;

    pq.push(make_pair(0, src));

    dist[src] = 0;
    while(!pq.empty()){
        int u = pq.top().second; 
        pq.pop();
        for(auto i : adj[u]){
            int v = i.first;
            int w = i.second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v],v));
            }
        }
    }

}
	



int main(){

	vector< vector<pii> > adj;
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    dist.resize(n+1,1e9);

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        addEdge(x,y,z);
    }

   
    for(int i = 0; i<dist.size();i++)
        cout << dist[i] << " ";

    return 0;
}