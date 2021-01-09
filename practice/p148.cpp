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
    int n, k; cin >> n >> k;
    vi a(n + 1), b(n + 1);
    for(int i = 1; i <= n; ++i){
    	cin >> a[i];
    }
    for(int i = 1; i <= n; ++i){
    	cin >> b[i];
    }
    vi sa = a, sb = b;
    for(int i = 1; i <= n; ++i){
    	sa[i] += sa[i - 1];
    	sb[i] += sb[i - 1];
    }
    auto geta = [&](int l, int r){
    	if(l > r){
    		return 0ll;
    	}
    	return sa[r] - (l ? sa[l - 1] : 0);
    };
    auto getb = [&](int l, int r){
    	if(l > r){
    		return 0ll;
    	}
    	return sb[r] - (l ? sb[l - 1] : 0);
    };
    vector <pi> d(n + 1);
    int cd = 0;
    for(int i = 0; i < n; ++i){
    	cd += a[i] - b[i];
    	if(cd > 0){
    		d[i].F = cd;
    	}
    	else{
    		d[i].S = -cd;
    	}
    }


    int pa = 0, p = -1, pb = 0;
    vi DP(n + 1, 1e9), ans(n + 1, 1e9), lst(n + 1), lsta(n + 1);
    DP[0] = 0;

    for(int i = 1; i <= n; ++i){
    	while(d[pa].F + geta(pa + 1, i) >= k){
    		pa++;
    	}
    	while(d[pb].S + getb(pb + 1, i) >= k){
    		pb++;
    	}

    	DP[i] = DP[max(pa, pb)] + 1;
    	lst[i] = max(pa, pb);

    	// p ??
    	if(p == -1){
    		if(getb(1, i) >= k){
    			p = 0;
    		}
    	}
    	
    	if(p == -1){
    		continue;
    	}

    	while(d[p].S + getb(p + 1, i - 1) >= k){
    		p++;
    	}

    	if(d[p].S + getb(p + 1, i) < k){
    		continue;
    	}

    	if(pa <= p){
    		ans[i] = DP[p];
    		lsta[i] = p;
    	}
    	else if(d[pa].S + getb(pa + 1, i) >= k){
    		ans[i] = DP[pa];
    		lsta[i] = pa;
    	}
    }

    int mn = 0;
    for(int i = 1; i <= n; ++i){
    	if(ans[i] < ans[mn]){
    		mn = i;
    	}
    }

    if(mn == 0){
    	cout << -1 << el;
    }
    else{
    	set <int> ans;
    	mn = lsta[mn];
    	while(mn){
    		ans.insert(mn);
    		mn = lst[mn];
    	}
    	cout << SZ(ans) << el;
    	for(int i : ans){
    		cout << i <<  " "; 
    	}
    	cout << el;

    	int sa = 0, sb = 0;
    	for(int i = 0; i <= n; ++i){
    		sa += a[i];
    		sb += b[i];

    		if(sa < k and sb >= k){
    			return;
    		}

    		assert(sa < k and sb < k);

    		if(ans.count(i)){
    			int df = min(sa, sb);
	    		sa -= df, sb -= df;
    		}
	    		
    	}
    	assert(sa < k and sb >= k);
    }
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