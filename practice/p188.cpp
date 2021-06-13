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

map <int, int> qq;

int q(int k){
	if(qq.find(k) != qq.end()){
		return qq[k];
	}
	cout << "? " << k << endl;
	cin >> qq[k];
	return qq[k];
}

void res(int a){
	cout << "! " << a << endl;
}

void solve(){
    int n; cin >> n;
    if(n == 1){
    	return res(1);
    }


    int f = q(1), s = q(2);
    if(f < s){
    	return res(1);
    }

    f = q(n - 1), s = q(n);
    if(s < f){
    	return res(n);
    }

    int l = 1, r = n;
    while(l + 2 < r){
    	db(l, r);
    	int m = (l + r) >> 1;

    	if(q(m - 1) > q(m) and q(m) < q(m + 1)){
    		l = r = m;
    		break;
    	}

    	if(q(m - 1) < q(m)){
    		r = m;
    	}
    	else{
    		l = m;
    	}
    }


	return res((l + r) >> 1);
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