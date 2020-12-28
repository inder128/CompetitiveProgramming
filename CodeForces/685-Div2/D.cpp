#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define maxi(x, y) x = max(x, (y))
#define mini(x, y) x = min(x, (y))
#define pb push_back
#define F first
#define S second
#define el '\n'
#define int long long
template<typename T>
istream&operator>>(istream&is,vector<T>&v){for(auto&it:v)is>>it;return is;}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.S << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

// https://codeforces.com/contest/1451/problem/E2
// nice interactive;

void solve(){
    int n; cin>>n;

    int u = -1, v = -1, c = -1;
    vi xr(n + 1);
    for (int i = 2; i <= n; ++i){
        cout<<"XOR 1 "<<i<<el; cout.flush();
        cin>>xr[i];
        if(xr[i] == 0){
            u = 1, v = i;
        }
        if(xr[i] == n - 1){
            c = i;
        }
    }

    if(u == -1){
        vector <pi> inds;
        for (int i = 2; i <= n; ++i){
            inds.pb({xr[i], i});
        }
        sort(rng(inds));
        for (int i = 1; i < inds.size(); ++i){
            if(inds[i - 1].F == inds[i].F){
                u = inds[i - 1].S, v = inds[i].S;
                break;
            }
        }
    }

    vi arr(n + 1, -1);
    if(u != -1){
        cout<<"AND "<<u<<" "<<v<<el; cout.flush();
        cin>>arr[u];
        if(arr[1] == -1){
            arr[1] = xr[u]^arr[u];
        }        
    }
    else{
        assert(c != -1);
        // distinct;
        int d = (c == 2 ? 3 : 2);

        // 1, c ,d;
        // arr[1] + arr[c] = n - 1;
        int s1c = n - 1;

        cout<<"AND 1 "<<d<<el; cout.flush();
        int a1d; cin>>a1d;
        // arr[1] + arr[d] = xr[d] + 2*a1d;
        int s1d = xr[d] + 2*a1d;

        cout<<"AND "<<c<<" "<<d<<el; cout.flush();
        int acd; cin>>acd;
        // arr[c] + arr[d] = xr[d]^xr[c] + 2*acd;

        // check wrong submission;
        // precedence;
        int scd = (xr[c] ^ xr[d]) + 2*acd;

        // s1c - s1d = dcd -> arr[c] - arr[d];
        int dcd = s1c - s1d;

        // 2*arr[c] = dcd + scd;
        assert((dcd + scd) % 2 == 0 and (dcd + scd) >= 0);
        arr[c] = (dcd + scd) >> 1;

        arr[1] = xr[c]^arr[c];
    }

    for (int i = 2; i <= n; ++i){
        arr[i] = xr[i]^arr[1];
    }

    cout<<"! "; 
    for (int i = 1; i <= n; ++i){
        cout<<arr[i]<<" ";
    } 
    cout<<el; cout.flush();
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}