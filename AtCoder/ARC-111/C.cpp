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
    vi a(n); cin >> a;
    vi b_(n); cin >> b_;
    vi b(n);
    vi perm(n);
    for(int i = 0; i < n; ++i){
    	cin >> perm[i];
    	perm[i]--;
    	b[i] = b_[perm[i]];
    }

    for(int i = 0; i < n; ++i){
    	if(perm[i] != i and b[i] >= a[i]){
    		cout << -1 << el;
    		return;
    	}
    }

    // 1 3 3 5
    // 3 4 2 1
    // 1 -> 3 -> 2 -> 4 -> 1;
    vector <pi> ans;
    vector <bool> vis(n);
    for(int i = 0; i < n; ++i){
    	if(vis[i]){
    		continue;
    	}
    	vi cyc;
    	int j = i;
    	while(vis[j] == false){
    		cyc.pb(j);
    		vis[j] = true;
    		j = perm[j];
    	}

    	int sz = SZ(cyc);

    	int mnj = 0;
    	for(int j = 1; j < sz; ++j){
    		if(b[cyc[j]] < b[cyc[mnj]]){
    			mnj = j;
    		}
    	}

    	for(int j = 1; j <= sz - 1; ++j){
    		int l = (mnj - j + sz) % sz;
    		int r = (l + 1) % sz;
    		ans.pb({cyc[l], cyc[r]});
    	}
    }

    cout << SZ(ans) << el;
    for(pi op : ans){
    	cout << op.F + 1 << " " << op.S + 1 << el;
    }
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