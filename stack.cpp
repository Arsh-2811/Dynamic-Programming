#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int x){
        val = x;
        next = NULL;
    }
};

struct MyStack{
    Node* head;
    int size;
    MyStack(){
        head = NULL;
        size = 0;
    }
    void push(int x){
        Node* temp = new Node(x);
        temp->next = head;
        head = temp;
        size++;
    }
    int pop(){
        if(head == NULL){
            cout << "Stack is Empty" << endl;
            return 0;
        }
        int res = head->val;
        Node*temp = head;
        head = head->next;
        delete(temp);
        size--;
        return res;
    }
    int peek(){
        if(head == NULL){
            cout << "Stack is Empty" << endl;
            return 0;
        }
        return head->val;
    }
    bool isEmpty(){
        return head == NULL;
    }
};

string removePair(string str){
    stack<char> s;
    int n = str.length();
    s.push(str[0]);
    for(int i = 1; i < n; i++){
        if(!s.empty() && str[i] == s.top()){
            s.pop();
            continue;
        }
        else{
            s.push(str[i]);
        }
    }
    string ans = "";
    while(s.empty() == false){
        ans = s.top() + ans;
        s.pop();
    }
    return ans;
}

int main(){

    string str = "aaabbaaccd";
    cout << removePair(str) << endl;

    return 0;
}