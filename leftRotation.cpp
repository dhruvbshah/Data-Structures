
#include <vector>
#include <iostream>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    // O(n) solution.
    int n, r;
    cin>>n>>r;
    vector<int> ivec(n);
    for(int i = 0; i < n; i++)
        cin>>ivec[i];
    r = r%n;
    for(int i = 0; i < n; i++)
        cout<<ivec[(i+r)%n]<<" ";
    return 0;
}
