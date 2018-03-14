#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    // O(n) Complexity - Easy 
    int N,T;
    cin>>N>>T;
    vector< vector<int> > ivec(N, vector<int>());
    int li = 0;
    for(int i = 0; i < T; i++){
        int q,x,y;
        cin>>q>>x>>y;
        int index = (x^li)%N;
        if(q == 1)
            ivec[index].push_back(y);
        else{
            int size = ivec[index].size();
            li = ivec[index][y%size];
            cout<<li<<endl;
            
        }
        
    }    
    return 0;
}
