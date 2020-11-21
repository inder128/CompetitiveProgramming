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

// https://codeforces.com/contest/1203/problem/F2
// exchange arguments technique;

void solve(){
    int n, r; cin>>n>>r;
    vector <pi> pos, neg;

    for (int i = 0; i < n; ++i){
    	int h, d; cin>>h>>d;
    	if(d >= 0){
    		pos.pb({h, d});
    	}
    	else{
    		neg.pb({h, d});
    	}
    }
    
    int m = pos.size();
    vector <bool> vis(m);
	sort(rng(pos));
	int c = 0;
	while(c < m){
		int i = 0, mxi = -1;
		while(i < m and pos[i].F <= r){
			if(vis[i] == false and (mxi == -1 or pos[mxi].S < pos[i].S)){
				mxi = i;
			}
			i++;
		}
		if(mxi == -1) break;
		vis[mxi] = true;
		r += pos[mxi].S;
		c++;
	}


	sort(rng(neg), [&](const pi &p1, const pi &p2){
		return p1.F - p2.S > p2.F - p1.S;
	});
	m = neg.size();

	vi DP(r + 1);
	for (int i = 0; i < m; ++i){
		vi newDP = DP;
		for (int left = max(0ll, neg[i].F + neg[i].S); left - neg[i].S <= r; ++left){
			maxi(newDP[left], DP[left - neg[i].S] + 1);
		}
		DP = newDP;
	}


	cout<<(c + *max_element(rng(DP)))<<el;
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