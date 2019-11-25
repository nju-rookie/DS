#include <iostream>
#include <stack>
using namespace std;

int num;
bool judge(int n,int *p);

int main()
{
    int temp;
    cin >> num;
    int *p = new int[num];
    cin >> temp;
    if(temp > 8) p[0] = 1; else p[0] = -1;
    
    for(int i = 1;i < num;i++){
        cin >> temp;
        if(temp > 8)
            p[i] = p[i-1]+1;
        else
            p[i] = p[i-1]-1;
    }

    
    //两种极端情况
    if(p[num-1] > 0){cout << num;delete []p;return 0;}
    if(p[num-1] == -num){cout << "0";delete []p;return 0;}
    
    //其他情况,i代表可能的长度，从长到短
        for(int i = num-1;i >=1 ;i--){
            if(p[i-1] > 0) {cout << i;delete []p;return 0;}
            for(int j = 1;j+i < num+1;j++){
                if(p[i+j-1] - p[j-1] > 0)
                    {cout << i;delete []p;return 0;}
            }
        }
    delete []p;
    return 0;

}



