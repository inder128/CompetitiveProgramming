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

int n, m, w;
vvi mat;
vi dx{0, -1, 0, 1};
vi dy{-1, 0, 1, 0};

bool valid(int x, int y){
    return x >= 0 and  x < n and y >= 0 and y < m and mat[x][y] >= 0; 
}

vvi get(int si, int sj){
	vvi dist(n, vi(m, 1e16));
	dist[si][sj] = 0;
	queue <pi> Q;
	Q.push({si, sj});
	while(SZ(Q)){
		auto [i, j] = Q.front(); Q.pop();
		for(int k = 0; k < 4; ++k){
			int ni = i + dx[k], nj = j + dy[k];
			if(valid(ni, nj) and dist[i][j] + w < dist[ni][nj]){
				dist[ni][nj] = dist[i][j] + w;
				Q.push({ni, nj});
			}
		}
	}
	return dist;
}

void solve(){
    cin >> n >> m >> w;
    mat = vvi(n, vi(m));
    cin >> mat;

    vvi mat00 = get(0, 0);
    vvi matnm = get(n - 1, m - 1);

    int ans = mat00[n - 1][m - 1];

    vi vals00, valsnm;
    for(int i = 0; i < n; ++i){
    	for(int j = 0; j < m; ++j){
    		if(mat[i][j] > 0){
    			vals00.pb(mat00[i][j] + mat[i][j]);
    			valsnm.pb(matnm[i][j] + mat[i][j]);
    		}
    	}
    }
    sort(rng(vals00));
    sort(rng(valsnm));
    if(SZ(vals00)){
    	mini(ans, vals00[0] + valsnm[0]);
    }

    if(ans >= 1e16){
    	ans = -1;
    }

    cout << ans << el;
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