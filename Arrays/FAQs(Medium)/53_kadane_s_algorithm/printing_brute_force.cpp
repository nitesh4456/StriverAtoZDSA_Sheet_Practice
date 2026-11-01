#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
        void display_all_subarrays(const vector<int>& nums){
            for(int i=0 ; i<nums.size();i++){
                cout<<endl;
                for(int j=i; j<nums.size();j++){
                    cout<<" ";
                    for(int k=i; k<=j;k++){
                        cout<<nums[k];
                    }
                }
            }
        }
        int max_sum_subarray_brute_force(const vector<int>&nums){
            int maxSum=INT_MIN;
            for(int i=0 ; i<nums.size();i++){
                int currSum=0;
                for(int j=i; j<nums.size();j++){
                    currSum=nums[j]+currSum;
                    maxSum = max(maxSum,currSum);
                }
            }
            return maxSum;
        }
        int max_sum_subarray_kadanes_algorithm(vector<int>&nums){
            // if currSum <0 ignore that sub array
            int maxSum=INT_MIN, currSum=0;
            for(int i=0 ; i<nums.size();i++){
                    currSum=nums[i]+currSum;
                    maxSum = max(maxSum,currSum);
                    if(currSum<0) currSum=0;
            }
            return maxSum;
            return 0;
        }
};
int main(){
    Solution s;
    vector<int> nums ={1,2,-5,3,-4,4,5,-4,-3};
    // s.display_all_subarrays(nums);
    // cout<<s.max_sum_subarray_brute_force(nums);
    cout<<s.max_sum_subarray_kadanes_algorithm(nums);
}