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

// int n, k;
// vi arr;
// bool good(int sz){
// 	int segs = 1, currSum = 0;
// 	for(int ln : arr){
// 		if(currSum + ln <= sz){
// 			currSum += ln;
// 		}
// 		else{
// 			segs++;
// 			currSum = ln;
// 		}
// 	}
// 	return segs <= k;
// }
// void solve(){
//     cin>>n>>k;
//     arr.resize(n);
//     cin>>arr;
//     int l = *max_element(rng(arr)) - 1; // bad;
//     int r = 1e14; // good;
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


// int n, k;
// vi arr;
// bool good(int d){
// 	int cnt = 1, lst = arr[0];
// 	for (int i = 1; i < n; ++i){
// 		if(arr[i] - lst >= d){
// 			lst = arr[i];
// 			cnt++;
// 		}
// 	}
// 	return cnt >= k;
// }
// void solve(){
//     cin>>n>>k;
//     arr.resize(n);
//     cin>>arr;
//     int l = 1; // good;
//     int r = 1e9 + 1; // bad;
//     while(l + 1 < r){
//     	int m = (l + r) >> 1;
//     	if(good(m)){
//     		l = m;
//     	}
//     	else{
//     		r = m;
//     	}
//     }
//     cout<<l<<el;
// }

void solve(){
	cin>>n>>m>>d;
	for (int i = 0; i < m; ++i){
		int u, v, w; cin>>u>>v>>w;
		u--, v--;
		adj[u].pb({v, w});
	}
	int l = -1; // bad;
	int r = 1e9 + 1; // possibly good;
	while(l + 1 < r){
		int m = (l + r) >> 1;
		if(good(m)){
			r = m;
		}
		else{
			l = m;
		}
	}

	if(r == 1e9 + 1){
		cout<<-1<<el;
		return;
	}

	good(r, true);
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