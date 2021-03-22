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

int n;
string s, x;

bool get(int i, vector <bool> a){
	if(i == -1){
		return a[0];
	}



	vector <bool> aa(7);
	if(x[i] == 'T'){
		for(int j = 0; j < 7; ++j){
			if(a[(10 * j) % 7] or a[(10 * j + s[i] - '0') % 7]){
				aa[j] = true;
			}
		}
	}
	else{
		for(int j = 0; j < 7; ++j){
			if(a[(10 * j) % 7] and a[(10 * j + s[i] - '0') % 7]){
				aa[j] = true;
			}
		}
		
	}

	return get(i - 1, aa);
}


void solve(){
    cin >> n >> s >> x;
    vector <bool> a(7);
    a[0] = true;
    cout << (get(n - 1, a) ? "Takahashi" : "Aoki") << el;
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