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

const int N = 2e5;
vi a(N), t(N);
int n;
vector <array <int, 4>> res;
const int inf = 1e9;


void go(int i, array <int, 4> lr){
	if(i == n){
		res.pb(lr);
		return;
	}

	if(t[i] == 1){
		lr[3] += a[i];
		go(i + 1, lr);
	}
	else if(t[i] == 2){
		if(lr[2]){
			if(lr[0] + lr[3] >= a[i]){
				return go(i + 1, lr);
			}
			int m = a[i] - lr[3];
			go(i + 1, {m, lr[1], lr[2], lr[3]});
			go(i + 1, {lr[0], m - 1, 0, a[i]});
		}
		else{
			maxi(lr[3], a[i]);
			return go(i + 1, lr);
		}
	}
	else{
		if(lr[2]){
			if(lr[1] + lr[3] <= a[i]){
				return go(i + 1, lr);
			}
			int m = a[i] - lr[3];
			go(i + 1, {lr[0], m, lr[2], lr[3]});
			go(i + 1, {m + 1, lr[1], 0, a[i]});
		}
		else{
			mini(lr[3], a[i]);
			return go(i + 1, lr);
		}
	}
}


void solve(){
    cin >> n;
    for(int i = 0; i < n; ++i){
    	cin >> a[i] >> t[i];
    }

    go(0, {-inf, inf, 1, 0});

    int q; cin >> q;
    vector <pi> qi(q);
    for(int i = 0; i < q; ++i){
    	cin >> qi[i].F;
    	qi[i].S = i;
    }
    sort(rng(qi));

    vi ans(q);

    sort(rng(res));
    for(int i = 0, j = 0; i < SZ(res); ++i){
    	while(j < q and qi[j].F <= res[i][1]){
    		ans[qi[j].S] = qi[j].F * res[i][2] + res[i][3];
    		j++;
    	}
    }

    for(int i : ans){
    	cout << i << el;
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