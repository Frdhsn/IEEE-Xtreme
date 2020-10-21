
// DSU, TREE
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD  = 1e9+7,MAX=1e5+10;
ll par[MAX],sz[MAX];
int find_par(int x){
    if(par[x]==x)return x;
    return par[x] = find_par(par[x]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        par[i]=i;
        sz[i]=1;
    
    }
    
    vector< pair<ll, pair<ll,ll> > > edge;
    for(int i=1;i<=n-1;i++){
        ll u,v,w;cin>>u>>v>>w;
        edge.push_back({w,{u,v}});
    }
    sort(edge.begin(),edge.end());
    ll res =0;
    for(int i=0;i<n;i++){
        ll w = edge[i].first;
        int l = find_par(edge[i].second.first);
        int r = find_par(edge[i].second.second);
        res = res%MOD + ((sz[l]*sz[r])%MOD * w)%MOD;
        res%=MOD;
        par[r]=l;
        sz[l]+=sz[r];
    }
    cout<<res<<"\n";
    return 0;
}
