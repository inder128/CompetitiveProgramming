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
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

void solve(){
    int n; cin>>n;
    vi arr(n); cin>>arr;
    vi curr = arr, ansArr;

    int ans = 0;
    for(int i = 0; i < 30; ++i){
    	int j = max_element(rng(curr)) - curr.begin();

    	int ele = curr[j];
    	if(ele == 0) break;

    	ansArr.pb(arr[j]);
    	arr[j] = -1;

    	ans += ele * (n - i);
    	
    	for(auto &a : curr){
    		a ^= (a & ele); 
    	}
    }
   
    for(int &a : arr){
    	if(a == -1) continue;
    	ansArr.pb(a);
    }
    reverse(rng(ansArr));

    cout<<ans<<el;
    for(int i : ansArr) cout<<i<<" "; cout<<el;
}

/*
1 2 3 4 5
0 2 2 0 0

*/
 
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