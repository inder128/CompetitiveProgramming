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


bool get(vi &A, int k, int n){
	// sum is n;
	// no are k;
	int sum = k * 2;
	for(int i = k - 1; i >= 0; --i){
		while (sum + A[i] <= n){ 
            sum += A[i]; 
            A[i] *= 2; 
        }
	}

	if(sum != n) return false;
	return true;
}

int give(vi A){
	int sum = 0;
	for(int i : A){
		while(i != 1){
			i /= 2;
			sum++;
		}
	}
	return sum;
}


void solve(){
    int k; cin>>k;
    if(k % 2 ){
    	cout<<-1<<el;
    	return;
    }
    k /= 2;

    for(int n = 1; n <= 2000; ++n){
    	vi ans(n, 2);
    	bool sol = get(ans, n, k + n);
    	if(sol == false) continue;
    	int cnt = give(ans);
    	if(cnt > 2000) continue;

    	cout<<cnt<<el;
    	cout<<"1 ";
    	int ptr = 0;
    	for(int i = 1; i < cnt; ++i){
    		ans[ptr] /= 2;
    		if(ans[ptr] == 1){
    			cout<<1<<" ";
    		}
    		else{
    			cout<<0<<" ";
    		}
    		if(ans[ptr] == 1) ptr++;
    	}
    	cout<<el;

    	return;
    }

    cout<<-1<<el;
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