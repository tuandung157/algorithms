#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;
int n, num, k, a[100][100], color[100], l[100],ok, res;

void paintDFS(int, int);

int main(int argc, char** argv) {
    cin >> n;
    ok = 1;
    res = 1;
    for (int i=1; i<=n; i++){
        num = 0;
        while (ok){
            cin >> k;
            if (k == 0) break;
            l[i]++;
            l[k]++;
            a[i][l[i]] = k;
            a[k][l[k]] = i;
        }
    }
    
    for (int i=1; i<=n; i++) {
        if (res == -1) break;
        if (color[i] == 0) paint(i,-1);
    }
    
    if (res == -1){
        cout << -1;
    } else {
        for (int i=1; i<=n; i++) if (color[i] == -1) {
            cout << 0;
        } else cout << 1;
    }
    
}

void paintDFS(int k, int code){
    if (res == -1) return;
    color[k] = code;
    int i = 0;
    int next;
    if (code == -1) {
        next = 1;
    } else next = -1;
    while (ok){
        i++;
        if (a[k][i] == 0) break;
        if (color[a[k][i]] == next) continue;
        if (color[a[k][i]] != 0){
            res = -1;
            return;
        }
        paintDFS(a[k][i],next);
    }
}