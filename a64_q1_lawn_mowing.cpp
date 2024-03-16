#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n,m,k;
  cin>>n>>m>>k;
  vector<int> v(n+5),summ(n+1),price(n+1);
  for(int i=1;i<=n;i++){
    cin>>v[i];
    summ[i]=summ[i-1]+v[i];
    price[i]=summ[i]+(i*k);
  }
  while(m--){
    int a,b;
    cin>>a>>b;
    auto it = upper_bound(price.begin(),price.end(),b+price[a]);
    if(it!=price.begin()){
        it--;
    }
    int x=it-price.begin();
    x=summ[x]-summ[a];
    cout<<x<<'\n';
  }
}