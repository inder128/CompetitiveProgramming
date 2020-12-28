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

int get(vi arr){
	int n = arr.size();
	if(n <= 2) return 0;


	vi cnt[32];
	for(int a : arr){
		for (int i = 29; i >= 0; --i){
			if((a & (1<<i)) == 0) continue;
			cnt[i + 1].pb(a);
			break;
		}
		if(a == 0) cnt[0].pb(a);
	}
	int sm = n, lf = cnt[0].size();

	int n0 = 0;
	for (int i = 0; i < 32; ++i){
		n0 += (cnt[i].size() != 0);
	}
	int ans = n - n0;

	if(cnt[0].size()) n0--;

	for (int i = 1; i < 32; ++i){
		if(cnt[i].size()) n0--;

		for(int &a : cnt[i]){
			a -= (1<<(i - 1));
		}

		int st = get(cnt[i]);
		st += max(lf - 1, 0ll);

		lf += cnt[i].size();

		int rem = n - lf;

		st += (rem - n0);

		mini(ans, st);
	}

	return ans;
}

void solve(){
    int n; cin>>n;
    vi arr(n); cin>>arr;
    cout<<get(arr)<<el;
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