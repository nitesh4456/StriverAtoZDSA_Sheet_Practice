#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
    //brute:
    //generate all possible combinations;   ()   requires O(N!*N) time complexity to form ;; high order time complexity ; cant be used; ()
    //find the next_permutaion in the array of all possible combinations 

    //better:
    // use next_permutation function from C++ STL;

    //optimal 
        //implementation of next_permuation by self as below;
        void generate_next_permuatation(vector<int>&nums){
            //e.g 2,1,5,4,3,0,0
            //increasing order 5,4,3,0,0
            //dip_index = at  1
            //find dip_index;
            int dip_index = -1;
            for(int i=nums.size()-2; i>=0; i--){
                if(nums[i]<nums[i+1]){
                    dip_index = i;
                    break;
                }
            }
            if(dip_index == -1){
                reverse(nums.begin(),nums.end());
                return;
            }
            
            //find smallest greater element in right side 
            for(int i=nums.size()-1;i>dip_index;i--){
                if(nums[i]>nums[dip_index]){
                    swap(nums[i],nums[dip_index]);
                    break;
                }
            }
            // swap 1, with 3
            //find as much as smallest in right side;
            //reverse 5,4,1,0,0 at it is in increasing order reversing it will form an decreasing order i.e smallest possible
            // i.e. smallest possible is required to get exact next_permutation;
            reverse(nums.begin()+dip_index+1, nums.end());
        }

};
int main(){
    vector<int> nums ={5,4,3,2,1};
    Solution s;
    s.generate_next_permuatation(nums);
    for(auto ele: nums){
        cout<<ele<<", ";
    }

}