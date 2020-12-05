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

struct ordPair{
	int leftOrd, rightOrd, ind;
};


vi get(string str){
	str.pb('a' - 1);
	int n = str.size();
	vi pos(n);
	for(int i = 0; i < n; ++i){
		pos[i] = str[i] - 'a' + 1;
	}
	int k = 0;
	while((1 << k) < n){
		// k -> k + 1;
		vector <ordPair> subStrOrd(n);
		for(int i = 0; i < n; ++i){
		 	subStrOrd[i] = {pos[i], pos[(i + (1 << k)) % n], i};
		} 
		sort(rng(subStrOrd), [&](const ordPair &s1, const ordPair &s2){
			if(s1.leftOrd == s2.leftOrd){
				return s1.rightOrd < s2.rightOrd;
			}
			return s1.leftOrd < s2.leftOrd;
		});
		pos[subStrOrd[0].ind] = 0;
		for(int i = 1; i < n; ++i){
			ordPair lastOrd = subStrOrd[i - 1];
			ordPair currOrd = subStrOrd[i];
			if(lastOrd.leftOrd == currOrd.leftOrd and lastOrd.rightOrd == currOrd.rightOrd){
				pos[currOrd.ind] = pos[lastOrd.ind];
			}
			else{
				pos[currOrd.ind] = pos[lastOrd.ind] + 1;
			}
		}
		if(pos[subStrOrd.back().ind] == n - 1) break;
		k++;
	}
	return pos;
}

void solve(){
    string str; cin>>str;
   	vi ordering = get(str);
   	vi ans = ordering;
   	for(int i = 0; i < str.length() + 1; ++i){
   		ans[ordering[i]] = i;
   	}
   	for(int i : ans) cout<<i<<" "; cout<<el;
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