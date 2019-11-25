//
//  main.cpp
//  homework6-3
//
//  Created by 谢宇 on 2019/11/7.
//  Copyright © 2019 谢宇. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    char c;
    while(true)
    {
        if((c = getchar()) == EOF)
            break;
        int array[30];
        int hash[30];
        int num = 0;
        cin >> num;
        for(int i = 0; i < num;i++)
            cin >> array[i];
        for(int i = 0; i < 30;i++)
            hash[i] = -1;

        for(int i = 0;i < num;i++){
            int temp = array[i];
            while(temp > 9)
                temp = temp/10;
            while(hash[temp] != -1)
                temp = (temp + 1) % 30;
            hash[temp] = array[i];
        }
        int last = 0;
        for(int i = 0;i < 30;i++){
            if(hash[i] != -1)
                last = i;
        }
        for(int i = 0;i < last;i++){
            if(hash[i] != -1)
                cout << hash[i] <<',';
        }
        cout << hash[last] << endl;
    }
}

