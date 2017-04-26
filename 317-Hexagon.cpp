// Example program
#include <iostream>
#include <string>
#include <algorithm>
#include <functional> 
using std::cout;
using std::cin;
using std::sort;
using std::greater;
int calculate(int nums[], bool isHighest){
	if(isHighest)return 8*nums[0] + 6*nums[1] + 5*nums[2];
	return 7*(nums[0] + nums[1]) + 5*nums[2];
}
bool checkDup(int nums[], int size){
	for(int i = 0; i < size-1; i++){
		for(int j = i+1; j < size; j++){
			if(nums[i]==nums[j]) return true;
		}
	}
	return false;
}
int main()
{
	int input[3][3];
	int n;
	int max = 0;
	int indMax;
	int result;
	int sum = 0;
	cin >> n;
	for(int tests = 1; tests <=n; tests++){
		for(int i = 0; i<3;i++){
			for(int j =0; j<3;j++){
				cin>>input[i][j];
			}
			sort(input[i], input[i]+3, greater<int>());
			result = calculate(input[i], true);
			if(result>max){
				max = result;
				indMax = i;
			}
		}
		sum += max;
		for(int k = 0; k <3; k++){
			if(k!=indMax)sum+=calculate(input[k], false);
		}
		cout << "Test #" << tests << "\n" << sum << "\n";
		cout << "\n";
		sum = 0;
		max = 0;
	}
}
