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
// https://codeforces.com/contest/1355/problem/E

int n, I, D, S; 
vi h, pre;

int calc(int x){
	int i = upper_bound(rng(h), x) - h.begin() - 1;

	int toInc = (i + 1) * x - pre[i];
	int toDec = (pre.back() - pre[i]) - (n - 1 - i) * x;
	if(toInc >= toDec){
    	return (toInc - toDec) * I + toDec * S;
	}
	else{
		return (toDec - toInc) * D + toInc * S;
	}
}

void solve(){
    cin>>n>>I>>D>>S;
    mini(S, I + D);
    h.resize(n); cin>>h;
    sort(rng(h));
    pre = h;
    for (int i = 1; i < n; ++i){
    	pre[i] += pre[i - 1];
    }

    set <int> breakPoints(rng(h));
    breakPoints.insert(pre.back() / n);
    breakPoints.insert((pre.back() + n - 1) / n);


    int ans = LLONG_MAX;
    for(int bp : breakPoints){
    	mini(ans, calc(bp));
    }

    cout<<ans<<el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}