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
    map <string, int> ind;
    int n; cin >> n;
    vector <double> x(n), y(n), z(n);
    for(int i = 0; i < n; ++i){
    	string name; cin >> name;
    	ind[name] = i;
    	cin >> x[i] >> y[i] >> z[i];
    }

    double dist[n][n];

    for(int i = 0; i < n; ++i){
    	for(int j = 0; j < n; ++j){
    		dist[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) + (z[i] - z[j]) * (z[i] - z[j]));
    	}
    }


    int m; cin >> m;

    for(int i = 0; i < m; ++i){
    	string name1, name2; cin >> name1 >> name2;
    	int u = ind[name1], v = ind[name2];
    	dist[u][v] = 0;
    }


    for (int k = 0; k < n; ++k) {
	    for (int i = 0; i < n; ++i) {
	        for (int j = 0; j < n; ++j) {
	            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); 
	        }
	   	}
    }

    int q; cin >> q;
    while(q--){
    	string name1, name2; cin >> name1 >> name2;
    	int u = ind[name1], v = ind[name2];
    	cout << "The distance from " << name1 << " to " << name2 << " is " << (int)(round(dist[u][v])) << " parsecs." << el;
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1, tc = 1;
    cin>>T;
    while(T--){
    	cout << "Case " << tc << ":" << el;
    	tc++;
        solve();
    }
    return 0;
}