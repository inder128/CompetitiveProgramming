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

int DP[201][201][401];
bool cl[201][201][401];
string s, t;

int get(int n, int m, int o){
	// invalid or curr stste is an ancestor;
	if(o < 0 or o > 400 or DP[n][m][o] == -2){
		return 1e9;
	}
	if(DP[n][m][o] != -1){
		return DP[n][m][o];
	}

	DP[n][m][o] = -2;

	int ans = 1e9;
	// (
	int l = get((n and s[n - 1] == '(') ? n - 1 : n, (m and t[m - 1] == '(') ? m - 1 : m, o - 1) + 1;
	if(l < ans){
		ans = l;
		cl[n][m][o] = false;
	}
	// )
	l = get((n and s[n - 1] == ')') ? n - 1 : n, (m and t[m - 1] == ')') ? m - 1 : m, o + 1) + 1;
	if(l < ans){
		ans = l;
		cl[n][m][o] = true;
	}

	return DP[n][m][o] = ans;
}

void solve(){
	cin >> s >> t;
	int n = SZ(s), m = SZ(t);

    for(int i = 0; i <= n; ++i){
    	for(int j = 0; j <= m; ++j){
    		for(int k = 0; k <= 400; ++k){
    			DP[i][j][k] = -1;
    		}
    	}
    }
    DP[0][0][0] = 0;
    get(n, m, 0);
    db(DP[n][m][0]);

   	string str;
   	int o = 0;
   	while(n + m + o){
   		char oc = (cl[n][m][o] ? ')' : '(');
   		if(n and s[n - 1] == oc){
   			n--;
   		}
   		if(m and t[m - 1] == oc){
   			m--;
   		}
   		if(oc == '('){
   			o--;
   			str.pb('(');
   		}
   		else{
   			o++;
   			str.pb(')');
   		}
   	}

   	reverse(rng(str));
    cout << str << el;
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