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
    int n, q; cin >> n >> q;
    string op; cin >> op;
    vector <pi> mxmn(n + 2), mxmnr(n + 2);
    vi df(n + 2);
    for(int i = 1; i <= n; ++i){
    	if(op[i - 1] == '+'){
    		df[i] = 1;
    	}
    	else{
    		df[i] = -1;
    	}
    	df[i] += df[i - 1];
    	mxmn[i] = mxmn[i - 1];
    	mini(mxmn[i].F, df[i]);
    	maxi(mxmn[i].S, df[i]);
    }
    mxmn[n + 1] = mxmn[n];
    df[n + 1] = df[n];

    mxmnr[n + 1] = {df[n + 1], df[n + 1]};
    for(int i = n; i >= 0; --i){
    	mxmnr[i] = mxmnr[i + 1];
    	mini(mxmnr[i].F, df[i]);
    	maxi(mxmnr[i].S, df[i]);
    }


    while(q--){
    	int l, r; cin >> l >> r;
    	int d = df[r] - df[l - 1];

    	auto [mnl, mxl] = mxmn[l - 1];
    	auto [mnr, mxr] = mxmnr[r + 1];

    	mnr -= d, mxr -= d;

    	cout << max(mxl, mxr) - min(mnl, mnr) + 1 << el;
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