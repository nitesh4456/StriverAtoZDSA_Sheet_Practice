#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void display_array(const vector<int>& nums){
        cout<<"\n";
        for(auto ele : nums){
            cout<<ele<<", ";
        }
        cout<<endl;
    }
    vector<int> rearrangeArray(vector<int>& nums) {
        // Solution s;
        vector<int> temp(nums.size(),0);
        // s.display_array(temp);
        int i=0, j= nums.size()/2;
        for (int k=0  ; k<nums.size(); k++ ){
            if(nums[k]>0){
                temp[i++]=nums[k];
            }
            else{
                temp[j++]=nums[k];
            }
        }
        // s.display_array(temp);
        // Time Complexity :: O(n)
        // Space Complexity :: O(n)
        i=0, j=nums.size()/2;
        vector<int> rearranged(nums.size(),0);
        for(int k =0 ; k<rearranged.size(); k++){
            if(k%2==0){
                rearranged[k]=temp[i++];
            }
            else{
                rearranged[k]=temp[j++];
            }
        }
        // Time Complexity :: O(n)
        // Space Complexity :: O(n)
        // s.display_array(rearranged);
        return rearranged;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,1,-2,-5,2,-4};
    s.rearrangeArray(nums);
    return 0;
}