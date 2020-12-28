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

double dist(double x1, double y1, double x2, double y2){
	double dx = x2 - x1, dy = y2 - y1;
	return sqrt(dx * dx + dy * dy);
}

const double eps = 1e-9;

void solve(){
	int n, h; cin >> n >> h;
	vector <pi> xy(n);
	for(int i = 0; i < n; ++i){
		cin >> xy[i].F >> xy[i].S;
	}
	vector <double> x(n), y(n);
	x[0] = 0, y[0] = -h;
	for(int i = 1, j = n - 2; i < n; ++i, --j){
		x[i] = x[i - 1] + (xy[j + 1].F - xy[j].F);
		y[i] = y[i - 1] + (xy[j].S - xy[j + 1].S);
	}

	double m = y[1] / x[1];
	double ans = dist(x[0], y[0], x[1], y[1]);
	for(int i = 1; i < n - 1; ++i){
		maxi(m, y[i] / x[i]);
		if(abs(m * x[i] - y[i]) < eps and abs((y[i + 1] - y[i]) / (x[i + 1] - x[i]) - m) < eps){
			ans += dist(x[i], y[i], x[i + 1], y[i + 1]);
		}
		else if(m * x[i + 1] < y[i + 1]){
			double mx = (x[i] * y[i + 1] - x[i + 1] * y[i]) / (y[i + 1] - y[i] - m * (x[i + 1] - x[i]));
			ans += dist(mx, m * mx, x[i + 1], y[i + 1]);
		}
	}

	cout << setprecision(12) << fixed << ans << el;
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