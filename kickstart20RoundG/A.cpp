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

void solve(){
    ll n, w; cin>>n>>w;
    vl arr(2*n);
    for (int i = 0; i < n; ++i){
        ll x; cin>>x; x--;
        arr[i] = x;
        arr[i + n] = w + x;
    }
    sort(rng(arr));
    vl sumArr = arr;
    for (int i = 1; i < 2*n; ++i){
        sumArr[i] += sumArr[i - 1];
    }

    function <ll(int, int)> get = [&](int l, int r){
    	return sumArr[r] - (l ? sumArr[l - 1] : 0);
    };

    ll ans = LLONG_MAX, l = 0, r = 0;

    for (int i = 0; i < 2*n; ++i){
    	if(arr[i] < (w - 1)/2) continue;
    	if(arr[i] > 2*w - 1 - w/2) break;

    	while(arr[l] < arr[i] - (w - 1)/2) l++;
    	while(r < 2*n and arr[r] <= arr[i] + w/2) r++;

        ll tans = ((i - l + 1)*arr[i] - get(l, i)) + (get(i, r - 1) - (r - 1 - i + 1)*arr[i]);
        mini(ans, tans);
    }
    cout<<ans<<el;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1, tc = 1;
    cin>>T; 
    while(T--){
        cout<<"Case #"<<tc<<": ";
        tc++;
        solve();
    }
    return 0; 
}