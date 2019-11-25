
#include <iostream>
#include <stack>
using namespace std;

struct node{
    int data; //数据成员，-1代表空节点
    node *left; //左子树
    node *right; //右子树
};

struct node_tag{
    node* ptr;
    int flag;
};

//利用递归的方式构造树
node* create(node* Tree);
void preorder(node* p);
void inorder(node* p);
void postorder(node* p);


int main()
{
    node *Tree = NULL;
    Tree = create(Tree);
    preorder(Tree);
    inorder(Tree);
    postorder(Tree);
}

node* create(node* Tree)
{
    int c;
    cin >> c;
    if(c == -1) Tree = NULL;
    else{
        Tree = (node*)malloc(sizeof(node));
        Tree -> data = c;
        Tree -> left = create(Tree -> left);
        Tree -> right = create(Tree -> right);
    }
    return Tree;
}

void preorder(node* p)
{
    stack<node*> st;
    st.push(NULL);
    do{
        while( p != NULL){
            cout << p -> data << ' ';
            if(p -> right != NULL)
                st.push(p -> right);
            p = p -> left;
        }
        p = st.top();
        st.pop();
    }while( p != NULL || !st.empty());
    cout << endl;
}


void inorder(node* p)
{
    stack<node*> s;
    s.push(NULL);
    do{
        while(p != NULL){
            s.push(p);
            p = p -> left;
        }
        p = s.top();
        s.pop();
        if( p != NULL)
        {
            cout << p->data<<' ';
            p = p -> right;
        }
    }while(p != NULL || !s.empty());
    cout << endl;
}


void postorder(node* Tree)
{
    stack<node_tag> st;
    node_tag w;
    node *p = Tree;
    do{
        while(p != NULL){
            w.ptr = p;
            w.flag = 1;
            st.push(w);
            p = p -> left;
        }
            int temp = 1;
            while(temp && !st.empty()){
                if(st.top().flag==1){
                    st.top().flag = -1;
                    temp = 0;
                    p = st.top().ptr -> right;
                }else{
                    cout << st.top().ptr -> data <<" ";
                    st.pop();
                }
            }
    }while(!st.empty() || p != NULL);
    cout << endl;
}
