#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define maxi(x, y) x = max(x, (y))
#define mini(x, y) x = min(x, (y))
#define pb push_back
#define F first
#define S second
#define el '\n'
#define ll long long
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
    sort(rng(arr));

    if(n == 1){
    	cout<<-1<<el;
    	return;
    }

    if(n == 2){
    	if(arr[0] == arr[1]){
    		cout<<1<<el;
    		cout<<arr[0]<<el;
    	}
    	else{
    		cout<<2 + ((arr[1] - arr[0]) % 2 == 0)<<el;
    		cout<<arr[0] - (arr[1] - arr[0])<<" ";
    		if(((arr[1] - arr[0]) % 2 == 0)){
    			cout<<(arr[1] + arr[0]) / 2<<" ";
    		}
    		cout<<arr[1] + (arr[1] - arr[0])<<el;
    	}
    	return;
    }

    // n >= 3;
    map <int, int> freq;
    for(int i = 1; i < n; ++i){
    	freq[arr[i] - arr[i - 1]]++;
    }

    if(SZ(freq) == 1){
    	if(freq.begin()->F == 0){
    		cout<<1<<el;
    		cout<<arr[0]<<el;
    	}
    	else{
    		cout<<2<<el;
    		cout<<arr[0] - (freq.begin()->F)<<" ";
    		cout<<arr[n - 1] + (freq.begin()->F)<<"\n";
    	}
    	return;
    }

    if(SZ(freq) == 2){
    	if(freq.rbegin()->S == 1 and freq.rbegin()->F == 2 * freq.begin()->F){
    		cout<<1<<el;
    		for(int i = 1; i < n; ++i){
    			if(arr[i] - arr[i - 1] == freq.begin()->F) continue;
    			cout<<(arr[i] + arr[i - 1]) / 2<<" ";
    			break;
    		}
    		return;
    	}
    }

    cout<<0<<el;
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