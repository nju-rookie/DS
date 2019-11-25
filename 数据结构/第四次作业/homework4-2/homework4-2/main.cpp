#include <iostream>
#include <stack>
using namespace std;

static int num = 1;
int judge(char* str);

int main()
{
    //存储字符串的数组str
    char str[300];
    cin.get(str,300);
    while(str[num-1]!= '\0') num++;
    
    //存储两个//中间的字符串s
    char (*s)[300];
    int j = 0;
    int k = 0;
    for(int i = 1;i < num-1;i++){
        if(str[i] != '/'){
            *(*(s+j)+k) = str[i];
            k++;
        }
        if(str[i] == '/' || i == num-2)
        {
            *(*(s+j)+k) = '\0';
            k = 0;
            j++;
        }
    }

    
     stack<char*> st;
     for(int i = 0;i < j;i++){
         //遇到合法的目录，入栈
         if(judge(s[i]) == 1)
             st.push(s[i]);
         //返回上一级目录，且此时不在根目录下的情况，出栈
         if(judge(s[i]) == 0 && !st.empty())
             st.pop();
     }
     
    //依然在根目录下
     if(st.empty()) {cout <<'/';return 0;}
     
    //为了倒转输出，用另一个栈存储元素
     stack<char*> st2;
    
     while(!st.empty()){
        st2.push(st.top());
        st.pop();
     }
    
    
    while(!st2.empty()){
        cout << '/' ;
        for(int i = 0;st2.top()[i]!='\0';i++)
            cout << st2.top()[i];
        st2.pop();
    }
    return 0;
       
}


int judge(char* str)
{
    //空字符串
    if(str[0] == '\0')
        return -1;
    //. 代表当前目录
    if(str[0] == '.' && str[1] == '\0')
        return -1;
    //.. 代表上一级目录
    if(str[0] == '.' && str[1] == '.')
        return 0;
    //代表合法目录
    return 1;
}
