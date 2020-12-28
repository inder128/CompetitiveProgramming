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
template<typename T>
istream&operator>>(istream&is,vector<T>&v){for(auto&it:v)is>>it;return is;}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.S << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

// time complexity -> O(100*n);
// vector <pi> xv;
// int n;
// bool good(double x){
// 	double mn = 0, mx = 0;
// 	for (int i = 0; i < n; ++i){
// 		double tm = (xv[i].F - x) / xv[i].S;
// 		if(tm > 0) maxi(mx, tm);
// 		else maxi(mn, -tm);
// 	}
// 	return mn > mx;
// }
// void solve(){
//     cin>>n;
//     xv.resize(n);
//     for (int i = 0; i < n; ++i){
//     	cin>>xv[i].F>>xv[i].S;
//     }
//     sort(rng(xv));
//     double l = xv[0].F, r = xv.back().F;
//     for (int i = 0; i < 100; ++i){
//     	double m = (l + r) / 2;
//     	// good(m) -> ans in left;
//     	if(good(m)){
//     		r = m;
//     	}
//     	else{
//     		l = m;
//     	}
//     }

//     double t = 0;
//     for (int i = 0; i < n; ++i){
//     	maxi(t, abs(xv[i].F - r) / xv[i].S);
//     }
//     cout<<setprecision(12)<<t<<el;
// }


// time complexity -> O(50*nlog(2*n));
vector <pi> xv;
int n;
bool good(double t){
	vector <pair<double, bool>> se;
	for (int i = 0; i < n; ++i){
		double l = xv[i].F - t * xv[i].S;
		double r = xv[i].F + t * xv[i].S;
		se.pb({l, false});
		se.pb({r, true});
	}
	sort(rng(se));
	int open = 0;
	for (int i = 0; i < 2*n; ++i){
		if(se[i].S == false) open++;
		else open--;
		if(open == n) return true;
	}
	return false;
}
void solve(){
    cin>>n;
    xv.resize(n);
    for (int i = 0; i < n; ++i){
    	cin>>xv[i].F>>xv[i].S;
    }

    double l = 0, r = 1e9;
    for (int i = 0; i < 50; ++i){
    	double m = (l + r) / 2;

    	if(good(m)){
    		r = m;
    	}
    	else{
    		l = m;
    	}
    }

    cout<<setprecision(12)<<r<<el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}