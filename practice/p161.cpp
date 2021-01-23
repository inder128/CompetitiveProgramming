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
#ifndef ONLINE_JUDGE 
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define db(...)
#endif
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code Begins--------------------------------*/

void solve(){
    int n; cin >> n;
    vi a(n); cin >> a;
    if(*max_element(rng(a)) / 2.0 <= *min_element(rng(a))){
    	for(int i = 0; i < n; ++i){
    		cout << -1 << " ";
    	}
    	cout << el;
    	return;
    }

    a.insert(a.end(), rng(a));
    a.insert(a.end(), rng(a));
    deque <int> decInds;
    int l = 0, r = 0;
    vi ans(2 * n);
    while(l < n){
    	while(SZ(decInds) < 2 or a[decInds.front()] / 2.0 <= a[decInds.back()]){
    		while(SZ(decInds) and a[decInds.back()] < a[r]){
    			decInds.pop_back();
    		}
    		decInds.pb(r);
    		r++;
    	}
    	for(int i = l; i <= decInds.front(); ++i){
    		ans[i] = decInds.back() - i;
    	}
    	l = decInds.front() + 1;
    	decInds.pop_front();
    }

    for(int i = 0; i < n; ++i){
    	cout << ans[i] << " ";
    }
    cout << el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}