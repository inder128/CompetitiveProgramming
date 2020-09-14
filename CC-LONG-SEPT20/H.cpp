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

void solve(int n){
    vi v;
    for (int i = 1; i <= n; ++i){
        int x = i*i;
        v.pb(x);
    }

    int sm = accumulate(rng(v), 0);
    vvi DP(n+1, vi(sm + 1, -1));
    DP[0][0] = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j <= sm; ++j){
            if(DP[i-1][j] != -1){
                DP[i][j] = j;
                continue;
            }
            if(j >= v[i-1] and DP[i-1][j-v[i-1]] != -1){
                DP[i][j] = j-v[i-1];
            }
        } 
    }

    int ci = n, csm;
    for (int i = sm/2; i >= 0; --i){
        if(DP[n][i] != -1){
            csm = i;
            break;
        }
    }

    vi sset;
    while(ci >= 0){
        if(csm - DP[ci][csm])
            sset.pb(csm - DP[ci][csm]);
        csm = DP[ci--][csm];
    }

    int sm2 = accumulate(rng(sset), 0ll);

    // db(v);
    for(int &i : sset) i = sqrt(i);
    db(sset);
    db(n, abs(sm - 2*sm2), '\n');

}

void solve2(int n){
    vi v;
    for (int i = 1; i <= n; ++i){
        int x = i*i;
        v.pb(x);
    }

    int d = 0;
    int i = n-1;
    while(i>=0){
        if(d<=0) d += v[i];
        else d -= v[i];
        i--;
    }
    db(d);
}


/*
1 4 9 16 25
55
25
*/
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=20, tc = 1;
    // cin>>T; 
    while(T--){
        solve(T+1);
        // solve2(20);
    }
    return 0; 
}