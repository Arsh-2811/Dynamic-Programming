#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node*left;
    Node*right;
    Node(int x){
        val = x;
        left = NULL, right = NULL;
    }
};

void levelOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(q.size() != 0){
        Node* temp = q.front();
        cout << temp->val << " ";
        q.pop();
        if(temp->left != NULL){
            q.push(temp->left);
        }
        if(temp->right != NULL){
            q.push(temp->right);
        }
    }

}

void levelOrderTraversallbl(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size() > 1){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout << "\n";
            q.push(NULL);
            continue;
        }
        cout << temp->val << " ";
        if(temp->left != NULL){
            q.push(temp->left);
        }
        if(temp->right != NULL){
            q.push(temp->right);
        }
    }
}

Node* BinaryTreetoDLL(Node* root){
    if(root == NULL){
        return root;
    }
    
}

int main(){

    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right= new Node(50);
    root->left->right->left = new Node(70);
    root->left->right->right = new Node(80);
    root->right->right = new Node(60);

    levelOrderTraversal(root);
    cout << "\n";
    levelOrderTraversallbl(root);

    return 0;
}