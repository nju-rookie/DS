#include <iostream>
using namespace std;

int main()
{
    char str[300];
    cin.getline(str,300);
    //输出字符串dest,临时字符串temp
    char dest[5000],temp[5000];
    int i = 0;
    int k = 0;
    while(str[i] != '\0'){
        //除了]，其他字符均输入dest中
        if((str[i] >= '0' && str[i]<= '9') || (str[i] >='a' && str[i] <= 'z' )||str[i] == '[')
            dest[k++] = str[i++];
        if(str[i] == ']'){
            //m用于寻找翻倍的数字
            //mul代表倍数
            int m = k - 1;
            int mul = 0;
            
            while(dest[m]<'0' || dest[m]>'9'){m--;}
            while(dest[m-1]>='0'&& dest[m-1]<='9' && m > 0){m--;}
            int temp_m = m;
            while(dest[temp_m]>='0'&&dest[temp_m]<='9'){ mul = 10*mul+dest[temp_m]-'0';temp_m++;}
            //将翻倍内容临时存放在temp中
            int temp_size = 0;
            for(int j = temp_m+1; j < k;j++) {temp[temp_size++] = dest[j];}
            temp[temp_size] = '\0';
            //翻倍
            while(mul) {
                int temp_i = 0;
                while(temp[temp_i]!='\0') dest[m++] = temp[temp_i++];
                mul--;
            }
            k = m;//重新设置位点
            dest[k] = '\0';
            i++;
        }
    }
    dest[k] = '\0';
    for(int temp_k = 0;temp_k < k;temp_k++) cout << dest[temp_k];
}

