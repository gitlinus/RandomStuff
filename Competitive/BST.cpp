#include "stdc++.h"
using namespace std;

int N, a, Q;

struct node
{
    int data;
    struct node * left;
    struct node * right;
};

struct node * newNode(int element)
{
    struct node * temp = (node *)malloc(sizeof(node));
    temp -> data = element;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

struct node * insert(struct node * root, int data)
{
    if(root == NULL)
        return newNode(data);
    else
    {
        if(data <= root -> data)
            root -> left = insert(root -> left, data);
        else    
            root -> right = insert(root -> right, data);
        return root;
    }
}

void preorder(struct node * root)
{
    if(root)
    {
        printf("%d\n", root -> data);
        preorder(root -> left);
        preorder(root -> right);
    }
}

void inorder(struct node * root)
{
    if(root)
    {
        if(root -> data==Q)
        {
            preorder(root);
        }
        inorder(root -> left);
        //printf("%d\n", root -> data);
        inorder(root -> right);
    }
}

int main()
{
    cin >> N; cin >> a;
    struct node * bst = newNode(a);

    for(int i=0; i<N-1; i++)
    {
        cin >> a;
        insert(bst, a);
    }
    cin >> Q;

    inorder(bst);
    return 0;
}