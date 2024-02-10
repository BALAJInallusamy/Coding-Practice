//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        int n=arr.size();
        int tar,right,left;
        for(int i=0;i<n;i++){
            if(i>0 && arr[i]==arr[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1 && arr[j]==arr[j-1]) continue;
                right=n-1;
                tar=k-arr[i]-arr[j];
                left=j+1;
                while(left<right){
                    if(arr[left]+arr[right]==tar) {
                        ans.push_back({arr[i],arr[j],arr[left],arr[right]});
                        while(left+1<right && arr[left]==arr[left+1]) left++;
                        while(right-1>left && arr[right]==arr[right-1]) right--;
                        left++;
                        right--;
                    }
                    else if(arr[left]+arr[right]>tar) {right--;continue;}
                    else {left++;continue;}
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
