#include <bits/stdc++.h>
using namespace std;
long long MOD =100000007;

vector<vector<long long>> matmul(vector<vector<long long>> m,vector<vector<long long>> n){
  vector<vector<long long>> result(m.size(),vector<long long>(n[0].size()));
  for(int i=0;i<m.size();i++){
    for(int j=0;j<n[0].size();j++){
      for(int k=0;k<n.size();k++){
        result[i][j]+=m[i][k]*n[k][j];
        result[i][j]%=MOD;
      }
    }
  }
  return result;
}

vector<vector<long long>> matmod(vector<vector<long long>> v,long long n,long long k){
    if(n==0){
      vector<vector<long long>> result(4,vector<long long>(4));
      for(int i=0;i<4;i++){
        result[i][i]=1;
      }
      return result;
    }
    if(n==1){
        return v;
    }
    if(n==2){
        return matmul(v,v);
    }
    else{
        if(n%2==0){
            vector<vector<long long>> tmp=matmod(v,n/2,k);
            return matmul(tmp,tmp);
        }
        else{
            vector<vector<long long>> tmp=matmod(v,n/2,k);
            tmp=matmul(tmp,tmp);
            return matmul(tmp,v);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    long long n;
    cin>>n;
    vector<vector<long long>> a={{1,0,1,0},
                            {1,0,0,0},
                            {0,1,0,1},
                            {0,1,0,1}};
    vector<vector<long long>> v={{2},{1},{2},{2}};
    a=matmod(a,n-3,MOD);
    v=matmul(a,v);
    long long t1=v[0][0],t2=v[1][0],t3=v[2][0],t4=v[3][0];
    cout<<((((t1+t2)%MOD)+t3)%MOD+t4)%MOD;
}

