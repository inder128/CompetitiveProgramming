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
#define SZ(x) ((double)(x).size()) 
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
typedef pair<double,double> pi; typedef vector<double> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code Begins--------------------------------*/

// https://codeforces.com/contest/793/problem/C

pi get(double l, double r, double m, double v){
    if(v == 0){
        if(m > r or m < l){
            return {0, -1};
        }
        else{
            return {0, 1e9};
        }
    }
    double t1 = (r - m) / v;
    double t2 = (l - m) / v;
    if(t1 > t2){
        swap(t1, t2);
    }
    if(t1 < 0){
        t1 = 0;
    }
    return {t1, t2};
}


void solve(){
    double n; cin >> n; 
    double x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    vi x(n), y(n), vx(n), vy(n);
    for(int i = 0; i < n; ++i){
    	cin >> x[i] >> y[i] >> vx[i] >> vy[i];
    }

    vi tin{0}, tout{1e9};
    for(int i = 0; i < n; ++i){
    	if(vy[i] == 0 and (y[i] == y1 or y[i] == y2)){
            cout << -1 << el;
            return;
        }
        if(vx[i] == 0 and (x[i] == x1 or x[i] == x2)){
            cout << -1 << el;
            return;
        }
        pi ts1 = get(x1, x2, x[i], vx[i]);
        pi ts2 = get(y1, y2, y[i], vy[i]);
        pi t = {max(ts1.F, ts2.F), min(ts1.S, ts2.S)};
        if(ts1.S < 0 or ts2.S < 0 or t.S < t.F){
            cout << -1;
            return;
        }
        tin.pb(t.F), tout.pb(t.S);
    }

    sort(rng(tin)), sort(rng(tout));
    if(tin.back() < tout[0]){
    	cout << setprecision(12) << fixed << tin.back() << el;
    }
    else{
    	cout << -1 << el;
    }
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