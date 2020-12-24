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
    int l = 2, r = 2 * n - 2;
    int mx = 0;
    while(l != r){
    	int m = (l + r) >> 1;
    	cout<<1<<" "<<(m - l + 1)<<" ";
    	cout<<1<<" ";
    	for(int i = l; i <= m; ++i){
    		cout<<i<<" ";
    	}
    	cout<<endl;
    	int dis; cin>>dis;
    	// db(dis, m, mx);
    	if(dis < mx){
    		l = m + 1;
    	}
    	else{
    		mx = dis;
    		r = m;
    	}
    }
    cout<<1<<" "<<n - 1<<" ";
	cout<<l<<" ";
	for(int i = 1; i <= n; ++i){
		if(i == l) continue;
		cout<<i<<" ";
	}
	cout<<endl;
	cin>>mx;
	cout<<-1<<" "<<mx<<endl;
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}