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

// void solve(){
//     int n, k; cin>>n>>k;
//     vector <pi> lr(n);
//     for (int i = 0; i < n; ++i){
//     	cin>>lr[i].F>>lr[i].S;
//     }

//     function <int(int)> cnt = [&](int x){
//     	int c = 0;
//     	for (int i = 0; i < n; ++i){
//     		c += max(0ll, min(x - 1, lr[i].S) - lr[i].F + 1);
//     	}
//     	return c;
//     };

//     int l = -2e9 - 1; // cnt[l] <= k;
//     int r = 2e9 + 1; // cnt[r] > k;

//     while(l + 1 < r){
//     	int m = (l + r) >> 1;
//     	if(cnt(m) <= k){
//     		l = m;
//     	}
//     	else{
//     		r = m;
//     	}
//     }
//     cout<<l<<el;
// }



void solve(){
    int n, k; cin>>n>>k;
    function <int(int)> cnt = [&](int x){
    	int c = 0;
    	for (int i = 1; i <= n; ++i){
    		c += min(n, (x - 1) / i);
    	}
    	return c;
    };

    int l = 0; // cnt[l] < k;
    int r = n * n + 1; // cnt[r] => k;

    while(l + 1 < r){
    	int m = (l + r) >> 1;
    	if(cnt(m) < k){
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