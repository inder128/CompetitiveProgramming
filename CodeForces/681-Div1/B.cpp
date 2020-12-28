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

// void solve(){
// 	int n; cin>>n;
//     vi a(n);
//     cin>>a;

//     int ld, rd;
//     vi dec(n), decr(n);
//     for (int i = 0; i < n; ++i){
//     	if(i == 0 or a[i - 1] >= a[i]){
//     		dec[i] = 1;
//     		ld = i;
//     	}
//     	else{
//     		break;
//     	}
//     }

//     for (int i = n - 1; i >= 0; --i){
//     	if(i == n - 1 or a[i] <= a[i + 1]){
//     		decr[i] = 1;
//     		rd = i;
//     	}
//     	else{
//     		break;
//     	}
//     }
    
//     int todec = 0;
//     for (int i = ld + 1; i < rd; ++i){
//     	a[i] -= todec;
//     	if(a[i] < 0){
//     		cout<<"NO\n";
//     		return;
//     	}
//     	todec += max(a[i] - a[i - 1], 0ll);
//     	a[i] = min(a[i], a[i - 1]);
//     }

//     if(todec > a[rd]){
//     	cout<<"NO\n";
//     	return;
//     }
//     cout<<"YES\n";
// }

void solve(){
    int n; cin>>n;
    vi a(n);
    cin>>a;

    int dec = a[0], inc = 0;
    for (int i = 1; i < n; ++i){
        if(a[i] < inc){
            cout<<"NO\n";
            return;
        }
        a[i] -= inc;
        dec = min(dec, a[i]);
        a[i] -= dec;
        inc += a[i];
    }
    cout<<"YES\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}