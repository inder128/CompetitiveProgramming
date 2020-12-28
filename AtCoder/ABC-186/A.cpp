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


int EED(int a, int b, int& x, int& y){
    if(b == 0){
        x = 1, y = 0;
        return a;
    }
    int x1, y1;
    int d = EED(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool findAnySolution(int a, int b, int c, int &x, int &y){
	// degenerate case;
	if(a == 0 and b == 0){
		x = y = 0;
		return c == 0;
	}

    int g = EED(abs(a), abs(b), x, y);
    if(c % g){
        return false;
    }

    x *= c / g;
    y *= c / g;
    if(a < 0) x = -x;
    if(b < 0) y = -y;

    return true;
}

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a % b);
}


void solve(){
    int n, r, k; 
    cin >> n >> r >> k;

    int x, y;

    int sol = findAnySolution(k, n, n - r, x, y);

    if(sol == false){
    	cout<<-1<<el;
    }
    else{
    	int diff = n / gcd(k, n);
    	if(x <= 0){
    		x += (-x) / diff * diff + diff;
    	}
    	assert(x > 0);
    	if(x > 0){
    		x %= diff;
    	}
    	assert(x < diff and x > 0);
    	cout<<x<<el;
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