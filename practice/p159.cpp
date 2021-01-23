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
template<class L, class R>
istream&operator>>(istream&is,pair<L,R>&P){is>>P.F>>P.S;return is;}
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

const int N = 1e3;
int n;
vector <string> mat(N, string(N, '0'));
vector <vector <pi>> xy(N, vector <pi>(N));
int cnt;

string d = "UDLR";
string rd = "DURL";
vi dx{-1, 1, 0, 0};
vi dy{0, 0, -1, 1};

bool isValid(int i, int j){
	return i >= 0 and i < n and j >= 0 and j < n;
}

void dfs(int i, int j){
	cnt++;
	for(int k = 0; k < 4; ++k){
		int ni = i + dx[k];
		int nj = j + dy[k];
		if(isValid(ni, nj) and mat[ni][nj] == '0' and xy[ni][nj] == xy[i][j]){
			mat[ni][nj] = rd[k];
			dfs(ni, nj);
		}
	}
}

void solve(){
    cin >> n;
    map <pi, int> heads;
    for(int i = 0; i < n; ++i){
    	for(int j = 0; j < n; ++j){
    		cin >> xy[i][j];
    		xy[i][j].F--, xy[i][j].S--;
    		if(xy[i][j].F != -2){
    			heads[xy[i][j]]++;
    		}
    	}
    }

    for(auto [hp, c] : heads){
    	cnt = 0;
    	auto [x, y] = hp;

    	mat[x][y] = 'X';
    	dfs(x, y);

    	if(cnt != c or xy[x][y] != pi(x, y)){
    		cout << "INVALID";
    		return;
    	}
    }

    for(int i = 0; i < n; ++i){
    	for(int j = 0; j < n; ++j){
    		if(mat[i][j] != '0'){
    			continue;
    		}
    		bool iso = true;
    		for(int k = 0; k < 4; ++k){
    			int ni = i + dx[k];
    			int nj = j + dy[k];
    			if(isValid(ni, nj) and mat[ni][nj] == '0'){
    				mat[i][j] = d[k];
    				mat[ni][nj] = rd[k];
    				dfs(ni, nj);
    				dfs(i, j);
    				iso = false;
    				break;
    			}
    		}
    		if(iso){
    			cout << "INVALID";
    			return;
    		}
    	}
    }

    cout << "VALID" << el;
    for(int i = 0; i < n; ++i){
    	for(int j = 0; j < n; ++j){
    		cout << mat[i][j];
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