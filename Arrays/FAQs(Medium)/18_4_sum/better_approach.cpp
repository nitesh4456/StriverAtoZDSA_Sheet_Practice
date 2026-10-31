#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution{
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target){
            set<vector<int>> st;
            //nums[i],nums[j],nums[l],nums[r];
            sort(nums.begin(),nums.end());//introsort O(NlogN)
            for(int i=0 ; i<nums.size();i++){
                if(i>0 && nums[i]==nums[i-1]) continue;
                //fix i
                for(int j=i+1; j<nums.size();j++){
                    if(j>i+1 && nums[j]==nums[j-1]) continue;
                    //fix j
                    int l = j+1;
                    int r = nums.size()-1;
                    while(l<r){
                        if(nums[i]+nums[j]+nums[l]+nums[r] < target ){
                            //increase the sum by moving 'l' to right side which will increase as it is in sorted order in ; left to right increasing order
                            l++;
                            continue;
                        }else if(nums[i]+nums[j]+nums[l]+nums[r] > target){
                            //decrease 
                            r--;
                            continue;
                        }else{
                            //nums[i]+nums[j]+nums[l]+nums[r] == target
                            vector<int> temp={nums[i],nums[j],nums[l],nums[r]};//it is already sorted
                            st.insert(temp);
                            l++;
                            r--;
                            //dont choose same l or r
                            while(l<r && nums[l]==nums[l-1]) l++;
                            while(l<r && nums[r]==nums[r+1]) r--;
                        }
                    }
                }
            }
            //
            vector<vector<int>> ans(st.begin(),st.end());
            return ans;
        }
};

int main(){
    vector<int>nums={10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90};
    int target = 200;
    Solution s;
    vector<vector<int>> ans = s.fourSum(nums,target);
    for(auto ele : ans){
        cout<<"[";
        for ( auto element: ele){
            cout<<element<<", ";
        }
        cout<<"]"<<endl;
    }
}