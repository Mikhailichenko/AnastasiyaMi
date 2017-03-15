#include <iostream>
#include <queue>

using namespace std;

typedef struct Node{
    int data;
    int balance=0;
    Node* left=NULL;
    Node* right=NULL;
}Node;



class AVLTree{
    Node* root;

public:

    Node* get_root(){
        return root;
    }

    AVLTree(int a){
        Node* temp=new Node;
        temp->data=a;
        root=temp;
    }

    void deleteTree(Node* n){
        if(n==NULL) return;
        deleteTree(n->left);
        deleteTree(n->right);
        delete n;
    }

    ~AVLTree(){
        deleteTree(root);
    }

    bool Search (int a, Node* n){
        if (n==NULL) return 0;
        if (n->data==a) return 1;
        if (n->data<a) return Search (a, n->left);
        if (n->data>a) return Search (a, n->right);
        return 0;
    }
};

int main()
{
    return 0;
}
