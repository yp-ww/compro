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
const ll INF = (ll)1e18+10;

int main()
{
    ll n;
    cin>>n;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    sort(all(a));
    reverse(all(a));
    vector<string> arr;
    rep(i,0,3){
        auto temp = to_string(a[i]);
        arr.push_back(temp);
    }
    sort(all(arr));
    ll ans = 0;
    do{
        string temp = "";
        rep(i,0,3){
            temp += arr[i];
        }
        chmax(ans, stoll(temp));
    }while(next_permutation(all(arr)));
    cout << ans << endl;
    return 0;
}