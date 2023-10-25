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
int n;
vector<bool> vis;

void addEdge( int u,int v, int wt)
{
    adj[u].pb(make_pair(v, wt));
    adj[v].pb(make_pair(u, wt));
}


int  prim(){ // only works in connected graphs.

    priority_queue<pii, vector<pii>, greater<pii> > pq;
    vector<vector<pii> > mst;
    pq.push({0,0});
    int ans = 0;

    while(!pq.empty()){

        int currVertex = pq.top().second;
        int currWeight = pq.top().first;

        pq.pop();
        
        
        if(vis[currVertex]) continue;

        vis[currVertex] = true;
        ans += currWeight;
        for(auto it: adj[currVertex]){
            int neighborVertex = it.first;
            int neighborWeight = it.second;

            if(!vis[neighborVertex])
                pq.push({neighborWeight,neighborVertex});
        
        }

    }

    return ans;
}



int main(){

	
    int n, m;
    cin >> n >> m;

    adj.resize(n );
    vis.resize(n,false);

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        addEdge(x,y,z);
    }
    int ans = prim();
    cout << ans;
    return 0;
}