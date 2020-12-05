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
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

// https://www.codechef.com/problems/FRCTNS
// see tle submissions;
// nice question;
// fast way to find divisors;

const int N = 1e6;
vi divs[N + 1], spf(N + 1, -1);

void sieve(){
	for(int i = 2; i <= N; ++i){
		if(spf[i] != -1) continue;
		spf[i] = i;
		for(int j = i * i; j <= N; j += i){
			spf[j] = i;
		}
	}
}

// this way of computing divisors is faster that normal linear sieve way;
void getDivisors(vi &div, int n){
	map <int, int> prPow;
	while(n != 1){
		prPow[spf[n]]++;
		n /= spf[n];
	}
	div.pb(1);
	for(auto prPowPr : prPow){
		int lastSz = SZ(div);
		for(int i = 0; i < lastSz * prPowPr.S; ++i){
			div.pb(div[i] * prPowPr.F);
		}
	}
	sort(rng(div));
}


void solve(){
	sieve();
    int n; cin>>n;
    for(int i = 1; i <= n; ++i){
    	getDivisors(divs[i], i);
    }

    int ans = 0;
    for(int i = 1; i < n; ++i){
    	int mxD = n - i;

    	// two pointers;
    	int r = SZ(divs[i + 1]) - 1;
    	for(int l = 0; l < SZ(divs[i]) and divs[i][l] <= mxD; ++l){
    		while(r >= 0 and divs[i][l] * 1ll * divs[i + 1][r] > mxD){
    			r--;
    		}
    		ans += r + 1;
    	}

    	// binary search;
    	// for(auto di : divs[i]){
    	// 	if(di > mxD) break;
    	// 	ans += upper_bound(rng(divs[i + 1]), mxD / di) - divs[i + 1].begin();
    	// }
    }

    cout<<ans<<el;
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