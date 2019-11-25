#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

//创建链表函数,传输参数num个数和comp划分值
node *create(int num,int comp);

int main()
{
    int number;//链表长度
    int x;//划分链表
    cin >> number;
    cin >> x;//用于划分链表
    if(number == 0) return 0;
    node *head = create(number,x);
    node *p = head;
    while(p) {cout << p -> data << " ";p = p -> next;}
    return 0;
}

node *create(int num,int comp)
{
    node *head1 = NULL,*tail1 = NULL;
    node *head2 = NULL,*tail2 = NULL;
    for(int i = 0;i < num;i++){
        node *p = (node*)malloc(sizeof(node));
        cin >> p -> data;
        if(p -> data >= comp){
            p -> next = NULL;
            if(head2 == NULL)
                head2 = p;
            else
                tail2 -> next = p;
            tail2 = p;
        }
        else{
            p -> next = NULL;
            if(head1 == NULL)
                head1 = p;
            else
                tail1 -> next = p;
            tail1 = p;
        }
        
    }
    if(head1 == NULL)
        return head2;
    tail1 -> next = head2;
    return head1;
}




