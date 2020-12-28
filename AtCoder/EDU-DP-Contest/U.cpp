#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define maxi(x, y) x = max(x, (y))
#define mini(x, y) x = min(x, (y))
#define pb push_back
#define F first
#define S second
#define el '\n'
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.S << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ "; for(auto m:M) os<<"("<<m.F<<" : "<<m.S<<") "; return os<<"}";}
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef long long ll; typedef pair<int,int> pi; typedef vector <bool> vb;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/


// Tricky time complexity -> O(3^n + (2^n)*(n^2)) -> amortised;
vl gpCost(1<<16), DP(1<<16, -1e18);

void rec(vi &pre, int &gp, int i = 0, int mask = 0){
	if(i == pre.size()){
		maxi(DP[gp], DP[gp^mask] + gpCost[mask]);
		return;
	}

	rec(pre, gp, i + 1, mask);
	rec(pre, gp, i + 1, mask|(1<<pre[i]));
}

void solve(){
    int n; cin>>n;
    vvi a(n, vi(n));
    for(vi &v : a) for(int &i : v) cin>>i;

	for (int i = 0; i < (1<<n); ++i){
		for (int u = 0; u < n; ++u){
			if(!(i&(1<<u))) continue;
			for (int v = 0; v < u; ++v){
				if(!(i&(1<<v))) continue;
				gpCost[i] += a[u][v];
			}
		}
	}


	DP[0] = 0;
	for (int gp = 1; gp < (1<<n); ++gp){
		vi pre;
		for (int u = 0; u < n; ++u){
			if(gp&(1<<u)) pre.pb(u);
		}
		rec(pre, gp);
	}

	cout<<DP[(1<<n) - 1]<<el;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1, tc = 1;
    // cin>>T; 
    while(T--){
        solve();
    }
    return 0; 
}