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

const int N = 1e3;
vector <string> mat(N);
vvi vis(N, vi(N));
int n, m;

vi dx = {-1,  0, 1, 0};
vi dy = {0, 1, 0, -1}; 


bool valid(int i, int j){
	return i >= 0 and i < n and j >= 0 and j < m and vis[i][j] == 0 and mat[i][j] == '#';
}


void dfs(int i, int j){
	vis[i][j] = 1;
	for (int k = 0; k < 4; ++k){
		int ni = i + dx[k];
		int nj = j + dy[k];
		if(!valid(ni, nj)) continue;
		dfs(ni, nj);
	}
}


void solve(){
    cin>>n>>m;
    vi cnti(n), cntj(m);
    for (int i = 0; i < n; ++i){
    	cin>>mat[i];
    	for (int j = 0; j < m; ++j){
    		if(mat[i][j] == '#'){
    			cnti[i]++;
    			cntj[j]++;
    		}
    	}
    }

    int ci = count(rng(cnti), 0);
    int cj = count(rng(cntj), 0);

    if((ci == 0 and cj) or (ci and cj == 0)){
    	cout<<"-1\n";
    	return;
    }


    for (int i = 0; i < n; ++i){
    	bool st = (mat[i][0] == '#');
    	for (int j = 1; j < m; ++j){
    		if(mat[i][j] == '#' and mat[i][j - 1] == '#') continue;
    		if(mat[i][j] == '#' and mat[i][j - 1] == '.'){
    			if(st){
    				cout<<"-1\n";
	    			return;
    			}
	    		else{
	    			st = true;
	    		}	
    		}
    	}
    }


    for (int i = 0; i < m; ++i){
    	bool st = (mat[0][i] == '#');
    	for (int j = 1; j < n; ++j){
    		if(mat[j][i] == '#' and mat[j - 1][i] == '#') continue;
    		if(mat[j][i] == '#' and mat[j - 1][i] == '.'){
    			if(st){
    				cout<<"-1\n";
	    			return;
    			}
	    		else{
	    			st = true;
	    		}	
    		}
    	}
    }

    int c = 0;
    for (int i = 0; i < n; ++i){
    	for (int j = 0; j < m; ++j){
    		if(!valid(i, j)) continue;
    		dfs(i, j);
    		c++;
    	}
    }

    cout<<c<<el;
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