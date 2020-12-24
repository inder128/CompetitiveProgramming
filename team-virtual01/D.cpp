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

void solve(){
    string str; cin >> str;
    int n = SZ(str);
    int o = -1, e;
    for(int i = 0; i < n; ++i){
    	if((str[i] == '-' or str[i] == '+' or str[i] == '*') and i and o == -1){
    		o = i;
    	}
    	if(str[i] == '='){
    		e = i;
    	}
    }

    int al = o;
    int bl = e - (o + 1);
    int cl = n - (e + 1);

    auto check = [&](){
    	if(str[0] == '?' and al > 1){
    		return false;
    	} 
    	if(str[0] == '-' and str[1] == '?'){
    		return false;
    	}
    	if(str[o + 1] == '?' and bl > 1){
    		return false;
    	}
    	if(str[o + 1] == '-' and str[o + 2] == '?'){
    		return false;
    	}
    	if(str[e + 1] == '?' and cl > 1){
    		return false;
    	}
    	if(str[e + 1] == '-' and str[e + 2] == '?'){
    		return false;
    	}
    	return true;
    };


    // db(o, e);
    for(char c = '0'; c <= '9'; ++c){
    	bool present = false;
    	for(char cc : str){
    		if(cc == c){
    			present = true;
    		}
    	}
    	if(present){
    		continue;
    	}
    	string newStr = str;
    	for(char& cc : newStr){
    		if(cc == '?'){
    			cc = c;
    		}
    	}
    	// db(newStr);
    	// db(newStr.substr(0, o));
    	// db(newStr.substr(o + 1, e - (o + 1)));
    	// db(newStr.substr(e + 1, n - (o + 1)));
    	int a = stoi(newStr.substr(0, o));
    	int b = stoi(newStr.substr(o + 1, e - (o + 1)));
    	int r = stoi(newStr.substr(e + 1, n - (o + 1)));
    	int v;
    	if(str[o] == '-'){
    		v = a - b;
    	}
    	else if(str[o] == '+'){
    		v = a + b;
    	}
    	else{
    		v = a * b;
    	}
    	if(r == v and (c != '0' or check())){
    		cout << c << el;
    		return;
    	}
    }
    cout << -1 << el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}