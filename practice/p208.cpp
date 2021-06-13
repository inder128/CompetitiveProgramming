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
    int n, m; cin >> n >> m;
    vi x(n); cin >> x;
    vector <char> dir(n); cin >> dir;

    vector <pi> xi(n), xd(n);
    for(int i = 0; i < n; ++i){
    	xi[i] = {x[i], i};
    	xd[i] = {x[i], dir[i] == 'R'};
    }
    sort(rng(xd));
    sort(rng(xi));

    for(int i = 0; i < n; ++i){
    	x[i] = xd[i].F;
    	dir[i] = (xd[i].S ? 'R' : 'L');
    }

    vi ans(n, -1);
    for(int par = 0; par < 2; ++par){
    	vi r, l;
    	for(int i = 0; i < n; ++i){
    		if(x[i] % 2 != par){
    			continue;
    		}
    		if(dir[i] == 'R'){
    			r.pb(i);
    		}
    		else if(SZ(r)){
    			ans[r.back()] = ans[i] = (x[i] - x[r.back()]) / 2;
    			r.pop_back();
    		}
    		else{
    			l.pb(i);
    		}
    	}

    	for(int i = 1; i < SZ(l); i += 2){
    		ans[l[i - 1]] = ans[l[i]] = (x[l[i - 1]] + x[l[i]]) / 2;
    	}
    	for(int i = SZ(r) - 2; i >= 0; i -= 2){
    		ans[r[i + 1]] = ans[r[i]] = m - (x[r[i + 1]] + x[r[i]]) / 2;
    	}

    	if(SZ(l) % 2 and SZ(r) % 2){
    		ans[l.back()] = ans[r[0]] = m - (x[r[0]] - x[l.back()]) / 2;
    	}
    }

    vi ans2(n);
    for(int i = 0; i < n; ++i){
    	ans2[xi[i].S] = ans[i];
    }
    for(int i : ans2) cout << i << " "; cout << el;
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