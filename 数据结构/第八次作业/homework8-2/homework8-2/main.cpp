#include <iostream>
using namespace std;

struct node{
    int data; //数据成员，-1代表空节点
    node *left; //左子树
    node *right; //右子树
};

node* create(node* Tree);

int sum = 0;
int post(node* Tree)
{
    //空节点返回0
    if(Tree == NULL)
        return 0;
    int temp1 = post(Tree -> left);
    int temp2 = post(Tree -> right);
    //叶子节点返回1
    if(!temp1 && !temp2)
       return 1;
    //叶子节点的父节点必定放置守卫，返回2
    if(temp1==1 || temp2==1){
        sum++;
        return 2;
    }
    //子结点有守卫，此点不用放守卫，返回3
    if(temp1 == 2 || temp2 == 2)
        return 3;
    //子结点没有守卫，此节点与叶子节点性质相同，返回1
    if((temp1 == 3 && temp2 == 3) || (temp1 == 3 && temp2 == 0)||(temp1 == 0 && temp2 == 3)){
        return 1;
    }
    return 0;
        
}
int main()
{
    node *Tree = NULL;
    Tree = create(Tree);
    int k = post(Tree);
    if(k == 1)
        sum++;
    cout << sum << endl;

}


node* create(node* Tree)
{
    int c;
    cin >> c;
    if(c == -1) Tree = NULL;
    else{
        Tree = (node*)malloc(sizeof(node));
        Tree -> data = 0;
        Tree -> left = create(Tree -> left);
        Tree -> right = create(Tree -> right);
    }
    return Tree;
}

