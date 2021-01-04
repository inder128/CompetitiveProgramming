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
    int n, kkk; cin >> n >> kkk;
    string str; cin >> str;

    vi diff(n);
    for(int i = 0; i < n; ++i){
        int j = (i - 1 + n) % n;
        int k = (i + 1) % n;
        if(str[i] != str[j] and str[i] != str[k]){
            diff[i] = 1;
        }
    }

    if(accumulate(rng(diff), 0) < n){
        int kk = kkk - (kkk % 2);
        int s;
        for(int i = 0; i < n; ++i){
            if(diff[i] == 0){
                s = i;
                break;
            }
        }

        auto process = [&](int l, int r){
            int lll = (l - 1 + n) % n;
            int rrr = (r + 1) % n;
            int ln;
            if(r >= l){
                ln = r - l + 1;
            }
            else{ // l > r; // l > r + 1
                ln = n - (l - r - 1);
            }
            for(int i = l, j = r, p = 0; p < min(kk, (ln + 1) / 2); ++p, i = (i + 1) % n, j = (j - 1 + n) % n){
                str[i] = str[lll];
                str[j] = str[rrr];
            }
        };

        int l, r;
        for(int ii = 0; ii < n; ++ii){
            int i = (s + ii) % n;
            int j = (i - 1 + n) % n;
            int k = (i + 1) % n;
            if(diff[i] == 0){
                continue;
            }
            if(diff[j] == 1 and diff[k] == 1){
                continue;
            }
            if(diff[j] == 0){
                l = i;
            }
            if(diff[k] == 0){
                r = i;
                process(l, r);
            }
        }
    }

    string ans = str;
    if(kkk % 2){
        for(int i = 0; i < n; ++i){
            int j = (i - 1 + n) % n;
            int k = (i + 1) % n;
            if(str[i] != str[j] and str[i] != str[k]){
                ans[i] = str[j];
            }
        }
    }
    cout << ans << el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}