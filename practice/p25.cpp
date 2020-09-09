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
    vector <bool> inc(n+1), taken(n+1);
    set <pi> ord;
    int ptr = n;

    for (int i = 0; i < n-1; ++i){
        int v; cin>>v; 
        if(i==0) cout<<v<<el;
        if(ord.empty() or inc[v]){
            taken[v] = inc[v] = true;
            while(taken[ptr]) ptr--;
            taken[ptr] = true;
            ord.insert({ptr, v});          
        }
        else{
            pi pr = *ord.upper_bound({v, 0});

            cout<<pr.S<<" "<<v<<el;
            taken[v] = inc[v] = true;

            ord.erase(pr);
            pr.S = v;
            if(pr.F == v){
                while(taken[ptr]) ptr--;
                taken[ptr] = true;
                pr.F = ptr;
            }
            ord.insert(pr);
        }
    }
    for(pi pr : ord) cout<<pr.S<<" "<<pr.F<<el;
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