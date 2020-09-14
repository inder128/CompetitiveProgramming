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

void solve(){
    int n; cin>>n;
    vi sp(n); for(int &i : sp) cin>>i;
    map <pair<double, double>, set<int>> tp; // time, pos
    for (int i = 0; i < n; ++i){
        for (int j = i+1; j < n; ++j){
            if(sp[i]>sp[j]){
                double tm = (double)(j-i)/(sp[i]-sp[j]);
                double pos = i + tm*sp[i];
                tp[{tm, pos}].insert(i);
                tp[{tm, pos}].insert(j);
            }
        }
    }

    // db(tp);

    int mn = n, mx = 0;
    for (int i = 0; i < n; ++i){
        vi vis(n);
        vis[i] = 1;
        for(auto &p : tp){
            int ill = 0;
            set <int> &st = p.S;
            for(int p : st) ill |= vis[p];
            if(ill) for(int p : st) vis[p] = 1;
        }
        int vc = count(rng(vis), 1);
        mx = max(mx, vc);
        mn = min(mn, vc);
    }
    cout<<mn<<" "<<mx<<el;
}
 
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