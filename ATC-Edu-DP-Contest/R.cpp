#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout<<#x<<"="<<x<<endl
#define deb2(x,y) cout<<#x<<"="<<x<<", "<<#y<<"="<<y<<endl
#define deb3(x,y,z) cout<<#x<<"="<<x<<", "<<#y<<"="<<y<<", "<<#z<<"="<<z<<endl
#define rng(x) x.begin(), x.end()
#define pb push_back
#define F first
#define S second
#define el '\n'

typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<bool> vb;

// Matrix Exponentiation;

typedef vector <vector <ll>> mat;
const ll mod = 1e9 + 7;
ll n; 

void mul(mat &M, mat X){
    mat A =  vector <vl>(n, vl(n));

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            for (int k = 0; k < n; ++k){
                A[i][j] += M[i][k]*X[k][j] % mod;
                A[i][j] %= mod;
            }
        }
    }
    M = A;
}


void solve(){
    cin>>n;
    ll k; cin>>k;
    mat A =  vector <vl>(n, vl(n));
    mat M = vector <vl>(n, vl(n));

    // A is ans;
    // M is curr mat expo;
    for (int i = 0; i < n; ++i){
        A[i][i] = 1;
        for (int j = 0; j < n; ++j){
            cin>>M[i][j];
        }
    }

    while(k){
        if(k%2) mul(A, M);
        k /= 2;
        mul(M, M);
    }

    ll sum = 0;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            sum += A[i][j];
            sum %= mod;
        }
    }
    cout<<sum<<el;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1, tc = 1;
    // cin>>T; 
    while(T--){
        solve();
    }
    return 0; 
}