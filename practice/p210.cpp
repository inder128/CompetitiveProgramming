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

// https://www.codechef.com/problems/ISS

// for all n upto 1e7;
// make sure to initialise;
const int N = 5e6;
// phi[i] -> no. of integers j such that (j <= i and gcd(j, i) == 1);
vi phi(N + 1); 
void findPHI() {
    iota(rng(phi), 0);    
    for(int i = 2; i <= N; i++){
        if (phi[i] != i) continue;
        // i is a prime;
        for (int j = i; j <= N; j += i){
            phi[j] /= i, phi[j] *= (i - 1);
        }
    }
}

vi gcdSum(N), ans(1e6 + 1);
void preCalc(){
	for(int i = 1; i < N; ++i){
		for(int j = i; j < N; j += i){
			gcdSum[j] += j / i * phi[i];
		}
	}

	for(int k = 1; k <= 1e6; ++k){
		ans[k] = (gcdSum[4 * k + 1] + (4 * k + 1)) / 2 - 1;
	}
}

void solve(){
    int k; cin >> k;
    cout << ans[k] << el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    findPHI();
    preCalc();
    while(T--){
        solve();
    }
    return 0;
}