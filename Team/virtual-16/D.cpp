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

map <array <int, 4>, bool> DP;
map <array <int, 4>, vector <pi>> res;


void get(int a, int b, int r, int w, vector <pi> &curr){
	if(a > 200 or b > 200 or DP[{a, b, r, w}]){
		return;
	}
	DP[{a, b, r, w}] = true;

	if(w == 3 or r - w == 3) {
		res[{a, b, r, w}] = curr;
		return;
	}

	int mx = 25 - (r == 4) * 10;

	// a win;
	for (int i = 0; i <= mx - 2; ++i){
		curr.pb({mx, i});
		get(a + mx, b + i, r + 1, w + 1, curr);
		curr.pop_back();
	}
	for (int i = mx - 1; i <= 200; ++i){
		curr.pb({i + 2, i});
		get(a + i + 2, b + i, r + 1, w + 1, curr);
		curr.pop_back();
	}

	// b win;
	for (int i = 0; i <= mx - 2; ++i){
		curr.pb({i, mx});
		get(a + i, b + mx, r + 1, w, curr);
		curr.pop_back();
	}
	for (int i = mx - 1; i <= 200; ++i){
		curr.pb({i, i + 2});
		get(a + i, b + i + 2, r + 1, w, curr);
		curr.pop_back();
	}
}


void preCalc(){
	vector <pi> curr;
    get(0, 0, 0, 0, curr);
}

void solve () {
	int a, b; cin >> a >> b;

	// w = 3, ow = 0;
	for (int ow = 0; ow <= 2; ++ow){
		if(DP[{a, b, 3 + ow, 3}]) {
			cout << "3:" << ow << el;
			for(auto p : res[{a, b, 3 + ow, 3}]){
				cout << p.F << ":" << p.S << " "; 
			}
			cout << el;
			return;
		}
	}

	for (int w = 2; w >= 0; --w){
		if(DP[{a, b, w + 3, w}]) {
			cout << w << ":3" << el;
			for(auto p : res[{a, b, w + 3, w}]){
				cout << p.F << ":" << p.S << " "; 
			}
			cout << el;
			return;
		}
	}

	cout << "Impossible" << el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    preCalc();
    while(T--){
        solve();
    }
    return 0;
}