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

const int N = 100;


char get(char a, char b){
	if(a == b) return a;
	if(a == 'R' and b == 'S') return a;
	if(a == 'S' and b == 'P') return a;
	if(a == 'P' and b == 'R') return a;
	return b;
}


void solve(){
    int n, k; cin>>n>>k;
    char DP[n][k + 1];

    vi pow2modn(k + 1);
    pow2modn[0] = 1 % n;
    for(int i = 1; i <= k; ++i){
    	pow2modn[i] = 2 * pow2modn[i - 1] % n;
    }

	string rps; cin>>rps;

    // DP[i][k] -> winner of rps[i..((i + 2^k - 1) % n)];
    for(int p = 0; p <= k; ++p){
    	for(int i = 0; i < n; ++i){
    		if(p == 0){
    			DP[i][p] = rps[i];
    		}
    		else{
    			DP[i][p] = get(DP[i][p - 1], DP[(i + pow2modn[p - 1]) % n][p - 1]);
    		}
    		// db(DP[i][p], i, p);
    	}
    }

    cout<<DP[0][k]<<el;
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