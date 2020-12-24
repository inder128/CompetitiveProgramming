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


class BIT{
public :
	int n;
	vi f;
	BIT(int n){
		this->n = n + 1000;
		f.assign(n, 0);
	}

	int get(int pos){
		int res = 0;
		for (; pos >= 0; pos = (pos & (pos + 1)) - 1){
		    res += f[pos];
		}
		return res;
	}

	int get(int l, int r){
		return get(r) - get(l - 1);
	}

	void increase(int pos, int val){
		for (; pos < SZ(f); pos = (pos | (pos + 1))) {
			f[pos] += val;
		}
	}
};


void solve(){
    int n, m; cin>>n>>m;

    vi up(m, n), left(n, m);

    vi cols[n];

    int b; cin>>b;

    int l = m, d = n;

    while(b--){
    	int i, j; cin>>i>>j;
    	i--, j--;

    	cols[i].pb(j);

    	mini(up[j], i);
    	mini(left[i], j);

    	if(i == 0){
    		mini(l, j);
    	}
    	if(j == 0){
    		mini(d, i);
    	}
    }

    int ans = 0;
    for(int j = 0; j < l; ++j){
    	ans += up[j];
    	assert(up[j] > 0);
    }


    BIT bit(m);

    // bit.increase(2, 1);
    // bit.increase(1, 1);
    // int x = bit.get(1, 2);
    // db(x);

    for(int j = l; j < m; ++j){
    	bit.increase(j, 1);
    }
    
    for(int i = 0; i < d; ++i){
    	ans += bit.get(0, left[i] - 1);
    	for(int j : cols[i]){
    		if(bit.get(j, j)){
    			continue;
    		}
    		bit.increase(j, 1);
    	}
    }

    cout<<ans<<el;
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