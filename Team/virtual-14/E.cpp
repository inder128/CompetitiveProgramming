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


int in(vi &v, int l, int r){
	return upper_bound(rng(v), r) - lower_bound(rng(v), l);
}


void solve(){
    int n, m; cin >> n >> m;
    vi a(n), b(m); cin >> a >> b;

    int fp = 0;
    while(fp < m and b[fp] < 0){
    	fp++;
    }

    int rmx = 0, cs = 0;
    for(int i = m - 1; i >= fp; --i){
    	// ending at b[i];
    	int tot = in(a, 1, b[i]);
    	maxi(rmx, in(b, b[i] - tot + 1, b[i]) + cs);

    	cs += in(a, b[i], b[i]);
    }


    int lmx = 0;
    cs = 0;
    for(int i = 0; i < fp; ++i){
    	//starting at b[i];
    	int tot = in(a, b[i], -1);
    	maxi(lmx, in(b, b[i], b[i] + tot - 1) + cs);

    	cs += in(a, b[i], b[i]);
    }

    cout << lmx + rmx << el;
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