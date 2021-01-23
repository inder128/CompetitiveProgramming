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

void solve(){
    int n; cin >> n;
    map <int, int> freq;
    for(int i = 0; i < n; ++i){
    	int x; cin >> x;
    	freq[x]++;
    }

    int rem = 0, curr = 0;
    vi vals[n + 1];
    for(auto [x, cnt] : freq){
    	vals[cnt].pb(x);
    	rem++;
    }

    int mi = 0, mj = 0;
    for(int i = 1; i <= n; ++i){
    	curr += SZ(vals[i]) * i;
    	rem -= SZ(vals[i]);
	
    	int tot = curr + rem * i;
    	int j = tot / i;
    	if(j >= i and i * j > mi * mj){
    		mi = i, mj = j;
    	}
    }

    vi a;
    for(int i = n; i >= 1; --i){
    	for(int x : vals[i]){
    		a.insert(a.end(), min(i, mi), x);
    	}
    }
    vvi mat(mi, vi(mj));
    for(int k = 0, i = 0, j = 0; k < mi * mj; ++k){
    	mat[i][j] = a[k];
    	i = (i + 1) % mi;
    	j = (j + 1) % mj;
    	if(mat[i][j]){
    		i++;
    	}
    }

    cout << mi * mj << el;
    cout << mi << " " << mj << el;
    for(int i = 0; i < mi; ++i){
    	for(int j = 0; j < mj; ++j){
    		cout << mat[i][j] << " ";
    	}
    	cout << el;
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}