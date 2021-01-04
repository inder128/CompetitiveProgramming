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
	int n, p; cin >> n >> p;
	vi nums(n); cin >> nums;
	sort(rng(nums));

    int mn = 0, mx = nums.back();
    for(int i = 0; i < n; ++i){
    	maxi(mn, nums[i] - i);
    }

    set <int> invalids;
    for(int i = 0; i < n; ++i){

    	int l = n - max(0, nums[i] - mn), r = n;
    	l -= (n - 1 - i), r -= (n - 1 - i);

    	if(r < p or l > p){
    		continue;
    	}

    	if(r == p){
    		mini(mx, mn + (p - l));
    	}
    	else{
    		invalids.insert(mn + (p - l));
    	}
    }

    vi ans;
   	for(int i = mn; i < mx; ++i){
   		if(invalids.count(i) == 0){
   			ans.pb(i);
   		}
   	}
   	cout << SZ(ans) << el;
   	for(int i : ans){
   		cout << i << " ";
   	}
   	cout << el;
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