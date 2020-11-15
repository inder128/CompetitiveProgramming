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

void prin(int n){
	for (int i = 0; i < 26; ++i){
		if((n & (1<<i)) == 0) continue;
		cout<<((char)('A' + i));
	}
	cout<<el;
}


void solve(){
	int n, q; cin>>n>>q;
	vector <string> names(n);
	vi inds[26];
    for (int i = 0; i < n; ++i){
    	cin>>names[i];
    	for(char c : names[i]){
    		inds[c - 'A'].pb(i);
    	}
    }

    vi reachable(26);
    for (int i = 0; i < 26; ++i){
    	for (int j : inds[i]){
    		for(char c : names[j]){
    			reachable[i] |= (1<<(c - 'A'));
    		}
    	}
    }
    // db(reachable);

    while(q--){
    	int i, j; cin>>i>>j; 
    	i--, j--;
    	int curr = 0, final = 0, steps = 0;
    	for(char c : names[i]){
    		curr |= (1<<(c - 'A'));
    	}
    	for(char c : names[j]){
    		final |= (1<<(c - 'A'));
    	}

    	while((curr & final) == 0){

    		steps++;
    		int newCurr = 0;
    		for (int k = 0; k < 26; ++k){
    			if((curr & (1<<k)) == 0) continue;
    			newCurr |= reachable[k];
    			// prin(1<<k);
    			// prin(reachable[k]);
    		}
    		if(newCurr == curr) break;
    		// db(steps);
    		// prin(curr);
    		// prin(newCurr);
    		curr = newCurr;
    	}

    	if((curr & final) == 0) steps = -3;
    	// db(steps, '0');
    	cout<<steps + 2<<" ";
    }
    cout<<el;
}
 
int32_t main(){
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