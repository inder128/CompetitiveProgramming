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

void solve () {
    int n, k; cin >> n >> k;
    vi a(n);
    iota(rng(a), 0);

    db(n, k);

    for (int i = n - 1, p = 1; i >= 0; --i, p *= 2) {
    	if(p < k){
    		continue;
    	}

    	if(0){
    		continue;
    	}

    	db(p, i, k);

    	while(k > 1){  
    		db(p);
    		p /= 2;

    		int b = 0;
    		while(k > p){
    			k -= p;
    			p /= 2;
    			maxi(p, 1ll);
    			b++;
    		}

    		db(b, k, p, i);

    		for (int j = i, bb = b; j <= i + b; ++j, bb--){
    			a[j] = i + bb;

    		}

    		i += b + 1;
    	}


    	for (int j = 0; j < n; ++j){
    		cout << a[j] + 1 << " ";
    	}
    	cout << el;

    	return;
    }

    cout << -1 << el;

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