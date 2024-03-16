#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,a;
    cin>>n;
    int sizz=2*n-1;
    vector<vector<int>> v(sizz,vector<int>());
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a;
            v[sizz/2-i+j].push_back(a);
        }
    }
    int ans=INT_MIN;
    for(vector<int> vec:v){
        int tmp=vec[0];
        ans=max(ans,tmp);
        for(int i=1;i<vec.size();i++){
            tmp=max(tmp+vec[i],vec[i]);
            ans=max(ans,tmp);
        }
    }
    cout<<ans;
}