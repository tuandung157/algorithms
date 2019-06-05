#include <cstdlib>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;
int n;
struct Point{
    int x,y,pos;
};
Point point[10003];
void quickSort(int, int);
int pointChecker(int,int,int,int);


int main(int argc, char** argv) {

    cin >> n;
    for (int i = 1; i<=n; i++) cin >> point[i].x >> point[i].y;
    for (int i = 1; i<=n; i++) point[i].pos = i;
    int k = 1;
    for (int i = 2; i<=n; i++) if (point[i].x<point[k].x) k = i; 
    swap(point[1],point[k]);
    quickSort(2,n);

    cout << point[1].pos << " " << point[1+ n/2].pos;
}

int pointChecker(int X1,int Y1, int X2, int Y2){
    //kiem tra ket qua x,y
    if ((X1==X2)&&(Y1==Y2)) return 0;
    int delX2 = X2 - point[1].x;
    int delY2 = Y2 - point[1].y;
    int delX1 = X1 - point[1].x;
    int delY1 = Y1 - point[1].y;
    int result = 0;
    if (delX2 == 0){
        if (delY2 < 0) return 0;
        if (delX1 !=0) return 1;
        if ((delX1 ==0) && (delY1) < 0 ) return 1;
        return 0;
    }
    if (delX1 == 0){
        if (delY1 > 0) return 0;
        if ((delX2 ==0) && (delY2) < 0 ) return 0;
        if (delY1 < 0) return 1;
        return 0;
    }
    
    if (delY2/(double) delX2 - delY1/(double) delX1 > 0) result = 1;
    return result;
}

void quickSort(int left, int right){
    int midX = point[(left+right)/2].x;
    int midY = point[(left+right)/2].y;
    int i = left;
    int j = right;
    while (i<=j){
        while (pointChecker(point[i].x,point[i].y,midX,midY)==1) i++;
        while (pointChecker(midX,midY,point[j].x,point[j].y)==1) j--;
        if (i<=j){
            swap(point[i],point[j]);
            i++;
            j--;
        }
    }
    if (left<j) quickSort(left,j);
    if (i<right) quickSort(i,right);
}


