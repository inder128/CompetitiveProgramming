#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define maxi(x, y) x = max(x, (y))
#define mini(x, y) x = min(x, (y))
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
    os << "{ "; for(auto m:M) os<<"("<<m.F<<" : "<<m.S<<") "; return os<<"}";}
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef long long ll; typedef pair<int,int> pi; typedef vector <bool> vb;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

// tricky
void solve(){
	int n; cin>>n;
    int r1, s1, p1; cin>>r1>>s1>>p1;
    int r2, s2, p2; cin>>r2>>s2>>p2;

    // mx -> max no of times alice will win;
    int mx = min(r1, s2) + min(s1, p2) + min(p1, r2);

    // mx2 -> max no of times bob wins or match draws;
    int mx2 = min(r2, r1 + s1) + min(s2, s1 + p1) + min(p2, p1 + r1);


    // another way to find minimum :-
    // int misMatch = max(0, r1 + s2 - n) + max(0, s1 + p2 - n) + max(0, p1 + r2 - n);
    /*
	misMatch -> no of games in witch alice beats bob;

	if max(0, r1 + s2 - n) == 0:
		rr------rrss--------sspp---pp
		--pprr--rrss--ssrr--rrpp-----
		then string can always be aligned such that misMatch id 0;
	else:
		no matter how string is aligned, misMatch will be atleast max(0, r1 + s2 - n); 
    */

    cout<<n - mx2<<" "<<mx<<el;
    // cout<<misMatch<<" "<<mx<<el;
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
