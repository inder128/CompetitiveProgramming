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

int getTime(string tm){
	return stoi(tm.substr(0, 2)) * 60 * 60 + stoi(tm.substr(3, 2)) * 60 + stoi(tm.substr(6, 2));
}

void solve(){
    int n, m, t; cin >> n >> m >> t;
    map <int, int> sm;
    vi ans;
    vector <int> tms;
    int lst = 0, mx = 0;
    for(int i = 0; i < n; ++i){
    	string str; cin >> str;
    	int tm = getTime(str);
    	int j = upper_bound(rng(tms), tm - t) - tms.begin();
    	if(j == i or lst + 1 - sm[tms[j]] + 1 <= m){
    		lst++;
    	}
    	if(sm.count(tm) == 0){
			sm[tm] = lst;
		}
    	tms.pb(tm);
    	ans.pb(lst);
    	maxi(mx, ans[i] - ans[j] + 1);
    }
    if(mx < m){
    	cout << "No solution" << el;
    	return;
    }
    cout << lst << el;
    for(int i : ans) cout << i << el;
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