#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define maxi(x, y) x = max(x, (y))
#define mini(x, y) x = min(x, (y))
#define pb push_back
#define F first
#define S second
#define el '\n'
#define ll long long
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
    int n, x; cin>>n>>x;
    vi arr(n); cin>>arr;
    vvi DP(501, vi(501, 1e9));
    DP[0][x] = 0;
    for(int i = 0; i < n; ++i){
    	vvi newDP(501, vi(501, 1e9));
    	for(int val = 0; val < arr[i]; ++val){
    		for(int lval = 0; lval <= val; ++lval){
    			mini(newDP[val][arr[i]], DP[lval][val] + 1);
    		}
       	}
       	for(int car = 0; car <= 500; ++car){
       		for(int lval = 0; lval <= arr[i]; ++lval){
       			mini(newDP[arr[i]][car], DP[lval][car]);
       		}
       	}
       	DP = newDP;
    }

    int ans = 1e9;
    for(int i = 0; i <= 500; ++i){
    	for(int j = 0; j <= 500; ++j){
    		mini(ans, DP[i][j]);
    	}
    }

    if(ans >= 1e9) ans = -1;
    cout<<ans<<el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}