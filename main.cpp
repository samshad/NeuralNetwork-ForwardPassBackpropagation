#include<bits/stdc++.h>

using namespace std;

#define si(x) scanf("%d",&x)
#define sii(x,y) scanf("%d %d",&x,&y)
#define siii(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define sl(x) scanf("%lld",&x)
#define sll(x,y) scanf("%lld %lld",&x,&y)
#define slll(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define ss(ch) scanf("%s",ch)
#define pi(x) printf("%d",x)
#define pii(x,y) printf("%d %d",x,y)
#define pl(x) printf("%lld",x)
#define pll(x,y) printf("%lld %lld",x,y)
#define sf scanf
#define pf printf
#define pcs(x,y) printf("Case %d: %s", x, y)
#define pci(x,y) printf("Case %d: %d", x, y)
#define pcl(x,y) printf("Case %d: %lld", x, y)
#define NL printf("\n")
#define nl '\n'
#define mod 1000000007
#define FI freopen("in.txt","r",stdin)
#define FO freopen("out.txt","w",stdout)

#define FOR(i,j,k) for(int i = j; i < k; i++)
#define rep(l,n) FOR(l,0,n)
#define per(i,j,k) for(int i = j; i > k; i--)

#define PI acos(-1.0)
#define eps 1e-9

#define pb(x) push_back(x)
#define ppb() pop_back()
#define sz(x) x.size()
#define xx first
#define yy second
#define mp(a,b) make_pair(a,b)
#define ssz(a) strlen(a)

#define mem(ara,val) memset(ara,val,sizeof(ara))
#define clr(ara) mem(ara,0)
#define st(ara) mem(ara,-1)
#define all(a) a.begin(),a.end()
//cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

#define debug(args...) {dbg,args; cout<<endl;}

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cout<<v<<" ";
        return *this;
    }
}dbg;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector< PII > VII;

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

///=>=>=>=>=>=>=>=>=>00100<=<=<=<=<=<=<=<=<=///

double i[2], b[2], netH1, netH2, outH1, outH2, w[9], outO1, outO2, netO1, netO2, targetO1 = .01, targetO2 = .99;
struct solve{
    double i[2], b[2], w[8], error;
}ans;

int main(){
    //std::ios_base::sync_with_stdio(0);//cin.tie(0);
    //FI;//FO;

    //int t = 0, z = 0, len;
    //int n = 0, k = 0; LL m = 0, ans = 0;

    cout << setprecision(9) << fixed;
    srand (time(NULL));

    i[0] = .05;
    i[1] = .10;
    b[0] = .35;
    b[1] = .60;
    w[0] = .15;
    w[1] = .20;
    w[2] = .25;
    w[3] = .30;
    w[4] = .40;
    w[5] = .45;
    w[6] = .50;
    w[7] = .55;

    ans.error = 5;
    rep(l,99999999){
        rep(j,2) i[j] = (double)(rand() % 100) / 100;
        rep(j,8) w[j] = (double)(rand() % 100) / 100;
        rep(j,2) b[j] = (double)(rand() % 100) / 100;

        netH1 = w[0] * i[0] + w[1] * i[1] + b[0];
        netH2 = w[2] * i[0] + w[3] * i[1] + b[0];

        outH1 = 1 / (1 + exp(-netH1));
        outH2 = 1 / (1 + exp(-netH2));

        netO1 = w[4] * outH1 + w[5] * outH2 + b[1];
        netO2 = w[6] * outH1 + w[7] * outH2 + b[1];

        outO1 = 1 / (1 + exp(-netO1));
        outO2 = 1 / (1 + exp(-netO2));

        double e1 = .5 * ((targetO1 - outO1) * (targetO1 - outO1));
        double e2 = .5 * ((targetO2 - outO2) * (targetO2 - outO2));

        double er = e1 + e2;

        if(er < ans.error){
            rep(j,2) ans.i[j] = i[j];
            rep(j,2) ans.b[j] = b[j];
            rep(j,8) ans.w[j] = w[j];
            ans.error = er;
        }
    }

    cout << "Inputs:" << nl;
    rep(l,2) cout << "I" << l+1 << ": " << ans.i[l] << nl;
    NL;
    cout << "Hidden Layers:" << nl;
    rep(l,2) cout << "B" << l+1 << ": " << ans.b[l] << nl;
    NL;
    cout << "Weights:" << nl;
    rep(l,8) cout << "W" << l+1 << ": " << ans.w[l] << nl;
    NL;
    cout << "Error: " << ans.error;

    return 0;
}
