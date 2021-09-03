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


int get(int n){
	if(n % 2 == 1){
		return 1e9;
	}
	int k = 0;
    for (int i = 0; i < 30; ++i){
    	if(n >> i & 1){
    		if(i % 2 == 0){
    			k += 2;
    		}
    		else{
    			k += 1;
    		}
    	}
    }
    return k;
}


void solve(){
    int n; cin >> n;
    int x; cin >> x;

    
    int k = get(n);

    for (int i = 0; i < 30; ++i){
    	if((n >> i & 1) == 0){
    		continue;
    	}

    	if((1 << i) <= x){
    		x -= (1 << i);
    		n -= (1 << i);
    	}
    	else if(i % 2 == 0 and i and (1 << (i - 1)) <= x){
    		x -= (1 << (i - 1));
    		n -= (1 << (i - 1));
    	}
    }

    mini(k, get(n) + 1);
    if(k == 1e9){
    	k = -1;
    }

    cout << k << el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}