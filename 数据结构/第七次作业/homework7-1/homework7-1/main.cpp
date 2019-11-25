#include <iostream>
using namespace std;

int main()
{
    int n;
    int sum = 0;
    int a[500];
    int res[10001];
    int res2[10001];
    for(int i = 0;i < 10001;i++){res[i]=0;res2[i]=0;}
    cin >> n;
    for(int i = 0;i < n;i++) {cin >> a[i];}
    for(int i = 0;i < n;i++) {
        int temp;
        cin >> temp;
        for(int j = 0;j < n;j++){
            if(temp + a[j] <= 10000){
                res[temp+a[j]]++;
            }
        }
    }

    for(int i = 0;i < n;i++) {cin >> a[i];}
    for(int i = 0;i < n;i++) {
        int temp;
        cin >> temp;
        for(int j = 0;j < n;j++){
            if(temp + a[j] <= 10000){
                res2[temp+a[j]]++;
            }
        }
    }
    
    for(int i = 0;i < 10001;i++){
            sum = sum + res[i]*res2[10000-i];
    }
    cout << sum;
    return 0;
}
    
