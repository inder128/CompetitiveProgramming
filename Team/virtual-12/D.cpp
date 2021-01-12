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

void solve(){
    int n, m, d; cin >> n >> m >> d;
    vector <array <int, 3>> tba(m + 1);
    for(int i = 1; i <= m; ++i){
    	cin >> tba[i][2] >> tba[i][1] >> tba[i][0];
    	tba[i][2]--;
    }
    tba[0][0] = 1;
    sort(rng(tba));


    vi DP(n);
    for(int i = 1; i <= m; ++i){
    	vi newDP(n);
    	auto [t, b, a] = tba[i];
    	int dt = t - tba[i - 1][0];

    	deque <int> DQ; // [l, -- -- r);
    	for(int j = 0, l = 0, r = 0; j < n; ++j){
    		int cl = max(0ll, j - dt * d);
    		int cr = min(n - 1, j + dt * d);

    		while(r <= cr){

    			while(SZ(DQ) and DQ.back() < DP[r]){
    				DQ.pop_back();
    			}

    			DQ.push_back(DP[r]);
    			r++;
    		}

    		if(l < cl){
    			if(DP[l] == DQ.front()){
    				DQ.pop_front();
    			}
    			l++;
    		}

    		newDP[j] = DQ.front() + b - abs(a - j);
    	}

    	DP = newDP;
    }

    cout << *max_element(rng(DP)) << el;
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