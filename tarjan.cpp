/// https://codeforces.com/contest/427/submission/68958991

#include<bits/stdc++.h>
using namespace std;

# define C continue;
# define R return

# define D double
# define I insert
# define ll long long
# define ld long double

# define ull unsigned long long
# define ui unsigned int

# define pb push_back
# define pf push_front

# define vi vector < int >
# define vc vector < char >
# define vs vector < string >
# define vb vector < bool >
# define vd vector < D >
# define vll vector < ll >
# define vull vector < ull >
# define vld vector < ld >
# define PQ priority_queue

# define vvi vector < vector < int > >
# define vvb vector < vector < bool > >
# define vvc vector < vector < char > >
# define vvll vector < vector < ll > >
# define vvd vector < vector < D > >
# define vvld vector < vector < ld > >

# define all(v) (v).begin() , (v).end()
# define allrev(v) (v).rbegin() , (v).rend()
# define allcomp(v) v.begin() , v.end() , comp
# define allrevcomp(v) v.rbegin() , v.rend() , comp

# define pii pair < int , int >
# define pll pair < ll , ll >
# define pld pair < ld , ld >
# define pDD pair < D , D >

# define vpld vector < pld >
# define vpii vector < pii >
# define vpll vector < pll >
# define vpDD vector < pDD >

# define vvpii vector < vector < pii > >
# define F first
# define S second
# define mp make_pair

# define dist(a,b,p,q) sqrt((p-a)*(p-a) + (q-b)*(q-b))

# define pp(n) printf("%.10Lf",n);
# define line cout<<"\n";
# define fast ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0);

string vow = "aeiou";
int month[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

const int dxhorse[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dyhorse[] = {1, -1, 2, -2, 2, -2, 1, -1};

const int dx[] = { -1 , 0 , 0 , 1 } ;
const int dy[] = { 0 , -1 , 1 , 0 } ;

const ld pie = 3.14159265358979 ;
const ll mod = 1e9 + 7 ;

// Tip : ceil ( a/b ) = 1 + floor( (a-1)/b ) !

int n ;
vi val ;
vvi g ;

void read()
{
    cin >> n ;
    val.resize ( n ) ;
    g.resize ( n ) ;

    for ( int i=0 ; i < n ; i ++ )
    {
        cin >> val[i] ;
    }

    int m ;
    cin >> m ;

    for ( int i=0 ; i < m ; i ++ )
    {
        int a , b ;
        cin >> a >> b ;

        a -- ; b -- ;
        g[a].pb ( b ) ;
    }
}

# define time owijeojwmejdwoeijdw
int time = 1 ;

vi dis_time , low_time ;

stack < int > temp ;
vb in_stack ;

ll tot_cost = 0 ;
ll tot_way = 1 ;

ll inf = 1e14 ;

void start_of_scc ( int node )
{
    ll c = inf , w = 1 ;

    while ( true )
    {
        int t = temp.top() ;
        temp.pop() ;
        in_stack[t] = false ;

        if ( val[t] < c )
            c = val[t] , w = 1 ;

        else if ( val[t] == c )
            w ++ ;

        if ( t == node )
            break ;
    }

    tot_cost += c ;

    tot_way *= w ;
    tot_way %= mod ;
}

void dfs ( int node )
{
    dis_time[node] = time ;
    low_time[node] = time ++ ;

    temp.push ( node ) ;
    in_stack[node] = true ;

    for ( auto i : g[node] )
    {
        if ( dis_time[i] > 0 && in_stack[i] == true )
            low_time[node] = min ( low_time[node] , low_time[i] ) ;

        else if ( dis_time[i] == 0 )
        {
            dfs ( i ) ;
            low_time[node] = min ( low_time[node] , low_time[i] ) ;
        }
    }

    if ( dis_time[node] == low_time[node] )
    {
        start_of_scc ( node ) ;
    }
}

void scc()
{
    dis_time.resize ( n ) ;
    low_time.resize ( n ) ;
    in_stack.resize ( n ) ;

    for ( int i=0 ; i < n ; i ++ )
    {
        if ( dis_time[i] ) C ;
        dfs ( i ) ;
    }
}

void solve ( int test_case )
{
    read() ;
    scc() ;

    cout << tot_cost << " " << tot_way ;
    line ;
}

int main()
{fast
    int t = 1;
    // cin >> t;

    for ( int i=0 ; i < t ; i++ ) solve(i);
    return 0;
}
