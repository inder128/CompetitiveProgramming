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

set <int> get(vi &arr, int l, int r){
	int n = r - l;
	set <int> ans;
	for (int msk = 0; msk < (1<<n); ++msk){
		int sm = 0;
		for (int i = 0; i < n; ++i){
			if((msk&(1<<i)) == 0) continue;
			sm += arr[l + i];
		}
		ans.insert(sm);
	}
	return ans;
}

void solve(){
	int n, t; cin>>n>>t;
	vi arr(n); cin>>arr;
	if(n == 1){
		if(arr[0] <= t){
			cout<<arr[0]<<el;
		}
		else{
			cout<<0<<el;
		}
		return;
	}

    set <int> a = get(arr, 0, n / 2);
    set <int> b = get(arr, n / 2, n);

    int ans = 0;
    for(int fst : a){
    	if(fst > t) break;
    	auto itr = b.lower_bound(t - fst);
    	if(itr == b.end() or (*itr) > t - fst){
    		itr--;
    	}
    	maxi(ans, fst + (*itr));
    }
    cout<<ans<<el;  
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