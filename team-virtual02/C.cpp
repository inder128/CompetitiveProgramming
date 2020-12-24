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

bool solve(){
    int t, n; 
    cin >> t;
    if(t == 0){
    	return true;
    }
    cin >> n;

    vi arr(n); cin >> arr;
    reverse(rng(arr));

    vector <vector <bool>> DP(n + 1, vector <bool>(t + 1));
    DP[0][0] = true;
    for(int i = 1; i <= n; ++i){
    	DP[i] = DP[i - 1];
    	for(int j = arr[i - 1]; j <= t; ++j){
    		DP[i][j] = DP[i][j] | DP[i - 1][j - arr[i - 1]];
    	}
    }

    vi taken;
    int currt;
    for(int i = 0; i <= t; ++i){
    	if(DP[n][i]){
    		currt = i;
    	}
    }

    for(int i = n; i ; --i){
    	if(currt < arr[i - 1] or DP[i - 1][currt - arr[i - 1]] == false){
    		continue;
    	}
    	else{
    		taken.pb(arr[i - 1]);
    		currt -= arr[i - 1];
    	}
    }


    for(int i : taken){
    	cout << i << " ";
    	currt += i;
    }
    cout << currt << el;

    return false;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin>>T;
    while(true){
        if(solve()){
        	break;
        }
    }
    return 0;
}