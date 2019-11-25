#include <iostream>
using namespace std;

struct node{
    char letter;
    node *next;
};


struct stack{
    node *top;
    node *bottom;
};

void create(stack& st);
void print(stack st);
void solve(stack st);


int main()
{
    stack st;
    create(st);
    solve(st);
}

//用链表实现栈的创建和初始化
void create(stack& st)
{
    st.top = NULL;
    st.bottom = NULL;
    char c;
    while((c = getchar())!= '\n'){
        node *p = (node*)malloc(sizeof(node));
        p -> letter = c;
        p -> next = NULL;
        if(st.top == NULL) st.top = p;
        else
            p -> next = st.top;
        st.top = p;
    }
}

//输出栈的内容
void print(stack st)
{
    while(st.top != st.bottom){
        cout << st.top -> letter;
        st.top = st.top -> next;
    }
}

void solve(stack st)
{
    stack temp;
    //名为temp的栈，用于存放空格中间的单词
    temp.top = NULL;
    temp.bottom = NULL;
    while(true)
    {
        //到达栈底，跳出循环
        if(st.top == st.bottom)
        {
            if(temp.top != temp.bottom)
                print(temp);
            break;
        }
        //遇到空格，表明一个单词已经结束
        else if(st.top -> letter == ' ')
        {
            //输出临时存放字母的temp栈中的内容
            if(temp.top != temp.bottom) {print(temp);temp.top = NULL;}
            //有多个空格的情况
            while(st.top -> letter ==' ') {
                cout << ' ';
                if(st.top -> next == NULL){
                    st.top = st.bottom;
                    break;
                }
            //栈顶向下移动
            st.top = st.top -> next;
            }
        }else{
            //遇到字母，将字母存放进临时栈
           node *p = (node*)malloc(sizeof(node));
           p -> letter = st.top -> letter;
           p -> next = NULL;
           if(temp.top == NULL) temp.top = p;
           else
               p -> next = temp.top;
           temp.top = p;
           //栈顶向下移动
           st.top = st.top -> next;
        }
    }
}
