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

struct node{
    int sz;
	int c[2];
};

class BitTrie{
public :
	vector <node> trie;
	int D;
	BitTrie(){
		// numbers should be less that (2 ^ D);
		// size of trie containing all elements less than (2 ^ D) will be (2 ^ (D + 1) - 1);
		D = 31;
		trie.pb({0, {-1, -1}});
	}

	void insert(int k){
		int curr = 0;
		for(int i = D - 1; i >= 0; --i){
			if(trie[curr].c[k >> i & 1] == -1){
				trie[curr].c[k >> i & 1] = SZ(trie);
				trie.pb({0, {-1, -1}});
			}
			curr = trie[curr].c[k >> i & 1];
            trie[curr].sz++;
		}
	}

	int get(int xr, int ul){
        int curr = 0, ans = 0;

        for(int i = D - 1; i >= 0 and curr != -1; --i){
            int xb = xr >> i & 1, ub = ul >> i & 1;

            if(ub and trie[curr].c[xb] != -1){
                ans += trie[trie[curr].c[xb]].sz;
            }

            curr = trie[curr].c[xb != ub];
        }

        ans += curr != -1;

        return ans;
    }
};


void solve(){
    int n = 1e5; 
    ll k = 1e9; cin >> n >> k; 
    vi a(n); cin >> a;




    int l = -1, r = INT_MAX; // 2 ** 31 - 1


    while(l + 1 < r){
    	int m = (l + 1ll + r) >> 1;

    	BitTrie bt;

    	ll ans = 0;
    	for(int i = 0; i < n; ++i){
    		ans += bt.get(a[i], m);
    		bt.insert(a[i]);
    	}

    	if(ans < k){
    		l = m;
    	}
    	else{
    		r = m;
    	}
    }

    cout << r << el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}