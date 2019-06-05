#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;
int n, k, cur, pos;
int a[100002];

int main(int argc, char** argv) {
    cin >> n;
    cur = 0;
    pos = 0;
    bool ok = true;
    for (int i = 1; i<=n; i++){
        cin >> k;
        if (k > cur){
            for (int i= cur +1 ; i <=k; i++){
                pos++;
                a[pos] = i;
            }
            cur = k;
        }
        if (a[pos] != k){
            ok = false;
            break;
        } else pos--;
    }
    
    if (ok) {
        cout << "Not a proof" << endl;
    } else cout << "Cheater" << endl;
}
