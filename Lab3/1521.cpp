#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;
int dis[4 * 100010], deleted[200010];

int n, k, curr, num;

void InitTree(int, int);
void solve();
void update(int, int, int, int);
int FindNext(int);

int main(int argc, char** argv) {
    cin >> n >> k;
    InitTree(1, n);
    solve();
}

void InitTree(int pos, int le) {
    dis[pos] = le;
    if (le <= 1) return;
    int modul = le % 2;
    InitTree(pos * 2, le / 2 + modul);
    InitTree(pos * 2 + 1, le / 2);
}

void update(int curr, int pos, int l, int r) {
    if ((curr < l) || (curr > r)) return;
    dis[pos]--;
    if (l == r) return;
    int le = (r + l) / 2;
    update(curr, pos * 2, l, le);
    update(curr, pos * 2 + 1, le + 1, r);
}

int cacul(int i, int j, int pos, int l, int r) {
    if ((j < l) || (i > r)) return 0;
    if ((l>=i) && (r<=j)) return dis[pos];
    if (dis[pos] == 0) return 0;
    int s;
    s = 0;
    int mid = (l + r) / 2;
    s += cacul(i, j, pos * 2, l, mid);
    s += cacul(i, j, pos * 2 + 1, mid + 1, r);
    return s;
}

int FindNext(int curr) {
    int l = curr + 1;
    int r = curr + n - 1;
    int start = l;
    int mid, sum;
    int s = k % num;
    if (s == 0) s = num;
    while (l <= r) {
        mid = (l + r) / 2;
        if (mid <= n) {
            sum = cacul(start, mid, 1, 1, n);
        } else {
            sum = cacul(start, n, 1, 1, n);
            sum += cacul(1, mid - n, 1, 1, n);
        }
        if (sum == s) {
            if (deleted[mid] == 0) return mid;
            r = mid - 1;
        }
        if (sum > s) r = mid - 1;
        if (sum < s) l = mid + 1;
    }
    return 0;
}

void solve() {
    curr = k;
    num = n - 1;
    deleted[k] = 1;
    deleted[k+n] = 1;
    update(curr, 1, 1, n);
    cout << curr << " ";

    for (int i = 2; i <= n; i++) {
        curr = FindNext(curr);
        if (curr > n) curr -= n;
        deleted[curr] = 1;
        deleted[curr+n] = 1;
        if (curr == 0) return;
        update(curr, 1, 1, n);
        cout << curr << " ";

        num--;
    }
}
