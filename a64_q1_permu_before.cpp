#include <iostream>
#include <vector>
#include<map>
#include<set>

using namespace std;

map<int,set<int>> mp;

void permu(int n,vector<int> &sol,int len, vector<bool> &used) {
  if (len < n) {
    for (int i = 0;i < n;i++) {
      if (!used[i]) {
        sol[len] = i;
        used[i] = true;
        bool check=false;
        if(mp.find(i)!=mp.end()){
          for(auto it=mp[i].begin();it!=mp[i].end();it++){
            used[*it]=false;
          }
          check=true;
        }
        permu(n,sol,len+1,used);
        used[i] = false;
        if(true){
          for(auto it=mp[i].begin();it!=mp[i].end();it++){
            used[*it]=true;
          }
        }
      }
    }
  } else {
    for (int i = 0;i < n;i++) {
      cout << sol[i] << " ";
    }
    cout << "\n";
  }
}
vector<int> a,b;
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n,m;
  cin >> n >> m;
  a.resize(n);
  b.resize(n);
  vector<int> sol(n);
  vector<bool> used(n);
  for (int i = 0;i < m;i++) {
    cin >> a[i] >> b[i];
    used[b[i]]=true;
    mp[a[i]].insert(b[i]);
  }

  permu(n,sol,0,used);

}