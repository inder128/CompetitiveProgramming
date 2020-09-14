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

int n, mod = 1e9 + 7;

ll get(vl &a){
    vi cnt(31);
    ll ans = 0;
    for(int j = 0; j < n; j++){
        ll e = a[j];
        bool is0 = true;
        for(int i = 0; i < 31; i++){
            if((e&(1<<i)) == 0) continue;
            if(cnt[i]) is0 = false;

        }
        for(int i = 0; i < 31; i++){
            ll ones = (e&(1<<i)) ? j - cnt[i] : cnt[i];
            if(!is0) ans += ones*(1<<i), ans %= mod;
            if(e&(1<<i)) cnt[i]++;
        }
    }
    return ans;
}

void solve(){
    cin>>n;
    vl a(n); for(ll &i : a) cin>>i;
    ll A = get(a);
    reverse(rng(a));
    ll B = get(a);

    cout<<(A + B)%mod<<el;
}


/*
011
110
100
001
110
0 5 9 14 14 = 42

110
001
100
110
011

0 0 7 9 19 = 35
*/
 
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