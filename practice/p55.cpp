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

void solve(){
    int n, k; cin>>n>>k;
    map <int, int> cnt;
    for (int i = 0; i < n; ++i){
    	int x; cin>>x;
    	cnt[x]++;
    }
    vl sum, occ;
    vector <pair <ll, ll>> cp; 
    for(pi p : cnt){
    	sum.pb(p.F*1ll*p.S + (sum.empty() ? 0 : sum.back()));
    	occ.pb(p.S + (occ.empty() ? 0 : occ.back()));
    	if(p.S >= k){
    		cout<<0<<el;
    		return;
    	}
    	cp.pb(p);
    }
    ll tsum = sum.back(), cost = LLONG_MAX;
    for (int i = 0; i < cp.size(); ++i){
    	ll c1 = (occ[i] - cp[i].S)*(cp[i].F - 1) - (sum[i] - cp[i].F*cp[i].S);
    	int toAdd = min(k - cp[i].S, occ[i] - cp[i].S);
    	c1 += toAdd;
    	if(toAdd + cp[i].S < k){
    		c1 += (tsum - sum[i]) - (n - occ[i])*(cp[i].F + 1);
    		c1 += min(n - occ[i], k - (toAdd + cp[i].S));
    	}

    	ll c2 = (tsum - sum[i]) - (n - occ[i])*(cp[i].F + 1);
    	toAdd = min(k - cp[i].S, n - occ[i]);
    	c2 += toAdd;
    	if(toAdd + cp[i].S < k){
    		c2 += (occ[i] - cp[i].S)*(cp[i].F - 1) - (sum[i] - cp[i].F*cp[i].S);
    		c2 += min(occ[i] - cp[i].S, k - (toAdd + cp[i].S));
    	}

    	mini(cost, min(c1, c2));
    }

    cout<<cost<<el;
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