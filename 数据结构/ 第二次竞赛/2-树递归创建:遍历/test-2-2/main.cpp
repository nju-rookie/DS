//
//  main.cpp
//  test-2-2
//
//  Created by 谢宇 on 2019/10/31.
//  Copyright © 2019 谢宇. All rights reserved.


//  给定两个二叉树，检查它们是否呈镜像对称的。即树的结构成轴对称，且对应节点的节点值相同

#include <iostream>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};
void InOrder(node *Tree);
void PostOrder(node *Tree);

int a[200];
int b[200];
int num1=0;
int num2=0;

node* create(node* Tree);
int main()
{
    node *Tree_1 = NULL;
    Tree_1 = create(Tree_1);
    node *Tree_2 = NULL;
    Tree_2 = create(Tree_2);
    if(Tree_1 == NULL && Tree_2 == NULL)
    {cout << "YES";return 0;}
    
    if((Tree_1 == NULL && Tree_2 != NULL) || (Tree_1 != NULL && Tree_2 == NULL)) {cout <<"NO";return 0;}
    
    InOrder(Tree_1);
    PostOrder(Tree_2);
    
    if(num1 != num2)
    {cout << "NO";return 0;}
    
    for(int i = 0;i < num1;i++){
        if(a[i] != b[i])
        {cout << "NO";return 0;}
    }
    
    cout <<"YES";
    return 0;
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


void InOrder(node *Tree)
{
    node *p = Tree;
    if(p != NULL){
        InOrder(p -> left);
        a[num1++] = p -> data;
        InOrder(p -> right);
    }
}

void PostOrder(node *Tree)
{
    node *p = Tree;
       if(p != NULL){
           PostOrder(p -> right);
           b[num2++] = p -> data;
           PostOrder(p -> left);
       }
}
