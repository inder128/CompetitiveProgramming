#include <bits/stdc++.h>
using namespace std;
 
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ "; for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") "; return os<<"}"; }
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " |"; __f(comma + 1, args...); }
#define rng(x) x.begin(), x.end()
#define pb push_back
#define F first
#define S second
#define el '\n'
 
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

void solve1(){
	int n; cin>>n;
	vi a(n); for(int &i : a) cin>>i;
	sort(rng(a));
	ll ci1 = pow(a.back(), 1.0/(n-1)), ci2 = ci1 + 1;
	ll s1 = 0, s2 = 0, f1 = 1, f2 = 1;
	for(int i : a) s1 += abs(i - f1), f1 *= ci1;
	for(int i : a) s2 += abs(i - f2), f2 *= ci2;
	cout<<min(s1, s2)<<el;
}

void solve(){
	// at max sm can be (n*10^9 - n) -> when c = 1;
	// when n==1 -> sm will always be a[0] - 1 regardless of c;
	// when n==2 -> 1 c -> abs(a[0] - 1) + abs(a[1] - c) -> so c will be a[i];
	// when n==3 -> c can be atmost 10^5;
	// so n >= 3 check for all possible values of c;
	int n; cin>>n;
	vl a(n); for(ll &i : a) cin>>i;
	sort(rng(a));
	if(n<=2){
		cout<<a[0] - 1<<el;
		// cout<<a[0] - 1 + abs(a[1] - c)<<el;
		// cout<<a[0] - 1 + abs(c - c)<<el;
		return;
	}
	ll lsm = LLONG_MAX, c = 1;
	while(true){
		ll ci = 1, sm = 0;
		for(int i : a){
			sm += abs(i - ci), ci *= c;
			if(sm >= lsm) break;
		} 
		if(sm >= lsm) break;
		lsm = sm;
		c++;
	}
	cout<<lsm<<el;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1, tc = 1;
    // cin>>T; 
    while(T--){
        solve();
    }
    return 0; 
}