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

int con(int x, int y){
    return y - (x==1);
}

void solve(){
    vi adj[4] = {{2}, {2}, {0, 1, 3}, {2}};
    vb occ(4);
    int s, x1, y1, x2, y2, c;
    cin>>s>>x1>>y1>>x2>>y2>>c;
    int p1 = con(x1, y1),  p2 = con(x2, y2);
    // db(p1, p2);
    occ[p1] = occ[p2] = true;
    for (int i = 0; i < c; ++i){
        int x, y; cin>>x>>y;
        occ[con(x, y)] = true;
    }
    int s1 = 1, s2 = 1;
    for (int p : adj[p1]){
        if(occ[p]) continue;
        occ[p] = true;
        p1 = p;
        s1++;
        break;
    }
    for (int p : adj[p2]){
        if(occ[p]) continue;
        occ[p] = true;
        s2++;
        break;
    }
    for (int p : adj[p1]){
        if(occ[p]) continue;
        s1++;
        break;
    }
    cout<<s1-s2<<el;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1, tc = 1;
    cin>>T; 
    while(T--){
        cout<<"Case #"<<tc<<": ";
        tc++;
        solve();
    }
    return 0; 
}