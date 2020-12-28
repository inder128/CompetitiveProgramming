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

// https://www.codechef.com/COOK124A/problems/COMMCHA
// divide and conquer DP;

#warning TODO
const int N = 1e5;
vector <double> f(N + 1), fSum(N + 1);

double cost(int l, int r){
	return (fSum[r - 1] - (l ? fSum[l - 1] : 0)) / f[r];
}


struct lr{
	// to compute range;
	int tl, tr;

	// available range;
	int al, ar;
};


void solve(){
    int n, k; cin>>n>>k;
    for(int i = 0; i < n + 1; ++i){
    	cin>>f[i];
    	if(i == 0){
    		fSum[i] = f[i];
    	}
    	else{
    		fSum[i] = fSum[i - 1] + f[i];
    	}
    }


    vector <double> DP(n + 1, 1e18);
    DP[0] = 0;

    for(int i = 1; i <= k + 1; ++i){
    	vector <double> newDP(n + 1, 1e18);
    	newDP[0] = 0;

    	stack <lr> dnc;
    	
    	// newDP[0] is already computed;
    	dnc.push({1, n, 0, n});

    	while(dnc.size()){
    		auto tp = dnc.top(); dnc.pop();

    		int m = (tp.tl + tp.tr) >> 1;

    		// db(tp.tl, tp.tr, m);

    		int oj = -1;
    		for(int j = tp.al; j < min(m, tp.ar + 1); ++j){
    			if(DP[j] + cost(j, m) < newDP[m]){
    				newDP[m] = DP[j] + cost(j, m);
    				oj = j;
    			}
    		}

    		assert(oj >= 0);
    		if(tp.tl <= m - 1){
    			dnc.push({tp.tl, m - 1, tp.al, oj});
    		}
    		if(m + 1 <= tp.tr){
    			dnc.push({m + 1, tp.tr, oj, tp.ar});
    		}
    	}

    	DP = newDP;
    }


    cout<<setprecision(12)<<fixed<<DP[n]<<el;
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