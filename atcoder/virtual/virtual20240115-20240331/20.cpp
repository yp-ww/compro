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

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // cout << fixed << setprecision(18);

    ll n,m;
    cin>>n>>m;
    vector<string>s(n);
    rep(i,0,n)cin>>s[i];

    queue<tuple<ll,ll,ll>> q;
    q.push({1,1,4});
    vector<vector<vector<bool>>> v(n,vector<vector<bool>>(m, vector<bool>(5)));
    v[1][1][4] = true;
    while(!q.empty()){
        auto [x,y,mode] = q.front(); q.pop();
        if (mode==4){
            rep(k,0,4){
                ll nx = x + DX[k];
                ll ny = y + DY[k];
                if (s[nx][ny]=='#') continue;
                if (v[nx][ny][k]) continue;
                v[nx][ny][k] = true;
                q.push({nx,ny,k});
            }
        }else{
            ll nx = x + DX[mode];
            ll ny = y + DY[mode];
            if (s[nx][ny]=='#'){
                if (v[x][y][4]) continue;
                v[x][y][4] = true;
                q.push({x,y,4});
            }else{
                if (v[nx][ny][mode]) continue;
                v[nx][ny][mode] = true;
                q.push({nx,ny,mode});
            }
        }
    }
    ll ans = 0;
    rep(i,0,n)rep(j,0,m){
        bool flag = false;
        rep(k,0,5) if(v[i][j][k]) flag = true;
        if (flag) ans++;
    }
    cout << ans << endl;
    return 0;
}