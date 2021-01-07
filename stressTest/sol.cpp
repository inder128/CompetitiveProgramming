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
    vi a(n); cin >> a;
    for(int i = 1; i < n; ++i){
        a[i] += a[i - 1];
    }
    auto get = [&](int l, int r){
        if(l > r){
            return 0ll;
        }
        return a[r] - (l ? a[l - 1] : 0);
    };


    int ans = 0;
    for(int i = 0; i < n; ++i){
        int x = a[i];
        if(a[n - 1] < 2 * x){
            break;
        }

        int l = i + 1, r = n;
        // invarients :-
        // get(r, n - 1) < (x or get(i + 1, l - 1))
        // get(l, n - 1) >= (x or get(i + 1, l - 1));
        // highest such l;
        while(l + 1 < r){
            int m = (l + r) >> 1;
            if(get(m, n - 1) >= max(x, get(i + 1, m - 1))){
                l = m;
            }
            else{
                r = m;
            }
        }
        int lastCut = l;

        l = i, r = n - 1;
        // invarients;
        // get(i + 1, l) < x;
        // get(i + 1, r) >= x; 
        // lowest such r;
        while(l + 1 < r){
            int m = (l + r) >> 1;
            if(get(i + 1, m) >= x){
                r = m;
            }
            else{
                l = m;
            }
        }
        int firstCut = r + 1;

        ans += max(0ll, lastCut - firstCut + 1);
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