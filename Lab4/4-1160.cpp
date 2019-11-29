#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct edge {
    int a, b, w;
};
int n, m, code, father[1020];
edge list[16000];

void init();
bool compare(Edge, Edge);
void kruskal();
void join(int, int);
int getRoot(int);

int main(int argc, char** argv) {
    init();
    kruskal();
}

bool compare(Edge u, Edge v) {
    return (u.w < v.w);
}

void init() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> list[i].a >> list[i].b >> list[i].w;
    sort(list, list + m + 1, compare);
    for (int i=1; i<=n; i++) father[i]=-1;
}

int getRoot(int k){
    int v = k;
    while (father[v] > 0) v = father[v];
    return v;
}

void kruskal() {
    int num = 0;
    int u,v,l;
    for (int i=1; i<=m; i++){
        u = getRoot(list[i].a);
        v = getRoot(list[i].b);
        if (u != v){
            num++;
            if (num == n-1){
                l=i;
                break;
            }
            join(u,v);
        }
    }
    cout << list[l].w << endl;
    cout << l << endl;
    for (int i = 1; i <= l; i++) cout << list[i].a << " " << list[i].b << endl;
}

void join(int u, int v){
    int x = father[u] + father[v];
    if (father[u] > father[v]){
        father[u] = v;
        father[v] =x;
    } else {
        father[u] = x;
        father[v] = u;
    }
}
