{\rtf1\ansi\ansicpg1252\deff0\nouicompat\deflang1033{\fonttbl{\f0\fnil\fcharset0 Calibri;}}
{\*\generator Riched20 10.0.15063}\viewkind4\uc1 
\pard\sa200\sl276\slmult1\f0\fs22\lang9 #include <iostream>\par
#include <stdio.h>\par
#include <stdlib.h>\par
#include <algorithm>\par
#include <vector>\par
\par
using namespace std;\par
\par
int N;\par
vector<int> children [200001];\par
pair<long long, int> pis [200001];\par
int tree [200001], id [200001], mx [200001], ret [200001], curr = 1, index = 1;\par
long long L, depth [200001];\par
\par
void add(int pos, long long x)\{\par
    while(pos < 200001)\{\par
        tree[pos] += x;\par
        pos += (pos&-pos);\par
    \}\par
\}\par
\par
int query(int pos)\{\par
    int sum = 0;\par
    while(pos > 0)\{\par
        sum += tree[pos];\par
        pos -= (pos&-pos);\par
    \}\par
    return sum;\par
\}\par
\par
int dfs(int x)\{\par
    id[x] = curr++; mx[x] = id[x];\par
    for(int i = 0; i < children[x].size(); i++)\{\par
        int next = children[x][i];\par
        mx[x] = max(mx[x], dfs(next));\par
    \}\par
    return mx[x];\par
\}\par
\par
int main()\{\par
    freopen("runaway.in", "r", stdin); freopen("runaway.out", "w", stdout);\par
    scanf("%d %I64d", &N, &L); depth[0] = 0ll;\par
    for(int i = 2; i <= N; i++)\{\par
        int x; long long y; scanf("%d %I64d", &x, &y);\par
        children[x].push_back(i); depth[i] = depth[x]+y;\par
    \}\par
    dfs(1);\par
    for(int i = 1; i <= N; i++) pis[i] = make_pair(depth[i], i);\par
    sort(pis+1, pis+N+1);\par
    for(int i = 1; i <= N; i++)\{\par
        long long curDepth = pis[i].first; int now = pis[i].second; int from = id[now]; int to = mx[now];\par
        while(index <= N && curDepth+L >= depth[pis[index].second])\{\par
            add(id[pis[index].second], 1);\par
            index++;\par
        \}\par
        ret[now] = query(to)-query(from-1);\par
    \}\par
    for(int i = 1; i <= N; i++) cout << ret[i] << '\\n';\par
    return 0;\par
\}\par
}
 