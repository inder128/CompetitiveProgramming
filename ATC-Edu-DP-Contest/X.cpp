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

// nice concept;
// algorithms live and erricto video about exchange arguments;

bool comp(const pair<pi, int> &tow1, const pair<pi, int> &tow2){
    return tow1.F.F + tow1.F.S < tow2.F.F + tow2.F.S;
}

void solve(){
    int n; cin>>n;
    vector <pair<pi, int>> towers(n);
    for(auto &tow : towers) cin>>tow.F.F>>tow.F.S>>tow.S;
    sort(rng(towers), comp);


    vl DP(20001);
    // DP[swt] = max value got when sum of weights is i;

    for (int i = 0; i < n; ++i){
        for (int swt = min(20000, towers[i].F.F + towers[i].F.S); swt >= towers[i].F.F; --swt){
            maxi(DP[swt], DP[swt - towers[i].F.F] + towers[i].S);
        }
    }

    cout<<*max_element(rng(DP))<<el;
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