#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define maxi(x, y) x = max(x, (y))
#define mini(x, y) x = min(x, (y))
#define pb push_back
#define F first
#define S second
#define el '\n'
#define ll long long
#define SZ(x) ((int)(x).size()) 
template<typename T>
istream&operator>>(istream&is,vector<T>&v){for(auto&it:v)is>>it;return is;}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.S << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
#ifndef ONLINE_JUDGE 
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define db(...)
#endif
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code Begins--------------------------------*/

vi get(int n, int c){

    if(n == 0){
        return {};
    }

    if(c >= n - 1 + n){
        vi ans = get(n - 1, c - n);

        for(int &i : ans){
            i++;
        }
        reverse(rng(ans));
        ans.pb(1);

        return ans;
    }
    else{
        vi ans(n);

        c -= n - 1;
        int x = 1;
        for(int i = c - 1; i >= 0; --i, x++){
            ans[i] = x;
        }
        for(int i = c; i < n; ++i, x++){
            ans[i] = x;
        }

        return ans;
    }
}

void solve(){
    int n, c; cin >> n >> c;

    if(c < n - 1 or c > n * (n + 1) / 2 - 1){
        cout << "IMPOSSIBLE" << el;
        return;
    }

    vi ans = get(n, c + 1);
    for(int i : ans){
        cout << i << " ";
    }
    cout << el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1, tc = 1;
    cin >> T;
    while(T--){
        cout << "Case #" << tc++ << ": ";
        solve();
    }
    return 0;
}