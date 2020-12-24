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

void solve(){
	int n; cin >> n;
    int u = ceil(log2(n));
    
    int p = 0;
    vector <pi> ans[n + 2];
    for(int i = 1; i <= n; ++i){
    	if(i <= 3){
    		for(int j = 1; j <= i; ++j){
    			ans[i].pb({j, i - 1});
    		}
    		ans[i].pb({i, 3}); // 2^3 == 8;
    	}
    	else if(i == 4){
    		ans[i].pb({4, 3}); 
    	}
        else{
        	ans[i].pb({i, p});
        	int r = i - (1 << (p - 1));
        	ans[i].pb({2 * r - 1, p + 1});
        	ans[i].pb({2 * r, p + 1});
        }
        if((i & (i - 1)) == 0){
        	p++;
        }
    }

    int pl = max(4, u + 2);
    cout << pl << el;
    for(int i = 0; i < pl; ++i){
    	cout << min(n, (1 << i)) << " ";
    }
    cout << el;
    for(int i = 1; i <= n; ++i){
    	cout << SZ(ans[i]) << el;
    	for(pi p : ans[i]){
    		cout << p.F << " " << p.S + 1 << el;
    	}
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}