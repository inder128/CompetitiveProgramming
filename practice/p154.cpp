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

int get(int x, int y){
	return x == y ? (abs(x) + (x < 0 or x > 1)) : max(abs(x), abs(y));
}


void solve(){
	vi x(3), y(3);
	for(int i = 0; i < 3; ++i){
		cin >> x[i] >> y[i];
	}

	vi x_ = x, y_ = y;
	sort(rng(x_)), sort(rng(y_));
	int xm = x_[1], ym = y_[1];

	for(int i = 0; i < 3; ++i){
		if(pi(x[i], y[i]) == pi(xm, ym)){
			x.erase(x.begin() + i);
			y.erase(y.begin() + i);
			break;
		}
	}

	if(x[0] != xm){
		swap(x[0], x[1]);
		swap(y[0], y[1]);
	}

	int xa = 2 * xm, ya = 2 * ym;
	if(y[0] > ym and x[1] > xm){
		
	}
	else if(y[0] > ym and x[1] < xm){
		xa--;
	}
	else if(y[0] < ym and x[1] > xm){
		ya--;
	}
	else{
		xa--, ya--;
	}

	cout << get(xa, ya) << el;
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