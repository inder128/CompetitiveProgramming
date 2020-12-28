#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
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
    os << "{ "; for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") "; return os<<"}";}
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef long long ll; typedef pair<int,int> pi; 
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

void solve(){
    int n; cin>>n;
    vi p(n); for(int &i : p) cin>>i;
    if(n > 16) return;
    for (int mask = 0; mask < (1<<n); ++mask){
    	vi p1, p2;
    	for (int b = 0; b < n; ++b){
    		if(mask&(1<<b)) p1.pb(p[b]);
    		else p2.pb(p[b]);
    	}
    	int c1 = 0, c2 = 0;
    	for (int i = 0; i < p1.size(); ++i){
    		for (int j = 0; j < i; ++j){
    			if(p1[j] > p1[i]) c1++;
    		}
    	}
    	for (int i = 0; i < p2.size(); ++i){
    		for (int j = 0; j < i; ++j){
    			if(p2[j] > p2[i]) c2++;
    		}
    	}
    	if(c1 != c2) continue;
    	cout<<"YES\n";
    	return;
    }
    cout<<"NO\n";
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1, tc = 1;
    cin>>T; 
    while(T--){
        solve();
    }
    return 0; 
}