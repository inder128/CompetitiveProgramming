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

const int mod = 1e9 + 7;

void solve(){
    int n, m; cin>>n>>m;
    vector <string> mat(n);
    vvi lstl(n, vi(m));
    vvi lstu = lstl, lstd = lstl;
    vvi DP = lstl, DPl = lstl, DPu = lstl, DPd = lstl;
    for (int i = 0; i < n; ++i){
    	cin>>mat[i];
    	for (int j = 0; j < m; ++j){
    		if(mat[i][j] == '#') continue;

    		//lstl
    		if(j == 0) lstl[i][j] = 1;
    		else lstl[i][j] = lstl[i][j - 1] + 1;

    		//lstu;
    		if(i == 0) lstu[i][j] = 1;
    		else lstu[i][j] = lstu[i - 1][j] + 1;

    		// lstd;
    		if(i == 0 or j == 0) lstd[i][j] = 1;
    		else lstd[i][j] = lstd[i - 1][j - 1] + 1;
    	}
    }

    DP[0][0] = DPl[0][0] = DPu[0][0] = DPd[0][0] = 1;
    for (int i = 0; i < n; ++i){
    	for (int j = 0; j < m; ++j){
    		if(mat[i][j] == '#') continue;

    		if(i and lstu[i][j] >= 2){
    			DP[i][j] += DPu[i - 1][j];
    			if(i - lstu[i][j] >= 0) DP[i][j] -= DPu[i - lstu[i][j] ][j];
    			DP[i][j] += mod;
    			DP[i][j] %= mod;
    		}


    		if(j and lstl[i][j] >= 2){
    			DP[i][j] += DPl[i][j - 1];
    			if(j - lstl[i][j] >= 0) DP[i][j] -= DPl[i][j - lstl[i][j] ];
    			DP[i][j] += mod;
    			DP[i][j] %= mod;
    		}

    		if(i and j and lstd[i][j] >= 2){
    			DP[i][j] += DPd[i - 1][j - 1];
    			if(i - lstd[i][j] >= 0 and j - lstd[i][j] >= 0) DP[i][j] -= DPd[i - lstd[i][j] ][j - lstd[i][j] ];
    			DP[i][j] += mod;
    			DP[i][j] %= mod;
    		}

    		DPu[i][j] = DPl[i][j] = DPd[i][j] = DP[i][j];

    		if(i) DPu[i][j] = (DPu[i - 1][j] + DPu[i][j]) % mod;
    		if(j) DPl[i][j] = (DPl[i][j - 1] + DPl[i][j]) % mod;
    		if(j and i) DPd[i][j] = (DPd[i - 1][j - 1] + DPd[i][j]) % mod;


    	}
    }


    cout<<DP[n - 1][m - 1]<<el;
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