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

    vi deg(n); cin>>deg;
    int mxU = max_element(rng(deg)) - deg.begin();

    vector <bool> vis(n);

    if(deg[mxU] >= k){
    	cout<<"2 "<<mxU + 1<<el; cout.flush();
    	int d; cin>>d;
    	vi childs(d); cin>>childs;
        vis[mxU] = true;
	    for (int ch : childs){
	    	cout<<"1 "<<ch<<el; cout.flush();
	    	int d; cin>>d;
            vis[ch - 1] = true;
            for(int i = 0; i < d; ++i){
                int x; cin>>x;
                x--;
                vis[x] = true;
            }
	    }
    }
    
    for (int i = 0; i < n; ++i){
    	if(vis[i]) continue;
    	vis[i] = true;
        cout<<"1 "<<i + 1<<el; cout.flush();
        int d; cin>>d;
        for(int j = 0; j < d; ++j){
            int x; cin>>x;
            x--;
            vis[x] = true;
        }
    }
	
    cout<<"3\n"; cout.flush();
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