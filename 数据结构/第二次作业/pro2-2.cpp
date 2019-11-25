#include <iostream>
using namespace std;

struct node{
	int i;
	node *pre;
	node *next;
};
node *create(int number);
void solve(node* head,int left,int right);


int main()
{
	int number;//学生人数
	int left,*right;//顺时针数right个，逆时针数left个
	node *head = create(number);
	solve(head,left,right);

}

node *create(int number)
{
	node *head = NULL,*tail = NULL;
	for（int i=0;i<number;i++)
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
		int a = right;
		int b = left;
		if(head == NULL) break;
		while(a--) p1 = p1 -> next;
		while(b--) p2 = p2 -> pre;
		if(p1 == p2){cout << p1 -> i << " "; break;}
		else{
			//删除该节点
			cout << p1 -> i << " "<<p2 -> i<< " ";
			node *temp1 = p1 -> pre;
			node *temp2 = p1 -> next;
			temp1 -> next = temp2;
			temp2 -> pre = temp1;
			p1 = NULL;
			p1 = temp2;//新起点
			node *temp1 = p2 -> pre;
			node *temp2 = p2 -> next;
			temp1 -> next = temp2;
			temp2 -> pre = temp1;
			p2 = NULL;
			p2 = temp1;
		}

	}

}