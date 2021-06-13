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

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a % b);
}

vi v;
int n, a, b;


void run(int i){
	if(i <= 0){
		return;
	}
	if(i > n or v[i] == 0){
		run(i - a);
		run(i - b);
		return;
	}
	v[i]--;
	return;
};



void solve(){
    cin >> n >> a >> b;
    vi u(n + 1);
    for(int i = 1; i <= n; ++i){
    	cin >> u[i];
    }

    int l = n;
    vi d;
    for(int i = n - 1; i ; --i){
    	if(u[i]){
    		d.pb(l - i);
    		l = i;
    	}
    }

    int g = gcd(a, b);

    for(int i : d){
    	if(i % g){
    		cout << "IMPOSSIBLE" << el;
    		return;
    	}
    }

    for(int i = n + g; ; i += g){
    	v = u;
    	run(i);

    	if(accumulate(rng(v), 0) == 0){
    		cout << i << el;
    		return;
    	}
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1, tc = 1;
    cin >> T;
    while(T--){
    	cout << "Case #" << tc << ": ";
        solve();
        tc++;
    }
    return 0;
}