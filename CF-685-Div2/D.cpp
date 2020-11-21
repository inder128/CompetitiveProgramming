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
    cout<<"XOR 1 2\n"; cout.flush();
    int x12; cin>>x12;

    cout<<"XOR 2 3\n"; cout.flush();
    int x23; cin>>x23;

    cout<<"OR 1 2\n"; cout.flush();
    int o12; cin>>o12;

    cout<<"OR 2 3\n"; cout.flush();
    int o23; cin>>o23;

    vi xr(n);
    int allxr = x12;
    for (int i = 3; i < n; ++i){
    	cout<<"XOR "<<i<<" "<<(i + 1)<<el; cout.flush();
    	cin>>xr[i];
    	if(i%2){
    		allxr ^= xr[i];
    	}
    }

    vi arr(n + 1);
    int un = 0;
    for (int i = 0; i < 16; ++i){
    	if(((x12)&(1<<i)) == 0 and ((x23)&(1<<i)) == 0){
    		if(((o12)&(1<<i)) == 0) continue;
    		arr[1] += (1<<i);
    		arr[2] += (1<<i);
    		arr[3] += (1<<i);
    	}
    	else if(((x12)&(1<<i)) == 0 and ((x23)&(1<<i)) != 0){
    		if(((o12)&(1<<i)) == 0){
    			arr[3] += (1<<i);
    		}
    		else{
    			arr[1] += (1<<i);
    			arr[2] += (1<<i);
    		}
    	}
    	else if(((x12)&(1<<i)) != 0 and ((x23)&(1<<i)) == 0){
    		if(((o23)&(1<<i)) == 0){
    			arr[1] += (1<<i);
    		}
    		else{
    			arr[2] += (1<<i);
    			arr[3] += (1<<i);
    		}
    	}
    	else if(((x12)&(1<<i)) != 0 and ((x23)&(1<<i)) != 0){
    		// arr[1] += (1<<i);
    		arr[2] += (1<<i);
    		un += (1<<i);
    	}
    }

    int aaa = arr[1]^arr[2]^arr[3];
    for (int i = 4; i <= n; ++i){
    	arr[i] = xr[i - 1] ^ arr[i - 1];
    	aaa ^= arr[i];
    }

    for (int i = 0; i < 16; ++i){
    	if(((aaa&(1<<i)) != (allxr&(1<<i)))){

    		for (int j = 1; j <= n; ++j){
    			arr[j] ^= (1<<i);
    		}
    	}
    }

    cout<<"! ";
    for (int i = 1; i <= n; ++i){
    	cout<<arr[i]<<" ";
    }
    cout.flush();





    



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