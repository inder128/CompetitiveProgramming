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
    vi p(n), q(n); cin >> p;
    for(int i = 0; i < n; ++i){
    	p[i]--;
    }

    auto update = [&](vi nums){
    	int m = SZ(nums);
    	for(int i = 0; i < m; ++i){
    		q[nums[i]] = nums[(i + (m + 1) / 2) % m];
    	}
    };

    auto update2 = [&](vi num1, vi num2){
    	int m = SZ(num1);
    	for(int i = 0; i < m; ++i){
    		q[num1[i]] = num2[i];
    		q[num2[i]] = num1[(i + 1) % m];
    	}
    };

    map <int, vi> mp;
    vi vis(n);
    for(int i = 0; i < n; ++i){
    	if(vis[i] == true) continue;
    	vi nums;
    	int j = i;
    	while(vis[j] == false){
    		vis[j] = true;
    		nums.pb(p[j]);
    		j = p[j];
    	}
    	int m = SZ(nums);
    	if(m % 2){
    		update(nums);
    	}
    	else if(mp.count(m)){
    		update2(mp[m], nums);
    		mp.erase(m);
    	}
    	else{
    		mp[m] = nums;
    	}
    }

    if(SZ(mp)){
    	cout << -1 << el;
    	return;
    }

    for(int i = 0; i < n; ++i){
    	assert(p[i] == q[q[i]]);
    }

    for(int i = 0; i < n; ++i){
    	cout << q[i] + 1 << " ";
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