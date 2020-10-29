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
typedef pair<int,int> pi; typedef vector <bool> vb;
typedef vector<int> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

// https://codeforces.com/contest/935/problem/D
// tricky representation of fraction in modulo inverse;
// se other submission;
// int is long long;
// see editorial -> DP type approach;

const int mod = 1e9 + 7;

int pow(int a, int b){
	int ans = 1;
	while(b){
		if(b % 2) ans = (ans * a) % mod;
		b /= 2;
		a = (a * a) % mod;
	}
	return ans;
}

void solve(){
    int n, m; cin>>n>>m;
    vi s1(n), s2(n);
    cin>>s1>>s2;

    int c0 = count(rng(s1), 0) + count(rng(s2), 0);
    int b0 = 0, rem0 = c0, prob = 0;
    int mul = pow(pow(m, c0), mod - 2);
    for (int i = 0; i < n; ++i){
    	if(s1[i] == 0 and s2[i] == 0){
    		rem0 -= 2;
    		prob = (prob + m*(m - 1)/2 % mod * pow(m, b0 + rem0) % mod * mul) % mod;
    		b0++;
    	}
    	else if(s1[i] == 0){
    		rem0--;
    		prob = (prob + (m - s2[i]) * pow(m, b0 + rem0) % mod * mul) % mod;
    	}
    	else if(s2[i] == 0){
    		rem0--;
    		prob = (prob + (s1[i] - 1) * pow(m, b0 + rem0) % mod * mul) % mod;
    	}
    	else{
    		if(s1[i] > s2[i])
    			prob = (prob + pow(m, b0 + rem0) % mod * mul) % mod;
    		if(s1[i] != s2[i]) break;
    	}
    }
    cout<<prob<<el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1, tc = 1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}