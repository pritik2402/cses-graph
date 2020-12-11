#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,t;
vector<pair<int,int>> adj[500+1];
ll dp[501][501];
bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
} 

void bfs(int a)
{
  bool visited[n+1];
  
    ll distance[n+1];
   
     for (int i = 0; i < n+1; ++i)
    {
      distance[i]=1e15;
      visited[i]=false;
    }
    priority_queue<pair<ll,int>> q;
    distance[a]=0;
    q.push({0,a});
    while(!q.empty())
    {
      int s=q.top().second;
      q.pop();
      if(visited[s])
        continue;
      visited[s]=true;
      for (auto u:adj[s])
      {
       
        ll b=u.first,w=u.second;
        if(distance[s]+w<distance[b])
        {
          distance[b]=distance[s]+w;
          q.push({-distance[b],b});
        }
      }
    }
    for (int i = 1; i < n+1; ++i)
    {
      dp[a][i]=distance[i];
      dp[i][a]=distance[i];
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
  
  
    cin>>n>>m>>t;
    
  
    int x,y,z;
    for (int i = 0; i < m; ++i)
    {
      cin>>x>>y>>z;
      adj[x].push_back(make_pair(y,z));
      adj[y].push_back(make_pair(x,z));
      
    }
    for (int i = 0; i < n+1; ++i)
    {
      for (int j = 0; j < n+1; ++j)
      {
        dp[i][j]=-1;
      }
    }
    for (int i = 0; i < n+1; ++i)
    {
      sort(adj[i].begin(), adj[i].end(), sortbysec);
    }
    for (int i = 1; i < n+1; ++i)
    {
      bfs(i);
    }
  while(t--)
  {
    int a,b;
    cin>>a>>b;
    
    
    if(dp[a][b]==1e15)
      cout<<"-1\n";
    else
      cout<<dp[a][b]<<"\n";
  }
   
    return 0;
}
