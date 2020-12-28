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

// minimax algorithm similar to kickstart20RoundF/C.cpp
// but there is DP in following algo;
// and it is a iterative algo


void solve(){
    int n; cin>>n;
    vi arr(n);
    for (int i = 0; i < n; ++i){
        cin>>arr[i];
    }

    vector <vl> DPmn(n, vl(n)), DPmx(n, vl(n));
    for (int i = 0; i < n; ++i){
        DPmx[i][i] = arr[i];
        DPmn[i][i] = -arr[i];
    }

    for (int ln = 2; ln <= n; ++ln){
        for (int l = 0, r = ln - 1; r < n; ++l, ++r){
            DPmx[l][r] = max(arr[l] + DPmn[l + 1][r], arr[r] + DPmn[l][r - 1]);
            DPmn[l][r] = min(-arr[l] + DPmx[l + 1][r], -arr[r] + DPmx[l][r - 1]);
        }
    }

    cout<<DPmx[0][n - 1]<<el;
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