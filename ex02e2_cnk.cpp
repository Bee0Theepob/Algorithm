#include<bits/stdc++.h>
using namespace std;

int c(int n, int k){
    if(n==k || k==0){
        return 1;
    }
    else{
        return c(n-1,k-1)+c(n-1,k);
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k;
    cin>>n>>k;
    cout<<c(n,k);
}