#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define maxi(x, y) x = max(x, (y))
#define mini(x, y) x = min(x, (y))
#define pb push_back
#define F first
#define S second
#define el '\n'
#define ll long long
#define SZ(x) ((int)(x).size()) 
template<typename T>
istream&operator>>(istream&is,vector<T>&v){for(auto&it:v)is>>it;return is;}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.S << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
#ifndef ONLINE_JUDGE 
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define db(...)
#endif
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code Begins--------------------------------*/

const int mod = 1e9 + 7;

void addSelf(int& x, int y){
    x += y;
    while(x >= mod) x -= mod;
    while(x < 0) x += mod;
}

void subSelf(int& x, int y){
    addSelf(x, -y);
}

void multSelf(int& x, int y){
    x = x * 1ll * y % mod;
}


int mxC = 16;
map <array <int, 4>, int> DP;

int get(array <int, 4> state){
	if(DP.count(state)){
		return DP[state];
	}

	int ans, currLast = state[3];

	if(state[currLast] == 0){
		ans = 0;
	}
	else if(state[0] + state[1] + state[2] == 1){
		ans = 1;
	}
	else{
		ans = 0;
		auto newState = state;
		newState[currLast]--;
		for(int last = 0; last < 3; ++last){
			if(last == currLast){
				continue;
			}
			newState[3] = last;
			addSelf(ans, get(newState));
		}
	}

	return DP[state] = ans;
}


void solve(){
    int n, t; cin >> n >> t;
    vi dur(n), ty(n);
    for(int i = 0; i < n; ++i){
    	cin >> dur[i] >> ty[i];
    }

    vi fact(16);
    fact[0] = 1;
    for(int i = 1; i < 16; ++i){
    	fact[i] = i;
    	multSelf(fact[i], fact[i - 1]);
    }

    int ans = 0;
    for(int msk = 0; msk < (1 << n); ++msk){
    	int ct = 0;
    	vi cnt(4);
    	for(int i = 0; i < n; ++i){
    		if(msk & (1 << i)){
    			ct += dur[i];
    			cnt[ty[i]]++;
    		}
    	}
    	if(ct == t){
    		int f = 1;
    		multSelf(f, fact[cnt[1]]);
    		multSelf(f, fact[cnt[2]]);
    		multSelf(f, fact[cnt[3]]);
    		for(int last = 0; last < 3; ++last){
    			int nw = get({cnt[1], cnt[2], cnt[3], last});
    			multSelf(nw, f);
    			addSelf(ans, nw);
    		}
    		// db(msk);
    	}
    }

    cout << ans << el;
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