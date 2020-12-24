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

// ICPC'19 online round india;
// https://www.codechef.com/ICPCIN19/problems/BEAUTPAR;


vi LIS(vi &arr, int up){
    int n = SZ(arr);

    // lb[i] is the smallest and last element of a lis of length i + 1 till now;
    // lbi[i] is the index of lb[i] in the array;
    // lasti[i] is the index of element of arr which comes before lb[i] in the lis;
    vi lb(n, 1e18), lbi(n, -1), lasti(n, -1); 

    for (int i = 0; i < n; ++i){
        // constraints if necessry;;
        if(arr[i] <= 0) continue;
        if(arr[i] >= up) continue;

        // longest strictly increasing subsequence;
        int ui = lower_bound(rng(lb), arr[i]) - lb.begin();

        // longest non-decreasing subsequence'
        // int ui = upper_bound(rng(lb), arr[i]) - lb.begin();

        lb[ui] = arr[i], lbi[ui] = i;
        if(ui){
            lasti[i] = lbi[ui - 1];   
        }
    }

    int lisSize = 0;
    for (int i = 0; i < n; ++i){
        if(lb[i] < 1e18){
            lisSize = i;
        }
    }

    vi lis;
    int curr_i = lbi[lisSize];
    while(curr_i != -1){
        lis.pb(curr_i);
        curr_i = lasti[curr_i];
    }
    reverse(rng(lis));


    return lis;
}

void solve(){
    int n, k; cin>>n>>k;
    vi arr(n); cin>>arr;
    for(int i = 1; i < n; ++i){
        arr[i] += arr[i - 1];
    }

    if(n == 1){
        // k = 1;
        if(arr[0] > 0){
            cout<<"YES\n1\n";
        }
        else{
            cout<<"NO\n";
        }
        return;
    }


    int up = arr.back();
    arr.pop_back();

    if(up <= 0){
        cout<<"NO\n";
        return;
    }

    vi lis = LIS(arr, up);

    if(k > SZ(lis) + 1){
        cout<<"NO\n";
        return;
    }

    cout<<"YES\n";

    while(SZ(lis) >= k){
        lis.pop_back();
    }
    lis.pb(n - 1);
    lis.insert(lis.begin(), -1);

    for(int i = 1; i < SZ(lis); ++i){
        cout<<(lis[i] - lis[i - 1])<<" ";
    }
    cout<<el;
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