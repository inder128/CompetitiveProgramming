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
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

struct node{
	int c[2];
};

class BitTrie{
public :
	vector <node> trie;
	int D;
	BitTrie(){
		// numbers should be less that (2 ^ D);
		// size of trie containing all elements less than (2 ^ D) will be (2 ^ (D + 1) - 1);
		D = 19;
		trie.pb({{-1, -1}});
	}

	void insert(int k){
		int curr = 0;
		for(int i = D - 1; i >= 0; --i){
			if(trie[curr].c[k >> i & 1] == -1){
				trie[curr].c[k >> i & 1] = SZ(trie);
				trie.pb({{-1, -1}});
			}
			curr = trie[curr].c[k >> i & 1];
		}
	}

	int minXOR(int xr){
		int curr = 0, num = 0;

		for(int i = D - 1; i >= 0; --i){
			if(xr >> i & 1){
				if(trie[curr].c[1] != -1){
					curr = trie[curr].c[1];
					num += (1 << i);
				}
				else{
					curr = trie[curr].c[0];
				}
			}
			else{
				if(trie[curr].c[0] != -1){
					curr = trie[curr].c[0];
				}
				else{
					curr = trie[curr].c[1];
					num += (1 << i);
				}
			}
		}

		return num ^ xr;
	}
};


void solve(){
    int n, q; cin>>n>>q;

    vector <bool> vis(1 << 19);
    for(int i = 0; i < n; ++i){
    	int x; cin>>x;
    	vis[x] = true;
    }

    BitTrie trie;
    for(int i = 0; i < (1 << 19); ++i){
    	// if(vis[i]) continue;
    	trie.insert(i);
    }

    int xr = 0;
    while(q--){
    	int txr; cin>>txr;
    	xr ^= txr;
    	cout<<trie.minXOR(xr)<<el;

    	db(trie.trie.size());
    }
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