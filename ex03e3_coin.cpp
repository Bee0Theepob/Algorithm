#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    vector<int> ans(m+5,INT_MAX);
    for(int i=0;i<n;i++){
        cin>>v[i];
        ans[v[i]]=1;
    }
    for(int i=0;i<ans.size();i++){
        for(int value:v){
            if(i-value>0){
                ans[i]=min(ans[i],ans[i-value]+1);
            }
        }
    }
    cout<<ans[m];
}
