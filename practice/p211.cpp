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

vi p{0, 6, 4, 2, 3, 5, 1};

int t1(int i, int j, int x){
	cout << "? 1 " << i << " " << j << " " << x << endl;
	int ans; cin >> ans; assert(ans != -1); return ans;
	// int ans = max(min(x, p[i]), min(x + 1, p[j])); db(ans); return ans;
}

int t2(int i, int j, int x){
	cout << "? 2 " << i << " " << j << " " << x << endl;
	int ans; cin >> ans; assert(ans != -1); return ans;
	// int ans = min(max(x, p[i]), max(x + 1, p[j])); db(ans); return ans;
}

void solve(){
    int n; cin >> n;
    assert(n != -1);
    vi ans(n + 1, -1);

    int l = 1, r = n;
    while(l + 1 < r){
    	int x = (l + r) >> 1;
    	int a1 = t1(1, 2, x - 1);
    	int a2 = t2(1, 2, x - 1);
    	if(min(a1, a2) >= x){
    		l = x;
    	}
    	else{
    		r = x;
    	}
    }

    int f = 1 + (t1(1, 2, l) < t2(1, 2, l));
    ans[f] = l;

    // db(f, ans[f]);

    if(l > n / 2){ // .........l..
    	for(int i = 1; i <= n; ++i){
    		if(ans[i] != -1) continue;
    		int a = t2(i, f, 1);
    		if(a == ans[f]){
    			ans[i] = t1(f, i, n - 1);
    		}
    		else{
    			ans[i] = a;
    		}
    	}
    }
    else{ // ..l........
    	for(int i = 1; i <= n; ++i){
    		if(ans[i] != -1) continue;
    		int a = t1(f, i, n - 1);
    		if(a == ans[f]){
    			ans[i] = t2(i, f, 1);
    		}
    		else{
    			ans[i] = a;
    		}
    	}
    }

    cout << "! ";
    for(int i = 1; i <= n; ++i){
    	cout << ans[i] << " ";
    }
    cout << endl;
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