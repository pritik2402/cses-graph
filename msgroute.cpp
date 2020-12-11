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
    bool visited[n+1];
    for (int i = 0; i < n+1; ++i)
    {
      visited[i]=false;
    }
    int x,y;
    for (int i = 0; i < m; ++i)
    {
      cin>>x>>y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    
    int distance[n+1];
    int prev[n+1];
    queue<int> q;
    visited[1]=true;
    distance[1]=0;
    q.push(1);
    while(!q.empty())
    {
      int s=q.front();
      q.pop();
      for(auto u:adj[s])
      {
        if(visited[u])
          continue;
        visited[u]=true;
        distance[u]=distance[s]+1;
        prev[u]=s;
        q.push(u);
      }
    }
    if(visited[n]==false)
    {
      cout<<"IMPOSSIBLE";
      return 0;
    } 
    cout<<distance[n]+1<<endl;
    vector<int> v;
    int i=n;
    while(i!=1)
    {
      v.push_back(i);
      i=prev[i];
    }
    v.push_back(1);
    for (int i = v.size()-1; i > -1; --i)
    {
      cout<<v[i]<<" ";
    }

    return 0;
}
