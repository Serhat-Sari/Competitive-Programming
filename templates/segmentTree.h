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

struct segtree{

    int size;
    vector<int> tree;

    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        tree.resize(2 * size);
    }

    void build(vector<int> &arr , int x,  int lx, int rx){
        if(rx-lx == 1){
            if(lx < (int)arr.size())
                tree[x] = arr[lx]; // Can change here.
            return;
        }
        int m = (lx+rx)/2;
        build(arr,2*x+1,lx,m);
        build(arr,2*x+2,m,rx);
        
        tree[x] = tree[2*x+1] + tree[2*x+2]; // Change here.
    }

    void build(vector<int> &arr){
        build(arr,0,0,size);
    }

    void update(int i , int v, int x, int lx, int rx){
        if(rx - lx == 1){
            tree[x] = v; // Might change here
            return;
        }
        int mid = (lx+rx)/2;

        if(i < mid)
            update(i, v ,2 * x + 1, lx, mid);
        
        else
            update(i, v, 2 * x + 2, mid, rx);

        tree[x] = tree[2 * x + 1] + tree[2 * x+ 2]; // Change here
    }

    void update(int i , int v){
        update(i, v, 0, 0, size);
    }

    int calc(int l, int r,int x, int lx, int rx){

        if( lx >= r || l >= rx ) return 0; // Change here , Etkisiz eleman olmalı.

        if( lx >= l && rx <= r)
            return tree[x];

        int mid = (lx+rx)/2;
        int s1 = calc(l,r,2*x+1,lx,mid);
        int s2 = calc(l,r,2*x+2,mid,rx);

        return s1 + s2; // Change here
    }

    int calc(int l, int r){
        return calc(l,r,0,0,size);
    }
};








void solve(){

int n,m;
cin >> n >> m;
vector<int> arr(n);
segtree seg;
seg.init(n);

for(int i = 0; i<n; i++){
    cin >> arr[i];
}

seg.build(arr);

while(m--){
    int op,a,b;
    cin >> op >> a >> b;

    if(op == 1)
        seg.update(a,b);
    
    else{
        auto res = seg.calc(a,b);
        cout << res.m << " " << res.c << '\n';
    }
}




}
int main(){

	fastAf
	solve();
	return 0;
}