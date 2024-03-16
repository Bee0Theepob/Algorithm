#include <bits/stdc++.h>
using namespace std;
int main() {
    // ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m;
    cin>>n>>m; 
    n++;m++;
    string a,b;
    cin>>a>>b;
    vector<vector<int>> v(n,vector<int>(m));
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
            cin>>v[i][j];
        }
    }
    string result="";
    int i=v.size()-1,j=v[0].size()-1;
    while(v[i][j]!=0){
        if(v[i][j]==v[i-1][j-1]+1){
            result=a[i-1]+result;
            i--;j--;
        }
        else if(v[i][j]==v[i-1][j]){
            i--;
        }
        else{
            j--;
        }

    }
    cout<<result;
}