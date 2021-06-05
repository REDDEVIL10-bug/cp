#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned int ui;
#define pb push_back
using namespace std;

int n;
void addedge(int u,int vv,vector<int> *v)
{
    v[u].pb(vv);
}
void dfs(int source,bool *visited,vector<int> *v,int &cnt)
{
    visited[source]=true;
    cnt++;
    for(int i:v[source])
    {
        if(visited[i]==false)
            dfs(i,visited,v,cnt);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>n && n!=0)
    {
        vector<int>v[n+1];
        int input1,input2,index=1;
        while(cin>>input1 && input1!=0)
        {
            while(cin>>input2 && input2!=0)
            {
                addedge(input1,input2,v);
            }
        }
        int no;
        cin>>no;
        for(int i=0;i<no;i++)
        {
            int query;
            cin>>query;
            bool visited[n+1]={false};
            int cnt=0;
            for(int i=0;i<v[query].size();i++)
            {
                if(!visited[v[query][i]])
                     dfs(v[query][i],visited,v,cnt);
            }
            cout<<n-cnt;
            for(int i=1;i<=n;i++)
            {
                if(!visited[i])
                    cout<<" "<<i;
            }
            cout<<endl;

        }
    }
}
