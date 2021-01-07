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

void solve(){
    int n, m; cin >> n >> m;

    map <int, int> mp;
    mp[0] = 3;
    for(int i = 0; i < m; ++i){
        int r, c; cin >> r >> c;
        r--;
        mp[c] += (1 << r);
    }
    if(mp[n] == 0){
        mp[n] = 0;
    }

    int lst = -1;
    vi arr;
    for(pi p : mp){
        if((p.F - lst - 1) % 2){
            arr.pb(0);
        }
        arr.pb(p.S);
        lst = p.F;
    }
    db(arr);

    n = SZ(arr);
    vector <vector <bool>> DP(n, vector <bool>(4));
    DP[0][3] = true;

    for(int i = 1; i < n; ++i){
        if(arr[i] == 0){
            DP[i][0] = DP[i - 1][3];
            DP[i][1] = DP[i - 1][2];
            DP[i][2] = DP[i - 1][1];
            DP[i][3] = DP[i - 1][3];
        }
        if(arr[i] == 1){
            DP[i][0] = false;
            DP[i][1] = DP[i - 1][3];
            DP[i][2] = false;
            DP[i][3] = DP[i - 1][1];
        }
        if(arr[i] == 2){
            DP[i][0] = false;
            DP[i][1] = false;
            DP[i][2] = DP[i - 1][3];
            DP[i][3] = DP[i - 1][2];
        }
        if(arr[i] == 3){
            DP[i][0] = false;
            DP[i][1] = false;
            DP[i][2] = false;
            DP[i][3] = DP[i - 1][3];
        }
    }

    if(DP[n - 1][3]){
        cout << "YES" << el;
    }
    else{
        cout << "NO" << el;
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}