#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int f,w,n;
    cin>>f>>w>>n;
    if(w==0){
        cout<<f;
        return 0;
    }
    vector<int> food(f);
    for(int i=0;i<f;i++){
        cin>>food[i];
    }
    sort(food.begin(),food.end());
    int cnt=1;
    auto it=upper_bound(food.begin(),food.end(),food[0]+2*w);
    while(it!=food.end()){
        cnt++;
        it=upper_bound(food.begin(),food.end(),*it+2*w);
    }
    cout<<cnt;
}
