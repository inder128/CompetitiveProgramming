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

// Codeforces Question link :-
// https://codeforces.com/contest/1294/problem/E
// better solution in editorial;


void solve(){
    int n, m; cin>>n>>m;
    vvi mat(m, vi(2*n));
    for (int i = 0; i < n; ++i){
    	for (int j = 0; j < m; ++j){
    		int x; cin>>x; x--;
    		mat[j][i] = mat[j][i + n] = x - j;
    	}
    }
    int ans = 0;
    for (int ii = 0; ii < m; ++ii){
    	vi &v = mat[ii], DP(2*n+1, n);
    	map <int, int> dist;
    	for (int i = 0; i < 2*n; ++i){
    		if(v[i] < 0 or v[i] % m) continue;
    		if(v[i]/m > i or v[i]/m >= n) continue;
    		if(v[i] == 0) DP[i] = i + (n-1);
    		else{
    			auto itr = dist.find(i - v[i]/m);
    			if(itr == dist.end()){
    				DP[i] = (i - v[i]/m) + (n-1);
    			}
    			else{
    				DP[i] = DP[itr->S] - 1;
    			}
    		}
    		dist[i - v[i]/m] = i;
    	}
    	ans += *min_element(rng(DP));
    }
	cout<<ans<<el;
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