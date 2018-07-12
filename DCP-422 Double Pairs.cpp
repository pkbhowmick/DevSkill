#include <bits/stdc++.h>
#define pb push_back
#define sc1(n) scanf("%lld",&n)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define MX 100000
using namespace std;

typedef long long int ll;
typedef unsigned long long ul;

unordered_map<ll,ll>mp;

ll arr[100005];
ll tree[800005];

void update(ll n,ll L,ll R,ll pos)
{
    if(L==R)
    {
        tree[n]++;
        return;
    }
    ll mid=(L+R)/2;
    if(pos<=mid)
        update(2*n,L,mid,pos);
    else
        update(2*n+1,mid+1,R,pos);

    tree[n]=tree[2*n]+tree[2*n+1];
}
ll query(ll n,ll L,ll R,ll l,ll r)
{
    if(r<L || R<l)
        return 0;
    if(l<=L&&R<=r)
        return tree[n];

    ll mid=(L+R)/2;
    ll x=query(n*2,L,mid,l,r);
    ll y=query(n*2+1,mid+1,R,l,r);

    return x+y;
}
int main()
{
    ll test;
    sc1(test);

    while(test--)
    {
        memset(tree,0,sizeof tree);
        ll n;
        mp.clear();
        //ll n;
        set<ll>S;
        sc1(n);
        for(ll i=1; i<=n; i++)
        {
            ll v;
            sc1(arr[i]);
            S.insert(arr[i]);
            S.insert(arr[i]/2);
        }

        auto it=S.begin();
        ll now=0;
        ll mx=S.size();
        while(it!=S.end())
        {
            ll nn=(ll)(*it);
            if(mp.count(nn)==0)
            {
                mp[nn]=++now;
                //cout<<nn<<" "<<now<<endl;
            }
            it++;
        }
        ll ans=0;
        for(ll i=1; i<=n; i++)
        {
            ll now=arr[i];
            now=now/2;
            now=mp[now];
            ans+=query(1,1,mx,1,now);
            //cout<<"query "<<now<<endl;
            update(1,1,mx,mp[arr[i]]);
            //cout<<"update "<<mp[arr[i]]<<endl;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
