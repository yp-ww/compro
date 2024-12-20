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
ll dist2(ll x1, ll y1, ll x2, ll y2){ return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2); }

#define endl "\n" // インタラクティブの時はコメントアウトする

using mint = modint998244353;

// Verify: https://atcoder.jp/contests/abc322/tasks/abc322_f

mint op(mint l, mint r){
    return (mint)0;
}

mint e(){
    return (mint)0;
}

struct F
{
    mint a, b;
    F(mint aa, mint bb){
        a = aa;
        b = bb;
    }
    F(){
        a = 1;
        b = 0;
    }
};

mint mp(F f, mint x){
    return f.a * x + f.b;
}

F comp(F f, F g){
    return F(g.a*f.a, f.a*g.b+f.b);
}

F id(){
    return F();
}

int main()
{
    ll n,q;
    cin>>n>>q;
    vector<mint> s(n);
    rep(i,0,n){
        ll a;
        cin>>a;
        s[i] = (mint)a;
    }

    lazy_segtree<mint,op,e,F,mp,comp,id> seg(s);
    while (q--){
        ll l,r,x;
        cin>>l>>r>>x;
        mint a = r-l;
        a /= r-l+1;
        mint b = x;
        b /= r-l+1;
        seg.apply(l-1,r,F(a,b));
    }
    rep(i,0,n){
        cout << seg.get(i).val() << endl;
    }

    return 0;
}