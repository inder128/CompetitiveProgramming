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

const int N = 1<<18, mod = 998244353;
vl ST(2*N), lazy(2*N, -1), ones(N);
int n;

void update(int si, int ss, int se, int dig){
    lazy[si] = dig;
    ST[si] = ((ones[se] - (ss ? ones[ss - 1] : 0) + mod)*dig) % mod;
}

void shift(int si, int ss, int se){
    if(lazy[si] == -1)  return;
    int mid = (ss+se)/2;
    update(si*2 + 1, ss, mid, lazy[si]);
    update(si*2 + 2, mid+1, se, lazy[si]);
    lazy[si] = -1;
}

void updateUtil(int si, int ss, int se, int qs, int qe, int dig){
    if (se < qs || ss > qe) return;

    if (qs <= ss && qe >= se) return update(si, ss, se, dig); 

    shift(si, ss, se);
    int mid = (ss+se)/2;
    updateUtil(2*si + 1, ss, mid, qs, qe, dig);
    updateUtil(2*si + 2, mid+1, se, qs, qe, dig);
    ST[si] = (ST[si*2 + 1] +  ST[si*2 + 2]) % mod;
}

void update(int qs, int qe, int dig){
    return updateUtil(0, 0, n-1, qs, qe, dig);
}

int construct(int si = 0, int ss = 0, int se = n-1){
    if(ss == se) return ST[si] = ones[ss];
    int mid = (ss + se)/2;
    return ST[si] = (construct(2*si + 1, ss, mid) + 
                    construct(2*si + 2, mid + 1, se)) % mod;
}

void solve(){
    int q; cin>>n>>q;
    ones[0] = 1;
    for (int i = 1; i < n; ++i){
        ones[i] = (ones[i-1]*10) % mod;
    }

    construct();
    for (int i = 1; i < n; ++i){
        ones[i] += ones[i-1];
        ones[i] %= mod;
    }

    while(q--){
        int l, r; cin>>l>>r;
        l = n-l, r = n-r;
        char dig; cin>>dig;
        update(r, l, dig-'0');
        cout<<ST[0]<<el;
    }
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