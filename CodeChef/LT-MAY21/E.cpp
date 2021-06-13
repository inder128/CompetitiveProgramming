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
    vi a(n), b(n); cin >> a >> b;

    vector <double> m(n);
    for(int i = 0; i < n; ++i){
    	double r1 = a[i] / (double) b[i];
    	for(int j = i; j < n; ++j){
    		double r2 = a[j] / (double) b[j];
    		double x = (b[j] * b[j]) / (double) (b[i] * b[i] + b[j] * b[j]);
    		x *= abs(r1 - r2);
    		if(r1 > r2){
    			m.pb(r1 - x);
    		}
    		else{
    			m.pb(r1 + x);
    		}
    	}
    }

    // db(m);
    sort(rng(m));

    

    auto get = [&](int i, double r){
    	return (a[i] - r * b[i]) * (a[i] - r * b[i]);
    };

    vector<vector <double>> DP(n + 1, vector <double>(SZ(m)));
    for(int i = n - 1; i >= 0; --i){
    	DP[i][0] = get(i, m[0]) + DP[i + 1][0];
    	for(int j = 1; j < SZ(m); ++j){
    		DP[i][j] = 1e14;
    		mini(DP[i][j], min(DP[i][j - 1], get(i, m[j]) + DP[i + 1][j]));
    	}
    }

    for(auto arr : DP){
    	// db(arr);
    }

    cout << DP[0].back() << el;
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