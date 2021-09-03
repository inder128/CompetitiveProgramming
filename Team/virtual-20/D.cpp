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

void solve(){
    int n, m; cin >> n >> m;
    vi a(n); cin >> a;
    vi ans(20);

    set <pi> lr[20];
    auto n2 = [&](int i){
    	return i * (i + 1) / 2;
    };
    auto erase = [&](int i, pi pr){
    	ans[i] -= n2(pr.S - pr.F + 1);
    	lr[i].erase(pr);
    };
    auto insert = [&](int i, pi pr){
    	ans[i] += n2(pr.S - pr.F + 1);
    	lr[i].insert(pr);
    };
    auto add = [&](int i, int j){
    	if(SZ(lr[i]) == 0){
    		insert(i, {j, j});
    		return;
    	}

    	auto prptr = lr[i].upper_bound({j, 0});
    	auto pr = *prptr;

    	if(prptr != lr[i].end() and prptr != lr[i].begin()){
    		auto prp = *prev(prptr);
    		if(prp.S == j - 1 and pr.F == j + 1){
    			erase(i, prp);
    			erase(i, pr);
    			insert(i, {prp.F, pr.S});
    			return;
    		}
    	}

    	if(prptr != lr[i].end() and pr.F == j + 1){
    		erase(i, pr);
    		insert(i, {j, pr.S});
    	}
    	else if(prptr != lr[i].begin() and (*prev(prptr)).S == j - 1){
    		pr = *prev(prptr);
    		erase(i, pr);
			insert(i, {pr.F, j});
    	}
    	else{
    		insert(i, {j, j});
    	}
    };
    auto del = [&](int i, int j){
    	auto prptr = lr[i].upper_bound({j, 1e9});
    	auto pr = *prev(prptr);
    	if(pr.F == j and pr.S == j){
    		erase(i, pr);
    	}
    	else if(pr.F == j){
    		erase(i, pr);
    		insert(i, {j + 1, pr.S});
    	}
    	else if(pr.S == j){
    		erase(i, pr);
    		insert(i, {pr.F, j - 1});
    	}
    	else{
    		erase(i, pr);
    		insert(i, {pr.F, j - 1});
    		insert(i, {j + 1, pr.S});
    	}
    };

    for(int i = 0; i < 20; ++i){
    	for(int j = 0; j < n; ++j){
    		if(a[j] >> i & 1){
    			add(i, j);
    		}
    	}
    }

    while(m--){
    	int i, x; cin >> i >> x;
    	i--;
    	for(int j = 0; j < 20; ++j){
    		if(a[i] >> j & 1){
    			del(j, i);
    		}
    	}
    	a[i] = x;
    	for(int j = 0; j < 20; ++j){
    		if(a[i] >> j & 1){
    			add(j, i);
    		}
    	}

    	int res = 0;
    	for(int i = 0; i < 20; ++i){
    		res += (1 << i) * ans[i];
    	}
    	cout << res << el;
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}