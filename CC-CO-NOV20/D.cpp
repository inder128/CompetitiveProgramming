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
    if(n == 2){
    	cout<<1<<el;
    	cout<<1<<" "<<2<<el;
    	return;
    }

    if(k == n * (n - 1) / 2){
    	cout<<k<<el;
    	for (int i = 1; i <= n; ++i){
    		for (int j = i + 1; j <= n; ++j){
    			cout<<i<<" "<<j<<el;
    		}
    	}
    	return;
    }

    if((n - 1) * (n - 2) / 2 < k){
    	cout<<-1<<el;
    	return;
    }

    

    vector <pi> edges;
    for (int i = 1; i < n; ++i){
    	edges.pb({i, 0});
    }

    k = (n - 1) * (n - 2) / 2 - k;

    for (int i = 1; i < n and k; ++i){
    	for (int j = i + 1; j < n and k; ++j){
    		k--;
    		edges.pb({i, j});
    	}
    }

    cout<<edges.size()<<el;
    for(pi eg : edges){
    	cout<<eg.F + 1<<" "<<eg.S + 1<<el;
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}