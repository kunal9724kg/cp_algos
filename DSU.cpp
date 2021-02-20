#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll>parent(100005,0);
vector<ll>weight(100005,0);

void create(ll a)
{
    parent[a]=a;
    weight[a]=1;
}

ll findParent(ll a)
{
    if(parent[a]!=a)
    {
        parent[a]=findParent(parent[a]);            // Path Compression optimization
    }
    return parent[a];
}

void merge(ll a, ll b)
{
    a=findParent(a);
    b=findParent(b);
    
    if(a==b) return;

    if(weight[a]<weight[b])                         // Union by weight optimization
    {
        swap(a,b);
    }

    parent[b]=a;
    weight[a]+=weight[b];

}

int main(){
    int numberOfNodes; cin>>numberOfNodes;
    int i;
    for(i=1;i<=numberOfNodes;i++)
    {
        create(i);
    }

    //call merge() if query is to make_union.

    //call findParent() to find the representative element of that set.
    return 0;
}