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
// https://codeforces.com/contest/1427/problem/C
// hint in limits;

void solve(){
    int n, r; cin>>r>>n;
    vi DP(n + 1, -1e9), mxDP(n + 1);
   	DP[0] = 0;
    vector <pi> coords(n + 1);
    vi time(n + 1);
    coords[0] = {1, 1};
    for (int i = 1; i <= n; ++i){
    	cin>>time[i];
    	cin>>coords[i].F>>coords[i].S;
    }
    for (int i = 1; i <= n; ++i){
    	int j = i - 1;

    	// it is only possible because r is small;
    	// ********* r being small ans increasing t was a hint to use this **********;
    	// otherwise r could have large;
    	for(; j >= 0 and time[i] - time[j] < 2*r - 2; j--){
    		if(abs(coords[i].F - coords[j].F) + abs(coords[i].S - coords[j].S) <= time[i] - time[j]){
    			maxi(DP[i], DP[j] + 1);
    		}
    	}

    	// it is always possible to reach from positions less than equal to j if this condition is true;
    	if(j >= 0 and time[i] - time[j] >= 2*r - 2) maxi(DP[i], mxDP[j] + 1);
    	mxDP[i] = max(mxDP[i - 1], DP[i]);
    }


    cout<<mxDP[n]<<el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}