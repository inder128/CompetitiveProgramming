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

void solve(){
    int n; cin>>n;
    int xr = 0;
    for (int i = 0; i < n; ++i){
    	int x; cin>>x;
    	xr ^= x;
    }
    

    // when n is even;
    // xor of all element should be zero;
    // let c0 = count of zeros at any bit in whole array;
    // after every operation parity of c0 and c1 will not change;
    // after all operations -> parity of c0 and c1 should be even;
    // so initially if any c0 or c1 parity is odd (xor of array is non-zero),
    // then there is no answer;
    // otherwise xor of elements from 1 to n - 1 will be wqual to element at n;
    if(n % 2 == 0 and xr){
        cout<<"NO\n";
        return;
    }
    if(n % 2 == 0) n--;

    cout<<((n - 3)/2 + (n - 1)/2)<<el;
    for (int i = 1; i <= n - 2; i += 2){
    	cout<<i<<" "<<i + 1<<" "<<i + 2<<el;
    }
    for (int i = 1; i < n - 3; i += 2){
    	cout<<i<<" "<<i + 1<<" "<<n<<el;
    }
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