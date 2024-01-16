#include <iostream>
#include <vector>
#include<map>
#include<set>

using namespace std;


void ahhh(int n,int len,vector<int>& v,int k,int c,bool trig){
    if(len<n){
        if(c>=k){
            trig=true;
        }
        v[len]=0;
        ahhh(n,len+1,v,k,0,trig);
        v[len]=1;
        ahhh(n,len+1,v,k,c+1,trig);
    }
    else{
        if(trig || c>=k){
            for(int x:v){
                cout<<x;
            }
            cout<<'\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    ahhh(n,0,v,k,0,0);
}