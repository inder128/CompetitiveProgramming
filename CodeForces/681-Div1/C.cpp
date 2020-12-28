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

const int mod = 998244353;
vi f;
int n;
int get(int pos) {
	int res = 0;
	for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
	    res += f[pos];
	return res;
}
void update(int pos, int val){
	for (; pos < (int)(f.size()); pos = (pos | (pos + 1)))
		f[pos] += val;
}
int getb(int ind){
	int l = 1, r = n, ans;
	while(l <= r){
		int m = (l + r)>>1;
		int id = get(m);
		if(id >= ind){
			r = m - 1;
			if(id == ind) ans = m;
		}
		else{
			l = m + 1;
		}
	}
	return ans;
}


void solve(){
	int k; cin>>n>>k;
    map <int, int> ind, rind;
    f = vi(n + 5);
    for (int i = 1; i <= n; ++i){
    	int x; cin>>x;
    	ind[x] = i;
    	rind[i] = x;
    	update(i, 1);
    }

    vi st(k);
    cin>>st;
    set <int> rem(rng(st));

    int ans = 1;
    for(int val : st){
    	int id = ind[val];
    	int aid = get(id);

    	int lval = -1, rval = -1;
    	if(aid > 1){
    		lval = rind[getb(aid - 1)];
    	}
    	if(aid < n + rem.size() - k){
    		rval = rind[getb(aid + 1)];
    	}

    	if((rem.count(rval) or rval == -1) and (rem.count(lval) or lval == -1)){
    		cout<<"0\n";
    		return;
    	}
    	
    	if(rem.count(rval) == 0 and rval !=-1 and rem.count(lval) == 0 and lval != -1){
    		ans = (ans * 2) % mod;
    	}

    	if(rval != -1 and rem.count(rval) == 0){
			update(getb(aid + 1), -1);
		}
		else{
			update(getb(aid - 1), -1);
		}

    	rem.erase(val);
    }
    cout<<ans<<el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}