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

const int N = 100;
bitset <N * N> DP[N][N][4][4][20];
vector <string> mat(N);

void solve(){
    int n, m, q; cin >> n >> m >> q;
    for (int i = 0; i < n; ++i){
    	cin >> mat[i];
    }

    for (int i = 0; i < n; ++i){
    	for (int j = 0; j < m; ++j){
    		// up
    		for (int di = -1; di >= -n; di--){
    			int i2 = (i + di + n) % n;
    			if(mat[i2][j] == '.'){
    				DP[i][j][0][1][0][i2 * n + j] = true;
    				break;
    			}
    		}

    		// right
    		for (int dj = 1; dj <= n; dj++){
    			int j2 = (j + dj + n) % n;
    			if(mat[i][j2] == '.'){
    				DP[i][j][1][3][0][i * n + j2] = true;
    				break;
    			}
    		}

    		// down
    		for (int di = 1; di <= n; di++){
    			int i2 = (i + di + n) % n;
    			if(mat[i2][j] == '.'){
    				DP[i][j][2][0][0][i2 * n + j] = true;
    				break;
    			}
    		}

    		// left
    		for (int dj = -1; dj >= -n; dj--){
    			int j2 = (j + dj + n) % n;
    			if(mat[i][j2] == '.'){
    				DP[i][j][3][1][0][i * n + j2] = true;
    				break;
    			}
    		}
    	}
    }


    for (int p = 1; p < 20; ++p){
    	for (int i = 0; i < n; ++i){
    		for (int j = 0; j < m; ++j){
    			for (int gd = 0; gd < 4; ++gd){
    				for (int cd = 0; cd < 4; ++cd){
    					for (int ma = 0; ma < 4; ++ma){
    						for (int mg = 0; mg < 4; ++mg){
    							if(ma == mg) continue;
    							DP[i][j][gd][cd][p] != (DP[])
    						}
    					}
    				}
    			}
    		}
    	}
    }


    while(q--){
    	int i, j, k, t; cin >> i >> j >> k >> t;
    	i--, j--;

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