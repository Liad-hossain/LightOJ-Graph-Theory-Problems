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
lld dx[]={0,-1,0,1};
lld dy[]={-1,0,1,0};

string grid[20];
bool vis[20][20];
lld dist[20][20];
lld r,c;
queue<pair<lld,lld>>qq;
bool isvalid(lld x,lld y)
{
    if(x<0 || x>=r || y<0 || y>=c)return false;

    if(vis[x][y] || grid[x][y]=='#' || grid[x][y]=='m')return false;

    return true;
}

void bfs(lld x,lld y)
{
    dist[x][y]=0;
    vis[x][y]=true;
    queue<pair<lld,lld>>q;
    q.push({x,y});

    while(!q.empty())
    {
        lld curx=q.front().ff;
        lld cury=q.front().ss;
        q.pop();
        FOR(i,4)
        {
            if(isvalid(curx+dx[i],cury+dy[i]))
            {
                x=curx+dx[i],y=cury+dy[i];
                dist[x][y]=dist[curx][cury]+1;
                vis[x][y]=true;
                q.push({x,y});
            }
        }
    }
}

int main()
{
/*#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif*/
    //*************Upload code in github*************
    lld test=0;
    T
    {
        read(r,c);
        vll girls;
        lld homex,homey;
        FOR(i,r)
        {
            read(grid[i]);
            FOR(j,c)
            {
                if(grid[i][j]=='a' || grid[i][j]=='b' || grid[i][j]=='c')girls.pb({i,j});
                if(grid[i][j]=='h')homex=i,homey=j;
            }
        }

        lld ans=0;
        FOR(i,3)
        {
            mem0(vis);
            bfs(girls[i].ff,girls[i].ss);
            ans=max(ans,dist[homex][homey]);
        }
        printf("Case %lld: %lld\n",++test,ans);
    }
    //cerr << "time taken : " << (float)clock() / (float)CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
