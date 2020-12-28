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
    int n, k; cin >> n >> k;
    string str; cin >> str;

    vi onesCnt(n);
    for(int i = 0; i < n; ++i){
    	if(i == 0){
    		onesCnt[i] = (str[i] == '0');
    	}
    	else{
    		onesCnt[i] = onesCnt[i - 1] + (str[i] == '0');
    	}
    }
    auto check = [&](int l, int r){
    	if(l > r){
    		return false;
    	}
    	else{
    		return (onesCnt[r] - (l ? onesCnt[l - 1] : 0)) > 0;
    	}
    };


    set <int> pre;
    for(int r = k - 1, l = 0; r < n; ++l, ++r){
    	if(check(l, max(r - 20 + 1, l) - 1)){
    		continue;
    	}
    	int num = 0;
    	for(int m = r, i = 0; m >= max(r - 20 + 1, l); --m, ++i){
    		if(str[m] == '0'){
    			num += (1 << i);
    		}
    	}
    	pre.insert(num);
    	// db(num);
    }


    int ln = min(20, k);

    for(int i = 0; i < (1 << ln); ++i){
    	if(pre.count(i)){
    		continue;
    	}
    	cout << "YES" << el;
    	for(int j = 0; j < (k - ln); ++j){
    		cout << "0";
    	}
    	for(int j = ln - 1; j >= 0; --j){
    		if(i & (1 << j)){
    			cout << "1";
    		}
    		else{
    			cout << "0";
    		}
    	}
    	cout << el;
    	return;
    }

    cout << "NO" << el;
    return;
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