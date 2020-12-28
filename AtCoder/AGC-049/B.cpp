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
    string s, t; cin>>s>>t;
    vi s1, t1;
    for (int i = 0; i < n; ++i){
    	if(s[i] == '1'){
    		s1.pb(i);
    	}
    	if(t[i] == '1'){
    		t1.pb(i);
    	}
    }

    int tn = t1.size(), sn = s1.size();
    if(sn < tn or (sn - tn) % 2){
    	cout<<"-1\n";
    	return;
    }

    int lr = -1, ans = 0;
    int i = 0, j = 0;
    while(i < sn and j < tn){
    	if(lr != -1){
    		ans += (s1[i] - lr);
    		lr = -1;
    		i++;
    	}
    	// lr == -1;
    	else if(s1[i] < t1[j]){
    		lr = s1[i];
    		i++;
    	}
    	else{
    		ans += (s1[i] - t1[j]);
    		i++, j++;
    	}
    }


    if(j < tn){
    	cout<<"-1\n";
    	return;
    }

    for (int p = i; p < sn; p += 2){
    	ans += (s1[p + 1] - s1[p]);
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