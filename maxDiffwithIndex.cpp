#include <iostream>

using namespace std;

int min(int a , int b){
	if(a < b)
		return a;
	return b;
}



int maxDiff(int a[], int size){
	
	int max_diff = a[1] - a[0];
	int Value = a[0];	
	
	for(int i = 2; i < size; i++){

		int min_value = min(a[i-1], Value);

		if(a[i] - min_value > max_diff){
			max_diff = a[i] - min_value;
			Value = min(a[i], min_value);
		}	
		
	}

	return max_diff;
}

int main(){

	int a[] = {2,3,10,6,4,8,1};
	cout<<endl<<maxDiff(a,7);
	return 0;

}