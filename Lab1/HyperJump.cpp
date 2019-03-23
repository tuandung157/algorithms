# include <iostream>
  using namespace std;
  void solve(){
      int result = 0, max_ending=0;
      int n;//size
      cin >>n;  
      int arr[60010];      
      for(int i =0;i< n;i++){
          cin>> arr[i];
          max_ending = max_ending + arr[i];
          if(result < max_ending) result = max_ending;
          if(max_ending < 0) max_ending = 0;
      }
      cout<< result;
  }
  int main()
  {
      int t = 1;
      while(t > 0){
          solve();
          t--;
          cout << '\n';
      }
      return 0;
  }