#include <iostream>
#include<cmath>

using namespace std;

int pow_mod(int a,int n, int k){
    if(n==1){
        return  a%k;
    }
    if(n%2==0){
        int tmp=pow_mod(a,n/2,k);
        return (tmp*tmp)%k;
    }
    else{
        int tmp=pow_mod(a,n/2,k);
        tmp=(tmp*tmp)%k;
        return (tmp*(a%k))%k;
    }

   
   
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int a,n,x,result=1;
    cin>>a>>n>>x;
    cout<<pow_mod(a,n,x);
}