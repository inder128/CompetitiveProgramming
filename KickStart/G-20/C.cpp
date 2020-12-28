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

const int N = 5e3;
double DP[N - 1][N - 1];

void solve(){
    int n; cin>>n;
    vi arr(n); for(int &i : arr) cin>>i;

    for (int l = 0; l <= n - 1; ++l){
    	for (int r = 0; r <= n - 1; ++r){
    		DP[l][r] = 0;
    		if(l) DP[l][r] += (l*DP[l - 1][r] + 1)/(l + r);
    		if(r) DP[l][r] += (r*DP[l][r - 1] + 1)/(l + r);
    	}
    }

    double ans = 0;
    for (int i = 0; i < n; ++i){
    	ans += arr[i]*DP[i][n - i - 1];
    }

    cout<<ans<<el;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1, tc = 1;
    cin>>T; 
    cout<<setprecision(9)<<fixed;
    while(T--){
    	cout<<"Case #"<<tc<<": ";
    	tc++;
        solve();
    }
    return 0; 
}