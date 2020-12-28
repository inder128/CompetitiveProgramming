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

void solve(){
    int n; cin>>n;
    vi a(n); for(int &i : a) cin>>i;
    vi b(n); for(int &i : b) cin>>i;

    vi s;
    for (int i = 0; i < n; ++i){
        if(b[i]==0) s.pb(a[i]);
    }

    sort(rng(s));
    reverse(rng(s));
    // db(s);

    for (int i = n-1; i >= 0; --i){
        if(b[i]==0){
            a[i] = s.back();
            s.pop_back();
        }
    }

    // int ans = a[0]<0 ? 1 : 0;
    // for (int i = 1; i < n; ++i){
    //     a[i] += a[i-1];
    //     if(a[i]<0) ans = i+1;
    // }

    for(int i : a) cout<<i<<" "; cout<<el;
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