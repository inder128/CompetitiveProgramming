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

// nice question;
// recursive solution will not work beacuse of prefix sum technique in DP array;
// recursive solution will be O(k*k*n), if implemented;
// similar technique is used in kickstart20RoundG/B.cpp

const int mod = 1e9 + 7;

void solve(){
    int n, k; cin>>n>>k;
    vi arr(n + 1);
    for (int i = 1; i <= n; ++i){
        cin>>arr[i];
    }
    
    vi oldDP(k + 1, 1);
    for (int i = 1; i <= n; ++i){
        vi newDP(k + 1);
        for (int j = 0; j <= k; ++j){
            // keep -> 0, 1, 2, 3 ---- min(j, arr[i]);
            // rem -> j, j - 1, j - 2, ---- j - min(j, arr[i]);
            newDP[j] = oldDP[j] - (j > arr[i] ? oldDP[j - arr[i] - 1] : 0);
            newDP[j] = (newDP[j] + mod) % mod;

            // -----
            if(j) newDP[j] = (newDP[j] + newDP[j - 1]) % mod;
        }
        oldDP = newDP;
    }

    // make sure to check for negative value and k == 0;
    cout<<(oldDP[k] - (k ? oldDP[k - 1] : 0) + mod) % mod<<el;
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