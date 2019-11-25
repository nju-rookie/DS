//
//  main.cpp
//  homework7-3
//
//  Created by 谢宇 on 2019/11/14.
//  Copyright © 2019 谢宇. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;


struct node{
    int x1;
    int x2;
    int des;
};


int pre[20000];
int a[20000];


bool cmp(node c1,node c2)
{
    return c1.des > c2.des;
}



int find(int x)
{
    while(x != pre[x])
        x = pre[x];
    return x;
}


void add(int x,int y)//合并
{
    x=find(pre[x]);
    y=find(pre[y]);
    pre[x]=y;
}



int main()
{
    //number of rogue
    int num = 0;
    //combination of rogue
    int com = 0;

    cin >> num;
    cin >> com;
    
    node c[100000];

    for(int i = 1; i < num+1;i++){
        pre[i]  = i;
    }
    
    for(int i = 0;i < com;i++){
        cin >> c[i].x1 >> c[i].x2 >> c[i].des;
    }
    
    sort(c,c+com,cmp);
    
    int min = 0;
    for(int i = 0;i <= com;i++){
        if(find(c[i].x1)==find(c[i].x2))
        {
            min = c[i].des;
            break;
        }
        else
        {
            if(a[c[i].x1] == 0)
            {a[c[i].x1] = c[i].x2;}
            else
            {add(a[c[i].x1],c[i].x2);}
            if(a[c[i].x2] == 0)
            {a[c[i].x2]=c[i].x1;}
            else
            {add(a[c[i].x2],c[i].x1);}
        }
    }
    
    cout << min << endl;
}
