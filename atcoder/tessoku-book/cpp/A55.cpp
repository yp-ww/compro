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
const ll INF = (ll)1e15;

int main()
{
    ll q;
    cin>>q;
    set<ll>st;
    while(q){
        q--;
        ll c;
        cin>>c;
        if (c==1){
            ll x;
            cin>>x;
            st.insert(x);
        }else if(c==2){
            ll x;
            cin>>x;
            st.erase(x);
        }else{
            ll x;
            cin>>x;
            auto itr = st.lower_bound(x);
            if (itr==st.end()){
                cout << -1 << endl;
            }else{
                cout << *itr << endl;
            }
            
        }
    }
    return 0;
}