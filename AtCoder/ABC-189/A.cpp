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

void solve(){
    int n; cin >> n;
    vvi xy(n, vi(2)); cin >> xy;
    int m; cin >> m;
    vi op(m + 1), op1(m + 1);
    for(int i = 1; i <= m; ++i){
    	cin >> op[i];
    	if(op[i] > 2){
    		cin >> op1[i];
    	}
    }
    int q; cin >> q;
    vector <pi> queries[m + 1];
    for(int i = 0; i < q; ++i){
     	int j, t; cin >> t >> j;
     	j--;
     	queries[t].pb({j, i});
    } 
    vector <pi> ans(q);
    array <int, 3> x{1, 0, 0}, y{1, 1, 0};

    auto rotate = [&](){
    	swap(x, y);
    	x[0] *= -1;
    	x[2] *= -1;
    };

    for(int i = 0; i <= m; ++i){
    	if(i){
    		if(op[i] == 1){
    			rotate();
    			rotate();
    			rotate();
    		}
    		else if(op[i] == 2){
    			rotate();
    		}
    		else if(op[i] == 3){
    			x[0] *= -1;
    			x[2] = 2 * op1[i] - x[2];
    		}
    		else{
    			y[0] *= -1;
    			y[2] = 2 * op1[i] - y[2];
    		}
    	}
    	for(auto [j , ai] : queries[i]){
    		ans[ai] = {x[0] * xy[j][x[1]] + x[2], y[0] * xy[j][y[1]] + y[2]};
    	}
    }
    for(int i = 0; i < q; ++i){
    	cout << ans[i].F << " " << ans[i].S << el;
    }
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