#include <iostream>
#include <vector>
using namespace std;

void combi(int n,vector<int> &sol,int len){
    if(len<n){
        sol[len]=0;
        combi(n,sol,len+1);    
        sol[len]=1;
        combi(n,sol,len+1);
    }
    else{
        for(auto x:sol){
            cout<<x;
        }
        cout<<'\n';
    }
}

void perm(int n ,vector<int> v,int ln){
    if(ln<n){
        
    }
    else{
        for(int x:v){
            cout<<x;
        }
        cout<<'\n';
    }
}


int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    combi(n,v,0);
}