#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for(ll i=a; i<b; i++)
#define rrep(i, a, b) for(ll i=a; i>=b; i--)
#define all(a) (a).begin(), (a).end()
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

const double pi = 3.141592653589793;
const ll INF = (ll)3e15;

ll op(ll a, ll b){ return max(a, b); };
ll e(){ return 0; };

int main()
{
    ll n;
    cin>>n;
    vector<ll>h(n),a(n);
    rep(i,0,n)cin>>h[i];
    rep(i,0,n)cin>>a[i];
    rep(i,0,n)h[i]--;
    segtree<ll,op,e> seg(n);
    
    rep(i,0,n){
        ll off = seg.prod(0, h[i]);
        seg.set(h[i], off+a[i]);
    }
    ll ans = 0;
    rep(i,0,n) chmax(ans, seg.get(i));
    cout << ans << endl;

    return 0;
}