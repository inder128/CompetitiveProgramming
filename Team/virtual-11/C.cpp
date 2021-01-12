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
    int n, a, b; cin >> n >> a >> b;
    vi arr(n); cin >> arr;

    vi primes;
    for(int j : {0ll, n - 1}){
    	for(int x : {arr[j] - 1, arr[j], arr[j] + 1}){
    		for(int i = 2; i * i <= x; i++){
    			if(x % i) continue;
    			primes.pb(i);
    			while(x % i == 0){
    				x /= i;
    			}
    		}
    		if(x > 1){
    			primes.pb(x);
    		}
    	}
    }
    sort(rng(primes));
    primes.resize(unique(rng(primes)) - primes.begin());


    auto get = [&](int p){
    	vi pre(n + 1, 1e18);
    	pre[0] = 0;	
    	for(int i = 1; i <= n and pre[i - 1] < 1e18; ++i){
    		if(arr[i - 1] % p == 0){
	    		pre[i] = pre[i - 1];
	    	}
	    	else if((arr[i - 1] - 1) % p == 0 or (arr[i - 1] + 1) % p == 0){
	    		pre[i] = pre[i - 1] + b;
	    	}
    	}
    	pre.erase(pre.begin());
    	return pre;
    };

    int ans = 1e18;
    for(int p : primes){
    	vi pre = get(p);
    	reverse(rng(arr));
    	vi suf = get(p);
    	reverse(rng(arr));

    	for(int l = 1; l <= n; ++l){
    		mini(ans, pre[l - 1] + (n - l) * a);
    		mini(ans, suf[l - 1] + (n - l) * a);
    	}

    	reverse(rng(suf));

    	// db(p);
    	// db(pre, suf);

    	for(int i = 0; i < n; ++i){
    		pre[i] -= i * a;
    	}

    	int l = 0;
    	for(int i = 1; i < n - 1; ++i){
    		if(pre[i] < pre[l]){
    			l = i;
    		}
    		mini(ans, pre[l] + i * a + suf[i + 1]);
    	}
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