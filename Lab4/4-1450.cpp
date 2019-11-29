#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

struct edge {
    int a, b, w;
};
int n, m, S, F, track[502], profit[502];
edge list[125000];

int minValue = -2147483640;

void init();
void fordBellman();

int main(int argc, char** argv) {
    init();
    fordBellman();
    if ((track[F] != 0) && (profit[F] >0)) {
        cout << profit[F];
    } else cout << "No solution";
}

void init() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> list[i].a >> list[i].b >> list[i].w;

    cin >> S >> F;
    for (int i = 1; i <= n; i++) profit[i] = minValue;
    profit[S] = 0;
}

void fordBellman() {
    for (int i = 1; i <= n - 1; i++)
        for (int j = 1; j <= m; j++)
            if (profit[list[j].a] + list[j].w > profit[list[j].b]) {
                profit[list[j].b] = profit[list[j].a] + list[j].w;
                track[list[j].b] = list[j].a;
            }
}
