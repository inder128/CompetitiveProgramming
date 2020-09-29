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


// https://codeforces.com/contest/1320/status/C

int n, m, p; 
const int N = 2e6;
vi ST(2*N), lazy(2*N), arr(N, 2e9);
const int mx = 1e6 + 6;

void increase(int si, int ss, int se, int inc){
    lazy[si] += inc;
    ST[si] += inc;
}

void shift(int si, int ss, int se){
    int mid = (ss+se)/2;
    increase(si*2 + 1, ss, mid, lazy[si]);
    increase(si*2 + 2, mid+1, se, lazy[si]);
    lazy[si] = 0;
}

void increaseUtil(int si, int ss, int se, int qs, int qe, int inc){
    if (se < qs || ss > qe) return;

    if (qs <= ss && qe >= se) return increase(si, ss, se, inc); 

    shift(si, ss, se);
    int mid = (ss+se)/2;
    increaseUtil(2*si + 1, ss, mid, qs, qe, inc);
    increaseUtil(2*si + 2, mid+1, se, qs, qe, inc);
    ST[si] = max(ST[si*2 + 1], ST[si*2 + 2]);
}

void increase(int qs, int inc){
    return increaseUtil(0, 0, mx-1, qs, mx-1, inc);
}

int construct(int si = 0, int ss = 0, int se = mx-1){
    if(ss == se) return ST[si] = -arr[ss];

    int mid = (ss + se)/2;
    return ST[si] = max(construct(2*si + 1, ss, mid),
                        construct(2*si + 2, mid + 1, se));
}

void solve(){
    cin>>n>>m>>p;
    vector <pi> w1(n);
    for(pi &p : w1) cin>>p.F>>p.S;
    sort(rng(w1));
    vector <pi> w2(m);
    for(pi &p : w2) cin>>p.F>>p.S;
    sort(rng(w2));
    for (int i = 0; i < m; ++i){
        arr[w2[i].F] = min(arr[w2[i].F], w2[i].S);
    }
    construct();
    vector <pair<pi, int>> mons(p);
    for(auto &ppr : mons) 
        cin>>ppr.F.F>>ppr.F.S>>ppr.S;
    sort(rng(mons));
    int profit = INT_MIN, j = 0;
    for (int i = 0; i < n; ++i){
        while(j < p and mons[j].F.F < w1[i].F){
            increase(mons[j].F.S + 1, mons[j].S);
            j++;
        }
        profit = max(profit, -w1[i].S + ST[0]);
    }
    cout<<profit<<el;
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