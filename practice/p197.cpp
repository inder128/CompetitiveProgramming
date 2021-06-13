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

int n, rem;
vvi ans;

vi dx{-1, 0, 1, 0};
vi dy{0, -1, 0, 1};

bool valid(int i, int j){
	return i >= j and i >= 0 and i < n and j >= 0 and j < n and ans[i][j] == 0;
}

void dfs(int i, int j, int k){
	if(rem == 0){
		return;
	}
	ans[i][j] = k;
	rem--;
	for(int p = 0; p < 4; ++p){
		int ni = i + dx[p];
		int nj = j + dy[p];
		if(valid(ni, nj)){
			dfs(ni, nj, k);
		}
	}
}

void solve(){
    cin >> n;
    ans = vvi(n, vi(n));
    vi p(n); cin >> p;

    for(int i = 0; i < n; ++i){
    	rem = p[i];
    	dfs(i, i, p[i]);
    }
    for(int i = 0; i < n; ++i){
    	for(int j = 0; j <= i; ++j){
    		cout << ans[i][j] << " ";
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