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

// nice interactive problem;
// https://codeforces.com/contest/1363/problem/D

bool solve(){
    int n, k; cin>>n>>k;
    set <int> inds[k];
    for (int i = 0; i < k; ++i){
    	int sz; cin>>sz;
    	for (int j = 0; j < sz; ++j){
    		int x; cin>>x;
    		inds[i].insert(x);
    	}
    }
    int l = 1, r = 2*n - 1, mx = 0;

    while(l < r){
    	int m = (l + r) >> 1;
    	cout<<"? "<<(m - l + 1)<<" ";
    	for (int i = l; i <= m; ++i){
    		cout<<i<<" ";
    	}
    	cout<<el; cout.flush();
    	int cmx; cin>>cmx;
    	if(cmx == -1){
    		return true;
    	}
    	if(cmx >= mx){
    		r = m;
    		mx = cmx;
    	}
    	else{
    		l = m + 1;
    	}
    }

    vi ans(k);
    for (int i = 0; i < k; ++i){
    	if(inds[i].count(l) == 0){
    		ans[i] = mx;
    	}
    	else{
    		cout<<"? "<<(n - inds[i].size())<<" ";
    		for (int j = 1; j <= n; ++j){
    			if(inds[i].count(j)) continue;
    			cout<<j<<" ";
    		}
    		cout<<el; cout.flush();
    		int lmx; cin>>lmx;
    		if(lmx == -1){
	    		return true;
	    	}
    		ans[i] = lmx;
    	}
    }

    cout<<"! ";
    for(int i : ans) cout<<i<<" "; cout<<el; cout.flush();
    string str; cin>>str;
	if(str == "Incorrect"){
		return true;
	}
	return false;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        bool failed = solve();
        if(failed){
        	return 0;
        }
    }
    return 0;
}