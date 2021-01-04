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
#ifndef ONLINE_JUDGE 
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define db(...)
#endif
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code Begins--------------------------------*/


struct node{
    int c[2];
};

class BitTrie{
public :
    vector <node> trie;
    int D;
    BitTrie(){
        // numbers should be less that (2 ^ D);
        // size of trie containing all elements less than (2 ^ D) will be (2 ^ (D + 1) - 1);
        D = 30;
        trie.pb({{-1, -1}});
    }

    void insert(int k){
        int curr = 0;
        for(int i = D - 1; i >= 0; --i){
            if(trie[curr].c[k >> i & 1] == -1){
                trie[curr].c[k >> i & 1] = SZ(trie);
                trie.pb({{-1, -1}});
            }
            curr = trie[curr].c[k >> i & 1];
        }
    }

    int XOR(int xr, bool mn = true){
        int curr = 0, num = 0;

        for(int i = D - 1; i >= 0; --i){
            if(xr >> i & 1){
                if(trie[curr].c[mn] != -1){
                    curr = trie[curr].c[mn];
                    num += (1 << i) * mn;
                }
                else{
                    curr = trie[curr].c[!mn];
                    num += (1 << i) * (!mn);
                }
            }
            else{
                if(trie[curr].c[!mn] != -1){
                    curr = trie[curr].c[!mn];
                    num += (1 << i) * (!mn);
                }
                else{
                    curr = trie[curr].c[mn];
                    num += (1 << i) * mn;
                }
            }
        }

        return num ^ xr;
    }
};


class DSU{ 
public: 
    vi size, par;
    int n;

    DSU(int n){ 
        this->n = n; 
        size.assign(n, 1);
        par.resize(n);
        iota(rng(par), 0);
    }

    int getPar(int u){
        return par[u] = (par[u] == u ? u : getPar(par[u]));
    }

    bool unite(int u, int v){
        u = getPar(u), v = getPar(v);
        if(u == v) return false;

        if(size[u] > size[v]) swap(u, v);
        size[v] += size[u], par[u] = v;
        return true;
    }
};


ll ans = 0;


int get(vector <pair <int, pi>>& egs, int n){
    sort(rng(egs));
    DSU dsu(n);
    for(auto ppi : egs){
        if(dsu.unite(ppi.S.F, ppi.S.S)){
            ans += ppi.F;
        }
    }
    return ans;
}


void get(vi& a){
    int n = SZ(a);
    if(n <= 1){
        return;
    }
    vi nums[31];
    BitTrie bt[31];
    for(int i = 0; i < n; ++i){
        if(a[i] == 0){
            nums[0].pb(a[i]);
            bt[0].insert(a[i]);
        }
        else{
            for(int j = 29; j >= 0; --j){
                if(a[i] >> j & 1){
                    nums[j + 1].pb(a[i]);
                    bt[j + 1].insert(a[i]);
                    break;
                }
            }
        }
    }

    vi hb(31);
    int nsz = 31;
    for(int i = 0; i < 31; ++i){
        int j = i;
        for(; j < 31; ++j){
            if(SZ(nums[j])){
                break;
            }
        }
        if(j == 31){
            nsz = i;
            break;
        }
        hb[i] = j;
        swap(bt[i], bt[j]);
        swap(nums[i], nums[j]);
    }


    vector <pair <int, pi>> egs;
    for(int i = 0; i < nsz; ++i){
        for(int j = i + 1; j < nsz; ++j){
            egs.pb({2e9, {i, j}});
            for(int& k : nums[i]){
                mini(egs.back().F, bt[j].XOR(k));
            }
        }
    }

    get(egs, nsz);

    for(int i = 0; i < nsz; ++i){
        for(int& j : nums[i]){
            if(hb[i]){
                j -= (1 << (hb[i] - 1));
            }
        }
        if(hb[i] == 0){
            continue;
        }
        get(nums[i]);
    }
}


void solve(){
    int n; cin >> n;
    vi a(n); cin >> a;
    get(a);
    cout << ans << el;
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