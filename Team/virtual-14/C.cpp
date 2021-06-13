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

bool q(int i, vi a){
	cout << "? 1 " << SZ(a) << el;
	cout << i << el;
	for(int j : a){
		cout << j << " ";
	}
	cout << endl;
	int x; cin >> x;
	return x != 0;
}

void solve(){
    int n; cin >> n;
    vi a{1};
    for(int i = 2; i <= n; ++i){
    	if(q(i, a)){
    		
    		int l = 0, r = i - 1;
    		while(l + 1 < r){
    			int m = (l + r) >> 1;
    			vi b(m);
    			iota(rng(b), 1);
    			if(q(i, b)){
    				r = m;
    			}
    			else{
    				l = m;
    			}
    		}

    		vi ans;
    		for(int j = 1; j < i; ++j){
    			if(j != r){
    				ans.pb(j);
    			}
    		}
    		for(int j = i + 1; j <= n; ++j){
    			if(q(i, {j}) == 0){
    				ans.pb(j);
    			}
    		}

    		cout << "! " << SZ(ans) << " ";
    		for(int j : ans){
    			cout << j << " ";
    		}
    		cout << endl;
    		return;
    	}
    	a.pb(i);
    }
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