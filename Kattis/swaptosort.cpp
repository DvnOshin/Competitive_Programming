#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <deque>
#include <string.h>
#include <sstream>
#include <bitset>
#include <math.h>
#include <assert.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
template <class T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <class T>
using ordered_multiset = __gnu_pbds::tree<T, __gnu_pbds::null_type, less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

int N, K, id = 0, visited [1000010];
vector<int> adjacency [1000010];

void dfs(int curr){
    visited[curr] = id;
    for(int nexty : adjacency[curr])
        if(visited[nexty] == -1)
            dfs(nexty);
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> K; memset(visited, -1, sizeof(visited));
    for(int i = 0; i < K; i++){
        int a, b; cin >> a >> b;
        adjacency[a].pb(b); adjacency[b].pb(a);
    }
    for(int i = 1; i <= N; i++)
        if(visited[i] == -1){
            dfs(i);
            id++;
        }
    for(int i = 1; i <= N/2; i++)
        if(visited[i] != visited[N+1-i]){
            cout << "No\n";
            return 0;
        }
    cout << "Yes\n";
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/