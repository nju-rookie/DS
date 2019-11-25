//
//  main.cpp
//  test-2-2
//
//  Created by 谢宇 on 2019/10/31.
//  Copyright © 2019 谢宇. All rights reserved.
//

#include <iostream>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

int num = 0;

node* create(node* Tree);
int main()
{
    node *Tree = NULL;
    Tree = create(Tree);
    
}


node* create(node* Tree)
{
    int c;
    cin >> c;
    if(c == -1) Tree = NULL;
    else{
        Tree = (node*)malloc(sizeof(node));
        num++;
        Tree -> data = c;
        Tree -> left = create(Tree -> left);
        Tree -> right = create(Tree -> right);
    }
    return Tree;
}


