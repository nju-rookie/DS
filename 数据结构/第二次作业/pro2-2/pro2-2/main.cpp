#include <iostream>
using namespace std;
 
struct node{
    int i;
    node *pre;
    node *next;
};
//创建双向循环链表
node *create(int number);
//解决问题
void solve(node* head,int left,int right);
 
 
int main()
{
    //学生人数
    int number;
    int left,right;
    cin >> number >> left >> right;
    node *head = create(number);
    solve(head,left,right);
     
}
 
node *create(int number)
{
    node *head = NULL,*tail = NULL;
    for(int i=0;i<number;i++)
    {
        node *p = (node*)malloc(sizeof(node));
        p -> i = i+1;
        p -> next = NULL;
        if(head == NULL){
            head = p;
            head -> pre = head;
            head -> next = head;
        }
        else{
            tail -> next = p;
            p -> pre = tail;
        }
        tail = p;
    }
    head -> pre = tail;
    tail -> next = head;
    return head;
}
 
 
 
void solve(node* head,int left,int right)
{
    node *p1 = head;
    node *p2 = head -> pre;
    while(true){
        int a = left;
        int b = right;
        
        //如果链表为空，跳出链表
        if(p1 == p2 && p1 == NULL) break;
        
        //如果不为空，进行选班长的操作
        while(--a) p1 = p1 -> next;
        while(--b) p2 = p2 -> pre;
        
        //选中班长，跳出循环
        if(p1 == p2) {cout <<p1 -> i << " "; break;}
        
        //没有选中班长，进行删除操作
        else{
            //剩下的人数超过两个人，删除两个人，循环继续
            if(p1 -> pre != p1 -> next)
                {cout << p1 -> i << " "<<p2 -> i<< " ";
                    node *temp1 = p1 -> pre;
                    node *temp2 = p1 -> next;
                    temp1 -> next = temp2;
                    temp2 -> pre = temp1;
                    p1 = NULL;
                    node *temp3 = p2 -> pre;
                    node *temp4 = p2 -> next;
                    temp3 -> next = temp4;
                    temp4 -> pre = temp3;
                    p2 = NULL;
                    p1 = temp1 -> next;
                    p2 = temp4 -> pre;}
            
            //剩下两个人，删除两人，循环结束
            else
            {
                cout << p1 -> i << " " << p2 -> i <<" ";
                p1 = NULL;
                p2 = NULL;
            }
        }
    }
}
