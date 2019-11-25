//
//  main.cpp
//  homework8-3
//
//  Created by 谢宇 on 2019/11/25.
//  Copyright © 2019 谢宇. All rights reserved.
//

#include <iostream>
#include <set>


using namespace std;
struct node{
    int i;
    int data;

};

bool operator<(const node& x,const node& y)
{
    return x.data < y.data;
}

int main()
{
    int num;
    set<node> s;
    cin >> num;
    node temp;
    
    cin >> temp.data;
    temp.i = 0;
    s.insert(temp);
    
    for(int i = 1;i < num;i++){
        temp.i = i; cin >> temp.data;
        
        int y = s.begin()->data;
        
        if(temp.data < y){
            cout << y<<' ';
            s.insert(temp);
        }
        
        else if(s.upper_bound(temp) == s.end()){
            set<node>::iterator it=s.end();
            it--;
            cout << it->data <<' ';
            s.insert(temp);
            
        }else{
            set<node>::iterator it = s.upper_bound(temp);
            set<node>::iterator it2 = (it--);
            if(it->i > it2->i){
                cout << it->data <<' ';
                s.insert(temp);
            }
            else{
                cout << it2->data <<' ';
                s.insert(temp);
            }
        }
          
    }
}
