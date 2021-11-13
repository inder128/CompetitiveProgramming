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
template<class T> ostream& operator<<(ostream &os, multiset<T> S){
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
    int d, n, k; cin >> d >> n >> k;
    multiset <int> mx, mn;
    int csm = 0;

    auto add = [&](int h){
        if(SZ(mx) < k){
            mx.insert(h);
            csm += h;
        }
        else{
            int x = *mx.begin();
            if(x >= h){
                mn.insert(h);
            }
            else{
                mx.erase(mx.find(x));
                mx.insert(h);
                csm -= x; csm += h;

                mn.insert(x);
            }
        }
    };
    auto del = [&](int h){
        if(mn.find(h) != mn.end()){
            mn.erase(mn.find(h));
        }
        else{
            mx.erase(mx.find(h));
            csm -= h;

            if(SZ(mn)){
                int x = *mn.rbegin();
                mx.insert(x);
                csm += x;

                mn.erase(mn.find(x));
            }
        }
    };


    vi curr[d + 2];
    for(int i = 0; i < n; ++i){
        int h, l, r; cin >> h >> l >> r;
        curr[l].pb(h);
        curr[r + 1].pb(-h);
    }

    int ans = 0;
    for(int i = 1; i <= d + 1; ++i){
        for(int h : curr[i]){
            if(h > 0){
                add(h);
            }
            else{
                del(-h);
            }
        }
        // db(i, mx, mn, csm);
        maxi(ans, csm);
    }

    cout << ans << el;
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