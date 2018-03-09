
#include <vector>
#include <climits>
#include <iostream>


using namespace std;
// Simple Solution Not much of logic. O(n^2) solution

int sum(vector< vector<int> >& ivec, int& i, int& j){
    return (ivec[i][j]+ivec[i][j+1]+ivec[i][j+2]
               +ivec[i+1][j+1]
               +ivec[i+2][j]+ivec[i+2][j+1]+ivec[i+2][j+2]);    
}


int main(){
    vector< vector<int> > arr(6,vector<int>(6));
    for(int arr_i = 0;arr_i < 6;arr_i++){
       for(int arr_j = 0;arr_j < 6;arr_j++){
          cin >> arr[arr_i][arr_j];
       }
    }
    int res = -1000;
    for(int i = 0; i < 4 ; i++){
        for(int j = 0; j < 4;j++ ){
            if(sum(arr, i, j) > res)
                res = sum(arr, i, j);
        }
    }
    cout<<res<<endl;
        
    return 0;
}
