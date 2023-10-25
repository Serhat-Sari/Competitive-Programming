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

vector< vector<int> > adj;
vector<bool> visited;
stack<int> topsort;

void topological_sort(int node){
    visited[node] = true;
    for(int i = 0 ; i<adj[node].size();i++){
        if(visited[adj[node][i]] == true)
            continue;
        topological_sort(adj[node][i]);
    }
    topsort.push(node);
}

/*void dfs(int node){

    visited[node] = true;
    for(int i = 0; i<adj[node].size();i++){
        if(visited[adj[node][i]] = true)
            continue;
        dfs(adj[node][i]);
    }
   
}
*/
int main(){
    int n; // number of vertices
    cin >> n;
    visited.resize(n,false); // 0 based
	adj.resize(n); // 0 based; 
    int m;// number of edges
    cin >> m;
    for(int i = 0; i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b); // its directed.
    }
    for(int i = 0; i<n;i++){
        if(!visited[i])
            topological_sort(i);
    }
    while(!topsort.empty()){
        int x = topsort.top();
        topsort.pop();
        cout << x << " ";
    }
}

