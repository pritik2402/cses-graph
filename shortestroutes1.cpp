#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



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
  int n,m;
  
    cin>>n>>m;
    vector<pair<int,int>> adj[n+1];
    bool visited[n+1];
    ll distance[n+1];
    for (int i = 0; i < n+1; ++i)
    {
      distance[i]=1e15;
      visited[i]=false;
    }
    int x,y,z;
    for (int i = 0; i < m; ++i)
    {
      cin>>x>>y>>z;
      adj[x].push_back(make_pair(y,z));
      
    }
    priority_queue<pair<ll,int>> q;
    distance[1]=0;
    q.push({0,1});
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
      cout<<distance[i]<<" ";
    }
   
    return 0;
}
