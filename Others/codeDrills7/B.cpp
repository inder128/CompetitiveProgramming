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

    vector <pi> segs(n);
    for(int i = 0; i < n; ++i){
    	cin >> segs[i].F >> segs[i].S;
    }

    sort(rng(segs), [&](pi p1, pi p2){
    	int mx = max(p1.F, p2.F), mn = min(p1.S, p2.S);
    	if(mx <= mn){
    		if(mx == p1.F and mn == p1.S){
    			return false;
    		}
    		if(mx == p2.F and mn == p2.S){
    			return true;
    		}

    		return (p1.F < p2.F);
    	}
    	else{
    		return (p1.F < p2.F);
    	}
    });

    // db(segs);

    int c = -1, ans = 0;
    for(int i = 0; i < n; ++i){
    	int nc = c++;
    	if(segs[i].F > c){
    		c = segs[i].F;
    		ans++;
    	}
    	else if(segs[i].S <= c){
    		continue;
    	}
    	else{
    		c++;
    		ans++;
    	}
    }

    cout << ans << el;
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