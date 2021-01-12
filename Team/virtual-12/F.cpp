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
    vi a(n + 1);
    for(int i = 1; i <= n; ++i){
    	cin >> a[i];
    }
    vi l(n + 1, 0), r(n + 1, n + 1);

    stack <int> sdec;
    for(int i = 1; i <= n; ++i){
    	while(SZ(sdec) and a[sdec.top()] <= a[i]){
    		sdec.pop();
    	}
    	if(SZ(sdec)){
    		l[i] = sdec.top();
    	}
    	sdec.push(i);
    }

    stack <int> dec;
    for(int i = n; i >= 1; --i){
    	while(SZ(dec) and a[dec.top()] < a[i]){
    		dec.pop();
    	}
    	if(SZ(dec)){
    		r[i] = dec.top();
    	}
    	dec.push(i);
    }


    vvi l1(n + 1, vi(30));
    for(int i = 2; i <= n; ++i){
    	l1[i] = l1[i - 1];
    	for(int b = 0; b < 30; ++b){
    		if(a[i - 1] >> b & 1){
    			l1[i][b] = i - 1;
    		}
    	}
    }

    vvi r1(n + 1, vi(30));
    r1[n] = vi(30, n + 1);
    for(int i = n - 1; i >= 1; --i){
    	r1[i] = r1[i + 1];
    	for(int b = 0; b < 30; ++b){
    		if(a[i + 1] >> b & 1){
    			r1[i][b] = i + 1;
    		}
    	}
    }

    db(l, r);

    int ans = 0;
    for(int i = 1; i <= n; ++i){
    	int cr = n + 1, cl = 0;

    	for(int b = 0; b < 30; ++b){
    		if((a[i] >> b & 1) == 0){
    			maxi(cl, l1[i][b]);
    			mini(cr, r1[i][b]);
    		}
    	}

    	ans += max(0ll, cl - l[i]) * (r[i] - i);
    	ans += max(0ll, r[i] - cr) * (i - l[i]);
    	ans -= max(0ll, cl - l[i]) * max(0ll, r[i] - cr);
    }


    cout << ans << el;
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