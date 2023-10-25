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

#define pb push_back

#define SORT(v) sort(v.begin(),v.end());

vector<bool> isPrimeArray;
vector<int> allDivisors;

bool find_if_number_prime(int n){ // O(N) = sqrt(n)
	for(int i = 2 ; i*i < n; i++){
		if(!(n%i))
			return false;
	}
	return true;
}


void sieve(int n){ // O(N)  == nloglogn
	
	isPrimeArray[0] = false, isPrimeArray[1] = false;
	
	for(int i = 2 ; i * i  < n; i++){
		if(isPrimeArray[i]){
			for(int j = i*2; j<n; j += i)
				isPrimeArray[j] = false;
		}
	}
}

ll logGcd (ll n, ll m){ // O(n) = log(n+m)

	ll temp = 0;
	while(n){
		temp = n;
		n = m%n;
		m = temp;
	}
	return m;
}

ll logLcm(ll n,ll m){ // O(n) = log ( min(n,m) )
	return (n*m)/logGcd(n,m);
}

void calculateAllDivisors(ll n){ // O(n) = sqrt(n)
	for(int i = 1 ; i*i<=n; i++){
		if(!(n%i)){
			if(i != n/i){
				allDivisors.pb(i), allDivisors.pb(n/i);
			}
			else
				allDivisors.pb(i);
		}
	}
}

ll fastExp(ll n, ll k){
	
	if(k==0) return 1;
	if(k==1) return n;
	
	ll temp = fastExp(n,k>>1);
	
	if((k&1) == 1 ) return (n*temp*temp) % MOD;
	return (temp*temp) % MOD;
}


int main(){
	int n,m;
	cin >> n >> m;
	isPrimeArray.resize(n+1,true);
	allDivisors.resize(n);
	return 0;	
}

