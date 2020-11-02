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

// weird code;
const int mod = 998244353;
int n, inv100; 
vi prob;

int pow(int x, int y){
    int ans = 1;
    while(y){
        if(y % 2) ans = ans * x % mod;
        y /= 2;
        x = x * x % mod;
    }
    return ans;
}

int inv(int n){
    return pow(n, mod - 2);
}

pi get(int i){
	if(i == n){
		return {0, 0};
	}
	pi p = get(i + 1);

	// 1 + prob[i]/100*(p) + ((100 - prob[i])/100)*x;
	// 1 + prob[i]/100*(p.F*x + p.S) + ((100 - prob[i])/100)*x;
	// 1 + prob[i]/100*p.F*x + p[i]/100*p.S + ((100 - prob[i])/100)*x;
	// (prob[i]/100*p.F + ((100 - prob[i])/100))*x + (1 + prob[i]/100*p.S);
	int a = prob[i] * inv100 % mod * p.F + (100 - prob[i]) * inv100 % mod;
	int b = 1 + prob[i] * inv100 % mod * p.S;

	// a*x + b;
	return {a % mod, b % mod};
}

void solve(){
    cin>>n;
    prob = vi(n);
    cin>>prob;
    inv100 = inv(100);

    pi p = get(0);

    // x = p.F*x + p.S;
    // x*(1 - p.F) = p.S;
    cout<<p.S * inv((1 - p.F + mod) % mod) % mod<<el;
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