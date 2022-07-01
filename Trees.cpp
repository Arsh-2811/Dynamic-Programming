#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int x){
        val = x;
        left = right = NULL;
    }
};

void preorder_iterative(Node* root){
    if(root == NULL){
        return;
    }
    stack<Node*> s;
    s.push(root);
    while(!s.empty()){
        Node* temp = s.top();
        cout << temp->val << " ";
        s.pop();
        if(temp->right != NULL){
            s.push(temp->right);
        }
        if(temp->left != NULL){
            s.push(temp->left);
        }
    }
    cout << "\n";
}

void inorder_iterative(Node* root){
    if(root == NULL){
        return;
    }
    stack<Node*> s;
    Node* temp = root;
    while(true){
        if(temp != NULL){
            s.push(temp);
            temp = temp->left;
        }
        else{
            if(s.empty()) break;
            temp = s.top();
            s.pop();
            cout << temp->val << " ";
            temp = temp->right;
        }
    }
    cout << "\n";
}

void postorder_iterative_2stacks(Node* root){
    if(root == NULL){
        return;
    }
    stack<Node*> s1, s2;
    s1.push(root);
    while(!s1.empty()){
        Node* temp = s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left != NULL) s1.push(temp->left);
        if(temp->right != NULL) s1.push(temp->right);
    }
    while(!s2.empty()){
        cout << s2.top()->val << " ";
        s2.pop();  
    }
    cout << "\n";
}

void postorder_iterative_1stack(Node* root){
    if(root == NULL){
        return;
    }
    stack<Node*> s;
    Node* curr = root;
    while(curr != NULL || !s.empty()){
        if(curr != NULL){
            s.push(curr);
            curr = curr->left;
        }
        else{
            Node* temp = s.top()->right;
            if(temp == NULL){
                temp = s.top();
                s.pop();
                cout << temp->val << " ";
                while(!s.empty() && temp == s.top()->right){
                    temp = s.top();
                    s.pop();
                    cout << temp->val << " ";
                }
            }
            else{
                curr = temp;
            }
        }
    }
    
}

void postorder_iterative(Node* root){   // This is just another way of doing post order iterative using 2 stacks. In this method we have used a vector instead of another stack, the only problem being revesing the vector takes O(n) of extra time.
    if(root == NULL){
        return;
    }
    stack<Node*> s;
    vector<int> v;
    s.push(root);
    while(!s.empty()){
        Node* temp = s.top();
        s.pop();
        v.push_back(temp->val);
        if(temp-> left != NULL) s.push(temp->left);
        if(temp-> right != NULL) s.push(temp->right);
    }
    reverse(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}

int maximum__depth(Node* root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(maximum__depth(root->left), maximum__depth(root->right));
}

bool isbalanced(Node* root){
    if(root == NULL){
        return 0;
    }
    int lh = isbalanced(root->left);
    if(lh == -1) return -1;

    int rh = isbalanced(root->right);
    if(rh == -1) return -1;

    if(abs(lh-rh) > 1) return -1;
    return max(lh, rh);
}

bool isBalanced(Node* root){
    return isbalanced(root) != -1;
}

struct custom{
    int height;
    int maxsofar;
    custom(int a, int b){
        height = a;
        maxsofar = b;
    }
};

custom* diameter(Node* root){
    if(root == NULL){
        custom* temp = new custom(0, 0);
        return temp;
    }
    custom* lh = diameter(root->left);
    custom* rh = diameter(root-> right);

    int height = 1 + max(lh->height, rh->height);
    int m = lh->height + rh->height;
    int maxsofar = max(m, max(lh->maxsofar, rh->maxsofar));
    
    custom* ans = new custom(height, maxsofar);
    return ans;

}

int Diameter(Node* root){
    return diameter(root)->maxsofar;
}

int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(7);
    root->right->right->right = new Node(8);
    root->right->right->right->right = new Node(9);
    root->right->left->left = new Node(5);
    root->right->left->left->left = new Node(6);

    cout << Diameter(root) << endl;

    return 0;
}