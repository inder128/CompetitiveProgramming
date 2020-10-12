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

vi DP(1<<20);

void insert(int msk, int ind){
    if(DP[msk]) return;
    DP[msk] = ind;
    for (int i = 0; i < 20; ++i){
        if((msk & (1<<i)) == 0) continue;
        insert(msk - (1<<i), ind);
    }
}

void solve(){
    fill(rng(DP), 0);
    int n, k; cin>>n>>k;
    string str; cin>>str;
    for (int i = 1; i <= k; ++i){
        string pat; cin>>pat;
        int msk = 0;
        for(char c : pat){
            msk += (1<<(c - 'a'));
        }
        insert(msk, i);
    }
    int msk = 0;
    vi ans(n);
    for (int i = 0; i < n; ++i){
        char c = str[i];
        if(DP[msk | (1<<(c - 'a'))]){
            msk |= (1<<(c - 'a'));
        }
        else{
            ans[i-1] = DP[msk];
            msk = (1<<(c - 'a'));
        }
    }
    ans[n-1] = DP[msk];
    for (int i = n-1; i >= 0; --i){
        if(ans[i]) continue;
        ans[i] = ans[i+1];
    }
    for(int i : ans) cout<<i<<" "; cout<<el;
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