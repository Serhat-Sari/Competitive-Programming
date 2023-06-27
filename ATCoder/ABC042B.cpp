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


void solve(){

    int n,size; cin >> n >> size;
    vector<string> arr(n);
    for(int i = 0; i<n;i++){string s;cin>>s; arr[i] = s;}
    SORT(arr);      
    string ans = "";
    for(int i = 0; i<n;i++){ans += arr[i];}
    cout << ans;
}
        
    

    


int main(){

    fastAf
    solve();

    return 0;
}

