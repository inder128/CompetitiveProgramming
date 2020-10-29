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

void solve(){
    string s, t; cin>>s>>t;
    int x = count(rng(s), '+') - count(rng(s), '-');
    int y = count(rng(t), '+') - count(rng(t), '-');
    int u = count(rng(t), '?');

    if((x - y + u) % 2 or (x - y + u)/2 < 0 or (x - y + u)/2 > u){
    	cout<<"0.000000000000\n";
    	return;
    }
    int r = (x - y + u)/2;

    vi fact(11);
    fact[0] = 1;
    vector <double> powh(11);
    powh[0] = 1.0;
    for (int i = 1; i <= 10; ++i){
    	fact[i] = i*fact[i - 1];
    	powh[i] = powh[i - 1]*0.5;
    }
    
    cout<<fact[u]/(fact[r]*fact[u - r])*powh[u]<<el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    //cin>>T;
    cout<<setprecision(12)<<fixed;
    while(T--){
        solve();
    }
    return 0;
}