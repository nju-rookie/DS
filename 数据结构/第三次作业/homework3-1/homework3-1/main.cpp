#include <iostream>
using namespace std;

int main()
{
    char str[1000000];
    char stack[1000000];
    cin.get(str,100000);
    int j = 0;
    int sum = 0;
    if(str[0] == '\0')
        cout << "0";
    else{
    for(int i = 0;str[i]!='\0';i++){
        if(str[i] == '(') stack[j++] = '(';
        if(str[i] == ')'){
            if(j == 0)  sum++;
            else j--;
        }
    }
    sum+=j;
    cout << sum << endl;
    }
}
