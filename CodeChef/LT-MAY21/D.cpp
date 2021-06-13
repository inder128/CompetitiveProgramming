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

int n;
vi p, DP;


int get(int mask){
	// db(mask);
	if(DP[mask] != -1){
		return DP[mask];
	}
	int &ans = DP[mask];
	ans = 0;
	for(int i = 1; i < n; ++i){
		// db((mask >> i & 1), (mask >> p[i] & 1), p[i]);
		if((mask >> i & 1) and (mask >> p[i] & 1) == 0){

			mask -= (1 << i);
			mask += (1 << p[i]);
			maxi(ans, 1 + get(mask));
			mask += (1 << i);
			mask -= (1 << p[i]);
		}
	}
	// db(ans, mask);
	return ans;
}


void solve(){
	cin >> n;
	string str; cin >> str;
    p = vector <int> (n);
    for(int i = 1; i <= n - 1; ++i){
    	cin >> p[i];
    	p[i]--;
    }

    DP = vector <int> (1 << n, -1);
    int ini = 0;
    for(int i = 0; i < n; ++i){
    	if(str[i] == '1'){
    		ini += (1 << i);
    	}
    }
    cout << get(ini) << el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}