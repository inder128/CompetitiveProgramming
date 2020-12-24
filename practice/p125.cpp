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


class BIT{
public :
	int n;
	vi f;
	BIT(int n){
		this->n = n;
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
		return get(r) - (l ? get(l - 1) : 0);
	}

	void increase(int pos, int val){
		for (; pos < SZ(f); pos = (pos | (pos + 1))) {
			f[pos] += val;
		}
	}
};


void solve(){
    int n, q; cin>>n>>q;
    vector <BIT> bit(30, BIT(n));
    for(int i = 0; i < n; ++i){
    	int val; cin>>val;
    	for(int b = 0; b < 30; ++b){
    		bit[b].increase(i, val >> b & 1);
    	}
    }
    while(q--){
    	int op; cin>>op;
    	if(op == 1){
    		int i, val; cin>>i>>val;
    		i--;
    		for(int b = 0; b < 30; ++b){
	    		bit[b].increase(i, val >> b & 1);
	    	}
    	}
    	else{
    		int l, r; cin>>l>>r;
    		l--, r--;
    		int ans = 0;
    		for(int b = 0; b < 30; ++b){
	    		ans += (bit[b].get(l, r) % 2) * (1 << b);
	    	}
	    	cout<<ans<<el;
    	}
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