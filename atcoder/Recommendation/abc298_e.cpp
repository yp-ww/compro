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

using mint = modint998244353;

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // cout << fixed << setprecision(18);

    ll n,a,b,p,q;
    cin>>n>>a>>b>>p>>q;

    vector<vector<mint>> dp1(n+1, vector<mint>(n+1));
    dp1[a][0] = 1;
    mint pinv = 1;
    pinv /= p;
    rep(i,0,n)rep(j,0,n){
        if (dp1[i][j].val()==0) continue;
        rep(k,1,p+1){
            dp1[min(n,i+k)][j+1] += dp1[i][j] * pinv;
        }
    }

    vector<vector<mint>> dp2(n+1, vector<mint>(n+1));
    dp2[b][0] = 1;
    mint qinv = 1;
    qinv /= q;
    rep(i,0,n)rep(j,0,n){
        if (dp2[i][j].val()==0) continue;
        rep(k,1,q+1){
            dp2[min(n,i+k)][j+1] += dp2[i][j] * qinv;
        }
    }

    mint ans = 0;
    rep(i,1,n+1){
        mint temp = 0;
        rep(j,i,n+1){
            temp += dp2[n][j];
        }
        ans += dp1[n][i]*temp;
    }
    cout << ans.val() << endl;

    
    return 0;
}