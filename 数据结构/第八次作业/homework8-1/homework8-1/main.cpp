
#include <iostream>
using namespace std;

struct node{
    int data; //数据成员，-1代表空节点
    node *left; //左子树
    node *right; //右子树
};

int a[2] = {0};
int res[2][2] = {0};
int inorder[300000];
int k = 0;

void in(node* Tree);

node* create(node* Tree);

int main()
{
    int num;
    cin >> num;
    node *Tree = NULL;
    Tree = create(Tree);
    in(Tree);
    k = 0;
    for(int i = 0;i < num-1;i++){
        if(inorder[i] > inorder[i+1]){
            res[k][0]=inorder[i];
            res[k][1]=inorder[i+1];
            k++;
        }
    }
    
    if(k == 1)
        cout << res[0][0] <<' '<<res[0][1];
    else
        cout << res[1][1] << ' '<<res[0][0];

}


node* create(node* Tree)
{
    int c;
    cin >> c;
    if(c == -1) Tree = NULL;
    else{
        Tree = (node*)malloc(sizeof(node));
        Tree -> data = c;
        Tree -> left = create(Tree -> left);
        Tree -> right = create(Tree -> right);
    }
    return Tree;
}


void in(node* Tree)
{
    if(Tree!=NULL){
        in(Tree->left);
        inorder[k++]  = Tree -> data;
        in(Tree->right);
    }
}
