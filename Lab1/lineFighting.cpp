/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: TuanDung
 *
 * Created on March 2, 2019, 10:58 PM
 */
#include <iostream>

using namespace std;

/*
 * 
 */
void solve(){
        int n;//num of fighter
    int k;//num of team
    cin >>n>>k;
    int num_avg = n/k;
    int num_mod = num_avg +1;
    int team_avg = n%k;//số người dư
    int team_mod = k - team_avg;
    
    int tmp = n;
    int result = 0;
    
    for(int j=0 ; j <team_mod;j++){
        tmp = tmp-num_avg;
        result += tmp*num_avg;
    }
//    printf("%d  %d  %d  %d  %d %d",team_avg,num_mod,team_mod,num_avg,tmp,result);
    for(int i=0 ; i <team_avg ;i++ ){
        tmp = tmp - num_mod;
        result += tmp*num_mod;
        
    }

    cout << result;
}
int main() {
    
    int t;
    cin >>t;
    while(t>0){
        solve();
        t--;
        cout << '\n';
    }

    return 0;
}

