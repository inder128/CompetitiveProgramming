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

// Nice question

// Lucas Theorum :-
// https://en.wikipedia.org/wiki/Lucas%27s_theorem

// oeis series :-
// https://oeis.org/A008302

ll pow2Fact(ll n){
    ll pow2 = 0;
    while(n > 1){
        n >>= 1;
        pow2 += n;
    }  
    return pow2;  
}

inline bool isEvenNcR(ll n, ll r){
    // return pow2Fact(n) - pow2Fact(r) - pow2Fact(n-r);
    // db(n, r);
    // for (int i = 0; i < 60; ++i){
    //     if(!(n&(1ll<<i)) and (r&(1ll<<i)))
    //         return true;
    // }
    // return false;
    return r > (n&r);
}

void solve(){
    ll n, k; cin>>n>>k;
    ll ex = n + k - 1;
    bool pos = isEvenNcR(ex, k), neg = true;
    for (ll j = 1; (j*(3*j - 1))/2 <= k; j++){
        ll uj = (j*(3*j - 1))/2;
        if(!isEvenNcR(ex - uj, k - uj)){
            if(j%2) neg = !neg;
            else pos = !pos;
        }
        if(j + uj <= k and !isEvenNcR(ex - uj - j, k - uj - j)){
            if(j%2) neg = !neg;
            else pos = !pos;
        }
    }
    cout<<(pos == neg ? "0" : "1")<<el;
}

// void solve(){
//     int n = 10;
//     vi vec(n), cnt(n2(n) + 1);
//     iota(rng(vec), 1);
//     do{
//         int inv = 0;
//         for (int i = 0; i < n; i++){
//             for (int j = i+1; j < n; ++j){
//                 inv += vec[j] < vec[i];
//             }
//         }
//         cnt[inv]++;
//     }
//     while(next_permutation(rng(vec)));
//     for (int i = 0; i <= n2(n); ++i){
//         cout<<i<<" : "<<cnt[i]<<el;
//     }
// }
 
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