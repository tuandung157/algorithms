#include <cstdlib>
#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
int n, k, num[10002], x[10002], result[10002];
void quickSort(int*, int, int);

void quickSort(int* a, int left, int right){
    int mid = (left+right)/2;
    int i = left;
    int j = right;
    int tmp;
    while (i<j){
        while (a[i]>a[mid]) i++;
        while (a[j]<a[mid]) j--;
        if (i<=j){
            swap(a[i], a[j]);
            swap(x[i], x[j]);
            i++;
            j--;
        }
    }
    if (left<j) quickSort(a, left,j);
    if (i<right) quickSort(a,i,right);
}
int main(int argc, char** argv) {
    cin >> k;
    n = 0;
    int tmp;
    for (int i=1; i<=k; i++) {
        cin >> num[i];
        x[i] = i;
    }
    quickSort(num,1,k);
    int step = 0;
    while (num[2] != 0){

        while (num[k]==0) k--;
        step++;
        result[step] = x[1];
        num[1]--;
        step++;
        result[step] = x[k];
        num[k]--;
        if ((num[1]<num[2])||(num[k]<num[3])|| ((num[3]==0)&&(num[1]!=num[k]))) quickSort(num,1,k);
    }
    while (num[1]!=0){
        step++;
        result[step] = x[1];
        num[1] --;
    }
    for (int i=1; i<=step; i++) cout <<result[i] << " ";
}

