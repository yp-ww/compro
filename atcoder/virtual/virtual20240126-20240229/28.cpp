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
const long long INF = (ll)1e18+10;
ll coordinate(ll h, ll w, ll W){ return h*W + w; } // 二次元座標を一次元座標に変換

#define endl "\n" // インタラクティブの時はコメントアウトする

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // cout << fixed << setprecision(18);
    
    ll h,w;
    cin>>h>>w;
    vector<vector<ll>>a(h,vector<ll>(w));
    rep(i,0,h)rep(j,0,w)cin>>a[i][j];

    vector<vector<vector<ll>>> dp(h, vector<vector<ll>>(2, vector<ll>(2, INF)));
    dp[0][0][0] = 0;
    dp[0][0][1] = 1;

    rep(i,1,h){
        rep(j,0,2){
            rep(k,0,2){
                rep(l,0,2){
                    vector<vector<ll>> arr(3, vector<ll>(w,INF));
                    rep(x,0,w){
                        if (i-2>=0) arr[0][x] = a[i-2][x] ^ l;
                        arr[1][x] = a[i-1][x] ^ j;
                        if (i<h) arr[2][x] = a[i][x] ^ k;
                    }
                    bool flag = true;
                    rep(x,0,w){
                        bool temp = false;
                        if (arr[1][x] == arr[0][x]) temp = true;
                        if (arr[1][x] == arr[2][x]) temp = true;
                        if (x+1<w && arr[1][x] == arr[1][x+1]) temp = true;
                        if (x-1>=0 && arr[1][x] == arr[1][x-1]) temp = true;
                        flag &= temp;
                    }
                    if (!flag) continue;
                    if (i==h-1){
                        bool last = true;
                        rep(x,0,w){
                            bool temp = false;
                            if (arr[2][x] == arr[1][x]) temp = true;
                            if (x+1<w && arr[2][x] == arr[2][x+1]) temp = true;
                            if (x-1>=0 && arr[2][x] == arr[2][x-1]) temp = true;
                            last &= temp;
                        }
                        if (!last) continue;
                    }
                    chmin(dp[i][j][k], dp[i-1][l][j] + k);
                }
            }
        }
    }

    ll ans = INF;
    chmin(ans, dp[h-1][0][0]);
    chmin(ans, dp[h-1][0][1]);
    chmin(ans, dp[h-1][1][1]);
    chmin(ans, dp[h-1][1][1]);
    if (ans>=INF){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
    
    return 0;
}