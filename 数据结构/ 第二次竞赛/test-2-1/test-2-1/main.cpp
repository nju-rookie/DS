//
//  main.cpp
//  test-2-1
//
//  Created by 谢宇 on 2019/10/31.
//  Copyright © 2019 谢宇. All rights reserved.
//

#include <iostream>
using namespace std;
int num;
struct node{
    int data;
    int hao;
};

int main()
{
    cin >> num;
    int max = 0;
    node a[10000];
    for(int i = 0;i < 10000;i++)
    {a[i].data = 0;a[i].hao = i;}
    
    for(int i = 0;i < num;i++){
        int temp;
        cin >> temp;
        if(temp > max)  max = temp;
        a[temp].data++;
    }
    int k = 0;
    cin >> k;
    for(int i = 0;i < k;i++){
        node m;
        m.data = 0;
        for(int j = 0;j <= max;j++){
            if(m.data < a[j].data)
            {m.data = a[j].data;m.hao = a[j].hao;}
        }
        cout << m.hao << ' ';
        a[m.hao].data = 0;
    }
}
