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
int main()
{
	int input[3][3];
	int n;
	int max = 0;
	int indMax;
	int result;
	int result2;
	int sum = 0;
	cin >> n;
	for(int tests = 1; tests <=n; tests++){
		for(int i = 0; i<3;i++){
			for(int j =0; j<3;j++){
				cin>>input[i][j];
			}
			sort(input[i], input[i]+3, greater<int>());
			result = calculate(input[i], true);
			result2 = calculate(input[i], false);
			if(result-result2>max){
				max = result-result2;
				indMax = i;
			}
		}
		sum += calculate(input[indMax], true);
		for(int k = 0; k <3; k++){
			if(k!=indMax)sum+=calculate(input[k], false);
		}
		cout << "Test #" << tests << "\n" << sum << "\n";
		cout << "\n";
		sum = 0;
		max = 0;
	}
}
