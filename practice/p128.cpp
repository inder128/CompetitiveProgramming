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
	int n, k; cin>>n>>k;
   	string str; cin>>str;
   	

   	vi pos;
   	for(int i = 0; i + 1 < n; ++i){
   		if(str[i] == 'R' and str[i + 1] == 'L'){
   			pos.pb(i);
   		}
   	}

   	vvi moves;
   	int tot = SZ(pos);
   	while(tot <= n * n and SZ(pos)){
   		// db(pos);
   		moves.pb(pos);
   		vi newPos;

   		for(int i : pos){
   			swap(str[i], str[i + 1]);
   			if(i - 1 >= 0 and str[i - 1] == 'R'){
   				newPos.pb(i - 1);
   			}
   			if(i + 2 <= n - 1 and str[i + 2] == 'L'){
   				newPos.pb(i + 1);
   			}
   		}

   		pos = newPos;
   		tot += SZ(pos);
   	}

   	// k not in range;
   	if(tot > n * n or tot < k or SZ(moves) > k){
   		cout<<-1<<el;
   		return;
   	}

   	int pre = SZ(moves);

   	vvi ans;

   	while(pre < k){
   		if(SZ(moves.back()) == 1){
   			ans.pb(moves.back());
   			moves.pop_back();
   		}
   		else{
   			ans.pb({moves.back().back()});
   			moves.back().pop_back();
   			pre++;
   		}
   	}

   	while(SZ(moves)){
   		ans.pb(moves.back());
   		moves.pop_back();
   	}

   	reverse(rng(ans));

   	for(vi &mv : ans){
   		cout<<SZ(mv)<<" ";
   		for(int &p : mv){
   			cout<<p + 1<<" ";
   		}
   		cout<<el;
   	}
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