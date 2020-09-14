#include <bits/stdc++.h>
using namespace std;

void solve(){
    string str; cin>>str;
    int n = str.length();

    vector <int> dec(n+1);
    dec[n] = 1;
    for(int i = n-1; i >= 0; i--){
        if(str[i] == '>')
            dec[i] = dec[i+1] + 1;
        else
            dec[i] = 1;
    }

    string ans;
    ans.push_back((char)('a' + dec[0] - 1));
    char curr = (char)('a' + dec[0]);
    for(int i = 0; i < n; i++){
        if(str[i]=='>'){
            ans.push_back((char)(ans.back()-1));
        }
        else{ // <
            curr = (char)(curr + dec[i+1]);
            ans.push_back((char)(curr - 1));
        }
    }

    cout<<ans<<"\n";
}

int main(){
    int t; cin>>t;
    while(t--) solve();
}