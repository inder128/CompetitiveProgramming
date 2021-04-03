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


    string str; cin >> str;
    int n = SZ(str);
    int x, y; cin >> x >> y;


    if (x > y) {
    	swap(x, y);
    	for (char &c : str) {
    		if (c == '1') {
    			c = '0';
    		}
    		else if (c == '0') {
    			c = '1';
    		}
    	}
    }
    // x <= y;

    int l0 = 0, l1 = 0;
    int ans = 0;

    for(char c : str){
    	if(c == '0'){
    		ans += y * l1;
    		l0++;
    	}
    	else{
    		ans += x * l0;
    		l1++;
    	}
    }

    int r0 = count(rng(str), '0'), r1 = n - r0;
    l0 = 0, l1 = 0;
    int gans = ans;
    for(int i = 0; i < n; ++i){
    	if(str[i] == '?'){
    		// str[i] = '0'
    		r1--;
    		ans -= x * l0 + y * r0;
    		ans += y * l1 + x * r1;
    		mini(gans, ans);
    		l0++;
    	}
    	else if(str[i] == '1'){
    		l1++;
    		r1--;
    	}
    	else{
    		l0++;
    		r0--;
    	}
    }

    cout << gans << el;
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