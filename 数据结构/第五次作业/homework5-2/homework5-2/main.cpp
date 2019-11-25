#include <iostream>
using namespace std;
static int num = 0;
int data1;
int data2;
int pos1 = 0;
int pos2 = 0;


struct node{
    int data;
    node *l;//left child
    node *r;//right child
    node *pa;
};

//深度
int getDepth(node* root, int data, int depth);
//寻找父节点
int findParent(node* root, int data);
static node str[1000];

int main()
{
    char c;
    int num_n = 1;
    //用于处理字符串，flag = 1，代表一个数输入结束
    int flag = 1;
    while((c=getchar())!= '\n'){
        if(c == ' '){flag = 1;}
        if(c >= '0' && c <='9' && flag == 1)
        {
            str[num].data = num_n++;
            str[num].l = NULL;
            str[num].r = NULL;
            num++;
            flag = 0;
        }
        if(c == '#')
        {
            str[num].data = -1;
            str[num].l = NULL;
            str[num].r = NULL;
            num++;
        }
    }

    //输入两个节点的值
    cin >> data1 >> data2;
    int p1 = 0,p2 = 0;

    //建立树，双指针，p2+1是p1的左子树，p2+2是p1的右子树
    while(p1 < num ){
        if(str[p1].data == -1)
            p1++;
        if(str[p1].data != -1){
            if(p2+1 < num)
            {
            	str[p1].l = &str[p2+1];	
            	str[p2+1].pa = &str[p1];
            }
            if(p2+2 < num)
            {
            	str[p1].l = &str[p2+2];
            	str[p2+2].pa = &str[p1];
            }
            p1++;
            p2 += 2;
        }
    }

    //两者的深度
    int len1 = getDepth(&str[0],data1,0);
    int len2 = getDepth(&str[0],data2,0);
    cout << len1 <<' '<<len2<<endl;

    //两者父节点的值
    int x = findParent(&str[0],data1);
    int y = findParent(&str[0],data2);

    //判断是否为堂兄弟，深度一样但父节点不同
    if(len1 == len2 && x != y)
        cout << "true";
    else
        cout << "false";
    
    
}


int getDepth(node* root, int data, int depth){
    if( root == NULL)   return 0;
    if (root-> data == data) {
        return depth;
    }
    int left = getDepth(root->l, data, depth+1);
    int right = getDepth(root->r, data, depth+1);
    if(left > right)
        return left;
    else
        return right;
}



int findParent(node* root, int data) {
    if (root == NULL) {
        return 0;
    }
    if (root -> l != NULL && root->l->data == data) {
        return root->data;
    }
    if (root->r != NULL && root->r->data == data) {
        return root->data;
    }
    int left = findParent(root->l, data);
    int right = findParent(root->r, data);
    return max(left, right);
}
