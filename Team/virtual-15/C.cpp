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

int n;

vector <string> strs(3);
string a, b;

string get2(){
	int curr = 0;
	vi va;
	for(char c : a){
		if(c == '0'){
			va.pb(curr);
			curr = 0;
		}
		else{
			curr++;
		}
	}
	va.pb(curr);


	curr = 0;
	vi vb;
	for(char c : b){
		if(c == '0'){
			vb.pb(curr);
			curr = 0;
		}
		else{
			curr++;
		}
	}
	vb.pb(curr);

	if(SZ(va) < SZ(vb)){
		swap(va, vb);
	}

	int ex = SZ(vb);
	for (int i = 0; i < SZ(va) - ex; ++i){
		vb.pb(0);
	}

	// db(va, vb);


	string c;
	for (int i = 0; i < SZ(va); ++i){
		for (int j = 0; j < max(va[i], vb[i]); ++j){
			c.pb('1');
		}
		c.pb('0');

	}
	c.pop_back();


	return c;
}

bool get(){
	if(count(rng(a), '0') >= n and count(rng(b), '0') >= n){
		string d = get2();
		db(a, b, d);
		cout << d << el;
		return true;
	}
	else if(count(rng(a), '1') >= n and count(rng(b), '1') >= n){
		for(char &c : a){
			c = '0' + ('1' - c);
		}
		for(char &c : b){
			c = '0' + ('1' - c);
		}
		string d = get2();
		for (char &c : d){
			c = '0' + ('1' - c);
		}
		cout << d << el;
		return true;
	}
	return false;
}

void solve(){
	cin >> n;
    cin >> strs;
    for (int i = 0; i < 3; ++i){
    	for (int j = i + 1; j < 3; ++j){
    		a = strs[i];
    		b = strs[j];
    		if(get()){
    			return;
    		}
    	}
    }
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