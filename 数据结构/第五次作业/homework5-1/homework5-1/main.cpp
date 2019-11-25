#include <iostream>
#include <string.h>
using namespace std;
static int res[100000];
static int res_size = 0;
char s1[100000],s2[100000];
int n[100000];
int len1;
int len2;


//next数组
void getNext()
{
        n[0] = -1;
        int j = 0;
        int k = -1;
        while(j < len2){
            if(k == -1 || s2[j] == s2[k]){
                j++;k++;
                n[j] = k;
            }
            else
                k = n[k];
        }
    }

void KMP()
{
    //p1是指向主串，p2指向模式串
    int p1 = 0;
    int p2 = 0;
    int num = 0;
    //生成next数组
    getNext();
    //匹配
    while(p1 < (len1-1) && p2 < (len2-1)){
        if(p2 == -1 || s1[p1] == s2[p2]) {
            p1++;
            p2++;
        }
        else
            p2 = n[p2];

        //如果匹配成功
        if(p2 == (len2-1)){
            //将结果记录在res数组中
            res[num++] = p1 - len2 + 1;
            res_size++;
            //从头开始匹配
            p2 = 0;
        }
    }
}


int main()
{

    cin.getline(s1,100000);
    cin.getline(s2,100000);
    len1 =(int)strlen(s1) +1;
    len2 =(int)strlen(s2) +1;
    KMP();
    if(res_size == 0)
        cout << "false";
    else
        for(int i = 0;i < res_size;i++)
            cout << res[i] <<' ';
}
