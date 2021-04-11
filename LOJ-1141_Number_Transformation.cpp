//Author:Md. Liad Hossain
//KUET ECE 2K18

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#define lld long long int
#define ulld unsigned long long int
#define vl vector<lld>
#define vll vector<pair<lld, lld>>
#define ff first
#define ss second
#define pf push_front
#define pb push_back
#define eb emplace_back
#define pof pop_front
#define pob pop_back
#define fbo find_by_order
#define ofk order_of_key
#define fo(i, a, b) for (lld i = a; i <= b; i++)
#define FOR(i, n) for (lld i = 0; i < n; i++)
#define F0R(j, n) for (lld j = 1; j <= n; j++)
#define ROF(i, n) for (lld i = n - 1; i >= 0; i--)
#define R0F(i, n) for (lld i = n; i >= 1; i--)
#define all(v) v.begin(), v.end()
#define lb lower_bound
#define ub upper_bound
#define er equal_range
#define rs random_shuffle
#define yes printf("YES\n")
#define no printf("NO\n")
#define mod 1000000007LL
#define mod2 998244353LL
#define setbit __builtin_popcount
#define elif else if
#define mem0(a) memset(a, 0, sizeof(a))
#define mem1(a) memset(a, -1, sizeof(a))
#define pi 2 * acos(0.0)
#define inf 9000000000000000000LL
#define T            \
    int t;           \
    scanf("%d", &t); \
    while (t--)
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
void read(int &x)
{
    scanf("%d", &x);
}
void read(lld &x)
{
    scanf("%I64d", &x);
}
void read(lld &a, lld &b)
{
    scanf("%I64d %I64d", &a, &b);
}
void read(lld &a, lld &b, lld &c)
{
    scanf("%I64d %I64d %I64d", &a, &b, &c);
}
void read(lld &a, lld &b, lld &c, lld &d)
{
    scanf("%I64d %I64d %I64d %I64d", &a, &b, &c, &d);
}
void read(double &x)
{
    scanf("%lf", &x);
}
void read(char &x)
{
    scanf("%c", &x);
}
void read(string &x)
{
    char y[1000006];
    scanf("%s", &y);
    x = y;
}

void print(lld x, bool flag = false)
{
    if (flag)
        printf("%I64d ", x);
    else
        printf("%I64d\n", x);
}
void print(int x, bool flag = false)
{
    if (flag)
        printf("%d ", x);
    else
        printf("%d\n", x);
}
void print(double x, bool flag = false)
{
    if (flag)
        printf("%0.14lf ", x);
    else
        printf("%0.14lf\n", x);
}
void print(char x)
{
    printf("%c\n", x);
}

void print(string x)
{
    for (lld i = 0; i < x.size(); i++)
    {
        printf("%c", x[i]);
    }
    printf("\n");
}
//knight moves...
//lld dx[]={-1,-2,-2,-1,1,2,2,1};
//lld dy[]={-2,-1,1,2,2,1,-1,-2};

//grid moves without diagonal
//lld dx[]={0,-1,0,1};
//lld dy[]={-1,0,1,0};
const lld mx=1005;
lld dist[mx];
bool vis[mx];
lld bfs(lld s,lld tar)
{
    if(s>tar)return -1;
    if(s==tar)return 0;

    queue<lld>q;
    q.push(s);
    lld ans=-1;
    dist[s]=0;
    vis[s]=true;
    while(!q.empty())
    {
        lld node=q.front();
        q.pop();
       // cout<<node<<" "<<dist[node]<<endl;
        if(node==tar)
        {
            ans=dist[node];
            break;
        }
        lld tmp=node;
        for(lld i=2;i*i<=tmp;i++)
        {
            if(tmp%i==0)
            {
                while(tmp%i==0)tmp/=i;
                if(node+i<=tar && !vis[node+i])
                {
                    dist[node+i]=dist[node]+1;
                    q.push(node+i);
                    vis[node+i]=true;
                }
            }
        }

        if(tmp>1 && tmp!=node)
        {
            if(node+tmp<=tar && !vis[node+tmp])
            {
                dist[node+tmp]=dist[node]+1;
                q.push(node+tmp);
                vis[node+tmp]=true;
            }
        }
    }

    return ans;
}

int main()
{
/*#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif*/
    lld test=0;
    T
    {
        lld s,tar;
        scanf("%lld %lld",&s,&tar);
        mem0(dist);
        mem0(vis);
        lld ans=bfs(s,tar);
        printf("Case %lld: %lld\n",++test,ans);
    }
    //cerr << "time taken : " << (float)clock() / (float)CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
