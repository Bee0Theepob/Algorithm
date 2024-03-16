#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
int ans=0;
vector<int> pareto(int l,int r){
    if(l==r){
        return {l};
    }
    int m=(l+r)/2;
    vector<int> left = pareto(l,m);
    vector<int> right = pareto(m+1,r);
    vector<int> result;
    int i=0,j=0;
    while(i<left.size() || j<right.size()){
        if (i == left.size()) result.push_back(right[j++]);
        else if (j == right.size()) result.push_back(left[i++]);
        else{
            if (!(v[left[i]].first <= v[right[j]].first && v[left[i]].second <= v[right[j]].second)) result.push_back(left[i++]);
            else {
                while (i < left.size() && v[left[i]].first <= v[right[j]].first && v[left[i]].second <= v[right[j]].second) i++;
                result.push_back(right[j++]);
            }           
        }
    }
    
    return result;
    
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    v.resize(n);
    for(auto &p:v){
        int x,y;
        cin>>x>>y;
        p={x,y};
    }
    sort(v.begin(),v.end());
    cout<<pareto(0,n-1).size();
}