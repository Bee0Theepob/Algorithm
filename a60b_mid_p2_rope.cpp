#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,a;
    vector<int> v(3);
    cin>>n;
    for(int i=0;i<3;i++){
        cin>>v[i];
    }
    vector<int> ans(n+10);
    for(int i=0;i<3;i++){
        ans[v[i]]=1;
    }
    for(int i=1;i<n+10;i++){
        for(int j=0;j<3;j++){
            if(i-v[j]<0){
                continue;
            }
            else{
                ans[i]=max(ans[i],ans[i-v[j]]+1);
            }
        }
    }
    cout<<ans[n];

}