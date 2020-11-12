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

// nice question;
// https://codeforces.com/edu/course/2/lesson/6/4/practice/contest/285069/problem/B
const int N = 1e5;
int n, m; 
vector <pi> adj[N];

bool good(double avg, bool print = false){

	// single source shortest in DAG using DP;
	vector <double> toReach(n, 1e9), lst(n, -1);
	toReach[0] = 0;
	for (int i = 1; i < n; ++i){
		for(pi ch : adj[i]){
			double cost = toReach[ch.F] + ch.S - avg;
			if(cost < toReach[i]){
				toReach[i] = cost;
				lst[i] = ch.F;
			}
		}
	}

	// we have to find minimal avg such that (toReach[n - 1] == 0);
	// let it be opt;
	// for avery value less that opt toReach[n - 1] will be positive;
	// for avery value less that opt toReach[n - 1] will be negative;
	if(print == false) return toReach[n - 1] < 0;

	int curr = n - 1;
	vi path;
	while(curr != -1){
		path.pb(curr + 1);
		curr = lst[curr];
	}
	reverse(rng(path));
	cout<<path.size() - 1<<el;
	for(int node : path) cout<<node<<" "; cout<<el;

	return true;
}

void solve(){
    cin>>n>>m;
    for (int i = 0; i < m; ++i){
    	int u, v, w; cin>>u>>v>>w;
    	u--, v--;
    	adj[v].pb({u, w});
    }

    // invairents;
    double l = 0;  // >= 0
    double r = 100 * (n - 1) + 1; // < 0

    for (int i = 0; i < 60; ++i){
    	double m = (l + r) / 2;
    	// conditions acc to invarients;
    	if(good(m)){ // optimal avg is in right side;
    		r = m;
    	}
    	else{
    		l = m;
    	}
    }

    good(l, true);
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