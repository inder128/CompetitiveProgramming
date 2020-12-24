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

int rand(int l, int r){
    return l + rand() % (r - l + 1);
}


void solve(){
    int a = rand(1, 1e9);

    int q = 0;

    while(true){
    	string op; cin>>op;
    	if(op == "!"){
            // terminating condition;
            int ans; cin>>ans;
    		bool correct = (a == ans);

            // write anything;
    		if(correct == false){
    			cout<<"wrong!!!\n";
    		}
    		else{
    			cout<<"right!!!"<<q<<el;
    		}
    		// db(a, ans);
            cout.flush();
    		return;
    	}
        q++;
    	int x, y; cin>>x>>y;
		if((x % a) >= (y % a)){
            cout<<"x"<<el;
        }
        else{
            cout<<"y"<<el;
        }
    	cout.flush();
    }
}
 
int main(int agg, char *argv[]){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = rand(2, 6);
    // cin>>T;
    srand(stoi(argv[1]));
    while(T--){
        cout<<"start\n"; cout.flush();
        solve();
    }
    cout<<"end\n"; cout.flush();
    return 0;
}