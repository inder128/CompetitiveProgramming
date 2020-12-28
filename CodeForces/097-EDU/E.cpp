#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define maxi(x, y) x = max(x, (y))
#define mini(x, y) x = min(x, (y))
#define pb push_back
#define F first
#define S second
#define el '\n'
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.S << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ "; for(auto m:M) os<<"("<<m.F<<" : "<<m.S<<") "; return os<<"}";}
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef long long ll; typedef pair<int,int> pi; typedef vector <bool> vb;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

const int N = 5e5 + 5;
vl arr(N);

int get(int l, int r){
	if(arr[r] - arr[l] < r - l) return 1e9;
	if(l + 1 == r) return 0;


	// longest non decreasing subsequence of positive elements such that largest element is less than arr[r];
	for (int i = l + 1; i < r; ++i){
		arr[i] -= arr[l];
		arr[i] -= i - (l + 1);
	}

	vl lb(r - l + 1, 1e15); 
    for (int i = l + 1; i < r; ++i){
    	if(arr[i] <= 0 or arr[i] > (arr[r] - arr[l] - (r) + (l + 1))) continue;

        // longest non-decreasing subsequence
        int ui = upper_bound(rng(lb), arr[i]) - lb.begin();

        lb[ui] = arr[i];  
    }
	// last element less than equal to (arr[r] - arr[l] - (r) + (l + 1));

    int ans = 0;
	for (int i = 0; i <= r - l; ++i){
		if(lb[i] < 1e15)  ans = i + 1;
	}
	// db(ans, lb);
	return (r - l - 1) - ans;
}


void solve(){
    int n, k; cin>>n>>k;
    for (int i = 1; i <= n; ++i){
    	cin>>arr[i];
    }
    arr[0] = -1e12;
    arr[n + 1] = 1e12;

    vi inds(k);
    for(int &i : inds) cin>>i;
    inds.pb(0);
    inds.pb(n + 1);
    sort(rng(inds));

    ll ans = 0;
    for (int i = 1; i < k + 2; ++i){
    	ans += get(inds[i - 1], inds[i]);
    	// db(inds[i - 1], inds[i], ans);
    }


    if(ans > n) ans = -1;

    cout<<ans<<el;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1, tc = 1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
