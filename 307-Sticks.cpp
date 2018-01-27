#include <iostream>
#include <algorithm>

using namespace std;

int* vals;

bool* unadded;
bool possible_length(int n, int total, int goal)
{
	if(total > goal) return false;
	if(total == goal) return true;
	for(int i = 0; i < n; i++){
		if(unadded[i]){
			unadded[i] = false;
			if(possible_length(n, total+vals[i], goal)){
				return true;	
			}
			else{
				unadded[i] = true;
			}
		}
	}
	return false;

}
int main()
{
    int n;
	int size;
    int m;
    int sum = 0;
    int max = 0;
    while(cin >> n){
        if(n==0)break;
		vals = new int[n];
		unadded = new bool[n];
		size = n;
		fill_n(unadded, n, true);
        while(n-->0){
            cin >> m;
			vals[n] = m;
            sum += m;
            if(m > max) max = m;
        }
        int temp = max;
        while(temp>0){
            if(sum%temp==0 && sum/temp >= max){
                //cout<<sum<<endl;
                //cout<<temp<<endl;
				int i;
				for(i = 0; i < temp; i++){
					if(!possible_length(size, 0, sum/temp)){
						fill_n(unadded, size, true);
						break;
					}
				}
				if(i==temp){
					cout<<sum/temp<<endl;
					break;
				}
            }
            temp--;
        }
        max = 0;
        sum = 0;
		delete[] vals;
    }
}
