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

// https://codeforces.com/gym/101653
// number game;

void solve(){
    int n; cin >> n;
    vi arr(n); cin >> arr;

    int one = 0;
    for(int i = 0; i < n; ++i){
    	if(arr[i] == 1){
    		one = i;
    	}
    }

    int l;
    if(one > 0 and (one == 1 or arr[one - 1] > arr[one - 2])){
    	l = one - 1;
    	while(l - 1 >= 0 and arr[l - 1] < arr[l]){
    		l--;
    	}
    }
    else{
    	l = one;
    }

    int r;
    if(one < n - 1 and (one == n - 2 or arr[one + 1] > arr[one + 2])){
    	r = one + 1;
    	while(r + 1 < n and arr[r + 1] < arr[r]){
    		r++;
    	}
    }
    else{
    	r = one;
    }

    l = one - l, r = r - one;
    int rem = n - l - r - 1;

    // db(l, r, rem);

    if(n == 1){
    	cout << "Alice" << el;
    }
    else if(one == 0 or one == n - 1){
    	if((l + r) == 0){
    		if(rem % 2){
	    		cout << "Bob" << el;
	    	}
	    	else{
	    		cout << "Alice" << el;
	    	}
    	}
    	else{
	    	if(rem % 2){
	    		cout << "Alice" << el;
	    	}
	    	else{
	    		cout << "Bob" << el;
	    	}
	    }
    }
    else{
    	if(l == 0 and r == 0){
    		if(rem % 2){
	    		cout << "Bob" << el;
	    	}
	    	else{
	    		cout << "Alice" << el;
	    	}
    	}
    	else if(l == 0 or r == 0){
    		l += r;
    		if((l + rem) % 2 == 0){
    			cout << "Alice" << el;
    		}
    		else{
    			cout << "Bob" << el;
    		}
    	}
    	else{
    		l %= 2, r %= 2, rem %= 2;
	    	if(l == r and r == rem and rem == l){
	    		cout << "Bob" << el;
	    	}
	    	else{
	    		cout << "Alice" << el;
	    	}
    	}
    }
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