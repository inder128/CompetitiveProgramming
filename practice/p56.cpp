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

// https://codeforces.com/contest/1404/problem/C

const int N = 3e5 + 3;
int n;
vi f(N);

ll get(int pos) {
     ll res = 0;
     for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
         res += f[pos];
     return res;
}
void update(int pos, int val){
 for (; pos < int(f.size()); pos = (pos | (pos + 1)))
     f[pos] += val;
}
int max_lower_bound(int k, int r){
    int l = 0, a;
    while(l <= r){
        int m = (l+r)/2;
        if(get(m) >= k) a = m, l = m+1;
        else r = m-1;
    }
    return a;
}

void solve(){
    int q; 
    cin>>n>>q;
    vi arr(n+1);
    for (int i = 1; i <= n; ++i){
        cin>>arr[i];
        arr[i] = i - arr[i];
    }
    vector <pi> st[n+1];
    vi ans(q);
    for (int i = 0; i < q; ++i){
        int x, y; cin>>x>>y;
        st[n - y].pb({x + 1, i});
    }
    update(0, 2*n);
    update(1, -2*n);
    for (int i = 1; i <= n; ++i){
        db(arr[i]);
        if(arr[i] >= 0){
            for (int i = 1; i <= n; ++i){
                cout<<get(i)<<" ";
            }
            cout<<el<<max_lower_bound(arr[i], i)<<el;
            update(max_lower_bound(arr[i], i) + 1, -1);
            update(0, 1);
        }
        for(pi qr : st[i]){
            ans[qr.S] = get(qr.F);
        }
    }

    for(int i : ans) cout<<i<<el;
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