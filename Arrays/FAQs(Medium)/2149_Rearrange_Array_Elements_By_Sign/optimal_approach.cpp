#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> rearranged(nums.size(),0);
        int pos=0 , neg=1;
        for(int ele : nums){
            if(ele>0){
                rearranged[pos]=ele;
                pos+=2;
                continue;
            }else{
                rearranged[neg]=ele;
                neg+=2;
            }
        }
        return rearranged;
    }
};

int main(){
    Solution s;
    vector<int> nums={3,1,-2,-5,2,-4};
    vector<int> ans = s.rearrangeArray(nums);
    for(auto ele:ans){
        cout<<ele<<", ";
    }
    cout<<endl;
}