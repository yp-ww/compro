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
const ll INF = numeric_limits<ll>::max();

int main()
{
    ll n,x;
    cin>>n>>x;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    set<ll> st;
    rep(i,0,n)st.insert(a[i]);
    bool flag = false;
    rep(i,0,n){
        ll y = a[i]-x;
        if (st.find(y)!=st.end()) flag = true;
    }
    YesNo(flag);
    return 0;
}