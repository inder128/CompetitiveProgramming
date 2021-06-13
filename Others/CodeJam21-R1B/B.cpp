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
    vi abc(3); cin >> abc;
    int p = 12 * 1ll * 3600 * 1e9;
    for(int i = 0; i < 12 * 3600; ++i){
    	int h = i * 1e9;
    	int m = i * 12 * 1e9;
    	int s = i * 720 * 1e9;
    	h %= p;
    	m %= p;
    	s %= p;

    	vi vv{h, m, s};
    	sort(rng(vv));

    	int d1 = vv[1] - vv[0];
    	int d2 = vv[2] - vv[1];

    	vi pp{0, 1, 2};
    	do{
    		if((abc[pp[1]] - abc[pp[0]] + p) % p == d1 and (abc[pp[2]] - abc[pp[1]] + p) % p == d2){
    			cout << i / 3600 << " " << (i % 3600) / 60 << " " << (i % 60) << " 0" << el;
    			return;
    		}
    	} while(next_permutation(rng(pp)));
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1, tc = 1;
    cin >> T;
    while(T--){
    	cout << "Case #" << tc << ": ";
        solve();
        tc++;
    }
    return 0;
}