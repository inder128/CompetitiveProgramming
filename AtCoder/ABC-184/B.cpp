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

const int N = 100;
double DP[N + 1][N + 1][N + 1];

double dfs(int a, int b, int c){
	if(DP[a][b][c] != -1){
		return DP[a][b][c];
	}
	double &ans = DP[a][b][c];
	ans = 0.0;
	ans += a * (1 + dfs(a + 1, b, c));
	ans += b * (1 + dfs(a, b + 1, c));
	ans += c * (1 + dfs(a, b, c + 1));
	ans /= (a + b + c);
	return ans;
}

void solve(){
    for (int i = 0; i < N + 1; ++i){
    	for (int j = 0; j < N + 1; ++j){
    		for (int k = 0; k < N + 1; ++k){
    			if(i == N or j == N or k == N){
    				DP[i][j][k] = 0;
    			}
    			else{
    				DP[i][j][k] = -1;
    			}
    		}
    	}
    }
    int a, b, c; cin>>a>>b>>c;
    cout<<setprecision(12)<<fixed;
    cout<<dfs(a, b, c)<<el;
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