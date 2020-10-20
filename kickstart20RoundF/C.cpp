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

// minimax algorithm similar to ATC-Edu-DP-Contest/J.cpp
// but there is no DP in following algo, we are checking all possiple sequences;
// and it is a recursive algo

vb occ(36);
int s;

int ind(int x, int y){
    return x*x + y;
}

bool valid(int x, int y){
    return (x<s and y<(2*x+1) and x>=0 and y>=0 and !occ[ind(x, y)]);
}

int dfs(int x1, int y1, int s1, int x2, int y2, int s2, bool t1){
    // db(x1, y1, s1, x2, y2, s2, t1);

    vector <pi> n1 = {{x1, y1-1}, {x1, y1+1}};
    vector <pi> n2 = {{x2, y2-1}, {x2, y2+1}};
    if(y1%2) n1.pb({x1-1, y1-1});
    else n1.pb({x1+1, y1+1});
    if(y2%2) n2.pb({x2-1, y2-1});
    else n2.pb({x2+1, y2+1});

    bool e1 = true, e2 = true;
    for(pi p : n1) if(valid(p.F, p.S)) e1 = false;
    for(pi p : n2) if(valid(p.F, p.S)) e2 = false;


    if(e1 and e2) return s1 - s2;

    if(t1){
        if(e1) return dfs(x1, y1, s1, x2, y2, s2, !t1);
        int ans = INT_MIN;
        for(pi p : n1){
            if(!valid(p.F, p.S)) continue;
            occ[ind(p.F, p.S)] = true;
            ans = max(ans, dfs(p.F, p.S, s1+1, x2, y2, s2, !t1));
            occ[ind(p.F, p.S)] = false;
        }
        return ans;
    }
    else{
        if(e2) return dfs(x1, y1, s1, x2, y2, s2, !t1);
        int ans = INT_MAX;
        for(pi p : n2){
            if(!valid(p.F, p.S)) continue;
            occ[ind(p.F, p.S)] = true;
            ans = min(ans, dfs(x1, y1, s1, p.F, p.S, s2+1, !t1));
            occ[ind(p.F, p.S)] = false;
        }
        return ans;
    }
}

void solve(){
    int x1, y1, x2, y2, c;
    cin>>s>>x1>>y1>>x2>>y2>>c;
    x1--, y1--, x2--, y2--;
    fill(rng(occ), false);
    for (int i = 0; i < c; ++i){
        int x, y; cin>>x>>y;
        occ[ind(x-1, y-1)] = true;
    }
    occ[ind(x1, y1)] = occ[ind(x2, y2)] = true;
    cout<<dfs(x1, y1, 1, x2, y2, 1, true)<<el;
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