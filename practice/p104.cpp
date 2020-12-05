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



void solve(){
	int n, k; cin>>n>>k;
	string str; cin>>str;
	str = "$" + str;

	vvi last(n + 1, vi(26));
	for(int i = 1; i <= n; ++i){
		last[i] = last[i - 1];
		last[i][str[i] - 'a'] = i;
	}

	int DP[n + 1][n + 1][27];
	for(int i = 0; i < n + 1; ++i){
		for(int j = 0; j < n + 1; ++j){
			for(int kk = 0; kk < 27; ++kk){
				DP[i][j][kk] = 0;
			}
		}
	}
	// DP[ln][pre][ls] -> no of distinct subsequences of length ln from str[1..pre] ending with letter ls;
	for(int i = 0; i <= n; ++i){
		for(int j = 0; j < 26; ++j){
			DP[1][i][j] = last[i][j] > 0;
			DP[1][i][26] += last[i][j] > 0;
		}
	}

	for(int ln = 2; ln <= n; ++ln){
		for(int pre = 0; pre <= n; ++pre){
			for(int ls = 0; ls < 26; ++ls){
				if(last[pre][ls]){
					DP[ln][pre][ls] = DP[ln - 1][last[pre][ls] - 1][26];
				}
				DP[ln][pre][26] += DP[ln][pre][ls];
			}	
		}
	}

	int ln = n, ans = 0;
	while(ln and k){
		int toDel = min(DP[ln][n][26], k);
		ans += (n - ln) * toDel;
		k -= toDel;
		ln--;
	}

	if(k){ // empty string;
		k--;
		ans += n;
	}

	if(k) ans = -1;

	cout<<ans<<el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}