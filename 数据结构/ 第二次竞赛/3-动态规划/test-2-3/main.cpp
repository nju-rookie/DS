//小蓝鲸最近下载了一款NJU版跳方格游戏。游戏规则如下：给定一个n×n的方格阵M，玩家需要从左上角移动到右下角
//规定每次只能向右或者向下跳一格，方格阵M中每个数字代表经过此点消耗的体力，只有消耗的体力值较少，才能获得更
//高的游戏排名。小蓝鲸希望你能帮他计算出最小的体力消耗值。

#include <iostream>
using namespace std;

int a[50][50];
int n;

int min(int x,int y);

int main()
{

    cin >> n;
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            int temp;
            cin >> temp;
            if(i == 0 && j == 0)
                a[i][j] = temp;
            if(i == 0 && j > 0)
                a[i][j] = temp + a[i][j-1];
            if(j == 0 && i > 0)
                a[i][j] = temp + a[i-1][j];
            if(i > 0 && j > 0)
                a[i][j] = temp + min(a[i-1][j],a[i][j-1]);
        }
    }
    cout << a[n-1][n-1];
}

int min(int x,int y)
{
    if(x > y)
        return y;
    return x;
}

