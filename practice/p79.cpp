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
template<typename T>
istream&operator>>(istream&is,vector<T>&v){for(auto&it:v)is>>it;return is;}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.S << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

// https://codeforces.com/contest/1361/problem/B
// see editorial;
// https://codeforces.com/blog/entry/78355?#comment-636627

// why greedy works :-
// dp[i] -> optimal partition of first i leements if k;
// it follows optimal substructure;

int n, p;
const int mod = 1e9 + 7;

int pow(int t){
	int ans = 1;
	while(ans < n and t--){
		ans *= p;
	}
	return ans;
}

int binpow(int x, int y){
    int z = 1;
    while(y){
        if(y & 1) z = (z * x % mod);
        x = (x * x % mod);
        y >>= 1;
    }
    return z;
}

void solve(){
    cin>>n>>p;
    vi k(n); cin>>k;

    if(p == 1){
    	cout<<(n % 2)<<el;
    	return;
    }

    sort(rng(k), greater<int>());
    int v = 0, ki = 0, i;
    for (i = 0; i < n; ++i){
    	if(v == 0){
    		v = 1, ki = k[i];
    	}
    	else{
    		int mul = pow(ki - k[i]);
    		if(v*mul >= n) break;
    		v *= mul;
    		v--;
    		ki = k[i];
    	} 	
    }

    int ans = v * binpow(p, ki) % mod;

    for (; i < n; ++i){
    	ans -= binpow(p, k[i]);
    	ans += mod;
    	ans %= mod;
    }

    cout<<ans<<el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}