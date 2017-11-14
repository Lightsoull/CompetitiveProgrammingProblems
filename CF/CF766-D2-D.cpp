/*
explanation : here the idea is to get relations between the words first if two words are the
same so their opposite are the same and if 2 words are opposite the opposite of first same 
with second and the opposite of second the same with first so you will observe that we want
to deal with sets thats why dsu is the optimal data structure to use.

complexity : O( m*log(n)+q*log(n))

*/
#include <bits/stdc++.h>
#define sz(v)   ((int)(v).size())
#define  all(v)    ((v).begin()),((v).end())
#define  allr(v)    ((v).rbegin()),((v).rend())
#define   pb         push_back
#define   mp         make_pair
#define   mt         make_tuple
#define   inf        0x7fffffff
#define    clr(v,d)      memset( v, d ,sizeof(v))
#define    vi       vector<int>
#define    vd       vector<double>
#define    vvi      vector< vector<int> >
#define    vvll      vector< vector<long long> >
#define    vvpi     vector< vector< pair<int,int> > >
#define    vvpll     vector< vector< pair<long long,long long> > >
#define    vvd      vector< vector<double> >
#define    vs       vector<string>
#define    vvs      vector< vector<string> >
#define     vc        vector<char>
#define     vpi        vector< pair<int ,int> >
#define      pi        pair<int ,int>
#define      pll       pair<long long ,long long>
#define     vpd        vector< pair<double ,double> >
#define     vpll        vector< pair<long long ,long long> >
#define    vll       vector<long long>
#define    dqi        deque< int >
#define     si         set<int>
#define     spi        set< pair<int ,int > >
#define     row          vector< ll >
#define     matrix            vector< row >
#define    lp(i,n)    for(i=0;i<n;i++)
#define     si         set<int>
#define    oo         900000000000000000
#define   MOD         1000000007
#define    X            real
#define    Y            imag
#define   angle(n)      atan2((n.imag()),(n.real()))
#define   vec(a,b)       ((b)-(a))
#define   length(a)      hypot( (a.imag()),(a.real()) )
#define   normalize(a)      (a)/(length(a))
#define    dp(a,b)          (((conj(a))*(b)).real())
#define    cp(a,b)          (((conj(a))*(b)).imag())
#define    lengthsqrt(a)       dp(a,a)
#define    rotate0( a,ang)    ((a)*exp( point(0,ang) ))
#define    rotateA(about,p,ang)   (rotate0(vec(about,p),ang)+about)
#define    lcm(a,b)                ((a*b)/(__gcd(a,b)))
#define    reflection0(m,v)         (conj((v)/(m))*(m))
#define     reflectionA(m,v,p0)     (conj( (vec(p0,v))/(vec(p0,m)) ) * (vec(p0,m)) ) + p0
#define     same(p1,p2)               ( dp(  vec(p1,p2),vec(p1,p2)) < eps )
#define     point                    complex<double>
#define    scani(n)                  scanf("%d",&n)
#define    scanll(n)                  scanf("%I64d",&n)
#define    printi(n)                 printf("%d",n)
#define    printll(n)                 printf("%I64d",n)
#define    scand(n)                  scanf("%lf",&n)
#define    printd(n)                 printf("%lf",n)
#define    scans(n)                  scanf("%s",&n)
#define    prints(n)                 printf("%s",n)
typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-10);
const double  PI= acos(-1.0);
using namespace std;
int dcmp(double a,double b){   return fabs(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
int setBit0(int num, int idx) {return num & ~(1<<idx);}
int flipBit(int num, int idx) {return num ^ (1<<idx);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
map< string,int > mb;
int par[2*100000+9],rnk[2*100000+9];

void intial(int n)
{
    for(int i=0;i<n;i++)
    {
        par[i]=i;
        par[i+n]=i+n;
        rnk[i]=1;
        rnk[i+n]=1;
    }

}
int fnd(int n)
{
    if(par[n]==n)
        return n;

    return par[n]=fnd(par[n]);
}
void join(int a,int b)
{
  int  p1= fnd(a);
  int  p2= fnd(b);

   if(p1==p2)
   return;

   if(rnk[p1]>=rnk[p2])
   {
       rnk[p1]+=rnk[p2];
       par[p2]=p1;

   }
   else if(rnk[p1]<rnk[p2])
   {
       rnk[p2]+=rnk[p1];
       par[p1]=p2;

   }
}
int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    int id=0;
    string st;
    intial(n);
    for(int i=0;i<n;i++)
    {
        cin>>st;
        mb[st]=id++;
    }
    int t;
    string s1,s2;
    int a,b;
    for(int i=0;i<m;i++)
    {
        cin>>t>>s1>>s2;
        a=mb[s1];
        b=mb[s2];

        if(t==1)
        {
            if(fnd(a)==fnd(b+n))
                cout<<"NO\n";
            else
            {
                join(a,b);
                join(a+n,b+n);
                cout<<"YES\n";
            }
        }
        else
        {
            if(fnd(a)==fnd(b))
                cout<<"NO\n";
            else
            {
                join(a,b+n);
                join(a+n,b);
                cout<<"YES\n";
            }
        }
    }
    while(q--)
    {

        cin>>s1>>s2;
        a=mb[s1];
        b=mb[s2];

        if(fnd(a)==fnd(b))
            cout<<"1\n";
        else if(fnd(a+n)==fnd(b))
            cout<<"2\n";
        else
            cout<<"3\n";
    }

}
