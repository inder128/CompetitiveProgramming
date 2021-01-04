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

const int mod = 1e9 + 7;

void addSelf(int& x, int y){
    x += y;
    while(x >= mod) x -= mod;
    while(x < 0) x += mod;
}

void multSelf(int& x, int y){
    x = x * (y % mod) % mod;
}

int mul[60][60];

void preCalc(){
	for(int i = 0; i < 60; ++i){
		for(int j = 0; j < 60; ++j){
			mul[i][j] = 1;
			multSelf(mul[i][j], (1ll << i));
			multSelf(mul[i][j], (1ll << j));
		}
	}
}


void solve(){
    vvi c11(60, vi(60));
    vvi c10(60, vi(60));
    vi c1(60);
    int n; cin >> n;
    int B = 60;

    vi xi(n); cin >> xi;

    for(int i = 0; i < n; ++i){
    	int x = xi[i];
    	for(int b1 = 0; b1 < B; ++b1){
    		if(x & (1ll << b1)){
    			c1[b1]++;
    		}
    		else{
    			continue;
    		}
    		for(int b2 = 0; b2 < B; ++b2){
    			if(x & (1ll << b2)){
    				c11[b1][b2]++;
    			}
    			else{
    				c10[b1][b2]++;
    			}
    		}
    	}
    }

    int ans = 0;

    for(int i = 0; i < B; ++i){
    	for(int j = 0; j < B; ++j){

    		int ic = c1[i];
    		int jc1 = c10[i][j];
    		int k1 = c1[j];
    		int la = mul[i][j];
  			multSelf(la, ic);
  			multSelf(la, jc1);
  			multSelf(la, k1);
  			addSelf(ans, la);
  			
  			int jc2 = c11[i][j];
  			int k2 = n;

  			la = mul[i][j];

  			multSelf(la, ic);
  			multSelf(la, jc2);
  			multSelf(la, k2);
  			addSelf(ans, la);
    	}
    }

    cout << ans << el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;

    preCalc();

    while(T--){
        solve();
    }
    return 0;
}