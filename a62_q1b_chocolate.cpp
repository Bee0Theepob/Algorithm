#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> v(k);
    vector<int> ans(n+5);
    for(int i=0;i<k;i++){
        cin>>v[i];
        ans[v[i]]=1;
    }
    for(int i=0;i<ans.size();i++){
        for(int x:v){
            if(i-x>0){
                ans[i]+=ans[i-x];
                ans[i]%=1000003;
            }
        }
    }
    cout<<ans[n];

}