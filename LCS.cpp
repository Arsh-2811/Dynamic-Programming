#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int memo[100][100];

int lcs(string s1, string s2, int m, int n){    // Memoization based solution

    if(memo[m][n] != -1){
        return memo[m][n];
    }

    if(m == 0 || n == 0){
        memo[m][n] = 0;
    }
    else{
        if(s1[m-1] == s2[n-1]){
            memo[m][n] = 1 + lcs(s1, s2, m-1, n-1);
        }
        else{
            memo[m][n] =  max(lcs(s1, s2, m-1, n), lcs(s1, s2, m, n-1));
        }
    }
    return memo[m][n];
}

int lcs2(string s1, string s2){
    int m = s1.length();
    int n = s2.length();

    int dp[m+1][n+1];

    for(int i = 0; i < m; i++){
        dp[m][0] = 0;
    }
    for(int i = 0; i < n; i++){
        dp[0][n] = 0;
    }

}

bool containsduplicate(vector<int> nums){
    int n = nums.size();
    unordered_set<int> lst;
    bool ans = false;
    for(int i = 0; i < n; i++){
        if(lst.find(nums[i]) != lst.end()){
            ans = true;
            break;
        }
        lst.insert(nums[i]);
        for(auto it = lst.begin(); it != lst.end(); it++){
            cout << *it << " ";
        }
        cout << endl;
    }
    return ans;
}

int search(int arr[], int l, int h, int key){
    while(l < h){
        int mid = h - (h-l)/2;
        if(key == arr[mid]){
            return mid;
        }
        if(arr[l] <= arr[mid]){
            if(key <= arr[mid] && key >= arr[l]){
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        else{
            if(key <= arr[h] && key >= arr[mid]){
                l = mid + 1;
            }
            else{
                h = mid - 1;
            }
        }
    }
    return -1;
}

int findMin(vector<int>& nums) {
    int l = 0;
    int h = nums.size() - 1;
    if(h == 0){
        return nums[0];
    }
    if(nums[l] < nums[h]){
        return nums[l];
    }
    while(l <= h){
        int mid = (l + h)/2;
        if(mid > 0 && nums[mid] < nums[mid - 1]){
            return nums[mid];
        }
        if(mid < h && nums[mid] > nums[mid+1]){
            return nums[mid + 1];
        }
        if(nums[l] < nums[mid]){
            l = mid + 1;
        }
        else{
            h = mid - 1;
        }
    }
    return -1;
}

vector<vector<int>> threeSum(vector<int> & nums){
    vector<vector<int>> ans;
    int n = nums.size();
    unordered_set<int> hsh;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(hsh.find(-nums[i] - nums[j]) != hsh.end()){
                vector<int> temp = {nums[i], nums[j], -nums[i] - nums[j]};
                ans.push_back(temp);
            }
        }
        hsh.insert(nums[i]);
    }
    return ans;
}

vector<vector<int>> threeSum2(vector<int> &nums){
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n - 2; i++){
        int l = i + 1;
        int r = n-1;
        while(l < r){
            if(nums[i] + nums[l] + nums[r] == 0){
                vector<int> temp = {nums[i], nums[l], nums[r]};
                ans.push_back(temp);
                while(l < r && nums[l] == nums[temp[1]]){
                    l++;
                }
                while(l < r && nums[r] == nums[temp[2]]){
                    r--;
                }
                l++;
                r--;
            }
            else if(nums[i] + nums[l] + nums[r] > 0){
                r--;
            }
            else{
                l++;
            }
        }
        while(nums[i+1] == nums[i]){
            i++;
        }
    }
    return ans;
}

int main(){
    
    vector<int> arr = {0, 0, 0, 0};
    vector<vector<int>> ans = threeSum2(arr);
    for(auto it = ans.begin(); it != ans.end(); it++){
        vector<int> temp = *it;
        for(auto x = temp.begin(); x != temp.end(); x++){
            cout << *x << " ";
        }
        cout << "\n";
    }

    return 0;
}