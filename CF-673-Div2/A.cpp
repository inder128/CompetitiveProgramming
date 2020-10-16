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

void solve(){
    int n; cin>>n;
    vi lp(n + 1), mnK(n + 1);
    for (int i = 1; i <= n; ++i){
        int x; cin>>x;
        maxi(mnK[x], i - lp[x]);
        lp[x] = i;
    }

    for (int i = 0; i <= n; ++i){
        maxi(mnK[i], n + 1 - lp[i]);
    }
    // db(mnK);

    function <bool(int, int)> comp = [&](int i, int j){
        if(mnK[i] == mnK[j]) return i < j;
        return mnK[i] < mnK[j];
    };

    vi inds(n + 1);
    iota(rng(inds), 0);
    sort(rng(inds), comp);

    // db(inds);

    int lk = 1, mn = INT_MAX;
    for (int i = 0; i <= n; ++i){
        for (; lk < mnK[inds[i]]; ++lk){
            cout<<(mn == INT_MAX ? -1 : mn)<<" ";
        }
        // db(lk);
        mn = mini(mn, inds[i]);
    }
    cout<<el;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1, tc = 1;
    cin>>T; 
    while(T--){
        solve();
    }
    return 0; 
}