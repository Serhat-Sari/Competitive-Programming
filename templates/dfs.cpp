#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

vector< vector<int> > adj;
vector<bool> visited;

void addEdge(int a, int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
}

void dfs(int n){
    visited[n] = 1;
    cout << n << '\n';

    for(auto it : adj[n]){
        if(!visited[it])
            dfs(it);
    }

}

int main() {
    int n;
    cin >> n;
    adj.resize(n + 1, vector<int>());
    visited.resize(n + 1,false);

    for(int i=0; i<n-1; i++) {
        int a,b;
        cin >> a >> b;
        addEdge(a,b);
    }
    dfs(1);

    
    return 0;
}