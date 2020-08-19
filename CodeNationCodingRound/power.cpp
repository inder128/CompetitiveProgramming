#include <bits/stdc++.h>
using namespace std;
 
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
template<class T> ostream& operator<<(ostream &os, multiset<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ "; for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") "; return os<<"}"; }
    #define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " |"; __f(comma + 1, args...); }
#define rng(x) x.begin(), x.end()
#define pb push_back
#define F first
#define S second
#define el '\n'
 
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<bool> vb;
 
/*-----------------------------Code begins----------------------------------*/

int n, d; 
const int N = 1e6 + 6;
vl arr(N), rm(N);

bool calc(int val){
    for (int i = 0; i < n+1; ++i){
        rm[i] = 0;
    }
    for (int i = 0; i < n; ++i){
        if(arr[i] <= val){
            rm[max(0, i-d)] -= val;
            rm[min(n, i+d+1)] += val;
        }
    }

    for (int i = 1; i < n; ++i){
        rm[i] += rm[i-1];
    }
    for (int i = 0; i < n; ++i){
        if(arr[i] + rm[i] > 0) return false;
    }
    return true;
}

void solve(){
    cin>>n>>d;
    for (int i = 0; i < n; ++i){
        cin>>arr[i];
    }
    int l = 1, r = 1e9, ans;
    while(l <= r){
        int m = (l+r)/2;
        if(calc(m)) ans = m, r = m-1;
        else l = m + 1;
    }
    cout<<ans<<el;
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