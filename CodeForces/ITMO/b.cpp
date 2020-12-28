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

// // 2C
// int n, x, y;
// bool good(int m){
// 	if(m < x) return false;
// 	return (m - x)/x + (m - x)/y + 1 >= n;
// }
// void solve(){
//     cin>>n>>x>>y;
//     if(x > y) swap(x, y);
//     int l = 0; //bad
//     int r = n*x; //good

//     while(l + 1 < r){
//     	int m = (l + r) >> 1;
//     	if(good(m)){
//     		r = m;
//     	}
//     	else{
//     		l = m;
//     	}
//     }
//     cout<<r<<el;
// }


// 3C
int n, m;
vi t, z, y;
bool good(int r){
	int ans = 0;
	for (int i = 0; i < n; ++i){
		int bsz = z[i]*t[i] + y[i];
		int bcnt = r / bsz;
		int rem = min((r % bsz) / t[i], z[i]);
		ans += bcnt * z[i] + rem;
	}
	return ans >= m;
}
void solve(){
	cin>>m>>n;
	t.resize(n);
	y.resize(n);
	z.resize(n);
	for (int i = 0; i < n; ++i){
		cin>>t[i]>>z[i]>>y[i];
	}
	if(m == 0){
		cout<<0<<el;
		for (int i = 0; i < n; ++i){
			cout<<0<<" ";
		}
		cout<<el;
		return;
	}
	
	int l = 0; // bad;
	int r = 1; // good;
	while(good(r) == false) r <<= 1;

	while(l + 1 < r){
		int m = (l + r) >> 1;
		if(good(m)){
			r = m;
		}
		else{
			l = m;
		}
	}

	cout<<r<<el;
	for (int i = 0; i < n; ++i){
		int bsz = z[i]*t[i] + y[i];
		int bcnt = r / bsz;
		int rem = min((r % bsz) / t[i], z[i]);
		int tot = bcnt * z[i] + rem;
		int taken = min(m, tot);
		m -= taken;
		cout<<taken<<" ";
	}
	cout<<el;
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