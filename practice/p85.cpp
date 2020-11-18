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
    int n; cin>>n;
    vi queries(2*n);
    for (int i = 0; i < 2*n; ++i){
    	char op; cin>>op;
    	if(op == '+') continue;
    	int x; cin>>x;
        queries[i] = x;
    }

    stack <int> stk;
    vi ans;
    for (int i = 2*n - 1; i >= 0; --i){
    	if(queries[i] == 0){
    		if(stk.empty()){
    			cout<<"NO\n";
    			return;
    		}
    		ans.pb(stk.top());
    		stk.pop();
    	}
    	else{
    		if(stk.empty() or queries[i] < stk.top()){
    			stk.push(queries[i]);
    		}
    		else{
    			cout<<"NO\n";
    			return;
    		}
    	}
    }

    cout<<"YES\n";
    reverse(rng(ans));
    for(int i : ans) cout<<i<<" "; cout<<el;
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