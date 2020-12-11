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
    vector<int> adj[n+1];
   
    int color[n+1];
    for (int i = 0; i < n+1; ++i)
    {
      
      color[i]=100000;
    }
    int x,y;
    for (int i = 0; i < m; ++i)
    {
      cin>>x>>y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    
    bool isBipartite=true;
   for(int i=1;i<=n;i++)
   {
    if(color[i]!=100000)
      continue;
    queue<int> q;
    color[i]=0;
    
    q.push(i);
    while(!q.empty()&&isBipartite)
    {
      int s=q.front();
      q.pop();
      for(auto u:adj[s])
      {
        if(color[u]==100000)
        {
          color[u]=1-color[s];
          q.push(u);
        }
        else if(color[u]==color[s])
        {
          isBipartite=false;
          break;
        }
      }
    }
   }
   if(isBipartite==false)
   {
    cout<<"IMPOSSIBLE";
    return 0;
   }
   for (int i = 1; i < n+1; ++i)
   {
     cout<<color[i]+1<<" ";
   }
    return 0;
}
