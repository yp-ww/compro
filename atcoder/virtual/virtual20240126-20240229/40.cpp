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

// #define endl "\n" // インタラクティブの時はコメントアウトする

ll opmax(ll a, ll b){ return max(a, b); }
ll emax(){ return 0LL; }
ll opmin(ll a, ll b){ return min(a, b); }
ll emin(){ return INF; }

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // cout << fixed << setprecision(18);
    
    ll n;
    cin>>n;
    vector<pair<ll,ll>> arr;
    rep(i,0,n){
        ll x,y;
        cin>>x>>y;
        arr.emplace_back(x,y);
    }
    sort(all(arr));
    vector<ll> x(n), y(n);
    rep(i,0,n) x[i] = arr[i].first;
    rep(i,0,n) y[i] = arr[i].second;
    segtree<ll,opmax,emax> segmax(y);
    segtree<ll,opmin,emin> segmin(y);

    auto f = [&](ll z){
        bool flag = false;
        ll right = 0;
        rep(i,0,n){
            while(right<n && x[right]-x[i]<z){
                right++;
            }
            if (right==n) continue;
            if (abs(segmax.prod(right, n)-y[i])>=z) flag = true;
            if (abs(segmin.prod(right, n)-y[i])>=z) flag = true;
        }
        return flag;
    };

    ll l = 0;
    ll r = INF;
    while(r-l>1){
        ll mid = (l+r)/2;
        if (f(mid)) l = mid;
        else r = mid;
    }
    
    cout << l << endl;
    return 0;
}