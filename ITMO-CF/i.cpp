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

// time complexity -> O(50*nlog(n));
int n, k; 
vector <pi> arr;
bool good(double avg){
	vector <double> vals(n);
	for (int i = 0; i < n; ++i){
		vals[i] = arr[i].F - avg * arr[i].S;
	}
	sort(rng(vals), greater<double>());
	double sum = 0;
	for (int i = 0; i < k; ++i){
		sum += vals[i];
	}
	return sum >= 0;
}
void solve(){
	cin>>n>>k;
    arr.resize(n);
    for (int i = 0; i < n; ++i){
    	cin>>arr[i].F>>arr[i].S;
    }
    double l = 0; // >= 0;
    double r = 1e5 + 1; // < 0;
    for (int i = 0; i < 50; ++i){
    	double m = (l + r) / 2;
    	if(good(m)){
    		l = m;
    	}
    	else{
    		r = m;
    	}
    }
    cout<<setprecision(11)<<l<<el;
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