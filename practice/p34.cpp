#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
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
    os << "{ "; for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") "; return os<<"}";}
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef long long ll; typedef pair<int,int> pi; 
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

// tricky question;
// codeforces question link :-
// https://codeforces.com/problemset/problem/1292/B

ll sx, sy, t;

ll dist(ll x, ll y, ll xt = sx, ll yt = sy){
    return abs(xt - x) + abs(yt - y);
}

int get(vector <pair<ll, ll>> &coords){
    ll tt = t - dist(coords.back().F, coords.back().S);
    int ans = 0, i = coords.size() - 2;
    while(tt >= 0){
        ans++;
        if(i < 0) break;
        tt -= dist(coords[i].F, coords[i].S, coords[i+1].F, coords[i+1].S);
        i--;
    }
    return ans;
}

void solve(){
    ll x, y, ax, ay, bx, by;
    cin>>x>>y>>ax>>ay>>bx>>by;

    cin>>sx>>sy>>t;

    vector <pair <ll, ll>> coords;
    ll lim = 1ll<<62 - 1;
    while((lim - bx)/ax >= x and (lim - by)/ay >= y){
        // db(x, y, dist(x, y));
        if(dist(x, y) <= t) coords.pb({x, y});
        ll nx = x*ax + bx, ny = y*ay + by;
        if(dist(nx, ny) > dist(x, y) and dist(x, y) > t) break;
        x = nx, y = ny;
    }

    // db(coords);
    int ans = 0, n = coords.size();
    for (int l = 0; l < n; ++l){
        for (int m = l; m < n; ++m){
            for (int r = m; r < n; ++r){
                ll stm = dist(coords[m].F, coords[m].S);
                ll mtl = dist(coords[m].F, coords[m].S, coords[l].F, coords[l].S);
                ll mtr = dist(coords[m].F, coords[m].S, coords[r].F, coords[r].S);
                ll ltr = dist(coords[l].F, coords[l].S, coords[r].F, coords[r].S);
                if(stm + mtl + ltr <= t) ans = max(ans, r-l+1);
                if(stm + mtr + ltr <= t) ans = max(ans, r-l+1);
            }
        }
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