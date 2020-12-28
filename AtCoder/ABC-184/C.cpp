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

vi dx{-1, 1, 0, 0};
vi dy{0, 0, -1, 1};

void solve(){
    int n, m; cin>>n>>m;
    vector <string> mat(n);
    vector <pi> pos[26];
    for (int i = 0; i < n; ++i){
    	cin>>mat[i];
    	for (int j = 0; j < m; ++j){
    		if(mat[i][j] >= 'a' and mat[i][j] <= 'z'){
    			pos[mat[i][j] - 'a'].pb({i, j});
    		}
    	}
    }

    vector <bool> full(26);
    vvi dist(n, vi(m, -1));
    queue <pi> Q;
    int ex, ey;
    for (int i = 0; i < n; ++i){
    	for (int j = 0; j < m; ++j){
    		if(mat[i][j] == 'S'){
    			Q.push({i, j});
    			dist[i][j] = 0;
    		}
    		if(mat[i][j] == 'G'){
    			ex = i, ey = j;
    		}
    	}
    }

    function <bool(int, int)> valid = [&](int x, int y){
    	return x >= 0 and x < n and y >= 0 and y < m and dist[x][y] == -1 and mat[x][y] != '#';
    };

    while(Q.size()){
    	int x = Q.front().F, y = Q.front().S; Q.pop();

    	if(mat[x][y] == 'G') break;

    	for (int i = 0; i < 4; ++i){
    		int nx = x + dx[i];
    		int ny = y + dy[i];
    		if(valid(nx, ny) == false) continue;
    		dist[nx][ny] = dist[x][y] + 1;
    		Q.push({nx, ny});
    	}

    	if(mat[x][y] == 'S' or mat[x][y] == '.') continue;

    	if(full[mat[x][y] - 'a']) continue;

    	full[mat[x][y] - 'a'] = true;

    	for(pi pr : pos[mat[x][y] - 'a']){
    		int nx = pr.F;
    		int ny = pr.S;
    		if(valid(nx, ny) == false) continue;
    		dist[nx][ny] = dist[x][y] + 1;
    		Q.push({nx, ny});
    	}
    }

    cout<<dist[ex][ey]<<el;

}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}