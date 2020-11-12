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

int n, k;
vi a, b; 

int cntLess(int x){
	// invarients;
	int l = -1; // b[l] < x;
	int r = n + 1; // b[l] >= x;

	while(l + 1 < r){
		int m = (l + r) >> 1;

		// maintaining invarients;
		if(b[m] < x){
			l = m;
		}
		else{
			r = m;
		}
	}

	return l + 1;
}

int good(int m){
	int cnt = 0;
	for (int i = 0; i < n; ++i){
		cnt += cntLess(m - a[i]);
	}
	return cnt;
}

void solve(){
    cin>>n>>k;
    a.resize(n);
    b.resize(n);
    cin>>a>>b;
    sort(rng(b));

    // invarients;
    int l = 0; // cnt(l) < k;
    int r = 2e9 + 1; // cnt(r) >= k;

    while(l + 1 < r){
    	int m = (l + r) >> 1;

    	// maintaining invarients;
    	if(good(m) < k){
    		l = m;
    	}
    	else{
    		r = m;
    	}
    }

    cout<<l<<el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}