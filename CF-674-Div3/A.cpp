#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define maxi(x, y) x = max(x, (y))
#define mini(x, y) x = min(x, (y))
#define pb push_back
#define F first
#define S second
#define el '\n'
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.S << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ "; for(auto m:M) os<<"("<<m.F<<" : "<<m.S<<") "; return os<<"}";}
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef long long ll; typedef pair<int,int> pi; typedef vector <bool> vb;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

int mod = 1e9 + 7;

// combinatorics

void solve(){
    int n; cin>>n;
    string str; cin>>str;

    ll re = count(rng(str), '?'), le = 0;
    ll a = 0, c = count(rng(str), 'c');

    vl pow3(n + 1);
    pow3[0] = 1;
    for (int i = 1; i <= n; ++i){
    	pow3[i] = pow3[i - 1]*3 % mod;
    }

    ll ans = 0;
    for(char s : str){
    	if(s == '?') re--;
    	if(s == 'c') c--;
    	if(s == 'b' or s == '?'){
    		ll lf = ((le ? le*pow3[le - 1] % mod : 0) + a*pow3[le]) % mod;
    		ll rf = ((re ? re*pow3[re - 1] % mod : 0) + c*pow3[re]) % mod;
    		ans += lf*rf % mod;
    		ans %= mod;
    	}
    	if(s == 'a') a++;
    	if(s == '?') le++;
    }

    cout<<ans<<el;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1, tc = 1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
