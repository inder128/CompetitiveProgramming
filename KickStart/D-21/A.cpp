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
    int a, b, c; cin >> a >> b >> c;
    int d, f; cin >> d >> f;
    int g, h, i; cin >> g >> h >> i;

    map <int, int> mp;

    int ans = 0;
    ans += b == ((a + c) / 2.0);
    ans += h == ((g + i) / 2.0);
    ans += d == ((a + g) / 2.0);
    ans += f == ((c + i) / 2.0);


    vector <pi> pnts = {{a, i}, {c, g}, {b, h}, {d, f}};
    for (auto [x, y] : pnts){
    	if((x + y) % 2){
    		continue;
    	}
    	mp[(x + y) / 2]++;
    }

    int mx = 0;
    for (auto [x, c] : mp){
    	maxi(mx, c);
    }

    cout << ans + mx << el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1, tc = 1;
    cin >> T;
    while(T--){
    	cout << "Case #" << tc << ": ";
    	tc++;
        solve();
    }
    return 0;
}