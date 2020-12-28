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

int n; 
bool valid(int i, int j){
    return i >= 0 and i < n and j >= 0 and j < n;
}

void solve(){
    int m; cin>>n>>m;
    vector <vl> mat(n, vl(n));
    for(auto &v : mat) for(ll &i : v) cin>>i;

    vi primes;
    for(int i = 0; i < m; i++){
        int x; cin>>x; 
        for(int j = 2; j < 100 and x > 1; j++){
            if(x%j == 0){
                x /= j;
                primes.pb(j);
            }
        }
    }


    int ans = INT_MAX;
    for(int pr : primes){
        vvi exp(n, vi(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ll val = mat[i][j];
                while(val % pr == 0){
                    exp[i][j]++;
                    val /= pr;
                }
                if(i==0 and  j==0) continue;
                
                if(i == 0)
                    exp[i][j] += exp[i][j - 1];
                else if(j == 0)
                    exp[i][j] += exp[i - 1][j];
                else 
                    exp[i][j] += min(exp[i - 1][j], exp[i][j - 1]);
            }
        }
        mini(ans, exp[n - 1][n - 1]);
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