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
    
    int a,b;
    int prev[n+1];
    queue<int> q;
    bool cycle=false;
    for(int i=1;i<=n;i++)
   {
    if(cycle)
      break;
    if(visited[i])
      continue;
    visited[i]=true;
    
    q.push(i);
    while(!q.empty()&&!cycle)
    {
      int s=q.front();
      q.pop();
      for(int i=0;i<adj[s].size();i++)
      {
        if(!visited[adj[s][i]])
        {
        visited[adj[s][i]]=true;
      
        prev[adj[s][i]]=s;
        q.push(adj[s][i]);
        }
      else if(prev[s]!=adj[s][i])
      {
        a=s;
        b=adj[s][i];
        cycle=true;

                break;
      }
      }
    }
  }
  if(cycle==false)
  {
    cout<<"IMPOSSIBLE";
    return 0;
  }

  while(!q.empty())
  q.pop();    
    for (int i = 0; i < n+1; ++i)
    {
      visited[i]=false;
    }
    
    int prev2[n+1];

    visited[b]=true;
   // cout<<b;
    q.push(b);
    while(!q.empty())
    {
      int s=q.front();
      q.pop();
      for(auto u:adj[s])
      {
     //   cout<<u<<" "<<s<<endl;
        if(visited[u])
          continue;
        if((s==a&&u==b)||(s==b&&u==a))
          continue;
        visited[u]=true;
       
        prev2[u]=s;
       // cout<<u<<" "<<prev2[u]<<endl;
        q.push(u);
      }
    }
   
    vector<int> v;
    int i=a;
    while(i!=b)
    {
      //cout<<i<<" ";
      v.push_back(i);
      
      i=prev2[i];
    }
    v.push_back(b);
    v.push_back(a);
    cout<<v.size()<<endl;

     for (int i = v.size()-1; i > -1; --i)
    {

      cout<<v[i]<<" ";
    }

    return 0;
}
