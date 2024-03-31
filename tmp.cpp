#include<bits/stdc++.h>
using namespace std;
vector<int> a,b;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;
    cin>>n;
    while(n--){
      cin>>m;
      a.push_back(m);
      b.push_back(m);
    }
    sort(b.begin(),b.end());
    vector<vector<int>> ans(a.size(),vector<int>(a.size()));
    for(int i=1;i<a.size();i++){
      for(int j=1,j<b.size();j++){
        if(a[i]==b[j]){
          ans[i][j]=ans[i-1][j-1]+1;
        }
        else{
           ans[i][j]=max(ans[i-1][j],ans[i][j-1]);
        }
      }
    }
    cout<<ans[a.size()-1][b.size()-1];
}