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

ll n2(int n){
    return (n*1ll*(n+1))/2;
}

ll get(ll n, ll m){
    ll diff = n2(n) - 2*n2(m);
    if(diff%2) return 0;
    if(diff==0) return n2(m-1) + n2(n-m-1);
    diff /= 2;
    if(diff<0 or diff>n-1) return 0;
    ll ans = 0;
    if(n-diff >= diff){
        if(m>=n-diff) ans = n-m;
        else if(m>=diff) ans = diff;
        else ans = m;
    }
    else{
        int x = diff - m;
        if(m>=diff) ans = n-m;
        else if(m>=n-diff) ans = max(0ll, n-m-x);
        else ans = m;
    }
    // db(n, m, diff, ans);
    return ans;
}

bool calc(vi &v){
    ll sm = 0, tsm = accumulate(rng(v), 0);
    for(int i : v){
        sm += i;
        if(sm == tsm/2) return true;
    }
    return false;
}

ll solve2(int n){
    vi v(n+1);
    iota(rng(v), 0);
    int cnt = 0;
    for (int x = 1; x <= n; ++x){
        for (int y = x + 1; y <= n; ++y){
            swap(v[x], v[y]);
            if(calc(v)) cnt++;
            swap(v[x], v[y]);
        }
    }
    return cnt;
}

void solve(){
    int n; cin>>n;
    if(n%4==1 or n%4==2){
        cout<<0<<el;
        return;
    }
    int m = n/sqrt(2);
    ll ans = get(n, m-1);
    ans += get(n, m);
    cout<<ans<<el;
    // ll ans2 = solve2(n);
    // if(ans2!=ans) db(n, ans, ans2);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=200, tc = 1;
    cin>>T; 
    while(T--){
        solve();
    }
    return 0; 
}