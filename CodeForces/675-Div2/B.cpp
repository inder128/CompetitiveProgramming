#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define maxi(x, y) x = max(x, (y))
#define mini(x, y) x = min(x, (y))
#define pb push_back
#define F first
#define S second
#define el '\n'
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.S << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ "; for(auto m:M) os<<"("<<m.F<<" : "<<m.S<<") "; return os<<"}";}
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef long long ll; typedef pair<int,int> pi; typedef vector <bool> vb;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

void solve(){
	int n, m; cin>>n>>m;
    vvi mat(n, vi(m));
    for(auto &v : mat) for(int &i : v) cin>>i; 

    vvi res(n, vi(m, -1));
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			if(res[i][j] != -1) continue;
			int a = mat[i][j], b = mat[n - 1 - i][j];
			int c = mat[i][m - 1 -j], d = mat[n - 1 - i][m - 1 - j];
			vi arr = {a, b, c, d};
			sort(rng(arr));
			res[i][j] = res[n - 1 - i][j] = arr[1];
			res[i][m - 1 - j] = res[n - 1 - i][m - 1 - j] = arr[1];
		}
	}

	ll ans = 0;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			ans += abs(res[i][j] - mat[i][j]);
		}
	}

	cout<<ans<<el;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1, tc = 1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
