#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[1000][1000];
int dist[1000][1000];
int dx[1000][1000];
int dy[1000][1000];
int n,m;
int A[2],B[2];

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

  bool visited[n][m];
  for (int i = 0; i < n; ++i)
  {
     for (int j = 0; j < m; ++j)
     {
        cin>>a[i][j];
        if(a[i][j]=='A')
        {
          A[0]=i;
          A[1]=j;
        }
        if(a[i][j]=='B')
        {

          B[0]=i;
          B[1]=j;
        }
        if(a[i][j]=='#')
          visited[i][j]=true;
        else
        visited[i][j]=false;
        dist[i][j]=10000000;
     }
  }  
    int dr[]={1,-1,0,0};
    int dc[]={0,0,1,-1};
    queue<int> x;
    queue<int> y;
    visited[A[0]][A[1]]=true;
    dist[A[0]][A[1]]=0;
    x.push(A[0]);
    y.push(A[1]);
    while(!x.empty())
    {
      int s1=x.front();
      int s2=y.front();
      if(s1==B[0]&&s2==B[1])
        break;
      x.pop();
      y.pop();
      for(int i=0;i<4;i++)
      {
        if(s1+dc[i]>n-1||s1+dc[i]<0||s2+dr[i]>m-1||s2+dr[i]<0)
          continue;
        if(visited[ s1+dc[i] ][ s2 + dr[i] ])
          continue;
        visited[ s1+dc[i] ][ s2 + dr[i] ]=true;
        dist[ s1+dc[i] ][ s2 + dr[i] ] = dist[s1][s2]+1;
        dx[ s1+dc[i] ][ s2 + dr[i] ] = s1;
        dy[ s1+dc[i] ][ s2 + dr[i] ] = s2;
        x.push(s1+dc[i]);
        y.push(s2 + dr[i] );

      }
    }
    if(dist[B[0]][B[1]]==10000000)
    {
      cout<<"NO";
      return 0;
    }
    cout<<"YES"<<endl;
    cout<<dist[B[0]][B[1]]<<endl;
    int i=B[0],j=B[1];
    vector<char> v;
    while(i!=A[0]||j!=A[1])
    {

      if( dx[i][j]-i==1 )
      {
        v.push_back('U');
        i=dx[i][j];
      }
      else if(i-dx[i][j]==1)
      {
        i=dx[i][j];
        v.push_back('D');
      }
      else if( dy[i][j]-j ==1)
      {
        j=dy[i][j];
        v.push_back('L');
      }
      else if( dy[i][j]-j ==-1)
      {
        j=dy[i][j];
        v.push_back('R');
      }
      if(i==A[0]&&j==A[1])
        break;
     

    }

    for(int i=v.size()-1;i>-1;i--)
    {
      cout<<v[i];
    }


    return 0;
}
