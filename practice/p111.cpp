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

multiset <int> diffs;
set <int> ones, zeros;


void insert(set <int>& vals, int i){
	vals.insert(i);
	auto itr = vals.lower_bound(i);

	// auto itr = vals.insert(i) // will not work;

	int prvi = *prev(itr), nxti = *next(itr);

	diffs.erase(diffs.find(nxti - prvi));
	diffs.insert(i - prvi);
	diffs.insert(nxti - i);
}

void del(set <int>& vals, int i){
	auto itr = vals.lower_bound(i);

	int prvi = *prev(itr), nxti = *next(itr);

	// erase after above line;
	vals.erase(i);

	diffs.erase(diffs.find(i - prvi));
	diffs.erase(diffs.find(nxti - i));
	diffs.insert(nxti - prvi);
}



void solve(){
    string str; cin>>str;
    int n = SZ(str);
    
    zeros.insert(-1);
    ones.insert(-1);
    for(int i = 0; i < n; ++i){
    	if(str[i] == '0'){
    		zeros.insert(i);
    	}
    	else{
    		ones.insert(i);
    	}
    }
    zeros.insert(n);
    ones.insert(n);


    int lastInd = -1;
    for(int ind : ones){
    	if(ind == -1) continue;
    	diffs.insert(ind - lastInd);
    	lastInd = ind;
    }
    lastInd = -1;
    for(int ind : zeros){
    	if(ind == -1) continue;
    	diffs.insert(ind - lastInd);
    	lastInd = ind;
    }

    int m; cin>>m;
    while(m--){
    	int i; cin>>i; 
    	i--;
    	if(str[i] == '0'){
			del(zeros, i);
    		str[i] = '1';
  			insert(ones, i);
    	}
    	else{
    		del(ones, i);
    		str[i] = '0';
    		insert(zeros, i);
    	}
    	cout<<(*diffs.rbegin() - 1)<<" ";
    }
    cout<<el;
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