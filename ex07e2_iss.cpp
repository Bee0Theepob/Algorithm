#include<bits/stdc++.h>
using namespace std;
int ans=0;
void letsgo(int n,int len,int sum,int last){
    if(sum==n) ans++;
    if(sum>n) return ;
    else{
        for(int i=last;i<=n;i++){
            letsgo(n,len+1,sum+i,i);
        }
    }
}

int  main(){
    int n;
    cin>>n;
    letsgo(n,0,0,1);
    cout<<ans;
    return 0;
}