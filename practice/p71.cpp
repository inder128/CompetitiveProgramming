#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define maxi(x, y) x = max(x, (y))
#define mini(x, y) x = min(x, (y))
#define pb push_back
#define F first
#define S second
#define el '\n'
// #define int long long
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

// https://codeforces.com/problemset/problem/1335/F
// checkout the binary lifting solution in editorial;
// see the memory limit error due to #define int long long;

map <pi, vector <pi>> adj;
vector <vector <bool>> isBlack, vis;
vector <bool> haveBlack;
vector <pair <pi, int>> cycHeads;
vector <string> mat, state;

void dfs(int i, int j, int no, int &mx){
	if(isBlack[i][j]) haveBlack[no] = true;
	vis[i][j] = true;
	for(pi p : adj[{i, j}]){
		if(vis[p.F][p.S]) continue;
		dfs(p.F, p.S, (no + 1)%mx, mx);
	}
}

void dfs(int i, int j){
	state[i][j] = 'g';

	int ci = i, cj = j;
	if(mat[ci][cj] == 'L') cj--;
	else if(mat[ci][cj] == 'R') cj++;
	else if(mat[ci][cj] == 'D') ci++;
	else ci--;

	if(state[ci][cj] == 'g'){
		cycHeads.pb({{ci, cj}, 0});
	}
	else if(state[ci][cj] == 'w'){
		dfs(ci, cj);
	}

	state[i][j] = 'b';
}

void solve(){
    adj.clear(); cycHeads.clear();
    int n, m; cin>>n>>m;
    isBlack = vector <vector <bool>>(n, vector <bool>(m));
    for (int i = 0; i < n; ++i){
    	string str; cin>>str;
    	for (int j = 0; j < m; ++j){
    		isBlack[i][j] = (str[j] == '0');
    	}
    }
    mat = vector <string>(n); cin>>mat;


    state = vector <string> (n, string(m, 'w'));
    for (int i = 0; i < n; ++i){
    	for (int j = 0; j < m; ++j){
    		if(state[i][j] == 'b') continue;
    		dfs(i, j);
    	}
    }


    vis = vector <vector <bool>>(n, vector <bool>(m));
    for(auto &p : cycHeads){
    	int ci = p.F.F, cj = p.F.S;
		while(!vis[ci][cj]){
			vis[ci][cj] = true;
			p.S++;
			if(mat[ci][cj] == 'L') cj--;
			else if(mat[ci][cj] == 'R') cj++;
			else if(mat[ci][cj] == 'D') ci++;
			else ci--;
		}
    }


    for (int i = 0; i < n; ++i){
    	for (int j = 0; j < m; ++j){
			if(mat[i][j] == 'L') adj[{i, j - 1}].pb({i, j});
			else if(mat[i][j] == 'R') adj[{i, j + 1}].pb({i, j});
			else if(mat[i][j] == 'D') adj[{i + 1, j}].pb({i, j});
			else adj[{i - 1, j}].pb({i, j});
    	}
    }

    vis = vector <vector <bool>>(n, vector <bool>(m));
    int ans = 0, bans = 0;
    for(auto &p : cycHeads){
    	haveBlack = vector <bool> (p.S);
    	dfs(p.F.F, p.F.S, 0, p.S);
    	ans += p.S;
    	bans += count(rng(haveBlack), true);
    }

    cout<<ans<<" "<<bans<<el;
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