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
    int m, n, a, b; cin >> m >> n >> a >> b;
    if(a > b){
    	int d = a - b;
    	b = m - (b - 1);
    	a = b - d;
    }

    vi arr(n); cin >> arr;	
    sort(rng(arr)); 

    int l = 0, r = n + 1;
    while(l + 1 < r){
    	int m = (l + r) >> 1;
    	bool sol = true;
    	if(b - m > a){

    	}
    	else{
    		sol = false;
    	}
    	for(int i = m - 1, s = 1; i >= 0 and sol; --i, s++){
	    	if(arr[i] + s <= b - 1){
	    		
	    	}
	    	else{
	    		sol = false;
	    	}
	    }
	    // db(m, sol);
	    if(sol){
	    	l = m;
	    }
	    else{
	    	r = m;
	    }
    }

    cout << l << el;
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