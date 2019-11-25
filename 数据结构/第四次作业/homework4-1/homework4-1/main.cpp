#include <iostream>
using namespace std;

static int num;
static int tree[100000];

struct node{
    int data;
    node* left;
    node* right;
};

node* create(int x);
void InOrder_re(node *Tree);
int solve(node* p,node* p1,node* p2);

int main()
{
    cin >> num;
    for(int i = 0;i < num;i++)
        cin >> tree[i];
    if(num == 0)
        cout << "0";
    else{
        node* head = create(1);
        solve(head ,head -> left, head -> right);
        InOrder_re(head);
        cout << endl;
    }
    
}


node* create(int x)
{
    node* p = (node*)malloc(sizeof(node));
    p -> data = tree[x-1];

    if((x*2) <= num)
        p -> left = create(2*x);
    else
        p -> left = NULL;
    if((x*2+1) <= num)
        p -> right = create(2*x+1);
    else
        p -> right = NULL;
    return p;

}


void InOrder_re(node *Tree)
{
    node *p = Tree;
    if(p != NULL){
        if(p -> left != NULL)
            InOrder_re(p -> left);
        cout << p -> data << ' ';
        if(p -> right != NULL)
            InOrder_re(p -> right);
    }
}

int solve(node*p, node* p1,node* p2)
{
    int left = 0;
    int right = 0;
    if(p1 == NULL)
        left = 0;
    else
        left = solve(p1, p1 -> left, p1 -> right);
    if(p2 == NULL)
        right = 0;
    else
        right = solve(p2, p2 -> left, p2 -> right );
    
    if(left > right){
        node* temp = p -> left;
        p -> left = p -> right;
        p -> right = temp;
    }
    if(p1 == NULL && p2 == NULL)
        return p -> data;
    return left+right+p->data;
}
