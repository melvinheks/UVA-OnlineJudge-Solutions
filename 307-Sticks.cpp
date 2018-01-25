#include <iostream>

using namespace std;

int main()
{
    int n;
    int m;
    int sum = 0;
    int max = 0;
    while(cin >> n){
        if(n==0)break;
        while(n-->0){
            cin >> m;
            sum += m;
            if(m > max) max = m;
        }
        int temp = max;
        while(temp>0){
            if(sum%temp==0 && sum/temp >= max){
                //cout<<sum<<endl;
                //cout<<temp<<endl;
                cout<<sum/temp<<endl;
                break;
            }
            temp--;
        }
        max = 0;
        sum = 0;
    }
}
