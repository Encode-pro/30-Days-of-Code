#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    struct Node* left;
    struct Node* right;
    int data;
}Node;
Node* newNode(int data){
    Node* node=(Node*)malloc(sizeof(Node));
    node->left=node->right=NULL;
    node->data=data;
    return node;
}

int getHeight(Node* root){
  //Write your code here
    if (root==NULL)
        return 0;
    else if ((root->left==NULL) && (root->right==NULL))
        return 0;
    else if ((root->left != NULL) && (root->right==NULL))
        return 1+getHeight(root->left);
    else if ((root->left == NULL) && (root->right!=NULL))
        return 1+getHeight(root->right);
    else{
        int a, b;
        a=getHeight(root->left);
        b=getHeight(root->right);
        if(a>b)
            return 1 + a;
        else
            return 1 + b;
    }
}
Node* insert(Node* root,int data){
    if(root==NULL)
        return newNode(data);
    else{
        Node* cur;
        if(data<=root->data){
            cur=insert(root->left,data);
            root->left=cur;                
        }
        else{
            cur=insert(root->right,data);
            root->right=cur;
        }
        
    }
    return root;
}
int main(){
    Node* root=NULL;
    int T,data;
    scanf("%d",&T);
    while(T-->0){
        scanf("%d",&data);
        root=insert(root,data);
    }
    int height=getHeight(root);
    printf("%d",height);
    return 0;
    
}