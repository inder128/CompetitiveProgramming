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
    string s1, s2; cin>>s1>>s2;
    int n = s1.length();
    int m = s2.length();

    reverse(rng(s2));

    vector <vi> end(n+1, vi(m+1));
    for (int i = 1; i <= n; ++i){
    	for (int j = 1; j <= m; ++j){
    		if(s1[i-1] != s2[j-1]) continue;
    		end[i][j] = 1 + end[i-1][j-1];
    	}
    }

    vector <vi> DP(n+1, vi(m+1));
    for (int i = 1; i <= n; ++i){
    	for (int j = 1; j <= m; ++j){
    		DP[i][j] = max({DP[i-1][j-1], DP[i-1][j], DP[i][j-1], end[i][j]});
    	}
    }





    int ans = 0;
    for (int i = 1; i <= n; ++i){
    	for (int j = 1; j <= m; ++j){
    		int eh = end[i][j];
    		maxi(ans, eh + DP[i - eh][j - eh]);
    	}
    }

    cout<<2*ans<<el;




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