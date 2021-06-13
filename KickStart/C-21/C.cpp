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

const int N = 60;
double DP[N + 1][N + 1][N + 1];
string str[N + 1][N + 1][N + 1];
int w, e;
string rpsStr = "RPS";

int sc(int my, int his){
	if(my == his) return e;
	return (my + 2) % 3 == his;
}

void get(int r, int p, int s){
	if(DP[r][p][s] != -1){
		return;
	}

	if(r + p + s == 60){
		DP[r][p][s] = 0;
		return;
	}

	double tot = r + p + s;

	vi rps{r, p, s};
	vi oldrps = rps;
	for(int my = 0; my < 3; ++my){
		rps[my]++;
		get(rps[0], rps[1], rps[2]);
		double newAvg = DP[rps[0]][rps[1]][rps[2]];
		for(int his = 0; his < 3; ++his){
			newAvg += (tot != 0.0 ? oldrps[(his + 2) % 3] / tot : 1.0 / 3.0) * sc(my, his);
		}
		if(newAvg > DP[r][p][s]){
			DP[r][p][s] = newAvg;
			str[r][p][s] = str[rps[0]][rps[1]][rps[2]];
			str[r][p][s].pb(rpsStr[my]);
		}
		rps[my]--;
	}
}

void solve(){
    cin >> w >> e;

    for(int i = 0; i <= N; ++i){
    	for(int j = 0; j <= N; ++j){
    		for(int k = 0; k <= N; ++k){
    			DP[i][j][k] = -1;
    			str[i][j][k] = "";
    		}
    	}
    }

    get(0, 0, 0);
    reverse(rng(str[0][0][0]));
    cout << str[0][0][0] << el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1, tc = 1;
    cin >> T;
    int x; cin >> x;
    while(T--){
    	cout << "Case #" << tc << ": ";
    	tc++;
        solve();
    }
    return 0;
}