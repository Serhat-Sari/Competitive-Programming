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

    int n;
    cin >> n;
    vector<int> numeros(n);
    for(int i = 0; i < n ; i++){
        int x; cin >> x;
        numeros[i] = x;
    }
    SORT(numeros);
    ll ans = LLONG_MAX;
    int maxi = numeros[n-1];
    int mini = numeros[0];
    for(int i = mini; i <= maxi;i++){
        ll temp = 0;
        for(int j = 0; j<n;j++){
            temp += (numeros[j]-i)*(numeros[j]-i);
        }
        ans = min(temp,ans);
    }
    cout << ans;


}
        
    

    


int main(){

    fastAf
    solve();

    return 0;
}

