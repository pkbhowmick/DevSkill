#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long int ll;
vector<ll>V;
void sc(ll &number)
{
    //variable to indicate sign of input number
    bool negative = false;
    register ll c;

    number = 0;

    // extract current character from buffer
    c = getchar();
    if (c=='-')
    {
        // number is negative
        negative = true;

        // extract the next character from the buffer
        c = getchar();
    }

    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;

    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    V.pb(1);
    V.pb(4096);
    V.pb(531441);
    V.pb(16777216);
    V.pb(244140625);
    V.pb(2176782336);
    V.pb(13841287201);
    V.pb(68719476736);
    V.pb(282429536481);
    V.pb(1000000000000);
    V.pb(3138428376721);
    V.pb(8916100448256);
    V.pb(23298085122481);
    V.pb(56693912375296);
    V.pb(129746337890625);
    V.pb(281474976710656);
    V.pb(582622237229761);
    V.pb(1156831381426176);
    V.pb(2213314919066161);
    V.pb(4096000000000000);
    V.pb(7355827511386641);
    V.pb(12855002631049216);
    V.pb(21914624432020321);
    V.pb(36520347436056576);
    V.pb(59604644775390625);
    V.pb(95428956661682176);
    V.pb(150094635296999121);
    V.pb(232218265089212416);
    V.pb(353814783205469041);
    V.pb(531441000000000000);
    V.pb(787662783788549761);
    ll test;
    ll ans;
    ll a,b;
    sc(test);
    while(test--)
    {
        sc(a);
        sc(b);
        ans=0;
        for(ll i=0;i<31;i++)
        {
            if(V[i]>=a&&V[i]<=b)
                ans++;
            else if(V[i]>b)
                break;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
