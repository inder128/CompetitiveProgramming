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

typedef pair <ll, ll> pl;

// intersection of two lines;
double its(pl p1, pl p2){
    return (p1.S - p2.S)/(double)(p2.F - p1.F);
}

// nice question;
// convex hull trick;
// https://cp-algorithms.com/geometry/convex_hull_trick.html


void solve(){
    ll n, C; cin>>n>>C;
    vl h(n);
    for(ll &i : h) cin>>i;

    ll tmpDP = 0;
    vector <pl> lines(1, {-2*h[0], h[0]*h[0]});
    vector <long double> pnts(1, (long double)h[0]);

    for (int i = 1; i < n; ++i){
        int j = lower_bound(rng(pnts), (long double)h[i]) - pnts.begin() - 1;
        tmpDP = lines[j].F*h[i] + lines[j].S  + h[i]*h[i] + C;
        pl ln = {-2*h[i], tmpDP + h[i]*h[i]};

        while(lines.size() >= 2 and its(lines[lines.size() - 2], lines[lines.size() - 1]) >= its(lines[lines.size() - 2], ln)){
            lines.pop_back();
            pnts.pop_back();
        }

        pnts.pb(its(lines.back(), ln));
        lines.pb(ln);
    }
    cout<<tmpDP<<el;
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