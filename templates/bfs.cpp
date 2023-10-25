#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector< vector<int> > adj;
vector<bool> visited;
queue<int> q;

void addEdge(int a, int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
}


void bfs(int x){

        q.push(x);
        visited[x] = true;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            for(auto it : adj[curr]){
                if(!visited[it]){
                    q.push(it);
                    visited[it] = true;
                }
            }
    }    
}    
        



int main(){

    int n,a,b;
    cin >> n;
    adj.resize(n+1,vector<int>());
    visited.resize(n+1,false);
    
    for(int i = 0 ; i<n-1; i++){
        cin >> a >> b;
        addEdge(a,b);
    }
    bfs(1);

    return 0;
}