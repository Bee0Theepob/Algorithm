#include <iostream>
#include <vector>
#include<map>
#include<set>

using namespace std;


void ahhh(int n,int len,vector<int>& v,int k,int c){
    if(len<n){
        if(n-len>=k-c+1){
            v[len]=0;
            ahhh(n,len+1,v,k,c);
        }
        if(c<k){
             v[len]=1;
            ahhh(n,len+1,v,k,c+1);
        }
       
    }
    else{
        for(int x:v){
            cout<<x;
        }
        cout<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,k;
    cin>>k>>n;
    vector<int> v(n);
    ahhh(n,0,v,k,0);
}