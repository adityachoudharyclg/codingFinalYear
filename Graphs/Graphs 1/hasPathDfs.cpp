#include <iostream>
using namespace std;
int hasPath(int **edges,int v,int sv,int ev,bool *visited)
{
    if(edges[sv][ev])
        return 1;
    visited[sv]=true;
    for(int i=0;i<v;i++)
    {
        if(!visited[i]&&edges[sv][i])
        {
            if(hasPath(edges,v,i,ev,visited))
                return 1;
        }
    }
    return 0;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int V, E;
    cin >> V >> E;

    int **edges=new int*[V];
    for(int i=0;i<V;i++)
    {
        edges[i]=new int[V];
        for(int j=0;j<V;j++)
            edges[i][j]=0;
    }
    for(int i=0;i<E;i++)
    {
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    int sv,ev;
    cin>>sv>>ev;
    bool *visited=new bool[V];
    for(int i=0;i<V;i++)
        visited[i]=false;
    string s=hasPath(edges,V,sv,ev,visited)?"true":"false";
    cout<<s; 
    return 0;
}
