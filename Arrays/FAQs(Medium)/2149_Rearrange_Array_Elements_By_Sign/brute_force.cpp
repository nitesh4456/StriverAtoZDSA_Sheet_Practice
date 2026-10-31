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
        vector<int> pos(nums.size()/2,0), neg(nums.size()/2);
        display_array(pos);
        display_array(neg);

        int i=0 , j=0;
        for(int ele: nums){
            if(ele>0){
                pos[i++]=ele;
            }
            else{
                neg[j++]=ele;
            }
        }
        display_array(pos);
        display_array(neg);

        vector<int> rearranged_array(nums.size(),0);
        i=0;
        for(int k =0  ; k<nums.size();k++){
            rearranged_array[k++]=pos[i];
            rearranged_array[k] = neg[i++];
        }
        display_array(rearranged_array);

        return nums;
    }    
};

int main(){
    Solution s;
    vector<int> nums = {3,1,-2,-5,2,-4};
    s.rearrangeArray(nums);
    return 0;
}