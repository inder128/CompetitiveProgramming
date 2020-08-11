#include <bits/stdc++.h>
using namespace std;
 
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
template<class T> ostream& operator<<(ostream &os, multiset<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ "; for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") "; return os<<"}"; }
    #define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " |"; __f(comma + 1, args...); }
#define rng(x) x.begin(), x.end()
#define pb push_back
#define F first
#define S second
#define el '\n'
 
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<bool> vb;
 
/*-----------------------------Code begins----------------------------------*/

// https://codeforces.com/contest/1268/problem/B
// two solutions;


// void solve(){
//     int n; cin>>n;
//     vi a(n); for (int &i : a) cin>>i;

//     ll b = 0, w = 0, sm;
//     for (int i = 0; i < n; ++i){
//         if(i%2 == 0){ // bwb
//             w += a[i]/2;
//             b += a[i]/2 + a[i]%2;
//         }
//         else{ // wbw
//             w += a[i]/2 + a[i]%2;
//             b += a[i]/2;
//         }
//     }

//     cout<<min(b, w)<<el;
// }


void solve(){
    int n; cin>>n;
    vi a(n); for (int &i : a) cin>>i;

    stack <int> stk;
    ll sm = 0;
    for (int i = 0; i < n; ++i){
        sm += a[i];
        if(stk.empty() or stk.top()%2 != a[i]%2)
            stk.push(a[i]);
        else 
            stk.pop();
    }
    int bad = 0;
    while(!stk.empty()){
        bad += stk.top()%2;
        stk.pop();
    }

    cout<<(sm - bad)/2<<el;
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


// if(a[i-1]%2 == a[i]%2)
//             DP[i] = DP[i-2];
//         else if(a[i]%2)
//             DP[i] = 