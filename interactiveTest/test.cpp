#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define maxi(x, y) x = max(x, (y))
#define mini(x, y) x = min(x, (y))
#define pb push_back
#define F first
#define S second
#define el '\n'
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
    int n = (1<<4);
    vi arr(n);
    iota(rng(arr), 1);
    for (int i = 0; i < n; ++i){
    	int j = rand()%n;
    	swap(arr[i], arr[j]);
    }
    cout<<n<<el; cout.flush();

    while(true){
    	string op; cin>>op;
    	if(op == "!"){
            // terminating condition;
    		bool isWrong = false;
    		int wr = -1;
    		for (int i = 0; i < n; ++i){
    			int x; cin>>x;
    			if(x != arr[i]){
    				isWrong = true;
    				wr = i + 1;
    			}
    		}

            // write anything;
    		if(isWrong){
    			cout<<"wrong!!!\n";
    		}
    		else{
    			cout<<"right!!!\n";
    		}
    		cout<<arr<<el;
    		return;
    	}
    	int i, j; cin>>i>>j;
		i--, j--;
    	if(op == "AND"){
    		cout<<(arr[i] & arr[j])<<el;
    	}
    	else if(op == "XOR"){
    		cout<<(arr[i] ^ arr[j])<<el;
    	}
    	else{
    		cout<<(arr[i] | arr[j])<<el;
    	}
    	cout.flush();
    }
}
 
int main(int agg, char *argv[]){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin>>T;
    srand(stoi(argv[1]));
    while(T--){
        solve();
    }
    return 0;
}