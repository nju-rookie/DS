#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    int height;
    int weight;
};



bool compare(node data1,node data2)
{
    if(data1.height != data2.height)
        return data1.height > data2.height;
    else
        return data1.weight > data2.weight;
}

int cmp(node x1, node x2){
    if(x1.height < x2.height && x1.weight < x2.weight)
        return 1;
    return 0;
}


int main() {
    int num;
    node data[10000];
    int dp[10000];
    
    cin >> num;
    
    for(int i =0;i < num;i++){
        cin >> data[i].height;
        cin >> data[i].weight;
    }
    
    //按身高排序
    sort(data,data+num,compare);
    
    for(int i = 0;i < num;i++)
        dp[i] = 1;
    for(int i = 1;i < num;i++){
        for(int k =0; k < i;k++){
            if(cmp(data[i],data[k]))
                dp[i] = max(dp[k] + 1,dp[i]);
        }
    }
    int max=0;
    for(int i = 0;i < num;i++){
        if(dp[i] > max)
            max = dp[i];
    }
    
    cout << max;
    
    return 0;
}

/*
void sort1(int num,node* data)
{

    for(int i=0;i < num -1 ;i++){
        for(int j = 0;j < num-1-i;j++){
            if(data[j].weight < data[j+1].weight){
                int temp = 0;
                temp = data[j+1].height;
                data[j+1].height = data[j].height;
                data[j].height = temp;
                temp = data[j+1].weight;
                data[j+1].weight = data[j].weight;
                data[j].weight = temp;
            }
            else if(data[j].weight == data[j+1].weight && data[j].height < data[j+1].height){
                    int temp = 0;
                    temp = data[j+1].height;
                    data[j+1].height = data[j].height;
                    data[j].height = temp;
            }
        }
    }
}
 */
