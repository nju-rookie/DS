#include <iostream>
using namespace std;



int n;
int tree[100000][3];
int max(int x,int y);

int main()
{
    cin >> n;
    int m = 0;
    for(int i = 0;i < n;i++){
        tree[i][0] = i;
        cin >> tree[i][1];
        cin >> tree[i][2];
    }
    
    int x = 0;
    int len = 0;
    while(x < n)
    {
        int max_left = max(x,tree[x][1]);
        int max_right = max(x,tree[x][2]);
        len = max_left + max_right;
        if (len > m)
            m = len;
        if(max_left > max_right)
            x = tree[x][1];
        else
            x = tree[x][2];
        if(x == -1)
            break;
    }

    cout << m + (n-1-m)*2 << endl;

}
 
int max(int x,int y)
{
    if(y == -1)
        return 0;
    else{
        int len1 = max(y,tree[y][1]);
        int len2 = max(y,tree[y][2]);
        if(len1 > len2)
            return len1 + 1;
        return len2 + 1;
    }
}


