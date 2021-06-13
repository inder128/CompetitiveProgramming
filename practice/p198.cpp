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
#define SZ(x) ((int)(x).size()) 
template<typename T>
istream&operator>>(istream&is,vector<T>&v){for(auto&it:v)is>>it;return is;}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.S << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
#ifndef ONLINE_JUDGE 
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define db(...)
#endif
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code Begins--------------------------------*/

int n, m;
vi dx{0, -1, 0, 1};
vi dy{-1, 0, 1, 0};
vi dxx{0, -1, 0, 0};
vi dyy{-1, 0, 0, 0};

bool valid(int x, int y){
    return x >= 0 and  x < n and y >= 0 and y < m; 
}

void solve(){
    int k; cin >> n >> m >> k;
    vvi hor(n, vi(m - 1)); cin >> hor;
    vvi ver(n - 1, vi(m)); cin >> ver;

    if(k % 2){
    	for(int i = 0; i < n; ++i){
    		for(int j = 0; j < m; ++j){
    			cout << -1 << " ";
    		}
    		cout << el;
    	}
    	return;
    }

    vvi DP(n, vi(m));
    for(int p = 1; p <= k / 2; ++p){
    	vvi newDP(n, vi(m, 1e14));

    	for(int i = 0; i < n; ++i){
    		for(int j = 0; j < m; ++j){
    			for(int d = 0; d < 4; ++d){
    				int ni = i + dx[d], nj = j + dy[d];
    				if(valid(ni, nj) == false) continue;
    				if(d % 2){ // ver
    					mini(newDP[i][j], DP[ni][nj] + ver[i + dxx[d]][j + dyy[d]]);
    				}
    				else{
    					mini(newDP[i][j], DP[ni][nj] + hor[i + dxx[d]][j + dyy[d]]);
    				}
    			}
    		}
    	}

    	DP = newDP;
    }

    for(int i = 0; i < n; ++i){
    	for(int j = 0; j < m; ++j){
    		cout << DP[i][j] * 2 << " ";
    	}
    	cout << el;
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}