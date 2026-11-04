#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int count=0;
        for(int i=0 ; i<nums.size();i++){
            for(int j=i+1; j<nums.size();j++){
                //check reverse condition
                //i<j by iteration
                if(nums[i]>2*nums[j]) count++;
            }
        }
        return count;
    }
};
int main(){
    vector<int> nums={5,4,4,3,3};
    Solution s;
    cout<<s.reversePairs(nums);
}