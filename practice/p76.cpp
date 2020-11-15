#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define maxi(x, y) x = max(x, (y))
#define mini(x, y) x = min(x, (y))
#define pb push_back
#define F first
#define S second
#define el '\n'
#define int long long
template<typename T>
istream&operator>>(istream&is,vector<T>&v){for(auto&it:v)is>>it;return is;}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.S << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

void solve(){
    int n, m; cin>>n>>m;
    set <int> st;
    vvi mat(n, vi(m));
    for (int i = 0; i < n; ++i){
    	for (int j = 0; j < m; ++j){
    		cin>>mat[i][j];
	    	st.insert(mat[i][j] - i - j);
    	}	
    }
    int ans = LLONG_MAX;
    for(int s : st){
    	vvi DP(n, vi(m, LLONG_MAX));
    	if(s > mat[0][0]){
    		break;
    	}
    	else{
    		DP[0][0] = mat[0][0] - s;
    	}

    	for (int i = 0; i < n; ++i){
    		for (int j = 0; j < m; ++j){
    			if(i == 0 and j == 0) continue;
    			if(mat[i][j] < s + i + j) continue; 
    			int prev;
    			if(i == 0){
    				prev = DP[i][j - 1];
    			}
    			else if(j == 0){
    				prev = DP[i - 1][j];
    			}
    			else{
    				prev = min(DP[i - 1][j], DP[i][j - 1]);
    			}
    			if(prev == LLONG_MAX) continue;
    			DP[i][j] = prev + (mat[i][j] - (s + i + j));
    		}
    	}
    	mini(ans, DP[n - 1][m - 1]);
    }

    cout<<ans<<el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}