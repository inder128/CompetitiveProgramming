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

vi pow5(20), cnt(20);

int count(int n){
	string str = to_string(n);

	str = "$" + str;
	int len = str.length();

	int ans = 0;
	for (int i = 1; i < len - 1; ++i){
		ans += pow5[i];
	}

	
	int i;
	for (i = 1; i < len; ++i){

		int c = str[i] - '0';
		int all;

		if(i % 2 == 1){
			all = c / 2;
		}
		else{
			all = (c + 1 - 2*(i == 1)) / 2;
		}

		ans += all * pow5[len - i - 1];

		// db(c, all, i);

		if(c % 2 != i % 2) break;
	}
	ans += (i == len);
	// db(n, ans);
	return ans;
}

void solve(){
    int l, r; cin>>l>>r;
    cout<<count(r) - count(l - 1)<<el;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1, tc = 1;

    pow5[0] = 1;
    for (int i = 1; i < 20; ++i){
    	pow5[i] = pow5[i - 1] * 5;
    }

    cin>>T;
    while(T--){
    	cout<<"Case #"<<tc<<": ";
    	tc++;
        solve();
    }
    return 0;
}