#include <bits/stdc++.h>
using namespace std;

// Type Aliases
#define ll long long
#define int long long
#define ull unsigned long long
#define ld long double

// Constants
#define mod 1000000007
#define mod2 998244353
#define inf 1e18
#define pi 3.141592653589793238462

// Vector Operations
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(x) (ll)(x).size()
#define maxvall(v) *max_element(all(v))
#define minvall(v) *min_element(all(v))
#define maxv(v,i,j) *max_element(v.begin() +i , v.begin() + j +1)
#define minv(v,i,j) *min_element(v.begin() +i , v.begin() + j+1)
#define imax(v) distance(v.begin(), max_element(all(v)))
#define imin(v) distance(v.begin(), min_element(all(v)))
#define sumv(v, i, j) accumulate(v.begin() + i, v.begin() + j + 1, 0LL)
#define sumvall(v) accumulate(all(v), 0LL)
#define prod(v) accumulate(all(v), 1LL, multiplies<ll>())
#define sor(v) sort(all(v))
#define rsor(v) sort(rall(v))
#define rev(v) reverse(all(v))
#define uniq(v) v.erase(unique(all(v)), v.end())
#define freq(v, x) count(all(v), x)
#define pres(v, x) (find(all(v), x) != v.end())
#define lb(v, x) lower_bound(all(v), x) - v.begin()
#define ub(v, x) upper_bound(all(v), x) - v.begin()
#define read(v) for(auto &x : v) cin >> x
#define print(v) for(auto x : v) cout << x << " "; cout << "\n"

// Macros for Loops
#define loop(i, a, b) for (ll i = a; i < b; i++)
#define looprev(i, a, b) for (ll i = a; i >= b; i--)
#define trav(a, x) for (auto &a : x)

// Shortcuts
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair

// Bitwise Operations
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define lsb(x) (x & -x)
#define msb(x) (1LL << (63 - __builtin_clzll(x)))

// Fast Input/Output
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// Debugging
#define debug(x) cerr << #x << " = " << x << '\n'
#define debugArr(arr) cerr << #arr << ": "; for(auto e : arr) cerr << e << " "; cerr << '\n';

// Data Structures
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
#define vb vector<bool>
#define mii map<int, int>
#define mll map<ll, ll>
#define umii unordered_map<int, int>
#define umll unordered_map<ll, ll>
#define usi unordered_set<int>
#define usll unordered_set<ll>
#define si set<int>
#define sll set<ll>
#define dq deque<int>
#define dql deque<ll>
#define pqmax priority_queue<int>
#define pqmin priority_queue<int, vector<int>, greater<int>>
#define pqpll priority_queue<pll>
#define pqpmin priority_queue<pll, vector<pll>, greater<pll>>
#define vdi vector<vector<int>>
#define vdll vector<vector<ll>>

// Stack & Queue
#define st stack<int>
#define stl stack<ll>
#define q queue<int>
#define ql queue<ll>
// Utility Functions
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define F first
#define S second

// Mathematical Functions
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll power(ll a, ll b, ll m = mod) { ll res = 1; while (b) { if (b & 1) res = res * a % m; a = a * a % m; b >>= 1; } return res; }

// Solve Function
void solve() {
    int n;
    cin >> n;
    vi a(n);
    read(a);

    int cnt = count(all(a), a[0]);
    vector<int> vec;
    vec.push_back(a[0]);
    int res=1;
    
    for(int i=1; i<n ; i++){
        if(count(all(a), a[i]) >= cnt) {
            if(a[i] != a[0]) {
                vec.push_back(a[i]);

            }
        }
        
    }
    loop(i, 1, n) {
        if (a[i] == a[0]) {
            cnt--;
            res++;
        }
        else{
            if(count(all(a), a[i]) < cnt -1) {
                break;
            }
        }
    }
    cout<< res << "\n";

}

// Main Function
int32_t main() {
    fast_io;
    ll test;
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}

/*
  ██████╗ ██████╗ ███████╗███████╗███╗   ██╗██╗ ██████╗
  ██╔══██╗██╔══██╗██╔════╝██╔════╝████╗  ██║██║██╔════╝
  ███████║██████╔╝███████╗█████╗  ██╔██╗ ██║██║██║     
  ██╔══██║██╔══██╗╚════██║██╔══╝  ██║╚██╗██║██║██║     
  ██║  ██║██║  ██║███████║███████╗██║ ╚████║██║╚██████╗
  ╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝  ╚═══╝╚═╝ ╚═════╝
*/