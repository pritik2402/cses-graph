#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
vector<int> adj[100000+1];
bool visited[100000+1];
void dfs(int s)
{
  visited[s]=true;
  for(int i=0;i<adj[s].size();i++)
  {
    if(visited[adj[s][i]]==false)
      dfs(adj[s][i]);
  }
}

void initialize()
{
  for (int i = 0; i < n+1; ++i)
  {
    visited[i]=false;
  }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

  #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
  #endif
    
  cin>>n>>m;
  int x,y;
  for (int i = 0; i < m; ++i)
  {
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int cc=0;
  vector<int> v;
  initialize();
  for (int i = 1; i <= n; ++i)
  {
    if(visited[i]==false)
    {
      dfs(i);
      cc++;
      v.push_back(i);
    }
  }

  cout<<cc-1<<endl;
  for (int i = 0; i < v.size()-1;++i)
  {
    cout<<v[i]<<" "<<v[i+1]<<endl;
  }

    return 0;
}
