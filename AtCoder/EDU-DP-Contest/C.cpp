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

const int mod = 1e9 + 7;

void solve(){
    int h, w; cin>>h>>w;
    vector <string> mat(h);
    for(string &s : mat) cin>>s;

    vvi DPu(h, vi(w));
    vvi DPl = DPu, DPr = DPu, DPd = DPu;

    int td = 0;
    for (int i = 0; i < h; ++i){
        for (int j = 0; j < w; ++j){
            if(mat[i][j] == '#') continue;
            DPu[i][j] = (i ? DPu[i - 1][j] : 0) + 1;

            DPl[i][j] = (j ? DPl[i][j - 1] : 0) + 1;

            td++;
        }
    }

    for (int i = h - 1; i >= 0; --i){
        for (int j = w - 1; j >= 0; --j){
            if(mat[i][j] == '#') continue;
            DPd[i][j] = (i < h - 1 ? DPd[i + 1][j] : 0) + 1;

            DPr[i][j] = (j < w - 1 ? DPr[i][j + 1] : 0) + 1;
        }
    }

    vi pow2(h*w + 1);
    pow2[0] = 1;
    for (int i = 1; i <= h*w; ++i){
        pow2[i] = (pow2[i - 1] * 2) % mod;
    }

    int ans = 0;
    for (int i = 0; i < h; ++i){
        for (int j = 0; j < w; ++j){
            if(mat[i][j] == '#') continue;
            int lgtn = DPl[i][j] + DPr[i][j] + DPu[i][j] + DPd[i][j] - 3;
            ans += (pow2[lgtn] - 1) * 1ll * pow2[td - lgtn] % mod;
            ans %= mod;
        }
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