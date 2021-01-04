#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <numeric>
#include <deque>
#include <cstring>
#include <iterator>
#include <map>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <complex>
#include <bitset>
#include <chrono>
#include <random>
#include <assert.h>
#include <array>

using namespace std;

template<typename M, typename N>
istream& operator>>(istream&is, pair<M,N> & p){is >> p.first >> p.second; return is;}
template<typename M>
istream& operator>>(istream&is, vector<M> & v){for(auto &it:v) is >> it; return is; }
template<typename M>
istream& operator>>(istream&is, vector<vector<M>> & v){for(auto &it:v) is >> it; return is; }
template<typename M, typename N>
ostream& operator<<(ostream&os, const pair<M,N> &p){os << p.first << ' ' << p.second << '\n';return os;}
template<typename M>
ostream& operator<<(ostream&os, const vector<M> &v){for(auto it: v)os << it << ' ';cout << '\n';return os;}
template<typename M>
ostream& operator<<(ostream&os, const vector<vector<M>> &v){for(auto it: v)os << it;return os;}

#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define mn(x) *min_element((x).begin(),(x).end())
#define mx(x) *max_element((x).begin(),(x).end())
#define acc(x) accumulate((x).begin(),(x).end(),0ll)
#define unique(x) sort(all(x)); x.erase(unique(all(x)),x.end());
#define eb emplace_back
#define el '\n'
typedef  long long  ll;
typedef  unsigned long long  ull;
typedef long double ld;
typedef complex<long double> cd;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<string> vs;

const ld pi=acos(-1);
const ll inf=(ll)1e9+10;
const int mod=1000000007;
//const int mod=998244353;

int n, m, k;
const int N=2e5+10;

vi v(N);


struct trie{
    struct node{
        node * c[2];
        node(): c(){}
    };
    node * root;
    const int LOG;
    int size;
    trie(int l): root(new node), LOG(l), size(0){};
    template<typename M>
    void insert(M no){
        size++;
        node * temp=root;
        for(int i=LOG; i>=0; i--){
            if(temp->c[no>>i&1]==NULL)temp->c[no>>i&1]=new node;
            temp=temp->c[no>>i&1];
        }
    }

    int min(int no){
        if(size==0)return 0;
        node * temp=root;
        int ans=0;
        for(int i=LOG; i>=0; i--){
            if(temp->c[no>>i&1]!=NULL){
                temp=temp->c[no>>i&1];
            }
            else{
                assert(temp->c[(no>>i&1)^1]!=NULL);
                temp=temp->c[(no>>i&1)^1];
                ans+=(1<<i);
            }
        }
        return ans;
    }
    template<typename M>
    int gt(M no){
        return size-lte(no);
    }
    
    template<typename M>
    int range(M l, M r){
        return lte(r)-lte(l-1);
    }
};


int clz(int n){
    return n==0?0:__builtin_clz(n);
}

ll rec(int l, int r){
    if(l==r)return 0;
    else if(r==l+1)return v[l]^v[r];
    else if(v[l]==v[r])return 0ll;
    int l_=l;
    ll ans=0;
    trie t(30);
    for(int i=l; i<=r; i++){
        if(clz(v[i])!=clz(v[l_])){
            int p=31-clz(v[l_]);
            p=1<<p;
            int mn=inf;
            for(int j=l_; j<i; j++){
                mn=min(mn,t.min(v[j]));
                v[j]^=p;
            }
            ans+=mn;
            ans+=rec(l_,i-1);
            for(int j=l_; j<i; j++){
                v[j]^=p;
                t.insert(v[j]);
            }
            l_=i;
        }
    }
    int p=31-clz(v[l_]);
    p=1<<p;
    int mn=inf;
    for(int j=l_; j<=r; j++){
        mn=min(mn,t.min(v[j]));
        v[j]^=p;
    }
    ans+=mn;
    ans+=rec(l_,r);
    for(int j=l_; j<=r; j++){
        v[j]^=p;
    }
    return ans;
};



int main()
{   ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    v.resize(n);
    unique(v);
    n=(int)v.size();
    cout << rec(0,n-1) << el;
    return 0;
}
