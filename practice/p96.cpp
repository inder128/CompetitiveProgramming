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
    int n, k; cin>>n>>k;
    vector <pi> lg;
    vi gsz(n), gcurrsz(n);
    for(int i = 0; i < n; ++i){
    	cin>>gsz[i];
    	for(int j = 0; j < gsz[i]; ++j){
    		int x; cin>>x;
    		lg.pb({x, i});
    	}
    }

    sort(rng(lg));
    int ans = LLONG_MAX, l = 0, gcnt = 0;
    for(int i = 0; i < lg.size(); ++i){
    	gcurrsz[lg[i].S]++;
    	if(gcurrsz[lg[i].S] == gsz[lg[i].S]) gcnt++;

    	while((gcurrsz[lg[l].S] > gsz[lg[l].S]) or 
    		(gcnt > k and gcurrsz[lg[l].S] == gsz[lg[l].S]) or 
    		(gcnt >= k and gcurrsz[lg[l].S] < gsz[lg[l].S])){
    		gcurrsz[lg[l].S]--;
    		if(gcurrsz[lg[l].S] == gsz[lg[l].S] - 1) gcnt--;
    		l++;
    	}

    	if(gcnt >= k){
    		mini(ans, lg[i].F - lg[l].F);
    	}
    }
    cout<<ans<<el;
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