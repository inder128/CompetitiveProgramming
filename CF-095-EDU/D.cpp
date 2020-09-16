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
    int n, q; cin>>n>>q;
    vi arr(n); for(int &i : arr) cin>>i;
    sort(rng(arr));

    set <int> pos(rng(arr));
    multiset <int> diff;
    diff.insert(0);
    for (int i = 1; i < n; ++i){
        diff.insert(arr[i] - arr[i-1]);
    }

    cout<<arr[n-1] - arr[0] - *diff.rbegin()<<el;

    while(q--){
        int op, p; cin>>op>>p;
        if(op == 0){
            int l = -1, r = -1;
            auto itr = pos.find(p);
            if(itr != pos.begin()) l = *prev(itr);  
            if(next(itr) != pos.end()) r = *next(itr);
            pos.erase(itr);

            if(l!=-1) diff.erase(diff.find(p-l));
            if(r!=-1) diff.erase(diff.find(r-p));
            if(l!=-1 and r!=-1) diff.insert(r-l);
        }
        else{
            int l = -1, r = -1;
            auto itr = pos.upper_bound(p);
            if(itr != pos.begin()) l = *prev(itr);  
            if(itr != pos.end()) r = *itr;
            pos.insert(p);

            if(l!=-1 and r!=-1) diff.erase(diff.find(r-l));
            if(l!=-1) diff.insert(p-l);
            if(r!=-1) diff.insert(r-p);
        }
        if(pos.empty()) cout<<0<<el;
        else cout<<*pos.rbegin() - *pos.begin() - *diff.rbegin()<<el;
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