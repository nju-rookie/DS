#include <iostream>
using namespace std;


int data[1000];
int main()
{
    int sum = 0;
    for(int i = 0 ; i < 1000 ;i++) data[i] = -1;
    char c;
    
    do{
        int temp = -1;
        cin >> temp;
        if(data[temp] == -1)
            data[temp]++;
        data[temp]++;
    }while((c = getchar()!= '\n'));


    for(int i = 0; i < 1000; i++){
        if(data[i] >= 0)
        {
            int temp = data[i] / (i+1);
            sum = sum + temp*(i+1);
            if(data[i] % (i+1) != 0)
                sum = sum + i + 1;
        }
    }
    
    cout << sum;
}
