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
    int n, h; cin >> n >> h;

    auto sm = [&](int l, int r){
    	return r * (r + 1) / 2 - (l - 1) * l / 2;
    };

    auto get = [&](int mxh){
    	if(mxh <= h){
    		int ssm = sm(1, mxh);
    		int rem = n - ssm;
    		if(rem < 0){
    			return -1ll;
    		}
    		return mxh + rem / mxh + (rem % mxh > 0);
    	}	
    	else{
    		int ssm = sm(h, mxh - 1) + sm(1, mxh);
    		int rem = n - ssm;
    		if(rem < 0){
    			return -1ll;
    		}
    		return mxh - 1 - h + 1 + mxh + rem / mxh + (rem % mxh > 0);
    	}
    };

    int l = 1, r = 2e9;
    while(l + 1 < r){
    	int m = (l + r) >> 1;
    	if(get(m) != -1){
    		l = m;
    	}
    	else{
    		r = m;
    	}
    }

    cout << get(l) << el;
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