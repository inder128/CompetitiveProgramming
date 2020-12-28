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

const int mod = 1e9 + 7;

void solve(){
    int n; cin>>n;
    string str; cin>>str;

    vvi DP(n, vi(n));
    // Base Case :- DP[n - 1][0] = 1; brcause brem will be zero at the last element;
    // prefix sum :-
    DP[n - 1] = vi(n, 1);

    // value of i only depends on value at i - 1;
    for (int i = n - 2; i >= 0; --i){
    	if(str[i] == '<'){
            // brem is the no of elements (> current element) which are not used till now;
	    	for (int brem = 1; brem < n; ++brem){
                // here we have to put an element greater than the current element, so brem will decrease;
	    		DP[i][brem] = DP[i + 1][brem - 1];
	    	}
	    }
	    else{
	    	for (int brem = 0; brem < n; ++brem){
	    		int srem = n - (i + 1) - brem;
                // not valid state, because we need remaining element smaller then the current element;
	    		if(srem <= 0) continue;

                // here we have to put an element smaller than the current element, so brem will decrease or remain the same;
	    		DP[i][brem] = (DP[i + 1][brem + srem - 1] - (brem ? DP[i + 1][brem - 1] : 0) + mod) % mod;
	    	}
	    }

        // optimising DP using prefix sum, similar technique is used in M.cpp;
	    for (int brem = 1; brem < n; ++brem){
	    	DP[i][brem] += DP[i][brem - 1];
	    	DP[i][brem] %= mod;
	    }
    }

    cout<<DP[0][n - 1]<<el;
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