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

const int mod = 998244353;

void solve(){
    int n; cin>>n;
    vi a(n); cin>>a;
    if(n == 1){
    	cout<<a[0]<<el;
    }
    else if(n == 2){
    	cout<<3*a[0] + a[1]<<el;
    }
    else{
    	vi pow2(n);
    	pow2[0] = 1;
    	for (int i = 1; i < n; ++i){
    		pow2[i] = 2 * pow2[i - 1] % mod;
    		a[i] = (a[i] + a[i - 1]) % mod;
    	}
    	int sm = a[n - 1] + 2*a[n - 2];
    	for (int i = 1; i <= n - 2; ++i){
    		sm += a[i - 1] * (n - i + 3) % mod * pow2[n - i - 2] % mod;
    		sm %= mod;
    	}
    	cout<<sm<<el;
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}