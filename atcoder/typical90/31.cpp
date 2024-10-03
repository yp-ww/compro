#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
template <class T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;

#define rep(i, a, b) for(ll i=a; i<b; i++)
#define rrep(i, a, b) for(ll i=a; i>=b; i--)
#define all(a) (a).begin(), (a).end()
#define smod(n, m) ((((n) % (m)) + (m)) % (m)) // 非負mod
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

inline int popcount(int n) { return __builtin_popcount(n); } // 2進数で表した場合に立ってるビット数がいくつか
inline int popcount(ll n) { return __builtin_popcountll(n); }
inline int ctz(int n) { return n != 0 ? __builtin_ctz(n) : -1; } // 2進数で表した場合に 1 の位からいくつ 0 が連なっているか
inline int ctz(ll n) { return n != 0 ? __builtin_ctzll(n) : -1; }
inline int clz(int n) { return n != 0 ? (31 - __builtin_clz(n)) : -1; } // 2進数で表した場合に左側にいくつ 0 を埋める必要があるか
inline int clz(ll n) { return n != 0 ? (63 - __builtin_clzll(n)) : -1; }

const double PI = 3.141592653589793;
const vector<int> DX = { 1, 0, -1, 0 };
const vector<int> DY = { 0, 1, 0, -1 };
const long long INF = 4004004003104004004LL; // (int)INF = 1010931620;
ll coordinate(ll h, ll w, ll W){ return h*W + w; } // 二次元座標を一次元座標に変換

#define endl "\n" // インタラクティブの時はコメントアウトする

ll op(ll a, ll b){ return min(a,b); }
ll e(){ return INF; }

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // cout << fixed << setprecision(18);
    
    ll n;
    cin>>n;
    vector<ll>w(n),b(n);
    rep(i,0,n)cin>>w[i];
    rep(i,0,n)cin>>b[i];

    vector<vector<ll>> dp(51, vector<ll>(2000,-1));
    
    vector<ll> init(2000);
    rep(i,0,2000) init[i] = i;
    
    rep(i,0,51)rep(j,0,1500){
        segtree<ll,op,e> seg(init);
        if (i>=1){
            if (j+i < 1500) seg.set(dp[i-1][j+i], INF);
        }
        if (j>=2){
            rep(k,1,j/2+1){
                seg.set(dp[i][j-k], INF);
            }
        }
        assert(seg.all_prod()!=INF);
        dp[i][j] = seg.all_prod();
    }
    ll tot = 0;
    rep(i,0,n) tot ^= dp[w[i]][b[i]];
    if (tot){
        cout << "First" << endl;
    }else{
        cout << "Second" << endl;
    }
    
    return 0;
}