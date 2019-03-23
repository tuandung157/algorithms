/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: TuanDung
 *
 * Created on March 3, 2019, 1:00 AM
 */

#include <iostream>
#include <climits>

using namespace std;

/*
 * 
 */
//commands function quick sort
int result;
int a[22];
void solve(int num, int test){

    if(num <0) result = min(result, abs(test));
    else{
        solve(num -1, test + a[num]);
        solve(num -1, test - a[num]);
    }
}
        
int main() {
    
    int num;
    cin >> num;
    for(int i =0; i < num; i++){
        cin >> a[i];
    }
    result =INT_MAX;
    solve(num,0);
    cout << result;

    
    return 0;
}


