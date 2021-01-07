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

// https://codeforces.com/blog/entry/20766

void solve(){
    int n; cin >> n;
    vi arr(n); cin >> arr;
    map <int, int> ord;
    for(int i = 0; i < n; ++i){
    	int x; cin >> x;
    	ord[x] = i;
    }
    vector <pi> ans;
    int cost = 0;
    int zeros = 0;
    for(int i = 0; i < n; ++i){
    	arr[i] = ord[arr[i]];
    	arr[i] -= i;
    	if(arr[i] == 0){
    		zeros++;
    	}
    	cost += abs(arr[i]);
    }
    db(arr);
    cout << cost / 2 << el;
    while(zeros < n){
    	db(arr);
    	int fp = -1;
    	for(int i = 0; i < n; ++i){
    		if(arr[i] < 0){
    			arr[fp] -= i - fp;
    			arr[i] += i - fp;
    			ans.pb({i, fp});
    			swap(arr[i], arr[fp]);
    			zeros += (arr[fp] == 0);
    			zeros += (arr[i] == 0);
    			break;
    		}
    		if(arr[i] > 0){
    			fp = i;
    		}
    	}
    }
    // assert(count(rng(arr), 0) == n);
    cout << SZ(ans) << el;
    cost /= 2;
    for(pi p : ans){
    	cout << p.F + 1 << " " << p.S + 1 << el;
    	// cost -= abs(p.F - p.S);
    }
    // assert(cost == 0);
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