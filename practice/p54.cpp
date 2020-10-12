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

// https://www.codechef.com/ICPCIN19/problems/SUMOR

void solve(){
    int n; cin>>n;
    vi arr(n); for(int &i : arr) cin>>i;
    vi per(n); iota(rng(per), 1);
    int ln = n-1;
    while(ln >= 0){
        int i = max_element(arr.begin(), arr.begin() + ln + 1) - arr.begin();
        if(arr[i] == 0) break;
        swap(arr[i], arr[ln]);
        swap(per[i], per[ln]);
        for (int i = 0; i < ln; ++i){
            arr[i] -= (arr[i]&arr[ln]);
        }
        ln--;
    }
    vi cnt(30);
    for (int i = 0; i < n; ++i){
        for (int b = 0; b < 30; ++b){
            cnt[b] += ((arr[i]&(1<<b))!=0);
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i){
        for (int b = 0; b < 30; ++b){
            if(cnt[b])
                ans += (1<<b);
        }
        for (int b = 0; b < 30; ++b){
            cnt[b] -= ((arr[i]&(1<<b))!=0);
        }
    }
    cout<<ans<<el;
    for(int &i : per) cout<<i<<" "; cout<<el;
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