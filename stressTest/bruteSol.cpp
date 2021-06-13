#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
vector<int>v,ans;
int m;
 
void dfs(int cnt,int prev,int sum1,int sum2)
{
    if(cnt==m)
    {
        cout<<"YES"<<endl;
        for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
        exit(0);
    }
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==prev)
        continue;
        if(cnt%2==0)
        {
            if(sum1+v[i]>sum2)
            {
                ans.push_back(v[i]);
                dfs(cnt+1,v[i],sum1+v[i],sum2);
                ans.pop_back();
            }
        }
        else
        {
            if(sum2+v[i]>sum1)
            {
                ans.push_back(v[i]);
                dfs(cnt+1,v[i],sum1,sum2+v[i]);
                ans.pop_back();
            }
        }
    }
}
 
int main() 
{
    int t; cin >> t;
    while(t--){
    string s;
    cin>>s;
    cin>>m;
    for(int i=0;i<10;i++)
    {
        if(s[i]=='1')
        {
            v.push_back(i+1);
        }
    }
    dfs(0,0,0,0);
    cout<<"NO" << endl;
}
    return 0;
}