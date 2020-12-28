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

// nice question
// nice editorial
// check tle submission of O(n*log(n)*log(n)) time complexity;
// following code have O(n*log(n)) time complexity

vector <pair <ll, ll>> invs(30);

void calc(vi &arr, int b){
    if(b < 0 or arr.size() < 2) return;
    vi arr0, arr1;
    ll sm = 0, rev = 0;
    int cnt0 = 0, cnt1 = 0;
    for(int a : arr){
        if(a&(1<<b)){
            rev += cnt0;
            cnt1++;
            arr1.pb(a);
        }
        else{
            sm += cnt1;
            cnt0++;
            arr0.pb(a);
        }
    }
    invs[b].F += sm;
    invs[b].S += rev;
    calc(arr0, b-1);
    calc(arr1, b-1);
}

void solve(){
    int n; cin>>n;
    vi arr(n);
    for(int &i : arr) cin>>i;
    calc(arr, 29);

    ll inv = 0, ans = 0;
    for (int i = 0; i < 30; ++i){
        inv += min(invs[i].F, invs[i].S);
        if(invs[i].S < invs[i].F) ans += (1<<i);
    }
    
    cout<<inv<<" "<<ans<<el;
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