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

void solve(){
    int n; cin>>n;
    vi arr(n+1);
    for (int i = 1; i <= n; ++i){
        cin>>arr[i];
    }

    stack <int> stk;

    vi t1[n+1];
    for (int i = n; i; --i){
        while(stk.size() and arr[stk.top()] < arr[i])
            stk.pop();
        if(stk.size()){
            t1[stk.top()].pb(i);
        }
        stk.push(i);
    }
    while(stk.size()) stk.pop();


    vi t4[n+1];
    for (int i = n; i; --i){
        while(stk.size() and arr[stk.top()] > arr[i])
            stk.pop();
        if(stk.size()){
            t4[stk.top()].pb(i);
        }
        stk.push(i);
    }
    while(stk.size()) stk.pop();


    vi t2(n+1);
    for (int i = 1; i <= n; ++i){
        while(stk.size() and arr[stk.top()] > arr[i])
            stk.pop();
        if(stk.size()) t2[i] = stk.top();
        stk.push(i);
    }
    while(stk.size()) stk.pop();


    vi t3(n+1);
    for (int i = 1; i <= n; ++i){
        while(stk.size() and arr[stk.top()] < arr[i])
            stk.pop();
        if(stk.size()) t3[i] = stk.top();
        stk.push(i);
    }
    while(stk.size()) stk.pop();


    vi DP(n+1, 1e9);
    DP[1] = 0;


    
    for (int i = 1; i <= n; ++i){
        mini(DP[i], DP[t2[i]] + 1);
        mini(DP[i], DP[t3[i]] + 1);

        for(int j : t1[i]){
            mini(DP[i], DP[j] + 1);
        }

        for(int j : t4[i]){
            mini(DP[i], DP[j] + 1);
        }
    }


    cout<<DP[n]<<el;
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