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

int n, d;
vi a;
pi good(double avg){
	vector <int> mnInd(n + 1);
	vector <double> sum(n + 1);
	for (int i = 0; i < n; ++i){
		sum[i + 1] = sum[i] + a[i] - avg;
		if(i >= d - 1){
			if(sum[i + 1] - sum[mnInd[i - d + 1]] >= 0) 
				return {mnInd[i - d + 1] + 1, i + 1};
		}
		if(sum[i + 1] < sum[mnInd[i]]){
			mnInd[i + 1] = i + 1;
		}
		else{
			mnInd[i + 1] = mnInd[i];
		}
	}
	return {-1, -1};
}
void solve(){
    cin>>n>>d;
    a.resize(n);
    cin>>a;
    double l = 0; // good;
    double r = 101; // bad;
    for (int i = 0; i < 50; ++i){
    	double m = (l + r) / 2;
    	if(good(m).F == -1){
    		r = m;
    	}
    	else{
    		l = m;
    	}
    }
    pi ans = good(l);

    cout<<ans.F<<" "<<ans.S<<el;
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