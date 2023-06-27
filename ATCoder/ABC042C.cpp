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

map<int,int> numeros;

bool check(int n){

    while(n){
        int temp = n%10;
        if(numeros[temp] == 1){return false;}
        n /= 10;
    }
    
}

void solve(){


    int amount,m;cin>>amount>>m;
    while(m--){
        int x;cin>>x;
        numeros[x]++;
    }
    while(true){
        if(check(amount)){
            cout << amount;
            return;
        }
        amount++;
    }

  

}
        
    

    


int main(){

    fastAf
    solve();

    return 0;
}

