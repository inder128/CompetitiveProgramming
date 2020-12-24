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

vvi valid(81, vi(10));

void preCalc(){
	valid[0] = vi(10, 1);
	for(int j = 0; j < 10; ++j){
		valid[1][j] = 10 - j;
	}
	// valid[i][j] -> no of valid str of len i stating at j or more;
	for(int i = 2; i <= 80; ++i){
		for(int j = 0; j < 10; ++j){
			valid[i][j] = valid[i - 1][j];
		}
		for(int j = 8; j >= 0; --j){
			valid[i][j] += valid[i][j + 1];
		}
	}
}


void solve(){
    string str; cin >> str;
    int n = SZ(str);

    for(int i = 1; i < n; ++i){
    	if(str[i] < str[i - 1]){
    		cout << -1 << el;
    		return;
    	}
    }

    int ans = 0;
    for(int i = 0; i < n; ++i){
    	for(int j = (i == 0 ? 0 : (str[i - 1] - '0')); j < (str[i] - '0'); ++j){
    		ans += valid[n - (i + 1)][j];
    	}
    }

    cout << ans << el;

}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    preCalc();
    while(T--){
        solve();
    }
    return 0;
}