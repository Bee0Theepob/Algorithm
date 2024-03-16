#include <bits/stdc++.h>
using namespace std;


vector<long long> multiply(vector<long long> &M,vector<long long> &N,int k){
    vector<long long> result(M.size());
    result[0]=(((M[0]*N[0])%k)+((M[1]*N[2])%k))%k;
    result[1]=(((M[0]*N[1])%k)+((M[1]*N[3])%k))%k;
    result[2]=(((M[2]*N[0])%k)+((M[3]*N[2])%k))%k;
    result[3]=(((M[2]*N[1])%k)+((M[3]*N[3])%k))%k;
    return result;
}

vector<long long> matmod(vector<long long> v,long long n,int k){
    if(n==1){
        return v;
    }
    if(n==2){
        return multiply(v,v,k);
    }
    else{
        if(n%2==0){
            vector<long long> tmp=matmod(v,n/2,k);
            return multiply(tmp,tmp,k);
        }
        else{
            vector<long long> tmp=matmod(v,n/2,k);
            tmp=multiply(tmp,tmp,k);
            return multiply(tmp,v,k);
        }
    }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
    long long n,k;
    cin>>n>>k;
    vector<long long> v(4);
    for(int i=0;i<4;i++){
        cin>>v[i];
    }
    vector<long long> ans=matmod(v,n,k);
    for(auto x:ans){
        cout<<x<<' ';
    }
    
}