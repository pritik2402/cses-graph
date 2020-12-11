#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[1000][1000];
int n,m;
void fill(int i,int j)
{
  if(a[i][j]=='#'||a[i][j]=='x')
    return;
  a[i][j]='x';
  if(i>0)
    fill(i-1,j);
  if(j>0)
    fill(i,j-1);
  if(i<n-1)
    fill(i+1,j);
  if(j<m-1)
    fill(i,j+1);

  return;  
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

  for (int i = 0; i < n; ++i)
  {
     for (int j = 0; j < m; ++j)
     {
        cin>>a[i][j];
     }
  }  
  int ans=0;
  for (int i = 0; i < n; ++i)
  {
     for (int j = 0; j < m; ++j)
     {
        if(a[i][j] =='.')
        {
          ans++;
          fill(i,j);
        }
     }
  }   

  cout<<ans;

    return 0;
}
