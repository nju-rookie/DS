
#include <iostream>
using namespace std;

int tree[31][3];
int solve[30][30];

int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        tree[i][0] = i;
        cin >> tree[i][1];
        cin >> tree[i][2];
    }
    

    //i是二维数组的行号，k是i下一层的元素个数
    int i = 0;
    int k = 0;
    solve[0][0] = 1;
    //根节点必定要输出
    cout << '1' <<' ';

    //层序遍历，len记录每一层的长度
    int len = 1;
    while(true){
        //记录每一层最后一个节点
        int last;
        k = 0;
        for(int count = 0; count < len;count++){
            //左子树不是NULL，
            if(tree[solve[i][count]-1][1] != -1)
            {
                    solve[i+1][k++] = tree[solve[i][count]-1][1];
            }
            //右子树不是NULL
            if(tree[solve[i][count]-1][2] != -1)
            {
                solve[i+1][k++] = tree[solve[i][count]-1][2];
            }
    
        }
        last = solve[i+1][k-1];
        //如果一层有超过两个节点，输出第一个和最后一个
        if(k-1 != 0)
            cout << solve[i+1][0] <<' '<<solve[i+1][k-1]<<' ';
        //如果一层只有一个节点，输出这唯一一个节点
        if(k-1 == 0)
            cout << solve[i+1][0]<<' ';
        //如果已经处理到最后一个节点n，跳出循环        
        if(last == n)
            break;
        //记录下一层的个数
        len = k;
        i++;
    }
    
}

