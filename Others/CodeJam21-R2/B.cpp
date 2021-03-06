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

// make sure to initialise;
const int N = 1e6;
vi spf(N + 1); // shortest prime factor;
vi mx(N + 1);
void findSPF(){
    iota(rng(spf), 0);
    spf[0] = spf[1] = 0;
    for(int i = 2; i * i <= N; ++i){
        if(spf[i] != i) continue;
        for(int j = i * i; j <= N; j += i){
            if(spf[j] != j) continue;
            spf[j] = i;
        }
    }

    for(int i = 2; i <= N; ++i){
    	mx[i] = 1;
    	for(int j = 2; j * j <= i; ++j){
    		if(i % j) continue;
    		maxi(mx[i], mx[i / j - 1] + 1);
    		maxi(mx[i], mx[j - 1] + 1);
    	}
    }
}


void solve(){
    int n; cin >> n;
    int ans = 1;
    for(int i = 3; i * i <= n; ++i){
    	if(n % i) continue;
    	maxi(ans, mx[n / i - 1] + 1);

    	if(n / i < 3) continue;
    	maxi(ans, mx[i - 1] + 1);
    }
    cout << ans << el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1, tc = 1;
    findSPF();
    cin >> T;
    while(T--){
    	cout << "Case #" << tc << ": ";
    	tc++;
        solve();
    }
    return 0;
}