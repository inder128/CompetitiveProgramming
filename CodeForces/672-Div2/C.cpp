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

const int N = 300043;
const int MOD = 998244353;

// operation keeping MOD in mind;
int add(int x, int y){
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}

int mul(int x, int y){
    // to avoid overflow;
    return (x * 1ll * y) % MOD;
}

int fact[N];

// return (x raised to power y) % MOD;
int binpow(int x, int y){
    int z = 1;
    while(y){
        if(y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}

int inv(int x){
    return binpow(x, MOD - 2);
}

// return x/y;
int divide(int x, int y){
    return mul(x, inv(y));
}

// array of factorials;
void precalc(){
    fact[0] = 1;
    for(int i = 1; i < N; i++)
        fact[i] = mul(fact[i - 1], i);
}

// returns nCk;
int C(int n, int k){
    if(k > n) return 0;
    return divide(fact[n], mul(fact[k], fact[n - k]));
}

void solve(){
    int n, k; cin>>n>>k;
    vector <pi> lamps(n);
    vi ind;
    for (int i = 0; i < n; ++i){
        cin>>lamps[i].F>>lamps[i].S;
        ind.pb(lamps[i].F);
        ind.pb(lamps[i].S);
    }

    sort(rng(ind));
    ind.resize(unique(rng(ind)) - ind.begin());
    function <int(int)> getID = [&](int a){
        return lower_bound(rng(ind), a) - ind.begin();
    };

    int un = ind.size();
    vi segCnt(un + 1), openSeg(un + 1);
    for (int i = 0; i < n; ++i){
        int l = getID(lamps[i].F);
        int r = getID(lamps[i].S);
        segCnt[l]++, segCnt[r+1]--;
        openSeg[l]++;
    }

    for (int i = 1; i <= un; ++i){
        segCnt[i] += segCnt[i-1];
    }

    int ans = 0;
    for (int i = 0; i <= un; ++i){
        ans = add(ans, (C(segCnt[i], k) - C(segCnt[i] - openSeg[i], k) + MOD) % MOD);
    }

    cout<<ans<<el;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1, tc = 1;
    precalc();
    // cin>>T; 
    while(T--){
        solve();
    }
    return 0; 
}