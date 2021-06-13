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
const int N = 1e7;
bitset <N + 1> isPrime;
vi cnt(2 * N + 1);
void findPrimes(){
    isPrime.set();
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i * i <= N; ++i){
        if(isPrime[i] == false) continue;
        for(int j = i * i; j <= N; j += i){
            isPrime[j] = false;
        }
    }

    cnt[2] = 1;
    int curr = 0;
    for(int i = 3; i <= N; ++i){
    	if(i > 4 and i % 2 == 0 and isPrime[i / 2]){
    		curr--;
    	}
    	if(isPrime[i]){
    		curr++;
    	}
    	cnt[i] = curr + 1;
    }
}

void solve(){
    int n; cin >> n;
    cout << cnt[n] << el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    findPrimes();
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}