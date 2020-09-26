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

// very tough implementation;
// codeforces question link :-
// https://codeforces.com/problemset/problem/1301/D
// different (not easy) implementation in editorial;

vector <pair<int, string>> moves;
bool sol = true;

void solve(){
    int n, m, k; cin>>n>>m>>k;
    int mxMoves = 4*n*m - 2*(n + m);
    if(k > mxMoves){
        sol = false;
        return;
    }

    int inR = min(m-1, k);
    moves.pb({inR, "R"});
    k -= inR;
    if(k==0) return;

    int inL = min(m-1, k);
    moves.pb({inL, "L"});
    k -= inL;
    if(k==0) return;

    int spkLn = 4*(m-1) + 1;
    int spkn = min(k/spkLn, n-1);
    for (int i = 0; i < spkn; ++i){
        moves.pb({m-1, "DRU"});
        moves.pb({1, "D"});
        moves.pb({m-1, "L"});
    }
    k -= spkn*spkLn;
    if(k==0) return;

    
    if(spkn < n-1){
        int sp = min(k/3, m-1);
        moves.pb({sp, "DRU"});
        k -= sp*3;
        if(k==0) return;

        moves.pb({1, "D"});
        k -= 1;
        if(k==0) return;

        if(sp < m-1){
            moves.pb({1, "R"});
            return;
        }

        moves.pb({k, "L"});
    }
    else{
        moves.pb({min(n-1, k), "U"});
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1, tc = 1;
    // cin>>T; 
    while(T--){
        solve();
        if(sol == false) cout<<"NO\n";
        else{
            int cnt = 0;
            for(auto mv : moves)  if(mv.F) cnt++;
            cout<<"YES"<<el<<cnt<<el;
            for(auto mv : moves) 
                if(mv.F) cout<<mv.F<<" "<<mv.S<<el;  
        }
    }
    return 0; 
}