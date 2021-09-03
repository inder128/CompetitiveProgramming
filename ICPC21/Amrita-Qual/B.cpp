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
void __f(const char* name, Arg1&& arg1) { cerr<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code Begins--------------------------------*/

int DP[26][26];


void solve(){
    int n, q; cin >> n >> q;
    for (int i = 0; i < 26; ++i){
    	for (int j = 0; j < 26; ++j){
    		DP[i][j] = 0;
    	}
    }
    vi mx(26);
    for (int k = 0; k < n; ++k){
    	string str; cin >> str;
    	// db(str);
		
		for (int j = 0; j < 26; ++j){
			int t = count(rng(str), (char)('a' + j));
			maxi(mx[j], t);
		}

		vvi dp(26, vi(26));
		for (int i = 0; i < SZ(str); ++i){
			int c = (str[i] - 'a');
			vvi newdp = dp;
			for (int l = 1; l <= 26; ++l){
				for (int s = 0, e = s + l - 1; e < 26; ++s, ++e){
					if(s <= c and c <= e){
						maxi(newdp[s][e], dp[s][c] + 1);
						if(s < 25)
						maxi(newdp[s][e], newdp[s + 1][e]);
						if(e > 0)
						maxi(newdp[s][e], newdp[s][e - 1]);

					}
				}
			}
			dp = newdp;
		}

		if(k == 1){
			// db(dp);
		}


		for (int i = 0; i < 26; ++i){
			for (int j = 0; j < 26; ++j){
				maxi(DP[i][j], dp[i][j]);
			}
		}

		// db(str);
    }

    // db(DP[1][0][2]);

    vvi ed(26, vi(26));
    for (int i = 1; i < 26; ++i){
    	for (int j = 0; j < 26; ++j){
    			for (int s = 0; s <= j; ++s){
    				// db(i, j, k, s);
    				maxi(ed[i][j], ed[i - 1][s] + DP[s][j]);

    				maxi(ed[i][j], ed[i - 1][j]);
    				if(j)
    				maxi(ed[i][j], ed[i][j - 1]);
    			}
    	}
    }

    // db('x');

    vvi st(26, vi(26));
    for (int i = 1; i < 26; ++i){
    	for (int j = 25; j >= 0; --j){
    			for (int e = 25; e >= j; --e){
    				maxi(st[i][j], st[i - 1][e] + DP[j][e]);
    				maxi(st[i][j], st[i - 1][j]);
    				if(j < 25)
    				maxi(st[i][j], st[i][j + 1]);
					
    			}
    	}
    }

    // db('x');



    int ans = 0;
    for (int i = 0; i < 26; ++i){
    	for (int l = 0; l < 26; ++l){
    		for (int r = 0; r < 26; ++r){
    			if((l + r) <= q){
    				maxi(ans, ed[l][i] + st[r][i] + (q - l - r) * mx[i]);
    				
    			}

    		}
    	}
    }

    cout << ans << el;
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