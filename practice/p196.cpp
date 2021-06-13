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

void solve(){
    int n, m; cin >> n >> m;
    vvi mat(n, vi(m)); cin >> mat;

    vector <pi> inds;
    for(int i = 0; i < n; ++i){
    	for(int j = 0; j < m; ++j){
    		inds.pb({i, j});
    	}
    }

    sort(rng(inds), [&](pi p1, pi p2){
    	return mat[p1.F][p1.S] < mat[p2.F][p2.S];
    });

    vvi path(n, vi(m));
    for(int i = 0; i < m; ++i){
    	path[inds[i].F][inds[i].S] = i + 1;
    }

    vvi ans(n, vi(m));
    for(int i = 0; i < n; ++i){
    	for(int j = 0; j < m; ++j){
    		if(path[i][j]){
    			ans[i][path[i][j] - 1] = mat[i][j];
    		}
    	}
    	int j1 = 0, j2 = 0;
    	while(j1 < m and j2 < m){
    		while(ans[i][j1]) j1++;
    		while(path[i][j2]) j2++;
    		if(j1 >= m or j2 >= m) break;
    		ans[i][j1] = mat[i][j2];
    		j1++, j2++;
       	}
       	for(int j = 0; j < m; ++j){
       		cout << ans[i][j] << " ";
       	}
       	cout << el;
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}