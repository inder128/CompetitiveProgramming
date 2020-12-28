#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define pb push_back
#define F first
#define S second
#define el '\n'
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.F << ")"; }
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

void solve(){
    ll n, ans = 0, sm = 0; cin>>n;
    vl a(21);
    for (int i = 1; i <= 20; ++i){
        cout<<"1 "<<(1<<i) - 1<<el; // 1 3 7 15 -----
        cout<<flush;
        cin>>a[i];
    }
    for (int i = 1; i < 20; ++i){
        int bc = (a[i] - a[i+1] + n*(1<<i))/(2*(1<<i));  
        sm += bc*(1<<i);
        if(bc%2) ans += 1<<i;
    }
    
    // a[1] odd -> 00 odd, n odd -> 11 even 
    // a[1] odd -> 00 odd, n even -> 11 odd ++
    // a[1] even -> 00 even, n odd -> 11 odd ++
    // a[1] even -> 00 even, n even -> 11 even
    ans += (a[1]%2 != n%2);
    
    cout<<2<<" "<<ans<<el;
    cout<<flush;
    cin>>n;
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