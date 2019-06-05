#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;
long long n, x[1000003], y[1000003];
void quickSort(long long*, int, int);

void quickSort(long long* a, int left, int right){
    int mid = a[(left+right)/2];
    int i = left;
    int j = right;
    int tmp;
    while (i<j){
        while (a[i]<mid) i++;
        while (a[j]>mid) j--;
        if (i<=j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    if (left<j) quickSort(a, left,j);
    if (i<right) quickSort(a,i,right);
}

int main(int argc, char** argv) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

    long long result = 0;  
    
    quickSort(x,0,n-1);
    quickSort(y,0,n-1);
    //tinh ket qua
    result = 0;

    long long resultX = 0;
    for (int i=1; i<n; i++) {
        resultX +=(x[i]-x[i-1])*i;
        result += resultX;
    }

    long long resultY = 0;
    for (int i=1; i<n; i++){
        resultY += (y[i] - y[i-1])*i;
        result += resultY;
    }

    result = result / (n * (n - 1) / 2);
    cout << result;
}

