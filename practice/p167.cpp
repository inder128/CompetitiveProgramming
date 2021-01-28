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

const int mod = 1e9 + 7;

int add(int x, int y){
    x += y;
    while(x >= mod) x -= mod;
    while(x < 0) x += mod;
    return x;
}

int mul(int x, int y){
    return (x * 1ll * y) % mod;
}

void solve(){
    int n; cin >> n;

    vi fac;
    for(int i = 0; (1 << i) <= n; ++i){
    	fac.pb(1 << i);
    	if((1 << i) * 3 <= n){
    		fac.pb((1 << i) * 3);
    	}
    }
    sort(rng(fac));

    map <int, int> mp;
    mp[fac.back()] = 1;
    if(fac.back() % 3 == 0){
    	mp[fac.back() / 3 * 2] = 1;
    }

    for(int i = 2; i <= n; ++i){
    	map <int, int> nmp;
    	for(int g : fac){
    		if(n / g < i){
    			continue;
    		}
    		nmp[g] = add(nmp[g], mul(mp[g], (n / g - (i - 1))));
    		nmp[g] = add(nmp[g], mul(mp[2 * g], (n / g - n / (2 * g))));
    		nmp[g] = add(nmp[g], mul(mp[3 * g], (n / g - n / (3 * g))));
    	}
    	mp = nmp;
    }

    cout << mp[1] << el;
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