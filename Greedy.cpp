#include<bits/stdc++.h>
using namespace std;

int minCoins(int coin[], int n, int amount){
    int ans = 0;
    sort(coin, coin+n);
    for(int i = n-1; i >= 0; i--){
        if(coin[i] <= amount){
            int c = floor(amount/coin[i]);
            ans += c;
            amount -= c*coin[i];
        }
        if(amount == 0){
            break;
        }
    }
    return ans;
}

bool myCmp(pair<int, int> a, pair<int, int> b){
    return (a.second < b.second);
}

int maxActivities(vector<pair<int, int>> arr){
    int n = arr.size();
    sort(arr.begin(), arr.end(), myCmp);
    int prev = 0, res = 1;
    for(int curr = 1; curr < n; curr++){
        if(arr[curr].first >= arr[prev].second){
            res++;
            prev = curr;
        }
    }
    return res;
}

bool mycmp1(pair<int, int> a, pair<int, int> b){
    return ((double)a.first/a.second) > ((double)b.first/b.second);
}

int fKnapS(int capacity, vector<pair<int, int>> arr){
    sort(arr.begin(), arr.end(), mycmp1);
    int n = arr.size();
    double res = 0;
    for(int i = 0; i < n; i++){
        if(capacity > arr[i].second){
            res += arr[i].first;
            capacity -= arr[i].second;
        }
        else{
            res += ((double)capacity/arr[i].second)*arr[i].first;
            break;
        }
    }
    return res;
}

int jobsequencing(vector<pair<int, int>> arr){
    
}

struct Node{
    char letter;
    int val;
    Node* left;
    Node* right;
    Node(char ltr, int v){
        letter = ltr;
        val = v;
        left = NULL;
        right = NULL;
    }
};

bool mycmp3(pair<char, int> a, pair<char, int> b){
    return a.second > b.second;
}

Node* huffman(vector<pair<char, int>> arr){
    int n = arr.size();
    sort(arr.begin(), arr.end(), mycmp3);

    vector<int> frequencies_left(n);
    frequencies_left[n-1] = 0, frequencies_left[n-2] = 0;
    int x = arr[n-1].second + arr[n-2].second;
    for(int i = n-3; i >= 0; i--){
        frequencies_left[i] = x;
        x += arr[i].second;
    }

    Node* head = new Node('$', x);
    Node* temp = head;
    for(int i = 0 ; i < n-2; i++){
        Node* left = new Node(arr[i].first, arr[i].second);
        Node* right = new Node('$', frequencies_left[i]);
        if(arr[i].second > frequencies_left[i]){
            swap(left, right);
        }
        temp->left = left;
        temp->right = right;
        if(arr[i].second < frequencies_left[i]){
            temp = temp->right;
        }
        else{
            temp = temp->left;
        }
    }
    Node* left = new Node(arr[n-1].first, arr[n-1].second);
    Node* right = new Node(arr[n-2].first, arr[n-2].second);
    temp->left = left;
    temp->right = temp;

    return head;
}

void print_huffman_tree(Node * root){
    if (root == NULL)
        return;
    queue<Node*> q;
    q.push(root);
 
    while (q.empty() == false) {
        Node* node = q.front();
        cout << node->letter << " " << node->val << "; ";
        q.pop();
        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
    }
}

bool mycmp4(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int activitySelection(vector<int> start, vector<int> end, int n)
{
    vector<pair<int, int>> newarr(n);
    for(int i = 0; i < n; i++){
        pair<int, int> temp = make_pair(start[i], end[i]);
        newarr[i] = temp;
    }
    sort(newarr.begin(), newarr.end(), mycmp4);
    int prev = 0, res = 1;
    for(int i = 1; i < n; i++){
        if(newarr[i].first > newarr[prev].second){
            res++;
            prev = i;
        }
    }
    return res;
}

int main(){

    vector<int> start = {1, 3, 2, 5};
    vector<int> end = {2, 4, 3, 6};

    int ans = activitySelection(start, end, 4);
    cout << ans << endl;

    return 0;
}