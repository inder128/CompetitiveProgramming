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


// https://www.codechef.com/ICPCIN19/problems/SPS

vi prefixFunction(string str) {
    int n = SZ(str);
    vi pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while(j > 0 and str[i] != str[j]){
            j = pi[j-1];
        }
        if(str[i] == str[j]){
            j++;
        }
        pi[i] = j;
    }
    return pi;
}


int comm2(string &a, string &b){
	// a c b;
	return prefixFunction(b + "$" + a).back();
}

int comm(string &a, string &b){
	vi pf = prefixFunction(b + "$" + a); 
	if(*max_element(rng(pf)) == SZ(b)){
		return SZ(b);
	}
	return max(comm2(a, b), comm2(b, a));
}


int calc(string &a, string &b){
	int n = SZ(a), ans = 1e9;
	for(int i = 0; i < n; ++i){
		bool valid = true;
		for(int l = i - 1, r = i; l >= 0 and r < n ; l--, r++){
			if(a[l] != a[r]){
				valid = false;
				break;
			}
		}
		if(valid){
			string lft = a.substr(0, i);
			string rgt = a.substr(i, n - i);
			string aa;

			if(SZ(lft) > SZ(rgt)){
				aa = lft;
				reverse(rng(lft));
				aa += lft;
			}
			else{
				aa = rgt;
				reverse(rng(rgt));
				aa = rgt + aa;
			}

			mini(ans, SZ(aa) + 2 * (SZ(b) - comm(aa, b)) );
		}


		valid = true;
		for(int l = i - 1, r = i + 1; l >= 0 and r < n ; l--, r++){
			if(a[l] != a[r]){
				valid = false;
				break;
			}
		}

		if(valid){
			string lft = a.substr(0, i);
			string rgt = a.substr(i + 1, n - i - 1);
			string aa;

			if(SZ(lft) > SZ(rgt)){
				aa = lft;
				reverse(rng(lft));
				aa.pb(a[i]);
				aa += lft;
			}
			else{
				aa = rgt;
				reverse(rng(rgt));
				aa = rgt + a.substr(i, 1) + aa;
			}

			mini(ans, SZ(aa) + 2 * (SZ(b) - comm(aa, b)) );
		}
	}
	return ans;
}


void solve(){
    string a, b; cin>>a>>b;
    cout<<min(calc(a, b), calc(b, a))<<el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}