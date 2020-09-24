#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define pb push_back
#define F first
#define S second
#define el '\n'
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.S << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ "; for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") "; return os<<"}";}
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef long long ll; typedef pair<int,int> pi; 
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

// codeforces question link :-
// https://codeforces.com/contest/1295/problem/E
// easy to code but tough to hit;

const int N = 2*(1<<18);
vl ST(N), lazy(N);
int n;

// it should be ll inc not int inc (reason in shift function);
void increase(int si, int ss, int se, ll inc){
	lazy[si] += inc;
	ST[si] += inc;
}

void shift(int si, int ss, int se){
	int mid = (ss+se)/2;
	// brcause lazy[si] is ll; 
	increase(si*2 + 1, ss, mid, lazy[si]);
	increase(si*2 + 2, mid+1, se, lazy[si]);
	lazy[si] = 0;
}

void increaseUtil(int si, int ss, int se, int qs, int qe, int inc){
	if (se < qs || ss > qe) return;

	if (qs <= ss && qe >= se) return increase(si, ss, se, inc); 

	shift(si, ss, se);
	int mid = (ss+se)/2;
	increaseUtil(2*si + 1, ss, mid, qs, qe, inc);
	increaseUtil(2*si + 2, mid+1, se, qs, qe, inc);
	ST[si] = min(ST[si*2 + 1], ST[si*2 + 2]);
}

void increase(int qs, int qe, int inc){
	return increaseUtil(0, 0, n, qs, qe, inc);
}


void solve(){
    cin>>n;
    vi p(n), c(n+1);
    for(int &i : p) cin>>i;
    for (int i = 0; i < n; ++i){
    	cin>>c[p[i]];
    }
    for (int i = 1; i <= n; ++i){
    	increase(i, n, c[i]);
    }

    ll ans = LLONG_MAX;
    for (int i = 0; i < n-1; ++i){
    	increase(p[i], n, -c[p[i]]);
    	increase(0, p[i]-1, c[p[i]]);
    	ans = min(ans, ST[0]);
    }

    cout<<ans<<el;
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