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
    int c1, c2, c3, c4;
    cin >> c1 >> c2 >> c3 >> c4;


    if(c1 - c2 >= 2 or c4 - c3 >= 2){
    	cout << "NO" << el;
    	return;
    }

    if(c1 == c2 + 1){
    	if(c3 + c4 == 0){
    		cout << "YES" << el;
    		for(int i = 0; i < c2; ++i){
    			cout << 0 << " " << 1 << " ";
    		}
    		cout << 0 << el;
    		return;
    	}
    	else{
    		cout << "NO" << el;
    		return;
    	}
    }


    if(c4 == c3 + 1){
    	if(c1 + c2 == 0){
    		cout << "YES" << el;
    		for(int i = 0; i < c3; ++i){
    			cout << 3 << " " << 2 << " ";
    		}
    		cout << 3 << el;
    		return;
    	}
    	else{
    		cout << "NO" << el;
    		return;
    	}
    }


    int d21 = c2 - c1, d34 = c3 - c4;


    vi ans;
    if(d21 == d34){
    	for(int i = 0; i < c1; ++i){
    		ans.pb(1);
    		ans.pb(2);
    	}
    	for(int i = 0; i < d21; ++i){
    		ans.pb(3);
    		ans.pb(2);
    	}
    	for(int i = 0; i < c4; ++i){
    		ans.pb(3);
    		ans.pb(4);
    	}
    }
    else if(d21 == d34 + 1){
    	ans.pb(2);
    	for(int i = 0; i < c1; ++i){
    		ans.pb(1);
    		ans.pb(2);
    	}
    	for(int i = 0; i < d34; ++i){
    		ans.pb(3);
    		ans.pb(2);
    	}
    	for(int i = 0; i < c4; ++i){
    		ans.pb(3);
    		ans.pb(4);
    	}
    }
    else if(d21 + 1 == d34){
    	for(int i = 0; i < c1; ++i){
    		ans.pb(1);
    		ans.pb(2);
    	}
    	for(int i = 0; i < d21; ++i){
    		ans.pb(3);
    		ans.pb(2);
    	}
    	for(int i = 0; i < c4; ++i){
    		ans.pb(3);
    		ans.pb(4);
    	}
    	ans.pb(3);
    }
    else{
    	cout << "NO" << el;
    	return;
    }

    cout << "YES" << el;
    for(int i : ans){
    	cout << i - 1 << " ";
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