#include <bits/stdc++.h>
using namespace std;
int n,k,a,b;
vector<vector<int>> multiply(vector<vector<int>> &M,vector<vector<int>> &N){
    vector<vector<int>> result;
    vector<int> tmp;
    for(int i=0;i<n;i++){
        result.push_back(tmp);
    }
    for(int i=0;i<n;i++){
        result[i].resize(n);
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                result[i][j]+=(M[i][k]*N[k][j]);
            }
        }
    }
    return result;
}

vector<vector<int>> power(vector<vector<int>> &v,int n){
    if(n==1){
        return v;
    }
    if(n==2){
        return multiply(v,v);
    }
    else{
        if(n%2==0){
            vector<vector<int>> tmp=power(v,n/2);
            return multiply(tmp,tmp);
        }
        else{
            vector<vector<int>> tmp=power(v,n/2);
            tmp=multiply(tmp,tmp);
            return multiply(tmp,v);
        }
    }
}

int main() {
    //ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>n>>k;
    vector<vector<int>> v(n,vector<int>(n,0));
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        v[a-1][b-1]++;
        v[b-1][a-1]++;
    }
    cout<<"------------------------------------\n";
    for(vector<int> arr:v){
        for(int x:arr){
            cout<<x<<' ';
        }
        cout<<'\n';
    }
    cout<<"------------------------------------\n";
    vector<vector<int>> ans=power(v,k);
    for(vector<int> arr:ans){
        for(int x:arr){
            cout<<x<<' ';
        }
        cout<<'\n';
    }
}