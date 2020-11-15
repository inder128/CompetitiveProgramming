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

int dist(int x1, int y1, int x2, int y2){
	return abs(x1 - x2) + abs(y1 - y2);
}

void solve(){
	int n; cin>>n;
	vi xs(n), ys(n);
	for (int i = 0; i < n; ++i){
		cin>>xs[i]>>ys[i];
	}
	sort(rng(ys));
	sort(rng(xs));

	int y = ys[n / 2];
	int yc = 0;
	for (int i = 0; i < n; ++i){
		yc += abs(y - ys[i]);
	}

	

	int l = -2e9; // dc >= (n + 1) / 2;
	int r = 2e9;

	while(l + 1 < r){
		int m = (l + r) >> 1;

		int in = 0, dc = 0;
		for (int i = 0; i < n; ++i){
			if(m + i > xs[i]) in++;
			else if(m + i < xs[i]) dc++;
		}

		if(dc >= (n + 1) / 2){
			l = m;
		}
		else{
			r = m;
		}
	}


    

	for (int i = 0; i < n; ++i){
		yc += abs(r + i - xs[i]);
	}

    cout<<yc<<el;
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