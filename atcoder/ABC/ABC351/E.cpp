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

template<typename T>
struct Cum{
    vector<T> cum;
    int n;
    // コンストラクタ
    Cum() {}
    Cum(vector<T>& arr){
        n = arr.size();
        cum.resize(n+1,0);
        // 累積和を計算
        for (int i=0; i<n; i++){
            cum[i+1] = cum[i] + arr[i];
        }
    }
    // 0-indexed, 区間 [l,r) の和を取得
    T get(int l, int r){
        assert(l<=r);
        return cum[r] - cum[l];
    }
    // 0-indexed, arr を連結した無限配列上で区間 [l,r) の和を取得
    T get_overRange(ll l, ll r){
        T cumr = get(0, n) * (r/(ll)n) + get(0, r%(ll)n);
        T cuml = get(0, n) * (l/(ll)n) + get(0, l%(ll)n);
        return cumr - cuml;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // cout << fixed << setprecision(18);

    ll n;
    cin>>n;
    vector<ll>x(n),y(n);
    rep(i,0,n)cin>>x[i]>>y[i];

    vector<ll> u(n), v(n);
    rep(i,0,n){
        u[i] = x[i] + y[i];
        v[i] = x[i] - y[i];
    }
    
    vector<ll> odu, evu, odv, evv;
    rep(i,0,n){
        if (u[i]%2){
            odu.push_back(u[i]);
            odv.push_back(v[i]);
        }else{
            evu.push_back(u[i]);
            evv.push_back(v[i]);
        }
    }

    ll ans = 0;
    auto f = [](vector<ll> arr){
        sort(all(arr));
        ll res = 0;
        Cum<ll> cum(arr);
        ll sz = arr.size();
        rep(i,0,sz-1){
            ll tot = cum.get(i+1,sz);
            tot -= (sz-i-1)*arr[i];
            res += tot;
        }
        return res;
    };
    
    ans += f(odu);
    ans += f(odv);
    ans += f(evu);
    ans += f(evv);

    cout << ans/2 << endl;
    
    return 0;
}