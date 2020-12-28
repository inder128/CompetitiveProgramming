#include <bits/stdc++.h>
using namespace std;
 
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
template<class T> ostream& operator<<(ostream &os, multiset<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ "; for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") "; return os<<"}"; }
    #define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " |"; __f(comma + 1, args...); }
#define rng(x) x.begin(), x.end()
#define pb push_back
#define F first
#define S second
#define el '\n'
 
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<bool> vb;
 
/*-----------------------------Code begins----------------------------------*/

void toBinStr(int n){
	for (int i = 4; i >= 0; --i)
		cout<<(char)('0' + ((n>>i)&1));
	cout<<" ";
}

void toBinVec(vi a){
	for (int i : a) toBinStr(i); cout<<el;
}


void solve(){
    int n; cin>>n;
    vi arr(n); for(int &i : arr) cin>>i;
    int ind = 0;
    for (int i = 10; i >= 0; --i){
        int mxInd = ind;
        int mxEle = INT_MIN;
        for (int j = ind; j < n; ++j){
            if((arr[j] & (1<<i)) and arr[j] > mxEle)
                mxEle = arr[j], mxInd = j;
        }
        if (mxEle == INT_MIN) continue; 
        toBinStr(arr[mxInd]); cout<<el;
        toBinVec(arr);
        swap(arr[ind], arr[mxInd]); 
        toBinVec(arr);
        mxInd = ind;
        for (int j=0; j<n; j++) { 
            if(j != mxInd and (arr[j] & (1<<i))) 
                arr[j] ^= arr[mxInd]; 
        } 
        toBinVec(arr); cout<<el;
        ind++;
    }

    int ans = 0;
    for(int i : arr) ans ^= i;
    cout<<ans<<el;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1, tc = 1;
    // cin>>T; 
    while(T--){
        solve();
    }
    return 0; 
}