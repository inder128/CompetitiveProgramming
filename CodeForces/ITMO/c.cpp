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


// // 1E
// void solve(){
//     double c; cin>>c;

//     double l = 0;  // f(l) < c;
//     double r = 1e5; // f(r) >= c;

//     for (int i = 0; i < 100; ++i){
//     	double m = (l + r) / 2;
//     	if(m*m + sqrt(m) >= c){
//     		r = m;
//     	}
//     	else{
//     		l = m;
//     	}
//     }
//     cout<<setprecision(12)<<fixed<<r<<el;

// 	// (x + dx) * (x + dx) - x*x;
// 	// dx*dx + 2*x*dx
// }


// // 1F
// string t, p;
// vi per;
// int n, m;
// bool good(int c){
// 	set <int> inds(per.begin(), per.begin() + c);
// 	int i, j;
// 	for (i = 0, j = 0; i < n and j < m; ++i){
// 		if(inds.count(i + 1)) continue;
// 		if(t[i] != p[j]) continue;
// 		j++;
// 	}
// 	return j == m;
// }
// void solve(){
// 	cin>>t>>p;
// 	n = t.length(); 
// 	m = p.length(); 

// 	per.resize(n);
// 	cin>>per;

// 	int l = 0; // good;
// 	int r = n; // bad;

// 	while(l + 1 < r){
// 		int m = (l + r) >> 1;
// 		if(good(m)){
// 			l = m;
// 		}
// 		else{
// 			r = m;
// 		}
// 	}
// 	cout<<l<<el;
// }

// // 1G
// int k, n;
// vi cnt;
// bool good(int c){
// 	int f = 0, fp = 0;
// 	for(int ln : cnt){
// 		if(ln >= c){
// 			f++;
// 		}
// 		else{
// 			int rem = c - fp;
// 			if(ln >= rem){
// 				f++;
// 				fp = (fp + ln) % c;
// 			}
// 			else{
// 				fp += ln;
// 			}
// 		}
// 	}
// 	return f >= k;
// }
// void solve(){
// 	cin>>k>>n;
// 	cnt.resize(n);
// 	cin>>cnt;

// 	int l = 0; // good;
// 	int r = 25e9 + 1; // bad;

// 	while(l + 1 < r){
// 		int m = (l + r) >> 1;
// 		if(good(m)){
// 			l = m;
// 		}
// 		else{
// 			r = m;
// 		}
// 	}
// 	cout<<l<<el;
// }


// 1H
void solve(){
	string recipe; cin>>recipe;
	int cb = count(rng(recipe), 'B');
	int cs = count(rng(recipe), 'S');
	int cc = count(rng(recipe), 'C');

	int nb, ns, nc; cin>>nb>>ns>>nc;
	int pb, ps, pc; cin>>pb>>ps>>pc;

	int m; cin>>m;

	function <bool(int)> good = [&](int n){
		int reqb = max(0ll, n * cb - nb);
		int reqs = max(0ll, n * cs - ns);
		int reqc = max(0ll, n * cc - nc);

		int cost = reqb * pb + reqs * ps + reqc * pc;

		return cost <= m;
	};

	int l = 0; // good;
	int r = 1; // bad;
	while(good(r)) r <<= 1;

	while(l + 1 < r){
		int mid = (l + r) >> 1;
		if(good(mid)){
			l = mid;
		}
		else{
			r = mid;
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